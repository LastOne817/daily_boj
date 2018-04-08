#include <cstdio>
#include <queue>

using namespace std;

int q(vector<int>& arr, int start, int end, int k) {
  priority_queue<int> q;
  for (int i = start; i < start + k; i++) {
    q.push(arr[i]);
  }
  for (int i = start + k; i <= end; i++) {
    if (arr[i] < q.top()) {
      q.pop();
      q.push(arr[i]);
    }
  }
  return q.top();
}

int main(void) {
  vector<int> arr;
  int n, m;
  scanf("%d %d", &n, &m);
  arr.reserve(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int t = 0; t < m; t++) {
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);
    printf("%d\n", q(arr, i - 1, j - 1, k));
  }

  return 0;
}
