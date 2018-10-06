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
	tint n, d;
	cin >> n >> d;
	vector<int> vals(n+1);
	vals[0] = 0;
	set<int> ceros;

	forn(i,n){
		int a;
		cin >> a;
		vals[i+1] = vals[i] + a;
		if (a == 0) {
			ceros.insert(i);
		}
		if (vals[i+1] > d){
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> der, add;
	der = add = vector<int> (n);

	int maximo = vals[n];
	for (int i = n-1; i >= 0; i--){
		maximo = max(maximo, vals[i+1] );
		der[i] = d - maximo;
		if (der[i] < 0){
			cout << -1 << endl;
			return 0;
		}
	}

	for (auto i : ceros){
		debug(i);
		debug(der[i]);
		add[i] = -vals[i+1];
		debug(add[i]);

		if (der[i] < add[i]){
			cout << -1 << endl;
			return 0;
		}
	}

	int eater = 0;
	int res = 0;
	for (auto i:ceros){
		if (add[i] > eater){
			eater = der[i];
			res++;
		}
	}

	cout << res << endl;





	return 0;
}
