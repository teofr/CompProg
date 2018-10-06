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

	vector<tint> arr (n+1, 0);
	tint tot = 0;

	forn(i, n){
		cin >> arr[i+1];
		arr[i+1] += arr[i];
	}

	tot = arr[n];

	forn(i, n){
		if (arr[i+1]*2 >= tot){
			cout << i+1 << endl;
			return 0;
		}
	}


	return 0;
}
