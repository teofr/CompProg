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
	int n, k;

	cin>>n>>k;
	vector<int> ans (n);
	tint cost = 0;

	set <pair<tint, tint> > cola ;
	forn(i,k){
		tint c;
		cin>>c;
		cola.insert(mp(c,i));
	}

	//tint min = k;

	forsn(i, k, n){
		tint c;
		cin>>c;
		cola.insert(mp(c, i));

		auto  out = cola.end();
		out--;

		cost += (out->fst*(i - out->snd));
		ans[(int)out->snd] = i;
		cola.erase(out);
	}
	tint minu = n;

	while (not cola.empty()){
		auto  out = cola.end();
		out--;

		cost += (out->fst*(minu - out->snd));
		ans[(int)out->snd] = minu;
		cola.erase(out);
		minu++;
	}

	cout<<cost<<endl;

	forn (i, ans.size()){
		cout<<ans[i] + 1;
		if (i<ans.size())
			cout<<' ';

	}
	cout<<endl;
	return 0;
}
