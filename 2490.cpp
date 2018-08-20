#include <cstdio>

int main(void) {
  for (int t = 0; t < 3; t++) {
    int n;
    int sum = 0;
    char m[] = {'D', 'C', 'B', 'A', 'E'};
    for (int i = 0; i < 4; i++) {
      scanf("%d", &n);
      sum += n;
    }
    printf("%c\n", m[sum]);
  }
  return 0;
}
