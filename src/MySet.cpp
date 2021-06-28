#include "MySet.h"


MySet::MySet()
{
}

void MySet::Union(MySet& set2, MySet& outSet){

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

}

vector<string> MySet::getSet(){
  return elements;
}

void MySet::setSet(vector<string>& assigned){
    elements = assigned;
}


