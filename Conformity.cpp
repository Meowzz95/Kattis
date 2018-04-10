#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  freopen("Conformity.1.in","r",stdin);
  int tc;
  cin>>tc;
  map<vector<int>,int> aMap;

  while(tc--){
    vector<int> v;
    for(int i=0;i<5;i++){
      int input;
      cin>>input;
      v.push_back(input);
    }
    sort(v.begin(),v.end());
    aMap[v]++;
  }
  int maxPop=-1;
  for(auto it=aMap.begin();it!=aMap.end();advance(it,1)){
    if(it->second>maxPop){
      maxPop=it->second;
    }
  }
  int count=0;
  for(auto it=aMap.begin();it!=aMap.end();advance(it,1)){
    if(it->second==maxPop)
      count+=it->second;
  }
  int output;
  if(count!=1){
    output=count;
  }
  else{
    output=aMap.begin()->second;
  }


  cout<<count<<endl;
}
