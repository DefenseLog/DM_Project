

#ifndef MYSET_H
#define MYSET_H

#include <vector>
#include <iostream>

using namespace std;

class MySet
{
    public:
        MySet();


        void Union(MySet&, MySet&);
        void Intersection(MySet&, MySet&);
        void Diffference(MySet&, MySet&);
        vector<string> getSet();
        void setSet(vector<string>& assigned);
        vector<string> elements;

    protected:

    private:

};

#endif // MYSET_H
