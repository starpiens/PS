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

int in[10000];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    
    sort(in, in + N);

    int ans = 0;
    int i = 0;
    int max_dist = 0;
    // < 0
    while (i < N && in[i] < 0) {
        for (int j = 0; j < M && i < N && in[i] < 0; j++) {
            if (!j) {
                max_dist = max(max_dist, ABS(in[i]));
                ans += ABS(in[i]) * 2;
            }
            i++;
        }
    }
    i = N - 1;
    while (i >= 0 && in[i] > 0) {
        for (int j = 0; j < M && i >= 0 && in[i] > 0; j++) {
            if (!j) {
                max_dist = max(max_dist, in[i]);
                ans += in[i] * 2;
            }
            i--;
        }
    }
    printf("%d", ans - max_dist);

    return 0;
}