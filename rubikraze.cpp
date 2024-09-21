#include <iostream>
#include <functional>

char cube[6][3][3] = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}},
                        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}},
                        {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}},
                        {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
                        {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
                        {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}}};

class Face {
    public:
    char (*facenumber)[3][3];
    char (*up)[3][3];
    char (*down)[3][3];
    char (*left)[3][3];
    char (*right)[3][3];
    Face(char (*facenumber)[3][3], char(*up)[3][3], char(*down)[3][3], char(*left)[3][3], char(*right)[3][3]){
        this->facenumber = facenumber;
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
    }

    void clockwise() {
        char t[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                t[i][j] = (*facenumber)[2-j][i];
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                (*facenumber)[i][j] = t[i][j];
            }
        }
    };
    void anticlockwise(){
        char t[3][3];
        for(int i = 2; i >= 0; i--){
            for(int j = 0; j < 3; j++){
                t[2-i][j] = (*facenumber)[j][i];
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                (*facenumber)[i][j] = t[i][j];
            }
        }
    }
};

int main(){
    //std::cout << cubo[0][1][1] << std::endl;
    //std::cout << (*W.facenumber)[1][1] << std::endl;
    //main, up, down, left, right
    Face W(&(cube[0]), &(cube[4]), &(cube[5]), &(cube[3]), &(cube[2]));
    Face Y(&(cube[1]), &(cube[4]), &(cube[5]), &(cube[2]), &(cube[3]));
    Face R(&(cube[2]), &(cube[4]), &(cube[5]), &(cube[0]), &(cube[1]));
    Face O(&(cube[3]), &(cube[4]), &(cube[5]), &(cube[1]), &(cube[0]));
    Face B(&(cube[4]), &(cube[1]), &(cube[0]), &(cube[3]), &(cube[2]));
    Face G(&(cube[5]), &(cube[0]), &(cube[1]), &(cube[3]), &(cube[2]));


    //testing
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[0][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    W.anticlockwise();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[0][i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}