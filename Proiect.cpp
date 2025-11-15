#include <iostream>
using namespace std;

class Pix {
public: 
    string culoare;
    double pret;
    char* marca;
    static int numarModeleDisponibile;
    const double MIN_PRET = 1.0;

    Pix() {
        this->culoare = "Albastru";
        this->pret = 1.0;
        this->marca = nullptr;
        this->numarModeleDisponibile++;
    }
    Pix(string culoare) {
        this->culoare = culoare;
        this->pret = 1.0;
        this->marca = nullptr;
        this->numarModeleDisponibile++;
    }
    Pix(string culoare, double pret, const char* marca) {
        this->culoare = culoare;
        this->pret = pret;
        this->marca = new char[strlen(marca) + 1];
        strcpy_s(this->marca, strlen(marca) + 1, marca);
        this->numarModeleDisponibile++;
    }

    static void ActualizareStoc(int contorActualizare) {
        numarModeleDisponibile += contorActualizare;
    }
};
int Pix::numarModeleDisponibile = 0;

class Creion {
public:
    double grosimeMina;
    double lungime;
    char* material;
    static int totalCreioane;
    const double MAX_LUNGIME = 30.0;

    Creion() {
        this->grosimeMina = 0.5;
        this->lungime = 10.0;
        this->material = nullptr;
        this->totalCreioane++;
    }
    Creion(double grosimeMina, double lungime) {
        this->grosimeMina = grosimeMina;
        this->lungime = lungime;
        this->material = nullptr;
        this->totalCreioane++;
    }
    Creion(double grosimeMina, double lungime, const char* material) {
        this->grosimeMina = grosimeMina;
        this->lungime = lungime;
        this->material = new char[strlen(material) + 1];
        strcpy_s(this->material, strlen(material) + 1, material);
        this->totalCreioane++;
    }
    static void CumparareCreion() {
        totalCreioane--;
    }
};

int Creion::totalCreioane = 0;

class Ascutitoare {
public:
    bool areRezervor;
    double pret;
    char* producator;
    static int totalAscutitori;
    const int MAX_ASCHII_REZERVOR = 30;

    Ascutitoare() {
        this->areRezervor = false;
        this->pret = 1.0;
        this->producator = nullptr;
        this->totalAscutitori++;
    }
    Ascutitoare(const char* producator) {
        this->areRezervor = false;
        this->pret = 1.0;
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->totalAscutitori++;
    }
    Ascutitoare(bool areRezervor, double pret, const char* producator) {
        this->areRezervor = areRezervor;
        this->pret = pret;
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->totalAscutitori++;
    }
    static void GolireStocAscutitori() {
        totalAscutitori = 0;
    }
};

int Ascutitoare::totalAscutitori = 0;


int main()
{
    Pix pix1 = Pix();
    Pix pix2 = Pix("Verde");
    Pix pix3 = Pix("Rosu", 5.0, "BIC");

    cout << "Pix1" << endl;
    cout << "Culoare " << pix1.culoare << ", Pret " << pix1.pret << ", Marca ";
    if (pix1.marca != nullptr) {
        cout << pix1.marca;
    }
    else {
        cout << "";
    }
    cout<< ", Numar modele " << pix1.numarModeleDisponibile << ", Pret minim " << pix1.MIN_PRET << endl;
    cout << "Pix2" << endl;
    cout << "Culoare " << pix2.culoare << ", Pret " << pix2.pret << ", Marca ";
    if (pix2.marca != nullptr) {
        cout << pix2.marca;
    }
    else {
        cout << "";
    }
    cout << ", Numar modele " << pix2.numarModeleDisponibile << ", Pret minim " << pix2.MIN_PRET << endl;
    cout << "Pix3" << endl;
    cout << "Culoare " << pix3.culoare << ", Pret " << pix3.pret << ", Marca ";
    if (pix3.marca != nullptr) {
        cout << pix3.marca;
    }
    else {
        cout << "";
    }
    cout<< ", Numar modele " << pix3.numarModeleDisponibile << ", Pret minim " << pix3.MIN_PRET << endl;

    Creion creion1 = Creion();
    Creion creion2 = Creion(0.9, 15, "Lemn");
    Creion creion3 = Creion(2.0, 10, "Metal");
    cout << "Creion1" << endl;
    cout << "Grosime mina " << creion1.grosimeMina << ", Lungime " << creion1.lungime << ", Material ";
    if (creion1.material != nullptr) {
        cout << creion1.material;
    }
    else {
        cout << "";
    }
    cout<< ", Total creioane " << creion1.totalCreioane<< ", Lungime maxima "<< creion1.MAX_LUNGIME << endl;
    cout << "Creion2" << endl;
    cout << "Grosime mina " << creion2.grosimeMina << ", Lungime " << creion2.lungime << ", Material ";
    if (creion2.material != nullptr) {
        cout << creion2.material;
    }
    else {
        cout << "";
    }
    cout<< ", Total creioane " << creion2.totalCreioane << ", Lungime maxima " << creion2.MAX_LUNGIME << endl;
    cout << "Creion3" << endl;
    cout << "Grosime mina " << creion3.grosimeMina << ", Lungime " << creion3.lungime << ", Material ";
    if (creion3.material != nullptr) {
        cout << creion3.material;
    }
    else {
        cout << "";
    }
    cout<<  ", Total creioane " << creion3.totalCreioane << ", Lungime maxima " << creion3.MAX_LUNGIME << endl;

    Ascutitoare ascutitoare1 = Ascutitoare();
    Ascutitoare ascutitoare2 = Ascutitoare("Pelikan");
    Ascutitoare ascutitoare3 = Ascutitoare(true, 10, "BIC");
    cout << "Ascutitoare1" << endl;
    cout << "Are rezervor " << ascutitoare1.areRezervor << ", Pret " << ascutitoare1.pret << ", Producator ";
    if (ascutitoare1.producator != nullptr) {
        cout << ascutitoare1.producator;
    }
    else {
        cout << "";
    }
    cout<< ", Total ascutitori " << ascutitoare1.totalAscutitori << ", Capacitate maxima rezervor " << ascutitoare1.MAX_ASCHII_REZERVOR << endl;
    cout << "Ascutitoare2" << endl;
    cout << "Are rezervor " << ascutitoare2.areRezervor << ", Pret " << ascutitoare2.pret << ", Producator ";
    if (ascutitoare2.producator != nullptr) {
        cout << ascutitoare2.producator;
    }
    else {
        cout << "";
    }
    cout<<", Total ascutitori " << ascutitoare2.totalAscutitori << ", Capacitate maxima rezervor " << ascutitoare2.MAX_ASCHII_REZERVOR << endl;
    cout << "Ascutitoare3" << endl;
    cout << "Are rezervor " << ascutitoare3.areRezervor << ", Pret " << ascutitoare3.pret << ", Producator ";
    if (ascutitoare3.producator != nullptr) {
        cout << ascutitoare3.producator;
    }
    else {
        cout << "";
    }
    cout<<", Total ascutitori " << ascutitoare3.totalAscutitori << ", Capacitate maxima rezervor " << ascutitoare3.MAX_ASCHII_REZERVOR << endl;
    return 0;
}


