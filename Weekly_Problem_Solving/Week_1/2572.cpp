#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;

vector<pr> v[503];
char A[2003];
int N, M, K, D[503][1003], card[1003];

int main() {
	scanf("%d", &M);
	for(int i=1; i<=M; i++) scanf(" %c", A+i);
	for(int i=1; i<=M; i++) {
		if(A[i] == 'R') card[i] = 1;
		if(A[i] == 'G') card[i] = 2;
		if(A[i] == 'B') card[i] = 3;
	}
	scanf("%d %d", &N, &K);
	while(K--) {
        int x, y;
        char z;
		scanf("%d %d %c", &x, &y, &z);
		int res = 0;
		if(z == 'R') res = 1;
        if(z == 'G') res = 2;
        if(z == 'B') res = 3;
		v[x].push_back(pr(y, res));
		v[y].push_back(pr(x, res));
	}
    memset(D, -1, sizeof(D));
    D[1][1] = 0;
	for(int j=1; j<=M; j++) for(int i=1; i<=N; i++) if(~D[i][j]) {
        for(auto it : v[i]) D[it.first][j+1] = max(D[it.first][j+1], D[i][j] + (card[j] == it.second));
	}
    int ans = 0;
    for(int i=1; i<=N; i++) ans = max(ans, D[i][M+1]);
    printf("%d\n", ans * 10);
}