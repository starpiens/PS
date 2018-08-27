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

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int in[100000];
int main() {
    int N, K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    scanf("%d", &K);
    bool chk = 0;
    for (int i = 0; i < N; i++) {
        chk |= in[i] > (ll)K * (i + 1);
        if (in[i] == (ll)K * (i + 1) || (chk && in[i] < (ll)K * (i + 1)))
            return printf("T"), 0;
    }
    printf("F");

    return 0;
}