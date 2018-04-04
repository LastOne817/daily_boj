#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main(void) {
  int t;
  int n, m;
  int p;
  int order;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &m);
    queue<int> q;
    queue<int> pos;
    multiset<int> s;
    for (int j = 0; j < n; j++) {
      scanf("%d", &p);
      q.push(p);
      pos.push(j);
      s.insert(p);
    }

    order = 1;
    while (true) {
      int cur = q.front();
      int cur_pos = pos.front();

      q.pop();
      pos.pop();

      if (cur < *s.rbegin()) {
        q.push(cur);
        pos.push(cur_pos);
      } else {
        if (cur_pos == m) {
          printf("%d\n", order);
          break;
        }
        order++;
        s.erase(s.find(cur));
      }
    }
  }
  return 0;
}
