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




#define MAXP 71

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

map<tint,tint> fact(tint n){ //O (cant primos)
	map<tint,tint> ret;
	for(auto p : primos){
		while(!(n %p)){
			ret[p]++;//divisor found
			n/=p;
		}
	}
	if(n>1) ret[n]++;
	return ret;
}

//#define MOD 1000000007

tint MOD = 1000000007;

tint exp(tint b, tint e){
	if (e == 0) return 1;
	if (e == 1) return b;
	tint med = exp(b, e>>1) % MOD;
	med = (med*med)%MOD;
	if (e%2 == 1){
		med *= b;
	}

	return med%MOD;
}

int main() {
	buscarprimos();
	ios::sync_with_stdio(0); cin.tie(0);
	//vector<int> app((1<<20) + 10, 0);
	map<tint, tint> app;
	tint n;
	cin >> n;



	forn(i,n){
		tint a;
		cin >>a;
		auto f = fact(a);
		int mask = 0;
		//debug(primos.size());
		forn (j, primos.size()){
			int p = primos[j];
			//debug(p);
			//debug(f[p]);
			if (f[p] % 2 == 1){
				
				mask = mask + (1<<j);
			}
		}
		app[mask]++;

	}

	tint res = 1;
	

	for(auto a:app){

		tint tmp = a.snd;
		//debug (i);
		//debug(app[i]);

		if (tmp > 0){
			//debug(i);
			//debug(tmp);
			if (a.fst == 0) tmp++;
			tmp = exp(2, tmp-1);
			res *= (tmp);
			res = res % MOD;
			//debug(res);
		}
		
	}

	cout << (res-1+MOD)%MOD << endl;


	return 0;
}
