
class Solution {
public:
    bool dfs(vector<vector<char>>& bd,string& wd,vector<vector<bool>>& vis,int i,int j,int k) {
        int m=bd.size();
        int n=bd[0].size();

        if(k==wd.size()){
            return true;
            }

       
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || bd[i][j]!=wd[k]){
            return false;
        }
        vis[i][j]=true;

        bool sol=dfs(bd,wd,vis,i+1,j,k+1)|| dfs(bd,wd,vis,i-1,j,k+1)||
                 dfs(bd,wd,vis,i,j+1,k+1)|| dfs(bd,wd,vis,i,j-1,k+1);

        vis[i][j]=false;
        return sol;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (dfs(board,word,vis,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
