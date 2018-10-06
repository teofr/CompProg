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
	vector<int> angles (n+1, 0);
	forn(i,n){
		cin >> angles[i+1];
		angles[i+1] += angles[i];
	}

	int res = angles[n];
	forsn(i,1, n+1){
		forsn(j,0, n){
			res = min(res, abs(angles[i] - angles[j] - (360 - (angles[i] - angles[j]))));
		}
	}

	cout << res << endl;


	return 0;
}
