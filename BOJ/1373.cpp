#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char in[(int) 1e6 + 1];

int main() {
    scanf("%s", in);

    stack<int> s;
    int i = strlen(in) - 1;
    while (i >= 0) {
        int val = 0;
        for (int j = 0; j < 3 && i >= 0; j++)
            val += (in[i--] - '0') << j;
        s.push(val);
    }
    while (!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }

    return 0;
}