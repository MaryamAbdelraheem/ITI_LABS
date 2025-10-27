#include <iostream>
using namespace std;

class MagicBox {
private:
    int size;
    int magic[50][50];  // 2D array (max size 50x50)

public:
    // Constructor
    MagicBox(int s) {
        if (s < 3 || s > 50 || s % 2 == 0) {
            cout << "Size must be an odd number between 3 and 49!\n";
            exit(0);
        }
        size = s;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                magic[i][j] = 0;
    }

    // Generate the magic square
    void generate() {
        int num = 1;
        int r = 0;             // Start at first row
        int c = size / 2;      // Middle column

        while (num <= size * size) {
            magic[r][c] = num;
            num++;

            int new_r = (r - 1 + size) % size; // Move up
            int new_c = (c + 1) % size;        // Move right

            if (magic[new_r][new_c] != 0) {
                r = (r + 1) % size;  // Move down instead
            } else {
                r = new_r;
                c = new_c;
            }
        }
    }

    // Print the magic square
    void print() const {
        cout << "\nMagic Square of size " << size << "x" << size << ":\n\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << magic[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter an odd size for the Magic Box: ";
    cin >> n;

    MagicBox box1(n);
    box1.generate();
    box1.print();

    return 0;
}