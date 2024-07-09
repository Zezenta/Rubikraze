#include <iostream>
#include <functional>

char cubo[6][3][3] = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}},
                        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}},
                        {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}},
                        {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
                        {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
                        {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}}};

class Face {
    public:
    char (*facenumber)[3][3];
    std::function<void()> myFunction;
    Face(char (*valuecube)[3][3]){
        facenumber = valuecube;
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
    Face W(&(cubo[0]));
    Face Y(&(cubo[1]));
    Face R(&(cubo[2]));
    Face O(&(cubo[3]));
    Face B(&(cubo[4]));
    Face G(&(cubo[5]));


    //testing
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cubo[0][i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    W.anticlockwise();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << cubo[0][i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}