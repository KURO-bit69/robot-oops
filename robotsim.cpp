#include <iostream>
#include <vector>

class  robotbase{
    private:
    std::string name;
    int battery;

    public:
    robotbase(std::string name, int battery){
        this->battery = battery;
        this->name = name;
    }

    virtual ~robotbase(){}  


    std::string getname(){
        return name;
    }
    int getbattery(){
        return battery;
    }

    virtual void move(){
        std::cout<<getname()<<" IS MOVING"<<std::endl;
    }

    void displaystatus(){
        std::cout<<"NAME :"<<getname()<<std::endl;
        std::cout<<"BATTERY LEVEL: "<<getbattery()<<std::endl;
    }
};

class mobilerobot : public robotbase{
    private:
    int speed;

    public:
    mobilerobot(std::string name,int battery,int speed) : robotbase(name,battery){
        this->speed = speed;
    }

    void move(){
        std::cout<<getname()<<" IS DRIVING AT "<<speed<<"KM/H"<<std::endl;
    }
};

class robotjoints : public robotbase{
    private:
    int numjoints;

    public:
    robotjoints(std::string name, int battery, int numjoints) : robotbase(name,battery){
        this->numjoints = numjoints;
    }

    void move(){
        std::cout<<getname()<<" IS ROTATING "<<numjoints<<" JOINTS"<<std::endl;
    }
    
};

int main(){

    std::vector<robotbase*> robot1;

    robot1.push_back(new mobilerobot("KURO",100,50));
    robot1.push_back(new robotjoints("KURO ARM",90,6));

    
    for(int i = 0;i<robot1.size();i++){

        robot1[i]->displaystatus(); 
        robot1[i]->move();
        
    }
    return 0;
}