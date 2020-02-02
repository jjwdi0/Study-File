#include <bits/stdc++.h>
using namespace std;

int N, M, D[303][303], A[303];

void trace(int x, int y) {
    if(y == 1) { printf("%d ", x); return; }
    for(int i=x-1; i>=0; i--) {
        if(D[x][y] == max(D[i][y-1], A[x] - A[i])) {
            trace(i, y - 1);
            printf("%d ", x - i);
            return;
        }
    }
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", A+i), A[i] += A[i-1];
	for(int i=1; i<=N; i++) D[i][1] = A[i];
	for(int i=1; i<=N; i++) for(int j=2; j<=M; j++) {
        D[i][j] = 1e9;
        for(int k=1; k<i; k++) D[i][j] = min(D[i][j], max(D[k][j-1], A[i] - A[k]));
	}
	printf("%d\n", D[N][M]);
	trace(N, M);
}
