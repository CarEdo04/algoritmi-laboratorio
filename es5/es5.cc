//intervalli scoperti

#include <iostream>
#include <fstream>
using namespace std;

struct libero {
    int start;
    int stop;
    libero* next;
};

void occupied(libero* &l, int start[], int stop[],int n){
    for(int i=0;i<n;i++){
        if(l==NULL){
            l = new libero;
            l->start = start[i];
            l->stop = stop[i];
            l->next = NULL;
        }
        bool modificato = true;
        while (l!=NULL&&modificato){
            // allargo l'intervallo
            if(start[i]<l->start && stop[i]>l->start){
                l->start = start[i];
                modificato = false;
            }
            if(start[i]<l->stop && stop[i]>l->stop){
                l->stop = stop[i];
                modificato = false;
            }
            l=l->next;
        }
        //creo un nuovo intervallo
        if(modificato){
            libero* temp = new libero;
            temp->start = start[i];
            temp->stop = stop[i];
            temp->next = l;
            l = temp;
        }
    }
}

void mergeIntervals(libero* &l) {
    if (l == NULL && l->next == NULL) return;

    libero* current = l->next,* comp=l,*temp=NULL;
    while(current!=NULL){
        if (
            (current->start <= comp->stop && current->start >= comp->start)||
            (current->stop <= comp->stop && current->stop >= comp->start)
            )
         {
            comp->start = min(comp->start, current->start);
            comp->stop = max(comp->stop, current->stop);
            temp=current->next;
            delete current;
            current = temp;
        } else {
            current = current->next;
        }

    }
}

void sortIntervals(libero* &l) {
    if (l == NULL || l->next == NULL) return;

    bool swapped;
    do {
        swapped = false;
        libero* current = l;
        libero* prev = NULL;
        while (current->next != NULL) {
            if (current->start > current->next->start) {
                // Swap the intervals
                libero* temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev == NULL) {
                    l = temp;
                } else {
                    prev->next = temp;
                }
                swapped = true;
                prev = temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

libero * findLongestGap(libero* l) {
    if (l == NULL || l->next == NULL) return 0;

    int longestGap = 0;
    int start=0,stop=0;
    libero* current = l;

    while (current->next != NULL) {
        int gap = current->next->start - current->stop - 1;
        if (gap > longestGap) {
            longestGap = gap;
            start = current->stop;
            stop=current->next->start;
        }
        current = current->next;
    }

    libero* longest = new libero;
    longest->start = start;
    longest->stop = stop;
    return longest;
}

int main(){
    int n;
    ifstream in("input.txt");

    in>>n;

    int start[n],stop[n];
    libero *l = NULL;

    for(int i=0;i<n;i++){
        in>>start[i]>>stop[i];
        stop[i]--;
        occupied(l,start,stop,n);
        mergeIntervals(l);
    }

    mergeIntervals(l);
    sortIntervals(l);
    libero *longest = findLongestGap(l);

    ofstream out("output.txt");

    if(longest->start==0 && longest->stop==0){
        out<<"0"<<"\n";
    } else {
        out<<longest->start<<" "<<(longest->stop+1)<<"\n";
    }




}
