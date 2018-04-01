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
    for(int i = 0; i <length; i++){
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
    string inputprofix = fixPro(inputpro);
    string profix = fixPro(pro);
 
    int counter = 0;
    if(numofinputpro == numofpro -1){
        for(int i = 0; i < numofinputpro; i++){
            int endPho = i + 1;
            if(nthPhoneme(inputprofix,i) == nthPhoneme(pro,i)){
                counter += 1;
            }
            if(nthPhoneme(inputprofix,i) == nthPhoneme(pro, endPho)){
                counter += 1;
            }

            if(counter == numofinputpro){
            add = true;
            }   
        }
    }
    return add; 
}

bool check_remove(string inputpro,string pro){ //use this to filter pronuncations in my removePhoneme funcs
    
    bool remove = false;
    int numofinputpro = countPhoneme(inputpro);//VIP number
    int numofpro = countPhoneme(pro);
    string inputprofix = fixPro(inputpro); //earases the first space in pronuncaition so nthPhoneme can work
    string profix = fixPro(pro);
 
    int counter = 0;
    if(numofinputpro -1 == numofpro){
        for(int i = 0; i < numofinputpro; i++){
            int endPho = i + 1;
            if(nthPhoneme(inputprofix,i) == nthPhoneme(pro,i)){
                counter += 1;
            }
            if(nthPhoneme(inputprofix, endPho) == nthPhoneme(pro,i)){
                counter += 1;
            }

            if(counter == numofinputpro - 1){
            remove = true;
            }   
        }
    }
    // cout<<counter<<endl;
    return remove; 
}

string addPhoneme(string W){ 
    ifstream inFile;
    inFile.open("cmudict.0.7a.txt"); //take out .txt when submitting

    string beforeSpace;
    string afterSpace;
    string result;
    string line;
    string pronun = pronunciation(W);

    int numofPho = countPhoneme(W); //6 in plants
    
    //Check For error
    if(inFile.fail()){
        cerr << "Error Opening File" << endl;
        exit(1);
    }

        while(!inFile.eof()){
        getline(inFile, line);
        splitOnSpace(line,beforeSpace,afterSpace); 

            if(check_add(pronun, afterSpace)){ //it's not working T_T 
    
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

    string P = pronunciation(upperW); //pronunciation string

    
    // cout<<"Pronunciation:    " << P <<endl;

    // cout<<"Identical:         "<< identical(upperW) <<endl;

    //cout<<"number of pho     "<<countPhoneme(P)<<endl;
    //cout<<fixPro(P);

    //cout<< nthPhoneme(P,1)<<endl;
    
    //cout<< boolalpha << check_add(" AH0 L UW1 ZH AH0 N"," AH0 L UW1 ZH AH0 N Z")<<endl;
    //cout<< boolalpha<<check_remove(" F L AW1 ER0 Z"," F AW1 ER0 Z")<<endl;
    
    cout<<addPhoneme(P)<<endl;


}