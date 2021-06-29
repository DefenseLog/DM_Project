#include <iostream>
#include <vector>
#include <MySet.h>

using namespace std;

string del(string input, char cDel);
string getElements(string& input, char stop);
void show(vector <string> element);
vector<string> elementParser(string input);
string identify(string& input);

char getOperand(string& input);

const char START = '[';
const char END = ']';
const char UNION = '+';
const char INTERSECTION = '*';
const char DIFFERENCE = '-';


int main(){
    string inputs;

    //inputs = "[1, 2, 3, 4] + [4, 5, 6, 7]";
    char operand;
    MySet outSet;

    cout << "Input: ";
    getline(cin, inputs);

    //cout << "Inputs: " << inputs << endl << endl;
    string deleted = del(inputs, ' ');

    MySet setOne(elementParser(getElements(deleted, END)));
    operand = getOperand(deleted);;
    MySet setTwo(elementParser(getElements(deleted, END)));

    switch(operand){
        case UNION:
            setOne.Union(setTwo, outSet);
            break;
        case INTERSECTION:
            setOne.Intersection(setTwo, outSet);
            break;
        case DIFFERENCE:
            setOne.Diffference(setTwo, outSet);
            break;
    }

    cout << "Output: "; show(outSet.elements);
    return 0;
}

//Shows all items inside a vector
void show(vector<string> element){
    cout << '[';
    for(int i = 0; i < element.size(); i++){
        if(i != element.size() - 1){
            cout << element[i] << ',';
        }
        else{
            cout << element[i];
        }
    }
    cout << ']';
    cout << endl;
}

//Deletes the character cDel
string del(string input, char cDel){
    int pos = input.find(cDel);
    if(pos != string::npos){
        return del(input.erase(pos, 1), cDel);
    }
    else{
        return input;
    }
}

//Gets all characters until character stop
string getElements(string& input, char stop){
    string out;
    int pos  = input.find(stop);
    for(int i = 0; i <= pos; i++){
        out += input[i];
    }
    input.erase(0, pos + 1);
    out = del(del(out, START), END);
    return out;
}

//Stores the identified elements to a vector
vector<string> elementParser(string input){
    vector<string> out;
    while(!input.empty()){
        out.push_back(identify(input));
    }
    return out;
}


//Element Identifier
string identify(string& input){
    int pos = input.find(',');
    string out;
    if(pos != string::npos){
        for(int i = 0; i < pos; i++){
            out += input[i];
        }
        input.erase(0, pos+1);
        return out;
    }
    else if(!input.empty()){
        out = input;
        input.erase();
        return out;
    }
}

//Gets the operator;
char getOperand(string& input){
    char operators[3] = {UNION, INTERSECTION, DIFFERENCE};
    for(int i = 0;  i < 3; i++){
        int pos =input.find(operators[i]);
        if( pos != string::npos){
            input.erase(pos, 1);
            return operators[i];
        }
    }
}
