#include <iostream>
#include <time.h>
using namespace std;

//Let's make a simple project: "Guess my number" ----->

int main()
{
    int number, guessNumber;

    srand(time(0));

    //Generate a random number which is between 1-10
    number = rand() % 10 + 1;

    while(true){

        cout << "Please Enter a number for guessing the secret number: ";
        cin >> guessNumber;

        if(guessNumber > number){
            cout << "NO!, This number is greater than the secret number:(" << endl;
        }
        else if(guessNumber == number){
            cout << "YEEESSS!, This number is the secret number:))" << endl;
            break;
        }
        else{
            cout << "NO!, This number is less than the secret number:(" << endl;
        }
    }
}
