#include <iostream>
using namespace std;

int getRows() {
    int a;

    cout << "Введите кол-во строк:\t";
    cin >> a;

    return a;
}

void print(int** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }
}

void printF(float** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }
}

int getCols() {
    int b;

    cout << "Введите кол-во столбцов:\t";
    cin >> b;

    return b;
}

void fillArrayRandom(int** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand();
        }
    }
}

void fillArrayRandomFloat(float** mas, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = (float)rand() / (float)RAND_MAX;
        }
    }
}

//Tasks
int Task1() {
    /*
        Удалить k-строку и j-столбец если их значения совпадают.
    */

    int m = getRows(),
        n = getCols();

    int** Array = new int* [m];

    for (int i = 0; i < m; i++) Array[i] = new int[n];

    fillArrayRandom(Array, m, n);
    print(Array, m, n);
    cout << endl;

    int k, j;

    cout << "Введите индекс строки (0 - " << m - 1 << ")\t";
    cin >> k;

    cout << "Введите индекс столбца (0 - " << n - 1 << ")\t";
    cin >> j;

    int k1 = 0, k2 = 0;

    for (int j1 = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (Array[k][i] == Array[j1][j]) k1++;
        }
    }

    return 0;
}

int Task2() {
    /*
        Удалить строку и столбец на пересечении которых стоит минимальный элемент. 
    */

    int m = getRows(),
        n = getCols();

    int** Array = new int* [m*m];

    for (int i = 0; i < m; i++) Array[i] = new int[n*n];

    fillArrayRandom(Array, m, n);
    print(Array, m, n);
    cout << endl;

    int min = Array[0][0],
        ind1 = 0,
        ind2 = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (Array[i][j] < min) {
                ind1 = i;
                ind2 = j;
            }
        }
    }

    cout << ind1 << "\t" << ind2 << "\t" << min << endl;

    for (int i = ind1; i < m - 1; i++) {
        for (int col = 0; col < n; col++) {
            Array[i][col] = Array[i + 1][col];
        }
    }
    m--;

    for (int i = 0; i < m; i++) {
        for (int col = ind2; col < n - 1; col++) {
            Array[i][col] = Array[i][col + 1];
        }
    }
    n--;

    print(Array, m, n);

    return 0;
}

int Task3() {
    /*
        Удалить все строки в которых средне арифметическое значение является четным числом. 
    */

    int m = getRows(),
        n = getCols();

    int** Array = new int* [m * m];

    for (int i = 0; i < m; i++) Array[i] = new int[n * n];

    fillArrayRandom(Array, m, n);
    print(Array, m, n);
    cout << endl;

    for (int i = 0; i < m; i++) {
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum += Array[i][j];
        }

        if (sum/n % 2 == 0) {
            for (int id = i; id < m - 1; id++) {
                for (int jd = 0; jd < n; jd++) {
                    Array[id][jd] = Array[id+1][jd];
                }
            }

            m--;
        }
    }

    print(Array, m, n);

    return 0;
}

int Task4() {
    /*
        Вставить новую строку после строки в которой находиться первый встреченный минимальный элемент. 
    */

    int m = getRows(),
        n = getCols();

    int** Array = new int* [2*m];

    for (int i = 0; i < 2*m; i++) Array[i] = new int[n];

    fillArrayRandom(Array, m, n);
    print(Array, m, n);
    cout << endl;

    int min = Array[0][0],
        minRow;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (Array[i][j] <= min) {
                min = Array[i][j];
                minRow = i;

                break;
            }
        }
    }

    for (int id = m + 1; id > minRow; id--) {
        for (int jd = 0; jd < n; jd++) {
            Array[id][jd] = Array[id - 1][jd];
        }
    }

    for (int j = 0; j < n; j++) {
        Array[minRow + 1][j] = 0;
    }

    m++;

    print(Array, m, n);

    return 0;
}

int Task5() {
    /*
        Для каждой строки подсчитать сумму элементов и записать в массив. 
    */

    int m = getRows(),
        n = getCols();

    int** Array = new int* [m];

    for (int i = 0; i < m; i++) Array[i] = new int[n];

    fillArrayRandom(Array, m, n);
    print(Array, m, n);
    cout << endl;

    int* Sums = new int[m];

    for (int i = 0; i < m; i++) {
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum += Array[i][j];
        }

        Sums[i] = sum;
    }

    for (int i = 0; i < m; i++) {
        cout << Sums[i] << "\t";
    }

    cout << endl;

    return 0;
}

int main()
{
    setlocale(0, "");

    //Task2();
    //Task3();
    //Task4();
    Task5();
    return 0;
}
