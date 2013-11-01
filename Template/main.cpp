#include <iostream>


#include "T.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("test.in");

    ofstream fout;
    fout.open("test.out");

    Stack <double>s;
    char operation;
    double element;

    fin>>operation;

    while(!(fin.eof()))
    {
        if (operation=='i')
        {
            fin>>element;
            s.push(element);
        }
        else if (operation=='o')
        {
            if(!s.is_empty())
            {
                fout<<s.on_top()<<"\n";
                s.pop();
            }
            else fout<<"error\n";
        }
        else
        {
            fout<<"\n\n\nError with file reading!\n\nFix your 'input.txt'\n";
            return 0;
        }

        fin>>operation;
    }

    fin.close();

    if (s.is_empty())
        fout<<"empty\n";
    else
        fout<<"nonempty\n";

    s.clear();

    if (s.is_empty())
        fout<<"empty\n";
    else
        fout<<"nonempty\n";

    fout.close();

    return 0;
}


