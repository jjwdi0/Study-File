#include <bits/stdc++.h>
using namespace std;

int N, A[100005], cnt[4][4], num[4];
int pmt[3] = { 1, 2, 3 }, ans = 1e9;

int g(int x, int y) {
    int res = min(cnt[x][y], cnt[y][x]);
    cnt[x][y] -= res, cnt[y][x] -= res;
    return res;
}

int f(int x, int y, int z) {
    int idx1 = num[x], idx2 = num[x] + num[y], res = 0;
    for(int i=1; i<=3; i++) for(int j=1; j<=3; j++) cnt[i][j] = 0;
    for(int i=1; i<=idx1; i++) cnt[A[i]][x]++;
    for(int i=idx1+1; i<=idx2; i++) cnt[A[i]][y]++;
    for(int i=idx2+1; i<=N; i++) cnt[A[i]][z]++;
    res += g(1, 2) + g(1, 3) + g(2, 3);
    return res + cnt[1][2] * 2 + cnt[2][1] * 2;
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", A+i), num[A[i]]++;
	do {
        ans = min(ans, f(pmt[0], pmt[1], pmt[2]));
	} while(next_permutation(pmt, pmt + 3));
	printf("%d\n", ans);
}
