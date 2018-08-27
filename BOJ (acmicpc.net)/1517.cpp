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

pair<int, int> in[500000], in2[500000];
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i].first);
        in[i].second = i;
        in2[i] = in[i];
    }
    sort(in2, in2 + N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += ABS(in2[i].second - i);
    }
    printf("%lld", sum / 2);

    return 0;
}