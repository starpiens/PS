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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    ll N, M;
    while (scanf("%lld %lld", &M, &N), (N || M)) {
        while (M) {
            ll minus_n = (N + M - 1) / M;
            while (true) {
                ll G = gcd(N, minus_n);
                ll common_n = N * minus_n / G;
                ll m1 = M * minus_n / G;
                ll m2 = N / G;
                ll result_m = m1 - m2;
                G = gcd(result_m, common_n);
                result_m /= G;
                common_n /= G;
                if (common_n < 1000000) {
                    printf("%lld ", minus_n);
                    N = common_n;
                    M = result_m;
                    break;
                }
                minus_n++;
            }
        }
        printf("\n");
    }

    return 0;
}