#include <cstdio>

inline static int max(int a, int b, int c) {
  if (a > b) {
    return a > c ? a : c;
  } else {
    return b > c ? b : c;
  }
}

int main(void) {
  int n;
  int wine[10000];
  int cont[3][10000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &wine[i]);
  }

  cont[0][0] = 0;
  cont[1][0] = wine[0];
  cont[2][0] = 0;

  for (int i = 1; i < n; i++) {
    cont[0][i] = max(cont[0][i - 1], cont[1][i - 1], cont[2][i - 1]);
    cont[1][i] = cont[0][i - 1] + wine[i];
    cont[2][i] = cont[1][i - 1] + wine[i];
  }

  printf("%d\n", max(cont[0][n - 1], cont[1][n - 1], cont[2][n - 1]));

  return 0;
}
