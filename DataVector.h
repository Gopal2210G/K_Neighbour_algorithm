#ifndef DATAVECTOR_H
#define DATAVECTOR_H
#include <iostream>
#include <vector>

/*
DataVector class is a class that represents a vector of double values and vector v is in private section. It have some functions to perform operations with vectors.
some of the functions are:

---DataVector(int dimension=0): It is a constructor of the DataVector class and sets the dimension of the vector.
---DataVector(const DataVector& other): It is a copy constructor of the class.
1. ~DataVector(): It is a destructor of the class.
2. setDimension: It is constructor of the class and sets the dimension of the vector.
3. operator=: It is a function that overloads the = operator to assign the value of one vector to another.
4. operator+: It is a function that adds two vectors.
5. operator-: It is a function that subtracts two vectors.
6. operator*: It is a function that returns the dot product of two vectors.
7. dist: It is a function that returns the distance between two vectors.
8. norm: It is a function that returns the norm of the vector.
9. addValue: It is a function that adds a value to the vector.
10. operator<<: It is a function that overloads the << operator to print the vector.
*/
class DataVector{
    private:
    std::vector<double> v;
    public:
    DataVector(int dimension=0);
    ~DataVector();
    DataVector(const DataVector& other);
    DataVector & operator=(const DataVector &other);
    void setDimension(int dimension=0);
    DataVector operator+(const DataVector &other);
    DataVector operator-(const DataVector &other);
    double operator*(const DataVector &other);
    double dist(const DataVector &other)const;
    double norm();
    void addValue(double value);
    friend std::ostream& operator<<(std::ostream& os, const DataVector& object);
};
std::ostream& operator<<(std::ostream& os, const DataVector& object);
#endif
