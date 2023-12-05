#include <vector>
#include <algorithm>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
    long long maxEndingHere = 0, maxSoFar = 0;
    
    for (int i = 0; i < n; ++i) {
        maxEndingHere = max(0LL, maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
