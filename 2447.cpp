#include <cstdio>

char board[2200][2200];

void star(int x, int y, int n) {
  if (n == 1) {
    board[x][y] = 1;
    return;
  }
  for (int i = 0; i < 9; i++) {
    if (i == 4) continue;
    else star(x + (i % 3) * (n / 3), y + (i / 3) * (n / 3), n / 3);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  star(0, 0, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", board[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  return 0;
}
