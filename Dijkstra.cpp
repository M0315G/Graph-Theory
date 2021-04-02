#include <iostream>
#include <vector>
using namespace std;


int min_distance(int dist[], bool visited[], int V){
    
    int min = INT_MAX, vertex;
    for(int i=0; i<V; ++i){
        if(visited[i]==false && min>=dist[i]){
            min = dist[i];
            vertex = i;
        }
    }

    return vertex;
}

void print_path(int dist[], int V){

    cout << "The distance of every vertex from source is as follows: "<<endl;
    for(int i=0; i<V; ++i){
        cout << "Vertex "<<(i+1)<<": "<<dist[i]<<endl;
    }
}


void shortest_path(int src, vector<vector<int> > graph)
{

    int dist[graph.size()];
    bool visited[graph.size()];

    for (int i = 0; i < graph.size(); i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < graph.size(); i++)
    {

        // Find the vertex closest to src vertex.
        int v = min_distance(dist, visited, graph.size());

        visited[v] = true;

        for(int j=0; j<graph.size(); ++j){
            if(visited[j]==false && graph[v][j] && dist[v]!=INT_MAX && dist[v]+graph[v][j]<dist[j]){
                dist[j] = dist[v] + graph[v][j];
            }
        }
    }


    print_path(dist, graph.size());
}

int main()
{

    // Take a graph as input

    vector<vector<int> > graph;
    int V;
    cout <<"Enter the number of vertices: "<<endl;
    cin >> V;
    cout <<"Enter the Adjancency Matrix :"<<endl;
    for(int i=0; i<V; ++i){
        vector<int> temp;
        int a;
        for(int j=0; j<V; ++j){
            cin >> a;
            temp.push_back(a);
        }
        graph.push_back(temp);
    }
    // Take source and destination vertex
    int src, dest;
    cout << "Enter source vertex: " << endl;
    cin >> src;
    shortest_path(src, graph);
    return 0;
}

// 0 2 4 0 0 0
// 2 0 1 7 0 0
// 4 1 0 0 3 0
// 0 7 0 0 2 1
// 0 0 3 2 0 5
// 0 0 0 1 5 0
