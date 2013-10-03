#include <iostream>
#include "Mountains.h"
#include "Container.h"
#include <cstdlib>


using namespace std;

template<typename T>
class DataBase: public Container<T>
{
public:
    void show();
};


template<typename T>
void DataBase<T>::show()
{
    system("clear");
    int current_size = this->get_size();
    cout<<"Название:";
    for(int j=0; j<11; ++j)
        cout<<' ';
    cout<<"Месторасположение:";
    for(int j=0; j<2; ++j)
        cout<<' ';
    cout<<"Высота:\n\n";

    for(int i=0; i<current_size; ++i)
    {
        T temp=this->get_data(i);

        cout<<temp.get_name();
        for(int j=0; j<20-temp.get_name().length()/2; ++j)
            cout<<'.';
        cout<<temp.get_location();
        for(int j=0; j<20-temp.get_location().length()/2; ++j)
            cout<<'.';
        cout<<temp.get_hight()<<endl;
        cout<<endl;
    }
}

int main()
{
    char answ='\0';
    while(answ!='q')
    {

        cout<<"Создать(z) или загрузить(d) Базу Данных? Выход - (q)\n";
        cin>>answ;
        system("clear");

        DataBase<Mountain> dataBase;
        if(answ=='c' || answ=='d' || answ=='q')
            while(answ != 'q')
            {

                if(answ!='z')
                    dataBase.load("file1");
                else
                {
                    int N;
                    cout<<"\nКак много данных вы хотите добавить?\n";
                    cin>>N;

                    string name;
                    string location;
                    int hight;

                    for(int i=0; i<N; ++i)
                    {
                        cout<<"\nВеведие имя "<<i+1<<" горы: ";
                        cin>>name;
                        cout<<"\nВеведие иестоположение "<<i+1<<" горы: ";
                        cin>>location;
                        cout<<"\nВеведие высоту "<<i<<" горы: ";
                        cin>>hight;

                        Mountain tempMountain(name,location,hight);

                        dataBase.add(tempMountain);
                        system("clear");
                        cout<<"\nДобавлено\n";
                    }
                }
                cout<<"\nЧто вы желает сделать?\n";

                cout<<"\na)Показать БД\n";
                cout<<"\nb)Добавить элемент в БД\n";
                cout<<"\nc)Удалить i-й элемент в БД\n";
                cout<<"\nd)Отсортировать БД\n";
                cout<<"\ne)Сохранить БД\n";
                cout<<"\nq)Выход\n";

                cin>>answ;
                switch(answ)
                {
                case 'a':
                    dataBase.show();
                    break;
                case 'b':
                {
                    string name;
                    string location;
                    int hight;

                    cout<<"\nВеведие имя горы: ";
                    cin>>name;
                    cout<<"\nВеведие иестоположение горы: ";
                    cin>>location;
                    cout<<"\nВеведие высоту горы: ";
                    cin>>hight;

                    Mountain tempMountain(name,location,hight);

                    dataBase.add(tempMountain);
                    cout<<"\nДобавлено\n";
                    system("clear");
                }
                break;
                case 'c':
                {
                    int i;
                    cout<<"Какой элемент удалить?";
                    cin>>i;
                    --i;
                    dataBase.remove(i);
                    cout<<"Удалено";
                    system("clear");
                }
                break;
                case 'd':
                {
                    cout<<"По какому признаку? Имя(n), Локация(l), Высота(h)";
                    cin>>answ;
                    switch(answ)
                    {
                    case 'n':
                        dataBase.sort("name");
                        break;
                    case 'l':
                        dataBase.sort("location");
                        break;
                    case 'h':
                        dataBase.sort("hight");
                        break;
                    }
                    system("clear");
                    cout<<"\nОтсортировано\n";
                }
                break;
                case 'e':
                    dataBase.save("file2");
                    system("clear");
                    cout<<"\nСохранено\n";
                    break;
                }

            }
    }
    return 0;
}
