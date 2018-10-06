#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

struct dxy {tint d,x,y;};
dxy mcde(tint a, tint b) {
	dxy r, t;
	if (b == 0) {
		r.d = a; r.x = 1; r.y = 0;
	} else {
		t = mcde(b,a%b);
		r.d = t.d; r.x = t.y;
		r.y = t.x - a/b*t.y;
	}
	return r;
}


int main() {
	tint n, a, b;
	cin >> n >> a >> b;

	tint repa, repb;
	repa = repb = 0;

	while (repa*a <= n){
		if ((n-repa*a) % b == 0){
			repb = (n-repa*a) / b;
			break;
		}
		repa++;
	}

		debug(repa);
		debug(repb);


	if (repa*a > n){
		cout << -1;
		return 0;
	}

	int next = 1;

	forn (i, repa){
		int first = next;
		forn (j, a){

			if (j == a-1){
				cout << first << (next == n ? '\n' : ' ');
				next = first + a;
			}else{
				cout << ++next << ' ';
			}
		}
	}

	forn (i, repb){
		int first = next;
		forn (j, b){

			if (j == b-1){
				cout << first << (next == n ? '\n' : ' ');
				next = first + b;
			}else{
				cout << ++next << ' ';
			}
		}
	}

	

	return 0;
}
