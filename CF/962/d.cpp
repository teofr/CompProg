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

	vector<tint> a(n);
	map<tint, set<int> > app;

	forn(i,n){
		cin >> a[i];
		app[a[i]].insert(i);
	}

	int final = n;

	for(auto& x : app){
		if (x.snd.size() >= 2){
			for(auto it = x.snd.begin(); it != x.snd.end(); it++){
				auto itn = it;
				itn++;
				if (itn == x.snd.end()){
					break;
				}
				final--;
				a[*it] = 0;
				a[*itn] *= 2;
				app[a[*itn]].insert(*itn);
				it = itn;
			}

			/*forn(i, x.snd.size() - 1){
				final--;
				a[x.snd[i]] = 0;
				a[x.snd[i+1]] *= 2;
				i++;
			}*/
		}
	}

	cout << final << endl;

	for (auto i : a){
		if (i != 0){
			cout << i << ' ';

		}
	}
	cout << endl;



	return 0;
}
