#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

long long operationCount = 0;
int maxDepth = 0;

void complexRec(int n, int depth = 0) {
   if (depth > maxDepth) {
       maxDepth = depth;
   }

   if (n <= 2) {
       operationCount++;
       return;
   }

   operationCount++;

   int p = n;
   while (p > 0) {
       operationCount += n;
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           operationCount++;
       }
       p >>= 1;
       operationCount++;
   }

   operationCount += n;
   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       operationCount++;
   }

   operationCount++;
   if (n % 3 == 0) {
       operationCount += n;
       reverse(small.begin(), small.end());
   } else {
       operationCount += n;
       reverse(small.begin(), small.end());
   }

   complexRec(n / 2, depth + 1);
   complexRec(n / 2, depth + 1);
   complexRec(n / 2, depth + 1);
}

int main(){
    vector<int> sizes = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
    
    for (int n : sizes) {
        operationCount = 0;
        maxDepth = 0;
        
        auto start = chrono::high_resolution_clock::now();
        complexRec(n);
        auto end = chrono::high_resolution_clock::now();
        
        double timeMs = chrono::duration<double, milli>(end - start).count();
        
        cout <<"For size "<< n <<", the Operation Count is " << operationCount << ", Max Depth is " << maxDepth << ", Time is " << timeMs << " ms" << endl;
    }
    
    return 0;
}

//The Recurence Relation is T(n) = 3T(n/2) + nlog(n), the Case for Master Theorem is Case 1 a>b^k
// The Time Complxity is O(n^(log(n)))