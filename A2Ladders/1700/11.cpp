//#include "../../stdc++.h"
#include <bits/stdc++.h>
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

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    
    ll res=0;

    vector<ll> v={a,b,c};
    sort(v.begin(), v.end());

    while (v[2]+v[1]+v[0]>=3 && v[1]){
    	if (v[2]-v[1]>=1 || v[1]-v[0]>=1){
    		res++;
    		v[2]-=2;
    		v[1]--;
    	sort(v.begin(), v.end());

    	}else{
    		ll cur=v[0];
    		res+=cur;
    		forn(i,3){
    			v[i]-=cur;
    		}
    	}

    }
   
    cout<<res<<endl;
    
    return 0;
    
}