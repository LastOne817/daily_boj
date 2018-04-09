#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

long long search(vector<int>& h, int start, int end) {
  if (start == end - 1) {
    return h[start];
  } else {
    long long lhs = search(h, start, (start + end) / 2);
    long long rhs = search(h, (start + end) / 2, end);

    long long left = (start + end) / 2 - 1;
    long long right = (start + end) / 2;
    long long min_h = MIN(h[left], h[right]);
    left--;
    right++;
    long long max_current = min_h * 2;
    while (left >= start && right < end) {
      if (h[left] < h[right]) {
        min_h = MIN(min_h, h[right]);
        if (min_h * (right - left) > max_current) {
          max_current = min_h * (right - left);
        }
        right++;
      } else {
        min_h = MIN(min_h, h[left]);
        if (min_h * (right - left) > max_current) {
          max_current = min_h * (right - left);
        }
        left--;
      }
    }
    while (left >= start) {
      min_h = MIN(min_h, h[left]);
      if (min_h * (right - left) > max_current) {
        max_current = min_h * (right - left);
      }
      left--;
    }
    while (right < end) {
      min_h = MIN(min_h, h[right]);
      if (min_h * (right - left) > max_current) {
        max_current = min_h * (right - left);
      }
      right++;
    }
    return MAX(MAX(lhs, rhs), max_current);
  }
}

int main(void) {
  int n;
  int h_i;

  while (true) {
    vector<int> h;
    vector<int> min_tree;
    scanf("%d", &n);
    if (n == 0) break;
    h.reserve(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &h_i);
      h.push_back(h_i);
    }
    printf("%lld\n", search(h, 0, n));
  }

  return 0;
}
