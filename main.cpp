#include <iostream>
#include <cmath>
#include <vector>
#include <MySet.h>

using namespace std;

void parse(string& input, string& sets, char stopper);

int main(){
    const char START = '[';
    const char END = ']';
    const char UNION = '+';
    const char INTERSECTION = '*';
    const char DIFFERENCE = '-';

    string inputs;
    string duplicateInput = inputs;

    string setOne;
    string operand;
    string setTwo;

    cout << "Input: ";
    getline(cin, inputs);
    duplicateInput = inputs;

    while(duplicateInput.size()){
        switch(duplicateInput[0]){
            case UNION:
                parse(duplicateInput, operand, UNION);
                break;
            case INTERSECTION:
                parse(duplicateInput, operand, INTERSECTION);
                break;
            case DIFFERENCE:
                parse(duplicateInput, operand, DIFFERENCE);
                break;
            case START:
                if(!setOne.size() && !setTwo.size()){
                    parse(duplicateInput, setOne, END);
                }
                else if(setOne.size() && !setTwo.size()){
                    parse(duplicateInput, setTwo, END);
                }
                break;
        }
    }
    cout << "First Set: " << setOne << endl;
    cout << "Second Set: " << setTwo << endl;
    cout << "Operand: " << operand;
    return 0;
}

void parse(string& input, string& sets, char stopper){
    char stop;
    while(stop != stopper){
        stop = input[0];

        if ((input[0] != ',') && (input[0] != '[' ) && (input[0] != ']')){
            sets += input[0];
        }

        if(input[1] == ' '){
            input.erase(0,2);
        }
        else{
            input.erase(0,1);
        }
    }
}
