#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

int main() {

    std::vector<double> angles = { 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 };
    
    std::vector <std::function<void(const double&)>> functions;
    auto sinus = [](const auto& angle) {std::cout << "sin: " << sin(angle) << " "; };
    auto cosinus = [](const auto& angle) {std::cout << "cos: " << cos(angle) << " "; };
    functions.emplace_back(sinus);
    functions.emplace_back(cosinus);

    
    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }

	return 0;
}