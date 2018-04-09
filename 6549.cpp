#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define LEFT(x) ((x) * 2)
#define RIGHT(x) ((x) * 2 + 1)

void init_tree(vector<int>& tree, vector<int>& h, int node, int n, int leaf_count) {
  if (node >= leaf_count) {
    if (node - leaf_count < n) tree[node] = h[node - leaf_count];
    else tree[node] = INT_MAX;
  } else {
    init_tree(tree, h, LEFT(node), n, leaf_count);
    init_tree(tree, h, RIGHT(node), n, leaf_count);
    tree[node] = MIN(tree[LEFT(node)], tree[RIGHT(node)]);
  }
}

int search(vector<int>& tree, int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return INT_MAX;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  auto lhs = search(tree, LEFT(node), start, (start + end) / 2, left, right);
  auto rhs = search(tree, RIGHT(node), (start + end) / 2 + 1, end, left, right);
  return MIN(lhs, rhs);
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

    int leaf_count;
    for (leaf_count = 1; leaf_count < n; leaf_count <<= 1);

    min_tree.reserve(leaf_count << 1);
    init_tree(min_tree, h, 1, n, leaf_count);

    int result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int area = (j - i + 1) * search(min_tree, 1, 1, n, i + 1, j + 1);
        if (area > result) result = area;
      }
    }
    printf("%d\n", result);
  }

  return 0;
}
