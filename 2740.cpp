#include <cstdio>

int main(void) {
  int n, m, k;
  int arr1[100][100], arr2[100][100];
  int result;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr1[i][j]);
    }
  }
  scanf("%d %d", &m, &k);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &arr2[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int l = 0; l < k; l++) {
      result = 0;
      for (int j = 0; j < m; j++) {
        result += arr1[i][j] * arr2[j][l];
      }
      printf("%d ", result);
    }
    printf("\n");
  }
  return 0;
}
