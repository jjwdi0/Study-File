#include <bits/stdc++.h>
using namespace std;

char a[17][17], mov[53];
int n, m, x, y, goal[17][17], cnt, dx[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
map<char, int> mod;
bool finish;

void init() {
	finish = false;
	cnt = 0;
	memset(goal, 0, sizeof(goal));
}

void go(char p) {
	int dir = mod[p], xx = x + dx[dir][0], yy = y + dx[dir][1];
	if(a[xx][yy] == '#') return;
	else if(a[xx][yy] == '.' || a[xx][yy] == '+') a[x][y] = (goal[x][y] ? '+' : '.'), x = xx, y = yy, a[x][y] = (goal[x][y] ? 'W' : 'w');
	else if(a[xx][yy]=='b' || a[xx][yy]=='B') {
		int xxx = xx + dx[dir][0], yyy = yy + dx[dir][1];
		if(a[xxx][yyy] == '#' || a[xxx][yyy] == 'b' || a[xxx][yyy] == 'B') return;
		if(goal[xxx][yyy]) cnt--, a[xxx][yyy] = 'B';
		else a[xxx][yyy] = 'b';
		if(goal[xx][yy]) cnt++, a[xx][yy] = 'W';
		else a[xx][yy] = 'w';
		if(goal[x][y]) a[x][y] = '+';
		else a[x][y]='.';
		x = xx, y = yy;
	}
	if(!cnt) finish = 1;
}

int main() {
	mod['U'] = 0, mod['D'] = 1, mod['L'] = 2, mod['R'] = 3;
	for(int count=1; ;count++) {
		init();
		scanf("%d %d", &n, &m);
		if(!n) return 0;
		for(int i=0; i<n; i++) {
			scanf("%s", a[i]);
			for(int j=0; j<m; j++) {
				if(a[i][j] == '+' || a[i][j] == 'B' || a[i][j] == 'W') goal[i][j] = 1, cnt += (a[i][j] != 'B');
				if(a[i][j] == 'w' || a[i][j] == 'W') x = i, y = j;
			}
		}
		scanf("%s", mov);
		int len = strlen(mov);
		for(int i=0; i<len; i++) if(!finish) go(mov[i]);
		printf("Game %d: ", count);
		puts(finish ? "complete" : "incomplete");
		for(int i=0; i<n; i++) puts(a[i]);
	}
}