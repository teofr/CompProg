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

vector<tint> a;
vector<tint> p1, p2;

int bfs(int pos, ii poss){
	debug(pos);
	if (pos >= a.size()) return 0;
	if (pos == 0){
		p1.pb(-1);
		p2.pb(-1);
		bfs (pos+1, {0, -1});
	}else{
		if (a[pos] == 1 or poss.snd == -1){
			forn(i, a[pos]){
				p1.pb(poss.fst);
				p2.pb(poss.fst);
			}
			
			ii nextposs = {p1.size()-1, -1};
			if (a[pos] > 1){
				nextposs.snd = p1.size()-2;
			}
			bfs(pos+1, nextposs);
		}else{
			forn(i, a[pos]-1){
				p1.pb(poss.fst);
				p2.pb(poss.fst);
			}
			p1.pb(poss.fst);
			p2.pb(poss.snd);
			ii nextposs = {p1.size()-1, p1.size()-2};
			bfs(pos+1, nextposs);
		}
	}

}

int main() {
	tint h;
	cin >> h;
	a = vector<tint> (h+1);
	tint tot = 0;
	forn(i, h+1){
		cin >> a[i];
		tot += a[i];
	}

	bfs(0, {-1, -1});

	if (p1 == p2){
		cout << "perfect" << endl;
	}else{
		cout << "ambiguous" << endl;
		for(auto i : p1){
			cout << i +1 << ' ';
		}
		cout << endl;
		for(auto i : p2){
			cout << i +1 << ' ';
		}
		cout << endl;

	}


	return 0;
}
