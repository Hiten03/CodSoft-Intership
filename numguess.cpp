#include<bits/stdc++.h>
using namespace std;
int main(){
    int num, guess, tries=0;
    srand(time(0));                       //--------->seed random number generator <----------
    num = rand() % 100+1;                //-------->generates random number between 1 and 100 <--------------
    cout<<"--- Number Guessing Game ---"<<endl<<endl;

    do{
        cout<<"Guess a number between 1 and 100 : ";
        cin>>guess;
        tries++;

        if(guess>num){
            cout<<"Too High! \n"<<endl;
        }
        else if(guess<num){
            cout<<"Too Low! \n"<<endl;
        }
        else{
            cout<<"\nCorrect! You got it in "<<tries<<" guesses!"<<endl;
        }
    } while(guess!=num);

    return 0;
}    