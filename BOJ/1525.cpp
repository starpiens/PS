#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

set<int> vis;

struct State {
  int board[3][3];
  int r, c;
  bool isok() {
      for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++)
              if (board[i][j] != i * 3 + j + 1 && i + j != 4)
                  return false;
      return true;
  }
  int val() {
      int ret = 0;
      for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++)
              ret = ret * 10 + board[i][j];
      return ret;
  }
};
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main() {
    State s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &s.board[i][j]), s.board[i][j] == 0) {
                s.r = i;
                s.c = j;
            }
        }
    }

    if (s.isok()) return printf("0"), 0;
    queue<pair<State, int>> q;
    vis.insert(s.val());
    q.emplace(s, 0);
    while (!q.empty()) {
        State now = q.front().first;
        int step = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            State nxt = now;
            nxt.r = now.r + dr[i];
            nxt.c = now.c + dc[i];
            if (nxt.r < 0 || nxt.r > 2 || nxt.c < 0 || nxt.c > 2) continue;
            swap(nxt.board[nxt.r][nxt.c], nxt.board[now.r][now.c]);
            if (vis.find(nxt.val()) != vis.end()) continue;
            if (nxt.isok()) return printf("%d", step + 1), 0;
            vis.insert(nxt.val());
            q.emplace(nxt, step + 1);
        }
    }
    printf("-1");
    return 0;
}