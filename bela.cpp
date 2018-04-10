#include <iostream>
#include <map>
using namespace std;

int main(){
  freopen("bela.in","r",stdin);
  map<char, pair<int,int>> scoreMap;
  scoreMap.insert({'A',{11,11}});
  scoreMap.insert({'K',{4,4}});
  scoreMap.insert({'Q',{3,3}});
  scoreMap.insert({'J',{20,2}});
  scoreMap.insert({'T',{10,10}});
  scoreMap.insert({'9',{14,0}});
  scoreMap.insert({'8',{0,0}});
  scoreMap.insert({'7',{0,0}});

  int hands;
  char dominant;
  cin>>hands>>dominant;

  cout<<hands<<" "<<dominant<<endl;
  int sum=0;
  for(int i=0;i<hands*4;i++){
    char card,suit;
    cin>>card>>suit;
    cout<<card<<" "<<suit;
    if(suit==dominant){
      sum+=scoreMap[card].first;
    }
    else{
      sum+=scoreMap[card].second;
    }
  }
  cout<<sum<<endl;

}
