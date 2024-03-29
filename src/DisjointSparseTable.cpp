#include <vector>

template <class T, T (*op)(T, T)>
class DisjointSparseTable {
  std::vector<std::vector<T> > table;

 public:
  DisjointSparseTable(const std::vector<T> &v) : table() {
    int n = v.size();
    table.emplace_back(v);
    for (int i = 2; i < n; i <<= 1) {
      table.emplace_back(n);
      for (int j = i; j < n; j += i << 1) {
        table.back()[j - 1] = table[0][j - 1];
        for (int k = 2; k <= i; k++) {
          table.back()[j - k] = op(table[0][j - k], table.back()[j - k + 1]);
        }
        table.back()[j] = table[0][j];
        for (int k = 2; k <= i && j + k <= n; k++) {
          table.back()[j + k - 1] =
              op(table.back()[j + k - 2], table[0][j + k - 1]);
        }
      }
    }
  }
  T prod(int l, int r) const {
    r--;
    if (l == r) return table[0][l];
    int k = 31 - __builtin_clz(l ^ r);
    return op(table[k][l], table[k][r]);
  }
};