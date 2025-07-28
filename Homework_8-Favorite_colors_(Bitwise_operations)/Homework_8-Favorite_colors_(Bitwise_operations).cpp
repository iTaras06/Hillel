#include <iostream>

void show_colors()
{
    std::cout << "Enter number to select your favorite color" << std::endl;
    std::cout << "0. Red" << std::endl;
    std::cout << "1. Blue" << std::endl;
    std::cout << "2. Green" << std::endl;
    std::cout << "3. Yellow" << std::endl;
    std::cout << "4. Purple" << std::endl;
    std::cout << "5. Cyan" << std::endl;
    std::cout << "6. White" << std::endl;
    std::cout << "7. Black" << std::endl;
    std::cout << "8. Orange" << std::endl;
    std::cout << "9. Beige" << std::endl;
    std::cout << "10. Pink" << std::endl;
    std::cout << "11. Salad green" << std::endl;
    std::cout << "12. Grey" << std::endl;
}

void show_favorite_colors(int love_colors)
{
    std::cout << "Your favorite colors are: ";

    for (int j = 0; j <= 12; ++j)
    {
        int l_c = love_colors;
        int i = 1;
        i = i << j;
        l_c = l_c & i;
        if (l_c)
        {
            std::cout << j << "  ";
        }
    }
    std::cout << std::endl;

}

int main()
{
    int input = 0;
    int index = 0;
    int love_colors = 0;
    while (true)
    {
        std::cout << "\n1. Add favorite color" << std::endl;
        std::cout << "2. Remove favorite color" << std::endl;
        std::cout << "3. Show favorite color" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> input;
        if (1 == input)
        {
            show_colors();
            std::cin >> index;
            int i = 1;
            i = i << index;
            love_colors = love_colors | i;

            show_favorite_colors(love_colors);
        }
        if (2 == input)
        {
            if (love_colors == 0)
            {
                std::cout << "You don't have any favorite colors yet\n";
                continue;
            }
            show_favorite_colors(love_colors);
            std::cout << "Enter number to delete your favorite color: ";
            std::cin >> index;
            int i = 1;
            i = i << index;
            love_colors = love_colors ^ i;

            show_favorite_colors(love_colors); 
        }
        if (3 == input)
        {
            if (love_colors == 0)
            {
                std::cout << "You don't have any favorite colors yet\n";
                continue;
            }
            show_favorite_colors(love_colors);
        }
        if (4 == input)
        {
            return 0;
        }
        else if(input<=0||input>=5)
        {
            std::cout << "You entered incorrect number\n";
        }
    }
}
