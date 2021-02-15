class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        
        int numberOfOranges = 0;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == FRESH){
                    numberOfOranges++;
                }else if(grid[i][j] == ROTTEN){
                    numberOfOranges++;
                    q.push({i,j});
                }
            }
        }

        
        int rotten = q.size();
        int count = 0;
        
        if(numberOfOranges == 0 || numberOfOranges == rotten) return 0;
        
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            
            count++;
            int length = q.size();
            for(int k=0; k<length; k++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int newR = r + dir[i][0];
                    int newC = c + dir[i][1];
                    if(newR>=0 && newR<row && newC>=0 && newC<col){
                        if(grid[newR][newC] != FRESH) continue;
                        else{
                            grid[newR][newC] = ROTTEN;
                            rotten++;
                            q.push({newR, newC});
                        }
                    }
                }
            }
            if(rotten == numberOfOranges) return count;
        }
        return -1;
    }
    
private:
    const int EMPTY = 0, FRESH = 1, ROTTEN = 2;
};
