#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define ll long long
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


#define MAXP 1001000 //no necesariamente primoEl Bueno, el Ralo y el Feo

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
//~ Useful for bit trick: #define SET(i) ( criba[(i)>>5]|=1<<((i)&31) ), #
#define INDEX(i) ( (criba[i>>5]>>((i)&31))&1 ), unsigned int criba[MAXP/32+1];

#define MOD 1000000007
#define MAXN 1000200
#define MAXM 40

map<ll,ll> fact2(ll n){ //O (cant primos)
	map<ll,ll> ret;
	for(auto p :primos){
		while(!(n %p)){
			ret[p]++;//divisor found
			n/=p;
		}
	}
	if(n>1) ret[n]++;
	return ret;
}





map<ll,ll> fact(ll n){ //O (lg n)
	map<ll,ll> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}


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
	tint q;
	cin >> q;

	crearcriba();

	vector<vector<int> > comb(MAXN+1, vector<int> (MAXM+1));

	forn(i, MAXN+1){//comb[i][k]=i tomados de a k
		comb[i][0]=1;
		if (i < MAXM+1) comb[i][i] = 1;
		forsn(k, 1, min(i, (tint)MAXM+1)) comb[i][k]=(comb[i-1][k]+comb[i-1][k-1]) %MOD;
	}

	
	
	forn(t, q){
		int x, y;
		cin >> x >> y;

		map<tint, tint> factor = fact(x);

		tint res = 1;

		for (auto p:factor){
			res *= (tint) comb[y + p.snd - 1][p.snd];
			
			res = res % MOD;
			debug(p.fst);
			debug(res);
		}

		//tint arreglos = res;
		//res = 0;
		/*
		forn(i, (y/2) + 1){
			//res += (arreglos * (tint) comb[y][2*i]) % MOD;
			debug(arreglos * (tint) comb[y][2*i]);
			res = res % MOD;
		}
		*/
		res = exp(2, y-1)* res;
		res = res % MOD;

		cout << res << endl;

	}


	return 0;
}
