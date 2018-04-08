#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cassert>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define snd second
#define fst first

using namespace std;

int main() {
	bool res=false;

	vector<int> v (16);
	forn(i,16){
		cin>>v[i];
	}

	forn(i,4){
		res=res||(v[3+i*4] && (v[0+i*4] || v[1+i*4] || v[2+i*4] || v[(4+i*4)%16] || v[(9+i*4)%16] || v[(14+i*4)%16]));
		// 3  -> 0,1,2,4,9,14
		// 15 -> 12,13,14,0,5,10
	}
	//res=res||(v[3] && (v[0] || v[1] || v[2] || v[(5)%16] || v[(9)%16] || v[(14)%16]));
	//res=res||(v[7] && (v[4] || v[5] || v[6] || v[(8)%16] || v[(9)%16] || v[(14)%16]));
	//res=res||(v[3] && (v[0] || v[1] || v[2] || v[(5)%16] || v[(9)%16] || v[(14)%16]));
	//res=res||(v[3] && (v[0] || v[1] || v[2] || v[(5)%16] || v[(9)%16] || v[(14)%16]));

	cout<<(res?"YES":"NO")<<endl;
	return 0;
}
