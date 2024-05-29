#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;
/*   dragon 、ninja、iceman、lion、wolf
num : 0        1      2      3     4
Blue: 3        0      1      2     4  lion、dragon、ninja、iceman、wolf
Red : 2        3      4      1     0  iceman、lion、wolf、ninja、dragon
*/

enum Headquater_type{RED, BLUE};
int original_born_order_life_value[5];//original life value
class Warrior;

class Headquater{
	int warrior_num_of_kind[5];//the number of warrior of every kind
	int born_index;
	int born_order[5];
	int type;
	int current_warrior_id;
	bool creation_complete;
    Warrior *warrior_arr[1000];
public:
	int total_life_value;
	Headquater(int _type=BLUE, int life_value=0, int v0=0, int v1=0, int v2=0, int v3=0, int v4=0){
		total_life_value = life_value;
		born_order[0] = v0;
		born_order[1] = v1;
		born_order[2] = v2;
		born_order[3] = v3;
		born_order[4] = v4;
		born_index = 0;
        warrior_num_of_kind[0] = warrior_num_of_kind[1] = warrior_num_of_kind[2] = warrior_num_of_kind[3] = warrior_num_of_kind[4] = 0;
		type = _type;
		current_warrior_id = 0;
        creation_complete = false;
        for(int i=0; i<1000; i++){
            warrior_arr[i] = NULL;
        }
	}
    int get_total_life_value(void){return total_life_value;}
    void update_total_life_value(int life_value){
        total_life_value -= life_value;
    }
    const char * get_headquarterstring();
    void create_warrior_according_time(int time);
    Warrior * create_warrior(int warrior_id, int born_index, int time);
    void clear_headquater(void);
};
const char * Headquater::get_headquarterstring(){
    if (type == BLUE){
        return "blue";
    }
    else{
        return  "red";
    }
    return NULL;
}
class Warrior{
	int ID;
	int life_value;
    string name;
public:
	Warrior(int _id, int _value, Headquater &hd, int _time, const char *str) : ID(_id), life_value(_value){
		cout << setfill('0') << setw(3) << _time<<" ";
		cout << hd.get_headquarterstring()<<" ";
        cout <<str<<" ";
        name = str;
		cout << ID;
		cout << " born with strength " << life_value << ",";
        hd.update_total_life_value(_value);
	}
    friend ostream & operator<<(ostream &o, Warrior &w);
    virtual void show_self(void) = 0;
    virtual ~Warrior(){}
};
void Headquater::create_warrior_according_time(int time){
    int turn = 0;

    if (creation_complete == true)return;

    for (turn = 0; turn < 5; turn++){
        if (total_life_value >= born_order[born_index]){
            current_warrior_id += 1;
            //create warrior
            warrior_arr[current_warrior_id-1] = create_warrior(current_warrior_id, born_index, time);  

            warrior_num_of_kind[born_index] = warrior_num_of_kind[born_index] + 1;
            cout << warrior_num_of_kind[born_index] << " " << *(warrior_arr[current_warrior_id-1]) << " in " << get_headquarterstring() << " headquarter" << endl;
            warrior_arr[current_warrior_id-1]->show_self();
            born_index++;
            born_index %= 5;
            break;
        }
        born_index++;
        born_index %= 5;
    }
    if (turn == 5){
        cout << setfill('0') << setw(3) << time << " ";
        cout << get_headquarterstring() << " headquarter stops making warriors" << endl;
        creation_complete = true;
    }
}

string weapon_string[3] = {
    "sword",
    "bomb",
    "arrow"
};

ostream & operator<<(ostream &o, Warrior &w){
    o<< w.name;
    return o;
}

class Dragon: public Warrior{
    int weapon;
    double morale;
public:
    Dragon(int _id, int _life_value, int _time, Headquater &hd): Warrior(_id, _life_value, hd, _time, "dragon"){
        weapon = _id%3;
        morale = ((double) hd.get_total_life_value())/(double)_life_value;
    }
    void show_self(void){
        cout<<"It has a "<<weapon_string[weapon]<<","<<"and it's morale is "<<fixed<<setprecision(2)<<morale<<endl;
    }
    ~Dragon(){
    
    }
};
class Ninja: public Warrior{
    int weapon_array[2];

    public:
    Ninja(int _id, int _life_value, int _time, Headquater &hd): Warrior(_id, _life_value, hd, _time, "ninja"){
        weapon_array[0] = _id%3;
        weapon_array[1] = (_id+1)%3;
    }
    void show_self(void){
        cout<<"It has a "<<weapon_string[weapon_array[0]]<<" and a "<<weapon_string[weapon_array[1]]<<endl;
    }
    ~Ninja(){
    
    }
};
class Iceman: public Warrior{
    int weapon;

    public:
    Iceman(int _id, int _life_value, int _time, Headquater &hd): Warrior(_id, _life_value, hd, _time, "iceman"){
        weapon = _id%3;
    }
    void show_self(void){
        cout<<"It has a "<<weapon_string[weapon]<<endl;
    }
    ~Iceman(){}
};
class Lion: public Warrior{
    int loyalty;

    public:
    Lion(int _id, int _life_value, int _time, Headquater &hd): Warrior(_id, _life_value, hd, _time, "lion"){
        loyalty = hd.get_total_life_value();
    }
    void show_self(void){
        cout<<"It's loyalty is "<<loyalty<<endl;
    }
    ~Lion(){}
};
class Wolf: public Warrior{

    public:
    Wolf(int _id, int _life_value, int _time, Headquater &hd): Warrior(_id, _life_value, hd, _time, "wolf"){
    }
    void show_self(void){
    }
    ~Wolf(){}
};
Warrior * Headquater::create_warrior(int warrior_id, int born_index, int time){
    if(type == BLUE){//blue
        if (born_index == 0){
            return new Lion(warrior_id, born_order[born_index], time, *this);;
        } else if (born_index == 1){
            return new Dragon(warrior_id, born_order[born_index], time, *this);
        } else if (born_index == 2){
            return new Ninja(warrior_id, born_order[born_index], time, *this);
        } else if (born_index == 3){
            return new Iceman(warrior_id, born_order[born_index], time, *this);
        } else if (born_index == 4){
            return new Wolf(warrior_id, born_order[born_index], time, *this);
        }
    }else{
        if (born_index == 0){
            return new Iceman(warrior_id, born_order[born_index], time, *this);
        } else if (born_index == 1){
            return new Lion(warrior_id, born_order[born_index], time, *this);;
        } else if (born_index == 2){
            return new Wolf(warrior_id, born_order[born_index], time, *this);
        } else if (born_index == 3){
            return new Ninja(warrior_id, born_order[born_index], time, *this);
        } else if (born_index == 4){
            return new Dragon(warrior_id, born_order[born_index], time, *this);
        }
    }
}

void Headquater::clear_headquater(void){
    for(int i=0; i<1000; i++){
        if(warrior_arr[i] != NULL){
            delete warrior_arr[i];
        }
    }
    current_warrior_id = 0;
}
int main(){
    int test_num;
    int total_life_value = 0;
    int life_value[5];

    cin >> test_num;
    if (test_num <= 0) return -1;

    Headquater *Blues_ptr = new Headquater[test_num];
    Headquater *Reds_ptr = new Headquater[test_num];
    for (int mycase = 0; mycase < test_num; mycase ++){

        cin >> total_life_value;
        cin >> original_born_order_life_value[0] >> original_born_order_life_value[1] >> original_born_order_life_value[2] >> original_born_order_life_value[3] >> original_born_order_life_value[4];
        /*			cout << test_num << endl;
                    cout << total_life_value << endl;
                    cout << original_born_order_life_value[0] << original_born_order_life_value[1] << original_born_order_life_value[2] << original_born_order_life_value[3] << original_born_order_life_value[4] << endl;
         */			
        Blues_ptr[mycase] = Headquater(BLUE, total_life_value, original_born_order_life_value[3], original_born_order_life_value[0], original_born_order_life_value[1], original_born_order_life_value[2], original_born_order_life_value[4]);
        Reds_ptr[mycase] = Headquater(RED, total_life_value, original_born_order_life_value[2], original_born_order_life_value[3], original_born_order_life_value[4], original_born_order_life_value[1], original_born_order_life_value[0]);

        cout << "Case:" << mycase+1 << endl;
        for (int i = 0; i < 10000; i++){

            Reds_ptr[mycase].create_warrior_according_time(i);
            Blues_ptr[mycase].create_warrior_according_time(i);

        }
        Reds_ptr[mycase].clear_headquater();
        Blues_ptr[mycase].clear_headquater();
    }
    delete[] Blues_ptr;
    delete[] Reds_ptr;
    return 0;
}
