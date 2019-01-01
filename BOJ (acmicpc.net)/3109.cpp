#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int R, C;
int g[10000][500];

bool f(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || g[r][c]) return false;
    g[r][c] = 1;
    if (c == C - 1)
        return true;

    for (int i = -1; i <= 1; i++)
        if (f(r + i, c + 1))
            return true;
    
    return false;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            char c;
            scanf(" %c", &c);
            g[i][j] = c == 'x';
        }
    
    int res = 0;
    for (int i = 0; i < R; i++)
        res += f(i, 0);
    printf("%d", res);

    return 0;
}