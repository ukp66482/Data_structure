#include <stdio.h>
#include <stdlib.h>

//define structure

typedef struct Edge {        // store Edge information
    int come;
    int in;
    int cost;
}Edge;

typedef struct Graph{        //G(V,E) V=node E=Edge_num also store Edge information by struct Edge
    int Node_num,Edge_num;
    Edge *edge;
}Graph;

typedef struct tree_subset{ //to make tree subset for disjoint set
    int parent;
    int rank;
}tree_subset;

//define function

Graph* create_Graph(int Node_num,int Edge_num){

    Graph *gph = malloc(sizeof (Graph));
    gph->Node_num = Node_num;
    gph->Edge_num = Edge_num;
    gph->edge = malloc(sizeof (Edge)*Edge_num); // create the Edge_num of edge aray

    return gph;
}



int DisjointSet_find(tree_subset subsets[],int i){
    if(subsets[i].parent!=i){
        subsets[i].parent = DisjointSet_find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}



void Disjointset_Union(tree_subset subsets[],int x,int y){
    int x_root = DisjointSet_find(subsets,x);
    int y_root = DisjointSet_find(subsets,y);

    if(subsets[x_root].rank < subsets[y_root].rank){
        subsets[x_root].parent = y_root;
    }else if(subsets[x_root].rank > subsets[y_root].rank){
        subsets[y_root].parent = x_root;
    }else{
        subsets[y_root].parent = x_root;
        subsets[x_root].rank++;
    }
}

int myComp(const void* a,const void* b){ //used by qsort

    Edge *a1 = (Edge*)a;
    Edge *b1 = (Edge*)b;
    if(a1->cost >= b1->cost) {
        return 1;
    }else{
        return -1;
    }

}

long long unsigned int Kruskal(Graph* gph){
    int Node = gph->Node_num;
    Edge result[Node];
    int e=0;
    int i=0;

    qsort(gph->edge,gph->Edge_num,sizeof (gph->edge[0]),myComp);

    tree_subset *subsets = malloc(Node * sizeof (tree_subset)*gph->Edge_num);

    for(int v=0;v<Node;++v){       //create Node_num subset
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e < Node-1 && i < gph->Edge_num){         //we need n-1 edge so e<Node-1
        Edge next_edge = gph->edge[i++];
        int x = DisjointSet_find(subsets, next_edge.come);
        int y = DisjointSet_find(subsets, next_edge.in);

        if(x!=y){
            result[e++] = next_edge;

            Disjointset_Union(subsets,x,y);
        }
    }

    long long unsigned int minimum_cost = 0;

    for(i=0;i<e;i++){
        //printf("%d-%d == %d\n",result[i].come,result[i].in,result[i].cost);
        minimum_cost += result[i].cost;
    }
    //printf("\n%lld",minimum_cost);
    return minimum_cost;
}



int main() {
    int Node_num,Edge_num;
    long long unsigned int minimum_cost;

    scanf("%d %d",&Node_num,&Edge_num);

    Graph* gph = create_Graph(Node_num, Edge_num);

     for(int i=0;i<Edge_num;i++){
        scanf("%d %d %d",&gph->edge[i].come,&gph->edge[i].in,&gph->edge[i].cost);
    }

    minimum_cost = Kruskal(gph);
    printf("%llu",minimum_cost);
    return 0;
}
