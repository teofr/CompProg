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
	int n; cin>>n;

	forn(i,n){
		forn(j,(n-1)/2)
			cout<<j*n+i+1<<' '<<n*n-j*n-i<<' ';
		cout<<n*n/2+i+1<<' '<<n*n-n*n/2-i<<endl;
	}

	return 0;
}
