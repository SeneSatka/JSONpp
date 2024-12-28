#include <iostream>
using std::string;
bool is_number(string text)
{
    bool is_number = true;
    for (int i = 0; i < text.length(); i++)
    {
        if (isdigit(text[i]) == false)
        {
            is_number = false;
            break;
        }
    }
    return is_number;
}
bool is_bool(string text)
{
    return text == "true" || text == "false";
}