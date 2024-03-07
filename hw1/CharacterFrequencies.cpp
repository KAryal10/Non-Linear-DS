#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#include "CharacterFrequencies.h"

//creates a new object with no characters
CharacterFrequencies::CharacterFrequencies(){
    reset();  
}

//creates a new object with character frequencies initialized from the given line
CharacterFrequencies::CharacterFrequencies(string line){
    reset();
    readString(line);
}

//read line and adds character to already stored frequencies
void CharacterFrequencies::readString(string line){
    for (int i = 0; i < line.length(); i++) //using the for loop to add each character of the line
    {
        bool contains = false;
        if(frequencies.size()>0){   //Only checking the matched condition of character if the frequency contains any item
            for(int j=0; j<frequencies.size();j++){ //using for loop to check whether the character from the line already exist in the frequencies
                char c=frequencies.at(j).first; //checking only the first items of vector pair that has character
                if(c==line[i]){ //if the letter already exists set contains to true and increase the count and break inner loop
                    contains=true;
                    frequencies.at(j).second++;
                    break;
                }
            }   
        }
        if(contains==false){    //if the character does not exists then add the character with the count of 1.
            frequencies.push_back(make_pair(line[i],1));
        }
    } 
}

//This function clears all the values of the frequencies
void CharacterFrequencies::reset(){
    frequencies.clear();
}

//This function returns the frequency of the given character
int CharacterFrequencies::getFrequency(char c){
    for(int i=0; i<frequencies.size();i++){
        if(frequencies.at(i).first==c)
            return frequencies.at(i).second;
    }
    return 0;
}

//This function prints all the character along with their frequencies in each line
void CharacterFrequencies::printFrequencies(){
    for(int i=0; i<frequencies.size();i++){
        char c=frequencies.at(i).first;
        cout<<c<<": "<<getFrequency(c)<<endl;
    }
}
