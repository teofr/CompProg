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

	vector<int> l(n), r(n), ans(n);
	vector<pair<int, int>> lr(n);

	forn(i, n){
		cin >> l[i];
	}
	forn(i, n){
		cin >> r[i];
	}
	forn(i, n){
		lr[i].fst = r[i] + l[i];
		lr[i].snd = i;
	}

	// sort(lr.begin(), lr.end());

	forn(i, n){
		ans[i] = n - lr[i].fst;
	} 

	vector<int> ll(n), rr(n);

	forn(i, n){
		forsn(j, 0, i){
			if (ans[j] > ans[i]) ll[i]++;
		}
		forsn(j, i+1, n){
			if (ans[j] > ans[i]) rr[i]++;
		}
	}

	if (l == ll and r == rr){
		cout << "YES" << '\n';
		for (auto x : ans){
			cout << x << ' ';
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
	}


	return 0;
}
