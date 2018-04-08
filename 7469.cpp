#include <cstdio>
#include <queue>

using namespace std;

#define MIN(x,y) ((x) < (y) ? (x) : (y))

vector<int> merge(vector<int>& a, vector<int>& b) {
  int i = 0, j = 0;
  vector<int> merged;
  merged.reserve(a.size() + b.size());
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      merged.push_back(a[i]);
      i++;
    } else {
      merged.push_back(b[j]);
      j++;
    }
  }
  while (i < a.size()) {
    merged.push_back(a[i]);
    i++;
  }
  while (j < b.size()) {
    merged.push_back(b[j]);
    j++;
  }
  return merged;
}

vector<int> merge_k(vector<int>& a, vector<int>& b, int k) {
  int i = 0, j = 0;
  vector<int> merged;
  merged.reserve(MIN(a.size() + b.size(), k));
  while (i < a.size() && j < b.size() && i + j < k) {
    if (a[i] < b[j]) {
      merged.push_back(a[i]);
      i++;
    } else {
      merged.push_back(b[j]);
      j++;
    }
  }
  while (i < a.size() && i + j < k) {
    merged.push_back(a[i]);
    i++;
  }
  while (j < b.size() && i + j < k) {
    merged.push_back(b[j]);
    j++;
  }
  return merged;
}

vector<int> search(vector<vector<int> >& tree, int node, int start, int end, int left, int right, int k) {
  if (left > end || right < start) {
    return vector<int>();
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  auto lhs = search(tree, node << 1, start, (start + end) / 2, left, right, k);
  auto rhs = search(tree, (node << 1) + 1, (start + end) / 2 + 1, end, left, right, k);
  return merge_k(lhs, rhs, k);
}

int main(void) {
  vector<int> arr;
  vector<vector<int> > sorted_tree;
  int n, m;
  scanf("%d %d", &n, &m);
  arr.reserve(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int leaf_count;
  for (leaf_count = 1; leaf_count < n; leaf_count <<= 1);
  sorted_tree.reserve(leaf_count << 1);

  for (int i = 0; i < n; i++) {
    sorted_tree[i + leaf_count] = vector<int>(1, arr[i]);
  }
  for (int i = n; i < leaf_count; i++) {
    sorted_tree[i + leaf_count] = vector<int>();
  }

  for (int start = leaf_count >> 1; start >= 1; start >>= 1) {
    for (int i = start; i < start << 1; i++) {
      sorted_tree[i] = merge(sorted_tree[i << 1], sorted_tree[(i << 1) + 1]);
    }
  }

  for (int t = 0; t < m; t++) {
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);
    auto sorted_range = search(sorted_tree, 1, 1, leaf_count, i, j, k);
    printf("%d\n", sorted_range[k - 1]);
  }

  return 0;
}
