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

    ifstream inFile;
    inFile.open("cmudict.0.7a.txt"); //take out txt when submitting

    string beforeSpace;
    string afterSpace;

    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }
    else{
        string line;
        bool found = false; //condition set to cout in case of Not Found
        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace);
        

        if(W == beforeSpace){
            cout<<"Pronunciation     :"<< afterSpace <<endl;
            found = true; 
            break;
            return afterSpace;

            
        } 

             

    }
    if(!found){
        cout<<"Not Found"<<endl;
        }
    }
    inFile.close();
}





string identical(string W){

    ifstream inFile;
    inFile.open("cmudict.0.7a.txt"); //take out txt when submitting

    string beforeSpace;
    string afterSpace;
    string result;
    string line;
    string pronun;

    //string pronunciation;

    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }
        //bool found = false; //condition set to cout in case of Not Found
        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace);
        
        if(W == beforeSpace){
            pronun = afterSpace; //currPronun
        inFile.clear();//Clear file handler.
        inFile.seekg(0, ios_base::beg);//Go back to beginning.
        }
            if(pronun == afterSpace && beforeSpace != W){ //does not account for words with the same pronun before the inputed word
                cout<< beforeSpace << endl;
                result += beforeSpace + " ";
            }              

    }
    inFile.close();
    return result;
}



int main(){

    string W;
    cout<<"Enter a word"<<endl;
    getline(cin, W);

    string upperW = transformW(W);
    
    //cout<< findWord(upperW)<<endl;

    cout<< identical(upperW) <<endl;

}