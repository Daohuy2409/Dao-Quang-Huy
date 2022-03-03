#include <iostream>
using namespace std;
const int maxMistakes=7;
bool check(string s,char t){
    bool c=false;
    for(int i=0;i<s.size();i++){
        if(s[i]==t){
            c=true;
            break;
        }
    }
    return c;
}
void output(string s){
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;
}
string chooseWord(){
    return "book";
}
string update(string a,string b,char t){
    for(int i=0;i<b.size();i++){
        if(b[i]==t){
            a[i]=t;
        }
    }
    return a;
}
char guessWord(){
    char a;
    cout<<"please choose a letter: ";
    cin>>a;
    return a;
}
int main(){
    string secretWord=chooseWord();
    string guessedWord="";
    for(int i=0;i<secretWord.size();i++){
        guessedWord='-'+guessedWord;
    }
    int countMistakes=0;
    do{
        cout<<"Number of mistakes: "<<countMistakes<<endl;
        char guess=guessWord();
        if(check(secretWord,guess)) {
            guessedWord=update(guessedWord,secretWord,guess);
        }
        else {
            countMistakes++;
            cout<<"You are wrong!"<<endl;
        }
        output(guessedWord);
    }while((countMistakes<maxMistakes)&&(secretWord!=guessedWord));
    if(countMistakes<maxMistakes) cout<<"Congratulation! You win!";
    else cout<<"Game over!";
}