#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, A[10], c[20000], ans1 = INF, ans2, sum;

void g(int x, int y) {
	if(x == 9) {
		sum += c[y];
		return;
	}
	for(int i=0; i<3; i++) {
		if(i + 1 == A[x]) continue;
		g(x + 1, y * 3 + i);
	}
}

void f(int x) {
	if(x == 9) {
		sum = 0;
		g(0, 0);
		ans1 = min(ans1, sum);
		ans2 = max(ans2, sum);
		return;
	}
	for(int i=1; i<=3; i++) A[x] = i, f(x + 1);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int cnt = 0;
		for(int j=0, x; j<9; j++) {
			scanf("%d", &x);
			cnt *= 3, cnt += x - 1;
		}
		c[cnt]++;
	}
	f(0);
	printf("%d %d\n", ans1, ans2);
}