#include "KdTree.h"

vector<vd> Dataset; // Parsed from Input File
vector<vector<int> > DimSortedDataset; // Precomputed Once -> Stores sorted Pointers to Original Dataset
int DIMENSIONS; // To be set by Parser Function

void parseInput(char *filename)//Parse and fill Dataset
{
	ifstream in;
	in.open(filename);

	int n;//number of points
	in>>DIMENSIONS>>n;
	for(int i=0;i<n;++i)
	{
		vd temp;
		for(int j=0;j<DIMENSIONS;++j)
		{
			double a;
			in>>a;
			temp.push_back(a);
		}
		Dataset.push_back(temp);
	}
}

void preprocessing()
{
	int instances=Dataset.size();
	DimSortedDataset.resize(DIMENSIONS);

	cerr << instances << endl;
	cerr << DIMENSIONS << endl;
	for (int i = 0; i < DIMENSIONS; i++)
	{
		// cerr << i << endl;

		DimSortedDataset[i].resize(instances);
		for(int j=0;j<instances;j++)
		{
				DimSortedDataset[i][j]=j;
		}
		sort(DimSortedDataset[i].begin(),DimSortedDataset[i].end(),CustomComparator(i));
		// https://stackoverflow.com/questions/4066576/passing-a-parameter-to-a-comparison-function
	}
	// for(int i=0;i<DIMENSIONS;i++)
	// {
	// 	cout<<i<<"hi"<<endl;
	// 	for(int j=0;j<instances;j++)
	// 		cout<<DimSortedDataset[i][j]<<endl;
	// }
}

vector<vector<kd_tree_node *> > result;

int main(int argc, char* argv[])
{
	// cerr << "started" << endl;
	char* dataset_file = argv[1];
	parseInput(dataset_file);
	// cerr<<"input parsed"<<endl;
	preprocessing();
	// [TODO] Construct kdTree using dataset_file here
	// cerr << "started making tree"<<endl;
	kd_tree_node * root=make_tree(DimSortedDataset,0);

	// cerr<<"tree made"<<endl;
	
	ofstream rfile;
	rfile.open("results.txt");

	char* query_file = new char[100];
	ifstream qfile;
	int d,n2;
	int k;
	cout << 0 << endl;

	// Wait till the parent responds with name/path of query_file and k | Timer will start now
	cin >> query_file;

	qfile.open(query_file);

	qfile>>d>>n2;
	cin>>k;

	// string resfile = "./Results/resultskd_" + to_string(k) + "_" + to_string(d) + ".txt";
	// rfile.open(resfile);


// cerr<<n2<<" queries"<<endl;
result.resize(n2);
for(int z=0;z<n2;++z)
{
	// cerr<<z<<endl;
	vector<double> query_point;
	for(int i=0;i<d;++i)
	{
		double a;
		qfile>>a;
		query_point.push_back(a);
	}


	knn(root,query_point,k);


	// vector<kd_tree_node *> result;
	int len=k;
	result[z].resize(len);
	int index=len;

	while(!max_heap.empty())
	{
		index--;
		kd_tree_node* r=max_heap.top();
		max_heap.pop();
		result[z][index]=r;
	}

	// for (int i = 0; i < d; ++i)
	// {
	// 	rfile << query_point[i]<<" ";
	// }
	// rfile << "\n";

	// for (int i = 0; i < len; ++i)
	// {
	// 	kd_tree_node *r = result[i] ;
	// 	for (int j = 0; j < DIMENSIONS; ++j)
	// 	{
	// 		rfile << (r->Datapoint[j]) << ' ';
	// 	}
	// 	// rfile << (result[i]->distance) << " ";
	// 	rfile << "\n";
	// }
}


for(int z=0;z<n2;++z)
{
for (int i = 0; i < k; ++i)
{
	kd_tree_node * r = result[z][i];
	for (int j = 0; j < DIMENSIONS; ++j)
	{
		rfile << (r->Datapoint[j]) << ' ';
	}
	// rfile << (result[i]->distance) << " ";
	rfile << "\n";
}
}

rfile.close();

cout << 1 << endl;
// [TODO] Read the query point from query_file, do kNN using the kdTree and output the answer to results.txt

// Convey to parent that results.txt is ready by sending "1" on stdout | Timer will stop now and this process will be killed
}
