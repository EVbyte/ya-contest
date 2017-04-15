#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int LEN_MAX = int(1e5) + 10;
const int NUM_MAX = int(1e6) + 10;


struct Connection
{
    int tonodeid;
    int cost;
};

long long nodescount;
long long connectionscount;
vector<Connection> connections[LEN_MAX];
int startnode;
int endnode;
int waycost;
long long costtonodes[LEN_MAX];

void init()
{
    waycost = 0;
    cin >> nodescount >> connectionscount;
    for(int i = 0; i < connectionscount; i++){
        int fromnodeid, tonodeid, cost;
        cin >> fromnodeid >> tonodeid >> cost;
        Connection connection = {connection.tonodeid=tonodeid, connection.cost=cost};
        connections[fromnodeid].push_back(connection);
        Connection second_connection = {connection.tonodeid=fromnodeid, connection.cost=cost};
        connections[tonodeid].push_back(second_connection);
    }
    cin >> startnode >> endnode;

    for(int i = 0; i < LEN_MAX; i++){
        costtonodes[i] = NUM_MAX;
    }
}

void mover(int nodeid){
    for(int i = 0; i < connections[nodeid].size(); i++)
    {
        long long toneighborfromhere = costtonodes[nodeid] + connections[nodeid][i].cost;
        long long neighborcost = costtonodes[connections[nodeid][i].tonodeid];
        int neighborid = connections[nodeid][i].tonodeid;

        // not sure < or <=
        if(toneighborfromhere <= neighborcost){
            costtonodes[neighborid] = toneighborfromhere;
            mover(neighborid);
        }
    }
}

void findwaycost()
{
    costtonodes[startnode] = 0;
    mover(startnode);
    waycost = costtonodes[endnode];
}

int main()
{
    init();

    // // **************Test Programm Input*************************
    // for(int i = 1; i < nodescount + 1; i++){
    //     for(int j = 0; j < connections[i].size(); j++)
    //         cout << i << "-th to: " << connections[i][j].tonodeid << " with cost: " << connections[i][j].cost << "\n";
    // }

    findwaycost();

    cout << waycost;

    return 0;
}
