/* In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
 * Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
 *
 * https://leetcode.com/problems/shortest-bridge/
 */

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int shortestBridge(vector<vector<int>>& A) {
        int minBridge=0;
        int rows = A.size();
        int cols = A[0].size();

        vector<vector<int>> B = A;
        int flag=1;

        for (int i=0; i<rows && flag; i++){
            for (int j=0; j<cols && flag; j++){

                if (A[i][j] == 1){
                    flag = 0;
                    int que[rows*cols][2];
                    int rr=0, frt=0;
                    que[rr][0] = i;
                    que[rr++][1] = j;

                    int visited[rows][cols];
                    memset (visited, 0, (rows*cols*sizeof(int)));
                    visited[i][j] = 1;
                    B[i][j] = 2;

                    while (rr!=frt){
                        int currX = que[frt][0]; 
                        int currY = que[frt++][1];
                        
                        for (int k=0; k<4; k++){
                            int nearX = currX + dir[k][0];
                            int nearY = currY + dir[k][1];
                            
                            if (nearX<0 || nearX>=rows || nearY<0 || nearY>=cols)
                                continue;
                            if (A[nearX][nearY] == 1 && visited[nearX][nearY]==0){
                                que[rr][0] = nearX;
                                que[rr++][1] = nearY;
                                visited[nearX][nearY] = 1;
                                B[nearX][nearY] = 2;
                            }
                        }
                    }
                }
            }
        }
        int island2[rows*cols][2];
        int rr=0,frt=0;

        int visited[rows][cols];
        memset (visited, 0, (rows*cols*sizeof(int)));

        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
//                cout<<B[i][j]<<" ";
                if (B[i][j] ==1){
                    island2[rr][0] = i;
                    island2[rr++][1] = j;
                    visited[i][j] = 1;
                }
            }
//            cout<<"\n";
        }

        while (rr!=frt){
            int samebreadth = rr-frt;
            
            while(samebreadth--){
                int currX = island2[frt][0];
                int currY = island2[frt++][1];
                
                for (int k=0; k<4; k++){
                    int nearX = currX + dir[k][0];
                    int nearY = currY + dir[k][1];
                    
                    if (nearX<0 || nearX>=rows || nearY<0 || nearY>=cols)
                        continue;
                    if (B[nearX][nearY] == 2)
                        return minBridge;
                    if (B[nearX][nearY] == 0 && visited[nearX][nearY] == 0){
                        B[nearX][nearY] = 1;
                        visited[nearX][nearY] = 1;
                        island2[rr][0] = nearX;
                        island2[rr++][1] = nearY;
                    }
                }
            }
            minBridge++;            
        }
            
        return minBridge;
    }
