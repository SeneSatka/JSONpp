#include <unordered_map>
#include <iostream>
#include "utils.h"
using namespace std;
class Json
{
public:
    Json(const string &text)
    {
        parse(text);
    }

    Json() = default;
    string stringify() const
    {
        string result = "{";
        for (const auto &it : charData)
        {
            result += "\"" + it.first + "\":\"" + it.second + "\",";
        }
        for (const auto &it : intData)
        {
            result += "\"" + it.first + "\":" + to_string(it.second) + ",";
        }
        for (const auto &it : floatData)
        {
            result += "\"" + it.first + "\":" + to_string(it.second) + ",";
        }
        for (const auto &it : boolData)
        {
            result += "\"" + it.first + "\":" + (it.second ? "true" : "false") + ",";
        }
        if (result.back() == ',')
        {
            result.pop_back();
        }
        result += "}";
        return result;
    }

    void parse(const string &text)
    {
        string part, key, value;
        for (size_t i = 0; i < text.length(); ++i)
        {
            if (text[i] != ',' && text[i] != '}' && text[i] != '{')
            {
                part += text[i];
            }
            else if (text[i] == ',' || text[i] == '}')
            {
                size_t pos = part.find(':');
                if (pos != string::npos)
                {
                    key = part.substr(1, pos - 2);
                    value = part.substr(pos + 1);
                    if (is_number(value))
                    {
                        set(key, stoi(value));
                    }
                    else if (is_bool(value))
                    {
                        set(key, value == "true");
                    }
                    else
                    {
                        value = value.substr(1, value.length() - 2);
                        set(key, value);
                    }
                }
                part.clear();
            }
        }
    }

    void set(const string &key, const string &value)
    {
        charData[key] = value;
    }

    void set(const string &key, int value)
    {
        intData[key] = value;
    }

    void set(const string &key, float value)
    {
        floatData[key] = value;
    }

    void set(const string &key, bool value)
    {
        boolData[key] = value;
    }

    string getString(const string &key) const
    {
        return charData.at(key);
    }

    int getInt(const string &key) const
    {
        return intData.at(key);
    }

    float getFloat(const string &key) const
    {
        return floatData.at(key);
    }

    bool getBool(const string &key) const
    {
        return boolData.at(key);
    }

    void remove(const string &key)
    {
        charData.erase(key);
        intData.erase(key);
        floatData.erase(key);
        boolData.erase(key);
    }

private:
    unordered_map<string, string> charData;
    unordered_map<string, int> intData;
    unordered_map<string, float> floatData;
    unordered_map<string, bool> boolData;
};
