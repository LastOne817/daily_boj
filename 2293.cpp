#include <cstdio>

int main(void) {
  int n, k;
  int count[10001];
  int value[100];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &value[i]);
  }

  count[0] = 1;
  for (int i = 1; i <= k; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = value[i]; j <= k; j++) {
      count[j] += count[j - value[i]];
    }
  }
  printf("%d\n", count[k]);
  return 0;
}
