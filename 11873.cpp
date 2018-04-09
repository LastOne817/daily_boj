#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define UP 0
#define DOWN 1
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

int height(vector<vector<int> >& board, int hpos, int vpos, int dir, int top, int bottom) {
  int i;
  if (dir == UP) {
    for (i = 0; vpos - i >= top && board[vpos - i][hpos]; i++);
    return i;
  } else {
    for (i = 0; vpos + i < bottom && board[vpos + i][hpos]; i++);
    return i;
  }
}

int search(vector<vector<int> >& board, int left, int right, int top, int bottom, map<pair<pair<int, int>, pair<int, int>>, int>& mem) {
  if (left >= right || top >= bottom) return 0;
  if (left == right - 1) {
    int max_len = 0;
    int len = 0;
    for (int i = left; i < right; i++) {
      if (board[top][i]) len++;
      else len = 0;
      if (len > max_len) max_len = len;
    }
    return max_len;
  }
  if (top == bottom - 1) {
    int max_len = 0;
    int len = 0;
    for (int i = top; i < bottom; i++) {
      if (board[i][left]) len++;
      else len = 0;
      if (len > max_len) max_len = len;
    }
    return max_len;
  }
  pair<pair<int, int>, pair<int, int>> key = make_pair(make_pair(top, left), make_pair(bottom, right));
  auto iter = mem.find(key);
  if (iter != mem.end()) {
    return iter->second;
  }
  int options[5];
  options[0] = search(board, left, right, top, (top + bottom) / 2, mem);
  options[1] = search(board, left, right, (top + bottom) / 2, bottom, mem);
  options[2] = search(board, left, (left + right) / 2, top, bottom, mem);
  options[3] = search(board, (left + right) / 2, right, top, bottom, mem);

  int h_mid = (top + bottom) / 2;
  int v_mid = (left + right) / 2;
  int l = v_mid - 1;
  int r = v_mid;
  int t = h_mid - 1;
  int b = h_mid;
  int up, down;
  up = MIN(height(board, l, t, UP, top, bottom), height(board, r, t, UP, top, bottom));
  down = MIN(height(board, l, b, DOWN, top, bottom), height(board, r, b, DOWN, top, bottom));
  l--;
  r++;
  int max_area = (down + up) * 2;
  while (l >= left && r < right) {
    int left_upper = height(board, l, t, UP, top, bottom);
    int left_lower = height(board, l, b, DOWN, top, bottom);
    int right_upper = height(board, r, t, UP, top, bottom);
    int right_lower = height(board, r, b, DOWN, top, bottom);
    if (MIN(left_lower, down) + MIN(left_upper, up) > MIN(right_lower, down) + MIN(right_upper, up) ) {
      down = MIN(left_lower, down);
      up = MIN(left_upper, up);
      if ((up + down) * (r - l) > max_area) max_area = (up + down) * (r - l);
      l--;
    } else {
      down = MIN(right_lower, down);
      up = MIN(right_upper, up);
      if ((up + down) * (r - l) > max_area) max_area = (up + down) * (r - l);
      r++;
    }
  }
  while (l >= left) {
    int left_upper = height(board, l, t, UP, top, bottom);
    int left_lower = height(board, l, b, DOWN, top, bottom);
    down = MIN(left_lower, down);
    up = MIN(left_upper, up);
    if ((up + down) * (r - l) > max_area) max_area = (up + down) * (r - l);
    l--;
  }
  while (r < right) {
    int right_upper = height(board, r, t, UP, top, bottom);
    int right_lower = height(board, r, b, DOWN, top, bottom);
    down = MIN(right_lower, down);
    up = MIN(right_upper, up);
    if ((up + down) * (r - l) > max_area) max_area = (up + down) * (r - l);
    r++;
  }
  options[4] = max_area;
  
  int result = options[0];
  for (int i = 1; i < 5; i++) {
    if (options[i] > result) result = options[i];
  }
  mem[key] = result;
  return result;
}

int main(void) {
  int n, m, e;
  while (true) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) break;
    vector<vector<int> > board;
    map<pair<pair<int, int>, pair<int, int>>, int> mem;
    board.reserve(n);

    for (int i = 0; i < n; i++) {
      board.push_back(vector<int>());
      board[i].reserve(m);
      for (int j = 0; j < m; j++) {
        scanf("%d", &e);
        board[i].push_back(e);
      }
    }

    printf("%d\n", search(board, 0, m, 0, n, mem));
  }

  return 0;
}
