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

int A[101], B[101];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        A[a]++;
        B[b]++;
        int ans = 0;
        int idx_a = 1, idx_b = 100;
        int A_cpy[101], B_cpy[101];
        memcpy(A_cpy, A, sizeof(A));
        memcpy(B_cpy, B, sizeof(B));

        while (true) {
            while (idx_a <= 100 && !A_cpy[idx_a]) idx_a++;
            while (idx_b >= 1   && !B_cpy[idx_b]) idx_b--;
            if (idx_a > 100 || idx_b < 1) break;
            ans = max(ans, idx_a + idx_b);
            int min_val = min(A_cpy[idx_a], B_cpy[idx_b]);
            A_cpy[idx_a] -= min_val;
            B_cpy[idx_b] -= min_val;
        }
        printf("%d\n", ans);
    }

    return 0;
}