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
};

extern vector<vd> Dataset; // Parsed from Input File
extern vector<vector<int> > DimSortedDataset; // Precomputed Once -> Stores sorted Pointers to Original Dataset
extern int DIMENSIONS; // To be set by Parser Function

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

#endif