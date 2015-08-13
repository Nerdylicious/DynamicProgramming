//Dynamic programming solution has a time complexity of O(XY) since we end up filling the
//cache matrix (no filling of matrix entries is duplicated)
//Non dynamic programming solution has a time complexity of O(2^XY) since the tree branches
//off 2 ways and there are XY steps for each path (the height of the tree is XY)
//We have 2 branches that go down XY recursion levels in the non dynamic programming version
#include <iostream>
using namespace std;

#define X_DIMENSION 5
#define Y_DIMENSION 5

class Grid{
    public:
        int size_x; //number of columns
        int size_y; //number of rows
        int min_x_coord;
        int max_x_coord;
        int min_y_coord;
        int max_y_coord;
        Grid(int, int);
};

Grid::Grid(int size_x, int size_y){
    this->size_x = size_x;
    this->size_y = size_y;
    this->min_x_coord = 0;
    this->max_x_coord = this->size_x - 1;
    this->min_y_coord = 0;
    this->max_y_coord = this->size_y - 1;
}

void print_cache(int cache[Y_DIMENSION][X_DIMENSION]){
    cout << "\n[ " ;
    for(int i = 0; i < Y_DIMENSION; i ++){
        for(int j = 0; j < X_DIMENSION; j ++){
            cout << "i: " << i << " j: " << j << endl;
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]\n";
}

int count_robot_walks(int x_coord, int y_coord, Grid *grid, int cache[Y_DIMENSION][X_DIMENSION]){

    if((grid->max_x_coord < 1) &&
        (grid->max_y_coord < 1)){

        return 0;
    }
    if((x_coord < grid->min_x_coord) ||
        (x_coord > grid->max_x_coord) ||
        (y_coord < grid->min_y_coord) ||
        (y_coord > grid->max_y_coord)){

        return 0;
    }
    else if(cache[y_coord][x_coord] != -1){

        return cache[y_coord][x_coord];
    }
    else if((x_coord == grid->max_x_coord) &&
            (y_coord == grid->max_y_coord)){

        cache[y_coord][x_coord] = 1;
        return 1;
    }
    else{
        int count = count_robot_walks(x_coord + 1, y_coord, grid, cache) +   //move right by 1
                    count_robot_walks(x_coord, y_coord + 1, grid, cache);   //move down by 1
        cache[y_coord][x_coord] = count;
        return count;
    }
}

void init_cache(int cache[Y_DIMENSION][X_DIMENSION]){
    for(int i = 0; i < Y_DIMENSION; i ++){
        for(int j = 0; j < X_DIMENSION; j ++){
            cache[i][j] = -1;
        }
    }
}

int main(){
    Grid *grid = new Grid(X_DIMENSION, Y_DIMENSION);
    //first index in 2d array is the row index (on y-axis)
    //second index in 2d array is the column index (on x-axis)
    int cache[Y_DIMENSION][X_DIMENSION];
    init_cache(cache);
    int res = count_robot_walks(0, 0, grid, cache);
    cout << res << endl;
    delete grid;
    return 0;
}
