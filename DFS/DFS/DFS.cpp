#include <iostream>
#include <stack>

#define Vertex int
#define WHITE 0
#define GRAY 1
#define BLACK 2

#define NumVertex 4

using namespace std;

struct node{
	int val;
	int weight;
	struct node* next;
	node(int v, int w) :val(v), weight(w), next(NULL){}
};

typedef node* VList;

struct TableEntry{
	VList header;
	Vertex color;
};

typedef TableEntry Table[NumVertex + 1];

void InitTableEntry(Vertex start, Table T){
	Vertex outDegree;
	VList temp = NULL;
	for (int i = 1; i <= NumVertex; i++) {
		scanf("%d", &outDegree);
		T[i].header = NULL;
		T[i].color = WHITE;
		for (int j = 0; j < outDegree; j++) {
			temp = (VList)malloc(sizeof(struct node));
			scanf("%d %d", &temp->val, &temp->weight);
			temp->next = T[i].header;
			T[i].header = temp;
		}
	}
	T[start].color = GRAY;
}

void DFS(Vertex start, Table T){
	stack<Vertex> S;
	S.push(start);
	Vertex V;
	VList temp;
	while (!S.empty()) {
		V = S.top();
		printf("%d ", V);
		T[V].color = BLACK;
		S.pop();
		temp = T[V].header;
		while (temp) {
			if (T[temp->val].color == WHITE) {
				S.push(temp->val);
				T[temp->val].color = GRAY;
			}
			temp = temp->next;
		}
	}
}

int main(int argc, const char * argv[]) {
	Table T;

	InitTableEntry(1, T);

	DFS(1, T);

	return 0;
}