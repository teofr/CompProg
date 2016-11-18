//#include "../../stdc++.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {

	int n;
	int suma=0;
	cin>>n;
	int ant=0;
	forn(i,n){
		int a;
		cin>>a;
		suma+=a;

		if(ant && !a){
			//cerr<<"No con "<<i<<endl;
			cout<<"NO"<<endl;
			return 0;
		}
		a-=ant;
		ant=a%2;
	}

	cout<<(!ant?"YES":"NO")<<endl;

	return 0;
}
