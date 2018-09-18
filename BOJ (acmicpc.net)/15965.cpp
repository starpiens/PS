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

char arr[8000000];

int main() {
    int K, cnt = 0;
    scanf("%d", &K);
    for (int i = 2; ; i++) {
        if (!arr[i]) {
            if (++cnt == K) return printf("%d", i), 0;
            for (ll j = ll(i) * i; j < 8000000; j += i)
                arr[j] = 1;
        }
    }

    return 0;
}