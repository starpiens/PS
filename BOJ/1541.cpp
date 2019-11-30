#include <cstdio>

using namespace std;

int main() {
    char in[51];
    scanf("%s", in);
    int sum = 0;
    int val = 0;
    bool chk = 0;
    for (int i = 0; in[i]; i++) {
        if ('0' <= in[i] && in[i] <= '9') {
            val *= 10;
            val += in[i] - '0';
        } else {
            sum += (chk ? -1 : 1) * val;
            val = 0;
            if (in[i] == '-') chk = 1;
        }
    }
    sum += (chk ? -1 : 1) * val;
    printf("%d", sum);
    return 0;
}