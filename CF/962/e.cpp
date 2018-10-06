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

	set<int> P, B, R;

	forn(i,n){
		int x;
		char c;
		cin >> x >> c;

		if (c == 'B'){
			B.insert(x);
		}else if ( c== 'P'){
			P.insert(x);
		}else{
			R.insert(x);
		}
	}

	tint tot = 0;
	if (not P.empty()){
		tot = *P.end() - *P.begin();
	}

	for (auto& b: B){
		
	}




	return 0;
}
