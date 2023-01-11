#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>

#include "../include/DST"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<long long> a(N);
  for (auto& e : a) std::cin >> e;
  DisjointSparseTable<long long> dst(a, std::plus<long long>());
  for (int i = 0; i < Q; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << dst.query(l, r) << "\n";
  }
}