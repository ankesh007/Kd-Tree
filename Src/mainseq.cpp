#include "KdTree.h"

vector<vd> Dataset;					  // Parsed from Input File
vector<vector<int>> DimSortedDataset; // Precomputed Once -> Stores sorted Pointers to Original Dataset
int DIMENSIONS;						  // To be set by Parser Function

void parseInput(char *filename) //Parse and fill Dataset
{
	ifstream in;
	in.open(filename);

	int n; //number of points
	in >> DIMENSIONS >> n;
	for (int i = 0; i < n; ++i)
	{
		vd temp;
		for (int j = 0; j < DIMENSIONS; ++j)
		{
			double a;
			in >> a;
			temp.push_back(a);
		}
		Dataset.push_back(temp);
	}
}

void preprocessing()
{
	int instances = Dataset.size();
	DimSortedDataset.resize(DIMENSIONS);

	cerr << instances << endl;
	cerr << DIMENSIONS << endl;
	for (int i = 0; i < DIMENSIONS; i++)
	{
		// cerr << i << endl;

		DimSortedDataset[i].resize(instances);
		for (int j = 0; j < instances; j++)
		{
			DimSortedDataset[i][j] = j;
		}
		sort(DimSortedDataset[i].begin(), DimSortedDataset[i].end(), CustomComparator(i));
		// https://stackoverflow.com/questions/4066576/passing-a-parameter-to-a-comparison-function
	}
	// for(int i=0;i<DIMENSIONS;i++)
	// {
	// 	cout<<i<<"hi"<<endl;
	// 	for(int j=0;j<instances;j++)
	// 		cout<<DimSortedDataset[i][j]<<endl;
	// }
}

int main(int argc, char *argv[])
{
	cerr << "started" << endl;
	char *dataset_file = argv[1];
	parseInput(dataset_file);
	cerr << "input parsed" << endl;
	preprocessing();


	// Request name/path of query_file from parent by just sending "0" on stdout
	ofstream rfile;

	// rfile.open("results.txt");
	cout << 0 << endl;

	// Wait till the parent responds with name/path of query_file and k | Timer will start now
	char *query_file = new char[100];
	cin >> query_file;

	ifstream qfile;
	qfile.open(query_file);

	int d, n2;
	qfile >> d >> n2;
	int k;
	cin >> k;

	string resfile = "./Results/resultsseq_" + to_string(k) + "_" + to_string(d)+".txt" ;
	rfile.open(resfile);

	cerr << "k received" << endl;

	cerr << n2 << " queries" << endl;
	for (int z = 0; z < n2; ++z)
	{
		cerr <<"z="<< z << endl;
		vector<double> query_point;
		for (int i = 0; i < d; ++i)
		{
			double a;
			qfile >> a;
			query_point.push_back(a);
		}

		naive_knn(query_point, k);

		vector<pair<double, int>> result;
		int len = naive_max_heap.size();
		result.resize(len);
		int index = len;

		while (!naive_max_heap.empty())
		{
			index--;
			pair<double, int> r = naive_max_heap.top();
			naive_max_heap.pop();
			result[index] = r;
		}


		for (int i = 0; i < len; ++i)
		{
			int idx = result[i].second ;
			// cerr<<"idx-"<<idx<<endl;
			for (int j = 0; j < DIMENSIONS; ++j)
			{
				rfile << (Dataset[idx][j]) << " ";
			}
			rfile << result[i].first;
			rfile	  << "\n";
		}
	}

	cout << 1 << endl;

	rfile.close();

	// [TODO] Read the query point from query_file, do kNN using the kdTree and output the answer to results.txt

	// Convey to parent that results.txt is ready by sending "1" on stdout | Timer will stop now and this process will be killed
}
