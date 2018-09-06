#include <cstdio>

int main(void) {
  int a1, a2, a;
  int n;
  scanf("%d", &n);
  if (n == 1) printf("1\n");
  else if (n == 2) printf("2\n");
  else {
    a1 = 1;
    a2 = 2;
    for (int i = 2; i < n; i++) {
      a = (a1 + a2) % 10007;
      a1 = a2;
      a2 = a;
    }
    printf("%d\n", a);
  }

  return 0;
}
