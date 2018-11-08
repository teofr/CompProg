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

	vector<int> a(n+3), nimber(n+3, 1);

	// unordered_set<int> perd;
	// perd.insert(a[n-1]);

	forn(i, n){
		int c; cin >> c;
		a[c] = i+1;
		// b[i] = c;
	}
	nimber[a[n]] = 0;

	for (int i = n-1; i >= 1; i--){
		int paso = i;
		int prox = a[i] + paso;

		int ans = 0;

		while (prox <= n){
			if (nimber[prox] == 0) ans = 1;
			prox += paso;
		}

		prox = a[i] - paso;

		while (prox >= 1){
			if (nimber[prox] == 0) ans = 1;
			prox -= paso;
		}

		nimber[a[i]] = ans;
	}

	forsn(i, 1, n+1){
		if (nimber[i])
			cout << 'A';
		else
			cout << 'B';
	
	}
	cout << endl;
	


	return 0;
}

