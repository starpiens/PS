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

int main() {
    int in[3][10], sa = 0, sb = 0, lw = -1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 10; j++)
            scanf("%d", &in[i][j]);
    
    for (int i = 0; i < 10; i++) {
        if (in[0][i] < in[1][i]) {
            sb += 3;
            lw = 1;
        } else if (in[0][i] > in[1][i]) {
            sa += 3;
            lw = 0;
        } else sa++, sb++;
    }

    printf("%d %d\n", sa, sb);
    if (sa > sb) printf("A");
    else if (sa < sb) printf("B");
    else if (lw < 0) printf("D");
    else if (lw) printf("B");
    else printf("A");

    return 0;
}