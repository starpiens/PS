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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

vector< pair<int, int> > in[200001];    // <size, pos>
int sum[2001];
int ans[200000];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int C, S;
        scanf("%d %d", &C, &S);
        in[C].push_back({S, i});
        sum[S] += S;
    }

    for (int i = 1; i <= 2000; i++)
        sum[i] += sum[i - 1];

    for (int i = 1; i <= 200000; i++) {
        if (!in[i].empty()) sort(in[i].begin(), in[i].end());
        int s = 0;
        for (int j = 0; j < in[i].size(); j++) {
            ans[in[i][j].second] = sum[in[i][j].first - 1] - s;
            // 중복 제거
            int k;
            for (k = 1; j + k < in[i].size() && in[i][j].first == in[i][j + k].first; k++) {
                ans[in[i][j + k].second] = ans[in[i][j].second];
            }
            s += in[i][j].first * k;
            j += k - 1;
        }
    }

    for (int i = 0; i < N; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}