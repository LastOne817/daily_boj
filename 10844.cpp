#include <cstdio>

#define M 1000000000

int main(void) {
  int n;
  long long count[101][10];
  scanf("%d", &n);

  count[1][0] = 0;
  for (int i = 1; i <= 9; i++) {
    count[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    count[i][0] = count[i - 1][1];
    count[i][9] = count[i - 1][8];
    for (int j = 1; j <= 8; j++) {
      count[i][j] = (count[i - 1][j - 1] + count[i - 1][j + 1]) % M;
    }
  }
  long long sum = 0;
  for (int i = 0; i <= 9; i++) {
    sum += count[n][i];
  }
  printf("%lld\n", sum % M);
  return 0;
}
