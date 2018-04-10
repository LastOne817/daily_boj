#include <cstdio>

int main(void) {
  unsigned long long n, p, q, base;
  int t, c;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &c);
    if (c == 1) {
      scanf("%lld", &n);
      p = q = 1;
      for (base = 1; base <= n >> 2; base <<= 1);
      while (base > 0) {
        if (n & base) {
          p += q;
        } else {
          q += p;
        }
        base >>= 1;
      }
      printf("Case #%d: %lld %lld\n", i, p, q);
    } else {
      scanf("%lld %lld", &p, &q);
      n = 0;
      base = 1;
      while (p > 1 || q > 1) {
        if (p > q) {
          n += base;
          p -= q;
        } else {
          q -= p;
        }
        base <<= 1;
      }
      n += base;
      printf("Case #%d: %lld\n", i, n);
    }
  }
  return 0;
}
