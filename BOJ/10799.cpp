#include <bits/stdc++.h>
using namespace std;

char in[(int)1e5 + 1];

int main() {
    int ans = 0, cnt = 0;
    scanf("%s", in);
    for (int i = 0; in[i]; i++) {
        if (in[i] == '(' && in[i + 1] == ')')
            ans += cnt, i++;
        else if (in[i] == '(')
            ans++, cnt++;
        else if (in[i] == ')')
            cnt--;
    }
    printf("%d", ans);
    return 0;
}