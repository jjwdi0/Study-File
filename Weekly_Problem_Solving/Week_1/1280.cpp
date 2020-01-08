#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;

struct BIT {
    ll tree[200005], base;
    void init(int x) {
        base = x + 1;
    }
    void add(int x, ll y) {
        while(x <= base) tree[x] += y, x += x & -x;
    }
    ll q(int x) {
        ll res = 0;
        while(x) res += tree[x], x -= x & -x;
        return res;
    }
} bit[2];

int N;
ll ans = 1LL;
set<int> s;

int main() {
    scanf("%d", &N), bit[0].init(200000), bit[1].init(200000);
    for(int i=1, x; i<=N; i++) {
        scanf("%d", &x), x++;
        s.insert(x);
        int L = bit[0].q(x - 1), R = bit[0].q(200001) - bit[0].q(x);
        ll res = 1LL * x * L - bit[1].q(x - 1) + bit[1].q(200001) - bit[1].q(x) - 1LL * x * R;
        res %= MOD;
        bit[0].add(x, 1LL), bit[1].add(x, x);
        if(!res) continue;
        ans = ans * res % MOD;
    }
    printf("%lld\n", (int)s.size() == 1 ? 0LL : ans);
}
