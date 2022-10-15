#include <vector>

template <class T>
class BinaryIndexedTree {
  std::vector<T> d;
  T sum(int r) const {
    T res = 0;
    while (r > 0) {
      res += d[r - 1];
      r -= r & -r;
    }
    return res;
  }

 public:
  BinaryIndexedTree(int n) : d(n) {}
  BinaryIndexedTree(std::vector<T>& v) : d(v) {
    for (int i = 1; i <= (int)d.size(); i++) {
      int j = i + (i & -i);
      if (j <= (int)d.size()) d[j - 1] += d[i - 1];
    }
  }
  void add(int p, T x) {
    p++;
    while (p <= (int)d.size()) {
      d[p - 1] += x;
      p += p & -p;
    }
  }
  T range(int l, int r) const { return sum(r) - sum(l); }
};
