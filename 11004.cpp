#include <cstdio>
#include <set>

using namespace std;

int main(void) {
  multiset<int> left;
  int n, k;
  scanf("%d %d", &n, &k);

  int a;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (left.size() < k) {
      left.insert(a);
    } else {
      if (*left.rbegin() > a) {
        left.erase(--left.end());
        left.insert(a);
      }
    }
  }
  printf("%d\n", *left.rbegin());

  return 0;
}
