//#include "../../stdc++.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

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
	cin>>n>>m;

	int dos,uno;
	dos=n/2;
	uno=n%2;

	while(dos>0 && (dos+uno)%m!=0){
		dos--;
		uno+=2;
	}

	cout<<((dos+uno)%m==0?dos+uno:-1)<<endl;

	return 0;
}
