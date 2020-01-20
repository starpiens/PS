#include <cstdio>
#include <algorithm>

const int MAX_N = 20;
const int MAX_STEP = 10;

using namespace std;

int N;
int g_max;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

struct State {
  int board[MAX_N][MAX_N];
  int max_value = 0;

  // dir 방향으로 이동시킨 후의 State 객체 리턴. 변경점이 없는 경우 nullptr.
  State *move(int dir) {
      auto *next_state = new State();

      bool updated = false;
      for (int i = 0; i < N; i++) {
          int end = (dr[dir] + dc[dir] > 0) * (N - 1);
          for (int j = 0; j < N; j++) {
              // (i, j) -> (r, c).
              int r, c;
              if (dr[dir] + dc[dir] > 0) r = N - 1 - j, c = i;
              else r = j, c = i;
              if (!dr[dir]) swap(r, c);

              next_state->board[r][c] = board[r][c];
              if (!board[r][c]) continue;
              next_state->max_value = max(next_state->max_value, board[r][c]);
              if ((dr[dir] ? r : c) == end) continue;

              int &endpoint = dr[dir] ? next_state->board[end][c] : next_state->board[r][end];
              if (endpoint) {
                  end -= (dr[dir] + dc[dir]);
                  if (endpoint == next_state->board[r][c]) {
                      next_state->board[r][c] = 0;
                      next_state->max_value = max(next_state->max_value, endpoint *= 2);
                      updated = true;
                  } else if ((dr[dir] ? r : c) != end) {
                      swap(dr[dir] ? next_state->board[end][c] : next_state->board[r][end], next_state->board[r][c]);
                      updated = true;
                  }
              } else {
                  swap(dr[dir] ? next_state->board[end][c] : next_state->board[r][end], next_state->board[r][c]);
                  updated = true;
              }
          }
      }

      if (!updated) {
          free(next_state);
          next_state = nullptr;
      }
      return next_state;
  }
};

void dfs(int n, State s) {
    g_max = max(g_max, s.max_value);
    if (n == MAX_STEP) return;
    if ((s.max_value << (MAX_STEP - n)) <= g_max) return;
    for (int dir = 0; dir < 4; dir++) {
        auto ns = s.move(dir);
        if (ns != nullptr) {
            dfs(n + 1, *ns);
            free(ns);
        }
    }
}

int main() {
    scanf("%d", &N);
    State s;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &s.board[i][j]);
            s.max_value = max(s.max_value, s.board[i][j]);
        }
    dfs(0, s);
    printf("%d", g_max);
    return 0;
}