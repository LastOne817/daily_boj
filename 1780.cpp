#include <cstdio>
#include <vector>

using namespace std;

vector<int> count(vector<vector<int> >& paper, int left, int top, int n) {
  vector<int> result{ 0, 0, 0 };
  if (n == 1) {
    if (paper[left][top] == -1) result[0] = 1;
    else if (paper[left][top] == 0) result[1] = 1;
    else result[2] = 1;
    return result;
  }

  int pivot = paper[left][top];
  bool flag = true;
  for (int i = left; i < left + n && flag; i++) {
    for (int j = top; j < top + n && flag; j++) {
      if (paper[i][j] != pivot) flag = false;
    }
  }

  if (flag) {
    if (paper[left][top] == -1) result[0] = 1;
    else if (paper[left][top] == 0) result[1] = 1;
    else result[2] = 1;
    return result;
  } else {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        auto v = count(paper, left + n / 3 * i, top + n / 3 * j, n / 3);
        result[0] += v[0];
        result[1] += v[1];
        result[2] += v[2];
      }
    }
    return result;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  vector<vector<int> > paper(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &paper[i][j]);
    }
  }
  auto result = count(paper, 0, 0, n);
  printf("%d\n%d\n%d\n", result[0], result[1], result[2]);
  return 0;
}
