#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pr = pair<int, int>;

int N, M, Q, par[100005], sz[100005], B[100005];
pr A[100005];
bool chk[100005];

int f(int x) { return par[x] = (par[x] == x ? x : f(par[x])); }
void uni(int x, int y) {
    x = f(x), y = f(y);
    if(x == y) return;
    sz[x] += sz[y], par[y] = x;
}

int main() {
	scanf("%d %d %d", &N, &M, &Q);
	iota(par, par + N + 1, 0);
	fill(sz + 1, sz + N + 1, 1);
	for(int i=1; i<=M; i++) scanf("%d %d", &A[i].first, &A[i].second);
	for(int i=1; i<=Q; i++) scanf("%d", B+i), chk[B[i]] = 1;
	for(int i=1; i<=M; i++) if(!chk[i]) uni(A[i].first, A[i].second);
	ll ans = 0LL;
	for(int i=Q; i; i--) {
        int u = A[B[i]].first, v = A[B[i]].second;
        if(f(u) == f(v)) continue;
        ans += 1LL * sz[f(u)] * sz[f(v)];
        uni(u, v);
	}
	printf("%lld\n", ans);
}
