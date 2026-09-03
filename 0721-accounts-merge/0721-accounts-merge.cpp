class DisjointSet {
    vector<int> rank, parent,size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1,1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already in same component
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already in same component
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,int>mp;
        int n = accounts.size();
        vector<vector<string>>ans(n);
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string str = accounts[i][j];
                if(mp.count(str)){
                    ds.unionBySize(i,mp[str]);
                }else{
                    mp[str] = i;
                }
            }
        }

        for(auto [str,index]:mp){
            int ulp_index = ds.findUPar(index);
            ans[ulp_index].push_back(str);
        }

        vector<vector<string>>finalAns;
        for(int i=0;i<n;i++){
            if(ans[i].size()!=0){
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                sort(ans[i].begin(),ans[i].end());
                for(auto str : ans[i]){
                    temp.push_back(str);
                }
                finalAns.push_back(temp);
            }
        }
        return finalAns;
    }
};