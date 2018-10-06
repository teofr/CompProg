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

#define DEBUG
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


int main() {
	tint n, k;
	cin >> n >> k;

	tint k2 = 2*k +1;

	cout << n/k2 + (n%k2 == 0 ? 0 : 1) << endl;

	tint rest = n % k2;

	if (rest == 0){
		forn (i, n/k2){
			cout << 1 + i*k2 + k << ' ';
		}
		cout << endl;
	}else{
		debug(n);
		debug(k2);
		debug(rest);
		debug(k + 1 - rest);
		forn (i, n/k2 + 1){
			cout << 1 + i*k2 + k - max(0ll,(k + 1 - rest)) << ' ';
		}
		cout << endl;
	}

	return 0;
}
