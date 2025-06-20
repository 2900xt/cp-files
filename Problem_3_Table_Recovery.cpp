#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N; 
    cin >> N;
    vector<vector<int>> F(N, vector<int>(N));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> F[i][j];
        }
    }
 
    // --- Step 1. Count frequencies in F.
    // Since originally entries come from sums 2..2N, and after a type‑3 swap the set is the same.
    int maxSum = 2 * N;
    vector<int> freq(maxSum+1, 0);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            freq[F[i][j]]++;
        }
    }
 
    // --- Step 2. Group the expected sums (from an addition table) by their frequency.
    // For an addition table with rows and columns 1..N, the sum s appears:
    //   f(s) = s-1   if s <= N+1
    //   f(s) = 2N-s+1 if s >= N+1.
    vector<vector<int>> sumsByFreq(N+1); // index f: list of sums with that frequency.
    for (int s = 2; s <= maxSum; s++){
        int expFreq = (s <= N+1 ? s - 1 : 2*N - s + 1);
        sumsByFreq[expFreq].push_back(s);
    }
 
    // --- Step 3. Group the numbers that appear in F by their actual frequency.
    // (They are the images of the sums under the type‑3 bijection phi.)
    vector<vector<int>> numsByFreq(N+1);
    for (int a = 2; a <= maxSum; a++){
        if(freq[a] > 0)
            numsByFreq[freq[a]].push_back(a);
    }
 
    // --- Step 4. For each frequency group, sort both groups and assign:
    // For every frequency f and index k in that group, let phi( sumsByFreq[f][k] ) = numsByFreq[f][k].
    // (This assignment is forced by the equality–pattern.)
    vector<int> phi(maxSum+1, 0);
    for (int f = 1; f <= N; f++){
        if(sumsByFreq[f].empty() && numsByFreq[f].empty()) continue;
        sort(sumsByFreq[f].begin(), sumsByFreq[f].end());
        sort(numsByFreq[f].begin(), numsByFreq[f].end());
        for (size_t i = 0; i < sumsByFreq[f].size(); i++){
            int s = sumsByFreq[f][i];
            int a = numsByFreq[f][i];
            phi[s] = a;
        }
    }
 
    // --- Step 5. Build the inverse mapping of phi.
    // Let inv[x] be the unique sum s such that phi(s)=x.
    vector<int> inv(maxSum+1, 0);
    for (int s = 2; s <= maxSum; s++){
        int a = phi[s];
        inv[a] = s;
    }
 
    // --- Step 6. Reconstruct the “s–matrix”: for each cell, s[i][j] = phi⁻¹( F[i][j] ).
    vector<vector<int>> sMat(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            sMat[i][j] = inv[F[i][j]];
        }
    }
 
    // --- Step 7. In an addition table r+c, the sum 2 (which is 1+1) appears exactly once.
    // Find the unique cell (pivot) in sMat that equals 2.
    int pivotR = -1, pivotC = -1;
    for (int i = 0; i < N && pivotR == -1; i++){
        for (int j = 0; j < N; j++){
            if(sMat[i][j] == 2){
                pivotR = i; pivotC = j;
                break;
            }
        }
    }
    // (The problem guarantees a valid answer, so such a cell exists.)
 
    // --- Step 8. Define row and column “labels” using the pivot.
    // Since the unique 2 must come from 1+1, we force the row containing it to have label 1 and
    // the column containing it to have label 1.
    // Then for any row i, we set: r[i] = sMat[i][pivotC] - 1.
    // Similarly, for any column j, c[j] = sMat[pivotR][j] - 1.
    vector<int> rVal(N), cVal(N);
    for (int i = 0; i < N; i++){
        rVal[i] = sMat[i][pivotC] - 1;
    }
    for (int j = 0; j < N; j++){
        cVal[j] = sMat[pivotR][j] - 1;
    }
    // One may check that {rVal} and {cVal} are permutations of {1,...,N}.
 
    // --- Step 9. Now the recovered table (before any type–3 swap) is given by:
    // Y[i][j] = r[i] + c[j].
    vector<vector<int>> Y(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            Y[i][j] = rVal[i] + cVal[j];
        }
    }
 
    // --- Step 10. Output Y.
    // (It is guaranteed that Y is a valid addition table (after some row/column swaps)
    // and that among all possibilities it is lexicographically smallest.)
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << Y[i][j] << (j==N-1 ? "\n" : " ");
        }
    }
    return 0;
}
