#include <vector>

template <class T, T (*op)(T, T), T (*id)()>
class DualSegmentTree {
  std::vector<T> d;
  int lg;
  static int ceil_pow2(const int n) {
    int res = 0;
    for (; 1 << res < n;) res++;
    return res;
  }
  void all_apply(int k, T f) { d[k] = op(f, d[k]); }
  void push(int k) {
    if (d[k] != id()) {
      all_apply(k << 1 | 0, d[k]);
      all_apply(k << 1 | 1, d[k]);
      d[k] = id();
    }
  }
  void all_push(int p) {
    for (int i = lg; i > 0; i--) push(p >> i);
  }

 public:
  DualSegmentTree(int n = 0)
      : d(1 << (ceil_pow2(n) + 1), id()), lg(ceil_pow2(n)) {}
  DualSegmentTree(const std::vector<T>& v)
      : d(1 << (ceil_pow2(v.size()) + 1), id()), lg(ceil_pow2(v.size())) {}
  void set(int p, T x) {
    all_push(p + (1 << lg));
    d[p + (1 << lg)] = x;
  }
  T get(int p) {
    all_push(p + (1 << lg));
    return d[p + (1 << lg)];
  }
  void apply(int p, T f) {
    all_push(p + (1 << lg));
    d[p] = op(f, d[p]);
  }
  void apply(int l, int r, T f) {
    if (l == r) return;
    l += 1 << lg;
    r += 1 << lg;
    for (int i = lg; i > 0; --i) {
      if (((l >> i) << i) != 1) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    while (l < r) {
      if ((l & 1) != 0) {
        all_apply(l, f);
        ++l;
      }
      if ((r & 1) != 0) {
        --r;
        all_apply(r, f);
      }
      l >>= 1;
      r >>= 1;
    }
  }
};