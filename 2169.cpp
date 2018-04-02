#include <cstdio>
#include <climits>

#define SIZE_MX 1002
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void) {
  int n, m;
  int board[SIZE_MX][SIZE_MX];
  long left[SIZE_MX][SIZE_MX], right[SIZE_MX][SIZE_MX];

  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // Initializing inputs
  for (int i = 0; i <= n + 1; i++) {
    left[i][0] = left[i][m+1] = INT_MIN;
    right[i][0] = right[i][m+1] = INT_MIN;
  }
  for (int j = 0; j <= m + 1; j++) {
    left[0][j] = right[0][j] = INT_MIN;
    left[n+1][j] = right[n+1][j] = INT_MIN;
  }
  left[1][0] = 0;

  // DP
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      left[i][j] = MAX(MAX(left[i][j-1], left[i-1][j]), right[i-1][j]) + board[i][j];
      right[i][m + 1 - j] = MAX(MAX(right[i][m + 2 - j], right[i-1][m + 1 - j]), left[i-1][m + 1 - j]) + board[i][m + 1 - j];
    }
  }

  printf("%ld\n", left[n][m]);

  return 0;
}
