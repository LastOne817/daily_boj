#include <cstdio>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  }
};

int main(void) {
  int board[502][502];
  int visit[502][502];
  int count[502][502];
  int m, n;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      count[i][j] = 0;
      visit[i][j] = 0;
    }
  }
  count[0][0] = 1;

  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

  pq.push(make_pair(0 * m + 0, board[0][0]));

  while (!pq.empty()) {
    int pos = pq.top().first;
    int x = pos % m;
    int y = pos / m;
    pq.pop();
    if (visit[y][x]) continue;
    else visit[y][x] = 1;
    if (x == m - 1 && y == n - 1) break;
    if (x > 0 && board[y][x - 1] < board[y][x]) {
      count[y][x - 1] += count[y][x];
      pq.push(make_pair((x - 1) + y * m, board[y][x - 1]));
    }
    if (x < m - 1 && board[y][x + 1] < board[y][x]) {
      count[y][x + 1] += count[y][x];
      pq.push(make_pair((x + 1) + y * m, board[y][x + 1]));
    }
    if (y > 0 && board[y - 1][x] < board[y][x]) {
      count[y - 1][x] += count[y][x];
      pq.push(make_pair(x + (y - 1) * m, board[y - 1][x]));
    }
    if (y < n - 1 && board[y + 1][x] < board[y][x]) {
      count[y + 1][x] += count[y][x];
      pq.push(make_pair(x + (y + 1) * m, board[y + 1][x]));
    }
  }

  printf("%d\n", count[n - 1][m - 1]);

  return 0;
}
