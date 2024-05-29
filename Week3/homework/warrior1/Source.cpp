#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;
/*   dragon,ninja,iceman,lion,wolf
num : 0        1      2      3     4
Blue: 3        0      1      2     4  lion,ragon,ninja,iceman,wolf
Red : 2        3      4      1     0  iceman,lion,wolf,ninja,dragon
*/

int original_born_order_life_value[5] = {};
class Warrior{
	int ID;
	int life_value;
	int strength;
	int headquater_type;
	int time;
public:
	Warrior(int _id, int _value, int _strength, int _type, int _time) : ID(_id), life_value(_value), strength(_strength),headquater_type(_type), time(_time){
		cout << setfill('0') << setw(3) << time<<" ";
		cout << get_headquarterstring();
		if (life_value == original_born_order_life_value[0]){
				cout << "dragon ";
			}
			else if (life_value == original_born_order_life_value[1]){
				cout << "ninja ";
			}
			else if (life_value == original_born_order_life_value[2]){
				cout << "iceman ";
			}
			else if (life_value == original_born_order_life_value[3]){

				cout << "lion ";
			}
			else if (life_value == original_born_order_life_value[4]){
				cout << "wolf ";
			}
		cout << ID;
		cout << " born with strength " << life_value << ",";
	}
	char * get_headquarterstring(){
		if (headquater_type == 0){
			return "blue ";
		}
		else{
			return  "red ";
		}
		return NULL;
	}
};
class Headquater{
	int total_life_value;
	int life_value;
	int warrior_num_of_kind[5];//the number of warrior of every kind
	int born_index;
	int born_order[5];
	int headquater_type;
	int warrior_id;
	int creation_complete;
public:
	Headquater(int _type=0, int life_value=0, int v0=0, int v1=0, int v2=0, int v3=0, int v4=0){
		total_life_value = life_value;
		born_order[0] = v0;
		born_order[1] = v1;
		born_order[2] = v2;
		born_order[3] = v3;
		born_order[4] = v4;
		born_index = 0;
		life_value = 0; warrior_num_of_kind[0] = warrior_num_of_kind[1] = warrior_num_of_kind[2] = warrior_num_of_kind[3] = warrior_num_of_kind[4] = 0;
		headquater_type = _type;
		warrior_id = 0;
        creation_complete = 0;
	}
	void print_warrior_bornorder(void){
		if (headquater_type == 0){
			cout << "blue: ";
		}else{
			cout << "red: ";
		}
		for (int i = 0; i < 5; i++){
			if (born_order[i] == original_born_order_life_value[0]){
				cout << "dragon ";
			}
			else if (born_order[i] == original_born_order_life_value[1]){
				cout << "ninja ";
			}
			else if (born_order[i] == original_born_order_life_value[2]){
				cout << "iceman ";
			}
			else if (born_order[i] == original_born_order_life_value[3]){

				cout << "lion ";
			}
			else if (born_order[i] == original_born_order_life_value[4]){
				cout << "wolf ";
			}
		}
		cout << endl;
	}
	char * get_warriorkindstring(int born_index){
		for (int i = 0; i < 5; i++){
			if (born_index == original_born_order_life_value[0]){
				return "dragon ";
			}
			else if (born_index == original_born_order_life_value[1]){
				return "ninja ";
			}
			else if (born_index == original_born_order_life_value[2]){
				return "iceman ";
			}
			else if (born_index == original_born_order_life_value[3]){

				return "lion ";
			}
			else if (born_index == original_born_order_life_value[4]){
				return "wolf ";
			}
		}
			return NULL;
	}
		char * get_headquarterstring(){
			if (headquater_type == 0){
				return "blue ";
			}
			else{
				return  "red ";
			}
			return NULL;
		}
	void create_warrior(int time){
		int turn = 0;
		if (creation_complete == 1)return;

		for (turn = 0; turn < 5; turn++){
			if (total_life_value >= born_order[born_index]){
				warrior_id = warrior_id + 1;
				//create warrior
				Warrior w(warrior_id, born_order[born_index], born_order[born_index],headquater_type, time);
				//Warrior w();
				warrior_num_of_kind[born_index] = warrior_num_of_kind[born_index] + 1;
				total_life_value -= born_order[born_index];
				cout << warrior_num_of_kind[born_index] << " " << get_warriorkindstring(born_order[born_index]) << "in " << get_headquarterstring() << "headquarter" << endl;
				born_index++;
				born_index %= 5;
				break;
			}
			born_index++;
			born_index %= 5;
		}
		if (turn == 5){
			cout << setfill('0') << setw(3) << time << " ";
			cout << get_headquarterstring() << "headquarter stops making warriors" << endl;
			creation_complete = 1;
		}
	}
};
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
		Blues_ptr[mycase] = Headquater(0, total_life_value, original_born_order_life_value[3], original_born_order_life_value[0], original_born_order_life_value[1], original_born_order_life_value[2], original_born_order_life_value[4]);
		Reds_ptr[mycase] = Headquater(1, total_life_value, original_born_order_life_value[2], original_born_order_life_value[3], original_born_order_life_value[4], original_born_order_life_value[1], original_born_order_life_value[0]);
		/*	Blue.print_warrior_bornorder();
			Red.print_warrior_bornorder();
			*/	
		cout << "Case:" << mycase+1 << endl;
		for (int i = 0; i < 10000; i++){

			Reds_ptr[mycase].create_warrior(i);
			Blues_ptr[mycase].create_warrior(i);

		}
	}
	delete[] Blues_ptr;
	delete[] Reds_ptr;
	return 0;
}
