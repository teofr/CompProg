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
	tint n;
	cin >> n;

	tint mex = -1;

	forn(i, n){
		tint ai;
		cin >> ai;

		if (ai > mex+1){
			cout << i+1 << endl;
			return 0;
		}
		mex = max(mex, ai);

	}

	cout << -1 << endl;


	return 0;
}
