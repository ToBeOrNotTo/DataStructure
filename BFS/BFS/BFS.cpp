#include <iostream>
#include <queue>

#ifndef Vertex
#define Vertex int
#endif

#ifndef NumVertex
#define NumVertex 4
#endif

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

struct node{
	int val;
	int weight;
	node* next;
	node(int v, int w) : val(v), weight(w), next(NULL){}
};

typedef node* VList;

struct TableEntery{
	VList header;
	Vertex color;
};

typedef TableEntery Table[NumVertex + 1];

void InitTableEntry(Vertex start, Table T){ //init the Graph
	Vertex OutDegree = 0;
	VList temp = NULL;

	for (int i = 1; i <= NumVertex; i++) {
		scanf("%d", &OutDegree); // input the out degree of vertex
		T[i].header = NULL;
		T[i].color = WHITE;
		for (int j = 0; j < OutDegree; j++) {
			temp = (VList)malloc(sizeof(struct node));
			scanf("%d %d", &temp->val, &temp->weight);
			temp->next = T[i].header;
			T[i].header = temp;
		}
	}

	T[start].color = GRAY; //init the start vertex color to gray
}

void BFS(Vertex start, Table T){
	queue<Vertex> Q;
	Q.push(start);
	VList temp = NULL;
	while (!Q.empty()) { //if queue is not empty, then the bfs is not over
		temp = T[Q.front()].header; //find the front of the queue
		while (temp) { //if the front vertex has next vertex
			if (T[temp->val].color == WHITE) {
				Q.push(temp->val); //push the white vertex to queue
				T[temp->val].color = GRAY; //change the color to gray
			}
			temp = temp->next;
		}
		printf("%d ", Q.front()); //output the vertex
		T[Q.front()].color = BLACK; //then change color
		Q.pop();
	}
}

int main(int argc, const char * argv[]) {
	Table T;
	InitTableEntry(1, T);
	BFS(1, T);
	return 0;
}