#include <iostream>
#include "Json.h"
using namespace std;
string test = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

Json json = Json();

int main()
{
    string name = "John";
    // json.set("name", name);
    // json.set("age", 20);
    // cout << json.getString("name") << endl;
    // cout << json.getInt("age") << endl;
    // cout << (is_number("123") ? "true" : "false") << endl;
    json.parse(test);
    cout << json.getString("name") << endl;
    cout << json.getInt("age") << endl;
    // for (int i = 0; i < test.length(); i++)
    // {
    //     cout << test[i];
    // }
}
