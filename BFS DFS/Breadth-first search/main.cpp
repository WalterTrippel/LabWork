#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

int main()
{
// part 0
    int N=0;
    int **ar=0;
    int a=0, b=0;

    ifstream fin("input.txt");
    if(!fin.is_open())
        throw "File is not exist!";

    fin>>N;
    ar = new int*[N];
    for (int i=0; i<N; ++i)
        ar[i]=new int[N];

    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            ar[i][j]=0;

// part 1
    fin>>a;
    fin>>b;
    a--;
    b--;
    while(!fin.eof())
    {
        ar[a][b]=1;
        ar[b][a]=1;
        fin>>a;
        fin>>b;
        a--;
        b--;
    }
    fin.close();

// part 2
    Queue<int> queue;

    ofstream fout("output.txt");

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            if(ar[i][j])
            {
                queue.push_back(j+1);
                ar[j][i]=0;
            }
        }
        while(!queue.is_empty())
        {
            fout<<i+1<<" "<<queue.on_front()<<"\n";
            queue.pop_front();
        }
    }
    fout.close();

    for (int i=0; i<N; ++i)
        delete []ar[i];
        delete []ar;
        ar=0;

    return 0;
}
