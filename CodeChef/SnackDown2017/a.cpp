//#include "../../stdc++.h"
//#include <bits/stdc++.h>
#include <iostream>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {

	int r;
	cin>>r;

	forn(i,r){
		int l;
		cin>>l;
		int res=0;

		int k=0;
		forn(j, l){
			char c;

			cin>>c;
			if (c=='H'){
				res++;
			}else if(c=='T'){
				res--;
			}

			if (!k && (res>1 || res <0)){
				k=1;
			}

		}
		if (!k && res==0){
			cout<<"Valid"<<endl;
		}else{
			cout<<"Invalid"<<endl;
		}

	}

	return 0;
}
