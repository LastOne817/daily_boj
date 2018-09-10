#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

class Compare
{
public:
  bool operator() (pair<int, int>& lhs, pair<int, int>& rhs) {
    return lhs.second > rhs.second;
  }
};

void dijkstra(vector<pair<int ,int> > graph[], int n, int start, vector<int>& d) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
  vector<bool> used (n, false);

  pq.push(make_pair(start, 0));

  while (!pq.empty()) {
    int v = pq.top().first;
    int dv = pq.top().second;
    pq.pop();
    if (used[v]) continue;
    d[v] = dv;
    used[v] = true;
    
    for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
      int u = it->first, cost = it->second;
      if (d[u] > dv + cost) {
        d[u] = dv + cost;
        pq.push(make_pair(u, d[u]));
      }
    }
  }
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, d;
  
  vector<pair<int, int> > graph[n];
  vector<pair<int, int> > graph_wolf[2 * n];

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &d);
    a--; b--;
    graph[a].push_back(make_pair(b, d * 2));
    graph[b].push_back(make_pair(a, d * 2));

    graph_wolf[a * 2].push_back(make_pair(b * 2 + 1, d));
    graph_wolf[b * 2].push_back(make_pair(a * 2 + 1, d));
    graph_wolf[a * 2 + 1].push_back(make_pair(b * 2, d * 4));
    graph_wolf[b * 2 + 1].push_back(make_pair(a * 2, d * 4));
  }

  vector<int> d_fox(n, INT_MAX);
  vector<int> d_wolf(n * 2, INT_MAX);

  dijkstra(graph, n, 0, d_fox);
  dijkstra(graph_wolf, 2 * n, 0, d_wolf);

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (d_fox[i] < MIN(d_wolf[i * 2], d_wolf[i * 2 + 1])) cnt++;
  }
  printf("%d\n", cnt);

  return 0;
}
