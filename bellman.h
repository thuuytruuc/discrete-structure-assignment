#ifndef bellman_h
#define bellman_h

#include "main.h"

void BF(int G[][20], int n, char vertex,int BFValue[20],int BFPrev[20]);

string BF_Path(int G[][20], int n, char first, char last);

#endif /* bellman_h */
