#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>

#include "../include/DST"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> a(N);
  for (auto& e : a) std::cin >> e;
  DisjointSparseTabel<int> dst(a, [](int l, int r) { return std::min(l, r); });
  for (int i = 0; i < Q; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << dst.query(l, r) << "\n";
  }
}