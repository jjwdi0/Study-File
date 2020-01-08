#include <bits/stdc++.h>
using namespace std;

struct R { double x, y, vx, vy; } A[53];

int N;

double f(double ti) {
	double mxx = -1e9, mxy = -1e9, mnx = 1e9, mny = 1e9;
	for(int i=0; i<N; i++) {
		mxx = max(mxx, A[i].x + A[i].vx * ti);
		mxy = max(mxy, A[i].y + A[i].vy * ti);
		mnx = min(mnx, A[i].x + A[i].vx * ti);
		mny = min(mny, A[i].y + A[i].vy * ti);
	}
	return max(mxx - mnx, mxy - mny);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lf %lf %lf %lf", &A[i].x, &A[i].y, &A[i].vx, &A[i].vy);
	double lo = 0, hi = 1e9;
	for(int i=0; i<1000; i++) {
		double p1 = (lo * 2 + hi) / 3;
		double p2 = (lo + hi * 2) / 3;
		f(p1) < f(p2) ? hi = p2 : lo = p1;
	}
	printf("%.10f\n", f(lo));
}