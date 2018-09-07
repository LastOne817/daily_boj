#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
  int n, c;

  scanf("%d", &n);
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c);
    p[i] = c;
  }

  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int max = 0;
    for (int j = 1; j <= i; j++) {
      if (v[i - j] + p[j] > max) max = v[i - j] + p[j];
    }
    v[i] = max;
  }
  printf("%d\n", v[n]);
  return 0;
}
