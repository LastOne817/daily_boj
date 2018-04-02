#include <cstdio>

int main(void) {
  int t, n, m;
  long long s;

  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &m);
    s = 1;
    for (int j = 1; j <= n; j++) {
      s = s * (m + 1 - j) / j;
    }
    printf("%lld\n", s);
  }
  return 0;
}
