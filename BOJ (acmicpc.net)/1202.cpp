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

pair<int, int> jew[300000]; // <weight, value>
int bag[300000];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jew[i].first, &jew[i].second);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &bag[i]);
    }
    sort(jew, jew + N);
    sort(bag, bag + K);

    llu res = 0;
    priority_queue<int> pq;
    int idx = 0;
    for (int i = 0; i < K; i++) {
        while (jew[idx].first <= bag[i]) {
            pq.push(jew[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    printf("%llu", res);

    return 0;
}