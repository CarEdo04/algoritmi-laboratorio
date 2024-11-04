//diametro grafo

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int bfs(const vector<vector<bool>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            if (graph[node][i] && distance[i] == numeric_limits<int>::max()) {
                distance[i] = distance[node] + 1;
                q.push(i);
            }
        }
    }

    int max_distance = 0;
    for (int dist : distance) {
        if (dist != numeric_limits<int>::max()) {
            max_distance = max(max_distance, dist);
        }
    }

    return max_distance;
}

int findGraphDiameter(const vector<vector<bool>>& graph) {
    int diameter = 0;
    for (int i = 0; i < graph.size(); ++i) {
        diameter = max(diameter, bfs(graph, i));
    }
    return diameter;
}


int main(){

    //inserimento grafo
    int n, m, s;
    ifstream in("input.txt");

    in>>n>>m>>s;

    vector<vector<bool>> archi(n, vector<bool>(n,false));

    int partenza, arrivo;

    for(int i = 0; i <= m; i++) {
        in>>partenza>>arrivo;
        archi[partenza][arrivo] = true;
    } 

    //calcolo diametro
    int diameter = findGraphDiameter(archi);
    
    //stampa
    ofstream out("output.txt");
    out<<diameter<<endl;

    return 0;
}