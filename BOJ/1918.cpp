#include <cstdio>
#include <stack>
using namespace std;

int main() {
    char in[101];
    scanf("%s", in);

    stack<int> op;
    for (auto c = in; *c; c++) {
        if (*c == '*' || *c == '/') {
            while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                printf("%c", op.top()), op.pop();
            op.push(*c);
        } else if (*c == '+' || *c == '-') {
            while (!op.empty() && op.top() != '(')
                printf("%c", op.top()), op.pop();
            op.push(*c);
        } else if (*c == '(') {
            op.push(*c);
        } else if (*c == ')') {
            while (op.top() != '(') {
                printf("%c", op.top());
                op.pop();
            }
            op.pop();
        } else {
            printf("%c", *c);
        }
    }
    while (!op.empty()) {
        printf("%c", op.top());
        op.pop();
    }
    return 0;
}