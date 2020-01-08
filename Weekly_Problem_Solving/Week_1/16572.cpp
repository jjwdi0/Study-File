#include <bits/stdc++.h>
using namespace std;

int N, A[2005][2005];

int main() {
    scanf("%d", &N);
    for(int i=1, x, y, z; i<=N; i++) {
        scanf("%d %d %d", &x, &y, &z);
        A[x][y] = max(A[x][y], z);
    }
    for(int i=2; i<=4000; i++) {
        int s = (i <= 2001 ? i - 1 : 2000);
        int e = (i <= 2001 ? 1 : i - 2000);
        for(int j=s; j>=e; j--) {
            int x = j, y = i - j;
            if(!A[x][y]) continue;
            A[x+1][y] = max(A[x+1][y], A[x][y] - 1);
            A[x][y+1] = max(A[x][y+1], A[x][y] - 1);
        }
    }
    int ans = 0;
    for(int i=1; i<=2000; i++) for(int j=1; j<=2000; j++) ans += !!A[i][j];
    printf("%d\n", ans);
}
