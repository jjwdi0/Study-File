#include <stdio.h>
#define MOD 1000000007
using ll = long long;

int N, K;
ll D[12][100002];

int main() {
	scanf("%d %d", &N, &K);
	D[0][0] = 1;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=K; j++) D[i-1][j] = (D[i-1][j] + D[i-1][j-1]) % MOD;
		for(int j=1; j<=K; j++) {
			ll res = 0LL;
			for(int k=j*2; k<=K; k+=j) res = (res + D[i-1][k] - D[i-1][k-1]) % MOD;
			D[i][j] = (D[i-1][K] - res) % MOD;
		}
	}
	ll ans = 0LL;
	for(int i=1; i<=K; i++) ans = (ans + D[N][i]) % MOD;
	printf("%lld\n", (ans + MOD) % MOD);
}