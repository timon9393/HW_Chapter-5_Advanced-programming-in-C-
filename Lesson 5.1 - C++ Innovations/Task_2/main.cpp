#include <iostream>
#include <vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    auto value = get_variant();
    if (std::holds_alternative<int>(value))
        std::cout << std::get<int>(value) * 2 << std::endl;

    else if (std::holds_alternative<std::string>(value))
        std::cout << std::get<std::string>(value) << std::endl;

    else if (std::holds_alternative<std::vector<int>>(value))
    {
        for (int x : std::get<std::vector<int>>(value))
            std::cout << x << " ";
        std::cout << std::endl;
    }

    else
        std::cout << "Unknown problem" << std::endl;
        
    return 0;
}