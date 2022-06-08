/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
void dfs(vector<Employee*> &employees, int id ,vector<bool> &visited , int &s ){
     visited[id] = true ;
        // cout << employees[id]->importance << endl ; 
         s+=employees[id]->importance ;
    for (int i = 0 ; i<(int)employees[id]->subordinates.size() ;i++){
        if (!visited[employees[id]->subordinates[i]]){
            dfs(employees,employees[id]->subordinates[i],visited,s) ;
        }
    }

}

int getImportance(vector<Employee*> employees, int id) {
    int n = (int)employees.size() ;
    map<int,int> mp ;
    int cnt = 0 ; 
    for (int i = 0 ; i<n ; i++){
        mp[employees[i]->id] = i ; 
    }
    for (int i = 0 ; i<n ; i++){
        employees[i]->id = i ; 
        for (int j = 0 ; j<employees[i]->subordinates.size() ; j++)
            employees[i]->subordinates[j] = mp[employees[i]->subordinates[j]] ;
    }
    id = mp[id] ; 
    vector<bool> visited(n,false) ;
    int s = 0 ;
    dfs(employees,id,visited,s);
    return s;
}

};