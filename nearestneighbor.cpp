#include<iostream>
#include "VectorDataset.h"
#include "DataVector.h"
#include <fstream>
#include <sstream>
#include<algorithm>
#include<vector>
#include<chrono>

using namespace std;

/*
As sir told in email that due to time constraints, we take only 100 test vectors and find their k nearest neighbors.
So, I take 100 test vectors and find their k nearest neighbors.


We have to store the dataset in a vector of DataVector so I make a vector of DataVector in private section of the class.
We have to read the dataset from a file so I make ReadDataset fxn to read it in a vector of DataVector.
We have to find the k nearest neighbors of a given DataVector so I make knearestneighbor fxn to find it.


I make a main fxn to take the value of k and read the dataset from a file and find the k nearest neighbors of a given DataVector.
I make ans.txt file to store the output of the program.
*/

VectorDataset::VectorDataset() {}
VectorDataset::~VectorDataset() {}
void VectorDataset::addData_Vector(const DataVector &dataVector) {
  dataset.push_back(dataVector);
}
DataVector VectorDataset::get_dataVector(int point) const {
  return dataset[point];
  // cout << "Inside get_dataVector function: point = " << point << endl;
}
int VectorDataset::size() const { return dataset.size(); }



VectorDataset knearestneighbor(const VectorDataset& trainDataset,const DataVector &test,int k){
    VectorDataset knearest;
    // cout<<trainDataset.size()<<endl;
    int t=trainDataset.size();
    vector<vector<double>> Store_distance(t, vector<double>(2, 0.0));
    for(int i=0;i<t;i++){
        try {
        double duri=test.dist(trainDataset.get_dataVector(i));
        Store_distance[i][0]=duri;
        }
        catch (const std::bad_alloc& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return knearest;
        }
        Store_distance[i][1]=i;
    } 
    // cout << "Reached point 2" << endl;
    sort(Store_distance[0].begin(),Store_distance[0].end());
    for(int i=0;i<k;i++){
        knearest.addData_Vector(trainDataset.get_dataVector(Store_distance[i][1]));
    }
    // cout << "Reached point 3" << endl;
    return knearest;
}


VectorDataset ReadDataset(const string& fmnist_train) {
    VectorDataset dataset;
    ifstream file(fmnist_train);
    if (!file.is_open()) {
        cout << "Error: Unable to open file -" << endl;
        return dataset;
    }
    string line;
    while (getline(file, line)) {
        DataVector dataVector;
        istringstream iss(line);
        string input;
        while (getline(iss, input, ',')) {
            double data = stod(input);
            dataVector.addValue(data);
        }
        dataset.addData_Vector(dataVector);
    }
    return dataset;
}


int main(){
    int k;
    cout<<"Enter value of K: ";
    cin>>k;
    string fmnist_test = "fmnist_test.csv";
    VectorDataset testDataset = ReadDataset(fmnist_test);
    string fmnist_train = "fmnist_train.csv";
    VectorDataset trainDataset = ReadDataset(fmnist_train);
    
    ofstream ansfile("ans.txt");
    if (!ansfile.is_open()) {
        cout << "Error Occur opening in txt file" << endl;
        return 1;
    }
    auto begin =chrono::high_resolution_clock::now();
    for(int i=900;i<1000;i++){
        VectorDataset knearest;
        DataVector test=testDataset.get_dataVector(i);
        ansfile<<"Test Vector: "<<i+1<<" "<<test<<endl;
        knearest = knearestneighbor(trainDataset,test,k);
        for(int j=0;j<knearest.size();j++){
            DataVector neighbor;
            neighbor = knearest.get_dataVector(j);
            ansfile<<"Nearest Neighbor "<<j+1<<": "<<neighbor<<endl;
        }
        ansfile<<endl;
    }
    ansfile.close();
    cout<<"Output is stored in ans.txt"<<endl;
    auto stop=chrono::high_resolution_clock::now();
    auto time=chrono::duration_cast<chrono::milliseconds>(stop-begin);
    cout<<"Time taken: "<<time.count()<<" milliseconds"<<endl;
    return 0;
}

// Command:
// g++ -c nearestneighbor.cpp -o nearestneighbor.o
// g++ -c DataVector.cpp -o DataVector.o
// g++ nearestneighbor.o DataVector.o -o nearestneighbor
// ./nearestneighbor



