#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
using tr = pair<int, pr>;
using ll = long long;

int N, par[100005], sz[100005];
tr A[100005];
ll ans;

int f(int x) { return par[x] = (par[x] == x ? x : f(par[x])); }
void uni(int x, int y) {
    x = f(x), y = f(y);
    if(x > y) swap(x, y);
    par[y] = x, sz[x] += sz[y];
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<N; i++) scanf("%d %d %d", &A[i].second.first, &A[i].second.second, &A[i].first);
    sort(A+1, A+N);
    reverse(A+1, A+N);
    for(int i=1; i<=N; i++) par[i] = i, sz[i] = 1;
    for(int i=1; i<N; i++) {
        ans += 1LL * sz[f(A[i].second.first)] * sz[f(A[i].second.second)] * A[i].first;
        uni(A[i].second.first, A[i].second.second);
    }
    printf("%lld\n", ans);
}
