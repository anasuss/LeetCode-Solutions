class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> v ; 
        int i = 0 ; 
        while(i<a.size() && a[i][1]<b[0]){
            v.push_back(a[i]) ; 
            ++i ; 
        }
        while(i<a.size() && a[i][0]<=b[1]){
            b[0] = min(a[i][0],b[0]) ; 
            b[1] = max(a[i][1],b[1]) ; 
            i++ ; 
        }
        v.push_back(b) ; 
        while(i<a.size()){
            v.push_back(a[i]) ; 
            ++i ; 
        }
        return v ; 
    }
};