#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> list;
int counter=0;
int shootCount=0;

void shoot(int h,int fromIndex){
  //cout<<"shoot h="<<h<<" from index="<<fromIndex<<endl;
  if(h<=0)
    return;
  int startIndex=0;
  bool hit=false;

  for(int i=fromIndex;i<list.size();i++){
    int cH=list[i];
    if(cH==h){
      list[i]=-1;
      startIndex=i;
      shootCount++;
      hit=true;
      break;
    }
  }
  if(!hit){
    return;
  }
  shoot(h-1,startIndex);
}

pair<int,int> GetHI(){
  for(int i=0;i<list.size();i++){
    if(list[i]!=-1)
      return {list[i],i};
  }
  return {-9,-9};
}
int main(){
  //freopen("baloni.1.in","r",stdin);
  int n;
  cin>>n;

  while(n--){
    int h;
    cin>>h;
    list.push_back(h);
  }

  while(true){
    auto pair=GetHI();
    if(pair.first==(-9))
      break;
    counter++;
    shoot(pair.first,pair.second);
  }

  cout<<counter<<endl;
  return 0;

}
