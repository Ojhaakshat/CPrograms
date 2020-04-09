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

