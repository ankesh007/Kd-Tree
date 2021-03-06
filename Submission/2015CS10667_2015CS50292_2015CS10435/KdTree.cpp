#include "KdTree.h"

// Receives datapoints and splitDimension and Returns Root Node
kd_tree_node *make_tree(vector<vector<int> > &DimSortedDataset,int dimCut)
{
	if(DimSortedDataset[0].size()==0)
		return NULL;
	//Empty Tree -> NULL
	
	int instances=DimSortedDataset[0].size();	/* Points this Node Represents*/
	// kd_tree_node *node=(kd_tree_node *)malloc(sizeof(kd_tree_node));
	kd_tree_node *node = new kd_tree_node;

	node->minRect.resize(DIMENSIONS);
	node->maxRect.resize(DIMENSIONS);

	// Storing Minimum Dimension Value and Maximum Value helpful for KNN Query
	for(int i=0;i<DIMENSIONS;i++)
	{
		node->minRect[i]=Dataset[DimSortedDataset[i][0]][i];
		node->maxRect[i]=Dataset[DimSortedDataset[i][instances-1]][i];
	}

	vector<vector<int> > lefData,rigData;
	lefData.resize(DIMENSIONS);
	rigData.resize(DIMENSIONS);

	int medianDatapoint=-1;
	double medianVal=-1;

	// Deciding Median
	medianDatapoint=DimSortedDataset[dimCut][instances/2];
	medianVal=Dataset[DimSortedDataset[dimCut][instances/2]][dimCut];

	node->Datapoint=Dataset[medianDatapoint];	/*Setting Node Datapoint*/

	// Divinding datapoints into 2 disjoint multiset
	for(int i=0;i<DIMENSIONS;i++)
	{
		for(int j=0;j<instances;j++)
		{
			int originalIndex=DimSortedDataset[i][j];
			if(originalIndex==medianDatapoint)
				continue;
			else if(Dataset[originalIndex][dimCut]<=medianVal)
				lefData[i].pb(originalIndex);
			else
				rigData[i].pb(originalIndex);
		}
	}

	node->lef=make_tree(lefData,(dimCut+1)%DIMENSIONS);
	node->rig=make_tree(rigData,(dimCut+1)%DIMENSIONS);
	return node;
}
