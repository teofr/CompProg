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

	int n;
	cin>>n;
	vector<int> pos(n);

	forn(i,n){
		cin>>pos[i];
	}

	sort(pos.begin(), pos.end());

	int mini=pos[1]-pos[0]+1;
	int cant=0;

	forn(i,n-1){
		int dist=pos[i+1]-pos[i];
		if (dist<mini){
			mini=dist; cant=1;
		}else if(dist==mini){
			cant++;
		}
	}

	cout<<mini<<' '<<cant<<endl;


	return 0;
}
