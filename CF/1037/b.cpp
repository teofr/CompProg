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


#define debug(v) cerr << #v << " = " << (v) << endl;


int main() {
	tint n,s ;
	cin >> n >> s;

	std::vector<tint> v(n);

	forn(i, n){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	tint ans = 0;
	debug(n/2);
	debug(v[n/2]);

	if (v[n/2] > s) {
		int next = n/2;
		ans += v[next] - s;
		next--;

		while (next >= 0 and v[next] > s){
			ans += v[next] - s;
			next--;
		}
	}else if (v[n/2] < s){
		int next = n/2;
		ans += s - v[next];
		next++;

		while (next < n and v[next] < s){
			ans += s - v[next];
			next++;
		}
	}

	cout << ans << endl;
	return 0;
}
