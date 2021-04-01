/* Practical - 1
Def: Represent graphs as a Adjacency List using either Arry of LinkedList of LinkedList of LinkedList representation and perform
     these operations:
     - Union
     - Intersection
     - Compliment
     - Sum
     - Difference
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};
struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

int max(int a, int b) { return (a >= b) ? a : b; }
int min(int a, int b) { return (a <= b) ? a : b; }

struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    bool vis[graph->V];
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode *pCrawl = graph->array[v].head;
        printf("\n For vertex %d\n head ", v + 1);
        for (int i = 0; i < graph->V; i++)
            vis[i] = false;
        while (pCrawl)
        {
            if (vis[pCrawl->dest] == false)
                printf("-> %d", pCrawl->dest + 1);
            vis[pCrawl->dest] = true;
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
    printf("\n");
}

void unionGraph(struct Graph *g3, struct Graph *g1, struct Graph *g2, int v1, int v2, int v3)
{
    bool vis[v3];
    for (int i = 0; i < v3; i++)
    {
        for (int k = 0; k < v3; k++)
            vis[k] = false;
        if (i < v1)
        {
            struct AdjListNode *temp = g1->array[i].head;
            while (temp)
            {
                if (vis[temp->dest] == false)
                {
                    addEdge(g3, i, temp->dest);
                    vis[temp->dest] = true;
                }
                temp = temp->next;
            }
        }
        if (i < v2)
        {
            struct AdjListNode *temp = g2->array[i].head;
            while (temp)
            {
                if (vis[temp->dest] == false)
                {
                    addEdge(g3, i, temp->dest);
                    vis[temp->dest] = true;
                }
                temp = temp->next;
            }
        }
    }
}

void intersectionGraph(struct Graph *g3, struct Graph *g1, struct Graph *g2, int v1, int v2, int v3)
{
    bool vis[v3];
    for (int i = 0; i < v3; i++)
    {
        for (int k = 0; k < v3; k++)
            vis[k] = false;
        struct AdjListNode *temp = g1->array[i].head;
        while (temp)
        {
            vis[temp->dest] = true;
            temp = temp->next;
        }
        temp = g2->array[i].head;
        while (temp)
        {
            if (vis[temp->dest])
            {
                addEdge(g3, i, temp->dest);
            }
            temp = temp->next;
        }
    }
}

void complementGraph(struct Graph *g2, struct Graph *g1, int v1, int v2)
{
    bool vis[v1];
    for (int i = 0; i < v2; i++)
    {
        for (int k = 0; k < v1; k++)
            vis[k] = false;
        struct AdjListNode *temp = g1->array[i].head;
        while (temp)
        {
            vis[temp->dest] = true;
            temp = temp->next;
        }
        vis[i] = true;
        for (int j = 0; j < v2; j++)
        {
            if (!vis[j])
                addEdge(g2, i, j);
        }
    }
}

void differenceGraph(struct Graph *g3, struct Graph *g1, struct Graph *g2, int v1, int v2)
{
    bool vis[v1];
    for (int i = 0; i < v1; i++)
    {
        for (int k = 0; k < v1; k++)
            vis[k] = false;
        if (i < v2)
        {
            struct AdjListNode *pCrawl = g2->array[i].head;
            while (pCrawl)
            {
                vis[pCrawl->dest] = true;
                pCrawl = pCrawl->next;
            }
        }
        struct AdjListNode *temp = g1->array[i].head;
        while (temp)
        {
            if (vis[temp->dest] == false)
            {
                addEdge(g3, i, temp->dest);
                vis[temp->dest] = true;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int v1, v2, e1, e2, sr, de;
    printf("For Graph G1:\n");
    printf("Enter total number of nodes and edges in G1: ");
    scanf("%d%d", &v1, &e1);
    struct Graph *g1 = createGraph(v1);
    for (int i = 0; i < e1; i++)
    {
        printf("Enter source destination of edge %d in G1: ", i + 1);
        scanf("%d%d", &sr, &de);
        addEdge(g1, sr - 1, de - 1);
    }

    printf("\n\nFor Graph G2:\n");
    printf("\nEnter total number of nodes and edges in G2: ");
    scanf("%d%d", &v2, &e2);
    struct Graph *g2 = createGraph(v2);
    for (int i = 0; i < e2; i++)
    {
        printf("Enter source destination of edge %d in G1: ", i + 1);
        scanf("%d%d", &sr, &de);
        addEdge(g2, sr - 1, de - 1);
    }
    int ch, v3, v4, v5;
    printf("\n Graph G1 is:\n");
    printGraph(g1);
    printf("\n Graph G2 is:\n");
    printGraph(g2);
    struct Graph *g3, *g4, *g5, *g6, *g7, *g8, *g9;
    do
    {
        printf("Enter 1 for union of G1 and G2\n");
        printf("Enter 2 for intersection of G1 and G2\n");
        printf("Enter 3 for complement of G1\n");
        printf("Enter 4 for complement of G2\n");
        printf("Enter 5 for difference G1-G2\n");
        printf("Enter 6 for difference G2-G1\n");
        printf("Enter 7 for G1 ringsum G2\n");
        printf("Enter 8 for exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            v3 = max(v1, v2);
            g3 = createGraph(v3);
            unionGraph(g3, g1, g2, v1, v2, v3);
            printGraph(g3);
            break;
        case 2:
            v4 = min(v1, v2);
            g4 = createGraph(v4);
            intersectionGraph(g4, g1, g2, v1, v2, v4);
            printGraph(g4);
            break;
        case 3:
            v5 = v1;
            g5 = createGraph(v5);
            complementGraph(g5, g1, v1, v5);
            printGraph(g5);
            break;
        case 4:
            g6 = createGraph(v2);
            complementGraph(g6, g2, v2, v2);
            printGraph(g6);
            break;
        case 5:
            g7 = createGraph(v1);
            differenceGraph(g7, g1, g2, v1, v2);
            printGraph(g7);
            break;
        case 6:
            g8 = createGraph(v2);
            differenceGraph(g8, g2, g1, v2, v1);
            printGraph(g8);
            break;
        case 7:
            v3 = max(v1, v2);
            g9 = createGraph(v3);

            g7 = createGraph(v1);
            differenceGraph(g7, g1, g2, v1, v2);
            g8 = createGraph(v2);
            differenceGraph(g8, g2, g1, v2, v1);

            unionGraph(g9, g7, g8, v1, v2, v3);
            printGraph(g9);
            break;
        case 8:
            ch = 8;
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    } while (ch != 8);

    return 0;
}
