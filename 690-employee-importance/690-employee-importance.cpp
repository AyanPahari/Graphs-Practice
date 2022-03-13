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
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        queue<Employee*>q;
        
        for(auto it:employees){
            mp[it->id] = it;
        }
        q.push(mp[id]);
        int ans = 0;
        
        while(!q.empty()){
            Employee* x = q.front();
            q.pop();
            ans += x->importance;
            
            for(auto sub: x->subordinates){
                q.push(mp[sub]);
            }
        }
        return ans;
    }
};