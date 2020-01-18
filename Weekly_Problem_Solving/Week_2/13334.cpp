#include <bits/stdc++.h>
#define MAX_N 100003
using namespace std;
using pr = pair<int, int>;

int N, d, ans, cnt, chk[MAX_N];
pr T1[MAX_N], T2[MAX_N], P[MAX_N << 1];
bool visited[MAX_N << 1];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d %d", &T1[i].first, &T2[i].first), T1[i].second = T2[i].second = i;
	sort(T1, T1 + N);
    sort(T2, T2 + N);
	scanf("%d", &d);
	for(int i = 0, j = 0, k = 0; i < 2 * N; i++) {
		if(j == N || T1[j].first > T2[k].first) P[i] = T2[k++];
		else P[i] = T1[j++];
	}
	for(int i = 0, k = 0; i < 2 * N; i++) {
		while(k < 2 * N && P[k].first <= P[i].first + d) {
			if(!visited[k]) {
                visited[k] = true;
                chk[P[k].second]++;
                if(chk[P[k].second] == 2) cnt++;
            }
            k++;
		}
        k--;
		ans = max(ans, cnt);
		chk[P[i].second]--;
        if(chk[P[i].second] == 1) cnt--;
	}
	printf("%d\n", ans);
}
