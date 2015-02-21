const int START = 51;
struct FoxBomb
{
    vector< vector<int> > G;
    int dp[2501][52][2][2];
    
    //========================================================
    // Minimum number of edges to take from x's subtree
    // If stepId == START : We have not decided yet whether x
    //                      will become active in the future.
    //
    // If stepId = 0 to degree(x)-1:
    //    We have already decided about the edges and subtrees
    // in the first stepId children of x.
    //
    // xA = 1 if x is already active. mustEdge = 1 if we need
    // to pick at least one edge that touches x.
    //
    // The parent argument is not part of the recurrence, we
    // just use it to ignore the vertex we determined to
    // be the parent.
    //
    int F(int x, int parent, int stepId, int xA, int mustEdge)
    {    
        int & res = dp[x][stepId][xA][mustEdge];
        if (res == -1) {
            res = 1000000;
            if (stepId == G[x].size() ) {
                res = ( (!mustEdge)? 0 : 1000000 );
            } else if (stepId == START) {
                //do we want x to be active?
                res = F(x, parent, 0, xA,mustEdge);
                if (! xA) {
                    res = min(res, F(x, parent, 0, 1,1) );
                }
            } else {
                int y = G[x][stepId];
                if (y == parent) { //ignore the parent
                    res = F(x, parent, stepId+1, xA, mustEdge);
                } else {
                    int next, child;
                    // Do not take the edge between (x and y):
                    if (xA) {
                        next = F(x, parent, stepId+1, xA, mustEdge);
                        child = F(y, x, START, 0, 0);                        
                    } else {
                        //child must be active
                        next = F(x, parent, stepId+1, 0, mustEdge);
                        child = F(y, x, START, 1, 1);
                    }
                    res = std::min(res, next + child );
                    
                    // Take the edge between (x and y):
                    if (xA) {
                        next = F(x, parent, stepId+1, 1, 0);
                        child = F(y, x, START, 1, 0);
                        res = std::min(res, 1 + next + child );
                    }
                    
                }
            }
        }
        return res;
    }
    
    int getMinimumCost(vector <string> grid)
    {
        int w = grid.size(), h = grid[0].size();
        int rowId[w][h];
        int columnId[w][h];
        int maximalR = 0, maximalC = 0;
        
        //========================================================
        // Extract maximal vertical and horizontal groups of cells
        //
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                if (grid[i][j]=='.') {
                     if ((j==0) || (grid[i][j-1] != '.') ) {
                         rowId[i][j] = maximalR++;
                     } else {
                         rowId[i][j] = rowId[i][j-1];
                     }
                }
            }
        }
        for (int j=0; j<h; j++) {
            for (int i=0; i<w; i++) {        
                if (grid[i][j]=='.') {
                     if ((i==0) || (grid[i-1][j] != '.') ) {
                         columnId[i][j] = maximalC++;
                     } else {
                         columnId[i][j] = columnId[i-1][j];
                     }
                }
            }
        }
        //===========================================================
        // Make a graph: For each walkable cell, there is an edge connecting
        // its respective maximal column and row
        G.resize( maximalR + maximalC );
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                if (grid[i][j]=='.') {
                    int r = rowId[i][j], c = columnId[i][j];
                    G[r].push_back(c + maximalR);
                    G[c + maximalR].push_back(r);
                }
            }
        }
        memset(dp, -1, sizeof(dp));        
        return F(0,-1, START,  0,0);
    }
};
