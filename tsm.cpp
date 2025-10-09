#include "tsm.h"

void findHamilton(int G[][20], int n, bool visit[], int path[], int step, int start, int distance, const int first, int &minDist, int shortest[]) {
    if (distance<minDist){
        if (step == n) {
            if (G[start][first]!=0){
                distance+=G[start][first];
                if(distance<minDist){
                    minDist = distance;
                    for (int i = 0; i < n; i++){
                        shortest[i] = path[i];
                    }
                }
            }
            return;
        }
        
        int next=0;
        while (next<n) {
            if (next==start  || visit[next] || G[start][next]==0){
                next++;
            }
            
            else{
                visit[next] = true;
                path[step] = next;
                distance+=G[start][next];
                findHamilton(G, n, visit, path, step+1, next, distance, first, minDist, shortest);
                
                visit[next]=false;
                distance-=G[start][next];
                next++;
            }
        }
    }
}

string Traveling(int G[][20], int n, char vertex){
    string result;
    bool visit[20];
    for (int i=0; i<n; i++) visit[i]=false;
    int path[20];
    int start = vertex - 'A';
    int minDist = 1000;
    int shortest[20];

    visit[start] = true;
    path[0] = start;
    findHamilton(G, n, visit, path, 1, start, 0, start, minDist, shortest);
    
    result+=vertex;
    result+=" ";
    for (int i=1; i<n; i++){
        char step=shortest[i]+65;
        result+=step;
        result+=" ";
    }
    result+=vertex;
    
    return result;
}
