#include "KdTree.h"

//Returns L^2 distance between 2 dataPoints
double getDistance(vd &a,vd &b)
{
	long dist=0;
	for(int i=0;i<DIMENSIONS;i++)
		dist+=(a[i]-b[i])*(a[i]-b[i]);
	return dist;
}
