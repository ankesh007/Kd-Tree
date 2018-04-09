#ifndef KDTREE_H
#define KDTREE_H

#include <bits/stdc++.h>

typedef long double ld ;
#define long long long int
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define MAX_DIM 22

using namespace std;
typedef vector<double> vd;

//Node Structure of KD Tree
struct kd_tree_node
{
	vd Datapoint;
	vd minRect,maxRect;
	kd_tree_node *lef,*rig;
	double distance;
	double lowerbound;
};

extern vector<vd> Dataset; // Parsed from Input File
extern vector<vector<int> > DimSortedDataset; // Precomputed Once -> Stores sorted Pointers to Original Dataset
extern int DIMENSIONS; // To be set by Parser Function

kd_tree_node *make_tree(vector<vector<int> > DimSortedDataset,int dimCut);
void knn(kd_tree_node *root, vector<double> &q, int k); 

struct CustomComparator
{
	CustomComparator(int parameter)
	{
		this->parameter=parameter;
	}
	bool operator()(int i,int j)
	{
		return Dataset[i][parameter]<Dataset[j][parameter];
	}
	int parameter;
};

struct maxheapComparator
{
	bool operator()(kd_tree_node *i, kd_tree_node *j)
	{
		return i->distance > j->distance;
	}
};

struct minheapComparator
{
	bool operator()(kd_tree_node *i, kd_tree_node *j)
	{
		return i->lowerbound < j->lowerbound;
	}
};

#endif