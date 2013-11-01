#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED
#include <fstream>
#include <string>
#include <ctime>
#include <exception>

template<typename T>
class Container
{
public:
    Container();
    ~Container();
    void add(const T data);
    void remove(int number_of_data);
    void sort(std::string by_what);
    T get_data(int number) const;
    void save(char const * filename);
    void load(char const * filename);
    int get_size();
private:
    int size;
    T **container;
};

template<typename T>
Container<T>::Container():
    size(0), container(0)
{
}

template<typename T>
void Container<T>::add(const T data)
{
    T **temp_container=0;
    temp_container = new T*[size+1];
    for(int i=0; i<size+1; ++i)
        temp_container[i]=new T;

    for(int i=0; i<size; ++i)
        *temp_container[i]=*container[i];
    *temp_container[size]=data;

    for(int i=0; i<size; ++i)
    {
        delete container[i];
        container[i]=0;
    }
    delete []container;
    container=0;

    ++size;

    container = new T*[size];
    for(int i=0; i<size; ++i)
        container[i]=new T;

    for(int i=0; i<size; ++i)
        *container[i]=*temp_container[i];

    for(int i=0; i<size; ++i)
    {
        delete temp_container[i];
        temp_container[i]=0;
    }
    delete []temp_container;
    temp_container=0;
}

template<typename T>
void Container<T>::remove(int number)
{
    if(number>=0 && number<size)
    {
        T **temp_container=0;

        temp_container = new T*[size-1];
        for(int i=0; i<size-1; ++i)
            temp_container[i]=new T;

        for(int i=0; i<number; ++i)
            *temp_container[i]=*container[i];
        for(int i=number+1; i<size; ++i)
            *temp_container[i-1]=*container[i];

        for(int i=0; i<size; ++i)
        {
            delete container[i];
            container[i]=0;
        }
        delete []container;
        container=0;

        --size;

        container = new T*[size];
        for(int i=0; i<size; ++i)
            container[i]=new T;

        for(int i=0; i<size; ++i)
            *container[i]=*temp_container[i];

        for(int i=0; i<size; ++i)
        {
            delete temp_container[i];
            temp_container[i]=0;
        }
        delete []temp_container;
        temp_container=0;
    }
}

template<typename T>
T Container<T>::get_data(int number) const
{
    if(number>=0 && number<size)
        return *container[number];
    else
        throw -1;

}

template<typename T>
void Container<T>::save(char const * filename)
{
    if(size)
    {
        std::ofstream fout(filename);
        for(int i=0; i<size; ++i)
        {
            fout<<container[i]->get_name();
            fout<<" ";
            fout<<container[i]->get_location();
            fout<<" ";
            fout<<container[i]->get_hight();
            fout<<"\n";
        }
        fout.close();
    }
    else throw -1;
}

template<typename T>
void Container<T>::load(char const *filename)
{
    if(!size)
    {
        std::ifstream fin(filename);
        std::string name;
        std::string location;
        int hight;

        fin>>name;
        fin>>location;
        fin>>hight;
        T temp0(name,location, hight);

        while(!fin.eof())
        {
            T temp(name,location,hight);
            temp0=temp;
            add(temp0);

            fin>>name;
            fin>>location;
            fin>>hight;
        }
        fin.close();
    }
}

template<typename T>
Container<T>::~Container()
{
    for(int i=0; i<size; ++i)
    {
        delete container[i];
        container[i]=0;
    }
    delete []container;
    container=0;
    size=0;
}

template<typename T>
void qsort(T **container, int l, int r, int (*comparison)(T &, T &));

template<typename T>
int cmp_by_hight(T &x, T &y)
{

    if(x.get_hight() != y.get_hight())
        return x.get_hight() > y.get_hight()?1:-1;
    else return 0;

}

template<typename T>
int cmp_by_name(T &x, T &y)
{

    if(x.get_name() != y.get_name())
        return x.get_name() > y.get_name()?1:-1;
    else return 0;

}

template<typename T>
int cmp_by_location(T &x, T &y)
{

    if(x.get_location() != y.get_location())
        return x.get_location() > y.get_location()?1:-1;
    else return 0;

}

template<typename T>
void Container<T>::sort(std::string by_what)
{
    if(by_what=="name")
        qsort(container,0,size-1,cmp_by_name);
    else
    {
        if(by_what=="location")
            qsort(container,0,size-1,cmp_by_location);
        else if(by_what=="hight")
            qsort(container,0,size-1,cmp_by_hight);
        else throw -1;
    }
}

template<typename T>
void qsort(T **con, int l, int r, int (*comparison)(T &, T &))
{
    T x = *con[l + (r - l)/2 ];

    int i = l;
    int j = r;

    while(i <= j)
    {
        while(comparison(*con[i], x)<0) i++;
        while(comparison(*con[j], x)>0) j--;
        if(i <= j)
        {
            swap(con[i], con[j]);
            i++;
            j--;
        }
    }
    if (i<r)
        qsort(con, i, r, comparison);

    if (l<j)
        qsort(con, l, j, comparison);
}

template<typename T>
void swap(T *&x, T *&y)
{
    T *tmp;
    tmp=x;
    x=y;
    y=tmp;
}

template<typename T>
int Container<T>::get_size()
{
    return size;
}

#endif // CONTAINER_H_INCLUDED
