#include "bellman.h"

void BF(int G[20][20], int n, char vertex,int BFValue[20],int BFPrev[20]){
    int start=vertex-'A';
    int BFPreValue[20];
    
    for (int j=0; j<n; j++){
        BFPreValue[j]=BFValue[j];
        if (j==start && BFPreValue[j]==-1) BFValue[j]=0;
        if (BFValue[j]==-1 && G[start][j]!=0){
            BFValue[j] = G[start][j];
            BFPrev[j] = start;
        }
    }
    
    if(BFPreValue[start]!=-1){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) continue;
                if (BFPreValue[i] + G[i][j] < BFValue[j] && G[i][j]>0 && BFPreValue[i]!=-1 || BFValue[j]==-1 && G[i][j]+BFPreValue[i]!=0){
                    BFValue[j] = BFPreValue[i] + G[i][j];
                    BFPrev[j] = i;
                }
            }
        }
    }
}


string BF_Path(int G[][20], int n, char first, char last){
    string result="";
    int start=first-'A';
    int end=last-'A';
    
    if (start==end){
        result+=first;
        return result;
    }
    
    int Value[20]={0};
    int Pre[20]={0};
    int PreValue[20]={0};
    
    for(int i=0;i<n;i++){
        Value[i]=-1;
        Pre[i]=-1;
    }
    
    for (int k=0; k<n; k++){
            for (int j=0; j<n; j++){
                PreValue[j]=Value[j];
            }
        if (k==0)
            for (int j=0; j<n; j++){
                if (j==start) Value[j]=0;
                if (Value[j]==-1 && G[start][j]!=0){
                    Value[j] = G[start][j];
                    Pre[j] = start;
                }
            }
        
        else {
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (i==j || G[i][j]==0 || PreValue[i]==-1) continue;
                    if ((PreValue[i] + G[i][j] < Value[j]) || Value[j]==-1){
                        Value[j] = PreValue[i] + G[i][j];
                        Pre[j] = i;
                    }
                }
            }
        }
    }
    
    int countStep=0;
    int previous=end;
    int path[20]={-1};
        while(previous!=start){;
        previous=Pre[end];
        if (Value[previous]<Value[end] && G[previous][end]>0){
            path[countStep]=previous;
            end=previous;
            countStep++;
        }
    }
    
    char step=0;
    for (int i=countStep-1; i>=0; i--){
        step=path[i]+65;
        result+=step;
        result+=" ";
    }
    result+=last;
    
    return result;
}
