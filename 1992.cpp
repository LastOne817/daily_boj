#include <cstdio>

char board[64][64];

void quad(int x1, int y1, int x2, int y2) {
  if (x2 - x1 == 1) {
    printf("%c", board[y1][x1]);
    return;
  }
  bool all_one = true;
  bool all_zero = true;
  for (int i = y1; i < y2; i++) {
    for (int j = x1; j < x2; j++) {
      if (board[i][j] == '0') all_one = false;
      if (board[i][j] == '1') all_zero = false;
    }
  }
  if (all_one) {
    printf("1");
  } else if (all_zero) {
    printf("0");
  } else {
    printf("(");
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    quad(x1, y1, xm, ym);
    quad(xm, y1, x2, ym);
    quad(x1, ym, xm, y2);
    quad(xm, ym, x2, y2);
    printf(")");
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  char str[65];

  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    for (int j = 0; j < n; j++) {
      board[i][j] = str[j];
    }
  }

  quad(0, 0, n, n);
  printf("\n");
  return 0;
}
