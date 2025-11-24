#include <iostream>
using namespace std;

class Pix {

private:
    string culoare;
    double pret;
    char* marca;
    static int numarModeleDisponibile;
    const double MIN_PRET = 1.0;

public: 

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
        if (this->marca != nullptr) {
            delete[] this->marca;
            this->marca = nullptr;
        }
        this->marca = new char[strlen(marca) + 1];
        strcpy_s(this->marca, strlen(marca) + 1, marca);
        this->numarModeleDisponibile++;
    }

    void setCuloare(string culoare) {
        if (culoare.length() > 0) {
            this->culoare = culoare;
        }
    }

    void setPret(double pret) {
        if (pret > 0) {
            this->pret = pret;
        }
    }

    void setMarca(const char* marca) {
        if (this->marca != nullptr) {
            delete[] this->marca;
            this->marca = nullptr;
        }
        if (strlen(marca) > 0) {
            this->marca = new char[strlen(marca) + 1];
            strcpy_s(this->marca, strlen(marca) + 1, marca);
        }
    }

    string getCuloare() {
        return this->culoare;
    }

    double getPret() {
        return this->pret;
    }

    char* getMarca() {
        return this->marca;
    }

    int getModeleDisponibile() {
        return this->numarModeleDisponibile;
    }

    double getMinPret() {
        return this->MIN_PRET;
    }
    static void ActualizareStoc(int contorActualizare) {
        numarModeleDisponibile += contorActualizare;
    }
};
int Pix::numarModeleDisponibile = 0;

class Creion {
private:
    double grosimeMina;
    double lungime;
    char* material;
    static int totalCreioane;
    const double MAX_LUNGIME = 30.0;
public:
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
        if (this->material != nullptr) {
            delete[] this->material;
            this->material = nullptr;
        }
        this->material = new char[strlen(material) + 1];
        strcpy_s(this->material, strlen(material) + 1, material);
        this->totalCreioane++;
    }
    static void CumparareCreion() {
        totalCreioane--;
    }

    void setGrosimeMina(double grosime) {
        if (grosime > 0) {
            this->grosimeMina = grosime;
        }
    }

    void setLungime(double lungime) {
        if (lungime > 0) {
            this->lungime = lungime;
        }
    }

    void setMaterial(const char* material) {
        if (this->material != nullptr) {
            delete[] this->material;
            this->material = nullptr;
        }
        if (strlen(material) > 0) {
            this->material = new char[strlen(material) + 1];
            strcpy_s(this->material, strlen(material) + 1, material);
        }
    }

    double getGrosimeMina() {
        return this->grosimeMina;
    }

    double getLungime() {
        return this->lungime;
    }

    char* getMaterial() {
        return this->material;
    }

    int getTotalCreioane() {
        return this->totalCreioane;
    }

    int getMaxLungime() {
        return this->MAX_LUNGIME;
    }
};

int Creion::totalCreioane = 0;

class Ascutitoare {
private:
    bool areRezervor;
    double pret;
    char* producator;
    static int totalAscutitori;
    const int MAX_ASCHII_REZERVOR = 30;
public:

    Ascutitoare() {
        this->areRezervor = false;
        this->pret = 1.0;
        this->producator = nullptr;
        this->totalAscutitori++;
    }
    Ascutitoare(const char* producator) {
        this->areRezervor = false;
        this->pret = 1.0;
        if (this->producator != nullptr) {
            delete[] this->producator;
            this->producator = nullptr;
        }
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->totalAscutitori++;
    }
    Ascutitoare(bool areRezervor, double pret, const char* producator) {
        this->areRezervor = areRezervor;
        this->pret = pret;
        if (this->producator != nullptr) {
            delete[] this->producator;
            this->producator = nullptr;
        }
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->totalAscutitori++;
    }
    static void GolireStocAscutitori() {
        totalAscutitori = 0;
    }

    void setAreRezervor(bool areRezervor) {
        this->areRezervor = areRezervor;
    }

    void setPret(double pret) {
        if (pret > 0) {
            this->pret = pret;
        }
    }

    void setProducator(const char* producator) {
        if (this->producator != nullptr) {
            delete[] this->producator;
            this->producator = nullptr;
        }
        if (strlen(producator) > 0) {
            this->producator = new char[strlen(producator) + 1];
            strcpy_s(this->producator, strlen(producator) + 1, producator);
        }
    }

    bool getAreRezervor() {
        return this->areRezervor;
    }

    double getPret() {
        return this->pret;
    }

    char* getProducator() {
        return this->producator;
    }

    int getTotalAscutitori() {
        return this->totalAscutitori;
    }

    int getMaxAschiiRezervor() {
        return this->MAX_ASCHII_REZERVOR;
    }

};

int Ascutitoare::totalAscutitori = 0;


int main()
{
    Pix pix1 = Pix();
    Pix pix2 = Pix("Verde");
    Pix pix3 = Pix("Rosu", 5.0, "BIC");

    cout << "Pix1" << endl;
    cout << "Culoare " << pix1.getCuloare() << ", Pret " << pix1.getPret() << ", Marca ";
    if (pix1.getMarca() != nullptr) {
        cout << pix1.getMarca();
    }
    else {
        cout << "";
    }
    cout<< ", Numar modele " << pix1.getModeleDisponibile() << ", Pret minim " << pix1.getMinPret() << endl;
    cout << "Pix2" << endl;
    cout << "Culoare " << pix2.getCuloare() << ", Pret " << pix2.getPret() << ", Marca ";
    if (pix2.getMarca() != nullptr) {
        cout << pix2.getMarca();
    }
    else {
        cout << "";
    }
    cout << ", Numar modele " << pix2.getModeleDisponibile() << ", Pret minim " << pix2.getMinPret() << endl;
    cout << "Pix3" << endl;
    cout << "Culoare " << pix3.getCuloare() << ", Pret " << pix3.getPret() << ", Marca ";
    if (pix3.getMarca() != nullptr) {
        cout << pix3.getMarca();
    }
    else {
        cout << "";
    }
    cout << ", Numar modele " << pix3.getModeleDisponibile() << ", Pret minim " << pix3.getMinPret() << endl;

    Creion creion1 = Creion();
    Creion creion2 = Creion(0.9, 15, "Lemn");
    Creion creion3 = Creion(2.0, 10, "Metal");
    cout << "Creion1" << endl;
    cout << "Grosime mina " << creion1.getGrosimeMina() << ", Lungime " << creion1.getLungime() << ", Material ";
    if (creion1.getMaterial() != nullptr) {
        cout << creion1.getMaterial();
    }
    else {
        cout << "";
    }
    cout<< ", Total creioane " << creion1.getTotalCreioane()<< ", Lungime maxima "<< creion1.getMaxLungime() << endl;
    cout << "Creion2" << endl;
    cout << "Grosime mina " << creion2.getGrosimeMina() << ", Lungime " << creion2.getLungime() << ", Material ";
    if (creion2.getMaterial() != nullptr) {
        cout << creion2.getMaterial();
    }
    else {
        cout << "";
    }
    cout << ", Total creioane " << creion2.getTotalCreioane() << ", Lungime maxima " << creion2.getMaxLungime() << endl;
    cout << "Creion3" << endl;
    cout << "Grosime mina " << creion3.getGrosimeMina() << ", Lungime " << creion3.getLungime() << ", Material ";
    if (creion3.getMaterial() != nullptr) {
        cout << creion3.getMaterial();
    }
    else {
        cout << "";
    }
    cout << ", Total creioane " << creion3.getTotalCreioane() << ", Lungime maxima " << creion3.getMaxLungime() << endl;

    Ascutitoare ascutitoare1 = Ascutitoare();
    Ascutitoare ascutitoare2 = Ascutitoare("Pelikan");
    Ascutitoare ascutitoare3 = Ascutitoare(true, 10, "BIC");
    cout << "Ascutitoare1" << endl;
    cout << "Are rezervor " << ascutitoare1.getAreRezervor() << ", Pret " << ascutitoare1.getPret() << ", Producator ";
    if (ascutitoare1.getProducator() != nullptr) {
        cout << ascutitoare1.getProducator();
    }
    else {
        cout << "";
    }
    cout<< ", Total ascutitori " << ascutitoare1.getTotalAscutitori() << ", Capacitate maxima rezervor " << ascutitoare1.getMaxAschiiRezervor() << endl;
    cout << "Ascutitoare2" << endl;
    cout << "Are rezervor " << ascutitoare2.getAreRezervor() << ", Pret " << ascutitoare2.getPret() << ", Producator ";
    if (ascutitoare2.getProducator() != nullptr) {
        cout << ascutitoare2.getProducator();
    }
    else {
        cout << "";
    }
    cout << ", Total ascutitori " << ascutitoare2.getTotalAscutitori() << ", Capacitate maxima rezervor " << ascutitoare2.getMaxAschiiRezervor() << endl;
    cout << "Ascutitoare3" << endl;
    cout << "Are rezervor " << ascutitoare3.getAreRezervor() << ", Pret " << ascutitoare3.getPret() << ", Producator ";
    if (ascutitoare3.getProducator() != nullptr) {
        cout << ascutitoare3.getProducator();
    }
    else {
        cout << "";
    }
    cout << ", Total ascutitori " << ascutitoare3.getTotalAscutitori() << ", Capacitate maxima rezervor " << ascutitoare3.getMaxAschiiRezervor() << endl;
    return 0;
}


