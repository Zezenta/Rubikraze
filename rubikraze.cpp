#include <iostream>
#include <functional>

//this just declares the char values of each of 9 squares in each of 6 faces
//char cube[6][3][3] = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}},
char cube[6][3][3] = {{{'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}},
                        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}},
                        {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}},
                        {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
                        {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
                        {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}}};

enum Border {TopRow, BottomRow, LeftCol, RightCol};


class Face {
    public:
    char (*facenumber)[3][3]; //points to a 3x3 char matrix
    char (*up)[3][3]; //face up to it
    char (*down)[3][3]; //face down to it
    char (*left)[3][3]; //left
    char (*right)[3][3]; //right
    Border up_border, down_border, left_border, right_border; //we make space for the indicators that will help us know how to affect squares in outer faces


    Face(char (*facenumber)[3][3], char(*up)[3][3], Border up_border, char(*down)[3][3], Border down_border, char(*left)[3][3], Border left_border, char(*right)[3][3], Border right_border){
        this->facenumber = facenumber;
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;

        this->up_border = up_border;
        this->down_border = down_border;
        this->right_border = right_border;
        this->left_border = left_border;
    }

    void getIndex(int i, Border border, int &row, int &col){ //get a value i, the border that will be affected, and the original addresses for the row and col variables 
        switch (border){
            case TopRow: row = 0; col = i; break;
            case BottomRow: row = 2; col = i; break;
            case LeftCol: row = i; col = 0; break;
            case RightCol: row = i; col = 2; break;
        }
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
        char up_face_t[3];
        char right_face_t[3];
        char down_face_t[3];
        char left_face_t[3];
        int row, col;

        for(int i = 0; i < 3; i++){
            getIndex(i, up_border, row, col);
            up_face_t[i] = (*up)[row][col];

            getIndex(i, right_border, row, col);
            right_face_t[i] = (*right)[row][col];

            getIndex(i, down_border, row, col);
            down_face_t[i] = (*down)[row][col];

            getIndex(i, left_border, row, col);
            left_face_t[i] = (*left)[row][col];
        }
        for(int i = 0; i < 3; i++){
            getIndex(i, up_border, row, col);
            (*up)[row][col] = left_face_t[2 - i];

            getIndex(i, right_border, row, col);
            (*right)[row][col] = up_face_t[i];

            getIndex(i, down_border, row, col);
            (*down)[row][col] = right_face_t[2 - i];

            getIndex(i, left_border, row, col);
            (*left)[row][col] = down_face_t[i];
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
        char up_face_t[3];
        char right_face_t[3];
        char down_face_t[3];
        char left_face_t[3];
        int col, row;


        for(int i = 0; i < 3; i++){
            getIndex(i, up_border, row, col);
            up_face_t[i] = (*up)[row][col];

            getIndex(i, right_border, row, col);
            right_face_t[i] = (*right)[row][col];

            getIndex(i, down_border, row, col);
            down_face_t[i] = (*down)[row][col];

            getIndex(i, left_border, row, col);
            left_face_t[i] = (*left)[row][col];
        }
        for(int i = 0; i < 3; i++){
            getIndex(i, up_border, row, col);
            (*up)[row][col] = right_face_t[2-i];

            getIndex(i, right_border, row, col);
            (*right)[row][col] = down_face_t[i];

            getIndex(i, down_border, row, col);
            (*down)[row][col] = left_face_t[2-i];

            getIndex(i, left_border, row, col);
            (*left)[row][col] = up_face_t[i];
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
    Face W(&(cube[0]), &(cube[4]), BottomRow, &(cube[5]), TopRow, &(cube[3]), RightCol, &(cube[2]), LeftCol);
    Face Y(&(cube[1]), &(cube[4]), TopRow, &(cube[5]), BottomRow, &(cube[2]), RightCol, &(cube[3]), LeftCol);
    Face R(&(cube[2]), &(cube[4]), RightCol, &(cube[5]), RightCol, &(cube[0]), RightCol, &(cube[1]), LeftCol);
    Face O(&(cube[3]), &(cube[4]), LeftCol, &(cube[5]), LeftCol, &(cube[1]), RightCol, &(cube[0]), LeftCol);
    Face B(&(cube[4]), &(cube[1]), TopRow, &(cube[0]), TopRow, &(cube[3]), TopRow, &(cube[2]), TopRow);
    Face G(&(cube[5]), &(cube[0]), BottomRow, &(cube[1]), BottomRow, &(cube[3]), BottomRow, &(cube[2]), BottomRow);
    


    //testing
    printCube();
    O.anticlockwise();
    printCube();
    std::cin.get();
    return 0;
}


