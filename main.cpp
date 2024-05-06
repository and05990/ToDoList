#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

struct Attivita
{
    string titolo;
    string descrizione;
    tm data;
};

bool confrontaDate(const Attivita &a, const Attivita &b)
{
    tm timeA = a.data;
    tm timeB = b.data;
    return mktime(&timeA) < mktime(&timeB);
}

int main()
{
    cout << "░▒▓███████▓▒░░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓████████▓▒░▒▓███████▓▒░" << endl;
    cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░" << endl;
    cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░" << endl;
    cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░▒▓█▓▒▒▓███▓▒░▒▓██████▓▒░ ░▒▓███████▓▒░" << endl;
    cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░" << endl;
    cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░" << endl;
    cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░" << endl;
    cout << "                                                                        " << endl;
    cout << "";
    vector<Attivita> attivita;
    string titolo;
    string descrizione;
    tm data;
    string data_str;

    int count;

    Attivita attivita1 = {"Titolo1", "Descrizione1", {0, 0, 0, 10, 10, 2021}};
    Attivita attivita2 = {"Titolo2", "Descrizione2", {0, 0, 0, 11, 10, 2021}};
    Attivita attivita3 = {"Titolo3", "Descrizione3", {0, 0, 0, 12, 10, 2021}};

    attivita.push_back(attivita1);
    attivita.push_back(attivita2);
    attivita.push_back(attivita3);

    int scelta = 1;
    do
    {
        cout << "1) Inserisci una nuova attività" << endl;
        cout << "2) Elimina un'attività" << endl;
        cout << "3) Cerca un attività" << endl;
        cout << "4) Modifica un'attività" << endl;
        cout << "5) Visualizza attività per data" << endl;
        cout << "6) Visualizza tutte le attività" << endl;
        cout << "99) Esci" << endl;

        cout << "Inserisci la tua scelta:";
        cin >> scelta;

        switch (scelta)
        {
        case 1:
            try
            {
                cout << "Titolo: ";
                cin >> titolo;

                cout << "Descrizione: ";
                cin >> descrizione;

                cout << "Data(AAAAMMDD): ";
                cin >> data_str;

                int year = stoi(data_str.substr(0, 4));
                int month = stoi(data_str.substr(4, 2));
                int day = stoi(data_str.substr(6, 2));

                tm data = {0};
                data.tm_year = year - 1900;
                data.tm_mon = month - 1;
                data.tm_mday = day;

                if (titolo.empty() || descrizione.empty())
                {
                    throw std::invalid_argument("Titolo e descrizione non possono essere vuoti");
                }

                time_t now = time(0);
                tm *ltm = localtime(&now);
                if (data.tm_year < ltm->tm_year || (data.tm_year == ltm->tm_year && data.tm_mon < ltm->tm_mon) || (data.tm_year == ltm->tm_year && data.tm_mon == ltm->tm_mon && data.tm_mday < ltm->tm_mday))
                {
                    throw std::invalid_argument("La data non può essere nel passato");
                }

                Attivita nuovaAttivita = {titolo, descrizione, data};
                attivita.push_back(nuovaAttivita);
            }
            catch (const std::exception &e)
            {
                cout << "Input errato" << endl;
            }

            break;
        case 2:
            cout << "Elimina un'attività" << endl;
            break;
        case 3:
            cout << "Cerca un attività" << endl;
            break;
        case 4:
            cout << "Modifica un'attività" << endl;
            break;
        case 5:
            cout << "Visualizza attività per data" << endl;
            if (attivita.empty())
            {
                cout << "Nessuna attività inserita" << endl;
                break;
            }
            else
            {

                sort(attivita.begin(), attivita.end(), confrontaDate);

                count = 1;
                for (auto &a : attivita)
                {
                    cout << count << ") " << a.titolo << " - " << a.descrizione << " - " << a.data.tm_mday << "/" << a.data.tm_mon << "/" << a.data.tm_year << endl;
                    count++;
                }
            }
            break;
        case 6:
            cout << "Visualizza tutte le attività" << endl;
            if (attivita.empty())
            {
                cout << "Nessuna attività inserita" << endl;
                break;
            }
            else
            {
                count = 1;
                for (auto &a : attivita)
                {
                    cout << count << ") " << a.titolo << " - " << a.descrizione << " - " << a.data.tm_mday << "/" << a.data.tm_mon << "/" << a.data.tm_year << endl;
                    count++;
                }
            }
            break;
        case 99:
            cout << "Arrivederci" << endl;
            break;
        default:
            cout << "Scelta non valida" << endl;
            break;
        }
        cout << "Attività inserite: " << attivita.size() << endl;
        cout << endl;
    } while (scelta != 99);

    return 0;
}
