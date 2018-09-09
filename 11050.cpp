#include <cstdio>

int main(void) {
  int n, k;
  int c = 1;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; i++) {
    c *= n - i;
    c /= i + 1;
  }
  printf("%d\n", c);
  return 0;
}
