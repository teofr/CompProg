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
	tint n, a, b, c, t;
	cin >> n >> a >> b >> c >> t;

	//vector<int> ti(n);
	tint bank = 0;
	forn(i, n){
		int ti;
		cin >> ti;
		bank += max(a, a + (t-ti)*(c - b));
	}

	cout << bank << endl;


	return 0;
}
