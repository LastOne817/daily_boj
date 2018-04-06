#include <cstdio>

int main(void) {
  int cost[20], score[20];
  int max_score[100];
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &cost[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &score[i]);
  }

  for (int i = 0; i < 100; i++) {
    max_score[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 99; j >= cost[i]; j--) {
      if (max_score[j] < max_score[j - cost[i]] + score[i]) max_score[j] = max_score[j - cost[i]] + score[i];
    }
  }

  int max = 0;
  for (int i = 0; i < 100; i++) {
    if (max_score[i] > max) max = max_score[i];
  }

  printf("%d\n", max);

  return 0;
}
