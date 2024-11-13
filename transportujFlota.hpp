#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int sumaPrzetransportowanegoTowaru = 0;
    unsigned int liczbaZaglowcow = 0;
    if (towar == 0) {
        return 0;
    }
    Stocznia stocznia{};
    while (sumaPrzetransportowanegoTowaru < towar) {
        Statek* statek = stocznia();
        unsigned int przetransportowanyTowar = statek->transportuj();
        sumaPrzetransportowanegoTowaru += przetransportowanyTowar;
        if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
            ++liczbaZaglowcow; 
        }
        delete statek;
    }
    return liczbaZaglowcow;
}
