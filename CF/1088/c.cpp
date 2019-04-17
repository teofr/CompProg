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
	forn(i, n){
		cin >> a[i];
	}

	tint carr = 0;
	tint nxt = n-1;

	auto it = a.rbegin();
	cout << n+1 << '\n';
	while(it != a.rend()){
		tint este = *it;
		este %= 2000;
		este = (este + carr) % 2000;
		tint suma = (nxt - este + 4000) % 2000;
		cout << "1 " << nxt + 1 << " " << suma << '\n';

		carr += suma;
		carr %= 2000;

		nxt--;
		it++;
	}

	cout << "2 " << n << " 2000\n";


	return 0;
}
