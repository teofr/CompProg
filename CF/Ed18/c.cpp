//#include "../../stdc++.h"
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {

	int n,m;
	vector<int> orig, mod3;

	cin>>n;
	m=n;
	while (n>0){
		orig.pb(n%10);
		mod3.pb((n%10)%3);
		n=n/10;
	}

	int suma=0;
	for (v:mod3){
		suma+=v;
	}
	suma=suma%3;

	vector<int> pos1;
	vector<int> pos2;

	forn(i,mod3.size()){
		if (mod3[i]==1){
			pos1.pb(i);
		}else if (mod3[i]==2){
			pos2.pb(i);
		}
	}

	if (suma==0){
		cout<<m<<endl;
	}else if (suma==1){
		//Caso saco un 1;
		int costo=10;
		int ceros=0;
		int pos=-1;

		if (pos1.size()>0 && pos1[0]!=mod3.size()){
			
		}

		//Caso saco dos 2

	}

	return 0;
}
