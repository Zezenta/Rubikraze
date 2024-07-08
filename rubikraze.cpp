#include <iostream>

char cubo[6][9] = {{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
                   {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
                   {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},
                   {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                   {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                   {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'}};


int main(){
    std::cout << cubo[0][0];
    return 0;
}