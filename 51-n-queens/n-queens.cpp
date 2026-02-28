class Solution {
public:
    int n;
    vector<string>board;
    vector<vector<string>>ret;
    int is_safe(int row, int col){
        for(int c=0;c<n;c++){
            if(board[row][c]=='Q')return 0;
        }
        for(int r=0;r<n;r++){
            if(board[r][col]=='Q')return 0;
        }

        int r= row, c= col;
        while(r >=0 && c <n){
            if(board[r][c]=='Q')return 0;
            r--, c++;
        }
        r= row, c= col;
        while(r >=0 && c >=0){
            if(board[r][c]=='Q')return 0;
            r--, c--;
        }

        r= row, c= col;
        while(r <n && c >=0){
            if(board[r][c]=='Q')return 0;
            r++, c--;
        }
         r= row, c= col;
        while(r <n && c <n){
            if(board[r][c]=='Q')return 0;
            r++, c++;
        }

        return 1;
        
    }
    void fun(int row){
        if(row == n){
            ret.push_back(board);
            return ;
        }
        for(int col=0;col<n;col++){
            //// put Q at (row, col);
            if (is_safe(row, col)){
                board[row][col]='Q'; /// do
                fun(row+1);
                board[row][col]='.'; /// do
            }
        }
    }
    vector<vector<string>> solveNQueens(int n2) {
        n = n2;
        board.assign(n, string(n, '.'));
        fun(0);
        return ret;
    }
};