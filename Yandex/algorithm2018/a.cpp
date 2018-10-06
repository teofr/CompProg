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
	set<int> chosen;
	forn(i, 10){
		int a;
		cin >> a;
		chosen.insert(a);
	}
	tint n;
	cin >> n;

	forn(i, n){
		int cnt = 0;
		forn(j, 6){
			int t; 
			cin >> t;
			if (chosen.find(t) != chosen.end()){
				cnt++;
			}
		}
		if (cnt >= 3){
			cout << "Lucky" << endl;
		}else{
			cout << "Unlucky" << endl;
		}
	}

	return 0;
}
