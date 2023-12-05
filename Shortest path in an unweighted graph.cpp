/*
		Time Complexity : O(N + M)		
		Space Complexity : O( N + M ),

		where N is the number of nodes and M is number of edges.

*/

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t)
{	
	// We will store graph in an adjecency list.
	vector<int> ADJ[n+1];	
	
    // Making adjacency list ADJ from edges.
	for(int i = 0 ; i < m ; i++ )
    {
		int X , Y;
		X=edges[i].first;
		Y=edges[i].second;
		ADJ[X].push_back(Y);
		ADJ[Y].push_back(X);
	}

	/* 
    	Declaring visited array and parent array , visited will be used in dfs. 
	    And parent will be use to recreate the path.
	*/
    vector<int> visited(n+1,-1);
	vector<int> parent(n+1,-1);
	visited[s]=1;
	queue<int> Q;
	
	/* 
    	Starting BFS from node S.
		Q is the queue used in bfs.
	*/
    Q.push(s);
	
    while(Q.size()>0) 
    {
		// Selecting a node and traversing all its neighbours.
		int currentNode = Q.front();
		Q.pop();
		
        for(int nextNode : ADJ[currentNode] ) 
        {
			/* 
            	If the node is not already visited we will add it to the Q.
				And we will set the currentNode the parent of nextNode.
			*/
            if( visited[nextNode]==-1 ) 
            {
				visited[nextNode]=1;
				Q.push(nextNode);
				parent[nextNode]=currentNode;
			}
		}
	}

	// Now we will backtrack and recreate the path from S to T using visited array.
	vector<int> path;
	int currentNode =  t;
	
    // We will start from T and try to go back from here until we reaches S.
	path.push_back(t);
	
    while(currentNode != s) 
    {
		/* 
        	From current node we will find a neighbour who has distance equal to
			distance of current node - 1 , that node will be the parent of currentNode.
		*/
        currentNode = parent[currentNode];
		path.push_back(currentNode);	
	}

	// We got path in from T to S , so we will reverse it and return it.
	reverse(path.begin() , path.end());

	return path;
}

