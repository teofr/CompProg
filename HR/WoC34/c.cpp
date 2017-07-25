//#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define debug(a) cerr<< #a <<": "<<a<<endl
#define mini(a, b) (a<b?a:b)
using namespace std;

int gauss (int a){
    return (a*(a+1))/2;
}

/*
         1 2 1
app[1] = 1 0 1
app[2] = 0 1 0


*/


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    map<int, vector<int> > app;
    int n, q;
    cin>>n>>q;
    for (int i=0; i<n; i++){
        int temp;
        cin>>temp;
        app[temp].push_back(i);
    }

    map<int, map<int, int> > ans;

    for (int ii=0; ii<q; ii++){
        int a, b, x, y;
        cin>>a>>b;
        if (app.find(a) == app.end()) a=0;
        if (app.find(b) == app.end()) b=0;
        //Todos los que no estan los pongo en 0
        x=min(a, b);
        y=max(a, b);

        auto fst=ans.lower_bound(x);
        map<int, int>::iterator snd;
        if (fst->first == x){
            //si ya esta el primer elemento
            snd = fst->second.lower_bound(y);
            if (snd->first == y){
                cout<<snd->second<<endl;
                continue;
            }
        }else{
            snd = (ans.insert(fst, make_pair(x, map<int, int> ())))->second.begin();
        }
        // snd es mi lower bound
        //calculo
        app.insert(make_pair(x, vector<int> ()));
        app.insert(make_pair(y, vector<int> ()));
        auto itx = app[x].begin();
        auto ity = app[y].begin();


        debug(x);
        debug(y);
        debug(app[x].size());
        debug(app[y].size());

        auto maxWin = mini((int) app[x].size(), (int) app[y].size());

        int curans = 0;
        if (maxWin>0){
          curans = 0;
          for (int i = 1; i<=maxWin*2; i++){
            int cntx = 0;
              //Para cada tamano de ventana, me fijo el resultado
              debug(i);
              auto rtempx = itx;
              auto rtempy = ity;
              // Preparo la primer ventana
              for (int j=0; j<i; j++){
                if (rtempy!=app[y].end() && *rtempy<*rtempx){
                  rtempy++;
                  cntx--;
                }else{
                  rtempx++;
                  cntx++;
                }
              }
              debug(cntx);
              auto ltempx = itx;
              auto ltempy = ity;
              // Las que quedan
              for (int j=i; j<=app[x].size()+app[y].size(); j++){
                debug(j);
                if (rtempy!=app[y].end() && *rtempy<*rtempx){
                  rtempy++;
                  cntx--;
                }else{
                  rtempx++;
                  cntx++;
                }
                if (ltempy!=app[y].end() && *ltempy<*ltempx){
                  ltempy++;
                  cntx++;
                }else{
                  ltempx++;
                  cntx--;
                }

                debug(cntx);

                if (!cntx){

                  auto rhsx = rtempx;
                  auto rhsy = rtempy;
                  auto lhsx = ltempx;
                  auto lhsy = ltempy;

                  // Veo cuanto me extiendo para el lado derecho
                  int rext;
                  if (rtempx == app[x].end()){
                    if (rtempy == app[y].end()){
                      // los dos son end
                      auto ittx = rtempx;
                      auto itty = rtempy;
                      ittx--;
                      itty--;
                      rext = n - max(*ittx, *itty);
                    }else{
                      //solo rtempx es end
                      auto ittx = rtempx;
                      auto itty = rtempy;
                      ittx--;
                      itty++;
                      rext = (itty==app[y].end()? n : *itty) - max(*ittx, *rtempy);
                    }
                  }else{
                    //rtemx no es end
                    if (rtempy == app[y].end()){
                      // solo rtempy es end
                      auto ittx = rtempx;
                      auto itty = rtempy;
                      ittx++;
                      itty--;
                      rext = (ittx==app[x].end()? n : *ittx) - max(*rtempx, *itty);
                    }else{
                      //ninguno es end
                      auto ittx = rtempx;
                      auto itty = rtempy;
                      ittx++;
                      itty++;
                      if (ittx == app[x].end()){
                        rext = (itty==app[y].end()? n : *itty) - max(*rtempx, *rtempy);
                      }else{
                        rext = (itty==app[y].end()? *ittx : min(*ittx, *itty)) - max(*rtempx, *rtempy);
                      }
                    }
                  }

                  // Veo cuanto me extiendo para el lado izquierdo
                  int lext;
                  if (ltempx == app[x].begin()){
                    if (ltempy == app[y].begin()){
                      // los dos son begin
                      lext = min(*ltempx, *ltempy);
                    }else{
                      //solo ltempx es begin
                      auto itty = rtempy;
                      itty--;
                      lext = (ltempy==app[y].end()? *ltempx : min(*ltempx, *ltempy)) - *itty;
                    }
                  }else{
                    //ltempx no es begin
                    if (ltempy == app[y].begin()){
                      // solo ltempy es begin
                      auto ittx = ltempx;
                      ittx--;
                      lext = (ltempx==app[y].end()? *ltempy : min(*ltempx, *ltempy)) - *ittx;
                    }else{
                      //ninguno es begin
                      auto ittx = ltempx;
                      auto itty = ltempy;
                      ittx--;
                      itty--;
                      if (ittx == app[x].begin()){
                        lext = (itty==app[y].begin()? 0 : *itty) - min(*ltempx, *ltempy);
                      }else{
                        lext = (itty==app[y].begin()? *ittx : min(*ittx, *itty)) - min(*ltempx, *ltempy);
                      }
                    }
                  }

                  debug(rext);
                  debug(lext);
                  curans += rext*lext; //por ahi hay que sumarle 1 a cada uno


                }
              }

          }
        }


        //agrego a ans en snd
        debug(curans);
        ans[x][y] = curans;
    }
    return 0;
}
