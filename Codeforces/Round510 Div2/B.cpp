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

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int C[1001], vit[1001], dp[8][1001];
int to_num(char c) { return 1 << (c - 'A'); }

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &C[i]);
        char in[4];
        scanf("%s", in);
        for (int j = 0; in[j]; j++)
            vit[i] += to_num(in[j]);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j <= 1000; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 8; j++)
            dp[j][i] = dp[j][i - 1];
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                if ((j | vit[i]) == k)
                    dp[k][i] = min(dp[k][i], dp[j][i - 1] + C[i]);
    }
    int min_v = INF;
    for (int i = 1; i <= N; i++)
        min_v = min(min_v, dp[7][i]);
    printf("%d", min_v == INF ? -1 : min_v);

    return 0;
}