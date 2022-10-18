#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <bits/stdc++.h>

#include "../include/modint"
#include "../include/sequence"

using M = ModInt<998244353>;
struct S {
  M sum, len;
  S() : S(0) {}
  S(M x) : sum(x), len(1) {}
  S(M x, M y) : sum(x), len(y) {}
};
struct T {
  M b, c;
  T(M x, M y) : b(x), c(y) {}
  bool operator!=(T rhs) const { return b != rhs.b || c != rhs.c; }
};
S op(S l, S r) { return S(l.sum + r.sum, l.len + r.len); }
S e() { return S(0, 0); }
S mapping(T f, S x) { return S(f.b * x.sum + f.c * x.len, x.len); }
T composition(T f, T g) { return T(f.b * g.b, f.b * g.c + f.c); }
T id() { return T(1, 0); }

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<S> a(N);
  for (S& e : a) std::cin >> e.sum;
  AVLTreeSequence<S, op, e, T, mapping, composition, id> A(a);
  for (int q = 0; q < Q; q++) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int i, x;
      std::cin >> i >> x;
      A.insert(i, S(x));
    } else if (t == 1) {
      int i;
      std::cin >> i;
      A.erase(i);
    } else if (t == 2) {
      int l, r;
      std::cin >> l >> r;
      A.reverse(l, r);
    } else if (t == 3) {
      int l, r, b, c;
      std::cin >> l >> r >> b >> c;
      A.apply(l, r, T(b, c));
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << A.prod(l, r).sum << "\n";
    }
  }
}