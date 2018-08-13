#include <cstdio>
#include <climits>

int main(void) {
  int a;
  int r_prev, r;
  int n;
  scanf("%d", &n);

  scanf("%d", &a);
  r_prev = a;
  int max = r_prev;

  for (int i = 1; i < n; i++) {
    scanf("%d", &a);

    if (r_prev < 0) r = a;
    else r = r_prev + a;

    if (r > max) max = r;

    r_prev = r;
  }

  printf("%d\n", max);
  
  return 0;
}
