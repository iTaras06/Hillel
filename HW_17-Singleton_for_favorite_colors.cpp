#include <iostream>

class ColorsSingleton {

private:
    static ColorsSingleton* m_instance;
    int loveColors = 0;

    ColorsSingleton() = default;

    ColorsSingleton(ColorsSingleton&) = delete;
    ColorsSingleton& operator=(ColorsSingleton&) = delete;
    ColorsSingleton(ColorsSingleton&&) = delete;
    ColorsSingleton& operator=(ColorsSingleton&&) = delete;

public:
    static ColorsSingleton* instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new ColorsSingleton();
        }
        return m_instance;
    }

    //наша функціональність

    void addColor()
    {
        std::cout << "Enter number of your favorite color: ";
        int index;
        std::cin >> index;
        int i = 1;
        i = i << index;
        loveColors = loveColors | i;

    }

    void removeColor()
    {
        if (loveColors == 0)
        {
            std::cout << "You don't have any favorite colors.\n";
            return;
        }

        printFavoriteColors();
        std::cout << "Enter number of your favorite color that you want to delete: ";

        int index;
        std::cin >> index;
        int i = 1;
        i = i << index; //смещение 1 влево на index битов

        int is_favorite = loveColors; //проверка правильности выбора любимого цвета
        is_favorite = loveColors & i; //если неправильно, то is_favorite=0

        if (!is_favorite) //если is_favorite=false
        {
            std::cout << "The color you chose is not your favorite!\n";
            return;
        }

        loveColors = loveColors ^ i;
    }

    void printFavoriteColors()
    {
        if (loveColors == 0)
        {
            std::cout << "You don't have any favorite colors.\n";
            return;
        }

        std::cout << "Your favorite colors: ";
        for (int j = 0; j < 13; ++j)
        {
            int l_C = loveColors;
            int i = 1;
            i = i << j;
            l_C = l_C & i;
            if (l_C != 0)
            {
                std::cout << j << "  ";
            }
        }
        std::cout << std::endl;
    }
};

ColorsSingleton* ColorsSingleton::m_instance = nullptr;

void show_colors()
{
    std::cout << "0. Red\n";
    std::cout << "1. Blue\n";
    std::cout << "2. Green\n";
    std::cout << "3. Yellow\n";
    std::cout << "4. Purple\n";
    std::cout << "5. Cyan\n";
    std::cout << "6. White\n";
    std::cout << "7. Black\n";
    std::cout << "8. Orange\n";
    std::cout << "9. Beige\n";
    std::cout << "10. Pink\n";
    std::cout << "11. Salad green\n";
    std::cout << "12. Grey\n";
}

int main()
{
    ColorsSingleton* s = ColorsSingleton::instance();

    int input = 0;
    while (true)
    {
        std::cout << "\n1. Add favorite color\n";
        std::cout << "2. Remove favorite color\n";
        std::cout << "3. Show favorite color\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter action number: ";
        std::cin >> input;

        if (input == 1)
        {
            show_colors();

            s->addColor();

            s->printFavoriteColors();
        }

        if (input == 2)
        {
            s->removeColor();

            s->printFavoriteColors();
        }

        if (input == 3)
        {
            s->printFavoriteColors();
        }

        if (input == 4) return 0;

        else if (input > 4 || input < 1)
        {
            std::cout << "You entered an incorrect number!\n";
        }
    }
}
