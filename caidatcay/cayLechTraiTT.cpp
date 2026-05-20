#include <iostream>
using namespace std;

#define MAXLENGTH 100
#define NIL -1

typedef int DataType;
typedef int Node;

struct Tree {
    DataType Data[MAXLENGTH];
    int MaxNode;
};

void InitTree(Tree &T) {

    for (int i = 0; i < MAXLENGTH; i++)
        T.Data[i] = NIL;

    T.MaxNode = 0;
}

void InputLeftSkewed(Tree &T) {

    int n;

    cout << "Nhap so node: ";
    cin >> n;

    int index = 0;

    for (int i = 0; i < n; i++) {

        cout << "Nut thu "<< i+1 << " : ";
        cin >> T.Data[index];

        // cập nhật kích thước thực tế
        if (index + 1 > T.MaxNode)
            T.MaxNode = index + 1;

        // sang con trái
        index = 2 * index + 1;
    }
}

// ================= IN CÂY =================
void PrintTree(const Tree &T) {

    for (int i = 0; i < T.MaxNode; i++) {

        if (T.Data[i] != NIL) {

            cout << "\nNode " << i
                 << " = " << T.Data[i];

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < T.MaxNode &&
                T.Data[left] != NIL)

                cout << "\n   Con trai : "
                     << T.Data[left];

            if (right < T.MaxNode &&
                T.Data[right] != NIL)

                cout << "\n   Con phai : "
                     << T.Data[right];

            cout << endl;
        }
    }
}

int main() {

    Tree T;

    InitTree(T);

    InputLeftSkewed(T);

    cout << "\nCay lech trai\n";

    PrintTree(T);

    return 0;
}