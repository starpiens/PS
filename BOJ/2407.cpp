#include <bits/stdc++.h>
using namespace std;

struct BigInt {
  char data[30] = { 0, };
  int len = 0;
  BigInt() = default;
  BigInt(int n) {
      while (n) {
          data[len++] = n % 10;
          n /= 10;
      }
  }
  BigInt operator+(BigInt o) {
      BigInt res;
      int i;
      for (i = 0; i < max(len, o.len); i++) {
          res.data[i] += data[i] + o.data[i];
          res.data[i + 1] = res.data[i] / 10;
          res.data[i] %= 10;
      }
      res.len = i + (res.data[i] != 0);
      return res;
  }
  void print() {
      for (int i = len - 1; i >= 0; i--)
          printf("%d", data[i]);
  }
} dp[101][51];

BigInt f(int n, int m) {
    if (m > n / 2) m = n - m;
    if (!m) return 1;
    if (dp[n][m].len) return dp[n][m];
    return dp[n][m] = f(n - 1, m) + f(n - 1, m - 1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    f(n, m).print();
    return 0;
}