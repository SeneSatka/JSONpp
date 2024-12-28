#include <map>
#include <iostream>
#include "utils.h"
using std::map, std::string;
class Json
{
public:
    Json() {}
    string stringfy() {}
    void parse(string text)
    {
        string part = "";
        string key = "";
        string value = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ',' && text[i] != '}' && text[i] != '{')
                part += text[i];
            else if (text[i] == ',' || text[i] == '}')
            {
                for (int j = 0; j < part.length(); j++)
                {
                    if (part[j] == ':')
                    {
                        key = part.substr(1, j - 2);
                        value = part.substr(j + 1, (part.length()));
                        break;
                    }
                }
                if (is_number(value))
                {
                    // set(key.c_str(), stoi(value));
                }
                else if (is_bool(value))
                {
                    // set(key.data(), value == "true");
                }
                else
                {
                    value = value.substr(1, value.length() - 2);
                    std::cout << value << std::endl;
                    set(key.data(), value.c_str());
                }
                // std::cout << part << std::endl;
                // std::cout << key << ":" << value << std::endl;

                part = "";
            }
        }
    }
    void set(const char *key, char *value)
    {

        charData[key] = value;
    }
    void set(const char *key, string value)
    {
        charData[key] = value.data();
    }
    void set(const char *key, int value)
    {
        intData[key] = value;
    }
    void set(const char *key, float value)
    {
        floatData[key] = value;
    }
    void set(const char *key, bool value)
    {
        boolData[key] = value;
    }
    string getString(const char *key)
    {
        return charData[key];
    }
    int getInt(const char *key)
    {
        return intData[key];
    }
    float getFloat(const char *key)
    {
        return floatData[key];
    }
    bool getBool(const char *key)
    {
        return boolData[key];
    }

private:
    map<const char *, char *> charData;
    map<const char *, int> intData;
    map<const char *, float> floatData;
    map<const char *, bool> boolData;
};