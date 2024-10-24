#include <iostream>
#include <functional>

//this just declares the char values of each of 9 squares in each of 6 faces
char cube[6][3][3] = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}},
                        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}},
                        {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}},
                        {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
                        {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
                        {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}}};



class Face {
    public:
    char (*facenumber)[3][3]; //points to a 3x3 char matrix
    char (*up)[3][3]; //face up to it
    char (*down)[3][3]; //face down to it
    char (*left)[3][3]; //left
    char (*right)[3][3]; //right
    Face(char (*facenumber)[3][3], char(*up)[3][3], char(*down)[3][3], char(*left)[3][3], char(*right)[3][3]){
        this->facenumber = facenumber;
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
    }

    void clockwise() {
        char t[3][3]; //creates temporal matirx
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                t[i][j] = (*facenumber)[2-j][i]; //saves current state to temporal matrix
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                (*facenumber)[i][j] = t[i][j]; //assigns the new altered matrix to the face
            }
        }

        //for outer faces
        char up_t[3];
        char right_t[3];
        char down_t[3];
        char left_t[3];
        for(int i = 0; i < 3; i++){
            up_t[i] = (*up)[2][i];
            right_t[i] = (*right)[i][0];
            down_t[i] = (*down)[0][i];
            left_t[i] = (*left)[i][2];
        }
        for(int i = 0; i < 3; i++){
            (*up)[2][i] = left_t[2-i];
            (*right)[i][0] = up_t[i];
            (*down)[0][i] = right_t[2-i];
            (*left)[i][2] = down_t[i];
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

        //for outer faces
        char up_t[3];
        char right_t[3];
        char down_t[3];
        char left_t[3];
        for(int i = 0; i < 3; i++){
            up_t[i] = (*up)[2][i];
            right_t[i] = (*right)[i][0];
            down_t[i] = (*down)[0][i];
            left_t[i] = (*left)[i][2];
        }
        for(int i = 0; i < 3; i++){
            (*up)[2][i] = right_t[i];
            (*right)[i][0] = down_t[2-i];
            (*down)[0][i] = left_t[i];
            (*left)[i][2] = up_t[2-i];
        }
    }
};

void printCube(){ //self explanatory I believe
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[0][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[1][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[2][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[3][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[4][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cube[5][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main(){
    //std::cout << cubo[0][1][1] << std::endl;
    //std::cout << (*W.facenumber)[1][1] << std::endl;

    //main, up, down, left, right
    Face W(&(cube[0]), &(cube[4]), &(cube[5]), &(cube[3]), &(cube[2]));
    Face Y(&(cube[1]), &(cube[4]), &(cube[5]), &(cube[3]), &(cube[2]));
    Face R(&(cube[2]), &(cube[4]), &(cube[5]), &(cube[1]), &(cube[0]));
    Face O(&(cube[3]), &(cube[5]), &(cube[4]), &(cube[0]), &(cube[1]));
    Face B(&(cube[4]), &(cube[1]), &(cube[0]), &(cube[2]), &(cube[3]));
    Face G(&(cube[5]), &(cube[0]), &(cube[1]), &(cube[2]), &(cube[3]));
    


    //testing
    printCube();
    Y.clockwise();
    printCube();
    std::cin.get();
    return 0;
}


