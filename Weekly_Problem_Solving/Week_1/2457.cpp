#include <bits/stdc++.h>
using namespace std;

int A[1235], N, today = 301, cnt, k;

int main() {
	scanf("%d", &N);
	for(int i=0, x, y, z, w; i<N; i++) {
		scanf("%d %d %d %d", &x, &y, &z, &w);
		A[x*100+y] = max(A[x*100+y], z * 100 + w);
	}
	while(today <= 1130){
		sort(A + 1, A + today + 1);
		if(today >= A[today]) return puts("0"),0;
		k = A[today];
		A[today] = 0;
		today = k;
		cnt++;
	}
	printf("%d\n", cnt);
}