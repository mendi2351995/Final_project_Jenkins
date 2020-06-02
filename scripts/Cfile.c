#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> CommandLineStringArgs;

int main(int argc, char *argv[])
{
    CommandLineStringArgs cmdlineStringArgs(&argv[0], &argv[0 + argc]);

    for (int i = 0; i < cmdlineStringArgs.size(); ++i)
    {
        cout << cmdlineStringArgs[i] << endl;
    }

    return 0;
}
