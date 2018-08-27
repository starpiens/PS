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
    for (int i = 0; i < 3; i++) {
        int mx = 1, cnt = 1;
        char in[10];
        scanf("%s", in);
        for (int j = 0; j < 7; j++) {
            if (in[j] == in[j + 1]) cnt++;
            else cnt = 1;
            mx = max(cnt, mx);
        }
        printf("%d\n", mx);
    }

    return 0;
}