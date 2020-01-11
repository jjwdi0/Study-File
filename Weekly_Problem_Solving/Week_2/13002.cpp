#include <bits/stdc++.h>
using namespace std;

int N, A[2005], D[2005][2005];

int f(int x, int y) {
    if(D[x][y]) return D[x][y];
    if(x == y) return D[x][y] = N * A[x];
    return D[x][y] = max(f(x + 1, y) + A[x] * (N - y + x), f(x, y - 1) + A[y] * (N - y + x));
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", A+i);
    printf("%d\n", f(1, N));
}
