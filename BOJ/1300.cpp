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

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int l = 1, r = K, ans;
    while (l < r) {
        int m = (l + r) >> 1;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
            cnt += min(m / i, N);
        if (cnt < K) l = m + 1;
        else r = m;
    }
    printf("%d", l);

    return 0;
}