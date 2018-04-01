#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>

#include<vector>



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





string pronunciation(string W){

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
            // cout<<"Pronunciation     :"<< afterSpace <<endl;
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
    inFile.open("cmudict.0.7a.txt"); //take out .txt when submitting

    string beforeSpace;
    string afterSpace;
    string result;
    string line;
    string pronun = pronunciation(W);

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
        
        if(pronun == afterSpace && beforeSpace != W){
            result += beforeSpace + " ";
        }
        
        // inFile.close();//Kill file.
        // inFile.open()          
    }

    inFile.close();
    return result;
}

int countPhoneme(string W){
    int index = W.length() - 1;
    int count = 0;
    for(int i=0; i<index;i++){
        if(W[i] == ' '){
            count += 1;
        }
    }
    return count;
}


string nthPhoneme(string W, int pos){ 

    int numPho = countPhoneme(W); // number of phonemes in the pronuncaition

    string beforeSpace;
    string afterSpace;
    string desiredPho;//the nth Phoneme 
    
    for(int i = 0; i < numPho; i++){
        splitOnSpace(W, beforeSpace, afterSpace);//W pronuncaition
        cout<<W<<endl; //testing and it does print out the pronuncaition
        cout<<beforeSpace<<endl; // it doesn't print out beforeSpace idk why???
        
        if(i == pos){
            desiredPho = beforeSpace; //should grab the desired phoneme

        }
        else{
            W = beforeSpace; // resets W to beforeSpace for next iteration
        }
    }

    return desiredPho; 
}






int main(){

    string W;
    cout<<"Enter a word"<<endl;
    getline(cin, W);

    string upperW = transformW(W);

    string P = pronunciation(upperW); //pronunciation string
    
    cout<<"Pronunciation:    " << P <<endl;

    cout<<"Identical:         "<< identical(upperW) <<endl;

    //cout<<"number of pho     "<<countPhoneme(P)<<endl;

    cout<< nthPhoneme(P,1)<<endl;


}