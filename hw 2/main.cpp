#include <iostream>
#include "CharacterFrequencies.h"
using namespace std;



int main(){
    string line2 = "Twinkle twinkle little star, how I wonder what you are.";
    cout << line2 << endl;
    cout<<"asd"<<endl;
    CharacterFrequencies line2CharFreq(line2);
    line2CharFreq.printFrequencies();
    
    line2CharFreq.readString(line2);
    line2CharFreq.printFrequencies();
    
    return 0;
}