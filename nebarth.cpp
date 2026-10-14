#include <iostream>
#include <cmath>
#include <ctime>

int main(){
    int confinue;
    int hp = 100;
    int pendejo;
    bool startio = true;
    srand(time(NULL));
    std::cout << "This is a Recode of my Previous 'Jungle Game' i made as an exercise to fully learn C++. (Press enter to continue.)\n";
    std::cin >> confinue;
    while(startio)
    {
        std::cout << "You are nebarth you have " << hp << " hp\n";
        std::cin >> confinue;
        pendejo = rand();
        std::cout << pendejo;
    }
}