#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

struct Team {
    int K, Da, Db;
} in[1000];

int main() {
    int N, A, B;
    while (scanf("%d %d %d", &N, &A, &B), N) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &in[i].K, &in[i].Da, &in[i].Db);
        }

        sort(in, in + N, [](Team l, Team r) -> bool { return ABS(l.Da - l.Db) > ABS(r.Da - r.Db); });

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int ca, cb;
            if (in[i].Da < in[i].Db) {
                ca = min(A, in[i].K);
                cb = in[i].K - ca;
            } else {
                cb = min(B, in[i].K);
                ca = in[i].K - cb;
            }
            ans += ca * in[i].Da + cb * in[i].Db;
            A -= ca;
            B -= cb;
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
3 15 15
10 20 10
10 10 30
10 40 10
0 0 0
*/