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

int A[100];

int main() {
    int N, M, mxA = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        mxA = max(mxA, A[i]);
    }
    int diffSum = 0;
    for (int i = 0; i < N; i++) {
        diffSum += mxA - A[i];
    }
    if (diffSum >= M) {
        printf("%d ", mxA);
    } else {
        int remain = M - diffSum;
        printf("%d ", mxA + (remain + N - 1) / N);
    }
    printf("%d", mxA + M);

    return 0;
}