#include <bits/stdc++.h>

using namespace std;

const int SZ = 100001;
char in[2][SZ];
char res[SZ];

int main() {
    scanf("%s %s", in[0], in[1]);

    // pre-process
    int len[2], neg[2];
    for (int i = 0; i < 2; i++) {
        neg[i] = in[i][0] == '-';
        len[i] = strlen(in[i]) - neg[i];
    }
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= len[i]; j++)
            in[i][SZ - j] = (neg[i] ? -1 : 1) * (in[i][len[i] + neg[i] - j] - '0');
    int idx = SZ - max(len[0], len[1]);
    while (in[0][idx] + in[1][idx] == 0) idx++;
    int negRes = (in[0][idx] + in[1][idx]) < 0;

    // calculate
    int carry = 0;
    idx = SZ - 1;
    while (idx >= SZ - max(len[0], len[1])) {
        int sum = in[0][idx] + in[1][idx] + carry;
        carry = 0;
        if ((negRes && sum > 0) || sum > 9) {
            carry++;
            sum -= 10;
        }
        if ((!negRes && sum < 0) || sum < -9) {
            carry--;
            sum += 10;
        }
        res[idx--] = sum;
    }
    res[idx--] = carry;

    // print
    if (negRes) printf("-");
    bool sw = 0;
    while (++idx < SZ) {
        sw |= (res[idx] != 0);
        if (sw) printf("%d", res[idx] * (negRes ? -1 : 1));
    }
    if (!sw) printf("0");

    return 0;
}