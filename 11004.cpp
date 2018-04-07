#include <cstdio>
#include <queue>

using namespace std;

int main(void) {
  priority_queue<int> arr;
  int n, k;
  scanf("%d %d", &n, &k);

  int a;
  for (int i = 0; i < k; i++) {
    scanf("%d", &a);
    arr.push(a);
  }
  for (int i = k; i < n; i++) {
    scanf("%d", &a);
    if (a < arr.top()) {
      arr.pop();
      arr.push(a);
    }
  }

  printf("%d\n", arr.top());

  return 0;
}
