#include <bits/stdc++.h>
using namespace std;

int D[503][503], N, K;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++) {
		D[i][1] = i;
		D[1][i] = 1;
	}
	for(int i=2; i<=N; i++) for(int j=2; j<=K; j++) {
		D[i][j] = 987654321;
		for(int p=1; p<=i; p++) D[i][j] = min(D[i][j], max(D[p-1][j-1], D[i-p][j]) + 1);
	}
	printf("%d\n", D[N][K]);
}