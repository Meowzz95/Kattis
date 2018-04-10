#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class RouteCalc{
private:
  const char MAX_X='H';
  const char MIN_X='A';
  const int MAX_Y=8;
  const int MIN_Y=1;
  char x;
  int y;
  vector<pair<char,int>> routes;

  bool IsOutBound(char x,int y){
    return x>MAX_X||x<MIN_X||y>MAX_Y||y<MIN_Y;
  }
  void GoDirOne(char x,int y){
    if(IsOutBound(x,y))
      return;
    routes.push_back({x,y});
    GoDirOne(x+1,y+1);
  }
  void GoDirTwo(char x,int y){
    if(IsOutBound(x,y))
      return;
    routes.push_back({x,y});
    GoDirTwo(x-1,y+1);
  }
  void GoDirThree(char x,int y){
    if(IsOutBound(x,y))
      return;
    routes.push_back({x,y});
    GoDirThree(x-1,y-1);
  }
  void GoDirFour(char x,int y){
    if(IsOutBound(x,y))
      return;
    routes.push_back({x,y});
    GoDirFour(x+1,y-1);
  }
public:
  RouteCalc(char x,int y):x(x),y(y){}
  vector<pair<char,int>> Calculate(){
    GoDirOne(x+1,y+1);
    GoDirTwo(x-1,y+1);
    GoDirThree(x-1,y-1);
    GoDirFour(x+1,y-1);
    return routes;
  }
};
int main(){
  freopen("chess.in","r",stdin);
  int tc;
  cin>>tc;
  for(int i=0;i<tc;i++){
    char x1,x2;
    int y1,y2;
    cin>>x1>>y1>>x2>>y2;
    //impossible
    if ((abs(x1-x2)%2==1 && abs(y1-y2)%2==0) ||
        (abs(x1-x2)%2==0 && abs(y1-y2)%2==1)) {
      cout<<"Impossible"<<endl;
      continue;
    }
    //same point solution
    if(x1==x2 && y1==y2){
      cout<<0<<" "<<x1<<" "<<y1<<endl;
      continue;
    }

    //move one or two steps solution
    //calculate all routes for initial point(point one)
    RouteCalc oneRouteCalc(x1,y1);
    auto oneRoutes=oneRouteCalc.Calculate();
    //one step solution
    bool foundSolution=false;
    for(auto &route:oneRoutes){
      if(route.first==x2&&route.second==y2){
        cout<<1<<" "<<x1<<" "<<y1<<" ";
        cout<<x2<<" "<<y2<<endl;
        foundSolution=true;
        break; //break search loop
      }
    }
    if(foundSolution){
      continue;//continue to next test case
    }

    //two step solution
    RouteCalc twoRouteCalc(x2,y2);
    auto twoRoutes=twoRouteCalc.Calculate();
    for(auto &oneRoute:oneRoutes){
      bool foundSolution=false;
      for(auto &twoRoute:twoRoutes){
        //find intersection
        if(oneRoute.first==twoRoute.first&&oneRoute.second==twoRoute.second){
          cout<<2<<" "<<x1<<" "<<y1<<" ";
          cout<<oneRoute.first<<" "<<oneRoute.second<<" ";
          cout<<x2<<" "<<y2<<endl;
          foundSolution=true;
          break;
          }
        }
        if(foundSolution){
          break;//break in case multiple solutions exist
      }
    }
  }
  return 0;
}
