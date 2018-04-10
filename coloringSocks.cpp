#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main(){
  freopen("coloringSocks.1.in","r",stdin);
  int s,c,k;
  cin>>s>>c>>k;
  map<int,int> aMap;

  while(s--){
    int color;
    cin>>color;
    aMap[color]++;
  }

  int numOfWM=0;
  int socksCounter=0;
  int lastColor=-1;
  for(auto it=aMap.begin();it!=aMap.end();advance(it,1)){
    // cout<<"current sock "<<it->first<<endl;
    if(lastColor<0||it->first-lastColor>k){
      // cout<<"color change"<<endl;
      numOfWM++;
      socksCounter=0;
      lastColor=it->first;
    }
    socksCounter+=it->second;
    // cout<<"sock counter"<<socksCounter<<endl;
    // cout<<"WM count"<<numOfWM<<endl;
    if(socksCounter>c){
      // cout<<"sock count exceed limit"<<endl;
      int vmAdded=ceil(socksCounter*1.0/c)-1;//plus wm needed more than the first one
      numOfWM+=vmAdded;
      socksCounter-=vmAdded*c;
      // cout<<"after clearing sock count"<<socksCounter<<endl;
      // cout<<"after clearing WM count"<<numOfWM<<endl;
      lastColor=it->first;
    }

  }
  // if(socksCounter>0)
  //   numOfWM++;
  cout<<numOfWM<<endl;

}
