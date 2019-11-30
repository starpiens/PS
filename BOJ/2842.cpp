#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, h[50][50], vis[50][50], mxh = 0;
char g[50][51];
int dr[] = { -1,0,1,1,1,0,-1,-1 };
int dc[] = { 1,1,1,0,-1,-1,-1,0 };
int numK, Prow, Pcol;

int runff(int row, int col, int l, int r) {
   if (row < 0 || row == N || col < 0 || col == N ||
      vis[row][col] || h[row][col] < l || h[row][col] > r) return 0;
   vis[row][col] = 1;
   int ret = g[row][col] == 'K';
   for (int i = 0; i < 8; i++)
      ret += runff(row + dr[i], col + dc[i], l, r);
   return ret;
}

int ff(int l, int r) {
   memset(vis, 0, sizeof(vis));
   return runff(Prow, Pcol, l, r) == numK;
}

int main() {
   scanf("%d", &N);
   for (int i = 0; i < N; i++) {
      scanf(" %s", g[i]);
      for (int j = 0; j < N; j++) {
         if (g[i][j] == 'K') numK++;
         if (g[i][j] == 'P') {
            Prow = i;
            Pcol = j;
         }
      }
   }
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
         scanf(" %d", &h[i][j]);
         mxh = max(mxh, h[i][j]);
      }

   int ans = 1e6;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
         int l = h[i][j], r = min(mxh, h[i][j] + ans);
         while (l < r) {
            int m = (l + r) >> 1;
            if (ff(h[i][j], m)) r = m;
            else l = m + 1;
         }
         if (ff(h[i][j], l) && ans > l - h[i][j]) ans = l - h[i][j];
      }
   printf("%d", ans);
   return 0;
}