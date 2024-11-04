//visita grafo

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void visita(int n, vector<vector<bool>> archi, vector<bool> &visitati, int s) {
    visitati[s] = true;
    cout<<s<<endl;
    for(int i = 0; i < archi[s].size(); i++) {
        if(archi[s][i] && !visitati[i]) {
            visita(n, archi, visitati, i);
        }
    }
}   

int main(){
    int n, m, s;
    ifstream in("input.txt");

    in>>n>>m>>s;

    // vector<vector<bool>> archi(n, vector<bool>(n,false));

    vector<vector<bool>> archi(n);
    int n1 = n;
    for (int i = 0; i < n; ++i , n1--) {
        archi[i].reserve(n1);
    }
    int partenza, arrivo;

    for(int i = 0; i < m; i++) {
        in>>partenza>>arrivo;
        if (archi[partenza].size() > (arrivo+1)) {
            archi[arrivo][partenza] = true;
        }
        else {
            archi[partenza][arrivo] = true;
        }
    } 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < archi[i].size(); ++j) {
            cout << archi[i][j] << " ";
        }
        cout << endl;
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