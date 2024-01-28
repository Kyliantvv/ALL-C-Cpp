#include <iostream>
#include <string>


class Vehicule {
public:

    Vehicule() {
        std::cout << "Constructeur par defaut de Vehicule" << std::endl;
    }


    Vehicule(const std::string& marque) : marque_(marque) {
        std::cout << "Constructeur de Vehicule avec parametre : " << marque_ << std::endl;
    }


    virtual void afficher() const = 0;

protected:
    std::string marque_;
};


class Voiture : public Vehicule {
public:

    Voiture() : modele_("Inconnu") {
        std::cout << "Constructeur par defaut de Voiture" << std::endl;
    }


    Voiture(const std::string& marque, const std::string& modele) : Vehicule(marque), modele_(modele) {
        std::cout << "Constructeur de Voiture avec parametres : " << marque_ << ", Modele = " << modele_ << std::endl;
    }


    void afficher() const override {
        std::cout << "Voiture " << marque_ << " de modele " << modele_ << std::endl;
    }

private:
    std::string modele_;
};


class Moto : public Vehicule {
public:

    Moto() : type_("Inconnu") {
        std::cout << "Constructeur par defaut de Moto" << std::endl;
    }

    Moto(const std::string& marque, const std::string& type) : Vehicule(marque), type_(type) {
        std::cout << "Constructeur de Moto avec parametres : " << marque_ << ", Type = " << type_ << std::endl;
    }

    void afficher() const override {
        std::cout << "Moto " << marque_ << " de type " << type_ << std::endl;
    }

private:
    std::string type_;
};

int main() {

    Vehicule* vehicule1 = new Voiture("Toyota", "Yaris");
    Vehicule* vehicule2 = new Moto("Ferrari", "488 Pista");

    return 0;
}
