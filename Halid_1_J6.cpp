#include <iostream>
using namespace std;

const int MAX_ARGS = 6;

struct ini_dahh
{
    string lepang;
    string argumen[MAX_ARGS];
    int num_args;
};

ini_dahh itu_dah[100];
int num_functions = 3;

void menu();

string dapatkanKelasGerbong(int indeks)
{
    return (indeks % 6 == 1) ? "RDI" : (indeks % 6 == 2) ? "RSI"
                                   : (indeks % 6 == 3)   ? "RDX"
                                   : (indeks % 6 == 4)   ? "RCX"
                                   : (indeks % 6 == 5)   ? "R8"
                                                         : "R9";
}

void header()
{
    cout << "##       ########    ###    ########  ##    ##      ######   ########    ###     ######   ##    ##     ##          ###    ##    ##   #######   ##     ##  ########\n";
    cout << "##       ##         ## ##   ##     ## ###   ##     ##    ##     ##      ## ##   ##    ##  ##   ##      ##         ## ##    ##  ##   ##     ##  ##     ##     ##\n";
    cout << "##       ##        ##   ##  ##     ## ####  ##     ##           ##     ##   ##  ##        ##  ##       ##        ##   ##    ####    ##     ##  ##     ##     ##\n";
    cout << "##       ######## ##     ## ########  ## ## ##      ######      ##    ##     ## ##        #####        ##       ##     ##    ##     ##     ##  ##     ##     ##\n";
    cout << "##       ##       ######### ##   ##   ##  ####           ##     ##    ######### ##        ##  ##       ##       #########    ##     ##     ##  ##     ##     ##\n";
    cout << "##       ##       ##     ## ##    ##  ##   ###     ##    ##     ##    ##     ## ##    ##  ##   ##      ##       ##     ##    ##     ##     ##  ##     ##     ##\n";
    cout << "######## ######## ##     ## ##     ## ##    ##      ######      ##    ##     ##  ######   ##    ##     ######## ##     ##    ##      #######    #######      ##\n";
}

void setNumFunctions()
{
    int pilihan;
    cout << "Enter the number of functions (3, 6, or 9): ";
    cin >> pilihan;
    if (pilihan == 3 || pilihan == 6 || pilihan == 9)
    {
        num_functions = pilihan;
    }
    else
    {
        cout << "Invalid number of functions. Defaulting to 3.\n";
        num_functions = 3;
    }
}

void adddata()
{
    setNumFunctions(); // Prompt user to set the number of functions at the beginning
    string pilihan;

    for (int i = 0; i < num_functions; i++)
    {
        cout << "You will add function (Y/N): ";
        cin >> pilihan;

        if (pilihan == "Y" || pilihan == "y")
        {
            while (true)
            {
                cout << "Have argument? (Y/N): ";
                cin >> pilihan;

                cout << "Function " << i + 1 << " to push: ";
                cin >> itu_dah[i].lepang;
                if (pilihan == "Y" || pilihan == "y")
                {
                    cout << "How many arguments? ";
                    cin >> itu_dah[i].num_args;

                    if (itu_dah[i].num_args > MAX_ARGS)
                    {
                        cout << "Too many arguments, max allowed is " << MAX_ARGS << ".\n";
                        itu_dah[i].num_args = MAX_ARGS;
                    }

                    for (int j = 0; j < itu_dah[i].num_args; j++)
                    {
                        cout << "Argument " << j + 1 << ": ";
                        cin >> itu_dah[i].argumen[j];
                    }
                    break;
                }
                else if (pilihan == "N" || pilihan == "n")
                {
                    itu_dah[i].num_args = 0;
                    break;
                }
                else
                {
                    cout << "Invalid input. Please enter Y or N.\n";
                }
            }
        }
        else if (pilihan == "N" || pilihan == "n")
        {
            cout << "Nilai -" << i + 1 << " to push: ";
            cin >> itu_dah[i].lepang;
            itu_dah[i].num_args = 0;
        }
        else
        {
            cout << "Invalid input. Please enter Y or N.\n";
            i--;
        }
    }
}

void debugmode()
{
    system("cls");
    string input;
    cout << "Debug command: ";
    getline(cin >> ws, input);

    if (input == "info stack")
    {
        bool hasData = false;

        for (int i = 0; i < num_functions; i++)
        {
            if (itu_dah[i].lepang != "")
            {
                hasData = true;
                break;
            }
        }

        if (!hasData)
        {
            cout << "-------------------------REGISTER-------------------------------------\n";
            cout << "No register.\n";
            cout << "-------------------------STACK-------------------------------------\n";
            cout << "No stack\n";
            system("pause");
            return;
        }

        int index = 0;
        cout << "-------------------------REGISTER-------------------------------------\n";

        while (index < num_functions)
        {
            system("cls");
            for (int i = 0; i < 6; i++)
            {
                string kelas = dapatkanKelasGerbong(i + 1);
                bool found = false;
                for (int j = 0; j < num_functions; j++)
                {
                    if (itu_dah[index].num_args > i)
                    {
                        cout << kelas << ": " << itu_dah[index].argumen[i] << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << kelas << ": 0\n";
                }
            }

            cout << "-------------------------STACK-------------------------------------\n";
            for (int i = 0; i < num_functions; i++)
            {
                if (i == index) // Menambahkan panah pada indeks yang dituju
                    cout << " => ";
                else
                    cout << "    ";
                cout << &itu_dah[i].lepang << ": " << itu_dah[i].lepang << "\n";
            }

            cout << "debug command ";
            getline(cin >> ws, input);
            if (input == "Exit" || input == "exit")
            {
                break;
            }
            index++;
        }
        while (index >= num_functions)
        {
            system("cls");

            cout << "-------------------------REGISTER-------------------------------------\n";
            cout << "No register.\n";
            cout << "-------------------------STACK-------------------------------------\n";
            cout << "No stack\n";
            system("pause");
            return;
        }
    }
    else
    {
        cout << "Invalid command.\n";
    }
}

void menu()
{
    int pilihan;
    do
    {
        system("cls");
        header();
        cout << "1. Add data" << endl
             << "2. Debug mode" << endl
             << "3. Exit" << endl;

        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            adddata();
            break;
        case 2:
            debugmode();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
            break;
        }
    } while (pilihan != 3);
}

int main()
{
    menu();
    return 0;
}
