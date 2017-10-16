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
/*
广度优先搜索的思想：

　　　　　　 　　① 访问顶点vi ；

　　　　　　　　 ② 访问vi 的所有未被访问的邻接点w1 ,w2 , …wk ；

　　　　　　　　 ③ 依次从这些邻接点（在步骤②中访问的顶点）出发，访问它们的所有未被访问的邻接点; 依此类推，直到图中所有访问过的顶点的邻接点都被访问；
节点有三个颜色，白色：表示节点还未遍历，灰色：节点已经遍历但是邻接节点有白色，黑色：节点已经遍历且邻接节点是非白色。
从源节点开始遍历，首先将其变为灰色然后加入队列中，之后遍历1节点的邻接节点，所以1节点的邻接节点全都变为灰色并加入队列中，之后弹出队首元素1节点并将其变为黑色。
然后再把队首元素的相邻节点加入到队列中。然后继续输出并弹出队首元素依次类推。到队列空为止，此时将遍历所有节点。

*/
