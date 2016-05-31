/*************************************************
* Amazon Interview Question:                     *
* Problem: Maximum Sum Sub Matrix                *
* Visit: http://programming-puzzles.blogspot.in/ *
* https://gist.github.com/ramprasadgopal/5364342 *
* Author : Ramprasad Gopalakrishnan              *
* Language : C++                                 *
**************************************************/

#include<iostream>
#include<list>
#include <algorithm>

using namespace std;

void getNextInputSet();
void printMatrix(int* matrix, int m1, int m2, int n1, int n2);
int maximumSumSubArray(int array[], int size, int* maxStartRetVal, int* maxTailRetVal);

/*
** input Matrix
**/
int inputMatrix[10][10] = { 
                      {2,-1,2,-1,4,-5},
                      {2,8,2,-1,4,-5},
                      {2,-1,2,-1,4,-5},
                      {2,-1,2,-1,4,-5},
                      {2,-1,2,-1,4,-5},
                      {-2,-1,-2,-1,4,-5}
                     };
int m = 6, n = 6;

/*
**sumMatrix:
** sumMatrix[i][j] gives the sum of column j till the ith row.
*/
int sumMatrix[10][10] = {{0}};

int main() {
    while(n > 0 && m >0) {

         for(int i = 1; i<=m;i++) {
             for(int j=0; j<n; j++)  {
                 sumMatrix[i][j] = sumMatrix[i-1][j] + inputMatrix[i-1][j];
             }
         }

         cout<<"SumMatrix:\n";
         printMatrix(*sumMatrix,0,m,0,n-1);

         int maxSum = sumMatrix[0][0], maxRowStart = 0, maxRowTail = 0, maxColStart =0, maxColTail = 0;
         cout<<"\n\nRij Matrix:\n";
         for(int i=0; i<n; i++) {
             for(int j=i; j<n; j++) {
                 /*r_ij matrix. 
                  * k th element in the matrix is the sum of all elements in 
                  * column k from row i to j in inputMatrix.
                  */
                 int r_ij[10] = {0};
                         
                 cout<<"R"<<i<<","<<j<<": ";
                 for(int k=0; k<m; k++) {
                     r_ij[k] = sumMatrix[j+1][k] - sumMatrix[i][k];
                     cout<<r_ij[k]<<" ";
                 }
                 cout<<endl;
                         
                 int maxStartForRij, maxTailForRij, maxSumRij;
                         
                 maxSumRij = maximumSumSubArray(r_ij, m, &maxStartForRij, &maxTailForRij);
                 
                 //update with tne new maxSum    
                 if(maxSumRij>maxSum) {
                     maxSum = maxSumRij;
                     maxRowStart = i;
                     maxRowTail = j;
                     maxColStart = maxStartForRij;
                     maxColTail = maxTailForRij;
                 }
             }
         }

         cout<<"\n\nAnswer:\n"<<"maxSum:"<<maxSum<<endl;
         printMatrix(*inputMatrix,maxRowStart,maxRowTail,maxColStart,maxColTail);

         getNextInputSet();
    }
}

/**
* This solves the sub problem of maximumSumSubArray.
* i.e. returns the sub array with the maximum sum.
* 
* refer: Kadane's algorithm.
*/
int maximumSumSubArray(int array[], int size, int* maxStartRetVal, int* maxTailRetVal) {
    int currentStart = 0, maxStart = 0, maxTail =0, currentSum = array[0], maxSum = array[0] ;
                         
    for(int currentTail = 1;currentTail < size; currentTail++) {
        if(currentSum > 0) {
            currentSum += array[currentTail];
        } else {
            currentStart = currentTail;
            currentSum = array[currentTail];
        }
        
        if(currentSum > maxSum) {
            maxSum = currentSum;
            maxTail = currentTail;
            maxStart = currentStart; 
        }
    }
    
    *maxStartRetVal = maxStart;
    *maxTailRetVal = maxTail;
    return maxSum;
}


/*
* Utility functions.
*/
void getNextInputSet() {
    //get next set of inputs
    cout<<"\n\nEnter M N (0 0 to quit):";
    cin>>m>>n;
    if(m>0 && n>0) {
        for(int i = 0; i<m;i++) {
            cout<<"Enter row " << i <<endl;
            for(int j=0; j<n; j++)
            cin>>inputMatrix[i][j];
        }
    }
}

void printMatrix(int* matrix, int m1, int m2, int n1, int n2) {
     for(int i = 0; i<=m;i++) {
         for(int j=0; j<n; j++)  {
             cout<<sumMatrix[i][j]<<" ";
         }
         cout<<endl;
     }
}
