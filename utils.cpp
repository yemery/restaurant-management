#pragma once
#include <iostream>
using namespace std;
#include <algorithm>
#include <optional>

// on a utilisé une template pour que la fonction puisse être utilisée avec n'importe quel type de vecteur et d'id
// cette fonction permet de chercher un objet dans un vecteur par son id et retourner un objet optionnel qui peut contenir l'objet trouvé ou pointeur nul
template <class V, class I>
// on utilise optional pour retourner un objet optionnel qui peut contenir un objet ou un pointeur nul
optional<V> find(vector<V> vector, I id)
{
    // on utilise find_if pour chercher l'objet par son id dans le vecteur
    auto it = find_if(vector.begin(), vector.end(), [id](const V &obj)
                      { return obj->id == id; });
    // si l'objet est trouvé on retourne un objet optionnel qui contient l'objet trouvé
    if (it != vector.end())
    {
        return *it;
    }
    // si l'objet n'est pas trouvé on retourne un pointeur nul
    else
    {
        return nullopt;
    }
}
