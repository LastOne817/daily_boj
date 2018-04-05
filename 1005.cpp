#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int main(void) {
  int t;
  scanf("%d", &t);
  for (int tc = 0; tc < t; tc++) {
    int n, k, w;
    int before, after;
    int cost[1000];
    int accumulate[1000];
    int indeg[1000];
    multimap<int, int> in;
    multimap<int, int> out;
    queue<int> q;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &cost[i]);
    }
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &before, &after);
      in.insert(pair<int, int>(after - 1, before - 1));
      out.insert(pair<int, int>(before - 1, after - 1));
    }
    scanf("%d", &w);
    w--;

    // toposort
    for (int i = 0; i < n; i++) {
      indeg[i] = in.count(i);
    }
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0) {
        q.push(i);
        accumulate[i] = cost[i];
      }
    }
    while (!q.empty()) {
      int pos = q.front();
      if (pos == w) {
        printf("%d\n", accumulate[pos]);
        break;
      }
      q.pop();
      auto iter_pair = out.equal_range(pos);
      for (auto iter = iter_pair.first; iter != iter_pair.second; iter++) {
        indeg[iter->second]--;
        if (indeg[iter->second] == 0) {
          q.push(iter->second);
          auto in_pair = in.equal_range(iter->second);
          int max = 0;
          for (auto it = in_pair.first; it != in_pair.second; it++) {
            if (accumulate[it->second] > max) max = accumulate[it->second];
          }
          accumulate[iter->second] = max + cost[iter->second];
        }
      }
    }
  }
  return 0;
}
