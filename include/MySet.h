#ifndef MYSET_H
#define MYSET_H

#include <vector>
#include <iostream>

using namespace std;

class MySet
{
    public:
        MySet();
        MySet(vector<string> sets);

        void Union(MySet&, MySet&);
        void Intersection(MySet&, MySet&);
        void Diffference(MySet&, MySet&);
        vector<string> elements;
};

#endif // MYSET_H
