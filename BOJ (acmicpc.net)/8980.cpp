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
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

struct Info {
    int st, end, box;
};

vector<Info> v;
int lim[2000], res;

int main() {
    int N, C, M;
    scanf("%d %d", &N, &C);
    scanf("%d", &M);

    fill(lim, lim + N, C);
    v.resize(M);
    for (auto & i : v) {
        scanf("%d %d %d", &i.st, &i.end, &i.box);
    }
    sort(v.begin(), v.end(), [](Info & l, Info & r) -> bool { return l.end < r.end; });

    for (auto & i : v) {
        int carry = i.box;
        for (int j = i.st; j < i.end; j++)
            carry = min(carry, lim[j]);
        res += carry;
        for (int j = i.st; j < i.end; j++)
            lim[j] -= carry;
    }
    printf("%d", res);

    return 0;
}