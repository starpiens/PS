#include <cstdio>
#include <cstring>

int main() {
    int M;
    bool s[21];
    scanf("%d", &M);
    while (M--) {
        char op[10];
        int num;
        scanf("%s", op);
        switch (op[0]) {
            case 'a':
                if (op[1] == 'd') {
                    scanf("%d", &num);
                    s[num] = true;
                } else {
                    memset(s, true, sizeof(s));
                }
                break;
            case 'r':
                scanf("%d", &num);
                s[num] = false;
                break;
            case 'c':
                scanf("%d", &num);
                printf("%d\n", s[num]);
                break;
            case 't':
                scanf("%d", &num);
                s[num] ^= true;
                break;
            case 'e':
                memset(s, false, sizeof(s));
        }
    }
    return 0;
}