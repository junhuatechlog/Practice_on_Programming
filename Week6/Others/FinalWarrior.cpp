#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//dragon ?ninja?iceman?lion?wolf ?????0~4??
FILE *stream;
int M=0, N=0, R=0, K=0, T=0, gametime, key;
int Num[2];
int order[2][5]={{2,3,4,1,0},
                 {3,0,1,2,4}};//Red, Blue
int original_elem[5]={0,0,0,0,0};
int ori_force[5]={0,0,0,0,0};
char name[5][7] = {"dragon","ninja","iceman","lion","wolf"};
char headname[2][5]={"red","blue"};
char weapname[3][6]={"sword", "bomb","arrow"};

enum Headquater_type{RED, BLUE};
enum Weapon_type{SWORD, BOMB, ARROW};
enum Warrior_type{DRAGON, NINJA, ICEMAN, LION, WOLF};
enum FIGHTBACK_TYPE{DONOTHING, FIGHTBACK};

class CWeapon {
    public:
        int type;//weapon type
        int force;//weapon's initial force
        int times;//maximual times
        bool avilable;//is it still can be used
        CWeapon(int _type = 0,int _force=0)
        {
            type = _type;
            if(type != ARROW) {//sword or bomb
                int k;
                if(_type == SWORD) k = _force; else k = R;
                if(k == 0)
                    avilable = false;
                else {

                    if(type == SWORD) {
                        force = k*0.2;
                    }else if(_type == BOMB) {    
                        force = k;
                    }
                    times = 0;
                    avilable = true;
                }
            } else {//Arrow
                force = 0;//??bomb????-1
                times = 0;
                avilable = true;
            }
        }
        void CWeaponCopy(CWeapon *P)
        {
            type = P->type;
            force = P->force;
            times = P->times; 
            avilable = P->avilable;
        }
        void attack(){//
            switch(type) {
                case SWORD:
                    times ++;
                    force *= 0.8;
                    if(force == 0)
                        avilable = false;
                    break;
                case BOMB:
                    times ++;
                    if(times == 1)
                        avilable = false;
                    break;
                case ARROW:
                    times ++;
                    if(times == 3)
                        avilable = false;
                    break;
            }
        }
};

class CWarrior {
    public:
        int sort;//?????
        int color;//Red or Blue
        int ID;//
        int elements;//??????
        CWeapon * wp[3];//??
        double morale;//??
        int loyalty;//???
        int force;//???
        CWarrior(int _type,int n,double mor,int loy,int _color)//warrior type, id, morale, loyality, color
        {
            color = _color;
            sort = _type;
            ID = n;
            elements = original_elem[_type%5];
            force = ori_force[_type%5];
            for(int i=0; i<3; i++){
                wp[i]= NULL;
            }
            switch(_type)
            {
                case DRAGON:
                    wp[n%3] = new CWeapon(n%3,force);
                    morale = mor;
                    break;
                case NINJA:
                    wp[n%3] = new CWeapon(n%3,force);
                    wp[(n+1)%3] = new CWeapon((n+1)%3,force);
                    break;
                case ICEMAN:
                    wp[n%3] = new CWeapon(n%3,force);
                    break;
                case LION:
                    loyalty = loy;
                    break;
                case WOLF:
                    break;
            }
            if(wp[0] != NULL){
                if(wp[0]->force == 0)
                {
                    delete wp[0];
                    wp[0] = NULL;
                }
            }

        }
        bool IsThereWeapon(int kind)
        {
            if(wp[kind] == NULL)
                return false;
            else 
                return true;
        }
        void attacked(int a)
        {
            elements -= a;
            if(elements < 0)
                elements = 0;
        }
        void attack(CWarrior *A) //
        {
            int force_of_attacker = force + (IsThereWeapon(SWORD)? wp[SWORD]->force : 0);
            if(A->sort == LION && (A->elements -force_of_attacker <= 0)){
            //    printf("elem: %d, attacked(Lion) elem: %d\n", elements, A->elements);
                elements += A->elements;
            
            }
            A->attacked(force_of_attacker);
            if(IsThereWeapon(SWORD))
            {
                wp[SWORD]->attack();
                if(wp[SWORD]->avilable == false)
                {
                    delete wp[SWORD];
                    wp[SWORD] = NULL;
                }
            }
            if(sort == DRAGON) {

                if(A->elements == 0)
                    morale += 0.2;
                else
                    morale -= 0.2;
            }
            if(sort == WOLF) {

                if(A->elements == 0)
                    CWeaponTake(A);
            }
        }
        int fightback(CWarrior *A)
        {
            int force_of_attacked = force/2 + (IsThereWeapon(SWORD)?wp[SWORD]->force :0);

            if(sort == NINJA)
                return 0;//ninja do nothing

            if(A->sort == LION && (A->elements - force_of_attacked <= 0))
                elements += A->elements;
            A->attacked(force_of_attacked);
            if(IsThereWeapon(SWORD))
            {
                wp[SWORD]->attack();
                if(wp[SWORD]->avilable == false)
                {
                    delete wp[SWORD];
                    wp[SWORD] = NULL;
                }
            }
            if(sort == DRAGON)
            {
                if(A->elements == 0)
                    morale += 0.2;
                else
                    morale -= 0.2;
            }
            if(sort == WOLF) 
            {
                if(A->elements == 0)
                    CWeaponTake(A);
            }
            return 1;
        }
        void LoyaltyDown()
        {
            loyalty -= K;
        }
        bool escape() {
            if(sort == LION){
                if(loyalty <= 0) {  
                    return true;
                }
            }
            return false;
        }
        bool yell()
        {
            if(morale > 0.8)
                return true;
            else 
                return false;
        }
        void IcemanChange() //iceman???????
        {
            force += 20;
            elements -= 9;
            if(elements <= 0)
                elements = 1;
        }
        bool bombjudge(int r,CWarrior *A)//need use bomb
        {
            if(A->elements == 0)
                return false;
            if(r == 0)
            {
                if(A->sort == NINJA)
                    return false;
                if(force + (IsThereWeapon(SWORD)?wp[SWORD]->force :0) >= A->elements)//killed, don't need to use bomb
                    return false;
                if(A->force/2 + (A->IsThereWeapon(SWORD)?A->wp[SWORD]->force :0) >= elements)
                    return true;
                else
                    return false;
            }
            else
            {
                if(A->force + (A->IsThereWeapon(SWORD)?A->wp[SWORD]->force :0) >= elements)
                    return true;
                else
                    return false;
            }
        }
        void bomb(CWarrior *A) //bombing a enemy
        {
            A->elements = 0;
            elements = 0;
            delete wp[BOMB];
            wp[BOMB] = NULL;
        }
        void arrow(CWarrior *A)
        {
            A->attacked(R);
            if(A->elements >0)
            {
                printf("%.3d:35 %s %s %d shot\n",gametime/60,headname[color],name[sort],ID);
            } else {
                printf("%.3d:35 %s %s %d shot and killed %s %s %d\n",
                        gametime/60,headname[color],name[sort],ID,headname[A->color],name[A->sort],A->ID);
            }
            wp[2]->attack();
            if(wp[2]->avilable == false)
            {
                delete wp[2];
                wp[2] = NULL;
            }
        }
        void CWeaponTake(CWarrior *A)//wolf get the weapon from enemy
        {
            for(int i=0; i<3; i++)
            {
                if(wp[i] == NULL && A->wp[i] != NULL)
                {
                    wp[i] = new CWeapon();
                    wp[i]->CWeaponCopy(A->wp[i]);
                }
            }
        }
};
CWarrior *warrior[2][1000];

class City {

    public:
        int elem;//???
        int flag; //??0,??1,??-1
        int red_num;//?????????????,?????-1
        int blue_num;//?????????????,?????-1
        int NO;
        int BattleResult[2];//??????????,???????-1,????0,????1,???2
        City(int n)
        {
            NO = n;
            elem = 0;
            flag = -1;
            red_num = -1;
            blue_num = -1;
            BattleResult[0] = -1;
            BattleResult[1] = -1;
        }
        int LoseElem()
        {
            int a = elem;
            elem = 0;
            return a;
        }
        void FlagUp()//??????????
        {
            if(BattleResult[1] == BattleResult[0] && BattleResult[1] != 2)
                if(BattleResult[1] != flag)
                {
                    flag = BattleResult[1];
                    printf("%.3d:40 %s flag raised in city %d\n",gametime/60,headname[flag],NO);
                }
        }
        void ElemUp()
        {
            elem += 10;
        }
        void BattleOver()
        {
            if(BattleResult[1] != -1)
                BattleResult[0] = BattleResult[1];
            BattleResult[1] = -1;
        }
        int Battle() //??????????,????-1,0,1?2,????????
        {//return -1, 0, 1, 2
            if(red_num == -1 || blue_num == -1)
                return -1;
            if(warrior[RED][red_num]->elements == 0 && warrior[BLUE][blue_num]->elements == 0)//????????
            {
                red_num = -1;blue_num = -1;
                return -1;
            }
            if(warrior[BLUE][blue_num]->elements == 0)
            {
                if(warrior[RED][red_num]->sort == WOLF)
                    warrior[RED][red_num]->CWeaponTake(warrior[BLUE][blue_num]);
                blue_num = -1;
                return 0;
            }
            if(warrior[RED][red_num]->elements == 0)
            {
                if(warrior[BLUE][blue_num]->sort == WOLF)
                    warrior[BLUE][blue_num]->CWeaponTake(warrior[RED][red_num]);
                red_num = -1;
                return 1;
            }
            if(flag == 0 || (flag == -1 && NO%2 == 1))
            {
                printf("%.3d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
                        gametime/60,headname[0],name[warrior[0][red_num]->sort],red_num,headname[1],name[warrior[1][blue_num]->sort],blue_num,
                        NO,warrior[0][red_num]->elements,warrior[0][red_num]->force);
                warrior[RED][red_num]->attack(warrior[BLUE][blue_num]);
                if(warrior[BLUE][blue_num]->elements == 0)
                {
                    printf("%.3d:40 blue %s %d was killed in city %d\n",
                            gametime/60, name[warrior[1][blue_num]->sort], blue_num, NO);
                    delete warrior[BLUE][blue_num];
                    blue_num = -1;
                    return 0;
                }
                else {
                    if(warrior[BLUE][blue_num]->fightback(warrior[RED][red_num]) == FIGHTBACK)
                        printf("%.3d:40 %s %s %d fought back against %s %s %d in city %d\n",
                                gametime/60,headname[1],name[warrior[BLUE][blue_num]->sort], blue_num,
                                headname[0],name[warrior[0][red_num]->sort],red_num,NO);
                    if(warrior[0][red_num]->elements == 0)
                    {
                        printf("%.3d:40 red %s %d was killed in city %d\n",gametime/60,name[warrior[0][red_num]->sort],red_num,NO);
                        delete warrior[0][red_num];
                        red_num = -1;
                        return 1;
                    }
                }
                return 2;
            }
            if(flag == 1 || (flag == -1 && NO%2 == 0))
            {
                printf("%.3d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
                        gametime/60,headname[1],name[warrior[1][blue_num]->sort],blue_num,headname[0],name[warrior[0][red_num]->sort],red_num,
                        NO,warrior[1][blue_num]->elements,warrior[1][blue_num]->force);
                warrior[1][blue_num]->attack(warrior[0][red_num]);
                if(warrior[0][red_num]->elements == 0)
                {
                    printf("%.3d:40 red %s %d was killed in city %d\n",gametime/60,name[warrior[0][red_num]->sort],red_num,NO);
                    delete warrior[0][red_num];
                    red_num = -1;
                    return 1;
                } else {

                    if(warrior[0][red_num]->fightback(warrior[1][blue_num]) == 1)
                        printf("%.3d:40 %s %s %d fought back against %s %s %d in city %d\n",
                                gametime/60,headname[0],name[warrior[0][red_num]->sort],red_num,headname[1],name[warrior[1][blue_num]->sort],blue_num,NO);
                    if(warrior[1][blue_num]->elements == 0)
                    {
                        printf("%.3d:40 blue %s %d was killed in city %d\n",gametime/60,name[warrior[1][blue_num]->sort],blue_num,NO);
                        delete warrior[1][blue_num];
                        blue_num = -1;
                        return 0;
                    }
                }
                return 2;
            }
        }
        void yell()
        {
            if(flag == 0 || (flag == -1 && NO%2 == 1))
            {
                if(red_num != -1)
                {
                    if(warrior[0][red_num]->sort == DRAGON && ((flag == 0)||(flag == -1 && NO%2 == 1)))
                        if(warrior[0][red_num]->yell())
                            printf("%.3d:40 red dragon %d yelled in city %d\n",gametime/60,red_num,NO);
                }
            } else {

                if(blue_num != -1)
                {
                    if(warrior[1][blue_num]->sort == DRAGON && ((flag == 1)||(flag == -1 && NO%2 == 0)))
                        if(warrior[1][blue_num]->yell())
                            printf("%.3d:40 blue dragon %d yelled in city %d\n",gametime/60,blue_num,NO);
                }
            }
        }
        void bomb()
        {
            if(red_num == -1 || blue_num == -1)
                return;    
            int r;
            if(warrior[0][red_num]->IsThereWeapon(1) && warrior[0][red_num]->elements >0)
            {

                if(flag == 0 || flag == -1 && NO%2 == 1)
                    r = 0;
                else
                    r = 1;
                if(warrior[0][red_num]->bombjudge(r,warrior[1][blue_num]) == true)
                {    
                    printf("%.3d:38 red %s %d used a bomb and killed blue %s %d\n",
                            gametime/60,name[warrior[0][red_num]->sort],red_num,name[warrior[1][blue_num]->sort],blue_num);
                    delete warrior[0][red_num];
                    warrior[0][red_num] = NULL;
                    delete warrior[1][blue_num];
                    warrior[1][blue_num] = NULL;
                    red_num = -1;
                    blue_num = -1;
                    return;
                }
            }
            if(warrior[1][blue_num]->IsThereWeapon(1) && warrior[1][blue_num]->elements >0)
            {
                if(flag == 1 || flag == -1 && NO%2 == 0)
                    r = 0;
                else
                    r = 1;
                if(warrior[1][blue_num]->bombjudge(r,warrior[0][red_num]) == true)
                {    
                    printf("%.3d:38 blue %s %d used a bomb and killed red %s %d\n",
                            gametime/60,name[warrior[1][blue_num]->sort],blue_num,name[warrior[0][red_num]->sort],red_num);
                    delete warrior[0][red_num];
                    warrior[0][red_num] = NULL;
                    delete warrior[1][blue_num];
                    warrior[1][blue_num] = NULL;
                    red_num = -1;
                    blue_num = -1;
                    return;
                }
            }

        }
        void escape()
        {
            if(red_num != -1)
                if(warrior[0][red_num]->sort == LION)
                {
                    if(warrior[0][red_num]->escape() == true)
                    {
                        printf("%.3d:05 %s %s %d ran away\n",gametime/60,headname[0],
                                name[warrior[0][red_num]->sort],warrior[0][red_num]->ID);
                        delete warrior[0][red_num];
                        warrior[0][red_num] = NULL;
                        red_num = -1;
                    }
                }
            if(blue_num != -1)
                if(warrior[1][blue_num]->sort == LION)
                {
                    if(warrior[1][blue_num]->escape() == true)
                    {
                        printf("%.3d:05 %s %s %d ran away\n",gametime/60,headname[1],
                                name[warrior[1][blue_num]->sort],warrior[1][blue_num]->ID);
                        delete warrior[1][blue_num];
                        warrior[1][blue_num] = NULL;
                        blue_num = -1;
                    }
                }
        }
        void ReportWeapon(int _c,int _num)
        {
            if(_num != -1)
            {
                int _mark = 0;
                printf("%.3d:55 %s %s %d has ",gametime/60,headname[_c],name[warrior[_c][_num]->sort],_num);
                if(warrior[_c][_num]->IsThereWeapon(2))
                {
                    printf("arrow(%d)",3 - (warrior[_c][_num]->wp[2])->times);
                    _mark = 1;
                }
                if(warrior[_c][_num]->IsThereWeapon(1))
                {
                    if(_mark == 1)
                        printf(",");
                    else
                        _mark = 1;
                    printf("bomb");
                }
                if(warrior[_c][_num]->IsThereWeapon(0))
                {
                    if(_mark == 1)
                        printf(",");
                    else
                        _mark = 1;
                    printf("sword(%d)",(warrior[_c][_num]->wp[0])->force);
                }
                if(_mark == 0)
                    printf("no weapon");
                printf("\n");
//                printf("elem: %d, force: %d\n", warrior[_c][_num]->elements, warrior[_c][_num]->force);
            }

        }
};


City *city[21];
class HeadCity : public City
{
public:
    int color; //
    int warrior_num;//num of warrior produced
    int enemy;//
    int enemy_num[2];//enemy's number
    int count[5];//record warrior's number of every type
    HeadCity(int _color,int no):City(no)
    {
        color = _color;
        warrior_num = -1;
        enemy = 0;
        memset(count,0,sizeof(count));
        enemy_num[0] = -1;enemy_num[1] = -1;
        elem = M;
    }
    void ElemTake(int a)
    {
        elem += a;
    }
    bool GiveBirth() 
    {
        int sort = order[color][(Num[color] - 1)%5];
        if(elem - original_elem[sort] >= 0 )
        {
            elem -= original_elem[sort];
            warrior[color][Num[color]] = new CWarrior(sort,Num[color], double(elem)/double(original_elem[sort]),elem,color);
            printf("%.3d:00 %s %s %d born\n",gametime/60,headname[color],name[sort],Num[color]);
            if(warrior[color][Num[color]]->sort == DRAGON)
                printf("Its morale is %.2f\n",warrior[color][Num[color]]->morale);
            if(warrior[color][Num[color]]->sort == LION)
                printf("Its loyalty is %d\n",warrior[color][Num[color]]->loyalty);
            count[order[color][Num[color]%5]]++;
            warrior_num = Num[color];
            Num[color] ++;
            return true;
        } else  {
            //cout<<"color: "<<color<<"not enough to born "<<sort<<endl;
            return false;
        }
    }
    void ReportElem()
    {
        printf("%.3d:50 %d elements in %s headquarter\n",gametime/60,elem,headname[color]);
    }
    void head_escape()
    {
        if(warrior_num != -1)
            if(warrior[color][warrior_num]->sort == LION)
                if(warrior[color][warrior_num]->escape())
                {
                    printf("%.3d:05 %s lion %d ran away\n",gametime/60,headname[color],warrior_num);
                    delete warrior[color][warrior_num];
                    warrior_num = -1;
                }
    }
};


HeadCity *head[2];
void clear() //??????????????
{
    for(int l=1;l<=N;l++)
    {
        if(city[l]->red_num != -1)
            if(warrior[0][city[l]->red_num]->elements == 0)
                city[l]->red_num = -1;
        if(city[l]->blue_num != -1)
            if(warrior[1][city[l]->blue_num]->elements == 0)
                city[l]->blue_num = -1;
    }
}
void IsHeadTaken(int _n)
{
    if(head[_n]->enemy == 2)
    {
        printf("%.3d:10 %s headquarter was taken\n",gametime/60,headname[_n]);
        key = 1;
    }
}
void move() //?????????????,???????iceman???
{
    int y = 0;
    head[1]->enemy_num[head[1]->enemy] = city[N]->red_num;
    if(head[1]->enemy_num[head[1]->enemy] != -1)
    {
        if(warrior[0][head[1]->enemy_num[head[1]->enemy]]->sort == ICEMAN)
            if((N+1)%2 == 0)
                warrior[0][head[1]->enemy_num[head[1]->enemy]]->IcemanChange();
    }
    for(y = N;y>=2;y--)
    {
        city[y]->red_num = city[y-1]->red_num;
        if(city[y]->red_num != -1)
            if(warrior[0][city[y]->red_num]->sort == 2)
                if(y%2 == 0)
                    warrior[0][city[y]->red_num]->IcemanChange();
    }
    city[1]->red_num = head[0]->warrior_num;
    head[0]->warrior_num = -1;


    head[0]->enemy_num[head[0]->enemy] = city[1]->blue_num;
    if(head[0]->enemy_num[head[0]->enemy] != -1)
    {
        if(warrior[1][head[0]->enemy_num[head[0]->enemy]]->sort == 2)
            if((N+1)%2 == 0)
                warrior[1][head[0]->enemy_num[head[0]->enemy]]->IcemanChange();
    }
    for(y = 1;y<=N-1;y++)
    {
        city[y]->blue_num = city[y+1]->blue_num;
        if(city[y]->blue_num != -1)
            if(warrior[1][city[y]->blue_num]->sort == 2)
                if((N+1-y)%2 == 0)
                    warrior[1][city[y]->blue_num]->IcemanChange();
    }
    city[N]->blue_num = head[1]->warrior_num;
    head[1]->warrior_num = -1;

    CWarrior *T;
    if(head[0]->enemy_num[head[0]->enemy] != -1)
    {
        T = warrior[1][head[0]->enemy_num[head[0]->enemy ]];
        printf("%.3d:10 blue %s %d reached red headquarter with %d elements and force %d\n",
                gametime/60,name[T->sort],T->ID,T->elements,T->force);
        head[0]->enemy ++;
        IsHeadTaken(0);
    }
    for(y = 1;y <= N;y++)
    {
        if(city[y]->red_num != -1)
        {
            T = warrior[0][city[y]->red_num];
            printf("%.3d:10 red %s %d marched to city %d with %d elements and force %d\n",
                    gametime/60,name[T->sort],T->ID,y,T->elements,T->force);
        }
        if(city[y]->blue_num != -1)
        {
            T = warrior[1][city[y]->blue_num];
            printf("%.3d:10 blue %s %d marched to city %d with %d elements and force %d\n",
                    gametime/60,name[T->sort],T->ID,y,T->elements,T->force);
        }
    }
    if(head[1]->enemy_num[head[1]->enemy] != -1)
    {
        T = warrior[0][head[1]->enemy_num[head[1]->enemy]];
        printf("%.3d:10 red %s %d reached blue headquarter with %d elements and force %d\n",
                gametime/60,name[T->sort],T->ID,T->elements,T->force);
        head[1]->enemy ++;
        IsHeadTaken(1);
    }
}
void UseArrow()
{
    for(int _i = 1;_i<=N;_i++)
    {
        if(_i!=N && city[_i]->red_num != -1 && city[_i+1]->blue_num!= -1)
            if(warrior[0][city[_i]->red_num]->IsThereWeapon(2))
            {
                warrior[0][city[_i]->red_num]->arrow(warrior[1][city[_i+1]->blue_num]);
            }
        if(_i!=1 && city[_i]->blue_num != -1 && city[_i-1]->red_num!= -1)
            if(warrior[1][city[_i]->blue_num]->IsThereWeapon(2))
            {
                warrior[1][city[_i]->blue_num]->arrow(warrior[0][city[_i-1]->red_num]);
            }
    }
    for(int _i = 1;_i<=N;_i++)
    {
        if(city[_i]->blue_num == -1 || city[_i]->red_num == -1)
        {
            if(city[_i]->blue_num != -1)
                if(warrior[1][city[_i]->blue_num]->elements <= 0)
                {
                    delete warrior[1][city[_i]->blue_num];
                    city[_i]->blue_num = -1;

                }
            if(city[_i]->red_num != -1)
                if(warrior[0][city[_i]->red_num]->elements<=0)
                {
                    delete warrior[0][city[_i]->red_num];
                    city[_i]->red_num = -1;
                }
            continue;
        }
        if(warrior[0][city[_i]->red_num]->elements<=0 &&
            warrior[1][city[_i]->blue_num]->elements <= 0)
        {
            delete warrior[0][city[_i]->red_num];
            delete warrior[1][city[_i]->blue_num];
            city[_i]->red_num = -1;
            city[_i]->blue_num = -1;
        }
    }
}
void EarnElem(int z)
{
    int Z[2]={30,40};
    for(int _i = 1;_i<=N;_i++)
    {
        if(city[_i]->blue_num!= -1 && city[_i]->red_num == -1)
        {
            printf("%.3d:%d blue %s %d earned %d elements for his headquarter\n",
                gametime/60,Z[z],name[warrior[1][city[_i]->blue_num]->sort],city[_i]->blue_num,city[_i]->elem);
            head[1]->ElemTake(city[_i]->elem);
            city[_i]->LoseElem();
        }
        if(city[_i]->red_num!= -1 && city[_i]->blue_num == -1)
        {
            printf("%.3d:%d red %s %d earned %d elements for his headquarter\n",
                gametime/60,Z[z],name[warrior[0][city[_i]->red_num]->sort],city[_i]->red_num,city[_i]->elem);
            head[0]->ElemTake(city[_i]->elem);
            city[_i]->LoseElem();
        }
    }
}
void BattleEffect(City *A)
{
    int _a = A->Battle();
    CWarrior * _temp;
    if(_a == 0)
        _temp = warrior[0][A->red_num];
    else if(_a == 1)
        _temp = warrior[1][A->blue_num];
    if(_a != -1)
    {
        A->yell();
    }
    if(_a != 2 && _a != -1)
    {
        printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n",
            gametime/60,headname[_a],name[_temp->sort],_temp->ID,A->elem);
        head[_a]->elem += A->elem;
        A->elem = 0;
    }
    if(_a == 2)
    {
        if(warrior[0][A->red_num]->sort == 3)
            warrior[0][A->red_num]->LoyaltyDown();
        if(warrior[1][A->blue_num]->sort == 3)
            warrior[1][A->blue_num]->LoyaltyDown();
    }
    if(_a != -1)
    {
        A->BattleResult[1] = _a;
        A->FlagUp();
    }
}
void award(int *  _backup)
{
    int _j=1;
    while(_backup[0]>=8 && _j<= N)
    {
        if(city[_j]->BattleResult[1] == 0)
        {
            warrior[0][city[_j]->red_num]->elements += 8;
            head[0]->elem -= 8;
            _backup[0] -= 8;
        }
        _j ++ ;
    }
    _j = N;
    while(_backup[1]>=8 && _j>=1)
    {
        if(city[_j]->BattleResult[1] == 1)
        {
            warrior[1][city[_j]->blue_num]->elements += 8;
            head[1]->elem -= 8;
            _backup[1] -= 8;
        }
        _j -- ;
    }
}

void PrintCase(){
    cout << M <<" "<<N<<" "<<R<<" " <<K<<" "<<T<<endl;
    for(int i=0;i<5;i++)
        cout<<original_elem[i];
    cout<<endl;
    for(int i=0;i<5;i++)
        cout<<ori_force[i];
    cout<<endl;

}
int main() {
    int test,i_test;
    cin>>test;
    for(i_test=1;i_test<=test;i_test++)
    {
        key = 0;
        int minute;
        gametime = 0;
        Num[0] = 1;Num[1] = 1;

        cin>>M>>N>>R>>K>>T;

        for(int i=0;i<5;i++)
            cin>>original_elem[i];
        for(int i=0;i<5;i++)
            cin>>ori_force[i];

        head[0] = new HeadCity(0,0);
        head[1] = new HeadCity(1,N+1);
        for(int i=1;i<=N;i++)
        {
//            cout<<"city "<<i<<"created!"<<endl;
            city[i] = new City(i);
        }
        printf("Case %d:\n",i_test);
/*        if(i_test == 11){
            PrintCase();
        }
 */       for(gametime = 0; gametime <= T && key == 0; gametime ++)
        {
            if(gametime / 60 == 6)
                int _aa = 0;
            switch(gametime % 60)
            {
                case 0:
                    head[0]->GiveBirth();
                    head[1]->GiveBirth();
                    break;
                case 5:
                    head[0]->head_escape();
                    for(int i_count =1 ;i_count<=N;i_count++)
                        city[i_count]->escape();
                    head[1]->head_escape();
                    break;
                case 10:
                    move();
                    break;
                case 20:
                    for(int i_count = 1;i_count<=N;i_count++)
                        city[i_count]->ElemUp();
                    break;
                case 30:
                    EarnElem(0);
                    break;
                case 35:
                    UseArrow();
                    break;
                case 38:
                    for(int i_count =1;i_count<=N;i_count++)
                        city[i_count]->bomb();
                    break;
                case 40:
                    int backup[2];
                    backup[0] = head[0]->elem; backup[1] = head[0]->elem;
                    for(int i_count = 1;i_count<=N ; i_count++)
                        BattleEffect(city[i_count]);
                    award(backup);
                    for(int i_count = 1;i_count<=N ; i_count++)
                        city[i_count]->BattleOver();
                    break;
                case 50:
                    head[0]->ReportElem();head[1]->ReportElem();
                    break;
                case 55:
                    for(int i_count = 1;i_count<=N ; i_count++)
                        city[i_count]->ReportWeapon(0,city[i_count]->red_num);
                    head[1]->ReportWeapon(0,head[1]->enemy_num[0]);
                    head[0]->ReportWeapon(1,head[0]->enemy_num[0]);
                    for(int i_count = 1;i_count<=N ; i_count++)
                        city[i_count]->ReportWeapon(1,city[i_count]->blue_num);
                    break;
            }
        }
    }
    return 0;
}

