#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "BST.h"
#include "P_info.h"
using namespace std;

int main()
{
    {
            // TESTOWANIE DRZEWA NA PROSTYM TYPIE DANYCH

               /*
                     intDrzewo<int> - wysokość 3
                          6
                       /     \
                      3       12
                    /   \    /   \
                   1     4  8     15
                                    \
                                     16
              */

        BST<int> intDrzewo;                 //Drzewo binarne przyjmujące dane typu int

        intDrzewo.insert(6);
        intDrzewo.insert(3);
        intDrzewo.insert(12);
        intDrzewo.insert(1);
        intDrzewo.insert(4);
        intDrzewo.insert(8);
        intDrzewo.insert(15);
        intDrzewo.insert(16);

        //intDrzewo.inorderTraversal();       //Wypisane elementów drzewa w kolejności rosnącej
        //intDrzewo.saveToFile();             //Zapis danych do pliku
        //intDrzewo.deleteTree();

        //BST<int> intDrzewo2;                //Stworzenie drugiego drzewa do odczytu danych z pliku
        //intDrzewo2.loadFromFile();          //Odczyt danych z pliku
        //cout << "\n";
        //intDrzewo2.inorderTraversal();      //Wypisane elementów drzewa w kolejności rosnącej     
        //cout << "\n";

        //int* sh = intDrzewo2.search(100);   //Wyszukiwanie elementu 100
        //if (sh != nullptr)
        //    cout << *sh << endl;



            // TESTOWANIE DRZEWA NA WŁASNEJ STRUKTURZE

        //P_info osoba1("Bartek", "Gordon", 20, 181, 75);
        //P_info osoba2("Jakub", "Kowalski", 12, 165, 42);
        //P_info osoba3("Michal", "Kamiski", 35, 175, 80);
        //P_info osoba4("Filip", "Szymanski", 2, 75, 22);

        //BST<P_info> osobyDrzewo;
        //osobyDrzewo.insert(osoba1);
        //osobyDrzewo.insert(osoba2);
        //osobyDrzewo.insert(osoba3);
        //osobyDrzewo.insert(osoba4);

        //BST<P_info> osobyDrzewo1;
        //osobyDrzewo.serializeBinary("osobyBinary.txt");
        //osobyDrzewo1.deserializeBinary("osobyBinary.txt");
        //osobyDrzewo1.inorderTraversal();

        //BST<P_info> osobyDrzewo2(osobyDrzewo1); //Konstruktor przypisania
        //osobyDrzewo2.inorderTraversal();
        //cout << "\n";
        //osobyDrzewo2.inorderTraversal();
        //BST<P_info> osobyDrzewo3;
        //osobyDrzewo3 = move(osobyDrzewo2);
        //cout << "\n";
        //osobyDrzewo3.inorderTraversal();

            // TESTOWANIE DRZEWA NA DUŻEJ ILOŚCI DANYCH

        //BST<int> big;
        //big.loadFromFile("big_data.txt");
        //big.serializeBinary("binaryBig.txt");
        //cout << "Drzewo big wysokosc" << big.height() << endl;

        //BST<int> big1;
        //big1.deserializeBinary("binaryBig.txt");
        //cout << "Drzewo big wysokosc" << big1.height() << endl;
    }
    _CrtDumpMemoryLeaks(); //Sprawdzenie wyciekow pamieci
    return 0;
}
