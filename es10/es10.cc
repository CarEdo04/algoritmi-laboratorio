//cammini minimi tra due nodi definiti

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include <queue>
#include <climits>

int bfs(const vector<vector<bool>>& archi, int start, int end) {
    vector<int> dist(archi.size(), INT_MAX);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < archi.size(); ++i) {
            if (archi[node][i] && dist[i] == INT_MAX) {
                dist[i] = dist[node] + 1;
                q.push(i);
                if (i == end) {
                    return dist[i];
                }
            }
        }
    }

    return -1; // return -1 if there is no path from start to end
}




int main(){
    int n, m, a, b;
    ifstream in("input.txt");

    in>>n>>m>>a>>b;

    vector<vector<bool>> archi(n, vector<bool>(n,false));

    int partenza, arrivo;

    for(int i = 0; i <= m; i++) {
        in>>partenza>>arrivo;
        archi[partenza][arrivo] = true;
    } 

    int distanza = 0, cammini = 0;
    distanza = bfs(archi, a, b);
    cout<<distanza<<endl;

    
    ofstream out("output.txt");
    out<<endl;

    return 0;
}