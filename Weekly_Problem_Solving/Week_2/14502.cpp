#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;

int N, M, A[10][10], d[4] = { 1,-1,0,0 }, ans;
bool visited[10][10];
queue<pr> q;

int bfs() {
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
        visited[i][j] = 0;
        if(A[i][j] == 2) q.push(pr(i, j));
    }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        visited[x][y] = 1;
        for(int i=0; i<4; i++) {
            int xx = x + d[i], yy = y + d[3-i];
            if(xx <= 0 || xx > N || yy <= 0 || yy > M || A[xx][yy] || visited[xx][yy]) continue;
            q.push(pr(xx, yy));
        }
    }
    int res = 0;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
        if(!A[i][j] && !visited[i][j]) res++;
    }
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &A[i][j]);

    for(int i=0; i<N*M; i++) for(int j=i+1; j<N*M; j++) for(int k=j+1; k<N*M; k++) {
        int xx1 = i / M + 1, yy1 = i % M + 1;
        int xx2 = j / M + 1, yy2 = j % M + 1;
        int xx3 = k / M + 1, yy3 = k % M + 1;
        if(A[xx1][yy1] == 0 && A[xx2][yy2] == 0 && A[xx3][yy3] == 0) {
            A[xx1][yy1] = 1, A[xx2][yy2] = 1, A[xx3][yy3] = 1;
            ans = max(ans, bfs());
            A[xx1][yy1] = 0, A[xx2][yy2] = 0, A[xx3][yy3] = 0;
        }
    }
    printf("%d\n", ans);
}
