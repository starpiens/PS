#include <cstdio>

int in[1000][1000];

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf("%d", &in[i][j]);

    if (R % 2) {
        for (int i = 1; i < C; i++)
            printf("R");
        for (int i = 0; i < R / 2; i++) {
            printf("D");
            for (int j = 1; j < C; j++)
                printf("L");
            printf("D");
            for (int j = 1; j < C; j++)
                printf("R");
        }
    } else if (C % 2) {
        for (int i = 1; i < R; i++)
            printf("D");
        for (int i = 0; i < C / 2; i++) {
            printf("R");
            for (int j = 1; j < R; j++)
                printf("U");
            printf("R");
            for (int j = 1; j < R; j++)
                printf("D");
        }

    } else {
        int min_r = 1, min_c = 0;
        for (int i = 0; i < R; i++)
            for (int j = i % 2 == 0; j < C; j += 2)
                if (in[min_r][min_c] > in[i][j])
                    (min_r = i), (min_c = j);
        for (int i = 0; i < min_r / 2; i++) {
            for (int j = 1; j < C; j++)
                printf("R");
            printf("D");
            for (int j = 1; j < C; j++)
                printf("L");
            printf("D");
        }

        bool down = true;
        for (int i = 0; i < C - 1; i++) {
            if (i == min_c)
                printf("R");
            else if (down)
                printf("DR"), (down = false);
            else
                printf("UR"), (down = true);
        }
        if (min_c != C - 1) printf("D");

        for (int i = 0; i < (R - min_r - 1) / 2; i++) {
            printf("D");
            for (int j = 1; j < C; j++)
                printf("L");
            printf("D");
            for (int j = 1; j < C; j++)
                printf("R");
        }
    }
    return 0;
}