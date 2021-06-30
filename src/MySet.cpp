#include "MySet.h"

MySet::MySet(){
}

MySet::MySet(vector<string> sets){
    elements = sets;
}

void MySet::Union(MySet& set2, MySet& outSet){
    outSet.elements = elements;
    int sOut = outSet.elements.size();

    for (int i = 0; i < set2.elements.size(); i++){
        bool hasDuplicate = false;
        for (int j = 0; j < sOut ; j++){
            if (outSet.elements[j]== set2.elements[i]){
                hasDuplicate = true;
            }
        }
        if(!hasDuplicate){
            outSet.elements.push_back(set2.elements[i]);
        }
    }
}

void MySet::Intersection(MySet& set2, MySet& outSet){
    for (int i = 0; i < elements.size(); i++){
        for (int j = 0; j < set2.elements.size() ; j++){
            if (elements[i]== set2.elements[j]){
                outSet.elements.push_back(elements[i]);
            }
        }
    }
}

void MySet::Diffference(MySet& set2, MySet& outSet){
    for (int i = 0; i < elements.size(); i++){
        bool hasDuplicate = false;
        for (int j = 0; j < set2.elements.size(); j++){
            if (elements[i] == set2.elements[j]){
                hasDuplicate = true;
            }
        }
        if (!hasDuplicate){
            outSet.elements.push_back(elements[i]);
        }
    }
}



