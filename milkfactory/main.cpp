#include <bits/stdc++.h>

using namespace std;

void dfs(set<int> &visited, map<int, vector<int>> graph, int node){
    if (visited.find(node) == visited.end()){ // if doesnt exist
        visited.insert(node);
        if (graph.count(node) > 0){
            vector<int> neighbors = graph.at(node);
            for (int i = 0; i < neighbors.size(); i++){
                int neighbor = neighbors[i];                
                dfs(visited, graph, neighbor);                
            }
        }
    }
}

int main() {
    ifstream cin("factory.in");
    ofstream cout("factory.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    set<int> stations;
    map<int, vector<int>> belts;

    for (int i = 0; i < n -1; i++){ // Get input
        int a, b;
        cin >> a;
        cin >> b;
        if (belts.count(b) == 0){
            belts.insert(pair<int, vector<int>>(b , {a}));   
        } else{
            vector<int> h = belts.at(b);
            h.push_back(a);
            belts[b] = h;
        }

        stations.insert(a);
        stations.insert(b);
    }

    // iterate through every station
    set<int>::iterator sitr;
    int min_all = -1;
    for(sitr = stations.begin(); sitr != stations.end(); sitr++){
        int b = *sitr;
        set<int> check = stations;
        check.erase(*sitr);

        // iterate through every other station
        set<int>::iterator citr;
        int connects = 0;
        int reached = 0;

        if (belts.count(b) > 0){
            set<int> visited;
            dfs(visited, belts, b );

            for(citr = check.begin(); citr != check.end(); citr++){
                int a = *citr;
                if (visited.find(a) != visited.end()){
                    reached++;
                }
            }
        } 

        if (reached == n - 1){
            if (min_all == -1 || b < min_all){
                min_all = b;
            }
        }
    }
    cout << min_all << endl;
    return 0;

}
