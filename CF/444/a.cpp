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

	 char c;

	bool start = false;
	int ceros = 0;

	while(cin>>c){
		int t = c - '0';
		if (t == 1){
			start = true;
		}else if(start){
			ceros++;
		}
	}

	cout << (ceros >=6?"yes":"no") << endl;

	return 0;
}
