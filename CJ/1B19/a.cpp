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




int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint t;
	cin >> t;

	forn(caso, t){
		tint p, q; cin >> p >> q;

		vector<tint> xs (q+1, 0);
		vector<tint> ys (q+1, 0);

		forn(i, p){
			tint x, y; char d;
			cin >> x>> y>> d;
			// x++; y++;
			if (d == 'N'){
				ys[y+1] += 1;
			}
			if (d == 'S'){
				ys[0] += 1;
				ys[y] -= 1;
			}
			if (d == 'E'){
				xs[x+1] += 1;
			}
			if (d == 'W'){
				xs[0] += 1;
				xs[x] -= 1;
			}
		}

		forsn(i, 1, q+1){
			xs[i] += xs[i-1];
			ys[i] += ys[i-1];
		}

		tint maxxv = xs[0], maxx = 0;

		forn(i, q+1){
			if (maxxv < xs[i]){
				maxxv = xs[i]; 
				maxx = i;
			}
		}

		tint maxyv = ys[0], maxy = 0;

		forn(i, q+1){
			if (maxyv < ys[i]){
				maxyv = ys[i]; 
				maxy = i;
			}
		}

		cout << "Case #" << caso+1 << ": " << maxx << " " << maxy << endl;
	}


	return 0;
}
