class Solution {
public:
    int n,m;

    bool dfs(vector<vector<char>>& board,string& word,int i,int j,int idx){
        if(idx==word.size()-1) return true;

        char temp=board[i][j];
        board[i][j]='#';

        if(i+1<n && board[i+1][j]==word[idx+1]){
            if(dfs(board,word,i+1,j,idx+1)){
                board[i][j]=temp;
                return true;
            }
        }

        if(i-1>=0 && board[i-1][j]==word[idx+1]){
            if(dfs(board,word,i-1,j,idx+1)){
                board[i][j]=temp;
                return true;
            }
        }

        if(j+1<m && board[i][j+1]==word[idx+1]){
            if(dfs(board,word,i,j+1,idx+1)){
                board[i][j]=temp;
                return true;
            }
        }

        if(j-1>=0 && board[i][j-1]==word[idx+1]){
            if(dfs(board,word,i,j-1,idx+1)){
                board[i][j]=temp;
                return true;
            }
        }

        board[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board,string word){
        n=board.size();
        m=board[0].size();

        vector<int> freq(128,0);

        for(auto& row:board){
            for(char ch:row){
                freq[ch]++;
            }
        }

        for(char ch:word){
            freq[ch]--;
            if(freq[ch]<0) return false;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
};