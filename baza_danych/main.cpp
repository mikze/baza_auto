#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct strk
{
 int id;
 string gwiazdka;
 string marka;
 string model;
 string kolor;
 string fabryka; //z jakiej fabryki
 string rejestracja; //rejestracja pojazdu
 string wlasciciel; //imie i nazwisko wlasciciela

 //char nazwisko[20];//nazwisko wlasciciela
 //char imie[20];//imie wlasciciela

 bool rodzaj; //1-sedan 0-hatchback

 int rok; //rok produkcji
 int nr_ser; //numer seryjny
 int nr_vin;
 int moc; //Konie mechaniczne
 int pesel; // numer pesel wlasciciela
 int max_v;//max predkosc


 float spalanie; //na 100 km
 float pojemnosc;// pojemnosc silnika




};

void wys_menu()
{
  cout<<"MENU"<<endl<<"1.Wyswietl"<<endl<<"2.Edytuj"<<endl<<"3.Dodaj"<<endl<<"4.Sciezka"<<endl<<"5.Kolorystyka"<<endl<<"6.Wyjdz"<<endl<<"_>";
}

void nowy(strk *wsk,strk *wsk_2,int rekordy,fstream &plik)
{
 string marka,model,kolor,fabryka,rejestracja,wlasciciel;
 char gwiazdka='*';
 bool rodzaj;
 int rok,nr_ser,nr_vin,moc,pesel,max_v,id;
 float spalanie,pojemnosc;
 cout<<"Podaj id: ";
 cin>>id;
 cout<<"Podaj marke: ";
 cin>>marka;
 cout<<"Podaj model: ";
 cin>>model;
 cout<<"Podaj kolor: ";
 cin>>kolor;
 cout<<"Podaj fabryke: ";
 cin>>fabryka;
 cout<<"Podaj rejestracje: ";
 cin>>rejestracja;
 cout<<"Podaj wlasciciela: ";
 cin>>wlasciciel;
 cout<<"Podaj rodzaj: ";
 cin>>rodzaj;
 cout<<"Podaj rok: ";
 cin>>rok;
 cout<<"Podaj nr_ser: ";
 cin>>nr_ser;
 cout<<"Podaj nr_vin: ";
 cin>>nr_vin;
 cout<<"Podaj moc: ";
 cin>>moc;
 cout<<"Podaj pesel: ";
 cin>>pesel;
 cout<<"Podaj max_v: ";
 cin>>max_v;
 cout<<"Podaj spalanie: ";
 cin>>spalanie;
 cout<<"Podaj pojemnosc: ";
 cin>>pojemnosc;


        plik.seekg( 0, std::ios::end );
        plik << endl;
        plik << id <<endl;
        plik << marka <<endl;
        plik << model<<endl;
        plik << kolor<<endl;
        plik << fabryka<<endl;
        plik << rejestracja<<endl;
        plik << wlasciciel<<endl;
        plik << rodzaj<<endl;
        plik << rok<<endl;
        plik << nr_ser<<endl;
        plik << nr_vin<<endl;
        plik << moc<<endl;
        plik << pesel<<endl;
        plik << max_v<<endl;
        plik << spalanie<<endl;
        plik << pojemnosc<<endl;
        plik << gwiazdka;
        plik.close();

       /* for(int i=0;i<rekordy;i++)
        {
        (wsk_2+i)->id=(wsk+i)->id;
        (wsk_2+i)->marka=(wsk+i)->marka;
        (wsk_2+i)->model=(wsk+i)->model;
        (wsk_2+i)->kolor=(wsk+i)->kolor;
        (wsk_2+i)->fabryka=(wsk+i)->fabryka;
        (wsk_2+i)->rejestracja=(wsk+i)->rejestracja;
        (wsk_2+i)->wlasciciel=(wsk+i)->wlasciciel;
        (wsk_2+i)->rodzaj=(wsk+i)->rodzaj;
        (wsk_2+i)->rok=(wsk+i)->rok;
        (wsk_2+i)->nr_ser=(wsk+i)->nr_ser;
        (wsk_2+i)->nr_vin=(wsk+i)->nr_vin;
        (wsk_2+i)->moc=(wsk+i)->moc;
        (wsk_2+i)->pesel=(wsk+i)->pesel;
        (wsk_2+i)->max_v=(wsk+i)->max_v;
        (wsk_2+i)->spalanie=(wsk+i)->spalanie;
        (wsk_2+i)->pojemnosc=(wsk+i)->pojemnosc;
        (wsk_2+i)->gwiazdka=(wsk+i)->gwiazdka;

        }*/

};
void wyswietl_cala_baze(strk *wsk,int rekordy)
{
        for(int i=0;i<=rekordy;i++)
        {
        cout<<"Id: "<<(wsk+i)->id<<endl;
        cout<<"Marka: "<<(wsk+i)->marka<<endl;
        cout<<"Model: "<<(wsk+i)->model<<endl;
        cout<<"Kolor: "<<(wsk+i)->kolor<<endl;
        cout<<"Fabryka: "<<(wsk+i)->fabryka<<endl;
        cout<<"Rejestracja: "<<(wsk+i)->rejestracja<<endl;
        cout<<"Wlasciciel: "<<(wsk+i)->wlasciciel<<endl;
        cout<<"Rodzaj: "<<(wsk+i)->rodzaj<<endl;
        cout<<"Rok produkcji: "<<(wsk+i)->rok<<endl;
        cout<<"Numer seryjny: "<<(wsk+i)->nr_ser<<endl;
        cout<<"Numer vin: "<<(wsk+i)->nr_vin<<endl;
        cout<<"Moc[kM]: "<<(wsk+i)->moc<<endl;
        cout<<"PESEL wlasciciela: "<<(wsk+i)->pesel<<endl;
        cout<<"Predkosc Maksymalna: "<<(wsk+i)->max_v<<endl;
        cout<<"Spalanie[L/100km]: "<<(wsk+i)->spalanie<<endl;
        cout<<"Pojemosc Silnika: "<<(wsk+i)->pojemnosc<<endl;
        cout<<"-----------------------"<<endl;

        }


}

void wyswietl_sciezke()
{

};
void edytuj_sciezke()
{

};
void zmien_nazwe_pliku()
{

};
void zliczanie(int &rekordy,int &ilosc_wierszy) //funkcja do zliczania rekordow za pomoca zliczania gwiazdek i ilosci wierszy w pliku
{
    string b;
    ifstream pomoc;
    pomoc.open("baza.txt");
    while(true)
    {
        pomoc>>b;
        if(b=="*")
        {
            rekordy++;
        }
        if(pomoc.eof())
        {
            break;
        }

        ilosc_wierszy++;

    }

};
void wczytywanie(fstream &plik, strk *wsk)  // FUNKCJA DO WCZYTYWANIA BAZY
{
        plik.open( "baza.txt" );

        int rekordy=0,ilosc_wierszy=1;
        zliczanie(rekordy,ilosc_wierszy);

        for(int i=0;i<rekordy;i++)
        {

        plik>>(wsk+i)->id;
        plik>>(wsk+i)->marka;
        plik>>(wsk+i)->model;
        plik>>(wsk+i)->kolor;
        plik>>(wsk+i)->fabryka;
        plik>>(wsk+i)->rejestracja;
        plik>>(wsk+i)->wlasciciel;
        plik>>(wsk+i)->rodzaj;
        plik>>(wsk+i)->rok;
        plik>>(wsk+i)->nr_ser;
        plik>>(wsk+i)->nr_vin;
        plik>>(wsk+i)->moc;
        plik>>(wsk+i)->pesel;
        plik>>(wsk+i)->max_v;
        plik>>(wsk+i)->spalanie;
        plik>>(wsk+i)->pojemnosc;
        plik>>(wsk+i)->gwiazdka;

        }
   plik.close();
  cout<<"Ilosc wczytanych rekordow: "<<rekordy<<endl<<"Ilosc wierszy w pliku: "<<ilosc_wierszy<<endl;
};

int main()
{
    /////////////////////////////////////////////// bajery
    system("title Baza danych Michal Zembik 210203");
    system("color 12");
    ////////////////////////////////////////////// Zliczanie rekordow i ilosci wierszy w pliku
    int rekordy=0,ilosc_wierszy=1;
    zliczanie(rekordy,ilosc_wierszy);

    ////////////////////////////////////////////// Wczytywanie bazy do programu
    fstream plik;
    int wielkosc_tab=rekordy;
    strk *wsk = new strk[wielkosc_tab];
    strk *wsk_2 = new strk[wielkosc_tab+1];

    wielkosc_tab--;
    wczytywanie(plik,wsk);
    ////////////////////////////////////////////// Zmienne do obslugi menu i petli
    bool wyjscie=true;
    int wybor;
    //////////////////////////////////////////////
    while(wyjscie)
    {

        wys_menu();
        cin>>wybor;
        switch(wybor)
        {
        case 1: //Wyswietl
            cin>>wybor;
            switch(wybor)
            {
            case 1: //Wyswietl->calabaze
                wyswietl_cala_baze(wsk,wielkosc_tab);
                break;
            case 2: //Wyswietl->szukaj wd danej
                break;
            case 3: //Wyswietl->szukaj wd warunku
                cin>>wybor;
                switch(wybor)
                {
                case 1: //Wyswietl->szukaj wd warunku->rocznik
                    break;
                case 2: //Wyswietl->szukaj wd warunku->pojemnosc
                    break;
                case 3: //Wyswietl->szukaj wd warunku->spalanie
                    break;
                case 4: //Wyswietl->szukaj wd warunku->max_predkosc
                    break;
                default:
                    break;
                }
                break;
            default:
                break;

            }
            break;
        case 2: // Edytuj
            cin>>wybor;
            switch(wybor)
            {
            case 1: //Edytuj->zapisz
                break;
            case 2: //Edytuj->zmien_wybrana_dana
                break;
            case 3: //Edytuj->kasuj
                break;
            case 4: //Edytuj->wczytaj
                break;
            default:
                break;

            }
            break;
        case 3: //Dodaj

            nowy(wsk,wsk_2,rekordy,plik);
            wielkosc_tab++;
            delete [] wsk;
            wsk = new strk[wielkosc_tab];
            if(wsk==NULL)
                cout<<"Blad wskaznika ;/ "<<endl;
            wczytywanie(plik,wsk);
            break;
        case 4: //Sciezka
            cin>>wybor;
            switch(wybor)
            {
            case 1: //Sciezka->zmiana sciezki
                edytuj_sciezke();
                break;
            case 2: //Sciezka->zmiana nazwy pliku z baza
                zmien_nazwe_pliku();
                break;
            case 3: //Sciezka->wyswietl sciezke do bazy
                wyswietl_sciezke();
                break;
            default:
                break;
            }
            break;
        case 5: //KOlory
            cin>>wybor;
            switch(wybor)
            {
            case 1: //KOlory->czcionka
                break;
            case 2: //kolory->tlo
                break;
            default:
                break;
            }
            break;
        case 6: // wyjscie
            char xx;
            cout<<"Czy napewno chcesz wyjsc? T/N: ";
            cin>>xx;
            if(xx=='T' || xx=='t')
            {
                cout<<"Zamykam program \n";
                wyjscie=false;
            }
            else
            {
                cout<<"Kontynuacja programu..."<<endl;
            }
            break;
        default:
            break;
        }
    }



    return 0;
}