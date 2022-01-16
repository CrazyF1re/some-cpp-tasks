#include <iostream>
using namespace std;
int vvod(char* N)
{
    int i = 0;
    cin.getline(N, 256, '\n');
    while (N[i] != '\0')i++;
    return i;
}
int slovo(char* A)
{
    int i = 0;
    cin.getline(A, 256, '\n');
    while (A[i] != '\0')i++;
    return i;
}
int* massiv_podstroki(int n, char* A)
{
    int* S = (int*)malloc(n * sizeof(int));
    int k = 0;
    S[n - 1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        S[i] = n - i - 1;
        if (A[i] == A[n - 1]) S[n - 1] = S[i];
    }
    if (S[n - 1] == 0) S[n - 1] = n;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (A[i] == A[j])
            {
                S[i] = S[j];
                k++;
            }
        }
    }
    return S;
}
void algoritm(char* S, char* P, int* T, int n, int M)
{
    bool f = 0;
    int i = M - 1;
    int j = M - 1;
    while (i < n and !f)
    {
        int k = i;
        j = M - 1;
        while (S[k] == P[j] && j >= 0)
        {
            k--;
            j--;
        }
        if (j < 0)
        {
            cout << "Слово есть, " << (i - M + 1) << endl; 
            f = 1;
        }
        else
        {
            k = i;
            int m = 0;
            for (int i = 0; i < M; i++)
            {
                if (S[k] == P[i]) { m = T[i]; break; }
            }
            if (m == 0) m = M;
            i += m;
        }
    }
    if (!f)cout << "Слова нет"<< endl;


}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;//переменная для количества букв в строке
    char N[256];
    N[0] = '1';
    cout << "Введите строку: ";
    n = vvod(N);
    while (N[0] != '0')
    {
        char* A = (char*)malloc(sizeof(char) * n);
        cout << "Введите искомое слово: ";
        int i = slovo(A);//функция считывания  символов слова и записи их в массив A
        int* S = massiv_podstroki(i, A);// массив расстояний в слове (массив S)
        algoritm(N, A, S, n, i);//основной алгоритм
        free(A);
        free(S);
        cout << "Введите строку: ";
        n = vvod(N);//функция считывания символов строки и записи их в массив N, n - точное количество символов в строке
    }
}
