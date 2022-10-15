#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>

#include "../include/BIT"
#include "../include/modint"
#include "../include/segtree"

using mint = ModInt<998244353>;
using S = std::pair<mint, mint>;
S e() { return std::make_pair(mint(1), mint(0)); }
S op(S l, S r) {
  return std::make_pair(l.first * r.first, l.second * r.first + r.second);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<std::pair<mint, mint> > ab(N);
  for (auto& [a, b] : ab) std::cin >> a >> b;
  SegmentTree<std::pair<mint, mint> > seg(ab, e(), op);
  for (int i = 0; i < Q; i++) {
    int q;
    std::cin >> q;
    if (q == 0) {
      int p;
      mint c, d;
      std::cin >> p >> c >> d;
      seg.set(p, std::make_pair(c, d));
    } else {
      int l, r;
      mint x;
      std::cin >> l >> r >> x;
      auto [a, b] = seg.prod(l, r);
      std::cout << a * x + b << "\n";
    }
  }
}