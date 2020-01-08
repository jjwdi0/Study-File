#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

using pr = pair<int, int>;
using tr = pair<int, pr>;

int V, E, K, s, e, D[1111][1111], max_len;
vector<pr> v[1111];
priority_queue<tr, vector<tr>, greater<tr>> pq;

int main() {
	scanf("%d %d %d %d %d", &V, &E, &K, &s, &e);
	for(int i=0, x, y, z; i<E; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(pr(y, z));
		v[y].push_back(pr(x, z));
	}
	for(int i=0; i<=V; i++) for(int j=0; j<=1000; j++) D[i][j] = INF;
	pq.push(tr(0, pr(s, 0)));
    bool flag = 0;
	while(!pq.empty()) {
		int u = pq.top().second.first, len = pq.top().second.second, cost = pq.top().first; pq.pop();
		if(D[u][len] < cost || len > 1000) continue;
		if(u == e && !flag) {
			flag = 1;
			max_len = len;
		}
		if(max_len <= len && flag) continue;
		D[u][len] = cost;
		for(auto it : v[u]) {
			if(D[it.first][len+1] <= cost + it.second) continue;
			D[it.first][len+1] = cost + it.second;
			pq.push(tr(D[it.first][len+1], pr(it.first, len+1)));
		}
	}
	int ans = INF, cnt = 0, ind = max_len;
	for(int i=0; i<=1000; i++) ans = min(ans, D[e][i]);
	printf("%d\n", ans);
	for(int i=0, x, t; i<K; i++) {
		scanf("%d", &x);
		cnt += x, ans = INF, t = ind;
		for(int j=0; j<=t; j++) if(ans > D[e][j] + j * cnt) ans = min(ans, D[e][j] + j * cnt), ind = j;
		printf("%d\n", ans);
	}
}