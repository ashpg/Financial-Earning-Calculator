#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double calculateEarnings(double principal, double rate, int years)
{
    double amount = principal * pow((1 + rate / 100), years);
    return amount - principal;
}

void recommendInvestmentStrategy(int age, double principal, int years)
{
    double largeCap, smallCap, mediumCap, stocks;
    double largeCapRate = 10;
    double smallCapRate = 20;
    double mediumCapRate = 15;
    double stocksRate = 25;

    if (age < 18)
    {
        cout << "You are too young to invest. Focus on your studies first!" << endl;
        return;
    }
    else if (age >= 18 && age <= 35)
    {

        largeCap = principal * 0.10;
        smallCap = principal * 0.30;
        mediumCap = principal * 0.20;
        stocks = principal * 0.40;
        cout << "You are young and can take higher risks. We recommend you allocate your capital as follows:" << endl;
        cout << "Since you have a long investment horizon, you can afford to take higher risks. Hence, we suggest a more aggressive investment approach with a higher allocation in stocks and small-cap funds." << endl;
    }
    else if (age >= 36 && age <= 60)
    {
        largeCap = principal * 0.30;
        smallCap = principal * 0.25;
        mediumCap = principal * 0.25;
        stocks = principal * 0.20;
        cout << "You are middle-aged. A balanced approach is best. We recommend you allocate your capital as follows:" << endl;
        cout << "At this stage, a more balanced approach is suggested. While you can still take some risks, it is important to ensure a mix of stable large-cap investments and riskier small-cap investments for growth." << endl;
    }
    else if (age > 60)
    {
        largeCap = principal * 0.50;
        smallCap = principal * 0.10;
        mediumCap = principal * 0.20;
        stocks = principal * 0.20;
        cout << "You are older and should focus on safer investments. We recommend you allocate your capital as follows:" << endl;
        cout << "As you are in the later stages of life, it's recommended to focus more on stable and safer investments such as large-cap funds while limiting exposure to high-risk small-cap funds." << endl;
    }

    cout << "Large-cap funds: " << largeCap << " (" << (largeCap / principal) * 100 << "%)" << endl;
    cout << "Small-cap funds: " << smallCap << " (" << (smallCap / principal) * 100 << "%)" << endl;
    cout << "Medium-cap funds: " << mediumCap << " (" << (mediumCap / principal) * 100 << "%)" << endl;
    cout << "Stocks: " << stocks << " (" << (stocks / principal) * 100 << "%)" << endl;

    double totalEarnings = 0;
    double earnings;
    largeCapRate = 10;
    smallCapRate = 20;
    mediumCapRate = 15;
    stocksRate = 25;

    earnings = calculateEarnings(largeCap, largeCapRate, years);
    totalEarnings += earnings;

    earnings = calculateEarnings(smallCap, smallCapRate, years);
    totalEarnings += earnings;

    earnings = calculateEarnings(mediumCap, mediumCapRate, years);
    totalEarnings += earnings;

    earnings = calculateEarnings(stocks, stocksRate, years);
    totalEarnings += earnings;

    cout << "Total earnings after " << years << " years: " << totalEarnings << endl;
    cout << "Total amount after " << years << " years: " << (principal + totalEarnings) << endl;
}

int main()
{
    double principal;
    int age, years;
    char choice;

    cout << "Enter your age: ";
    cin >> age;

    if (age < 0)
    {
        cout << "Invalid age! Age cannot be negative." << endl;
        return 1;
    }

    if (age >= 100)
    {
        cout << "Invalid age! Age cannot be greater than 100." << endl;
        return 1;
    }

    cout << "Enter the amount you want to invest: ";
    cin >> principal;

    if (principal <= 0)
    {
        cout << "Invalid investment amount! It must be greater than zero." << endl;
        return 1;
    }
    cout << "Enter the number of years for investment: ";
    cin >> years;

    if (years <= 0 && years > 99)
    {
        cout << "Invalid number of years! It must be greater than 0 and between 100 " << endl;
        return 1;
    }

    cout << "Would you like us to calculate the investment allocation automatically based on your age (A), or would you like to manually input the percentages (M)? (A/M): ";
    cin >> choice;

    double largeCap, smallCap, mediumCap, stocks;

    if (choice == 'A' || choice == 'a')
    {
        recommendInvestmentStrategy(age, principal, years);
    }
    else if (choice == 'M' || choice == 'm')
    {
        cout << "Enter percentage allocation for large-cap (0-100): ";
        cin >> largeCap;
        cout << "Enter percentage allocation for small-cap (0-100): ";
        cin >> smallCap;
        cout << "Enter percentage allocation for medium-cap (0-100): ";
        cin >> mediumCap;
        cout << "Enter percentage allocation for stocks (0-100): ";
        cin >> stocks;

        double totalPercentage = largeCap + smallCap + mediumCap + stocks;
        if (totalPercentage != 100)
        {
            cout << "Error: The total percentage allocation must equal 100%. Please try again." << endl;
            return 1;
        }

        double largeCapAmount = principal * (largeCap / 100);
        double smallCapAmount = principal * (smallCap / 100);
        double mediumCapAmount = principal * (mediumCap / 100);
        double stocksAmount = principal * (stocks / 100);

        cout << "Large-cap funds: " << largeCapAmount << " (" << largeCap << "%)" << endl;
        cout << "Small-cap funds: " << smallCapAmount << " (" << smallCap << "%)" << endl;
        cout << "Medium-cap funds: " << mediumCapAmount << " (" << mediumCap << "%)" << endl;
        cout << "Stocks: " << stocksAmount << " (" << stocks << "%)" << endl
             << endl;

        double totalEarnings = 0;
        double earnings;
        int years = 10;

        earnings = calculateEarnings(largeCapAmount, 10, years);
        totalEarnings += earnings;

        earnings = calculateEarnings(smallCapAmount, 20, years);
        totalEarnings += earnings;

        earnings = calculateEarnings(mediumCapAmount, 15, years);
        totalEarnings += earnings;

        earnings = calculateEarnings(stocksAmount, 25, years);
        totalEarnings += earnings;

        cout << "Total earnings after " << years << " years: " << totalEarnings << endl
             << endl;
        cout << "Total amount after " << years << " years: " << (principal + totalEarnings) << endl
             << endl;
    }
    else
    {
        cout << "Invalid choice! Please enter 'A' for automatic or 'M' for manual allocation." << endl;
        return 1;
    }

    return 0;
}
