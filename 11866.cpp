#include <cstdio>
#include <queue>

using namespace std;

int main(void) {
  int n, m;
  queue<int> q;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }
  printf("<");
  while (q.size() > 1) {
    for (int i = 0; i < m - 1; i++) {
      int t = q.front();
      q.pop();
      q.push(t);
    }
    printf("%d, ", q.front());
    q.pop();
  }
  printf("%d>\n", q.front());
  return 0;
}
