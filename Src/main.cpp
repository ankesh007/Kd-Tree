#include "KdTree.h"

vector<vd> Dataset; // Parsed from Input File
vector<vector<int> > DimSortedDataset; // Precomputed Once -> Stores sorted Pointers to Original Dataset
int DIMENSIONS; // To be set by Parser Function

void parseInput(char *filename)//Parse and fill Dataset
{

}

void preprocessing()
{
	int instances=Dataset.size();
	DimSortedDataset.resize(DIMENSIONS);

	for(int i=0;i<DIMENSIONS;i++)
	{
		DimSortedDataset.resize(instances);
		for(int j=0;j<instances;j++)
			DimSortedDataset[i][j]=j;
		sort(DimSortedDataset[i].begin(),DimSortedDataset[i].end(),CustomComparator(i));
		// https://stackoverflow.com/questions/4066576/passing-a-parameter-to-a-comparison-function
	}
}


int main(int argc, char* argv[]) {

	char* dataset_file = argv[1];

	// [TODO] Construct kdTree using dataset_file here

	// Request name/path of query_file from parent by just sending "0" on stdout
	cout << 0 << endl;

	// Wait till the parent responds with name/path of query_file and k | Timer will start now
	char* query_file = new char[100];
	int k;
	cin >> query_file >> k;
	// cerr << dataset_file << " " << query_file << " " << k << endl;

	// [TODO] Read the query point from query_file, do kNN using the kdTree and output the answer to results.txt

	// Convey to parent that results.txt is ready by sending "1" on stdout | Timer will stop now and this process will be killed
	cout << 1 << endl;
}
