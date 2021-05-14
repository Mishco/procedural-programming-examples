// uloha-8-1.c -- Tyzden 8 - Uloha 1
// Michal Slovik, 10.11.2015 09:37:34
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXV        10000   /* maximum number of vertices */
#define MAXDEGREE   50000    /* maximum outdegree of a vertex */

#define QUEUESIZE       10000

typedef struct graph {
	int edges[MAXV+1][MAXDEGREE];   /* adjacency info */
	int degree[MAXV+1];     /* outdegree of each vertex */
	int nvertices;          /* number of vertices in the graph */
	int nedges;         /* number of edges in the graph */
} graph;


typedef struct queue {
	int q[QUEUESIZE+1];     /* body of queue */
	int first;                      /* position of first element */
	int last;                       /* position of last element */
	int count;                      /* number of queue elements */
} queue;

int d[MAXV];

int finished = FALSE;  /* if true, cut off search immediately */
int count = 0;

void init_queue(queue *q)
{
	q->first = 0;
	q->last = QUEUESIZE-1;
	q->count = 0;
}

void enqueue(queue *q, int x)
{
	if (q->count >= QUEUESIZE)
		printf("Warning: queue overflow enqueue x=%d\n",x);
	else {
		q->last = (q->last+1) % QUEUESIZE;
		q->q[ q->last ] = x;    
		q->count = q->count + 1;
	}
}

int dequeue(queue *q)
{
	int x;

	if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
	else {
		x = q->q[ q->first ];
		q->first = (q->first+1) % QUEUESIZE;
		q->count = q->count - 1;
	}

	return(x);
}

int empty(queue *q)
{
	if (q->count <= 0) return (TRUE);
	else return (FALSE);
}

void initialize_graph(graph *g)
{
    int i;              /* counter */
	

    g -> nvertices = 0;
    g -> nedges = 0;

    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}
void insert_edge(graph *g, int x, int y, int directed)
{
    if (g->degree[x] > MAXDEGREE)
        printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);

    g->edges[x][g->degree[x]] = y;
    g->degree[x] ++;

    if (directed == FALSE)
        insert_edge(g,y,x,TRUE);
    else
        g->nedges ++;
}
void read_graph(graph *g, int directed)
{
    int i;              /* counter */
    int m;              /* number of edges */
    int x, y;           /* vertices in edge (x,y) */

    initialize_graph(g);

    scanf("%d %d",&(g->nvertices),&m);

    for (i=1; i<=m; i++) {
        scanf("%d %d",&x,&y);
        insert_edge(g,x,y,directed);
    }
}
void delete_edge(graph *g, int x, int y, int directed)
{
    int i;              /* counter */

    for (i=0; i<g->degree[x]; i++) 
        if (g->edges[x][i] == y) {
            g->degree[x] --;
            g->edges[x][i] = g->edges[x][g->degree[x]];

            if (directed == FALSE)
                delete_edge(g,y,x,TRUE);

            return;
        }

    printf("Warning: deletion(%d,%d) not found in g.\n",x,y);
}

void print_graph(graph *g)
{
    int i,j;            /* counters */

    for (i=1; i<=g->nvertices; i++) {
        printf("%d: ",i);
        for (j=0; j<g->degree[i]; j++)
            printf(" %d",g->edges[i][j]);
        printf("\n");
    }
}

void myBFS(graph *g, int K, int end, int countOfstartingNodes[])
{
	int i, x;
	queue *q;

	q = (queue*)malloc(sizeof(queue));
	init_queue(q);
	
	for (i = 1; i <= end; i++)
	{
		d[i] = -1;
	}
	// chceme urcit d[v] pre vsetky vrcholy grafu


	for (i = 0; i < K; i++)
	{
		d[countOfstartingNodes[i]] = 0;
		enqueue(q,countOfstartingNodes[i]);	//vsetky prvky dame do radu
	}
	
	while (empty(q) == FALSE) 
	{
	
		x = dequeue(q);
		// prejdi vsetky susedne vrcholy x
		for (i=0; i<g->degree[x]; i++)
		{ 
			// este nebol navstiveny
			if ( d[g->edges[x][i]] == -1 )
			{
				enqueue(q,g->edges[x][i]);
				d[g->edges[x][i]]= d[x] + 1;
			}
		}
	}
}

/*main function*/
int main() 
{

	int i;
	int N,M,K;
	int from, to;
	int poleK[MAXV];
	graph *g;
  
	scanf("%d %d %d", &N, &M, &K);
	// N pocet miest
	// M pocet letov medzi mestami ( maximum )
	// K urcuje pocet miest kde kde mame agentov

	g = (graph*)malloc(sizeof(graph));
	initialize_graph(g);
	g->nvertices=N;

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &from, &to);
		insert_edge(g,from, to, FALSE);
	}

	// najdi start
	for (i = 0; i < K; i++)
	{
		scanf("%d", &poleK[i]);
	}
  
	myBFS(g, K, N, poleK);

	for (i = 1; i <= N; i++)
	{
		if ( d[i] != -1 )
			printf("%d %d\n", i,d[i]);
	}
	printf("\n");
	return 0;
}
