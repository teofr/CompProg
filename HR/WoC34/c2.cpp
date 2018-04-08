//#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define debug(a) //cerr<< #a <<": "<<a<<endl
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
        if (app.find(a) == app.end()) a=-1;
        if (app.find(b) == app.end()) b=-1;
        //Todos los que no estan los pongo en 0
        x=min(a, b);
        y=max(a, b);
        debug(x);
        debug(y);

        map<int, map<int, int> >::iterator fst=ans.find(x);
        debug((fst == ans.end()));
        map<int, int>::iterator snd;
        if (fst == ans.end()){
          snd = (ans.insert(fst, make_pair(x, map<int, int> ())))->second.begin();

        }else{
          //si ya esta el primer elemento
          snd = ans[x].find(y);
          if (snd != ans[x].end()){
              cout<<ans[x][y]<<endl;
              continue;
          }
        }
        // snd es mi lower bound
        //calculo

        map<int, int> un; //calculo la un de app[x] y app[y]

        for (auto elem:app[x]){
          un[elem] = x;
        }
        for (auto elem:app[y]){
          un[elem] = y;
        }

        int maxWin = min(app[x].size(), app[y].size()) * (x==y?1:2);

        int curans = 0; //La respuesta que voy a calcular

        // primero la calculo para contiguos con 0 rep de cada un

        if (max(app[x].size(), app[y].size()) == 0){
          curans = gauss(n);
          cout<<curans<<endl;
          ans[x][y] = curans;
          continue;
        }
        curans += gauss(un.begin()->first);
        for (auto it=un.begin(); it!=un.end(); it++){
          auto nextit = it;
          nextit++;

          curans += gauss((nextit==un.end() ? n : nextit->first) - it->first - 1);
        }
        debug(curans);
        // ahora para tamanos de ventanas desde 2, hasta 2*maxWin de a 2

        for (int win=1; win<=maxWin; win++){
          debug(win);

          auto left = un.begin();
          auto right = un.begin();
          int cntx=0;

          for (int ii=0; ii<win; ii++){
            if (right->second==x){
              cntx++;
            }
            if (right->second==y){
              cntx--;
            }
            right++;
          }
          right--;
          // aca left tiene el primer elemento de la ventana
          // y right el ultimo [left, right]

          while (right!=un.end()){
            debug(cntx);

            if (!cntx){
              //que hago si encontre una ventana buena
              //calculo cuanto me extiendo a derecha y a izquierda
              int lext, rext;

              auto nextRight = right;
              nextRight++;

              rext = (nextRight==un.end() ? n : nextRight->first) - right->first;

              if (left==un.begin()){
                lext = left->first+1;
              }else{
                auto prevLeft = left;
                prevLeft--;
                lext = left->first - prevLeft->first;
              }

              debug(rext);
              debug(lext);
              curans+= lext*rext;
            }




            //avanzo la ventana
            right++;
            if (right->second==x){
              cntx++;
            }
            if (right->second == y){
              cntx--;
            }
            if (left->second==x){
              cntx--;
            }
            if(left->second == y){
              cntx++;
            }
            left++;
            debug(curans);
          }
        }


        //agrego a ans en snd
        cout<<curans<<endl;
        ans[x][y] = curans;
    }
    return 0;
}
