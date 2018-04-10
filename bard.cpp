#include <iostream>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main(){
    freopen("bard2.in","r",stdin);

    int nV,nights;
    cin>>nV;
    cin>>nights;
    map<int,set<int>> vKnowSongsMap;
    int songIdSeq=0;
    set<int> fullSongList;
    for (int i = 0; i < nights; i++) {
        int numOfVPresent;
        cin>>numOfVPresent;
        int vArray[numOfVPresent];
        bool isBardPresent= false;

        for (int k = 0; k < numOfVPresent; k++) {
            int vId;
            cin>>vId;
            vArray[k]=vId;
            if(vId==1){
                isBardPresent=true;
            }
        }
        if(isBardPresent){
            for (int k = 0; k < numOfVPresent; k++) {
                vKnowSongsMap[vArray[k]].insert(songIdSeq);
                fullSongList.insert(songIdSeq);
            }
            songIdSeq++;
        }
        else{
            for (int k = 0; k < numOfVPresent; k++) {
                int vid=vArray[k];
                auto vKnownSongSet = vKnowSongsMap[vid];
                for (int j=0;j<numOfVPresent;j++) {
                    int vToBeAddedId=vArray[j];
                    if(vToBeAddedId==vid)
                        continue;
                    for (auto it = vKnownSongSet.begin(); it != vKnownSongSet.end(); advance(it, 1)) {
                        vKnowSongsMap[vToBeAddedId].insert(*it);
                    }
                }
            }

        }

    }


    for (auto it = vKnowSongsMap.begin(); it != vKnowSongsMap.end(); advance(it,1)) {
        if(it->second==fullSongList){
            cout<<it->first<<endl;
        }
    }
    return 0;
}