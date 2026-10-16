#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class Emergency_res{
  private:
int resource_id;
string resource_type;
int location;
bool available;
int capacity;
public:
Emergency_res(int id,string type,int locate,int cap):
resource_id(id) ,resource_type(type),
location(locate),
available(true),capacity(cap){}

//using getterss....
int getid() const{
  return resource_id;

}

string getType() const{
  return resource_type;

}

int getlocation(){
  return location;

}

int getCapacity() const{
  return capacity;

}

bool isavaailable(){
  return available;

}

void dispatch(){
  if(available) {
    available=false;
    cout<<resource_type<<" #"<<resource_id<<" is now available.";
  }  //checks for availability...
  else{

    cout<<resource_type<<" #"<<resource_id<<" is currently busy.";

  }
}

void makeavailable(){   //it makes the resources availabel again....
  available=true;
  cout<<resource_type<<" #"<<resource_id<<" is now available."<<endl;
  cout<<"-----------------------------------------------------------"<<endl;
}

void display() const{
cout<<"Resource ID-> "<<resource_id<<endl;
cout<<"Resource Type-> "<<resource_type<<endl;
cout<<"Location ID-> "<<location<<endl;
cout<<"Capacity-> "<<capacity<<endl;
cout<<"Status "<<(available ? "Available":"Dispatched")<<endl;
}

};


int main() {
    Emergency_res truck(
        101, "Fire Truck", 0, 5000
    );

    truck.display();

    cout << "\nDispatching resource...\n";
    truck.dispatch();

    cout << "\nAfter dispatch:\n";
    truck.display();

    cout << "\nReleasing resource...\n";
    truck.makeavailable();

    return 0;
}