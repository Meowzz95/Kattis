#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int maxN,maxM;
bool isValid(int n,int m){
  return n<maxN&&n>=0&&m<maxM&&m>=0;
}


int main(){
  //freopen("grid.4.in","r",stdin);
  int n,m;
  cin>>n>>m;
  maxN=n;
  maxM=m;
  cin.get();
  int grid[n][m];
  int state[n][m];

  for(int i=0;i<n;i++){
    string line;
    getline(cin,line);
    for(int k=0;k<m;k++){
      string s(1,line[k]);
      //cout<<"reading data "<<s<<endl;
      grid[i][k]=stoi(s);
      state[i][k]=INT_MAX;
    }
  }


  //start bfs
  queue<pair<int,int>> q;
  state[0][0]=0;
  q.push({0,0});
  while(!q.empty()){
    auto current=q.front();
    q.pop();
    auto currentValue=grid[current.first][current.second];
    int dn[]={0-currentValue,0,currentValue,0};
    int dm[]={0,0-currentValue,0,currentValue};
    for(int i=0;i<4;i++){
      int nextN=current.first+dn[i];
      int nextM=current.second+dm[i];
      //cout<<"next n,m "<<nextN<<","<<nextM<<endl;
      if(!isValid(nextN,nextM)){
        continue;
      }
      if(state[nextN][nextM]!=INT_MAX){
        continue; //skip visited
      }
      //cout<<"current state "<<state[current.first][current.second]<<endl;
      if(state[current.first][current.second]+1<state[nextN][nextM]){
        state[nextN][nextM]=state[current.first][current.second]+1;
      }
      q.push({nextN,nextM});
    }
  }

  auto steps=state[maxN-1][maxM-1];
  if(steps==INT_MAX){
    cout<<"-1"<<endl;
  }else{
    cout<<steps<<endl;
  }

}
