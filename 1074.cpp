#include <cstdio>

long long int z(int n, int r, int c) {
  if (n == 0) return 1;
  long long int mid = 1 << (n - 1);
  if (r < mid) {
    if (c < mid) return z(n - 1, r, c);
    else return z(n - 1, r, c - mid) + mid * mid;
  } else {
    if (c < mid) return z(n - 1, r - mid, c) + mid * mid * 2;
    else return z(n - 1, r - mid, c - mid) + mid * mid * 3;
  }
}

int main(void) {
  int n, r, c;
  scanf("%d %d %d", &n, &r, &c);
  printf("%lld\n", z(n, r, c) - 1);
  return 0;
}
