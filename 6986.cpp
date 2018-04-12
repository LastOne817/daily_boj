#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  vector<int> score;
  int a, b;
  int n, k;
  scanf("%d %d", &n, &k);
  score.reserve(n);
  for (int i = 0; i < n; i++) {
    scanf("%d.%d", &a, &b);
    score.push_back(10 * a + b);
  }

  sort(score.begin(), score.end());

  int cut_sum = 0, ls_sum = 0;
  for (int i = 0; i < n; i++) {
    if (i < k) {
      ls_sum += score[k];
    } else if (i >= n - k) { 
      ls_sum += score[n - k - 1];
    } else {
      cut_sum += score[i];
      ls_sum += score[i];
    }
  }
  printf("%.2f\n%.2f\n", round((double)cut_sum / (n - 2 * k) * 10) / 100, round((double)ls_sum / n * 10) / 100);

  return 0;
}
