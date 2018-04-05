#include <cstdio>

int main(void) {
  int fib[46], n;
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= 45; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  scanf("%d", &n);
  printf("%d\n", fib[n]);
  return 0;
}
