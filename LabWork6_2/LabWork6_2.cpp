#include <iostream>
#include <string>
#include <regex> //библеотека регулярных выражений

using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите строку ниже:"<<endl;
    string input_string;
    getline(cin, input_string);
    //string input_string = "abc 123.45, x-1.23y, +456, 789.01, def";

    // Регулярное выражение для поиска вещественного числа с фиксированной точкой
    regex regex_number(R"([+-]?\d+(\.\d+)?)");
    //[+-]? - наличие + или - перед числом (необязательно)
    // "\d+(\.\d+)?" - число с фиксированной точкой "\d+" - число из одного или нескольких цифр, "\." - наличие точки
    
    smatch match;//контейнер сохраняющий совпадения из основной строки с регулярным выражением 

    if (regex_search(input_string, match, regex_number)) //Поиск соответствия из input_string с выражением в regex_number и запись в контейнер match
    {
        cout << "Найдено первое вещественное число: " << match[0] << endl;
    }else {
        cout << "Вещественное число не найдено." << endl;
    }

    return 0;
}