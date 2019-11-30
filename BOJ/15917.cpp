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

int main() {
    int Q, a;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &a);
        printf("%d\n", (a & (-a)) == a);
    }

    return 0;
}