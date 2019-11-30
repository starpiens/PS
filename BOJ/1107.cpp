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
#include <fstream>
#include <random>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

bool chk[10];

int poss(int n) {
    int len = 0;
    do {
        ++len;
        if (chk[n % 10])
            return 0;
        n /= 10;
    } while (n);
    return len;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    while (M--) {
        int x;
        scanf("%d", &x);
        chk[x] = 1;
    }
    int ans = ABS(N - 100);

    for (int i = 0; i < (int)1e6; i++) {
        int ret = poss(max(0, N - i));
        if (ret) {
            ans = min(ans, ret + i);
            break;
        }
        ret = poss(N + i);
        if (ret) {
            ans = min(ans, ret + i);
            break;
        }
    }
    printf("%d", ans);

    return 0;
}