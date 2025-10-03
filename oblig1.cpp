#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private: 
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    
    // 1: Slett første element
    void slettFørste() {
        if (!head) {
            cout << "Listen er tom.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Første element slettet. \n";
    }

    // 2: Legg til i slutten 
    void leggTilSlutt(int verdi) {
        Node* nyNode = new Node{verdi, nullptr};
        if (!head) {
            head = nyNode;
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = nyNode;
    }

    // 3: Slett siste element
    void slettSiste() {
        if (!head) {
            cout << "Listen er tom.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            cout << "Siste element slettet.\n";
            return;
        }
        Node* curr = head;
        while (curr->next->next) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        cout << "Siste element slettet.\n";
    }

    // 4: Slett første forekomst av verdi
    void slettVerdi(int verdi) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->data == verdi) {
                if (!prev) head = curr->next;
                else prev->next = curr->next;
                delete curr;
                cout << "Element med verdi " << verdi << " slettet.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Verdi ikke funnet. \n";
    }
    
    // 5: Legg til etter verdi
    void leggEtter(int etterVerdi, int nyVerdi) {
        Node* curr = head;
        while (curr) {
            if (curr->data == etterVerdi) {
                Node* nyNode = new Node{nyVerdi, curr->next};
                curr->next = nyNode;
                cout << "La til " << nyVerdi << " etter " << etterVerdi << ".\n";
                return;
            }
            curr = curr->next;
        }
        cout << "Verdi ikke funnet. \n";
    }

    // 6: Legg til foran verdi
    void leggForan(int foranVerdi, int nyVerdi) {
        if (!head) {
            cout << "Listen er tom.\n";
            return;
        }
        if (head->data == foranVerdi) {
            Node* nyNode = new Node{nyVerdi, head};
            head = nyNode;
            cout << "La til " << nyVerdi << " foran " << foranVerdi << ".\n";            
            return;
        }
        Node* curr = head;
        while (curr->next) {
            if (curr->next->data == foranVerdi) {
                Node* nyNode = new Node{nyVerdi, curr->next};
                curr->next = nyNode;
                cout << "La til " << nyVerdi << "foran " << foranVerdi << ".\n";
                return;
            }
            curr = curr->next;
        }
        cout << "Verdi ikke funnet.\n";
    }


    // 7: Lengde på Listen
    int lengde() const {
        int count = 0;
        Node* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // 8: Tell forekomster
    int tellForkomster(int verdi) {
        int count = 0;
        Node* curr = head;
        while (curr) {
            if (curr->data == verdi) count++;
            curr = curr->next;
        }
        return count;
    }

    // 9: Skriv ut Listen
    void skrivut() const {
        Node* curr = head;
        cout << "Listen: ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    // 10: Slett hele listen 
    void slettAlt() {
        int count = 0;
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        cout << "Slettet hele listen. Antall elementer: " << count << "\n";
    }

    // 11: Tidskompleksitet
    void visTidskompleksitet() const {
        cout << "\n--- TIDSKOMPLEKSITET ---\n";
        cout << "1. Slett første: O(1)\n";
        cout << "2. Legg til slutt: O(n)\n";
        cout << "3. Slett siste: O(n)\n";
        cout << "4. Slett verdi: O(n)\n";
        cout << "5. Legg til etter verdi: O(n)\n";
        cout << "6. Legg til foran verdi: O(n)\n";
        cout << "7. Lengde: O(n)\n";
        cout << "8. Tell forekomster: O(n)\n";
        cout << "9. Skriv ut: O(n)\n";
        cout << "10. Slett alt: O(n)\n";
    }


    ~LinkedList() {
        slettAlt();
    }
};

void visMeny() {
    cout << "\n--- MENY ---\n";
    cout << "1. Slett første element\n";
    cout << "2. Legg til i slutten\n";
    cout << "3. Slett siste element\n";
    cout << "4. Slett element med verdi\n";
    cout << "5. Legg til etter verdi\n";
    cout << "6. Legg til foran verdi\n";
    cout << "7. Skriv ut lengde\n";
    cout << "8. Tell forekomster ut av verdi\n";
    cout << "9. Skriv ut listen\n";
    cout << "10. Slett hele listen\n";
    cout << "11. Vis tidskompleksitet\n";
    cout << "12. Avslutt\n";
    cout << "Velg: ";
}

int main() {
    LinkedList liste;
    int valg, tall, ekstra;
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        int tilfeldigTall = rand() % 100;
        liste.leggTilSlutt(tilfeldigTall);
    }

    do {
        visMeny();
        cin >> valg;

        switch (valg) {
            case 1: liste.slettFørste(); break;
            case 2: cout << "Tall å legge til: ";
                    cin >> tall;
                    liste.leggTilSlutt(tall);
                    break;
            case 3: liste.slettSiste(); break;
            case 4: cout << "Verdi å slette: ";
                    cin >> tall;
                    liste.slettVerdi(tall);
                    break;
            case 5: cout << "Etter hvilken verdie? ";
                    cin >> tall;
                    cout << "Ny verdi: ";
                    cin >> ekstra;
                    liste.leggEtter(tall, ekstra);
                    break;
            case 6: cout << "Foran hvilken verdi? ";
                    cin >> tall;
                    cout << "Ny verdi: ";
                    cin >> ekstra;
                    liste.leggForan(tall, ekstra);
                    break;
            case 7: cout << "Lengde: " << liste.lengde() << "\n";
                    break;
            case 8: cout << "Verdi å telle: ";
                    cin >> tall;
                    cout << "Antall forekomster: " << liste.tellForkomster(tall) << "\n";
                    break;
            case 9: liste.skrivut(); break;
            case 10: liste.slettAlt(); break;
            case 11: liste.visTidskompleksitet(); break;
            case 12: cout << "Avslutter...\n"; break;
            default: cout << "Ugyldig valg.\n";
        }
    } while (valg != 12);
    return 0;
}
