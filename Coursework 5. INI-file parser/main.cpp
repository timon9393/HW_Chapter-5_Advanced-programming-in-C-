#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <string>
#include <map>

class ini_parser
{
private:
	std::map <std::string, std::map <std::string, std::string>> data;
	std::ifstream file;
public:
	ini_parser(const std::string& filename)
	{
		file.open(filename);
		if (!file.is_open())
			throw std::runtime_error("Ошибка открытия файла!");

		std::string line, current_section;
		size_t line_number = 0;

		while (std::getline(file, line))
		{
			line_number++;
			if (line.empty() || line[0] == ';')
				continue;

			if (line.find('[') != std::string::npos || line.find(']') != std::string::npos)
			{
				if (line.find('[') != std::string::npos && line.find(']') != std::string::npos && line.find('[') < line.find(']'))
					current_section = line.substr(line.find('[') + 1, line.find(']') - line.find('[') - 1);
				else
					throw std::runtime_error("Синтаксическая ошибка в указании секции на строке " + std::to_string(line_number));
			}

			if (line.find('=') != std::string::npos)
			{
				std::string key, value;
				char ch;
				size_t count_eq = 0;
				std::istringstream iss(line);
				while (iss.get(ch))
				{
					if (ch == '=')
						count_eq++;
				}
				if (count_eq != 1)
					throw std::runtime_error("Не допускается присваивание нескольких значений на строке " + std::to_string(line_number));

				size_t pos = line.find_first_of("= ");
				size_t pos_mid;
				key = line.substr(0, pos);
				if (pos !=line.size()-1)
				{
					pos_mid = line.find_first_not_of("= ", pos);					
					std::istringstream iss_end(line.substr(pos_mid));
					if (std::getline(iss_end, value, ';'))
						data[current_section][key] = value;					
				}
				else
					data[current_section][key] = "empty";
			}
		}
	}

	template<typename T>
	T get_value(const std::string& section_key)
	{
		std::istringstream iss(section_key);
		std::string section, key;
		if (std::getline(iss, section, '.') && std::getline(iss, key))
		{
			if (data.find(section) != data.end() && data[section].find(key) != data[section].end())
			{
				if (data[section][key] == "empty")
					throw std::runtime_error("Не найдено значение для переменной '" + key + "'");

				T value;
				return result(value, section, key);
			}
			else
			{
				std::string available_keys = "Доступные переменные в секции '" + section + "': ";
				for (const auto& el : data[section])
					available_keys += el.first + " ";

				throw std::runtime_error("Не найдено значение для переменной '" + key + "'. " + available_keys);
			}
		}
		else
			throw std::invalid_argument("Некорректный формат введённых данных!");
	}

	template <typename T>
	T result(T& value, const std::string& section, const std::string& key)
	{
		std::istringstream(data[section][key]) >> value;
		return value;
	}

	template<>
	std::string result(std::string& value, const std::string& section, const std::string& key)
	{
		std::getline(std::istringstream(data[section][key]), value);
		return value;
	}

	~ini_parser()
	{
		file.close();
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		ini_parser parser("config.ini");
		auto value = parser.get_value<int>("Section1.var1");
		std::cout << "Запрашиваемое значение: " << value << std::endl;
	}
	catch (const std::exception& ex) {
		       std::cerr << ex.what() << std::endl;
		    }
	return 0;
}
