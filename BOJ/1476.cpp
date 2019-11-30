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

int main() {
    int E, S, M, i;
    scanf("%d %d %d", &E, &S, &M);
    for (i = 1; E + S + M > 3; i++) {
        if (--E == 0) E = 15;
        if (--S == 0) S = 28;
        if (--M == 0) M = 19;
    }
    printf("%d", i);

    return 0;
}