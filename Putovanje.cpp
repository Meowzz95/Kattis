#include <iostream>
using namespace std;
#include <vector>

int main(){
  freopen("putovanje.3.in","r",stdin);
  int n,c;
  cin>>n>>c;

  vector<int> wList;
  while(n--){
    int w;
    cin>>w;
    wList.push_back(w);
  }

  int maxCount=0;

  for(int i=0;i<wList.size();i++){
    int eaten=0;
    int count=0;
    for(int k=i;k<wList.size();k++){
      int w=wList[k];
      if(eaten+w<=c){
        count++;
        eaten+=w;
      }
    }
    cout<<"loop count"<<count<<endl;
    if(count>maxCount){
      maxCount=count;
    }
  }
  cout<<maxCount<<endl;
}
