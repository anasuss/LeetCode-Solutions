class Solution {
public:

int target , n ; 

vector<vector<int>> ans ; 

vector<int> t , a ; 

unordered_set<string> ss ;

void findTarget(int i = 0 , int s = 0){
 
    if (i == n)
        return ;
      if (s == target){
        int k = 0 ;
        string b = "" ;
        for (int j = 0 ; j<a.size() ; j++){
            k+=a[j] ;
            b+=to_string(a[j]) ;
        }

        if (k == target && ss.count(b) == 0)
            ans.push_back(a) ;
        ss.insert(b) ;
        return  ;
    }
    if (s+t[i]<=target){
        a.push_back(t[i]) ;
         findTarget(i+1,s+t[i]) ;
        findTarget(i,s+t[i]) ;
        a.pop_back() ;
    }
    findTarget(i+1,s) ;
    return ;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int a) {
        target = a ; 
        t = candidates ; 
        n = t.size() ; 
        findTarget() ; 
        return ans ; 
    }
};