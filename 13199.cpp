#include <cstdio>

int main(void) {
  int t, p, m, f, c;
  scanf("%d\n", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d %d %d", &p, &m, &f, &c);
    int coupon = (m / p) * c;
    int sum = 0;
    while (coupon / f > 0) {
      int additional = coupon / f;
      sum += additional;
      coupon %= f;
      coupon += additional * c;
    }
    printf("%d\n", sum - (m / p) * c / f);
  }
  return 0;
}
