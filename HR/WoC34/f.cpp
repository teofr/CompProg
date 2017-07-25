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
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define debug(a) //cerr<< #a <<": "<<a<<endl;
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;
/////


typedef vector<list<pair<int, int> > > camino;
vector<list<pair<int, int> > > fromroot;
vector<vector<int> > adj;
vector<int> pesos;

vector<int> padres;

void dfsP(int n){
  for (auto son : adj[n]){
    if (son != padres[n]){
      padres[son] = n;
      dfsP(son);
    }
  }
}

struct query{
  int u;
  int v;
  int k;

  bool operator< (const query& otro) const{
    if (u != otro.u){
      return u<otro.u;
    }else if (v != otro.v){
      return v<otro.v;
    }else{
      return k< otro.k;
    }
  }
};

void dfs (int start, const list<pair<int, int> > & path, int padre){
  fromroot[start] = path;
  fromroot[start].pb(mp(start, pesos[start]));

  for (auto x : adj[start]){
    if (x != padre){
      dfs(x, fromroot[start], start);
    }
  }

}

int main() {
  int n, q;
  cin>>n>>q;

  pesos = vector<int> (n);

  forn(i,n){
    cin>>pesos[i];
  }

  adj = vector<vector<int> > (n);
  //fromroot = vector<list<pair<int, int> > > (n);
  padres = vector<int> (n);
  padres[0] = -1;

  forn(i, n-1){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfsP(0);
  //dfs(0, list<pair<int, int> > (0), -1);
  //adj.clear();
  //pesos.clear();

  map<query, int> ans;

  forn(j, q){
    int u, v, k;
    cin>>u>>v>>k;
    u--;
    v--;
    k--;
    query q = {u, v, k};
    map<query, int>::iterator it = ans.find(q);
    if (it == ans.end()){

      set<int> seen;
      int uu, vv;
      uu = u;
      vv = v;

      while (seen.find(uu) == seen.end() && seen.find(vv) == seen.end()){
        debug(uu);
        debug(vv);
        if (uu != -1){
          seen.insert(uu);
          uu = padres[uu];
        }
        if (vv != -1){
          seen.insert(vv);
          vv = padres[vv];
        }
      }

      int lca = (seen.find(uu) != seen.end() ? uu : vv);
      debug(lca);
      map<int, int> freq;

      uu = u;
      vv = v;

      while (uu != lca){
        debug(uu);
        freq[pesos[uu]] += 1;
        uu = padres[uu];
      }

      while (vv != lca){
        debug(vv);
        freq[pesos[vv]] += 1;
        vv = padres[vv];
      }

      freq[pesos[lca]] += 1;

      /*
      list<pair<int, int> >& c1 = fromroot[u];
      list<pair<int, int> >& c2 = fromroot[v];

      map<int, int> freq;

      debug(u);
      debug(v);
      debug(k);

      auto it1 = c1.begin();
      auto it2 = c2.begin();

      while (it1 != c1.end() &&
              it2 != c2.end() &&
              *it1 == *it2){
        it1++;
        it2++;
      }

      it1--;
      freq[it1->snd] += 1;
      debug(it1->snd);
      it1++;

      while (it1 != c1.end()){
        freq[it1->snd] += 1;
        debug(it1->snd);
        it1++;
      }

      while (it2 != c2.end()){
        freq[it2->snd] += 1;
        debug(it2->snd);
        it2++;
      }
      */

      set<pair<int, int>, greater<pair<int, int> > > order;

      for (auto x:freq){
        debug(x.snd);
        debug(x.fst);

        order.insert(mp(x.snd, x.fst));
      }

      int cur = 0;
      for (auto x:order){
          // se pueden guardar todos los resultados
          if (cur == k){
            cout<<x.snd<<endl;
            ans.insert(mp(q, x.snd));
            break;
          }
          cur++;
      }

    }else{
      cout<<it->snd<<endl;
    }


  }

  return 0;
}
