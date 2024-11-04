//visita grafo

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void visita(int n, vector<vector<bool>> archi, vector<bool> &visitati, int s) {
    visitati[s] = true;
    for(int i = 0; i < n; i++) {
        if(archi[s][i] && !visitati[i]) {
            visita(n, archi, visitati, i);
        }
    }
}

int main(){
    int n, m, s;
    ifstream in("input.txt");

    in>>n>>m>>s;

    vector<vector<bool>> archi(n, vector<bool>(n,false));

    int partenza, arrivo;

    for(int i = 0; i <= m; i++) {
        in>>partenza>>arrivo;
        archi[partenza][arrivo] = true;
    } 

    vector<bool> visitati(n, false);
    visita(n, archi, visitati, s);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(visitati[i]) {
            count++;
        }
    }
    
    ofstream out("output.txt");
    out<<count<<endl;

    return 0;
}


