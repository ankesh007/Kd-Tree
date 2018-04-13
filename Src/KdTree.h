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

kd_tree_node *make_tree(vector<vector<int> > &DimSortedDataset,int dimCut);
void knn(kd_tree_node *root, vector<double> &q, int k); 
void naive_knn(vector<double> &q, int k); 

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
		if(i->distance!=j->distance)
			return i->distance < j->distance;
		bool flag=false;
		for(int d=0;d<DIMENSIONS;d++)
		{
			if(i->Datapoint[d]<j->Datapoint[d])
				break;
			if(i->Datapoint[d]>j->Datapoint[d])
			{
				flag=false;
				break;
			}
		}
	}
};

struct maxheapComparator2
{
	bool operator()(pair<double,int> i,pair<double,int> j)
	{
		return i.x < j.x;
	}
};

struct minheapComparator
{
	bool operator()(kd_tree_node *i, kd_tree_node *j)
	{
		return i->lowerbound > j->lowerbound;
	}
};
extern priority_queue<kd_tree_node *, vector<kd_tree_node *>, maxheapComparator> max_heap;
extern priority_queue<pair<double,int>, vector<pair<double,int> >, maxheapComparator2> naive_max_heap;

#endif