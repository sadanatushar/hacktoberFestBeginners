#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define int int64_t

using namespace std;

typedef double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

const ftype pi = acos(-1);
const ftype inf = 1e16;
const ftype eps = 1e-6;

ftype dot(point a, point b) {
	return a.x() * b.x() + a.y() * b.y();
}
ftype cross(point a, point b) {
	return a.x() * b.y() - a.y() * b.x();
}

void read(point &r) {
	ftype x, y;
	cin >> x >> y;
	r = {x, y};
}

ftype area(ftype r, ftype a) {
	return norm(r) * acos(a / r) - a * sqrt(norm(r) - norm(a));
}

ftype overlap(ftype r1, ftype r2, ftype d) {
	if(d >= r1 + r2) {
		return 0;
	} else if(d <= abs(r1 - r2)) {
		return pi * norm(min(r1, r2));
	} else {
		ftype a = (norm(r1) - norm(r2) + norm(d)) / (2 * d); 
		return area(r1, a) + area(r2, d - a);
	}
}

ftype sign(ftype x) {
	return x < 0 ? -1 : 1;
}
tuple<point, point, ftype> reflect(point A, point Av, ftype Ar, point W1, point W2) {
	point nrm = point(0, 1) * (W2 - W1);
	nrm /= abs(nrm);
	ftype d = dot(A - W1, nrm);
	ftype Vd = dot(Av, nrm);
	point A_ = A - 2 * (d - sign(d) * Ar) * nrm;
	point Av_ = Av - 2 * Vd * nrm;
	if(abs(Vd) < eps || sign(d - sign(d) * Ar) == sign(Vd)) {
		return {A, Av, 0};
	} else {
		ftype At = -(d - sign(d) * Ar) / Vd;
		return {A_, Av_, At};
	}
}

ftype dist(point A, point Av, point B, point Bv, ftype tl, ftype tr) {
	tl = max(tl, (ftype)0);
	if(tl > tr) {
		return inf;
	} else {
		Bv -= Av;
		ftype t = dot(A - B, Bv) / norm(Bv);
		if(tl <= t && t <= tr) {
			return abs(cross(A - B, Bv)) / abs(Bv);
		} else {
			return min(abs(A - (B + tl * Bv)), abs(A - (B + tr * Bv)));
		}
	}
}

void solve() {
	point A, Av; ftype Ar;
	point B, Bv; ftype Br;
	read(A); read(Av); cin >> Ar;
	read(B); read(Bv); cin >> Br;
	point W1, W2;
	read(W1); read(W2);
	point A_, Av_, B_, Bv_;
	ftype At, Bt;
	tie(A_, Av_, At) = reflect(A, Av, Ar, W1, W2);
	tie(B_, Bv_, Bt) = reflect(B, Bv, Br, W1, W2);
	if(At < 0) {
		swap(A, A_); swap(Av, Av_);
	}
	if(Bt < 0) {
		swap(B, B_); swap(Bv, Bv_);
	}
	ftype d = min({dist(A, Av, B, Bv, 0, min(At, Bt)), 
		           dist(A_, Av_, B, Bv, At, Bt),
		           dist(A, Av, B_, Bv_, Bt, At),
		           dist(A_, Av_, B_, Bv_, max(At, Bt), inf)});
	cout << overlap(Ar, Br, d) << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
