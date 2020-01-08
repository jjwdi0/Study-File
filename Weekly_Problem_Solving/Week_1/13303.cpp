#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
using tr = pair<int, pr>;

int N, _X, _Y;
tr A[100005];
map<int, int> m;
int tmp[100005][2];
vector<int> ans;

int main() {
    scanf("%d %d %d", &N, &_X, &_Y);
    for(int i=1; i<=N; i++) scanf("%d %d %d", &A[i].first, &A[i].second.first, &A[i].second.second);
    sort(A+1, A+N+1);
    m[_X] = 0;
    for(int i=1; i<=N; i++) {
        auto it = m.lower_bound(A[i].second.first), jt = m.upper_bound(A[i].second.second);
        int idx = 0, u = A[i].second.first, v = A[i].second.second;
        for(; it!=jt; it++) tmp[idx][0] = it->first, tmp[idx][1] = it->second, idx++;
        it = m.lower_bound(A[i].second.first);
        m.erase(it, jt);
        if(idx == 0) continue;
        m[u] = m[v] = 1e9;
        for(int j=0; j<idx; j++) {
            m[u] = min(m[u], tmp[j][1] + abs(tmp[j][0] - u));
            m[v] = min(m[v], tmp[j][1] + abs(v - tmp[j][0]));
        }
    }
    int mn = 2e9;
    for(auto &it : m) {
        it.second += _Y;
        mn = min(mn, it.second);
    }
    printf("%d\n", mn);
    for(auto it : m) if(it.second == mn) ans.push_back(it.first);
    printf("%d ", (int)ans.size());
    for(auto it : ans) printf("%d ", it);
}
