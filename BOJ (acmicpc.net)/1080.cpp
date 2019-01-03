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
#include <random>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int A[50][50], B[50][50];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &A[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &B[i][j]);

    int ans = 0;
    for (int i = 0; i <= N - 3; i++)
        for (int j = 0; j <= M - 3; j++)
            if (A[i][j] != B[i][j]) {
                ans++;
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++)
                        A[i + k][j + l] ^= 1;
            }
    
    int fail = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            fail |= (A[i][j] != B[i][j]);

    printf("%d", fail ? -1 : ans);

    return 0;
}