#include <bits/stdc++.h>
using namespace std;

int N, S[200005];
char A[200005];

int main() {
    scanf("%d %s", &N, A);
    for(int i=1; i<=N; i++) S[i] = (A[i-1] == 'k' ? 1 : -1) + S[i-1];
    if(S[N/2] == 0) return !printf("1\n%d\n", N / 2);
    for(int i=N/2+1; i<N; i++) if(S[i] - S[i-N/2] == 0) return !printf("2\n%d %d\n", i - N / 2, i);
}
