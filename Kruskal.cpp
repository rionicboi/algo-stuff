// Kruskal's algorithm in C++

#include<iostream>
#include<vector>
#include<algorithm>
#include"DoublyLinkedList.h"

using namespace std ;

class Kruskal {
	private:
		DLinkedList<int>* vert_list ;
		vector< pair<int, pair<int, int> > > mstTree ;
		int vertSize ;
		int edgeSize ;
		int* setName ;
	public:
		Kruskal() ;
		~Kruskal() ;
		
		void input() ;
		int findSetName(int i) ;
		void Union(int u, int v) ;
		void kruskal() ;
		void printMst() ;
		int mstLength() ;
};

Kruskal :: Kruskal() {
	vertSize = 0 ;
	edgeSize = 0;
	setName = 0 ;
	vert_list = 0 ;
}

Kruskal :: ~Kruskal() {
	delete[] setName ;
	delete[] vert_list ;
}

void Kruskal :: input() {
	cout << "\n\n\t\t\t\t\tEnter the details of vertices of graph\n\n" ;
	
	cout << "\nEnter the number of vertex :   " ;
	cin >> vertSize ;
	
	setName = new int[vertSize] ;
	vert_list = new DLinkedList<int>[vertSize] ;
	
	for(int i=0 ; i<vertSize ; i++) {
		setName[i] = i ;
	}
				

	cout << "Enter the details of edges of graph" ;
	
	cout << "How many edges in your graph?  :   " ;
	cin >> edgeSize ;
	
	for(int i=0; i<edgeSize ; i++) {
		int vert1, vert2, wt ;
		
		cout << "Enter the vertices that joined by edge e" <<i + 1 << endl << endl ;
		cout << "Enter first vertex  :  " ;
		cin >> vert1 ;
		
		cout << "Enter second vertex :  " ;
		cin >> vert2 ;
		
		cout << "Enter the weight of edge e" << i+1 << " :   " ;
		cin >> wt ;
		
		if((vert1 > 0 && vert1 <= vertSize) && (vert2 > 0 && vert2 <= vertSize)) {
			vert_list[vert1 - 1].addBack(wt, vert2 - 1) ;
		}else {
			i-- ;
		
			cout << "\n\n\t\t\t\t\t\tVertex does'nt exist\n" ;
	
	}
	
	cout << endl << endl ;
	
	return ;
}

int Kruskal :: findSetName(int i) {
	if(i == setName[i])
		return i ;
	else
		return findSetName(setName[i]) ;
}

void Kruskal :: Union(int u, int v) {
	setName[u] = setName[v] ;
}

void Kruskal ::kruskal() {
	int uSetname, vSetname, k = 0 ;
	vector< pair<int, pair<int, int> > > storeEdges ;
	
	for(int i=0 ; i<vertSize ; i++) {
		DNode<int>* temp = vert_list[i].getHeader() ;
		
		for(temp = temp->getNext() ; temp != vert_list[i].getTrailer() ; temp = temp->getNext()) 
			storeEdges.push_back(make_pair(temp->getFirst(), make_pair(i, temp->getSecond()))) ;
		
		delete[] temp ;
	}
	
	sort(storeEdges.begin(), storeEdges.end()) ;
	
	for(int i = 0 ; i<storeEdges.size() ; i++) {
		uSetname = findSetName(storeEdges[i].second.first) ;
		vSetname = findSetName(storeEdges[i].second.second) ;
			
		if(uSetname != vSetname) {
			mstTree.push_back(storeEdges[i]) ;
			Union(uSetname, vSetname) ;
		}
	}
	
	return ;
}

void Kruskal :: printMst() {
	cout << "\nVertex explored in order:   {\n" ;
	
	for(int i=0 ; i<mstTree.size() ; i++)
		cout << endl << "\t" << mstTree[i].second.first + 1 << "  -->  " << mstTree[i].second.second + 1 << " :  " << mstTree[i].first ;
		
	cout << "\n\n   }" ;
}

int Kruskal :: mstLength() {
	int sum = 0 ;
	
	for(int i=0 ; i<mstTree.size() ; i++)
		sum = sum + mstTree[i].first ;

	return sum ;
}

int main() {
	char option ;
	int source ;
	
	do {
		system("cls") ;
		
		Kruskal ob ;
		ob.input() ;
		
		ob.kruskal() ;
		
		cout << "\n\n\t\t\t\t\t-------------------------------------------------" << endl << endl ;
		cout << "\t\t\t\t\t\t\tMinimum Spanning Tree" ;
		cout << "\n\n\t\t\t\t\t-------------------------------------------------" << endl << endl ;
		
		ob.printMst() ;
		cout << "\n\nLength of Minimum spanning tree is :   " << ob.mstLength() << endl ;
			
		cout << "\n\n\t\t\t\t\tDo you wish to continue ?(y/n) :       " ;
		cin >> option ;
		
		if(option == 'N' || option == 'n')
			exit(0);
	}while(option == 'y' || option == 'Y') ;
	
	return 0 ;
}
