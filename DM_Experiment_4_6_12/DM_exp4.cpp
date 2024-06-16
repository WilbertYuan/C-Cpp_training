#include<bits/stdc++.h>
#include<chrono>
using namespace std;
void InitAdjacencyMatrix(int** p, int* q, int n);
void InitAdjacencyMatrix(int** p, int n);
void ConstructAdjacencyMatrixforPath(int* q,int** p,int n,double connecting_rate);
void ShowAdjacencyMatrix(int** p, int n);
bool TestIfEulerPath(int** p, int n);
bool TestIfEulerCircuit(int** p, int n);
long long get_high_time() {
	return (chrono::high_resolution_clock::now()).time_since_epoch().count();
}
int* FindEulerPath(int** p, int n, int& pathLength);
int* FindEulerCircuit(int** p, int n, int& pathLength);
bool dfs(int** p, int n, int currentVertex, int* path, int pathIndex, int* visited);
void ShowEulerPath(int* path, int n);
void ShowEulerCircuit(int* path, int n);

int main()
{
	srand((unsigned int)time(NULL));
	double connecting_rate = rand() % 100 / 200.0;

	int n = 0,flag = -1,failnum = 0,pathlength = 0,eulernum = 0,halfeulernum = 0;
	printf("请输入顶点的数目 ");
	scanf_s("%d", &n);
	int**p = new int*[n], ** multi_p = new int* [n];
	int*q = new int[n];

	while ((flag!=0)&&((flag != 1)))
	{
		printf("\n我想要一个半欧拉图(0) 我想要一个欧拉图(1)\n请选择[0/1] ");
		scanf_s("%d", &flag);
	}

	while(true)
	{
		InitAdjacencyMatrix(p, q, n);
		ConstructAdjacencyMatrixforPath(q,p,n,connecting_rate);
		//ShowAdjacencyMatrix(p,n);
		if(TestIfEulerPath(p,n))
		{
			if(flag)
			{
				failnum++;
				halfeulernum++;
				continue;
			}
			ShowAdjacencyMatrix(p, n);
			printf("\n经过%d次失败生成，得到了您所需要的半欧拉图\n\n（在此过程中一共生成了%d个一般连通图以及%d个欧拉图)\n\n", failnum,failnum-eulernum,eulernum);
			break;
		}
		else if(TestIfEulerCircuit(p,n))
		{
			if(!flag)
			{
				failnum++;
				eulernum++;
				continue;
			}
			ShowAdjacencyMatrix(p, n);
			printf("\n经过%d次失败生成，得到了您所需要的欧拉图\n\n（在此过程中一共生成了%d个一般连通图以及%d个半欧拉图)\n\n", failnum,failnum - halfeulernum, halfeulernum);
			break;
		}
		else
		{
			failnum++;
			//cout << "This is not a Euler Path or a Euler Circuit" << endl;
		}
	}
	//InitAdjacencyMatrix(multi_p, n);
	//MatrixMultiplication(p, multi_p, n,10);
	//ShowAdjacencyMatrix(multi_p, n);
	//int* path = FindEulerPath(p, n,a);
	//int* path = FindEulerCircuit(p, n, pathlength);
	if(!flag)
		ShowEulerPath(FindEulerPath(p, n, pathlength), n);
	else
		ShowEulerCircuit(FindEulerCircuit(p, n, pathlength), n);

	//释放内存
	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
	}
	delete[] p;
	delete[] q;
	for (int i = 0; i < n; i++)
	{
		delete[] multi_p[i];
	}
	delete[] multi_p;


	return 0;
}


void InitAdjacencyMatrix(int** p, int* q, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(p + i) = new int[n];
		for (int j = 0; j < n; j++)
		{
			*(*(p + i) + j) = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		q[i] = i;
	}
}
void InitAdjacencyMatrix(int** p,int n)
{
	for (int i = 0; i < n; i++)
	{
		*(p + i) = new int[n];
		for (int j = 0; j < n; j++)
		{
			*(*(p + i) + j) = 0;
		}
	}
}
void ConstructAdjacencyMatrixforPath(int*q,int** p,int n = 5,double connecting_rate = 0.3)
{
	int stepnow = -1;
	int stepnext = -1;
	for (int j = 0; j < n; j++)
	{
		
		srand((unsigned int)time(NULL));
		int a = rand() % (n - j);
		int* step = q;
		for (int k = 0;k <= a;k++)
		{
			if (*step == -1)
			{
				a++;
			}
			step++;
		}
		step--;
		//cout << *step;
		stepnext = *step;
		if (stepnow != -1)
		{
			*(*(p + stepnow) + stepnext) = 1;
			*(*(p + stepnext) + stepnow) = 1;
		}
		stepnow = stepnext;
		*step = -1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < i;j++)
		{
			srand((unsigned int)get_high_time());
			int mm = (rand() % ((unsigned int)(1 / connecting_rate)));
			//cout<< mm;
			if((*(*(p+i)+j) == 0)&&(mm==0))
			{
				*(*(p+i)+j) = 1;
				*(*(p+j)+i) = 1;
			}
		}
	}
	//cout << endl;
	/*for (int ll = 0; ll < 100; ll++)
	{

		cout << a;
	}*/
}
bool TestIfEulerPath(int** p, int n)
{
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		int degree = 0;
		for (int j = 0; j < n; j++)
		{
			degree += *(*(p + i) + j);
		}
		if (degree % 2 != 0)
		{
			odd++;
		}
	}
	if (odd == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TestIfEulerCircuit(int** p, int n)
{
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		int degree = 0;
		for (int j = 0; j < n; j++)
		{
			degree += *(*(p + i) + j);
		}
		if (degree % 2 != 0)
		{
			odd++;
		}
	}
	if (odd == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ShowAdjacencyMatrix(int** p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(p + i) + j) << " ";
		}
		cout << endl;
	}
}

void ShowEulerPath(int* path, int n)
{
	cout << "生成的欧拉路为：";
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			cout << path[i] + 1;
		}
		else
		{
			cout << path[i] + 1 << " -> ";
		}
	}
	cout << endl;
}

void ShowEulerCircuit(int* path, int n)
{
	cout << "生成的欧拉回路为：";
	for (int i = 0; i < n; i++)
	{
			cout << path[i] + 1 << " -> ";
	}
	cout << path[0] + 1;
	cout << endl;
}

//void MatrixMultiplication(int** p, int** multi_p, int n, int eps = 2)
//{
//	if (eps < 1)
//	{
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			*(*(multi_p + i) + j) = *(*(p + i) + j);
//		}
//	}
//	for (int ep = 1; ep < eps; ep++)
//	{
//		int ** temp = new int* [n];
//		for (int i = 0; i < n; i++)
//		{
//			*(temp + i) = new int[n];
//			for (int j = 0; j < n; j++)
//			{
//				*(*(temp + i) + j) = *(*(multi_p + i) + j);
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				int sum = 0;
//				for (int k = 0; k < n; k++)
//				{
//					sum += *(*(p + i) + k) * (*(*(temp + k) + j));
//				}
//				*(*(multi_p + i) + j) = sum;
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			delete[] temp[i];
//		}
//		delete[] temp;
//	}
//}

//void FindEulerPath(int** p, int n)
int* FindEulerPath(int** p, int n, int& pathLength) 
{
	int* path = new int[n];
	int* visited = new int[n] {0};
	int pathIndex = 0; 
	int startVertex = -1;
	for (int i = 0; i < n && startVertex == -1; ++i)
	{
		int degree = 0;
		for (int j = 0; j < n; ++j)
			degree += p[i][j];
		if (degree > 0)
			startVertex = i;
	} 
	if (startVertex == -1)
	{
		pathLength = 0;
		delete[] path;
		delete[] visited;
		return nullptr;
	}
	dfs(p,n,startVertex,path,pathIndex,visited);
	pathLength = pathIndex; 
	delete[] visited; 
	return path;
}


int* FindEulerCircuit(int** p, int n, int& pathLength)
{
	int* path = new int[n];
	int* visited = new int[n] {0};
	int pathIndex = 0;
	int startVertex = 0;
	dfs(p, n, startVertex, path, pathIndex, visited);
	pathLength = pathIndex;
	delete[] visited;
	return path;
}




bool dfs(int** p, int n, int currentVertex, int* path, int pathIndex, int* visited) {
	visited[currentVertex] = 1;
	path[pathIndex++] = currentVertex;
	for (int nextVertex = 0; nextVertex < n; ++nextVertex) 
	{
		if (p[currentVertex][nextVertex] > 0) 
		{  
			p[currentVertex][nextVertex] = 0; 
			p[nextVertex][currentVertex] = 0; 

			if (!visited[nextVertex] && dfs(p, n, nextVertex, path, pathIndex, visited)) 
				return true;
			p[currentVertex][nextVertex] = 1; 
			if (p[nextVertex][currentVertex] == 0) 
				p[nextVertex][currentVertex] = 1;
		}
	}
	--pathIndex;
	return false;
}

//bool dfs(int** p, int n, int currentVertex, std::vector<int>& path, int& pathIndex, std::vector<bool>& visited) {
//	visited[currentVertex] = true;
//	path[pathIndex++] = currentVertex;
//
//	for (int nextVertex = 0; nextVertex < n; ++nextVertex) {
//		if (p[currentVertex][nextVertex] > 0) {
//			p[currentVertex][nextVertex] = 0; // 标记边为已访问  
//			if (p[nextVertex][currentVertex] > 0) // 如果是无向图  
//				p[nextVertex][currentVertex] = 0; // 也要标记反向边为已访问  
//
//			if (!visited[nextVertex] && dfs(p, n, nextVertex, path, pathIndex, visited))
//				return true;
//
//			// 回溯时恢复边  
//			p[currentVertex][nextVertex] = 1;
//			if (p[nextVertex][currentVertex] == 0)
//				p[nextVertex][currentVertex] = 1;
//		}
//	}
//	--pathIndex;
//	return false;
//}



//int* FindEulerCircuit(int** p, int n, int& pathLength) {
//	if (p == nullptr || n <= 0) {
//		pathLength = 0;
//		return nullptr;
//	}
//
//	// 初始化访问数组和路径数组  
//	std::vector<bool> visited(n, false);
//	std::vector<int> path(n); // 假设最多有n个顶点在回路中  
//	int pathIndex = 0;
//
//	// 找到欧拉回路的起始顶点（通常选择度数为偶数的顶点）  
//	// 这里简化处理，假设第一个度数为偶数的顶点就是起始点  
//	int startVertex = -1;
//	for (int i = 0; i < n && startVertex == -1; ++i) {
//		int degree = 0;
//		for (int j = 0; j < n; ++j) {
//			degree += p[i][j];
//		}
//		if (degree % 2 == 0) {
//			startVertex = i;
//		}
//	}
//
//	if (startVertex == -1) {
//		// 没有找到度数为偶数的顶点，无法形成欧拉回路  
//		pathLength = 0;
//		return nullptr;
//	}
//
//	// 从起始顶点开始DFS搜索  
//	if (dfs(p, n, startVertex, path, pathIndex, visited)) {
//		// 如果DFS成功，调整pathIndex到正确的路径长度  
//		pathLength = pathIndex;
//
//		// 分配新内存并复制路径  
//		int* eulerCircuit = new int[pathLength];
//		for (int i = 0; i < pathLength; ++i) {
//			eulerCircuit[i] = path[i];
//		}
//
//		return eulerCircuit;
//	}
//
//	// DFS失败，没有找到欧拉回路  
//	pathLength = 0;
//	return nullptr;
//}

//int* FindEulerPath(int** p, int n)
//{
//	int* path = new int[n];
//	int* degree = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		degree[i] = 0;
//		for (int j = 0; j < n; j++)
//		{
//			degree[i] += *(*(p + i) + j);
//		}
//	}
//	int* stack = new int[n];
//	int top = 0;
//	stack[top] = 0;
//	int* path_top = path;
//	while (top >= 0)
//	{
//		int i = stack[top];
//		int j = 0;
//		while (j < n && *(*(p + i) + j) == 0)
//		{
//			j++;
//		}
//		if (j == n)
//		{
//			*path_top = i;
//			path_top++;
//			top--;
//		}
//		else
//		{
//			top++;
//			stack[top] = j;
//			*(*(p + i) + j) = 0;
//			*(*(p + j) + i) = 0;
//		}
//	}
//	delete[] stack;
//	delete[] degree;
//	return path;
//}

//int* FindEulerCircuit(int** p, int n)
//{
//	int* path = new int[n+1];
//	int* degree = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		degree[i] = 0;
//		for (int j = 0; j < n; j++)
//		{
//			degree[i] += *(*(p + i) + j);
//		}
//	}
//	int* stack = new int[n];
//	int top = 0;
//	stack[top] = 0;
//	int* path_top = path;
//	while (top >= 0)
//	{
//		int i = stack[top];
//		int j = 0;
//		while (j < n && *(*(p + i) + j) == 0)
//		{
//			j++;
//		}
//		if (j == n)
//		{
//			*path_top = i;
//			path_top++;
//			top--;
//		}
//		else
//		{
//			top++;
//			stack[top] = j;
//			*(*(p + i) + j) = 0;
//			*(*(p + j) + i) = 0;
//		}
//	}
//	delete[] stack;
//	delete[] degree;
//	*(path+n) = *path;
//	return path;
//}