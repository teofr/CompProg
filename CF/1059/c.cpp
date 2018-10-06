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

#define MAXP 1000010 //no necesariamente primo

int criba[MAXP+1];
void crearcriba(){
int w[] = {4,2,4,2,4,6,2,6};
for(int p=25;p<=MAXP;p+=10) criba[p]=5;
for(int p=9;p<=MAXP;p+=6) criba[p]=3;
for(int p=4;p<=MAXP;p+=2) criba[p]=2;
for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p])
for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}
vector<int> primos;
void buscarprimos(){
crearcriba();
forsn (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}
// //~ Useful for bit trick: #define SET(i) ( criba[(i)>>5]|=1<<((i)&31) ), #
// #define INDEX(i) ( (criba[i>>5]>>((i)&31))&1 ), unsigned int criba[MAXP
// /32+1];

vector<vector<int>> ady;

vector<int> ans;

void dfs(tint d, tint n){
	// cout << d << ' ';
	if (d > n) return;


	int idx = 1;

	while(idx < primos.size() and primos[idx]*d <= n){
		debug(n / (d*primos[idx]));
		debug(n/(d*2));
		if (n / (d*primos[idx]) < (n/(d*2))) break;
		idx++;
	}
	idx--;

	debug(d);
	debug(idx);

	dfs(d*primos[idx], n);

	while(ans.size() < (n / d)){
		ans.pb(d);
	}

}

int main() {
	tint n;
	cin >> n;

	buscarprimos();

	dfs(1, n);

	reverse(ans.begin(), ans.end());
		for (auto s:ans){
			cout << s << ' ';
		}
		cout << endl;


	return 0;
}
