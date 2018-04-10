#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> al;
vector<int> visited;

void dfs(int node)
{
    //mark current node as visited
    visited[node] = 1;
    for(auto &it : al[node]) //check all neighbour in this node
        if(!visited[it])
            dfs(it);
}

int main()
{
    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int roadEndpoints, pair, output = 0;
        cin >> roadEndpoints >> pair;
        al.assign(roadEndpoints, vector<int>());
        for(int i = 0; i < pair; i++)
        {
            int a, b;
            cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        visited.assign(roadEndpoints, 0);
//        dfs(0);

        for(int j = 0; j < visited.size(); j++)
            if(!visited[j])
            {
//                cout << "not visited: " << j << endl;
                output++;
                dfs(j);
            }

            cout << output - 1 << endl;
    }
    return 0;
}