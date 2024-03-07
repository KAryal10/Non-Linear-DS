#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#include "CharacterFrequencies.h"

CharacterFrequencies::CharacterFrequencies(){
    reset();
}

CharacterFrequencies::CharacterFrequencies(string line){
    reset();
    readString(line);
}


void CharacterFrequencies::readString(string line){
    for (int i = 0; i < line.length(); i++) 
    {
        if(frequencies.size()>0){   
            for(int j=0; j<frequencies.size();j++){ 
                if(frequencies.at(j).first==line[i]){ 
                    frequencies.at(j).second++;
                    break;
                }
            }   
        }
        frequencies.push_back(make_pair(line[i],1));
        
    } 
}


void CharacterFrequencies::reset(){
    frequencies.clear();
}


int CharacterFrequencies::getFrequency(char c){
    int count =0;
    for(int i=0; i<frequencies.size();i++){
        if(frequencies.at(i).first==c)
           count = frequencies.at(i).second;
    }
    return count;
}


void CharacterFrequencies::printFrequencies(){
    if(frequencies.size()>0){
        for(int i=0; i<frequencies.size();i++){
            cout<<frequencies.at(i).first<<": "<<frequencies.at(i).second<<endl;
        }
    }
    
}