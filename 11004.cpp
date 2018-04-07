#include <cstdio>
#include <vector>

using namespace std;

int qfind_r(vector<int>& arr, int n, int k, int l, int r) {
  int left = l + 1;
  int right = r;
  int pivot = l;
  int tmp;

  while (left < right) {
    if (arr[left] <= arr[pivot]) {
      left++;
    } else if (arr[right] >= arr[pivot]) {
      right--;
    } else {
      tmp = arr[left];
      arr[left] = arr[right];
      arr[right] = tmp;
    }
  }
  if (arr[left] > arr[pivot]) left--;
  tmp = arr[pivot];
  arr[pivot] = arr[left];
  arr[left] = tmp;

  pivot = left;

  if (pivot < k) return qfind_r(arr, n, k, pivot + 1, r);
  else if (pivot > k) return qfind_r(arr, n, k, l, pivot - 1);
  else return arr[pivot];
}

int main(void) {
  vector<int> arr;
  int n, k;
  scanf("%d %d", &n, &k);
  arr.reserve(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("%d\n", qfind_r(arr, n, k - 1, 0, n - 1));

  return 0;
}
