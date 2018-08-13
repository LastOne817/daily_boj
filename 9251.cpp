#include <cstdio>
#include <cstring>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(void) {
  char s1[1002], s2[1002];
  int lcs[1001][1001];
  scanf("%s", &s1[1]);
  scanf("%s", &s2[1]);

  int l1 = strlen(&s1[1]);
  int l2 = strlen(&s2[1]);

  for (int i = 0; i <= l1; i++) {
    lcs[i][0] = 0;
  }
  for (int i = 0; i <= l2; i++) {
    lcs[0][i] = 0;
  }

  for (int i = 2; i <= l1 + l2; i++) {
    for (int j = 1; j < i; j++) {
      if (j > l1 || i - j > l2) continue;
      lcs[j][i - j] = (s1[j] == s2[i - j] ? lcs[j - 1][i - j - 1] + 1 : MAX(lcs[j][i - j - 1], lcs[j - 1][i - j]));
    }
  }

  printf("%d\n", lcs[l1][l2]);
  return 0;
}
