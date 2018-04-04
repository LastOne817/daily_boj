#include <cstdio>
#include <set>

using namespace std;

int main(void) {
  int h[100000], min[100000];
  int n, x;
  multiset<int> hset;
  multiset<int> minset;

  scanf("%d %d", &n, &x);

  long long sum = 0;

  for (int i = 0; i < x; i++) {
    scanf("%d", &h[i]);
    hset.insert(h[i]);
  }
  min[0] = *hset.begin();
  minset.insert(min[0]);
  int count = 0;
  int same = 0;
  int maxmin = min[0];

  for (int i = 0; i < n - x; i++) {
    int h_orig = h[i % x];
    hset.erase(hset.find(h_orig));
    scanf("%d", &h[i % x]);
    hset.insert(h[i % x]);

    if (maxmin != *minset.rbegin()) {
      count += (same + x - 1) / x;
      same = 1;
      maxmin = *minset.rbegin();
    } else {
      same++;
    }

    sum += (h_orig - *minset.rbegin());
    if (minset.size() >= x) minset.erase(minset.find(min[(i + 1) % x]));
    min[(i + 1) % x] = *hset.begin();
    minset.insert(min[(i + 1) % x]);
  }

  for (int i = n - x; i < n; i++) {
    int h_orig = h[i % x];
    hset.erase(hset.find(h_orig));

    if (maxmin != *minset.rbegin()) {
      count += (same + x - 1) / x;
      same = 1;
      maxmin = *minset.rbegin();
    } else {
      same++;
    }

    sum += (h_orig - *minset.rbegin());
    minset.erase(minset.find(min[(i + 1) % x]));
  }
  count += (same + x - 1) / x;

  printf("%lld\n", sum);
  printf("%d\n", count);

  return 0;
}
