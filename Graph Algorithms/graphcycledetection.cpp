********** UNDIRECTED *******************    

bool isCyclicUndirectedUsing_BFS(T src){
        unordered_map<T,bool> visited;
        unordered_map<T,T> parent;
        visited[src]=true;
        parent[src]=src;
        queue<T> q;
        q.push(src);
        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(T neighbour : adjlist[node]){
                if(visited[neighbour] and parent[node]!=neighbour){
                    return true;
                }else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                }
            }
        }
        return false; 
    }
    // DFS APPROACH 
    bool visited[100001];
    bool dfs(int s, int p, vector<int> adj[]) {
        if(visited[s]) {
            return true;
        }
        visited[s] = true;
        for(auto child : adj[s]) {
            if(child != p) {
                bool ans = dfs(child,s,adj);
                if(ans) {
                    return true;
                }
            }
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    memset(visited, false, sizeof visited);
	    for(int i = 0; i < V; i++) {
	        if(!visited[i]) {
	            bool ans = dfs(i,-1,adj);
	            if(ans) {
	                return true;
	            }
	        }
	    }
	    return false;
	}

************ DIRECTED **********************
    bool isCyclicDirectedUsing_DFShelper(T node,unordered_map<T,bool> &visited,unordered_map<T,bool> &instack){
        visited[node]=true;
        instack[node]=true;
        for(T neighbour:adjlist[node]){
            // dfscall to further node whos further branch leads to a cycle
            if(!visited[neighbour] and isCyclicDirectedUsing_DFShelper(neighbour,visited,instack)){
                return true;
            }
            // dfscall to node which has a back edge
            else if(instack[neighbour]){
                return true;
            }
        }    
        instack[node]=false;
        return false;

    }
    bool isCyclicDirectedUsing_DFS(){
        unordered_map<T,bool> visited;
        unordered_map<T,bool> instack;
        for(auto i:adjlist){
            T node=i.first;
            if(!visited[node]){
                bool checkcycle=isCyclicDirectedUsing_DFShelper(node,visited,instack);
                if(checkcycle){
                    return true;
                }
            }
        }
        return false;
    }

