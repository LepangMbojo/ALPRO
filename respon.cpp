#include <iostream>

using namespace std;

struct Vote {
    string type;
    string choice;
};

const int MAX_VOTES = 100;
Vote votes[MAX_VOTES];
int voteCount = 0;

const int MAX_CANDIDATES = 10;
string presidenCandidates[MAX_CANDIDATES] = {
    "Senator Amstrong.SH", "Sasuke.SK", "Kakashi.SJ",
};
string wapresCandidates[MAX_CANDIDATES] = {
    "Raiden", "Liu Kang", "Kung Lao",
};
string dprCandidates[MAX_CANDIDATES] = {
    "Simo", "Polpot",
};
int presidenCount = 3;
int wapresCount = 3;
int dprCount = 2;

void mainMenu();
void pemilihMenu();
void kppsMenu();

void plank(){
    cout<<"---------------------------------------------------\n";
    cout<<"|                Tumpuk saja buku ini             |\n";
    cout<<"|           eh kek pernah dengar ya di mana gitu  |\n";
    cout<<"---------------------------------------------------\n";
}

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    while (true) {
        plank();
        cout << "\nMenu Utama:\n";
        cout << "1. tumpukan buku\n";
        cout << "2. ambil buku\n"
        int choice;
        cin >> choice;

        system("cls");
        switch (choice) {
            case 1:
                plank();
                pemilihMenu();
                break;
            case 2:
                plank();
                kppsMenu();
                break;
            case 3:
                cout << "Press any key to continue........\n";
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    }
}

void pemilihMenu() {
    while (true) {
        cout << "\nMenu Pemilih:\n";
        cout << "1. Pilih Presiden dan Wakil Presiden\n";
        cout << "2. Pilih DPR\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "Pilih opsi (1/2/3): ";
        int choice;
        cin >> choice;

        system("cls");
        if (choice == 1) {
            cout << "Daftar Calon Presiden dan Wakil Presiden:\n";
            for (int i = 0; i < presidenCount; i++) {
                cout << i + 1 << ". " << presidenCandidates[i] << " dan " << wapresCandidates[i] << "\n";
            }
            cout << "Pilih nomor pasangan calon presiden dan wakil presiden: ";
            int presidenChoice;
            cin >> presidenChoice;
            if (presidenChoice >= 1 && presidenChoice <= presidenCount) {
                votes[voteCount].type = "Presiden";
                votes[voteCount].choice = presidenCandidates[presidenChoice - 1] + " dan " + wapresCandidates[presidenChoice - 1];
                voteCount++;
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } else if (choice == 2) {
            cout << "Daftar Calon DPR:\n";
            for (int i = 0; i < dprCount; i++) {
                cout << i + 1 << ". " << dprCandidates[i] << "\n";
            }
            cout << "Pilih nomor calon DPR: ";
            int dprChoice;
            cin >> dprChoice;
            if (dprChoice >= 1 && dprChoice <= dprCount) {
                votes[voteCount].type = "DPR";
                votes[voteCount].choice = dprCandidates[dprChoice - 1];
                voteCount++;
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } else if (choice == 3) {
            cout << "Kembali ke Menu Utama.\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
}

void kppsMenu() {
    cout << "\nHasil Pemilihan:\n";
    int presidenVotes[MAX_CANDIDATES] = {0};
    int dprVotes[MAX_CANDIDATES] = {0};

    for (int i = 0; i < voteCount; i++) {
        if (votes[i].type == "Presiden") {
            for (int j = 0; j < presidenCount; j++) {
                if (votes[i].choice == (presidenCandidates[j] + " dan " + wapresCandidates[j])) {
                    presidenVotes[j]++;
                }
            }
        } else if (votes[i].type == "DPR") {
            for (int j = 0; j < dprCount; j++) {
                if (votes[i].choice == dprCandidates[j]) {
                    dprVotes[j]++;
                }
            }
        }
    }

    cout << "Presiden dan Wakil Presiden:\n";
    for (int i = 0; i < presidenCount; i++) {
        cout << presidenCandidates[i] << " dan " << wapresCandidates[i] << ": " << presidenVotes[i] << " suara\n";
    }

    cout << "\nDPR:\n";
    for (int i = 0; i < dprCount; i++) {
        cout << dprCandidates[i] << ": " << dprVotes[i] << " suara\n";
    }

    cout << "Tekan Enter untuk kembali ke Menu Utama.";
    cin.ignore();
    cin.get();
}
