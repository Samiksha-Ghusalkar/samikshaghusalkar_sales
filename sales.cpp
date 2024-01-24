#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    const int daysInMonth = 30; 
    const int daysInQuarter = 90; 

    
    srand(time(0));
    int max_element =0;

    
    const int priceMin = 20;
    const int priceMax = 30;
    const int unitsMin = 100;
    const int unitsMax = 1000;

    
    int dailyUnits[365];
    int dailyPrice[365];

    //daily sales
    for (int i = 0; i < 365; ++i) {
        dailyUnits[i] = generateRandom(unitsMin, unitsMax);
        dailyPrice[i] = generateRandom(priceMin, priceMax);
    }

    //monthly sales 
    int monthlyUnits[12] = {0};
    int monthlyAmount[12] = {0};
    int quarterlyUnits[4] = {0};
    int quarterlyAmount[4] = {0};

    // Compute monthly and quarterly totals
    for (int i = 0; i < 365; ++i) {
        int month = i / daysInMonth;
        int quarter = i / daysInQuarter;

        monthlyUnits[month] += dailyUnits[i];
        monthlyAmount[month] += dailyUnits[i] * dailyPrice[i];

        quarterlyUnits[quarter] += dailyUnits[i];
        quarterlyAmount[quarter] += dailyUnits[i] * dailyPrice[i];
    }

    
    std::cout << "Monthly Sales:\n";
    for (int i = 0; i < 12; ++i) {
        std::cout << "Month " << i + 1 << ": Units Sold = " << monthlyUnits[i] << ", Amount = " << monthlyAmount[i] << "\n";
    }

   
    std::cout << "\nQuarterly Sales:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "Quarter " << i + 1 << ": Units Sold = " << quarterlyUnits[i] << ", Amount = " << quarterlyAmount[i] << "\n";
    }


    int maxAmountQuarter = std::distance(quarterlyAmount, std::max_element(quarterlyAmount, quarterlyAmount + 4)) + 1;

    
    int maxUnitsQuarter = std::distance(quarterlyUnits, std::max_element(quarterlyUnits, quarterlyUnits + 4)) + 1;

   
    std::cout << "\nQuarter with Maximum Sales (Amount): Quarter " << maxAmountQuarter << "\n";
    std::cout << "Quarter with Maximum Sales (Units): Quarter " << maxUnitsQuarter << "\n";

    return 0;
}



















































