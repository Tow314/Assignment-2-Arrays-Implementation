#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<int> rows;
    std::vector<int> columns;
    std::vector<int> values;
    int totalRows;
    int totalColumns;

public:
    SparseMatrix(int rows, int columns) : totalRows(rows), totalColumns(columns) {}

    void addElement(int row, int column, int value) {
        if (row >= totalRows || column >= totalColumns || row < 0 || column < 0) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        if (value != 0) {
            this->rows.push_back(row);
            this->columns.push_back(column);
            this->values.push_back(value);
        }
    }

    void printSparseMatrix() {
        std::cout << "Row Column Value" << std::endl;
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << rows[i] << "    " << columns[i] << "      " << values[i] << std::endl;
        }
    }

    void printMatrix() {
        std::cout << "Full Matrix Representation:" << std::endl;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalColumns; ++j) {
                bool found = false;
                for (size_t k = 0; k < values.size(); ++k) {
                    if (rows[k] == i && columns[k] == j) {
                        std::cout << values[k] << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int rows = 4;
    int columns = 5;
    SparseMatrix sparseMatrix(rows, columns);

    sparseMatrix.addElement(0, 1, 3);
    sparseMatrix.addElement(1, 2, 5);
    sparseMatrix.addElement(2, 0, 9);
    sparseMatrix.addElement(3, 3, 12);
    sparseMatrix.addElement(3, 4, 15);

    sparseMatrix.printSparseMatrix();
    std::cout << std::endl;
    sparseMatrix.printMatrix();

    return 0;
}
