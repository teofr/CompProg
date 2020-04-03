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

bool isCat(vector<int>& xb){
	for(auto xbi : xb){
		if (xbi == 0){
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint x;
	cin >> x;

	// dp[i][j] = max de hacer i operacione
	vector<int> ans;
	vector<int> xb;

	while(x){
		xb.pb(x % 2);
		x = x >> 1;
	}
	while(1){
		//apply A

		int curr = 0;
		while(xb[curr] == 0){
			xb[curr] = 1;
			curr++;
		}

		ans.pb(curr);

		//isPerfect
		if (isCat(xb)){
			break;
		}
		//apply B

		curr = 0;
		while(xb[curr] == 1){
			xb[curr] = 0;
			curr++;
		}
		xb[curr] = 1;

	}
	cout << ans.size() *2 - 1 << endl;

	for (auto ai :ans) {
		cout << ai << " ";
	}
	cout << endl;


	return 0;
}
