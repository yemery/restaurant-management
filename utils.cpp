#pragma once
#include <iostream>
using namespace std;
#include <algorithm>
#include <optional>
#include "header.h"

template <class V, class I>
optional<V> find(vector<V> vector, I id)
{
    auto it = find_if(vector.begin(), vector.end(), [id](const V &obj)
                      { return obj->id == id; });
    if (it != vector.end())
    {

        return *it;
    }
    else
    {
        return nullopt;
    }
}
