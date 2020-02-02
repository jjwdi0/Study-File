#include <bits/stdc++.h>
using namespace std;

int N, T[1005];
bool A[1005][1005];
vector<int> v[1005], team[2];

void put(int x, int y) {
    T[x] = y;
    team[y-1].push_back(x);
    for(int it : v[x]) {
        if(!T[it]) put(it, 3 - y);
        else if(T[it] == T[x]) { puts("-1"); exit(0); }
    }
}

int main() {
    scanf("%d", &N);
    for(int x, y;;) {
        scanf("%d %d", &x, &y);
        if(x < 0) break;
        A[x][y] = A[y][x] = 1;
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(i != j && !A[i][j]) v[i].push_back(j);
    for(int i=1; i<=N; i++) if(!T[i]) put(i, 1);
    puts("1");
    for(int i=0; i<2; i++) {
        for(auto it : team[i]) printf("%d ", it);
        puts("-1");
    }
}
