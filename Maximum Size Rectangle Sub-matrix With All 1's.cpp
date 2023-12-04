/*
    Time Complexity: O(N*M)
    Space Complexity: O(M)

    Where N is the number of rows in matrix and M is the number of columns in the matrix.
*/

#include<stack>

int largestRectangleAreaInHistogram(vector < int > & height) {
    stack < int > stack;
    int globalMax = 0;
    int i = 0;
    for (; i < height.size(); i++) {

        while (!stack.empty() && height[i] < height[stack.top()]) {
            int top = stack.top();
            stack.pop();
            int area = 0;
            if (stack.empty()) {
                area = height[top] * i;
            } else {
                area = height[top] * (i - stack.top() - 1);
            }

            if (area > globalMax) {
                globalMax = area;
            }
        }
        stack.push(i);
    }
    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        int area = 0;
        if (stack.empty()) {
            area = height[top] * i;

        } else {
            area = height[top] * (i - stack.top() - 1);
        }
        if (area > globalMax) {
            globalMax = area;
        }
    }
    return globalMax;
}

int maximalAreaOfSubMatrixOfAll1(vector < vector < int >> & mat, int n, int m) {

    if (mat.size() == 0) {
        return 0;
    }

    int maxArea = 0;

    // Stores histogram height in a given row.
    vector < int > height(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j] = height[j] + 1;
            }
        }

        maxArea = max(maxArea, largestRectangleAreaInHistogram(height));
    }

    return maxArea;
}
