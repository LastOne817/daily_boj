#include <cstdio>

int main(void) {
  long long p[101];
  int t, n;

  p[1] = p[2] = p[3] = 1;
  p[4] = p[5] = 2;

  for (int i = 6; i <= 100; i++) {
    p[i] = p[i - 1] + p[i - 5];
  }

  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%lld\n", p[n]);
  }
  return 0;
}
