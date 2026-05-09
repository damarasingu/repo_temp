class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid,int k) {
        int m=grid.size(),n=grid[0].size();
        int layers=min(m,n)/2;

        for(int layer=0;layer<layers;layer++) {
            vector<int> v;

            int top=layer,left=layer;
            int bottom=m-layer-1,right=n-layer-1;

            for(int j=left;j<=right;j++) v.push_back(grid[top][j]);
            for(int i=top+1;i<bottom;i++) v.push_back(grid[i][right]);
            for(int j=right;j>=left;j--) v.push_back(grid[bottom][j]);
            for(int i=bottom-1;i>top;i--) v.push_back(grid[i][left]);

            int sz=v.size();
            int shift=k%sz;

            vector<int> r(sz);

            for(int i=0;i<sz;i++)
                r[i]=v[(i+shift)%sz];

            int a=0;

            for(int j=left;j<=right;j++) grid[top][j]=r[a++];
            for(int i=top+1;i<bottom;i++) grid[i][right]=r[a++];
            for(int j=right;j>=left;j--) grid[bottom][j]=r[a++];
            for(int i=bottom-1;i>top;i--) grid[i][left]=r[a++];

        }

        return grid;
    }
};