#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <cmath>

using namespace std;

struct Address
{
    string street,city;
    int suite;
    Address(const string& street,const string&city,int suite):street(street),city(city),suite(suite){}
    Address(const Address& other):street(other.street),city(other.city),suite(other.suite){}
    friend ostream& operator <<(ostream &os,const Address &address){
        os << "street:" << address.street << " city: "<<address.city<<" suite: "<< address.suite;
        return os;
    } 
};

struct Contact
{
    string name;
    Address* address;
    Contact(const string& name, Address* address) : name(name),address(address){}
    Contact(const Contact& other)
    :name(other.name),
    address{new Address{*other.address}}
    {}
    ~Contact(){delete address;}
    friend ostream& operator <<(ostream &os,const Contact &contact){
        os << "name:" << contact.name<<" address: "<<*contact.address;
        return os;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee
        (const string& name, const int suite){
            static Contact p {"", new Address{"123 East Drv", "London", 0}};
            return new_employee(name,suite,p);
        }
    private:
    static unique_ptr<Contact> new_employee(const string&name,const int suite, const Contact& prototype){
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};


void prototype_test(){
    /*Contact john{"John Doe", new Address{"123 East Drv","London",123}};
    Contact jane{"Jane Smith", Address{"123 East Drv","London",103}};//Instead of this use a prototype
    Contact jane = john;
    Contact jane{john};
    jane.name = "Jane Smith";
    jane.address->suite = 103;//Because of = addresses have same pointer value. This line will change the room address of the john as well
    cout<<john<<endl<<jane<<endl;*/
    auto john = EmployeeFactory::new_main_office_employee("John",123);
    cout<<*john<<endl;
}
