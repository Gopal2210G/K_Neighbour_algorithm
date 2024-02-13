#ifndef VECTORDATASET_H
#define VECTORDATASET_H

#include "DataVector.h"
using namespace std;
/*
VectorDataset class is a class that represents a vector of DataVector values and dataset is in private section. It have some functions to perform operations with vectors.
some of the functions are:
---VectorDataset(): It is a constructor of the VectorDataset class.
---~VectorDataset(): It is a destructor of the VectorDataset class.
1. addData_Vector: It is a function that adds a DataVector to the dataset.
2. get_dataVector: It is a function that returns the DataVector at a given index.
3. ReadDataset: It is a function that reads the dataset from a file and returns the dataset.
4. knearestneighbor: It is a function that returns the k nearest neighbors of a given DataVector.
5. size: It is a function that returns the size of the dataset.
*/
class VectorDataset{
    private:
    vector<DataVector> dataset;

    public:
    VectorDataset();
    ~VectorDataset();
    void addData_Vector(const DataVector & dataVector);
    DataVector get_dataVector(int index) const;
    VectorDataset ReadDataset(const string& fmnist_train);
    VectorDataset knearestneighbor(const VectorDataset& trainDataset,const DataVector &test,int k);
    int size() const;
};

#endif