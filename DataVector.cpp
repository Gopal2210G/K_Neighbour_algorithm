#include "DataVector.h"
#include <iostream>
#include <cmath>
using namespace std;

DataVector::DataVector(int dimension):v(dimension,0.0){}
DataVector::DataVector(const DataVector& other_v):v(other_v.v){}
DataVector::~DataVector(){}

DataVector & DataVector::operator=(const DataVector &other_v){
    if(this!=&other_v){
        v=other_v.v;
    }
    return *this;
}

void DataVector::setDimension(int dimension){
    v.resize(dimension);
}

DataVector DataVector::operator+(const DataVector &other_v){
    DataVector ans(v.size());
    for(int i=0;i<v.size();i++){
        ans.v[i]=v[i]+other_v.v[i];
    }
}

DataVector DataVector::operator-(const DataVector &other_v){
    DataVector ans(v.size());
    for(int i=0;i<v.size();i++){
        ans.v[i]=v[i]-other_v.v[i];
    }
    return ans;
}

double DataVector::operator*(const DataVector &other_v){
    double ans=0.0;
    for(int i=0;i<v.size();i++){
        ans+=v[i]*other_v.v[i];
    }
    return ans;
}

double DataVector::dist(const DataVector &other_v)const{
    if (v.size() != other_v.v.size()) {
        cout<<"Vectors are different in size"<<endl;
    }
    double sum=0.0;
    for(int i=0;i<v.size();i++){
        double diff= v[i]-other_v.v[i];
        sum += diff * diff;
    }
    // cout << "Inside dist function: sum = " << sum << endl;
    return sqrt(sum);
}

double DataVector::norm(){
    double sum=0.0;
    sum=(*this)*(*this);
    return sqrt(sum);
}

ostream& operator<<(ostream& os, const DataVector& object) {
    for (double data : object.v) {
        os << data << ' ';
    }
    return os;
}
void DataVector::addValue(double data){
    v.push_back(data);
}








