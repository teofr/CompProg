#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back
#define mp make_pair

int main() {
	int k; cin>>k;
	int maxi = -1;
	forn(i,k){
		int t;
		cin>>t;
		maxi = max(maxi, t);
	}

	cout<< max(0, maxi - 25) <<endl;
	return 0;
}
