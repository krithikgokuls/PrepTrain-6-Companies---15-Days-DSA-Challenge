/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(1)

    Where N is the number of intervals.
*/

#include <algorithm>

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        int curS = intervals[i][0];
        int curE = intervals[i][1];

	    // If current interval doesn't overlap with the previous interval.
        if (res.size() == 0 || curS > res[res.size() - 1][1]) 
        {

            res.push_back(intervals[i]);
        }
        // If current interval overlaps with the previous interval.
        else 
        {
            res[res.size() - 1][1] = max(res[res.size() - 1][1], curE);
        }
    }

    return res;
}
