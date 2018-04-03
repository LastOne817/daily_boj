#include <cstdio>
#include <cstring>

int main(void) {
  int n, k;
  int count[65536];
  int t[5000];
  long long sum = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k - 1; i++) {
    scanf("%d", &t[i % k]);
  }
  for (int i = k - 1; i < n; i++) {
    scanf("%d", &t[i % k]);

    memset(count, 0, sizeof(int) * 65536);
    for (int j = 0; j < k; j++) {
      count[t[j]]++;
    }
    for (int j = 1; j < 65536; j++) {
      count[j] += count[j - 1];
      if (count[j - 1] <= (k + 1) / 2 && count[j] > (k + 1) / 2) {
        sum += j - 1;
        break;
      }
    }
  }
  printf("%lld\n", sum);
  return 0;
}
