#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define PI 3.14159265

int main(void) {
  int n;
  vector<pair<long long int, long long int> > p;
  long long int max = 0;
  long long int x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &x, &y);
    if (x*x + y*y > max) max = x*x + y*y;
    if (x*x + y*y < max) continue;
    p.push_back(make_pair(x, y));
  }

  for (auto it = p.begin(); it != p.end(); ) {
    x = it->first;
    y = it->second;
    if (x*x + y*y < max) it = p.erase(it);
    else ++it;
  }

  double max_deg = 0;
  for (int i = 0; i < p.size(); i++) {
    long long int x1 = p[i].first, y1 = p[i].second;
    long long int x2 = p[(i + 1) % p.size()].first, y2 = p[(i + 1) % p.size()].second;
    double deg1 = atan2(double(y1), double(x1));
    double deg2 = atan2(double(y2), double(x2));
    double deg = deg2 - deg1;
    if (deg < 1e-8) deg += 2. * PI;
    if (deg > max_deg) max_deg = deg;
  }

  printf("%lf\n", max_deg * 180. / PI);
  return 0;
}
