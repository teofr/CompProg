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
	int n;
	cin>>n;

	int suma = 0;
	vector<int> tortas (n);
	dforn(i,n){
		cin>>tortas[i];
		suma += tortas[i];
	}
	vector<int> dp (n+1, 0);

	forn(i, n){
		dp[i+1] = max(tortas[i] - dp[i], dp[i] - tortas[i]);
	}

	int alice = (suma - dp[n])/2;
	cout << alice << ' ' << suma - alice <<endl;
	return 0;
}
