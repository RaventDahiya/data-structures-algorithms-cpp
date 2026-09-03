class DisjointSet{
    vector<int>rank,size,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++) parent[i] = i;
        }

        int findUpar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUpar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();
        int requiredEdges = n - 1;
        if(requiredEdges > totalEdges) return -1;

        

        DisjointSet ds(n);
        //build ds
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
        }
        
        //count no of disconnected comp
        int noOfComp = 0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i){
                noOfComp++;
            }
        }

        return noOfComp - 1;
    }
};