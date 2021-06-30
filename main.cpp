#include <iostream>
#include <vector>
#include <MySet.h>
#include <stdlib.h>
#include <limits>

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
    bool ending;

    do{
        string inputs;
        char operand;
        MySet outSet;
        ending = false;
        //Getting the Input
        cout << "Input: ";
        getline(cin, inputs);



        //----Parsing------
        //Deletes all the space inside the input
        string deleted = del(inputs, ' ');

        //Gets the Operator
        operand = getOperand(deleted);;

        //Identify the Sets
        MySet setOne(elementParser(getElements(deleted, END)));
        MySet setTwo(elementParser(getElements(deleted, END)));

        //Checks what operator to use
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

        //Shows the Output
        cout << "Output: "; show(outSet.elements);


        //Checks whether the user wants to continue
        bool again;
        do{
            again = false;
            char check;
            cout << "\nDo you want to try again? (Y/N): ";
            cin >> check;
            check = tolower(check);
            switch(check){
                case 'y':
                    system("cls");
                    break;
                case 'n':
                    ending = true;
                    break;
                default:
                    again = true;
                    break;

            }
        }while(again);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(!ending);
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
