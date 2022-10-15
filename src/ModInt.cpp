#include <iostream>

template <long long MOD>
class ModInt {
  using i64 = long long;
  i64 v;
  static constexpr bool _is_prime(i64 x) {
    if (x < 2 || (x % 2 == 0 && x != 2)) return false;
    for (i64 k = 3; k * k <= x; k += 2) {
      if (x % k == 0) return false;
    }
    return true;
  }
  static_assert(0 < MOD, "MOD must be positive number");
  static_assert(MOD < (i64)(INT32_MAX), "MOD must be less than INT32_MAX");
  static_assert(_is_prime(MOD), "MOD must be prime number");

 public:
  constexpr ModInt(const i64 x = 0) : v(x % MOD) {
    if (v < 0) v += MOD;
  }
  constexpr i64 val() const { return v; }
  constexpr ModInt operator+(const ModInt &rhs) const {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt &rhs) const {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt &rhs) const {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt &rhs) const {
    return ModInt(*this) /= rhs;
  }
  constexpr bool operator==(const ModInt &rhs) const { return v == rhs.v; }
  constexpr bool operator!=(const ModInt &rhs) const { return v != rhs.v; }
  constexpr ModInt &operator+=(const ModInt &rhs) {
    v += rhs.v;
    if (v >= MOD) {
      v -= MOD;
    }
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &rhs) {
    if (v < rhs.v) {
      v += MOD;
    }
    v -= rhs.v;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &rhs) {
    v = v * rhs.v % MOD;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt &rhs) {
    i64 exp = MOD - 2;
    while (exp) {
      if (exp & 1) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp >>= 1;
    }
    return *this;
  }
  ModInt pow(i64 p) const {
    ModInt x = *this, res = 1;
    while (p) {
      if (p & 1) {
        res = res * x;
      }
      x = x * x;
      p >>= 1;
    }
    return res;
  }
  ModInt inv() const { return pow(MOD - 2); }
  friend std::istream &operator>>(std::istream &is, ModInt &x) {
    i64 v;
    is >> v;
    x = v;
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
    os << x.val();
    return os;
  }
};
