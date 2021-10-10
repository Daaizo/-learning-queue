#include <iostream>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

struct element
{
    char character;
    element* next;
};

struct queue
{
    element* head;
    element* tail;
};

void push(queue &,char);
void pop(queue &);
bool isEmpty(queue );
char first(queue );


int main()
{
    int choice = 1;
    queue q;
    q.head=nullptr;
    q.tail=nullptr;
    while(choice != 8)
    {
        cout << "\n\nMENU\n1. sprawdzenie czy kolejka jest pusta \n2. dodanie elementu do kolejki \n3. usuniecie elementu z kolejki\n4. pobranie elementu z kolejki \n5. usuniecie wszystkich elementow z kolejki \n6. wczytanie do kolejki du¿ych liter alfabetu lacinskiego z pliku tekstowego \n7. wydruk kolejki \n8. wyjscie\n";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << ( isEmpty(q) ? " \nkolejka nie jest pusta" : " \nkolejka jest pusta" );
                break;
            }

            case 2:
            {
                srand(time(NULL));
                char character = rand()%(255+1);
                push(q, character);
                cout << " \nwylosowano i dodano do koleji znak  " << character;

                break;
            }

            case 3:
            {
                if(isEmpty(q))
                {
                    pop(q);
                    cout << " \npomyslnie usunieto  " ;
                }
                else cout << " \nkolejka jest pusta i nie ma co usunac ";

                break;
            }

            case 4:
            {
                if(isEmpty(q))
                {
                    char character;
                    character = first(q);
                    cout << " \npobrano element " << character;
                }
                else cout <<  " \nkolejka jest pusta i nie ma co pobrac ";

                break;
            }

            case 5:
            {
                if(isEmpty(q))
                {
                    while(isEmpty(q))
                    {
                        pop(q);
                    }
                    cout << " \npomyslnie usunieta cala kolejke";
                }
                else cout << " \nkolejka juz jest pusta ";
                break;
            }

            case 6:
            {
                string sciezka;
                ifstream plik;
                char sredniki;
                sciezka = "znaki2.txt";
                plik.open(sciezka);
                if(!plik){cout << " nie udalo sie otworzyc pliku";}
                else
                {
                    while(!plik.eof())
                    {

                        char var;
                        plik >>  var;
                        if((int)var >= 65 && (int)var <= 90  )
                        {
                            push(q, var);
                        }
                    }
                }
                cout << " \npomyslnie dodano litery z pliku";
                plik.close();
                break;
            }

            case 7:
            {
                if(isEmpty(q))
                {
                    cout << "\n wydruk kolejki \n";
                    queue temp ;

                    temp = q;

                    while(isEmpty(temp))
                    {
                        cout << first(temp) << " ";
                        pop(temp);
                    }
                }
                else cout << "\n kolejka jest pusta";
                break;
            }

            case 8 : cout << " \nwychodzenie .. " ; break ;
            default : cout << " \nwprowadzono zly numer, sproboj ponownie ..";




        }

    }
    return 0;
}



void push(queue &q, char character_to_add)
{
   element *temp = new element;
   temp->character = character_to_add;
   temp->next = nullptr;
   if(q.tail != nullptr)
   {
       q.tail->next = temp;
   }
   else q.head = temp;
   q.tail = temp;

}


void pop(queue &q)
{
    element *temp = q.head;
    q.head = q.head->next;
    delete temp ;
    if(q.head == nullptr)
    {
        q.tail = nullptr;
    }

}
bool isEmpty(queue q){ return !(q.head == nullptr); }

char first(queue q){ return q.head->character; }
