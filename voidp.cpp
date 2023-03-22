#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 174;
    string s = "chris";
    char c = 'a';

    void* xpr = &x;

    xpr = &c;

    cout << *((char*)xpr) << "\n";

    return 0;

}