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
    Pix(Pix& sursa) {
        this->culoare = sursa.culoare;
        this->pret = sursa.pret;
        if (this->marca != nullptr) {
            delete[] this->marca;
        }
        if (sursa.marca != nullptr) {
            this->marca = new char[strlen(sursa.marca) + 1];
            strcpy_s(this->marca, strlen(sursa.marca) + 1, sursa.marca);
        }
        else {
            this->marca = nullptr;
        }
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
    ~Pix() {
        if (this->marca != nullptr) {
            delete[] this->marca;
        }
    }

    void afisarePix() {
        cout << "Pix:" << endl;
        cout << "Culoare " << this->culoare << ", Pret " << this->pret << ", Marca ";
        if (this->marca != nullptr) {
            cout << this->marca;
        }
        else {
            cout << "";
        }
        cout << ", Numar modele " << this->numarModeleDisponibile << ", Pret minim " << this->MIN_PRET << endl;
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
    Creion(Creion& sursa) {
        this->grosimeMina = sursa.grosimeMina;
        this->lungime = sursa.lungime;
        if (this->material != nullptr) {
            delete[] this->material;
            this->material = nullptr;
        }
        if (sursa.material != nullptr) {
            this->material = new char[strlen(sursa.material) + 1];
            strcpy_s(this->material, strlen(sursa.material) + 1, sursa.material);
        }
        this->totalCreioane++;
    }
    ~Creion() {
        if (this->material == nullptr) {
            delete[] this->material;
        }
    }

    void afisareCreion() {
        cout << "Creion:" << endl;
        cout << "Grosime mina " << this->grosimeMina << ", Lungime " << this->lungime << ", Material ";
        if (this->material != nullptr) {
            cout << this->material;
        }
        else {
            cout << "";
        }
        cout << ", Total creioane " << this->totalCreioane << ", Lungime maxima " << this->MAX_LUNGIME << endl;
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
        }
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
        this->totalAscutitori++;
    }
    Ascutitoare(Ascutitoare& sursa) {
        this->areRezervor = sursa.areRezervor;
        this->pret = sursa.pret;
        if (this->producator != nullptr) {
            delete[] this->producator;
        }
        if (sursa.producator != nullptr) {
            this->producator = new char[strlen(sursa.producator) + 1];
            strcpy_s(this->producator, strlen(sursa.producator) + 1, sursa.producator);
        }
        this->totalAscutitori++;
    }
    ~Ascutitoare() {
        if (this->producator != nullptr) {
            delete[] this->producator;
        }
    }
    void afisareAscutitoare() {
        cout << "Ascutitoare:" << endl;
        cout << "Are rezervor " << this->areRezervor << ", Pret " << this->pret << ", Producator ";
        if (this->producator != nullptr) {
            cout << this->producator;
        }
        else {
            cout << "";
        }
        cout << ", Total ascutitori " << this->totalAscutitori << ", Capacitate maxima rezervor " << this->MAX_ASCHII_REZERVOR << endl;
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
    Pix pix1;
    Pix pix2("Verde");
    Pix pix3("Rosu", 5.0, "BIC");

    pix1.afisarePix();
    pix2.afisarePix();
    pix3.afisarePix();

    Pix pix4(pix2);
    pix4.afisarePix();

    Creion creion1;
    Creion creion2(0.9, 15, "Lemn");
    Creion creion3(2.0, 10, "Metal");
    
    creion1.afisareCreion();
    creion2.afisareCreion();
    creion3.afisareCreion();

    Creion creion4(creion3);
    creion4.afisareCreion();


    Ascutitoare ascutitoare1;
    Ascutitoare ascutitoare2("Pelikan");
    Ascutitoare ascutitoare3(true, 10, "BIC");
    
    ascutitoare1.afisareAscutitoare();
    ascutitoare2.afisareAscutitoare();
    ascutitoare3.afisareAscutitoare();

    Ascutitoare ascutitoare4(ascutitoare1);
    ascutitoare4.afisareAscutitoare();
   
    return 0;
}


