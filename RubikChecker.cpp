#include <iostream>
char cubo[6][9][9];
int sumas[6];
//the order will be WHITE, BLUE, GREEN, ORANGE, RED, YELLOW
int main(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                std::cin >> cubo[i][j][k];
                if(i == 0 || i == 5){ //white or yellow
                    sumas[i] += (cubo[i][j][k] == 'G' || cubo[i][j][k] == 'R') ? 1 : (cubo[i][j][k] == 'B' || cubo[i][j][k] == 'O') ? -1 : 0;
                }else if(i == 1 || i == 2){ //blue or green
                    sumas[i] += (cubo[i][j][k] == 'W' || cubo[i][j][k] == 'O') ? 1 : (cubo[i][j][k] == 'R' || cubo[i][j][k] == 'Y') ? -1 : 0;
                }else if(i == 3 || i == 4){ //orange or red
                    sumas[i] += (cubo[i][j][k] == 'Y' || cubo[i][j][k] == 'B') ? 1 : (cubo[i][j][k] == 'G' || cubo[i][j][k] == 'W') ? -1 : 0;
                }
            }
        }
    }
    int grupo1 = sumas[0] + sumas[1] + sumas[4];
    int grupo2 = sumas[2] + sumas[3] + sumas[5];
    int checksum = grupo1 + grupo2;
    std::cout << std::endl;
    std::cout << "B = " << sumas[1] << " \\" << std::endl;
    std::cout << "R = " << sumas[4] << "   " << grupo1 << " \\" << std::endl;
    std::cout << "W = " << sumas[0] << " /    \\";
    std::cout << "\n            " << checksum << std::endl;;
    std::cout << "G = " << sumas[2] << " \\    /" << std::endl;;
    std::cout << "O = " << sumas[3] << "   " << grupo2 << " /" << std::endl;
    std::cout << "Y = " << sumas[5] << " /   ";
}