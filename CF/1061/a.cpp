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
	tint n, s;
	cin >> n >> s;
	tint ans = 0;
	// while (s>0){
	// 	s -= n;
	// 	n--;
	// 	ans++;
	// }

	cout << (s /n + (s % n ? 1 : 0)) << endl;


	return 0;
}
