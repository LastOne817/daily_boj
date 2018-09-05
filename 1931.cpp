#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool latest_start (pair<int, int>& lhs, pair<int, int>& rhs) {
  if (lhs.first == rhs.first) return lhs.second > rhs.second;
  else return lhs.first > rhs.first;
}

int main(void) {
  vector<pair<int, int> > l;
  int start, end;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &start, &end);
    l.push_back(make_pair(start, end));
  }

  sort(l.begin(), l.end(), latest_start);

  int cnt = 1;
  int s = l[0].first;
  for (int i = 1; i < n; i++) {
    if (l[i].second <= s) {
      cnt++;
      s = l[i].first;
    }
  }
  printf("%d\n", cnt);

  return 0;
}
