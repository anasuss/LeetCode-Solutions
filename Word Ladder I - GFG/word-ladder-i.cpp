//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private: 
    vector<vector<int>> graph ; 
    vector<bool> visited ; 
    int n ; 
    int length ; 
    bool found ; 
public:
    int bfs(string targetWord, vector<string>& wordList,int node){
        queue<int> q ; 
        q.push(node) ; 
        visited[node] = true ; 
        if (wordList[node] == targetWord){
            found = true; 
            return 1 ; 
        }
        for (int level = 1 , sz = 1 ; !q.empty() ; level++ , sz = q.size()){
            while(sz--){
                int x = q.front() ; 
                q.pop() ; 
                for (int child : graph[x])
                    if (!visited[child]){
                        if (wordList[child] == targetWord){
                            found = true ; 
                            return level+1 ; 
                        }
                        visited[child] = true; 
                        q.push(child) ; 
                    }
            }
        }
    }
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        n = wordList.size() ;
        graph.resize(n) ; 
        visited.resize(n,false) ; 
        int check = 0 ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                if (i == j || wordList[j] == startWord)
                    continue ;
                int cnt = 0 ; 
                for (int k = 0 ; k<wordList[i].size() ; k++){
                    cnt += (wordList[i][k] != wordList[j][k]) ; 
                }
                if (cnt == 1){
                    graph[i].push_back(j) ; 
                }
            }
        }
        int ans = 1e8 ; 
        for (int i = 0 ; i<n ; i++){
            int cnt = 0 ; 
            for (int j = 0 ; j<wordList[i].size() ; j++){
                cnt += (wordList[i][j] != startWord[j]) ; 
            }
            if (cnt == 1){
                for (int i = 0 ; i<n ; i++)
                    visited[i] = false ; 
                found = 0 ; 
                length = bfs(targetWord,wordList,i)+1 ; 
                if (found){
                    ans = min(ans,length) ; 
                }
            }
        }
        return (ans == 1e8 ? 0 : ans) ; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends