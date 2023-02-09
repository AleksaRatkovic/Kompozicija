#include "Nota.h"

Nota& Nota::operator<<=(int p)
{
    oktava -= p;
    return *this;

}

Nota& Nota::operator>>=(int p)
{
    oktava += p;
    return *this;

}

string Nota::opis() const
{
    string help[] = { "DO", "RE", "MI", "FA", "SO", "LA", "SI" };
    return help[visina];
}
