#include <cstdio>

int main(void) {
  unsigned long long n;
  int f0, f1, f2;
  scanf("%llu", &n);
  if (n == 0) {
    printf("0\n");
  } else if (n == 1) { 
    printf("1\n");
  } else {
    f0 = 0;
    f1 = 1;
    n %= 1500000;
    for (int i = 1; i < n; i++) {
      f2 = (f1 + f0) % 1000000;
      f0 = f1;
      f1 = f2;
    }
    printf("%d\n", f2);
  }
  return 0;
}
