/****************************/
//////////heapsort////////////
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
///////////////////////////////////////
template<typename T>
void addSymbols (int number,vector<T> &tree)
{
  T a;
for (int i=0; i<=number;i++) {
  cin>>a;
  tree.push_back(a);
  }
}
/////////////////////////////////////////
int getParent (int key)
{
	return key/2;
}
////////////////////////////////////////
int  getLeft (int key) 
{
	return key*2+1;
}
////////////////////////////////////////
int  getRight (int key) 
{
	return (key*2+2);
}
////////////////////////////////////////
///Поддержание свойств двоичной кучи///
///////////////////////////////////////
template <typename T>
void heapifyMax(vector<T> &tree,int i,int currentSize)
{	
	int largest;
	int left=getLeft(i);
	int right=getRight(i);
	if ((left<=currentSize)&&(tree.at(left)>tree.at(i)))
		largest=left;
	else largest=i;
	if ((right<=currentSize)&&(tree.at(right)>tree.at(largest)) )
		largest=right;
	if (largest!=i) {
		swap(tree.at(i),tree.at(largest));
		heapifyMax(tree,largest,currentSize);
	}//test
}
////////////////////////////////////////
     ///Построение двоичной кучи///
///////////////////////////////////////
template <typename T>
void buildMaxHeap(vector<T> &tree, int &currentSize)
{   
	currentSize=tree.size()-1;
	int k=tree.size()/2;

	while (k!=0) {
		heapifyMax(tree,k-1,currentSize);
		k--;
	}
	
	 cout<<endl;
}
////////////////////////////////////////////////
template <typename T>
void heapsort(vector<T> &tree)
{
	int currentSize=0;
	buildMaxHeap(tree,currentSize);
	int k=tree.size()-1;
	while (k!=0) {
		swap(tree.at(0),tree.at(k));
		currentSize--;
	    heapifyMax(tree,0,currentSize);
	    k--;
	}
}
template <typename T>
void show(vector<T> &tree)
{ unsigned size=0;
  while (size<tree.size()) {
	  cout<<tree.at(size)<<" ";
	  size++;
  }
  cout<<endl;
}
/////////////////////////////////////////////////////