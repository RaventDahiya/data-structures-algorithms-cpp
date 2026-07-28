class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, int> mp;
        wordList.insert(wordList.begin(), beginWord);
        int len = beginWord.length();
        int V = wordList.size();
        for (int i = 0; i < V; i++) {
            mp[wordList[i]] = i;
        }

        if (!mp[endWord])
            return 0;

        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string str = wordList[i];
            for (int j = 0; j < len; j++) {
                char original = str[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    str[j] = ch;
                    if (mp.count(str)) adj[i].push_back(mp[str]);
                }
                str[j] = original; // Restore original character
            }
        }

        int src = 0;
        int dest = mp[endWord];
        vector<int> dis(V, INT_MAX);
		dis[src] = 0;
		
		// BFS Queue
		queue<int> q;
		q.push(src);
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			for (auto nbr : adj[node]) {
				if (dis[nbr] == INT_MAX) {
					dis[nbr] = dis[node] + 1;
					q.push(nbr);
				}
			}
		}
		
		if (dis[dest] == INT_MAX)
			return 0;
		
		return dis[dest] + 1;
    }
};