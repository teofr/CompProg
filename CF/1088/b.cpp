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
	ios::sync_with_stdio(0);
	cin.tie(0);
	tint n, k;
	cin >> n >> k;
	vector<tint> a;
	forn(i, n){
		tint b;
		cin >> b;
		if (b)
			a.pb(b);
	}

	sort(a.begin(), a.end());
	tint last = 0;

	auto it = a.begin();
	forn(i, k){
		while(it != a.end() and *it == last)
			it++;
		if (it == a.end()){
			cout << 0 << '\n';
		}else{
			cout << *it - last << '\n';
			last = *it;

		}

	}



	return 0;
}
