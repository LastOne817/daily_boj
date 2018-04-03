#include <cstdio>
#include <set>

using namespace std;

int main(void) {
  int n, k;
  long long sum = 0;
  int pivot;
  int t[5010];

  multiset<int> left;
  multiset<int> right;
  multiset<int>::iterator it;

  scanf("%d %d", &n, &k);

  scanf("%d", &t[0]);
  left.insert(t[0]);
  for (int i = 1; i < k; i++) {
    scanf("%d", &t[i]);
    if (t[i] < *left.rbegin()) {
      left.insert(t[i]);
    } else {
      right.insert(t[i]);
    }

    if (left.size() < right.size()) {
      it = right.begin();
      left.insert(*it);
      right.erase(it);
    } else if (left.size() > right.size() + 1) {
      it = --left.end();
      right.insert(*it);
      left.erase(it);
    }
  }
  sum += *left.rbegin();

  for (int i = k; i < n; i++) {
    int t_pop = t[i % k];
    scanf("%d", &t[i % k]);
    if (t_pop <= *left.rbegin()) {
      it = left.find(t_pop);
      left.erase(it);
    } else {
      it = right.find(t_pop);
      right.erase(it);
    }
    if (left.size() < right.size()) {
      it = right.begin();
      left.insert(*it);
      right.erase(it);
    } else if (left.size() > right.size() + 1) {
      it = --left.end();
      right.insert(*it);
      left.erase(it);
    }

    if (left.empty() || t[i % k] < *left.rbegin()) {
      left.insert(t[i % k]);
    } else {
      right.insert(t[i % k]);
    }

    if (left.size() < right.size()) {
      it = right.begin();
      left.insert(*it);
      right.erase(it);
    } else if (left.size() > right.size() + 1) {
      it = --left.end();
      right.insert(*it);
      left.erase(it);
    }
    sum += *left.rbegin();
  }

  printf("%lld\n", sum);
  return 0;
}
