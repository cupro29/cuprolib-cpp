#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

#include <bits/stdc++.h>

#include "../include/dualsegtree"

int op(int l, int _r) { return l; }

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  DualSegmentTree<int, op, std::numeric_limits<int>::max> seg(N);
  for (int i = 0; i < Q; i++) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int l, r, x;
      std::cin >> l >> r >> x;
      seg.apply(l, r + 1, x);
    } else {
      int x;
      std::cin >> x;
      std::cout << seg.get(x) << "\n";
    }
  }
}