#include <iostream>
#include <string>

class big_integer {
private:
    std::string num;
public:
    big_integer() {}

    big_integer(std::string num) : num(num) {}

    big_integer(const big_integer& other) : num(other.num) {}

    big_integer(big_integer&& other) noexcept : num(std::move(other.num)) {}

    big_integer& operator=(const big_integer& other) {
        if (this != &other) {
            num = other.num;
        }
        return *this;
    }

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            num = std::move(other.num);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        int carry = 0;
        std::string res;
        int i = num.length() - 1;
        int j = other.num.length() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += other.num[j] - '0';
                j--;
            }
            carry = sum / 10;
            sum = sum % 10;
            res = std::to_string(sum) + res;
        }

        return big_integer(res);
    }

    big_integer operator*(int n) const {
        int carry = 0;
        std::string res;

        for (int i = num.length() - 1; i >= 0 || carry > 0; i--) {
            int product = carry;
            if (i >= 0) {
                product += (num[i] - '0') * n;
            }
            carry = product / 10;
            product = product % 10;
            res = std::to_string(product) + res;
        }

        return big_integer(res);
    }

    friend big_integer operator*(int n, const big_integer& other)
    {
        return other * n;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& bi) {
        os << bi.num;
        return os;
    }
};

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099

    return 0;
}