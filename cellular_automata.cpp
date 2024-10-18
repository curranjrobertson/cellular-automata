#include <iostream>
#include <vector>
#include <fstream>

int main() {
    int N = 150;
    std::vector<std::vector<int> > Z(N + 1, std::vector<int>(N + 1, 0));
    // int a = 1;
    // int b = 1;
    // int c = 1; 
    // int d = 1; 
    // int e = 1; 
    // int f = 1; 
    // int g = 1; 
    // int h = 1;

    Z[0][N / 2] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (Z[i][j - 1] == 1 && Z[i][j] == 1 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 1 && Z[i][j] == 1 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 1 && Z[i][j] == 0 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 1 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 0 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 1 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 1 && Z[i][j] == 0 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 0 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 1;
            }
        }
    }

    std::ofstream vector;
    vector.open("vector.txt", std::ios::app);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            vector << Z[i][j] << " ";
            std::cout << Z[i][j] << " ";
        }
        std::cout << std::endl;
    }
    vector.close();
    return 0;
}