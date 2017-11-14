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
	vector <tint> jugs (6);
	int todo = 0;
	forn(i, 6){
		cin >> jugs[i];
		todo += jugs[i];
	}

	forn(i, 6){
		forsn(j, i+1, 6){
			forsn(h, j+1, 6){
				if (2*(jugs[i] + jugs[j] + jugs[h]) == todo){
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}
