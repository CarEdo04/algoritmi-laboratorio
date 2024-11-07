#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

struct point {
    int x;
    bool start;
};



int main() {
    int n;
    ifstream in("input.txt");
    in>>n;

    vector<point> points(2*n);
    bool b=true;

    for(int i = 0; i < 2*n; i++) {
        int x;
        in>>x;
        points[i] = {x,b};
        if(b) {
            b = false;
        }
        else {
            b = true;
        }
    }

    
    //sort
    sort(points.begin(), points.end(), [](const point &a, const point &b) {
        if (a.x == b.x) {
            return a.start > b.start;
        }
        return a.x < b.x;
    });

    int intervalli = 0, start=1, stop=0, libero=0;
    int libero_max = 0,start_max=0,stop_max=0;

    for(int i = 0; i < 2*n; i++) {
        //controllo l'intervallo inizia o finisce
        if(points[i].start) {
            intervalli++;
        }
        else {
            intervalli--;
        }
        cout<<intervalli<<"  "<<points[i].x<<endl;
        if(intervalli == 0) {
            libero=points[i+1].x-points[i].x;  
            /* if(libero > libero_max) {
                libero_max = libero;
                start_max = points[i].x;
                stop_max = points[i+1].x;
            } */
        }
        if(intervalli == 0&&libero>0) {
            start = points[i].x;
        }
        if(intervalli > 0 && libero>0) {
            stop = points[i].x;
            if(libero > libero_max) {
                libero_max = libero;
                start_max = start;
                stop_max = stop;
            }
            libero = 0;
        } 

    }

    ofstream out("output.txt");
    if(stop==0){
        out<<"0"<<endl;
    }else{
        out<<start_max<<" "<<stop_max<<endl;
    }
    return 0;
}