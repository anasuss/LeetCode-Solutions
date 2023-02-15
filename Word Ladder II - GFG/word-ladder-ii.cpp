//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

public:

   vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans ; 
        queue<vector<string>> q ; 
        vector<string> used ; 
        set<string> st(wordList.begin(),wordList.end());
        int level = 0 ; 
        q.push({beginWord}) ; 
        used.push_back(beginWord) ; 
        while(!q.empty()){
            vector<string> v = q.front() ; 
            q.pop() ;
            string word = v.back() ;
            if (v.size()>level){
                ++level ; 
                for(string s : used)
                    st.erase(s) ;
            }
            if (word == endWord){
                if (ans.size() == 0)
                    ans.push_back(v) ; 
                else if (v.size() == ans[0].size())
                    ans.push_back(v) ;
            }
            for (int i = 0 ; i<word.size() ; i++){
                char original = word[i] ; 
                for (char c = 'a' ; c<='z' ; c++){
                    if (c == original)
                        continue ; 
                    word[i] = c ; 
                    if (st.count(word)){
                        v.push_back(word) ;
                        used.push_back(word) ; 
                        q.push(v) ; 
                        v.pop_back() ; 
                    }
                }
                word[i] = original ; 
            } 
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends