#include <cstdio>
#include <stack>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
  while (true) {
    int n;
    stack<pair<long long, long long> > s;
    scanf("%d", &n);
    if (n == 0) break;
    int h;
    long long last;
    long long max_area = 0;
    for (long long i = 0; i < n; i++) {
      scanf("%d", &h);
      last = i;
      while (!s.empty() && s.top().first > h) {
        last = s.top().second;
        max_area = MAX(max_area, s.top().first * (i - last));
        s.pop();
      }
      if (s.empty() || s.top().first < h) s.push(make_pair(h, last));
    }
    while (!s.empty()) {
      max_area = MAX(max_area, s.top().first * (n - s.top().second));
      s.pop();
    }
    printf("%lld\n", max_area);
  }
  return 0;
}
