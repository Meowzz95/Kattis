#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;


class Calculator{
private:
  const int UP=-100,DOWN=-101,LEFT=-102,RIGHT=-103;
  int mN,mM;
  vector<vector<int>> grid;
  vector<vector<bool>> visit;
  unordered_map<int,int> routes;
  unordered_map<int,bool> successMap;
  int routeIdSeq=0;

public:
  Calculator(int n,int m):mN(n),mM(m){
    //cout<<"counstructor "<<mN<<" "<<mM<<endl;
  }

  void start(){
    for(int i=0;i<mN;i++){
      string line;
      getline(cin,line);
      vector<int> v;
      grid.push_back(v);
      vector<bool> vVisit;
      visit.push_back(vVisit);
      for(int k=0;k<mM;k++){
        string s(1,line[k]);
        //cout<<"reading data "<<s<<endl;
        grid[i].push_back(stoi(s));
        visit[i].push_back(false);
      }
    }
    //cout<<"data read done"<<endl;

    //print
    // for(int i=0;i<mN;i++){
    //   for(int k=0;k<mM;k++){
    //     cout<<grid[i][k]<<" ";
    //   }
    //   cout<<endl;
    // }
    go(0,0,routeIdSeq);
  }

  void printResult(){
    int minSteps=INT_MAX;
    for(auto it=successMap.begin();it!=successMap.end();advance(it,1)){
      auto successRouteId=it->first;
      auto steps=routes[successRouteId];
      //cout<<"success route id "<<successRouteId<<endl;
      //cout<<"steps "<<steps<<endl;
      if(steps<minSteps){
        minSteps=steps;
      }
    }
    if(successMap.size()==0){
      minSteps=-1;
    }
    cout<<minSteps<<endl;
  }

  void go(int n,int m,int routeId){
    cout<<"go() n="<<n<<" m="<<m<<" routeId="<<routeId<<endl;
    cout<<"current steps"<<routes[routeId]<<endl;
    if(!isValidMove(n,m)){
      cout<<"not valid coordinate return"<<endl;
      return;
    }
    if(isDest(n,m)){
      cout<<"*success*"<<endl;
      successMap[routeId]=true;
      cout<<"success steps "<<routes[routeId]<<endl;
      return;
    }
    if(visit[n][m]==true){
      //cycle
      cout<<"cycle deteced return"<<endl;
      return;
    }
    visit[n][m]=true;
    routes[routeId]++;
    int cValue=grid[n][m];

    //cout<<"Try 4 directions====="<<endl;
    for(int i=UP;i>=RIGHT;i--){
      auto dest=moveFrom(n,m,cValue,i);
      cout<<"next move to "<<dest.first<<" "<<dest.second<<endl;

      routeIdSeq++;
      routes[routeIdSeq]=routes[routeId];
      go(dest.first,dest.second,routeIdSeq);

    }

  }
  pair<int,int> moveFrom(int n,int m,int length,int dir){
    if(dir==UP){
      return {n,m-length};
    }
    if(dir==DOWN){
      return {n,m+length};
    }
    if(dir==LEFT){
      return {n-length,m};
    }
    if(dir==RIGHT){
      return {n+length,m};
    }
    exit(-1);
  }
  bool isValidMove(int n,int m){
    return n<mN&&n>=0&&m<mM&&m>=0;
  }
  bool isDest(int n,int m){
    return n==mN-1&&m==mM-1;
  }

};





int main(){
  freopen("grid.4.in","r",stdin);
  int n,m;
  cin>>n>>m;
  cin.get();


  Calculator c(n,m);
  c.start();
  c.printResult();

  // for(int i=0;i<n;i++){
  //   for(int k=0;k<m;k++){
  //     cout<<grid[i][k]<<" ";
  //   }
  //   cout<<endl;
  // }
}
