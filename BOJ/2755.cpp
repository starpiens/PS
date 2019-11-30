#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

vector< pair< const char *, double > > score;

int main() {
    score.push_back({"A+", 4.3});
    score.push_back({"A0", 4.0});
    score.push_back({"A-", 3.7});
    score.push_back({"B+", 3.3});
    score.push_back({"B0", 3.0});
    score.push_back({"B-", 2.7});
    score.push_back({"C+", 2.3});
    score.push_back({"C0", 2.0});
    score.push_back({"C-", 1.7});
    score.push_back({"D+", 1.3});
    score.push_back({"D0", 1.0});
    score.push_back({"D-", 0.7});

    int N;
    double ans = 0;
    int weight_sum = 0;
    scanf("%d", &N);
    while (N--) {
        char buf[100];
        int weight;
        scanf("%s", buf);
        scanf("%d", &weight);
        scanf("%s", buf);
        weight_sum += weight;
        for (auto i : score) {
            if (!strcmp(i.first, buf))
                ans += weight * i.second;
        }
    }
    ans /= weight_sum;
    ans = round(ans * 100) / 100;
    printf("%.2lf", ans);

    return 0;
}