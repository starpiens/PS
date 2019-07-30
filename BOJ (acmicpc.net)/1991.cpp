#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> tree[26];

void preorder(int n) {
    if (n < 0) return;
    printf("%c", n + 'A');
    preorder(tree[n].first);
    preorder(tree[n].second);
}

void inorder(int n) {
    if (n < 0) return;
    inorder(tree[n].first);
    printf("%c", n + 'A');
    inorder(tree[n].second);
}

void postorder(int n) {
    if (n < 0) return;
    postorder(tree[n].first);
    postorder(tree[n].second);
    printf("%c", n + 'A');
}

int main() {
    scanf("%d", &N);
    fill(tree, tree + N, make_pair(-1, -1));
    for (int i = 0; i < N; i++) {
        char n, l, r;
        scanf(" %c %c %c", &n, &l, &r);
        if (l != '.') tree[n - 'A'].first = l - 'A';
        if (r != '.') tree[n - 'A'].second = r - 'A';
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);

    return 0;
}