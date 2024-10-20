#include <fstream>
using namespace std;

int X,Y;

int A[2000][2000];

int S[2000][2000];

int main(void)
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  in>>X>>Y;
  //riempio la matrice
  for(int x=1;x<=X;x++){
    for(int y=1;y<=Y;y++){
      in>>A[x][y];
    }
  }
  
  for(int x=1;x<=X;x++){
    //mantiene la somma della riga corrente
    int sumr=0;
    for(int y=1;y<=Y;y++){
      sumr+=A[x][y];
      //inserisco la somma della riga fino a questo punto
      S[x][y]=sumr;
    }
  }

  int final=0;
  //per ogni coppia di colonne
  for(int x=1;x<=Y;x++)
    for(int y=x;y<=Y;y++){
      int tot=0;
      //visito la colonna con l'algoritmo lineare per la sottosequenza
      for(int z=1;z<=X;z++){
          int temp=S[z][y]-S[z][x-1];
          tot=max(temp,temp+tot);
          final=max(final,tot);
      }
    }
  out<<final<<endl;
  return 0;
}
