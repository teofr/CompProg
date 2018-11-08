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

#define MAXP 

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

int main() {
	tint n;
	cin >> n;
	


	return 0;
}
