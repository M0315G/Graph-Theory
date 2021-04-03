#include<bits/stdc++.h>

using namespace std;

const int INF = 99999;
const int V = 4;


void print_answer(int dist[][V]){

    for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
            if(dist[i][j]==INF){
                cout << "INF" << "  ";
            }else{
                cout << dist[i][j]<<"  ";
            }
        }
        cout << endl;
    }

}

void all_pair_shortest_path(int graph[][V]){

    int dist[V][V];

    for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
            dist[i][j] = graph[i][j];
        }
    }

    for(int k=0; k<V; ++k){
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    print_answer(dist);
}


int main(){

    // vector<vector<int> > graph;
    // // cout <<"Enter the number of vertices: "<<endl;
    // // cin >> V;
    // cout <<"Enter the Adjancency Matrix :"<<endl;
    // for(int i=0; i<V; ++i){
    //     vector<int> temp;
    //     int a;
    //     for(int j=0; j<V; ++j){
    //         cin >> a;
    //         temp.push_back(a);
    //     }
    //     graph.push_back(temp);
    // }

    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0}
                    };

    all_pair_shortest_path(graph);
    return 0;
}