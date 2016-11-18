//#include "../../stdc++.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

typedef  long long int ll;

using namespace std;

#define MAXP 1000010
int criba[MAXP+1];
void crearCriba(){
	int w[]={4,2,4,2,4,6,2,6};
	for (int p=25; p<=MAXP; p+=10) criba[p]=5;
	for (int p=9; p<=MAXP; p+=3) criba[p]=3;
	for (int p=4; p<=MAXP; p+=2) criba[p]=2;
	for (int p=7, cur=0; p*p<=MAXP; p+=w[cur++&7])
		if (!criba[p])
			for (int j=p*p; j<=MAXP; j+=(p<<1)) if(!criba[j]) criba[j]=p;
}


int main() {
	crearCriba();
	int n;
	cin>>n;
	criba[1]=1;

	forn(i,n){
		ll a;
		cin>>a;
		ll b=sqrt(a);
		if (b*b==a && !criba[b]){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}
