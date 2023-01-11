#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>

#include "../include/DST"

long long op(long long l, long long r) { return l + r; }

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<long long> a(N);
  for (auto& e : a) std::cin >> e;
  DisjointSparseTable<long long, op> dst(a);
  for (int i = 0; i < Q; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << dst.prod(l, r) << "\n";
  }
}