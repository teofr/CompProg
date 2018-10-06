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

tint queries;

bool bsearch(tint& l, tint& h, tint k, tint n){
	while((h - l) > k * 4 + 2){
		tint m = (l+h)/2ll;
		cout << l << ' ' << m << endl; cout.flush();
		queries++;

		string t;
		cin >> t;
		if (t == "Yes"){
			if (h==l) return false;
			h = min(n + 1, m + k + 1);
			l = max(l-k, 1ll);

		} else if (t == "No") {
			h = min(n+1, h+k);
			l = max(m - k, 1ll);
		}else if (t == "Bad"){
			return false;
		}
		
	}
	return true;

}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	tint n, k;
	cin >> n >> k;
	queries = 0;

	tint l = 1;
	tint h = n+1;
	// [l, h)
	tint next = 0;
	while (1){
		if (!bsearch(l, h, k, n)) return 0;
		next = std::rand() % (h - l);
		cout << l + next << ' ' << l+next << endl; cout.flush();
			h = min(n + 1, h + k);
			l = max(l - k, 1ll);
		queries++;

		debug(l);
		debug (h);
		debug(h - l);
		string t;
		cin >> t;
		if (t == "Bad" or t == "Yes") return 0;	
	}





	


	return 0;
}
