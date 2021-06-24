#ifndef MYSET_H
#define MYSET_H


class MySet
{
    public:
        MySet();
        virtual ~MySet();

        void Union(MySet, MySet);
        void Intersection(MySet, MySet);
        void Diffference(MySet, MySet);
        vector<unsigned int> getSet();
        void setSet(vector<unsigned int> assigned);

    protected:

    private:
        unsigned int cardinality;
        vector<unsigned int> elements;
};

#endif // MYSET_H
