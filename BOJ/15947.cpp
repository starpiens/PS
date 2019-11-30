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

const char * str = "baby sukhwan tururu turu very cute tururu turu in bed tururu turu baby sukhwan ";

int main() {
    int N;
    scanf("%d", &N);
    N--;
    
    int i, idx = 0;
    for (i = 0; i < N % 14; i++) {
        while (str[idx++] != ' ');
    }

    if (i % 4 >= 2) {
        int ru = N / 14 + (i % 4 == 2) + 1;
        if (ru >= 5)
            printf("tu+ru*%d", ru);
        else {
            printf("tu");
            while (ru--)
                printf("ru");
        }
    } else {
        while (str[idx] != ' ')
            printf("%c", str[idx++]);
    }

    return 0;
}