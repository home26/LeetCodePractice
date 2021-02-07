class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]) continue;
                dfs(grid, i, j, m, n);
                ans = max(ans, area);
                area = 0;
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        area++;
        dfs(grid, i-1,j, m, n);
        dfs(grid, i+1,j, m, n);
        dfs(grid, i,j-1, m, n);
        dfs(grid, i,j+1, m, n);
        
    }
private:
    int area = 0;
};
