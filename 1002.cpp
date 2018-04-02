#include <cstdio>

#define SQ(x) ((x)*(x))

int main(void) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int x1, y1, r1, x2, y2, r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    long long dist = SQ(x1 - x2) + SQ(y1 - y2);
    if (x1 == x2 && y1 == y2 && r1 == r2) printf("-1\n");
    else if (dist > SQ(r1 + r2) || dist < SQ(r1 - r2)) printf("0\n");
    else if (dist == SQ(r1 + r2) || dist == SQ(r1 - r2)) printf("1\n");
    else printf("2\n");
  }
  return 0;
}
