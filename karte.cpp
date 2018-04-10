#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int main(){
  freopen("karte.2.in","r",stdin);


  unordered_map<char,unordered_map<int,int>> aMap;

  char suit;
  int card;
  while(cin>>suit>>card){
    auto cardMap=aMap[suit];
    if(cardMap.find(card)!=cardMap.end()){
      cout<<"GRESKA"<<endl;
      return 0;
    }
    aMap[suit][card]++;
  }
  auto pMap=aMap['P'];
  auto kMap=aMap['K'];
  auto hMap=aMap['H'];
  auto tMap=aMap['T'];

  cout<<(13-pMap.size())<<" ";
  cout<<13-kMap.size()<<" ";
  cout<<13-hMap.size()<<" ";
  cout<<13-tMap.size()<<" ";



  //cout<<"end";
  return 0;
}
