#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int FrequnctIDX(int ourString[], int len);
int returnShift(int AlphaListTemp[]);
int returnFreq(char ciperText[], int ciperTextLength);

    /* main 
   * Input: no input 
   * Description: opening the file and editing it 
   * Output: prints shift amount 
   */ 
int main(int argc, char *argv[])
{

    //get data in memory 
    ifstream infile;
    infile.open(argv[1]);
    if (!infile) {
        cout << "Error: Can't open the file" << endl;
        return 1;
    }
    stringstream buffer;
    buffer << infile.rdbuf();
    string text;
    text = buffer.str();
    //cout << text; 
    infile.close();
    //end of in memory 

    //clean up the txt 
    char cleanText [text.length()];
    int CleanTextNum = 0;
    argc = text.length();
    for(int i = 0; i < argc; i++){
        if(isalnum(text[i])){
            //isalmun - check for alpha numeric values only
            //cout<<text[i];
            //cleanText[CleanTextNum] = text[i];
            cleanText[CleanTextNum] = toupper(text[i]);
            //cout<<cleanText[CleanTextNum];
            CleanTextNum++;
        }
    } 

    ///return letter freq
    cout << "The shift amount is: " << returnFreq(cleanText,CleanTextNum) << "\n";

}

    /* FrequnctIDX 
   * Input: string and the length of the string 
   * Description: finding the index of the letter that is most frequent 
   * Output: index with the most frequent letter 
   */ 
int FrequnctIDX(int ourString[], int len)
{
    int i;
      
    // Initialize maximum element
    int max = ourString[0];
    int idxLatter1 = 0;
    for (i = 1; i < len; i++){        
        if (ourString[i] > max){
            max = ourString[i];
            idxLatter1 = i;
        }
    }

//cout<<"the biggest number is "<<max<<endl;
    /*int idxLatter = 0;
    for(int i = 0; i < 26; i++){
        if(ourString[i] == max){
            idxLatter = i;
            break;
        }
    }
    */
//cout<<" idxLatter1 - "<<idxLatter1<<endl;
//cout<<" idxLatter - "<<idxLatter<<endl;
// add 1 b/c the list is 0 based
    return idxLatter1+1;
}
    /*returnshift 
   * Input: the list of integers from the index 
   * Description: find shift amount by determining if the number value is bigger or smaller than 5 
   * Output: shift amount 
   */ 
int returnShift(int AlphaListTemp[])
{
    //if letter is less E (5)
    int idx = FrequnctIDX(AlphaListTemp,26); 
    int finalShift = 0;
    if( idx > 5){
        finalShift = 5+idx;
    }else{
        finalShift = 26-(5-idx);
    }
    //add 1 since the list is 0 based
    return finalShift;
}
    /* returnfreq 
   * Input: list of characters and integers 
   * Description: checking the first letter of the string against the first letter of the alphabet list 
   * Output: most frequent letter in the string 
   */ 
int returnFreq(char ciperText[], int ciperTextLength)
{
    //cout<<"i am here \n";
    char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int Alphalist [26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < ciperTextLength; i++ )
    {
        //cout<<" latter  - "<<ciperText[i]<<endl;
        for(int j = 0; j < 26; j++){
            if(alphabet[j] == ciperText[i]){
                Alphalist[j] =  Alphalist[j] + 1;
                break;
            }
        }
    }

    /*
    for(int j = 0; j < 26; j++){
    cout<<"the current list "<<j<<" : "<<Alphalist[j]<<endl;
    }
    
    char mostFreqLetter = alphabet[FrequnctIDX(Alphalist,26)];
    cout << " most found later ";
    cout<<mostFreqLetter<<endl;
    */

    return returnShift(Alphalist);
    
}