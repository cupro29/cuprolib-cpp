#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>

#include "../include/UF"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  UnionFind uf(N);
  for (int i = 0; i < Q; i++) {
    int t, u, v;
    std::cin >> t >> u >> v;
    if (t == 0) {
      uf.unite(u, v);
    } else {
      std::cout << (uf.same(u, v) ? 1 : 0) << "\n";
    }
  }
}