#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>

#include "../include/BIT"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<long long> a(N);
  for (auto& e : a) std::cin >> e;
  BinaryIndexedTree<long long> bit(a);
  for (int i = 0; i < Q; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x == 0) {
      bit.add(y, z);
    } else {
      std::cout << bit.range(y, z) << "\n";
    }
  }
}