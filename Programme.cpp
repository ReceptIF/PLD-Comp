#include "Programme.h"

using namespace std;

Programme::Programme()
{

}

Programme::~Programme()
{

}

void Programme::AjouteFonction(Fonction* & fonction)
{
    fonctions.push_back(fonction);
}