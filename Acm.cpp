#include <iostream>
using namespace std;
#include <unordered_map>

int main(){
  freopen("acm.2.in","r",stdin);
  unordered_map<char,int> timeMap;
  unordered_map<char,bool> statusMap;
  while(true){
    int time;
    cin>>time;
    if(time==-1){
      break;
    }
    char q;
    string status;
    cin>>q>>status;
    //cout<<"q "<<q<<" "<<status<<endl;
    if(status=="right"){
      timeMap[q]+=time;
      statusMap[q]=true;
    }
    else{
      timeMap[q]+=20;
    }
  }
  int sum=0;
  for(auto it=timeMap.begin();it!=timeMap.end();advance(it,1)){
    if(statusMap.find(it->first)!=statusMap.end()){
      sum+=it->second;
    }
  }
  cout<<statusMap.size()<<" "<<sum<<endl;
}
