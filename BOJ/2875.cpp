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
    int N, M, K;
    int cnt = 0;

    scanf("%d %d %d", &N, &M, &K);
    
    while (N >= 2 && M >= 1 && N + M - 3 >= K) {
        cnt++;
        N -= 2;
        M -= 1;
    }
    printf("%d", cnt);

    return 0;
}