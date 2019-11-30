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
#include <fstream>
#include <random>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

char S[101], K[101];
char rS[101];

int i, j;
int ri;

int main() {
    scanf("%s %s", S, K);
    
    while (S[i]) {
        if (!isdigit(S[i])) 
            rS[ri++] = S[i];
        i++;
    }

    int len_k = strlen(K);
    for (ri = 0; rS[ri + len_k - 1]; ri++) {
        for (j = 0; j < len_k; j++)
            if (rS[ri + j] != K[j]) break;
        if (j == len_k) return printf("1"), 0;
    }

    printf("0");
    return 0;
}