/*
Author: Michelle Lucero
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Project 02, e.g., Pronounce

Here, briefly, at least in one or a few sentences
describe what the program does.
*/

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

string fixPro(string pro){ // fixed pronunciation's first space problem
    int length = pro.length();
    string fixed;
    for(int i = 1; i <length; i++){
        fixed += pro[i];
    }
    return fixed;
}


string nthPhoneme(string W, int pos){ 
    
    string fix = fixPro(W); // "P L AE1 N T S" instead of " P L AE1 N T S"



    int numPho = countPhoneme(W); // number of phonemes in the pronuncaition

    string beforeSpace;
    string afterSpace;
    string desiredPho; //the nth Phoneme 
    
    for(int i = 0; i < numPho; i++){

        splitOnSpace(fix, beforeSpace, afterSpace);//W pronuncaition

        if(i == pos){

            desiredPho = beforeSpace; //grabs the desired phoneme
        }
        else if(i != pos){
            fix = afterSpace; // resets fix to beforeSpace for next iteration
        }
    }
    return desiredPho; 
}

bool check_add(string inputpro,string pro){ //use this to filter pronuncations in my addPhoneme funcs
    bool add = false;
    int numofinputpro = countPhoneme(inputpro);//VIP number
    int numofpro = countPhoneme(pro);

 
    int counter = 0;
    if(numofinputpro == numofpro -1){ 
        for(int i = 0; i < numofinputpro; i++){
            int endPho = i + 1; //accounts for a pronunciation that has a phoneme added at the end

            
            if(nthPhoneme(inputpro,i) == nthPhoneme(pro,i)){ //suppose to account for phonemes added at the end
                counter += 1;
            }
            if(nthPhoneme(inputpro,i) == nthPhoneme(pro, endPho)){ //suppose to account for phonemes added at the beginning
                counter += 1;
            }

            if(counter == numofinputpro){ // counter == to the number of phonemes in inputpro
            add = true;
            }   
        }
    }
    
    return add; 
}

bool check_remove(string inputpro,string pro){ //use this to filter pronuncations in my addPhoneme funcs
    bool remove = false;
    int numofinputpro = countPhoneme(inputpro);//VIP number
    int numofpro = countPhoneme(pro); //
 
    int counter = 0;
    if(numofinputpro -1 == numofpro){ 
        for(int i = 0; i < numofpro; i++){
            int endPho = i + 1; //accounts for a pronunciation that has a phoneme added at the end

            
            if(nthPhoneme(inputpro,i) == nthPhoneme(pro,i)){ //suppose to account for phonemes added at the end
                counter += 1;
            }
            
            else if(nthPhoneme(inputpro,endPho) == nthPhoneme(pro, i)){ //suppose to account for phonemes added at the beginning
                counter += 1;
            }

            if(counter == numofinputpro -1){ // counter == to the number of phonemes in inputpro
            remove = true;
            }   
        }
    }
    
    return remove; 
}

bool isAlpha(string W){
    bool alpha = true;
    int length = W.length();


    for(int i = 0; i < length; i++){
        if(W[i] == '0'){
            alpha = false;
        }
        if(W[i] == '1'){
            alpha = false;
        }
        if(W[i] == '2'){
            alpha = false;
        }
        if(W[i] == '3'){
            alpha = false;
        }
        if(W[i] == '4'){
            alpha = false;
        }
        if(W[i] == '5'){
            alpha = false;
        }
        if(W[i] == '6'){
            alpha = false;
        }
        if(W[i] == '7'){
            alpha = false;
        }
        if(W[i] == '8'){
            alpha = false;
        }
        if(W[i] == '9'){
            alpha = false;
        }
    }

    return alpha;
}





string addPhoneme(string W){ 
    ifstream inFile;
    inFile.open("cmudict.0.7a.txt"); //take out .txt when submitting

    string beforeSpace;
    string afterSpace;
    string result;
    string line;

    int numofPho = countPhoneme(W); //6 in plants
    int counter = 0;
    
    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }

        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace);



        int numofPhoA = countPhoneme(afterSpace); 
            
            if(check_add(W, afterSpace)==true){//trying to solve ackerman - " AE1 K ERO M AHO N" resulting in " AE1 N K ERO AHO N"
            //since the end and beg phoneme are the same ik it's not consecutive so these condition should help?? but it's not working
                if(isAlpha(beforeSpace)==true ){
                    result += beforeSpace += " ";
                }
                
            }

            
        }

    inFile.close();
    return result;
    
    }
bool check_replaced(string inputpro,string pro){ //use this to filter pronuncations that have x-1 phonemes in common with the inputed word
    bool replaced = false;
    int numofinputpro = countPhoneme(inputpro); //Phonemes of input
    int numofpro = countPhoneme(pro); //Phonemes of afterSpace' pronuciation --- to be used in replacePhoneme
    int amountforRemoved = numofinputpro -1;
 
    int counter = 0; // keeps tracks of the phonemes in common
    if(numofinputpro == numofpro){ //needs to have the same # of phonemes
        for(int i = 0; i < numofinputpro + 1; i++){
            
            if(nthPhoneme(inputpro,i) == nthPhoneme(pro,i)){ //checks to see if they are the same
                counter += 1;
                
            }

            if(counter == amountforRemoved){ // counter should be equal to  numofinputpro -1 bc that would imply that the two pronunciation have x-1 in
            replaced = true;
            }   
        }
        cout<<counter<<endl; //keep track of common phonemes
    }
    
    return replaced; 
}

string removePhoneme(string W){ 
    ifstream inFile;
    inFile.open("cmudict.0.7a.txt"); //take out .txt when submitting

    string beforeSpace;
    string afterSpace;
    string result;
    string line;

    int numofPho = countPhoneme(W); //6 in plants
    int counter = 0;
    
    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }

        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace);



        int numofPhoA = countPhoneme(afterSpace); 
            
            if(check_remove(W, afterSpace)==true){

                if(isAlpha(beforeSpace)==true ){
                    result += beforeSpace += " ";
                }
                
            }

            
        }

    inFile.close();
    return result;
    
    }



string replacePhoneme(string W){ 
    ifstream inFile;
    inFile.open("cmudict.0.7a.txt"); //take out .txt when submitting

    string beforeSpace;
    string afterSpace;
    string result;
    string line;

    int numofPho = countPhoneme(W); //6 in plants
    int counter = 0;
    
    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }

        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace);



        int numofPhoA = countPhoneme(afterSpace); 
            
            if(check_replaced(W, afterSpace)==true){

                if(isAlpha(beforeSpace)==true ){
                    result += beforeSpace += " ";
                }
                
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

    string P = pronunciation(upperW); //pronunciation string

   // cout<< countPhoneme(P)<<endl;
    
    cout<<"Pronunciation:    " << P <<endl;

    cout<<"Identical:         "<< identical(upperW) <<endl;

    //cout<< boolalpha << isAlpha("anchorman(1)");

    //cout<<"number of pho     "<<countPhoneme(P)<<endl;
    //cout<<fixPro(P);

    //cout<< nthPhoneme(P,0)<<endl;
    
    //cout<< boolalpha << check_add(" AH0 L UW1 ZH AH0 N"," K AH0 L UW1 ZH AH0 N")<<endl;
    cout<< boolalpha<<check_replaced(" P L AE1 N T S"," G L AE1 N T S")<<endl; //should print true
    cout<< boolalpha<<check_replaced(" P L AE1 N T S"," B L AE1 S T S")<<endl; //should print false
    cout<< boolalpha<<check_replaced(" P L AE1 N T S"," P R IH1 N T S")<<endl; //should print false


    
    // cout<<"Add phoneme:       "<<addPhoneme(P)<<endl;
    //cout<<"Remove phoneme:    "<<removePhoneme(P)<<endl;
    //cout<<"Replace phoneme:     "<<replacePhoneme(P)<<endl;


}