#include <iostream>
#include <vector>

int main() {
    int N = 15000;
    std::vector<std::vector<int>> Z(N + 1, std::vector<int>(N + 1, 0));

    Z[0][N / 2] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (Z[i][j - 1] == 1 && Z[i][j] == 1 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 0;
            }
            else if (Z[i][j - 1] == 1 && Z[i][j] == 1 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 1 && Z[i][j] == 0 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 1 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 0;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 0 && Z[i][j + 1] == 1) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 1 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 1;
            }
            else if (Z[i][j - 1] == 1 && Z[i][j] == 0 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 0;
            }
            else if (Z[i][j - 1] == 0 && Z[i][j] == 0 && Z[i][j + 1] == 0) {
                Z[i + 1][j] = 0;
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            std::cout << Z[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}