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

	set<int> app;

	tint m = 0;

	if (n == 1){
		cout << 1 << endl;
	}else{
		cout << 1 + n / 2 << endl;
	}

	/*
	8 8 1
	8 7 1
	8 6 1
	8 5 1
	8 4 2
	8 3 2
	8 2 4
	8 1 8
	*/

	return 0;
}
