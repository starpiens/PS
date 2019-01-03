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

int chk[50001], in[50001];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    
    chk[0] = 1;
    for (int i = 0; i < N; i++) {
        if (chk[in[i]]) {
            in[i]++;
        } else if (!chk[in[i] - 1]) {
            chk[in[i]] = chk[in[i] - 1] = 1;
            in[i]--;
        } else chk[in[i]] = 1;
    }
    
    for (int i = 0; i < N; i++)
        printf("%d ", in[i]);

    return 0;
}