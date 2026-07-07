/*
Scrieţi un program C/C++ care citeşte de la tastatură un număr natural, n (n∈[2,10^2]), și un șir de n 
numere naturale distincte din intervalul [0,10^9], elemente ale unui tablou unidimensional. 
Programul modifică tabloul în memorie, înlocuind valoarea minimă cu valoarea aflată pe ultima poziție. 
Elementele tabloului obținut sunt afișate pe ecran, separate prin câte un spaţiu.  
Exemplu: pentru n=8 şi tabloul (17,19,10,4,23,3,11,9) 
se obține tabloul (17,19,10,4,23,9,11,9)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n))
        return 0; // no input

    if (n < 2 || n > 100) {
        // invalid n per problem constraints — exit quietly
        return 0;
    }

    std::vector<long long> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        std::cin >> x;
        v.push_back(x);
    }

    // find index of minimum element (works correctly when elements are distinct)
    auto it = std::min_element(v.begin(), v.end());
    if (it != v.end()) {
        *it = v.back(); // replace minimal value with last element's value
    }

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}