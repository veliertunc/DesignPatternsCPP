#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <cmath>
#include <map>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

class SingletonDatabase
{
private:
    map<string,int> capitals;
    SingletonDatabase(){
        cout<<"Init dn"<<endl;
        ifstream ifs("capitals.txt");
        string s,s2;
        while (getline(ifs,s))
        {
            getline(ifs,s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }
        
    }

public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;
    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }
    int get_population(const string& name){
        return capitals[name];
    }
};


void singleton_test()
{
    cout<<SingletonDatabase::get().get_population("Tokyo")<<endl;
}