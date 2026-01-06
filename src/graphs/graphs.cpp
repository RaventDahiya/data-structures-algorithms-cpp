/*
 * ============================================================================
 *                         GRAPH DATA STRUCTURE & ALGORITHMS
 * ============================================================================
 * 
 * GRAPH BASICS:
 * - A graph G = (V, E) consists of vertices (nodes) V and edges E
 * - Types: Directed (one-way edges) vs Undirected (two-way edges)
 * - Weighted vs Unweighted edges
 * 
 * GRAPH REPRESENTATIONS:
 * 1. Adjacency Matrix: 2D array, O(1) edge lookup, O(V²) space
 * 2. Adjacency List: Array of lists, O(V+E) space, efficient for sparse graphs
 * 
 * This implementation uses Adjacency List with:
 *   unordered_map<int, list<pair<int, int>>> 
 *   where pair = (neighbor_node, edge_weight)
 * 
 * TIME COMPLEXITIES (V = vertices, E = edges):
 * - BFS/DFS: O(V + E)
 * - Dijkstra: O((V + E) log V) with priority queue
 * - Bellman-Ford: O(V * E)
 * - Floyd-Warshall: O(V³)
 * - Topological Sort: O(V + E)
 * - Kosaraju's SCC: O(V + E)
 * - Tarjan's Bridges: O(V + E)
 * ============================================================================
 */

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <set>
using namespace std;

class Graph
{
public:
    // Adjacency List: node -> list of (neighbor, weight) pairs
    unordered_map<int, list<pair<int, int>>> adjList;

    /*
     * ADD EDGE TO GRAPH
     * -----------------
     * @param u: source vertex
     * @param v: destination vertex  
     * @param weight: edge weight (default = 1)
     * @param direction: 0 = undirected, 1 = directed
     */
    void addEdge(int u, int v, int weight = 1, int direction = 0)
    {
        // direction = 0 -> undirected (add edge both ways)
        // direction = 1 -> directed (add edge one way only)
        adjList[u].push_back({v, weight});
        if (direction == 0)
        {
            adjList[v].push_back({u, weight});
        }
    }

    // Print the adjacency list representation of the graph
    void printAdjList(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> {";
            for (auto j : adjList[i])
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }

    /*
     * ========================================================================
     *                    BREADTH-FIRST SEARCH (BFS)
     * ========================================================================
     * 
     * CONCEPT:
     * - Explores all vertices at current depth before moving to next level
     * - Uses a QUEUE (FIFO) data structure
     * - Visits nodes level by level (like ripples in water)
     * 
     * ALGORITHM:
     * 1. Start from source, mark visited, add to queue
     * 2. While queue not empty:
     *    a. Dequeue front node, process it
     *    b. Enqueue all unvisited neighbors, mark them visited
     * 
     * APPLICATIONS:
     * - Shortest path in unweighted graph
     * - Level order traversal
     * - Finding connected components
     * - Detecting cycle in undirected graph
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    void bfs(int n)
    {
        unordered_map<int, bool> visited;
        // Handle disconnected components
        for (int src = 0; src < n; src++)
        {
            if (!visited[src])
            {
                bfsUtil(src, visited);
            }
        }
    }

    void bfsUtil(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;           // FIFO queue for BFS
        q.push(src);            // Start with source
        visited[src] = true;    // Mark as visited BEFORE entering queue

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";  // Process current node
            
            // Explore all neighbors
            for (auto neighbor : adjList[node])
            {
                if (!visited[neighbor.first])
                {
                    q.push(neighbor.first);
                    visited[neighbor.first] = true;  // Mark visited when enqueueing
                }
            }
        }
    }

    /*
     * ========================================================================
     *                    DEPTH-FIRST SEARCH (DFS)
     * ========================================================================
     * 
     * CONCEPT:
     * - Explores as far as possible along each branch before backtracking
     * - Uses STACK (explicit or recursion call stack)
     * - Goes deep into one path before exploring siblings
     * 
     * ALGORITHM:
     * 1. Start from source, mark visited
     * 2. For each unvisited neighbor, recursively call DFS
     * 3. Backtrack when no unvisited neighbors remain
     * 
     * APPLICATIONS:
     * - Detecting cycles
     * - Topological sorting
     * - Finding connected components
     * - Solving mazes/puzzles
     * - Finding strongly connected components
     * 
     * TIME: O(V + E)  |  SPACE: O(V) for recursion stack
     * ========================================================================
     */
    void dfs(int n)
    {
        unordered_map<int, bool> visited;
        // Handle disconnected components
        for (int src = 0; src <= n; src++)
        {
            if (!visited[src])
            {
                dfsUtil(src, visited);
            }
        }
    }

    void dfsUtil(int node, unordered_map<int, bool> &visited)
    {
        visited[node] = true;     // Mark current node as visited
        cout << node << " ";      // Process current node
        
        // Recursively visit all unvisited neighbors (go deep)
        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor.first])
            {
                dfsUtil(neighbor.first, visited);
            }
        }
        // Backtrack happens automatically when function returns
    }
    /*
     * ========================================================================
     *          CYCLE DETECTION IN UNDIRECTED GRAPH (BFS)
     * ========================================================================
     * 
     * CONCEPT:
     * - A cycle exists if we reach an already visited node that is NOT the parent
     * - In undirected graph, we track parent to avoid false positives
     *   (going back to parent is not a cycle)
     * 
     * KEY INSIGHT:
     * - If neighbor is visited AND neighbor != parent → CYCLE FOUND!
     * - We must exclude parent because in undirected graph,
     *   edge u-v appears in both u's and v's adjacency lists
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    bool cycle_Detection_Undirected_Graph_BFS_helper(int n)
    {
        unordered_map<int, bool> visited;
        // Check all components (graph may be disconnected)
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (cycle_Detection_Undirected_Graph_BFS(i, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool cycle_Detection_Undirected_Graph_BFS(int src, unordered_map<int, bool> &visited)
    {
        unordered_map<int, int> parent;  // Track parent of each node

        parent[src] = -1;      // Source has no parent
        visited[src] = true;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for (auto neighbor : adjList[front])
            {
                if (!visited[neighbor.first])
                {
                    q.push(neighbor.first);
                    visited[neighbor.first] = true;
                    parent[neighbor.first] = front;
                }
                // If visited AND not parent → CYCLE!
                else if (visited[neighbor.first] && neighbor.first != parent[front])
                    return true;
            }
        }
        return false;
    }

    /*
     * ========================================================================
     *          CYCLE DETECTION IN UNDIRECTED GRAPH (DFS)
     * ========================================================================
     * 
     * CONCEPT: Same as BFS approach but using DFS
     * - Track parent during recursion
     * - Cycle exists if we find visited neighbor that isn't parent
     * 
     * WHY PARENT CHECK?
     * - In undirected graph: edge A-B exists in both A's and B's list
     * - When at B (came from A), seeing A is NOT a cycle, it's the parent
     * - Seeing any OTHER visited node IS a cycle
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    bool cycle_Detection_undireted_graph_dfs_helper(int n)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (cycle_Detection_undirected_graph_dfs(i, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool cycle_Detection_undirected_graph_dfs(int node, unordered_map<int, bool> &visited, int parent)
    {
        visited[node] = true;
        
        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor.first])
            {
                // Recurse for unvisited neighbors
                if (cycle_Detection_undirected_graph_dfs(neighbor.first, visited, node))
                {
                    return true;
                }
            }
            // Visited AND not parent → CYCLE!
            else if (visited[neighbor.first] && neighbor.first != parent)
            {
                return true;
            }
        }
        return false;
    }

    /*
     * ========================================================================
     *          CYCLE DETECTION IN DIRECTED GRAPH (DFS)
     * ========================================================================
     * 
     * CONCEPT:
     * - In directed graphs, we can't use parent check (edges are one-way)
     * - Use "recursion stack" to track nodes in current DFS path
     * - Cycle exists if we encounter a node already in current path
     * 
     * TWO MAPS NEEDED:
     * 1. visited: All nodes ever visited (across all DFS calls)
     * 2. inStack: Nodes in CURRENT recursion path only
     * 
     * KEY INSIGHT:
     * - visited but NOT in stack → visited from different path (no cycle)
     * - visited AND in stack → back edge to ancestor (CYCLE!)
     * 
     * BACK EDGE:
     * - Edge from descendant to ancestor in DFS tree
     * - Presence of back edge = cycle in directed graph
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    bool direted_graph_cycle_detection_dfs_helper(int n)
    {
        unordered_map<int, bool> visited;   // Ever visited?
        unordered_map<int, bool> inStack;   // In current DFS path?
        
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (directed_graph_cycle_detection_dfs(i, visited, inStack))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool directed_graph_cycle_detection_dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &inStack)
    {
        visited[node] = true;    // Mark as visited
        inStack[node] = true;    // Add to current path
        
        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor.first])
            {
                if (directed_graph_cycle_detection_dfs(neighbor.first, visited, inStack))
                {
                    return true;
                }
            }
            // If in current recursion stack → CYCLE (back edge found)!
            else if (inStack[neighbor.first])
            {
                return true;
            }
        }
        
        inStack[node] = false;   // Remove from current path (backtrack)
        return false;
    }

    /*
     * ========================================================================
     *                    TOPOLOGICAL SORT (DFS Method)
     * ========================================================================
     * 
     * CONCEPT:
     * - Linear ordering of vertices such that for every directed edge u→v,
     *   u comes before v in the ordering
     * - Only possible for DAG (Directed Acyclic Graph)
     * 
     * ALGORITHM (DFS-based):
     * 1. Do DFS from each unvisited node
     * 2. After visiting ALL neighbors of a node, push it to stack
     * 3. Pop from stack to get topological order
     * 
     * WHY IT WORKS:
     * - Node is pushed AFTER all its dependencies (neighbors) are processed
     * - So when we pop, all dependencies appear after it (reverse = correct order)
     * 
     * APPLICATIONS:
     * - Task scheduling with dependencies
     * - Build systems (compile order)
     * - Course prerequisites
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    void topologicalSortDFS(int node, unordered_map<int, bool> &visited, stack<int> &topoStack)
    {
        visited[node] = true;
        
        // First, visit all neighbors (dependencies)
        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor.first])
            {
                topologicalSortDFS(neighbor.first, visited, topoStack);
            }
        }
        
        // Push to stack AFTER all neighbors are done
        topoStack.push(node);
    }

    vector<int> topologicalSort(int n)
    {
        unordered_map<int, bool> visited;
        stack<int> topoStack;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topologicalSortDFS(i, visited, topoStack);
            }
        }

        // Pop from stack to get topological order
        vector<int> result;
        while (!topoStack.empty())
        {
            result.push_back(topoStack.top());
            topoStack.pop();
        }
        return result;
    }

    /*
     * ========================================================================
     *                TOPOLOGICAL SORT - KAHN'S ALGORITHM (BFS)
     * ========================================================================
     * 
     * CONCEPT:
     * - Use in-degree (number of incoming edges) of vertices
     * - Process vertices with 0 in-degree first (no dependencies)
     * 
     * ALGORITHM:
     * 1. Calculate in-degree of all vertices
     * 2. Add all vertices with in-degree 0 to queue
     * 3. While queue not empty:
     *    a. Dequeue vertex, add to result
     *    b. Reduce in-degree of all neighbors by 1
     *    c. If any neighbor's in-degree becomes 0, enqueue it
     * 
     * CYCLE DETECTION:
     * - If result.size() != n, graph has a cycle!
     * - (Some nodes never reach in-degree 0)
     * 
     * ADVANTAGE OVER DFS:
     * - Can detect cycles directly
     * - More intuitive for some applications
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    vector<int> topologicalSortBFS(int n)
    {
        vector<int> indegree(n, 0);  // In-degree of each vertex

        // Step 1: Calculate in-degree of all nodes
        for (int i = 0; i < n; i++)
        {
            for (auto neighbor : adjList[i])
            {
                indegree[neighbor.first]++;  // neighbor has one more incoming edge
            }
        }

        // Step 2: Enqueue all vertices with in-degree 0
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);  // No dependencies, can process immediately
            }
        }

        vector<int> result;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            result.push_back(front);  // Add to topological order

            // Step 3: Reduce in-degree of neighbors
            for (auto neighbor : adjList[front])
            {
                indegree[neighbor.first]--;
                if (indegree[neighbor.first] == 0)
                {
                    q.push(neighbor.first);  // Now has no dependencies
                }
            }
        }
        // Note: if result.size() < n, graph has a cycle!
        return result;
    }

    /*
     * ========================================================================
     *          SHORTEST PATH IN DAG (Using Topological Sort)
     * ========================================================================
     * 
     * CONCEPT:
     * - For DAGs, we can find shortest path more efficiently than Dijkstra
     * - Process nodes in topological order and relax edges
     * 
     * WHY TOPOLOGICAL ORDER?
     * - When we process a node, all paths TO it have already been considered
     * - So its distance is finalized, and we can safely relax outgoing edges
     * 
     * ALGORITHM:
     * 1. Get topological order
     * 2. Initialize dist[src] = 0, all others = ∞
     * 3. For each node in topological order:
     *    - Relax all outgoing edges
     * 
     * ADVANTAGE:
     * - Works with NEGATIVE weights (unlike Dijkstra)
     * - TIME: O(V + E) — faster than Dijkstra!
     * 
     * LIMITATION: Only works for DAGs (no cycles)
     * ========================================================================
     */
    vector<int> shortestPathDAG(int src, int n)
    {
        // Step 1: Get topological order
        unordered_map<int, bool> visited;
        stack<int> topoStack;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topologicalSortDFS(i, visited, topoStack);
            }
        }

        // Step 2: Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Step 3: Process nodes in topological order and relax edges
        while (!topoStack.empty())
        {
            int node = topoStack.top();
            topoStack.pop();

            // Only process if node is reachable from source
            if (dist[node] != INT_MAX)
            {
                for (auto neighbor : adjList[node])
                {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    // Relaxation: if we found shorter path, update
                    if (dist[node] + weight < dist[v])
                    {
                        dist[v] = dist[node] + weight;
                    }
                }
            }
        }

        return dist;
    }

    /*
     * ========================================================================
     *                    DIJKSTRA'S ALGORITHM
     * ========================================================================
     * 
     * CONCEPT:
     * - Single Source Shortest Path for graphs with NON-NEGATIVE weights
     * - Greedy approach: always process the closest unvisited vertex
     * 
     * ALGORITHM:
     * 1. Initialize dist[src] = 0, all others = ∞
     * 2. Use min-heap/set to always pick vertex with minimum distance
     * 3. For picked vertex, relax all outgoing edges
     * 4. Repeat until all vertices processed
     * 
     * RELAXATION:
     * - If dist[u] + weight(u,v) < dist[v], update dist[v]
     * 
     * WHY NO NEGATIVE WEIGHTS?
     * - Once a node is processed, we assume its distance is final
     * - Negative weights can make a shorter path through already-processed nodes
     * 
     * TIME COMPLEXITY:
     * - With set/priority_queue: O((V + E) log V)
     * - With simple array: O(V²)
     * 
     * SPACE: O(V)
     * ========================================================================
     */
    vector<int> dijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Using set as min-heap: automatically sorted by first element (distance)
        set<pair<int, int>> st;
        st.insert({0, src}); // {distance, node}

        while (!st.empty())
        {
            // Get the node with smallest distance (greedy choice)
            auto front = *(st.begin());
            int node = front.second;
            int nodeDist = front.first;
            st.erase(st.begin());  // Remove from set (mark as processed)

            // Relax all outgoing edges
            for (auto neighbor : adjList[node])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relaxation step
                if (nodeDist + weight < dist[v])
                {
                    // Remove old entry if exists (update operation)
                    auto result = st.find({dist[v], v});
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    // Update distance and insert new entry
                    dist[v] = nodeDist + weight;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist;
    }

    /*
     * ========================================================================
     *                    BELLMAN-FORD ALGORITHM
     * ========================================================================
     * 
     * CONCEPT:
     * - Single Source Shortest Path that handles NEGATIVE WEIGHTS
     * - Can detect NEGATIVE WEIGHT CYCLES
     * 
     * ALGORITHM:
     * 1. Initialize dist[src] = 0, all others = ∞
     * 2. Repeat (V-1) times: relax ALL edges
     * 3. Do one more pass: if any edge can be relaxed → negative cycle!
     * 
     * WHY (V-1) ITERATIONS?
     * - Shortest path can have at most (V-1) edges
     * - Each iteration guarantees at least one more vertex gets correct distance
     * - After (V-1) iterations, all shortest paths are found
     * 
     * NEGATIVE CYCLE DETECTION:
     * - If we can still relax after (V-1) iterations,
     *   there's a negative cycle (distances keep decreasing infinitely)
     * 
     * COMPARISON WITH DIJKSTRA:
     * - Bellman-Ford: O(V*E), handles negative weights
     * - Dijkstra: O((V+E)logV), faster but no negative weights
     * 
     * TIME: O(V * E)  |  SPACE: O(V)
     * ========================================================================
     */
    vector<int> bellman_Ford(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Step 1: Relax all edges (V-1) times
        for (int i = 0; i < n - 1; i++)
        {
            for (auto edge : adjList)
            {
                int u = edge.first;
                for (auto neighbor : edge.second)
                {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    // Relaxation
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Step 2: Check for negative-weight cycles
        // If we can still relax, there's a negative cycle
        for (auto edge : adjList)
        {
            int u = edge.first;
            for (auto neighbor : edge.second)
            {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    cout << "Graph contains negative weight cycle" << endl;
                    return {};  // Return empty - no valid shortest paths
                }
            }
        }

        return dist;
    }

    /*
     * ========================================================================
     *                    FLOYD-WARSHALL ALGORITHM
     * ========================================================================
     * 
     * CONCEPT:
     * - ALL PAIRS shortest path (not single source!)
     * - Dynamic Programming approach
     * - Handles negative weights (but not negative cycles)
     * 
     * ALGORITHM:
     * - dist[i][j] = shortest distance from i to j
     * - For each intermediate vertex k:
     *     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
     * 
     * INTUITION:
     * - For each pair (i,j), check if going through k gives shorter path
     * - After considering all k, we have shortest paths for all pairs
     * 
     * DP RECURRENCE:
     * - Let dp[k][i][j] = shortest i→j using vertices {0,1,...,k} as intermediates
     * - dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j])
     * - Space optimized to 2D since we only need previous k
     * 
     * NEGATIVE CYCLE DETECTION:
     * - If dist[i][i] < 0 for any i, there's a negative cycle
     * 
     * TIME: O(V³)  |  SPACE: O(V²)
     * ========================================================================
     */
    vector<vector<int>> flaydWarshall(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances based on adjacency list
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;  // Distance to self is zero
            for (auto neighbor : adjList[i])
            {
                dist[i][neighbor.first] = neighbor.second;  // Direct edge
            }
        }

        // Floyd-Warshall: try each vertex as intermediate
        for (int k = 0; k < n; k++)          // k = intermediate vertex
        {
            for (int i = 0; i < n; i++)      // i = source
            {
                for (int j = 0; j < n; j++)  // j = destination
                {
                    // Check if path through k is shorter
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        // Note: if dist[i][i] < 0, there's a negative cycle through i

        return dist;
    }

    /*
     * ========================================================================
     *    STRONGLY CONNECTED COMPONENTS - KOSARAJU'S ALGORITHM
     * ========================================================================
     * 
     * DEFINITION:
     * - SCC: A maximal set of vertices where every vertex is reachable from
     *   every other vertex (in a directed graph)
     * 
     * KOSARAJU'S ALGORITHM (3 Steps):
     * 1. Do DFS and push nodes to stack in order of finish time (topological-like)
     * 2. Create TRANSPOSE/REVERSE graph (reverse all edges)
     * 3. Do DFS on reverse graph in stack order → each DFS tree is one SCC
     * 
     * WHY IT WORKS:
     * - In original graph: nodes in same SCC can reach each other
     * - In reversed graph: if u can reach v in original, v can reach u in reverse
     * - Processing in finish-time order ensures we don't cross SCC boundaries
     * 
     * INTUITION:
     * - First DFS finds "leaders" (nodes that finish last)
     * - Reverse graph + finish-time order isolates each SCC
     * 
     * APPLICATIONS:
     * - Finding cycles in directed graphs
     * - 2-SAT problem
     * - Simplifying graphs (contract SCCs to single nodes)
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    int StronglyConnectedComponents(int n)
    {
        // Step 1: Get nodes in order of finish time (using topological sort)
        vector<int> topoArray = topologicalSort(n);
        
        // Step 2: Build REVERSE/TRANSPOSE graph
        unordered_map<int, list<int>> adjReverse;
        for (auto &i : adjList)
        {
            for (auto &j : i.second)
            {
                int u = i.first;
                int v = j.first;
                adjReverse[v].push_back(u);  // Reverse: v → u instead of u → v
            }
        }

        int sccCount = 0;
        unordered_map<int, bool> visited;

        // Step 3: DFS on reverse graph in topological order
        // Each DFS traversal discovers one SCC
        for (int idx = 0; idx < topoArray.size(); idx++)
        {
            int src = topoArray[idx];
            if (!visited[src])
            {
                SCC_DFS(src, visited, adjReverse);
                sccCount++;  // One complete DFS = one SCC
            }
        }
        return sccCount;
    }

    // Helper DFS for Kosaraju's algorithm
    void SCC_DFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjReverse)
    {
        visited[src] = true;
        for (auto nbr : adjReverse[src])
        {
            if (!visited[nbr])
                SCC_DFS(nbr, visited, adjReverse);
        }
    }

    /*
     * ========================================================================
     *         TARJAN'S ALGORITHM - FINDING BRIDGES (Cut Edges)
     * ========================================================================
     * 
     * DEFINITIONS:
     * - BRIDGE: An edge whose removal disconnects the graph
     * - Also called "cut edge"
     * 
     * KEY CONCEPTS:
     * - time_in[u]: Discovery time when node u was first visited
     * - min_time[u]: Minimum discovery time reachable from subtree of u
     *                (including back edges, excluding parent edge)
     * 
     * BRIDGE CONDITION:
     * - Edge (u, v) is a bridge if: min_time[v] > time_in[u]
     * - This means: v's subtree has NO back edge to u or u's ancestors
     * - So removing (u,v) disconnects v's subtree from u!
     * 
     * ALGORITHM:
     * 1. Do DFS, assign discovery time to each node
     * 2. For each node, compute min_time (lowest reachable discovery time)
     * 3. After DFS of child v: if min_time[v] > time_in[u], edge u-v is bridge
     * 
     * BACK EDGE:
     * - Edge to already-visited node (that's not parent)
     * - Back edges create alternate paths, making those edges NOT bridges
     * 
     * APPLICATIONS:
     * - Network reliability analysis
     * - Finding critical connections
     * - Identifying weak points in network
     * 
     * TIME: O(V + E)  |  SPACE: O(V)
     * ========================================================================
     */
    int TarjanAlgo(int n)
    {
        int timer = 0;
        vector<int> time_in(n, -1);    // Discovery time of each node
        vector<int> min_time(n, -1);   // Min discovery time reachable from subtree
        unordered_map<int, bool> visited;
        int bridges = 0;

        // Handle disconnected components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                countBridges(i, -1, time_in, min_time, visited, timer, bridges);
            }
        }
        return bridges;
    }

    void countBridges(int src, int parent, vector<int> &time_in, vector<int> &min_time, 
                      unordered_map<int, bool> &visited, int &timer, int &bridges)
    {
        visited[src] = true;
        timer++;
        time_in[src] = timer;      // Assign discovery time
        min_time[src] = timer;     // Initialize min_time to discovery time

        for (auto nbr : adjList[src])
        {
            int neighbor = nbr.first;
            
            if (neighbor == parent)
                continue;  // Skip the edge we came from
            
            else if (!visited[neighbor])
            {
                // Tree edge: recurse
                countBridges(neighbor, src, time_in, min_time, visited, timer, bridges);
                
                // After DFS, update min_time from child's subtree
                min_time[src] = min(min_time[src], min_time[neighbor]);
                
                // BRIDGE CONDITION: child can't reach src or above
                if (min_time[neighbor] > time_in[src])
                {
                    cout << "Bridge found: " << src << " -> " << neighbor << endl;
                    bridges++;
                }
            }
            else
            {
                // Back edge: update min_time (found alternate path!)
                min_time[src] = min(min_time[src], time_in[neighbor]);
            }
        }
    }
};

/*
 * ============================================================================
 *                              QUICK REFERENCE
 * ============================================================================
 * 
 * ALGORITHM           | TIME        | SPACE  | USE CASE
 * --------------------|-------------|--------|--------------------------------
 * BFS                 | O(V+E)      | O(V)   | Shortest path (unweighted)
 * DFS                 | O(V+E)      | O(V)   | Traversal, cycle detection
 * Topological Sort    | O(V+E)      | O(V)   | DAG ordering, dependencies
 * Dijkstra            | O((V+E)logV)| O(V)   | Shortest path (non-negative)
 * Bellman-Ford        | O(V*E)      | O(V)   | Shortest path (negative ok)
 * Floyd-Warshall      | O(V³)       | O(V²)  | All-pairs shortest path
 * Kosaraju (SCC)      | O(V+E)      | O(V)   | Strongly connected components
 * Tarjan (Bridges)    | O(V+E)      | O(V)   | Find bridge edges
 * 
 * CYCLE DETECTION:
 * - Undirected: Check if visited neighbor ≠ parent
 * - Directed: Use recursion stack (inStack) to detect back edges
 * 
 * NEGATIVE WEIGHTS:
 * - Dijkstra: ❌ Cannot handle
 * - Bellman-Ford: ✅ Can handle, detects negative cycles
 * - Floyd-Warshall: ✅ Can handle
 * 
 * ============================================================================
 */

int main()
{
    Graph g;

    int n = 6; // number of nodes (0 to 5)

    // SCC 1: nodes 0, 1, 2 form a cycle
    g.addEdge(0, 1, 1, 1); // 0 -> 1
    g.addEdge(1, 2, 1, 1); // 1 -> 2
    g.addEdge(2, 0, 1, 1); // 2 -> 0 (completes cycle)

    // Connection from SCC 1 to SCC 2
    g.addEdge(1, 3, 1, 1); // 1 -> 3

    // SCC 2: nodes 3, 4 form a cycle
    g.addEdge(3, 4, 1, 1); // 3 -> 4
    g.addEdge(4, 3, 1, 1); // 4 -> 3 (completes cycle)

    // Connection from SCC 2 to SCC 3
    g.addEdge(4, 5, 1, 1); // 4 -> 5

    // SCC 3: node 5 is a single node (no outgoing edges back to any SCC)

    cout << "Graph Adjacency List:" << endl;
    g.printAdjList(n);

    cout << "\n===== Kosaraju's Algorithm =====" << endl;
    int sccCount = g.StronglyConnectedComponents(n);
    cout << "Number of Strongly Connected Components: " << sccCount << endl;
    cout << "(Expected: 3 SCCs -> {0,1,2}, {3,4}, {5})" << endl;

    // ===== Tarjan's Algorithm for Bridges =====
    cout << "\n===== Tarjan's Algorithm (Bridges) =====" << endl;
    
    // Create a new undirected graph for bridge detection
    Graph g2;
    int n2 = 5;
    
    // Create a graph with bridges:
    //     0 --- 1 --- 2
    //           |     |
    //           3 --- 4
    // Edge 0-1 is a bridge (removing it disconnects node 0)
    
    g2.addEdge(0, 1);  // Bridge!
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 4);
    g2.addEdge(3, 4);  // This creates a cycle 1-2-4-3-1
    
    cout << "Graph for Bridge Detection:" << endl;
    g2.printAdjList(n2);
    
    cout << "\nFinding Bridges:" << endl;
    int bridgeCount = g2.TarjanAlgo(n2);
    cout << "Total number of bridges: " << bridgeCount << endl;
    cout << "(Expected: 1 bridge -> 0-1)" << endl;

    return 0;
}
