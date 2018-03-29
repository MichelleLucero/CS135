#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>


using namespace std;

void splitOnSpace(string line, string & before, string & after) {
  // reset strings
  before = ""; 
  after = "";
  // accumulate before space
  int i = 0;
  while (i < line.size() && not isspace(line[i])) { before += line[i]; i++; }
  // skip the space
  i++;
  // accumulate after space
  while (i < line.size()) { after += line[i]; i++; }
}

string transformW(string W){
    string Upper;
    for(int i=0;i<W.length(); ++i){
        if(isupper(W[i])){
            Upper+=W[i];

        }
        else if(islower(W[i])){
            Upper+=char(int(W[i])-32);
        }

        else if(W[i]=='\''){
            Upper+=W[i];
        }
    }
    return Upper;
}


string findWord(string W){

    // cout<<"Enter a word"<<endl;
    // getline(cin, W);
    // string upperW = transformW(W);
   

    ifstream inFile;
    inFile.open("dict.txt");

    string beforeSpace;
    string afterSpace;

    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }
    else{
        string line;
        bool found = false;
        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace);
        
        //cout<<beforeSpace<<endl;

        if(W == beforeSpace){
            cout<<"Pronunciation     :"<< afterSpace <<endl;
            found = true;
            break;
        } 

             

    }

    if(!found){
        cout<<"Not Found"<<endl;
        }
    }
    inFile.close();
}


int main(){

    string W;
    cout<<"Enter a word"<<endl;
    getline(cin, W);

    string upperW = transformW(W);
    
    cout<< findWord(upperW)<<endl;

}