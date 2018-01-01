// https://leetcode.com/problems/redundant-connection/description/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent;
        parent.reserve(2001);
        for(int i = 0; i < 2001; ++i)
            parent.push_back(i);
        
        for(auto& edge : edges){
            int f = edge[0];
            int t = edge[1];
            if (find(parent, f) == find(parent, t))
                return edge;
            else
                parent[find(parent, f)] = find(parent, t);
        }
        return vector<int>(2, 0);
    }
    
private:
    int find(vector<int>& parent, int x){
        if(parent[x] == x)
            return x;
        else
            return find(parent, parent[x]);
    }
};