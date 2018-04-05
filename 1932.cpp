#include <cstdio>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void) {
  int n;
  int num[500][500];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      scanf("%d", &num[i - 1][j]);
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      num[i][j] += MAX(num[i + 1][j], num[i + 1][j + 1]);
    }
  }
  printf("%d\n", num[0][0]);
  return 0;
}
