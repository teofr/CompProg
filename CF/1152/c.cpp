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

#define MAXP 1000000 //no necesariamente primo
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
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}
//~ Useful for bit trick: #define SET(i) ( criba[(i)>>5]|=1<<((i)&31) ), #
// define INDEX(i) ( (criba[i>>5]>>((i)&31))&1 ), unsigned int criba[MAXP
// /32+1];


struct dxy {tint d,x,y;};
dxy mcde(tint a, tint b) {
	dxy r, t;
	if (b == 0) {
		r.d = a; r.x = 1; r.y = 0;
	} else {
		t = mcde(b,a %b);
		r.d = t.d; r.x = t.y;
		r.y = t.x - a/b*t.y;
	}
	return r;
}

tint modq(x, q) { return (x % q + q) % q ; }

tint tcr(tint* r, tint* m, int n) {
	tint p=0, q=1;
	forn(i, n) {
		p = modq(p-r[i], q);
		dxy w = mcde(m[i], q);
		if (p % w.d) return -1; // sistema incompaible
		q = q / w.d * m[i];
		p = modq(r[i] + m[i] * p / w.d * w.x, q);
	}
	return p; // x \equiv p (q)
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint a, b;
	cin >> a >> b;

	buscarprimos();


	return 0;
}
