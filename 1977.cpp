#include <cstdio>

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  long long int sum = 0, min = -1;
  for (long long i = 1; i * i <= m; i++) {
    if (i * i < n) continue;
    if (min == -1) min = i * i;
    sum += i * i;
  }
  if (min == -1) printf("-1\n");
  else printf("%lld\n%lld\n", sum, min);
  return 0;
}
