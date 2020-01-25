#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long llu;

const int MOD = 1234567891;

int main() {
    int L;
    char in[51];
    scanf("%d %s", &L, in);

    llu res = 0;
    int len = strlen(in);
    for (int i = len - 1; i >= 0; i--) {
        res *= 31;
        (res += in[i] - 'a' + 1) %= MOD;
    }
    printf("%llu", res);
    return 0;
}