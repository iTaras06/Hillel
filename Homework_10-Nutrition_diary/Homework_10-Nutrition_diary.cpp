#include <iostream>

const short days = 7;
const short max_meals = 10;

short calories[days][max_meals] = {};
short mealCount[days] = {};


void inputCalories(short calories[][max_meals], short mealCount[])
{
        for (short day = 0; day < days; ++day)
        {
            std::cout << "\nDay " << day + 1 << ". Enter number of meals: ";
            std::cin >> mealCount[day];

            for (short meal = 0; meal < mealCount[day]; ++meal)
            {
                std::cout << "  dinner " << meal + 1 << ": Enter number of calories: ";
                std::cin >> calories[day][meal];
            }
        }
}

void showStatistics(short calories[][max_meals], short mealCount[])
{
        short totalWeekCalories = 0;
        short totalDayCalories = 0;
        short totalMeals = 0;
        short maxDay = 0, minDay = 0;
        short maxCalories = 0, minCalories = 0;
        short avgMealCalories = 0;
        short avgDailyCalories = 0;
        short caloriesPerDay[days] = {};

        std::cout << "Total number of calories every day\n";
        for (short day = 0; day < days; ++day)
        {
            for (short meal = 0; meal < mealCount[day]; ++meal)
            {
                totalDayCalories += calories[day][meal];
            }
            std::cout << "Day " << day + 1 <<  ": " << totalDayCalories << "\n";

            caloriesPerDay[day] = totalDayCalories;


            totalWeekCalories += totalDayCalories;
            totalDayCalories = 0;
        }

        for (short meal = 0; meal < days; ++meal)
        {
            totalMeals += mealCount[meal];
        }
        avgMealCalories = totalWeekCalories / totalMeals;

        std::cout << "Average number of calories per meal: ";
        std::cout << avgMealCalories << "\n";
        std::cout << std::endl;

        maxCalories = caloriesPerDay[0];
        minCalories = caloriesPerDay[0];
        for (short day = 0; day < days; ++day)
        {
            if (caloriesPerDay[day] > maxCalories)
            {
                maxCalories = caloriesPerDay[day];
                maxDay = day;
            }
            if (caloriesPerDay[day] < minCalories)
            {
                minCalories = caloriesPerDay[day];
                minDay = day;
            }
        }
        std::cout << "Day with the maximum number of calories: " << maxDay + 1 << "\n";
        std::cout << "Day with the minimum number of calories: " << minDay + 1 << "\n";
        avgDailyCalories = totalWeekCalories / days;
        std::cout << "Your average daily number of calories intake: " << avgDailyCalories << "\n";
        if (avgDailyCalories < 1200)
        {
            std::cout << "Unfortunately, it's not enough\n";
        }
        if (avgDailyCalories > 2500)
        {
            std::cout << "Unfortunately, it's too much\n";
        }
        else
        {
            std::cout << "Congratulations! It's normal\n";
        }
}

int main()
{
    short choice = 0;
    do
    {
        std::cout << "\n1. Input data for the week\n";
        std::cout << "2. Show statistic\n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                inputCalories(calories, mealCount);
                break;
            case 2:
                showStatistics(calories, mealCount);
                break;
            case 3:
                std::cout << "Bye!\n";
                break;
            default:
                std::cout << "Please, try again.\n";
        }
    }
    while (choice != 3);

    return 0;
}
