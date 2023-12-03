/*  
    Time Complexity : O(K)
    Space Complexity : O(K)
    
    Where K = N * M and N and M are the rows and columns
    of the input matrix.
*/

#include <queue>
#include <climits>

class Cell
{
public:
    int cost;
    int i;
    int j;
    Cell(int cost, int i, int j) : cost(cost), i(i), j(j)
    {
    }
};

int isValid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int minCostToDestination(int **matrix, int n, int m, int x, int y)
{
    //  If the destination is a blocked cell.
    if (matrix[x][y] == 0)
        return -1;

    int **minCost, i, j, k, curCost, nextI, nextJ, newCost;

    minCost = new int *[n];
    for (i = 0; i < n; i++)
    {
        minCost[i] = new int[m];
    }

    //  Initializing Minimum Cost.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            minCost[i][j] = INT_MAX;
        }
    }

    /*
        We will store Cell(cost, i, j) in the deque where
        (i,j) is cell no.
        cost is cost of reaching (i,j) from (0,0).

        deque will always contain a minimum cost cell in the front.

        We will use 0-1 BFS Technique to maintain the deque.
    */
    deque<Cell> dq;

    dq.push_front(Cell(0, 0, 0));
    minCost[0][0] = 0;

    // Array for exploring all 4 directions.
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    vector<pair<int, int>> ans;

    while (!dq.empty())
    {

        Cell minCostCell = dq.front();
        dq.pop_front();

        i = minCostCell.i;
        j = minCostCell.j;
        curCost = minCostCell.cost;

        // We reached the destination.
        if (i == x && j == y)
        {
            break;
        }

        for (k = 0; k < 4; k++)
        {
            nextI = i + dx[k];
            nextJ = j + dy[k];

            if (isValid(nextI, nextJ, n, m) && matrix[nextI][nextJ] == 1)
            {

                if (k < 2)
                {
                    // For Right and Left.
                    newCost = curCost;

                    // If there is a improvement in minCost push in the front.
                    if (minCost[nextI][nextJ] > newCost)
                    {
                        minCost[nextI][nextJ] = newCost;
                        dq.push_front(Cell(newCost, nextI, nextJ));
                    }
                }
                else
                {
                    // For Up and Down.
                    newCost = curCost + 1;

                    // If there is a improvement in minCost push in the back.
                    if (minCost[nextI][nextJ] > newCost)
                    {
                        minCost[nextI][nextJ] = newCost;
                        dq.push_back(Cell(newCost, nextI, nextJ));
                    }
                }

                
            }
        }
    }

    // Final minCost of Destination.
    curCost = minCost[x][y];

    // Deleting Dynamic MinCost Array.
    for (i = 0; i < n; ++i)
    {
        delete[] minCost[i];
    }
    delete[] minCost;

    // If it is impossible to reach the Destination.
    if (curCost == INT_MAX)
        return -1;

    return curCost;
}
