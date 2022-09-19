/**
 * @file maps.cpp
 * @author Toba Adesanya (toba@shyftpower.com)
 * @brief Understanding maps in C++ (from The Cherno)
 * @version 0.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

#include <map> // This is a sorted map. Basically a balanced binary tree
#include <unordered_map> // This is a hash table

struct CityRecord
{
    std::string Name;
    int Population;
    double Latititude, Longitude;
};

int main()
{
    std::map<std::string, CityRecord> cityMap;  //Takes at least 2 template arguments (key, data)
    // Here, the index becomes our key for values in this map.
    // Note that the key has to be hash-able
    cityMap["Melbourne"] = CityRecord{"Melbourne", 5000000, 2.4, 9.4};
    cityMap["Lagos"] = CityRecord{"Lagos", 17000000, 2.4, 9.4};
    cityMap["Cambridge"] = CityRecord{"Cambridge", 140000, 2.4, 9.4};
    cityMap["Paris"] = CityRecord{"Paris", 2000000, 2.4, 9.4};
    cityMap["Qatar"] = CityRecord{"Qatar", 1000000, 2.4, 9.4};

    /**
     * @brief To retrieve information for any city
     * 
     */
    // CityRecord& LagosData = cityMap["Lagos"];
    // // A note on the index operator is that it always inserts data into the map, especially if the data didn't exist before
    // // So commenting out the Lagos data, will still compile but would use the default values of the struct
    // std::cout << LagosData.Population << "\n";

    // A better to retieve data therefore is to use the .at() function. This cannot insert data into the map 
    // And would also work if the map was declared as const
    CityRecord& parisData = cityMap.at("Paris");
    std::cout << "Paris population: " << parisData.Population << "\n";

    /**
     * @brief To find elements in a map
     * If the data doesn't exist though, it would throw an exception, so it makes sense to check first
     */ 
    const auto& cities = cityMap;
    if (cities.find("Lagos") != cities.end())
    {
        const CityRecord& lagosData = cities.at("Lagos");
        std::cout << "Lagos population: " << lagosData.Population << "\n";
    }
    
    /**
     * To iterate through the entire map, we can use a range based for loop
     *
     */
    for (auto& kv : cityMap) // This is using C++ 14 style. Apparently, this is old style!
    {
        const std::string& name = kv.first;
        CityRecord& city = kv.second;
    }

    // With C++ 17, we can use structured bindings which would look like this
    for (auto& [name, city] : cityMap)
    {
        std::cout << name << "\nPopulation: " << city.Population << std::endl;   
    }

    /**
     * @brief To delete a map entry
     * 
     */
    cityMap.erase("Cambridge");
    std::cout << "\n\n";

    for (auto& [name, city] : cityMap)
    {
        std::cout << name << "\nPopulation: " << city.Population << std::endl;   
    }

    // To use an unordered map, just change the name of the map and it would work.
    // The apis are identical
    std::unordered_map<std::string, CityRecord> cityMap2;

    // Checking if a key exist
    return 0;
}

