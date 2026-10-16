// COMPLETED i think i translated it fully
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main(){
    std::string confinue;
    int hp = 100;
    int pendejo;
    int rounds = 0;
    int gm = 1;
    int mmrand = 0;
    bool startio = true;
    srand(time(NULL));
    std::cout << "This is a Recode of my Previous 'Jungle Game' i made as an exercise to fully learn C++. (Press Any Key then Press enter to continue.)\n";
    std::cin >> confinue;
    if (confinue == "TeStBeNcH") {
        std::cout << "Cheat Code Activated! You Now Start With 500 hp.\n";
        hp = 500;
    }
    std::cout << "Choose a game mode:\n*1. Survival\n*2. Extreme\n*3.Hp Collector\n(1-3): ";
    std::cin >> gm;
    switch(gm){
        case 1:
            std::cout << "You saw a cool jungle you had seen on a website,\nand you thought it wouldn't hurt to explore it,\nbut it was a scam and you are now in a jungle full of dangerous animals!\n";
            std::cin >> confinue;
            std::cout << "How to play:\nYou Are Nebarth. you must survive the jungle until 20 more goes!\nthere are random encounters. some friendly, some evil.\ntest your luck and win!\n";
            std::cin >> confinue;
            break;
        case 2:
            std::cout << "You saw a cool jungle you had seen on a website,\nand you thought it wouldn't hurt to explore it,\nbut you went the wrong way, and now you are in a jungle with the most vicious animals!\n";
            std::cin >> confinue;
            std::cout << "How to play:\nYou Are Nebarth. you must survive the jungle until 15 more goes!\nnow the animals wont give any mercy, so they do DOUBLE the damage!\nhealers heal more.";
            std::cin >> confinue;
            break;
        case 3:
            std::cout << "ALRIGHT SCOUTS! you are going to be going into this jungle and exploring it.\nif you find any issues, it wouldn't hurt to shout.\ntry to collect as much hp as possible!\n";
            std::cin >> confinue;
            std::cout << "How to play:\nYou Are Nebarth. you must trek through the jungle until you reach 5000 hp!\nthere are random encounters. some friendly, some evil.\ntest your luck and win!\n";
            std::cin >> confinue;
            break;
        default:
            std::cout << "Invalid Gamemode number.\n";
            return 1;
    }
    while(startio)
    {
        std::cout << "You are nebarth you have " << hp << " hp.\n";
        std::cin >> confinue;
        pendejo = (rand() % 8) + 1;
        switch(pendejo){
            case 1:
                std::cout << "You Saw a Cat! aww so cute! you still have " << hp << " hp.\n";
                rounds++;
                break;
            case 2:
                std::cout << "You Saw a LION! So Fierce! you took " << 25*(gm == 1 ? 1 : 2) << "hp.\n";
                rounds++;
                hp-=25*(gm == 1 ? 1 : 2);
                break;
            case 3:
                std::cout << "You Saw a DRAGON! AHH IT BURNS! you took " << 50*(gm == 1 ? 1 : 2) << "hp.\n";
                rounds++;
                hp-=50*(gm == 1 ? 1 : 2);
                break;
            case 4:
                std::cout << "You Saw an ant! it bit you, it hurt, a bit... you took " << 2*(gm == 1 ? 1 : 2) << "hp.\n";
                rounds++;
                hp-=2*(gm == 1 ? 1 : 2);
                break;
            case 5:
                std::cout << "You Saw a DOG! Aww, so Friendly! you gained " << 25*(gm == 1 ? 1 : 2) << "hp!\n";
                rounds++;
                hp+=25*(gm == 1 ? 1 : 2);
                break;
            case 6:
                if(gm == 3) {
                    std::cout << "JACKPOT! your hp is now DOUBLED!\n";
                    hp*=2;
                } else {
                    std::cout << "You are not in the Hp collector game mode. as a punishment, you took 1 hp.\n";
                    hp--;
                }
                rounds++;
                break;
            case 7:
                rounds++;
                std::cout << "as you were exploring, you found a medkit! you gained " << 25*(gm == 1 ? 1 : 2) << "hp!\n";
                hp+=25*(gm == 1 ? 1 : 2);
                break;
            case 8:
                rounds++;
                mmrand = rand() % 7;
                if(gm == 3){
                    mmrand = 2;
                }
                if(mmrand == 2){
                    std::cout << "YOU GOT THE MEGA MEDKIT! You gained " << 150*(gm == 1 ? 1 : 2) << "hp!\n";
                    hp+=150*(gm == 1 ? 1 : 2);
                } else {
                    std::cout << "you tried to get the mega medkit but it exploded. you lost " << 25*(gm == 1 ? 1 : 2) << "hp.\n";
                    hp-=25*(gm == 1 ? 1 : 2);
                }
                break;
            default:
                std::cout << "Whoops! an error occured. the game will shut down now.\n";
                startio = false;
                return 1;
        }
        if (hp <= 0) {
            if (gm != 3) {
                std::cout << "\nYOU LOSE!\nYou died while adventuring the jungle.\nBetter luck next time!\n";
                startio = false;
            } else {
                std::cout << "You almost died!\nhere is some extra hp to keep you going!\n";
                hp = 55;
            }
        } 
        else if (gm == 3 && hp >= 5000) {
            std::cout << "\nYOU WIN!\nYou successfully collected over 5000 HP!\n";
            startio = false;
        } 
        else if (gm == 1 && rounds >= 20) {
            std::cout << "\nYOU WIN!\nYou survived 20 rounds!\n";
            startio = false;
        } 
        else if (gm == 2 && rounds >= 15) {
            std::cout << "\nYOU WIN!\nYou survived 15 rounds!\n";
            startio = false;
        } 
        else if (startio) {
            if (gm != 3) {
                int maxRounds = (gm == 2) ? 15 : 20;
                std::cout << maxRounds - rounds << " rounds left to go. Keep Going!\n";
                hp++;
            } else {
                std::cout << rounds << " rounds passed, Keep Going!\n";
                hp += 4;
            }
        }
    }
    return 0;
}
