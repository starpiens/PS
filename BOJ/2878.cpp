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

int in[100000];

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    llu sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
        sum += in[i];
    }
    sum -= M;
    
    sort(in, in + N);

    llu ans = 0;
    for (int i = 0; i < N; i++) {
        int anger = min(in[i], (int)(sum / (N - i)));
        sum -= anger;
        ans += SQR((llu)anger);
    }
    printf("%llu", ans);

    return 0;
}
// 50 2 1 100