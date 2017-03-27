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

	int n,k;
	cin>>n>>k;

	vector<int> pibes(n);
	forn(i,n){
		pibes[i]=i+1;
	}

	vector<int> saco(k);

	forn(i,k){
		cin>>saco[i];
	}
	int leader=0;

	forn(i, k){
		int asacar=(leader+saco[i])%pibes.size();
		cout<<pibes[asacar]<<' ';
		pibes.erase(pibes.begin() + asacar);
		leader=asacar;
	}
	cout<<endl;

	return 0;
}
