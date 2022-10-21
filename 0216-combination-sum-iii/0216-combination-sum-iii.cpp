class Solution {
public:
    int numbers[9] = {1,2,3,4,5,6,7,8,9} ; 
    vector<vector<int>> ans ; 
    vector<int> v ; 
    void work(int k , int n , int i = 0 , int used = 0){
        if (n == 0 && used == k){
            ans.push_back(v) ; 
            return ; 
        }
        if (i == 9 || numbers[i]>n || used>k)
            return ; 
        v.push_back(numbers[i]) ; 
        work(k,n-numbers[i],i+1,used+1) ; 
        v.pop_back() ; 
        work(k,n,i+1,used) ; 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        work(k,n) ; 
        return ans ; 
    }
};