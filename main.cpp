#include "bellman.h"
#include "tsm.h"

using namespace std;

void task1(int G[][20], int n){
    int BFValue[20];
    int BFPrev[20];

    for(int i=0;i<n;i++){
        BFValue[i]=-1;
        BFPrev[i]=-1;
    }

    
    for(int i=0;i<n;i++){
        BF(G,n,'A',BFValue,BFPrev);
        cout<<"Step "<<i+1<<":"<<endl;
        
        for(int j=0;j<n;j++){
            cout<<BFValue[j]<<" ";
        }
        cout<<endl;
        
        for(int j=0;j<n;j++){
            cout<<BFPrev[j]<<" ";
        }
        cout<<endl;
    }
}

void task2(int G[][20], int n){
    int BFValue[20];
    int BFPrev[20];

    for(int i=0;i<n;i++){
        BFValue[i]=-1;
        BFPrev[i]=-1;
    }
    cout<<"Shortest path from A to D: "<<BF_Path(G, n, 'A', 'D')<<endl;
}

void task3(int G[][20], int n){
    
    string output=Traveling(G,n,'A');
    cout<<output;
}

int main() {
    int n=8;
    int G[20][20] = {
        {0, 12, 99, 75, 84, 77, 37, 65},
        {36, 0, 40, 90, 71, 38, 9, 75},
        {46, 72, 0, 38, 17, 46, 75, 8},
        {8, 57, 27, 0, 61, 88, 71, 7},
        {54, 60, 76, 66, 0, 24, 50, 15},
        {68, 54, 47, 70, 94, 0, 36, 40},
        {32, 11, 14, 44, 84, 18, 0, 61},
        {96, 59, 35, 4, 15, 63, 31, 0},
    };
    
    cout<<"-------Bellman-Ford calculation-------"<<endl;
    task1(G, n);
    cout<<endl;

    cout<<"-------Bellman-Ford path--------------"<<endl;
    task2(G, n);
    cout<<endl;

    cout<<"-------Traveling sale man-------------"<<endl;
    task3(G, n);
    
    return 0;
}
