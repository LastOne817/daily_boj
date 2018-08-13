#include <cstdio>
#include <climits>

int main(void) {
  int t;
  scanf("%d", &t);
  for (int ti = 0; ti < t; ti++) {
    int k;
    int arr[500];
    int c[500][500];

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      scanf("%d", &arr[i]);
    }

    for (int i = 0; i < k; i++) {
      c[i][i] = 0;
    }

    for (int l = 1; l < k; l++) {
      for (int m = 0; m < k - l; m++) {
        int n = m + l;
        int min = INT_MAX;
        int sum = 0;
        for (int p = m; p < n; p++) {
          int cost = c[m][p] + c[p + 1][n];
          if (cost < min) min = cost;
          sum += arr[p];
        }
        sum += arr[n];
        c[m][n] = min + sum;
      }
    }

    printf("%d\n", c[0][k - 1]);
  }
  return 0;
}
