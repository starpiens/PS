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

char in[1000000];

int main() {
    scanf("%s", in);

    bool ig = 0;
    int cnt = 0;
    char * s = in;
    while (*(++s)) {
        if (*s != in[0] && !ig) {
            ig = 1; 
            cnt++;
        }
        if (*s == in[0]) ig = 0;
    }
    printf("%d", cnt);

    return 0;
}