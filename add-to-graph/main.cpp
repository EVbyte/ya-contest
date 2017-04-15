#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int LEN_MAX = int(1e4) + 10;

long long nodescount;
long long connectionscount;
vector<int> connections[LEN_MAX];

bool used[LEN_MAX];
int cnt;

void dfs (int v) {
	used[v] = true;
	for (int i=0; i<connections[v].size(); i++) {
		int to = connections[v][i];
		if (!used[to])
			dfs (to);
	}
}

void find_comps() {
    cnt = 0;
	for (int i=1; i < nodescount+1; i++)
		used[i] = false;
	for (int i=1; i < nodescount+1; i++)
		if (!used[i]) {
			dfs (i);
			cnt++;
		}
    cout << cnt - 1;
}

void init()
{
    cin >> nodescount >> connectionscount;
    for(int i = 0; i < connectionscount; i++){
        int fromnodeid, tonodeid;
        cin >> fromnodeid >> tonodeid;
        connections[fromnodeid].push_back(tonodeid);
        connections[tonodeid].push_back(fromnodeid);
    }
}

int main()
{
    // vector<int> m;
    // m.push_back(1);
    // m.push_back(2);
    // cout << m.size();
    init();

    // // **************Test Programm Input*************************
    // for(int i = 1; i < nodescount + 1; i++)
    //     for(int j = 0; j < connections[i].size(); j++){
    //         cout << i << "-th to: " << connections[i][j] << ' ';
    //         cout << connections[i].size() << '\n';
    //     }

    // for(int i = 1; i < nodescount + 1; i++){
    //     // cout << connections[i].size();
    //     if(connections[i].size() == 0){
    //         nodewithoutconnactionscount++;
    //     }
    // }
    if(nodescount == 1){
        cout << 0;
    }else{
        find_comps();
    }
    return 0;
}
