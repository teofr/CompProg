#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
#define debug(a) //cerr<< #a <<": "<< (a) <<endl;
#define debugMat(ans) //debug ((ans).x1); debug ((ans).x2); debug ((ans).y1); debug ((ans).y2); cerr<<endl;
//#define MOD 1000000000+7
typedef int tint;
typedef pair<int,int> ii;
typedef double tipo;

const tint MOD = 1000000007;

/** MATRICES
  ( x1  y1  )
  ( x2  y2  )
*/


struct mat{
  tint x1, x2, y1, y2;

  mat operator+ (mat otro){
    mat res;
    res.x1 = (x1+otro.x1) % MOD;
    res.x2 = (x2+otro.x2) % MOD;
    res.y1 = (y1+otro.y1) % MOD;
    res.y2 = (y2+otro.y2) % MOD;

    return res;
  }

  mat operator* (mat otro){
    mat res;
    res.x1=(x1*otro.x1 + y1*otro.x2) % MOD;
    res.x2=(x2*otro.x1 + y2*otro.x2) % MOD;
    res.y1=(x1*otro.y1 + y1*otro.y2) % MOD;
    res.y2=(x2*otro.y1 + y2*otro.y2) % MOD;
    return res;
  }

  mat power(tint n){
    if (n==0){
      mat res;
      res.x1=res.y2=1;
      res.x2=res.y1=0;
      return res;
    }else if (n==1){
      return *this;
    }else{
      mat half = power(n/2);
      return half*half*power(n%2);
    }
  }
};
/////

vector<vector<int> > gr;
vector<int> peso;
mat fibo;
mat resGen;
mat dfs(int start, int parent, mat pre){
  debug(start);
  mat toparent = fibo.power(peso[start])*pre;
  resGen = resGen + toparent;
  debugMat(pre);
  debug(peso[start]);
  debugMat(fibo.power(peso[start]));
  debugMat(toparent);
  mat res = fibo.power(peso[start]);

  vector<mat> sons;

  for (auto node:gr[start]){
    if (node != parent){
      mat tempans = dfs(node, start, toparent + fibo.power(peso[start]));
      debugMat(tempans);
      sons.pb(tempans);
      resGen = resGen + tempans;

      res = res + tempans*fibo.power(peso[start]);
    }
  }


  forn (i, sons.size()){
    forn(j, sons.size()){
      if (i != j){
        debugMat(sons[i]);
        debugMat(sons[j]);
        debugMat(fibo.power(peso[start])*sons[i]*sons[j]);
        resGen = resGen + fibo.power(peso[start])*sons[i]*sons[j];
      }
    }
  }

  debugMat(res);
  debug(start);
  return res;
}

int main() {
  int n;
  cin>>n;
  gr = vector<vector<int> > (n);
  peso = vector<int> (n);
  fibo.x1 = 0;
  fibo.x2 = fibo.y1 = fibo.y2 = 1;
  resGen = {0,0,0,0};
  //MOD = 1000000007;

  forn(i, n-1){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    gr[a].pb(b);
    gr[b].pb(a);
  }

  forn(i, n){
    cin>>peso[i];
  }

  int root;
  forn(i, n){
    if (gr[i].size() <= 1) root = i;
  }

  mat ans = dfs(root, -1, {0,0,0,0});
  debugMat(ans);
  ans = ans + resGen;

  debugMat(resGen);
  cout<<(ans.x1 + ans.y1) % MOD<<endl;

  return 0;
}
