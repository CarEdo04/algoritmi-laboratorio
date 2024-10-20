//sottosequenza di somma massima

#include <fstream>
using namespace std;

int max(int a, int b){
    return a>b ? a :b;
}


int maxsum4(int A[], int n) {
    int maxSoFar = 0;
    int maxHere = 0;
    for (int i=0; i < n; i++) {
        maxHere = max(maxHere+A[i], 0);
        maxSoFar = max(maxSoFar,maxHere);
        }
    return maxSoFar;
}

int main(){
    int N;
    ifstream in("input.txt");
    in>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    in>>arr[i];

    ofstream out("output.txt");
    out<<maxsum4(arr,N)<<endl;
    return 0;
}