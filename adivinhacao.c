#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//declaring the variables that wil be used
int guess; 
int attempts = 5;
float score = 1000;
int difficultyLevel;
int numberAttempts = 1;

int main(){

    //title: 
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          welcome to the  \n");
    printf("     |_|_|nnnn nnnn|_|_|          guessing game!  \n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    //implementing a difficulty level to the game
    printf("type the difficulty level\n");
    printf("(1)easy (2)medium (3)hard\n");
    printf("choose: ");
    scanf("%d", &difficultyLevel);

    switch (difficultyLevel){
    case 1:
        attempts = 20;
        break;
    case 2:
        attempts = 15;
        break;
    default:
        attempts = 6;
        break;
    }

    //turning the secret number into a random value:
    srand(time(0));
    int secretNumber = rand() % 100;

    //main game loop
    for(int i = 1; i<=attempts; i++){

        printf("attempt %d of %d\n",i, attempts);
        printf("guess a number: ");
        scanf("%d", &guess);

        //message saying that the program receives only positive values
        if(guess < 0){
            printf("you can only type positive values!\n\n");
            i--;
            continue;
        }

        // if the player guesses correctly the secret number, the for loop ends
        if(guess == secretNumber){
            break;

        }else{

            //tips for the player
            if(guess < secretNumber){
                printf("your guess is less than the secret number\n");
                numberAttempts++;

            }else if (guess > secretNumber){
                printf("your guess is bigger than the secret number\n");
                numberAttempts++;
                
            }
            
            //calculated a score for the player
            float lostPoints = abs(guess-secretNumber)/(double)2;

            score -=lostPoints;
            }
    }
    //program end message
    if(guess == secretNumber){
        printf("\nYou won!\n");
        printf("you guessed correctly in %d attempts\n",numberAttempts);
    }
    else{
        printf("\nyou lost! the secret number is %d, try again!\n", secretNumber);
    }

    printf("your score: %.2f", score);
    
}