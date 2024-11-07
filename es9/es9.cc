//diametro grafo

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> bfs(const vector<vector<bool>>& graph, int start) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max());
    queue<int> q;

    distances[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            if (graph[node][i] && distances[i] == numeric_limits<int>::max()) {
                distances[i] = distances[node] + 1;
                q.push(i);
            }
        }
    }

    return distances;
}

int calculate_diameter(const vector<vector<bool>>& graph) {
    int n = graph.size();
    int diameter = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> distances = bfs(graph, i);
        for (int d : distances) {
            if (d != numeric_limits<int>::max()) {
                diameter = max(diameter, d);
            }
        }
    }

    return diameter;
}




int main(){

    //inserimento grafo
    int n, m;
    ifstream in("input.txt");

    in>>n>>m;

    vector<vector<bool>> archi(n, vector<bool>(n,false));

    int partenza, arrivo;

    for(int i = 0; i <= m; i++) {
        in>>partenza>>arrivo;
        archi[partenza][arrivo] = true;
    } 

    //calcolo diametro
    int diameter = calculate_diameter(archi);
    
    //stampa
    ofstream out("output.txt");
    out<<diameter<<endl;
    cout << diameter << endl;

    return 0;
}