class Solution {
public:
int dx[4] = {1,-1,0,0} ;

int dy[4] = {0,0,1,-1} ;


vector<vector<bool> > vis ;

bool isvalid(int x ,int y , int l , int c){
    return x>=0 && y>=0 && x<l && y<c  ;
}

void dfs(vector<vector<int>>& grid, int i, int j, int prev, int color,int l , int c){

        if (vis[i][j])
            return ;

        vis[i][j]=true;


        int count=0;    

        if(i-1>=0 && grid[i-1][j]==prev ){
            count++;
        }
        if(j-1>=0 && grid[i][j-1]== prev ){
            count++;
        }
        if(i+1<grid.size() && grid[i+1][j]==prev  ){
            count++;
        }
        if(j+1<grid[0].size() && grid[i][j+1]==prev ){
            count++;
        }

        for (int k = 0 ; k<4 ; k++){
            if (isvalid(i+dx[k],j+dy[k],l,c) && grid[i+dx[k]][j+dy[k]] == prev ){
                dfs(grid,i+dx[k],j+dy[k],prev,color,l,c) ;
            }
        }
         if(count!=4)
            grid[i][j]=color;
}
 vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color){
     int l = grid.size() ;
     int c = grid[0].size() ;
     vis.resize(l,vector<bool>(c,false)) ;
     int curr_color = grid[row][col] ;
     dfs(grid,row,col,curr_color,color,l,c) ;
     return grid ; 
}

};