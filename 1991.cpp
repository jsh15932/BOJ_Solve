#include<bits/stdc++.h>
using namespace std;

int n, i;
char a, b, c;
char ch[27][2];

void Solve(int x) {
    if(i == 0) {
        putchar(x);
    }

    if(ch[x][0] != '.') {
        Solve(ch[x][0]);
    }

    if(i == 1) {
        putchar(x);
    }

    if(ch[x][1] != '.') {
        Solve(ch[x][1]);
    }

    if(i == 2) {
        putchar(x);
    }
}

int main() {
    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> a >> b >> c;
        ch[a][0] = b;
        ch[a][1] = c;
    }

    for(i = 0; i < 3; i++) {
        Solve('A');
        puts("");
    }
}