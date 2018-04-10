#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>


int maxN,maxM;
int main(){
  //freopen("mockpe4.1.in","r",stdin);
  //9 14 row col
  int n,m;
  cin>>n>>m;
  maxN=n;
  maxM=m;
  char image[n][m];
  int visit[n][m];
  for(int i=0;i<n;i++){
    string line;
    getline(cin,line);
    for(int k=0;k<m;k++){
      char input=line[k];

      image[i][k]=input;
      visit[i][k]=0;
    }
  }
  //down,right
  int dn[]={1,0};
  int dm[]={0,1};

  vector<pair<pair<int,int>,pair<int,int>>> faces;
  vector<pair<int,int>> smiles;
  unordered_map<int,bool> smileFaceIdMap;



  //find ###
  for(int i=0;i<n;i++){
    for(int k=0;k<m;k++){
      char c=image[i][k];
      if(c=='v'){
        smiles.push_back({i,k});
      }
      //if this char has been visited skip
      if(visit[i][k]==1){
        continue;
      }
      if(c=='#'){
        pair<pair<int,int>,pair<int,int>> face;
        face.first={i,k};
        queue<pair<int,int>> q;

        q.push({i,k});
        while(!q.empty()){
          auto cPoint=q.front();
          q.pop();
          auto cN=cPoint.first;
          auto cM=cPoint.second;
          //cout<<"cn cm "<<cN<<" "<<cM<<endl;
          if(visit[cN][cM]==1){
            //cout<<"face found"<<endl;
            face.second={cN,cM};
            faces.push_back(face);
            continue;
          }

          visit[cN][cM]=1;
          //calc next
          for(int j=0;j<2;j++){
            auto nextN=cN+dn[j];
            auto nextM=cM+dm[j];
            //cout<<"nextN,nextM "<<nextN<<","<<nextM<<endl;
            if(nextN>maxN-1||nextM>maxM-1){
              //cout<<"out of bound"<<endl;
              continue;
            }
            if(image[nextN][nextM]!='#'){
              //cout<<"not # skip"<<endl;
              continue;
            }
            // if(visit[nextN][nextM]==1){
            //   //if cycle deteced, this is the other side of square
            //   face.second={nextN,nextM};
            //   faces.push_back(face);
            //   cout<<"face end found"<<endl;
            // }
            // else{
              //cout<<"adding to explore queue"<<endl;
              q.push({nextN,nextM});
            // }
          }
        }
      }
    }
  }

  //print faces
  // for(auto &face:faces){
  //   auto p1=face.first;
  //   auto p2=face.second;
  //   cout<<"face "<<p1.first<<","<<p1.second<<" "<<p2.first<<","<<p2.second<<endl;
  //
  //
  // }

  for(int i=0;i<smiles.size();i++){
    auto n=smiles[i].first;
    auto m=smiles[i].second;
    for(int k=0;k<faces.size();k++){
      auto face=faces[k];
      auto p1n=face.first.first;
      auto p1m=face.first.second;
      auto p2n=face.second.first;
      auto p2m=face.second.second;
      if(n>p1n&&n<p2n&&m>p1m&&m<p2m){
        //cout<<"this smile is in "<<k<<endl;
        smileFaceIdMap.insert({k,true});
      }
    }
  }
  cout<<faces.size()<<endl;
  cout<<smileFaceIdMap.size()<<endl;

  //print
  // for(int i=0;i<n;i++){
  //   for(int k=0;k<m;k++){
  //     cout<<image[i][k];
  //   }
  //   cout<<endl;
  // }

}
