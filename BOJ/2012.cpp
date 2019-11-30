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

int in[500000];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);

    sort(in, in + N);

    llu ans = 0;
    for (int i = 0; i < N; i++) {
        ans += ABS(in[i] - i - 1);
    }
    printf("%llu", ans);

    return 0;
}