class Solution {
public:
    int numbers[9] = {1,2,3,4,5,6,7,8,9} ; 
    vector<vector<int>> ans ; 
    vector<int> v ; 
    void work(int k , int n , int i = 0 ){
        if (n == 0 && k == 0){
            ans.push_back(v) ; 
            return ; 
        }
        if (i == 9 || numbers[i]>n || k<0)
            return ; 
        v.push_back(numbers[i]) ; 
        work(k-1,n-numbers[i],i+1) ; 
        v.pop_back() ; 
        work(k,n,i+1) ; 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        work(k,n) ; 
        return ans ; 
    }
};