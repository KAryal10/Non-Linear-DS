/*Kritan Aryal
Homework Assignment 1
EECS 2510 Spring 2024
Problem 2
*/

// Including file stream and input output libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//main function
int main(){


    ifstream inputText;  //input filestream
    char nextCharacter;  //declaring nextCharacter varible to store next character from file
    vector<char> characters;  //declaring Vector named characters to store all the characters from text file.
    vector<int> indices; //declaring Vector named indices to store all the indices of character that matched the user input
    char userWord; //declaring nextCharacter varible to store the character to be checked
    int count=0; //declaring count variable to store the number of character occurance

    inputText.open("input.txt"); //Opening our text file for reading

    //if the text file fails to open, print the message and exit with "EXIT_FAILURE" code
    if (inputText.fail()) {
        cerr << "The input file input.txt could not be opened." << endl;
        exit(EXIT_FAILURE);
    }    

    //reading each character from text file and storing all of them in the characters
    while(inputText.get(nextCharacter)){
        characters.push_back(nextCharacter);
    }

    //Prompt user to type the character they want to search for and store it in userWord variable
    cout<<"Enter the character to search for: ";
    cin>> userWord;
    

    
    //search each characters in the characters vector and increase the count if the character matches userWord
    //Also add the value of indices where the character is at to the indices vector
    for (int i=0;i<characters.size();i++){
        if (characters.at(i)==userWord){
            count++;
            indices.push_back(i);
        }
    }

    //print the number of occurrence of the character
    cout<<"The number of occurrences of the character "<<userWord<<" is "<<count<<endl;

    //If the occurrence of character is greater than 0, print the indices of the character separated by space
    if(indices.size()>0){
       cout<< "The indices of the character positions are ";

       for(int i=0;i<indices.size();i++){
        cout<< indices.at(i) << " ";
       }
       cout<<endl;
    }

    //return 0 for successful termination of program
    return 0;
}