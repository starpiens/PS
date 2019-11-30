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

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int main() {
    int N, st, end, ans = 0;
    scanf("%d %d %d", &N, &st, &end);
    for (int i = 1; i < N; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        if (end < X) {
            ans += end - st;
            st = X;
        }
        end = max(end, Y);
    }
    ans += end - st;
    printf("%d", ans);

    return 0;
}