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

int N, K;
int in[101];
vector<int> v[101];
int is_on[101];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &in[i]);
        v[in[i]].push_back(i);
    }
    
    for (int i = 1; i <= K; i++) {
        v[i].push_back(INF);
    }

    int res = 0;
    for (int i = 0; i < K; i++) {
        int cur = in[i];
        if (!is_on[cur]) {
            // 남은 구멍이 없음
            if (!N) {
                // 다음 사용이 가장 늦은 것 찾기
                int last = cur;
                for (int j = 1; j <= K; j++) {
                    if (is_on[j] && v[last][0] < v[j][0]) {
                        last = j;
                    }
                }
                is_on[last] = 0;
                res++;
            } else N--;
            is_on[cur] = 1;
        }
        v[cur].erase(v[cur].begin());
    }
    printf("%d", res);

    return 0;
}
/*
2 11
1 2 3 1 3 1 3 1 3 1 2
--> 2
*/