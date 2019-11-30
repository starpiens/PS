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

int N, in;
ll dp[100][21];

int main() {
    scanf("%d", &N);
    scanf("%d", &in);
    dp[0][in] = 1;
    for (int i = 1; i < N - 1; i++) {
        scanf("%d", &in);
        for (int j = 0; j <= 20; j++) {
            if (j - in >= 0) dp[i][j] += dp[i - 1][j - in];
            if (j + in <= 20) dp[i][j] += dp[i - 1][j + in];
        }
    }
    scanf("%d", &in);
    printf("%lld", dp[N - 2][in]);

    return 0;
}