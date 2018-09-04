#include <cstdio>
#include <vector>

using namespace std;

void traverse(vector<int>& in_order, vector<int>& post_order, int start_in, int end_in, int start_post, int end_post) {
  if (start_in > end_in) return;
  int root = post_order[end_post];
  int i;
  for (i = 0; in_order[end_in - i] != root; i++);
  printf("%d ", root);
  traverse(in_order, post_order, start_in, end_in - i - 1, start_post, end_post - i - 1);
  traverse(in_order, post_order, end_in - i + 1, end_in, end_post - i, end_post - 1);
}

int main(void) {
  int n;
  int node_id;
  scanf("%d", &n);

  vector<int> in_order (n);
  vector<int> post_order (n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &node_id);
    in_order[i] = node_id;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &node_id);
    post_order[i] = node_id;
  }

  traverse(in_order, post_order, 0, n - 1, 0, n - 1);
  printf("\n");
  
  return 0;
}
