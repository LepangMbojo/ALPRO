#include <iostream>
using namespace std;

int main()
{
    int JARAK_MAX = 100;
    char input[JARAK_MAX];
    int key;

    cout << "Masukkan pesan untuk dienkripsi: ";
    cin.getline(input, JARAK_MAX);
    cout << "Masukkan kunci (geseran): ";
    cin >> key;

    int length = 0;
    for (length = 0; input[length] != '\0'; ++length)
    {
        
    }

    for (int i = 0; i < length / 2; ++i)
    {
        char temp = input[i];
        input[i] = input[length - i - 1];
        input[length - i - 1] = temp;
    }

        cout << "Pesan terenkripsi: " << input << endl;
    cout << "hasil enkripsi dengan reverse cipher + caesar cipher : ";

        for (int i = 0; input[i] != '\0'; ++i)
    {
        char & c = input[i]; 


        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            char base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
            c = c - base;
            c = (c + key) % 26;
            c = c + base;
        }
    }
    cout << input;
    cout<<endl;
    system("pause");
    return 0;
}

