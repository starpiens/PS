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

vector<char> dp[10001][3];

vector<char> & operator+(vector<char> & l, vector<char> & r) {
    vector<char> & res = *new vector<char>();
    int carry = 0;
    for (size_t i = 0; i < max(l.size(), r.size()) || carry; i++) {
        int s = (i < l.size() ? l[i] : 0)
              + (i < r.size() ? r[i] : 0)
              + carry;
        res.push_back(s % 10);
        carry = s / 10;
    }
    return res;
}

void print(vector<char> & v) {
    for (int i = v.size() - 1; i >= 0; i--)
        printf("%d", v[i]);
    printf("\n");
}

int main() {
    dp[3][0].push_back(2);
    dp[3][1].push_back(1);
    dp[3][2].push_back(1);

    dp[4][0].push_back(3);
    dp[4][1].push_back(2);
    dp[4][2].push_back(2);
    
    for (int i = 5; i <= 10000; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][2] + dp[i - 2][2];
    }

    int N;
    while (scanf("%d", &N) != EOF) {
        print(dp[N][0] + dp[N][1] + dp[N][2]);
    }

    return 0;
}