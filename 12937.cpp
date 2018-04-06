#include <cstdio>

#define M 1000000007

int main(void) {
  int n, k;
  int count[50001];
  int next[50001];
  scanf("%d %d", &n, &k);

  for (int i = 1; i <= k; i++) {
    count[i] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      next[j] = 0;
      for (int l = 1; l <= k; l++) {
        if (l <= j || l % j != 0) {
          next[j] += count[l];
          next[j] %= M;
        }
      }
    }
    for (int j = 1; j <= k; j++) {
      count[j] = next[j];
    }
  }

  int sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += count[i];
    sum %= M;
  }
  printf("%d\n", sum);
  return 0;
}
