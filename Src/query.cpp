#include "KdTree.h"

//Returns L^2 distance between 2 dataPoints
double getDistance(vd &a,vd &b)
{
	long dist=0;
	for(int i=0;i<DIMENSIONS;i++)
		dist+=(a[i]-b[i])*(a[i]-b[i]);
	return dist;
}

double lowerbound(vd &mi, vd &ma, vd &a)
{
	long dist = 0;
	for (int i = 0; i < DIMENSIONS; i++)
	{
		double t1=a[i]-mi[i],t2=a[i]-ma[i];
		t1=t1*t1;
		t2=t2*t2;		
		dist += min(t1,t2);
	}
	return dist;
}


priority_queue<kd_tree_node*, vector<kd_tree_node*>, maxheapComparator> max_heap;
priority_queue<kd_tree_node*, vector<kd_tree_node*>, minheapComparator> min_heap;



void knn(kd_tree_node *root, vector<double> &q, int k)
{

	root->lowerbound = lowerbound(root->minRect, root->maxRect, q);

	min_heap.push(root);

	while(!min_heap.empty())
	{
		kd_tree_node* r=min_heap.top();
		min_heap.pop();

		if (r->lowerbound > max_heap.top()->distance)
			if(max_heap.size()>=k)
				break;

		double distance = getDistance(r->Datapoint, q);
		r->distance=distance;	/*Setting distance for the node*/

		if (max_heap.size() < k)
		{
			max_heap.push(r);
		}
		else if (distance < max_heap.top()->distance)
		{
			max_heap.pop();
			max_heap.push(r);
		}

		kd_tree_node* left=r->lef;
		kd_tree_node* right=r->rig;

		if(left!=NULL)
		{
			left->lowerbound=lowerbound(left->minRect,left->maxRect,q);
			min_heap.push(left);
			// if (left->lowerbound <= max_heap.top()->distance)
		}
		if(right!=NULL)
		{
			right->lowerbound = lowerbound(right->minRect, right->maxRect, q);
			min_heap.push(right);
			// if (right->lowerbound <= max_heap.top()->distance)
		}

	}
}