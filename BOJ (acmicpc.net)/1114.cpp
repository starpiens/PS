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
    int L, K, C;
    scanf("%d %d %d", &L, &K, &C);
    for (int i = 0; i < K; i++)
        scanf("%d", &in[i]);
    sort(in, in + K);
    
    int l = 1, r = L;
    while (l < r) {
        int m = (l + r) >> 1;
        int cnt = 0;
        int prv = 0, cur_idx = 0;
        // 자르기
        while (cnt < C) {
            while (cur_idx < K && in[cur_idx] - prv <= m) 
                cur_idx++;
            prv = cur_idx ? in[cur_idx - 1] : 0;
            cnt++;
        }
        // 남은 조각
        if (L - prv <= m) r = m;
        else l = m + 1;
    }
    printf("%d ", l);

    int cnt = 0;
    int prv = L, cur_idx = K - 1;
    while (cnt < C) {
        while (cur_idx >= 0 && prv - in[cur_idx] <= l)
            cur_idx--;
        prv = cur_idx < K - 1 ? in[cur_idx + 1] : L;
        cnt++;
    }
    printf("%d", prv);

    return 0;
}