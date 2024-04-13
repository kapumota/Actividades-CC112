#include <iostream>
using namespace std;
int main()
{
    int* ptr= new int(69);
    char* cr = reinterpret_cast<char*>(ptr);
    cout << *ptr << endl;
    cout << *cr << endl;
    cout << ptr << endl;
    cout << cr << endl;
    
    return 0;
}
