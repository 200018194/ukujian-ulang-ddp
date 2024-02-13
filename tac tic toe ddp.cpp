#include <iostream>

// Fungsi untuk menampilkan papan permainan
void displayBoard(char board[3][3]) {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Fungsi untuk memeriksa apakah ada pemenang atau permainan seri
int checkWin(char board[3][3]) {
    // Memeriksa baris dan kolom
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1; // Ada pemenang
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1; // Ada pemenang
        }
    }

    // Memeriksa diagonal
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1; // Ada pemenang
    }

    // Memeriksa apakah permainan seri
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return 0; // Masih ada celah kosong, permainan belum selesai
            }
        }
    }

    return -1; // Permainan seri
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int currentPlayer = 1; // 1 untuk pemain pertama, 2 untuk pemain kedua
    int row, col;

    do {
        displayBoard(board);

        // Meminta input dari pemain
        std::cout << "Pemain " << currentPlayer << ", masukkan baris (0-2) dan kolom (0-2) yang dipilih: ";
        std::cin >> row >> col;

        // Memeriksa apakah sel yang dipilih sudah terisi
        if (board[row][col] != ' ') {
            std::cout << "Sel tersebut sudah terisi. Pilih sel lain." << std::endl;
            continue;
        }

        // Menyimpan tanda (X atau O) ke dalam sel yang dipilih
        if (currentPlayer == 1) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }

        // Memeriksa kondisi permainan (pemenang atau seri)
        int result = checkWin(board);

        // Beralih ke pemain berikutnya
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        if (result == 1) {
            displayBoard(board);
            std::cout << "Pemain " << ((currentPlayer == 1) ? 2 : 1) << " menang!" << std::endl;
            break;
        } else if (result == -1) {
            displayBoard(board);
            std::cout << "Permainan seri!" << std::endl;
            break;
        }

    } while (true); // Melakukan loop hingga ada pemenang atau permainan seri

    return 0;
}

