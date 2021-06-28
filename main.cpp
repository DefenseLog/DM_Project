#include <iostream>
#include <vector>
#include <MySet.h>

using namespace std;

string del(string input, char cDel);
string getElements(string& input, char stop);
void show(vector <string> element);
vector<string> elementParser(string& input);
string identify(string& input);

char getOperand(string& input);

const char START = '[';
const char END = ']';
const char UNION = '+';
const char INTERSECTION = '*';
const char DIFFERENCE = '-';


int main(){
    string inputs;
    string duplicateInput;

    inputs = "[112, 231, 65312, 13] * [6, 4, 7, 8]";

    MySet setOne;
    char operand;
    MySet setTwo;

    MySet outSet;


    //cout << "Input: ";
    //getline(cin, inputs);
   // duplicateInput = inputs;

    cout << "Inputs: " << inputs << endl << endl;

    cout << "Getting the first set" << endl;
    string deleted = del(inputs, ' ');
    cout << "Deleted Space: " << deleted << endl;
    string set1 = del(del(getElements(deleted, END),START), END);
    cout << "Set 1: " << set1 << endl;
    cout << "This is inside a vector: "; show(elementParser(set1));
    cout << "Set 1: " << set1 << endl;
    cout << "Input: " << inputs << endl;
    cout << "Remaining Input: " << deleted << endl << endl;

    cout << "Getting the Operand" << endl;
    cout << "Operator "<<getOperand(deleted) << endl;
    cout << "Remaining Input: " << deleted << endl << endl;

    cout << "Getting the second set" << endl;
    string set2 = del(del(getElements(deleted, END),START), END);
    cout << "Set 2: " << set2 << endl;
    cout << "This is inside a vector: "; show(elementParser(set2));
    cout << "Set 2: " << set2 << endl;
    cout << "Input: " << inputs << endl;
    cout << "Remaining Input: " << deleted << endl << endl;
    return 0;
}

//Shows all items inside a vector
void show(vector<string> element){
    for(int i = 0; i < element.size(); i++){
        cout << element[i] << ',';
    }
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
    return out;
}

//Stores the identified elements to a vector
vector<string> elementParser(string& input){
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
