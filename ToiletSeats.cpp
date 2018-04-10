#include <iostream>
using namespace std;

int main(){
  freopen("toilet-seats.1.in","r",stdin);
  string cmd;
  cin>>cmd;

  int one=0,two=0,three=0;
  char current=cmd[0];

  for(int i=1;i<cmd.length();i++){
    char pref=cmd[i];
    //common - adjust to pref
    if(current!=pref){
      current=pref;
      one++;
    }
    //one
    if(current!='U'){
      current='U';
      one++;
    }
  }

  current=cmd[0];
  for(int i=1;i<cmd.length();i++){
    char pref=cmd[i];
    //common - adjust to pref
    if(current!=pref){
      current=pref;
      two++;
    }
    //two
    if(current!='D'){
      current='D';
      two++;
    }
  }

  current=cmd[0];
  for(int i=1;i<cmd.length();i++){
    char pref=cmd[i];
    //common - adjust to pref
    if(current!=pref){
      current=pref;
      three++;
    }
    //three
  }

  cout<<one<<endl<<two<<endl<<three<<endl;
}
