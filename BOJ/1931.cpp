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

pair<int, int> in[100000];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &in[i].second, &in[i].first);
    
    sort(in, in + N);
    
    int last = 0;
    int i, j = 0;
    for (i = 0; ; i++) {
        while (j < N && last > in[j].second) j++;
        if (j == N) break;
        last = in[j].first;
        in[j].second = -1;
    }
    printf("%d", i);

    return 0;
}