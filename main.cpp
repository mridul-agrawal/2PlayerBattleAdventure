#include <iostream>
using namespace std;

class Warrior{
  private:
  string name;
  int health;
  int baseDamage;
  int minAdditionalDamage;
  int maxAdditionalDamage;
  int minHealPower;
  int maxHealPower;
  bool dodge;

  public:
  virtual int GetHealth() = 0;
  virtual string GetName() = 0;
  virtual int GetAdditionalDamage() = 0;
  virtual int GetBaseDamage() = 0;
  virtual void TakeDamage(int damage) = 0;
  virtual int Heal() = 0;
  virtual void SpecialAbility1(Warrior *) = 0;
  virtual void SpecialAbility2(Warrior *) = 0;
};

class PowerfulWarrior : public Warrior {
  private:
  string name;
  int health;
  int baseDamage;
  int minAdditionalDamage;
  int maxAdditionalDamage;
  int minHealPower;
  int maxHealPower;

  public:
  PowerfulWarrior() {
    cout<<"\nPowerful Warrior: \"Thanks for choosing me, I will crush my opponent and bring you glory\"\n";
    name = "Powerful Warrior";
    health = 200;
    baseDamage = 15;
    minAdditionalDamage = 8;
    maxAdditionalDamage = 16;
    minHealPower = 6;
    maxHealPower = 12;
    cout<<"Warrior Health is "<<health<<" \n";
    cout<<"Warrior Base Damage is "<<baseDamage<<" \n";
    cout<<"Warrior Additional Damage is "<<minAdditionalDamage<<"-"<<maxAdditionalDamage<<" \n";
    cout<<"Warrior Heal Power is "<<minHealPower<<"-"<<maxHealPower<<" \n\n\n";
  }
  int GetHealth() {
    return health;
  }
  string GetName() {
    return name;
  }
  int GetAdditionalDamage() {
    int x = minAdditionalDamage + (rand() % 9);
    return x;
  }
  int GetBaseDamage() {
    return baseDamage;
  }
  void TakeDamage(int damage) {
    health = health-damage;
    if(health<0) {
      health = 0;
    }
  }
  int Heal() {
    int x = minHealPower + (rand() % (maxHealPower-minHealPower+1));
    health += x;
    return x;
  }
  void SpecialAbility1(Warrior *warrior2) {
    cout<< name << " used the Special Ability Huge Heal!!" << endl ;
    int healthRecovered = health;
    health += 100;
    if(health > 200) health = 200;
    healthRecovered = health - healthRecovered;
    cout<< name << " healed " << healthRecovered << " health Points!!!" << endl;
    cout<< "Total health of " << name << " after healing is: " << health << "\n\n" ;
  } 
  void SpecialAbility2(Warrior *warrior2) {
    cout<< name << " used the Special Ability Double Attack!!" << endl ;
    cout<< name << " Attacked!\n";
    int additionalDamage1 = GetAdditionalDamage();
    cout<<"Additional Damage dealt: "<< additionalDamage1 << endl;
    int totalDamage1 = additionalDamage1 + baseDamage;
    cout<<"Total Damage dealt by " << name << " is: " << totalDamage1 << endl;
    warrior2->TakeDamage(totalDamage1);
    cout<<"Health of " << warrior2->GetName() << " after taking damage: " << warrior2->GetHealth() << "\n";

    cout<< name << " Attacked Again!\n";
    int additionalDamage2 = GetAdditionalDamage();
    cout<<"Additional Damage dealt: "<< additionalDamage2 << endl;
    int totalDamage2 = additionalDamage2 + baseDamage;
    cout<<"Total Damage dealt by " << name << " is: " << totalDamage2 << endl;
    warrior2->TakeDamage(totalDamage2);
    cout<<"Health of " << warrior2->GetName() << " after taking damage: " << warrior2->GetHealth() << "\n\n";
  }
};

class SkillfulWarrior : public Warrior {
  private:
  string name;
  int health;
  int baseDamage;
  int minAdditionalDamage;
  int maxAdditionalDamage;
  int minHealPower;
  int maxHealPower;
  bool dodge;

  public:
  SkillfulWarrior() {
    cout<<"\nSkillful Warrior: \"Thank you for choosing me, I will be loyal to you till my last breath\"\n";
    name = "Skillful Warrior";
    health = 150;
    baseDamage = 25;
    minAdditionalDamage = 10;
    maxAdditionalDamage = 18;
    minHealPower = 15;
    maxHealPower = 24;
    dodge = false;
    cout<<"Warrior Health is "<<health<<" \n";
    cout<<"Warrior Base Damage is "<<baseDamage<<" \n";
    cout<<"Warrior Additional Damage is "<<minAdditionalDamage<<"-"<<maxAdditionalDamage<<" \n";
    cout<<"Warrior Heal Power is "<<minHealPower<<"-"<<maxHealPower<<" \n\n\n";
  }
  int GetHealth() {
    return health;
  }
  string GetName() {
    return name;
  }
  int GetAdditionalDamage() {
    int x = minAdditionalDamage + (rand() % 8);
    return x;
  }
  int GetBaseDamage() {
    return baseDamage;
  }
  void TakeDamage(int damage) {
    if(dodge) {
      cout<< name << " Blocked the Attack!!" << endl;
      dodge = false;
      return;
    }
    health = health-damage;
    if(health<0) {
      health = 0;
    }
  }
  int Heal() {
    int x = minHealPower + (rand() % (maxHealPower-minHealPower+1));
    health += x;
    return x;
  }
  void SpecialAbility1(Warrior *warrior2) {
    cout<< name << " used the Special Ability Attack Blocker!!" <<endl;
    dodge = true;
  }
  void SpecialAbility2(Warrior *warrior2) {
    cout<< name << " used the Special Ability Heal + Attack!!" <<endl;
     
    cout<< name << " Attacked!\n";
    int additionalDamage = GetAdditionalDamage();
    cout<<"Additional Damage dealt: "<< additionalDamage << endl;
    int totalDamage = additionalDamage + baseDamage;
    cout<<"Total Damage dealt by " << name << " is: " << totalDamage << endl;
    warrior2->TakeDamage(totalDamage);
    cout<<"Health of " << warrior2->GetName() << " after the attack: " << warrior2->GetHealth() << "\n";

    cout<< name << " Healed himself!" << endl;
    int heal = Heal();
    cout<< name << " was healed by " << heal << " health points" << endl ;
    cout << name << " has now total health of: " << health << "\n\n" ;
  }
};

class RagingWarrior : public Warrior {
  private:
  string name;
  int health;
  int baseDamage;
  int minAdditionalDamage;
  int maxAdditionalDamage;
  int minHealPower;
  int maxHealPower;

  public:
  RagingWarrior() {
    cout<<"\nRaging Warrior: \"Thanks for choosing me, I will bring you the head of enemies\"\n";
    name = "Raging Warrior";
    health = 100;
    baseDamage = 40;
    minAdditionalDamage = 4;
    maxAdditionalDamage = 8;
    minHealPower = 12;
    maxHealPower = 25;
    cout<<"Warrior Health is "<<health<<" \n";
    cout<<"Warrior Base Damage is "<<baseDamage<<" \n";
    cout<<"Warrior Additional Damage is "<<minAdditionalDamage<<"-"<<maxAdditionalDamage<<" \n";
    cout<<"Warrior Heal Power is "<<minHealPower<<"-"<<maxHealPower<<" \n\n\n";
  }
  int GetHealth() {
    return health;
  }
  string GetName() {
    return name;
  }
  int GetAdditionalDamage() {
    int x = minAdditionalDamage + (rand() % 5);
    return x;
  }
  int GetBaseDamage() {
    baseDamage += (int)(baseDamage * ((100-health)/100.0)/2.0);   
    return baseDamage;
  }
  void TakeDamage(int damage) {
    health = health-damage;
    if(health<0) {
      health = 0;
    }
  }
  int Heal() {
    int x = minHealPower + (rand() % (maxHealPower-minHealPower+1));
    health += x;
    return x;
  }
  void SpecialAbility1(Warrior *warrior2) {
    SpecialAbility2(warrior2);
  }
  void SpecialAbility2(Warrior *warrior2) {
    cout<< name << " used Special Ability Critical Attack!!" <<endl;

    cout<< name << " Attacked!\n";
    int totalDamage = baseDamage*2;
    cout<<"Total Damage dealt by " << name << " is: " << totalDamage << endl;
    warrior2->TakeDamage(totalDamage);
    cout<<"Health of " << warrior2->GetName() << " after the attack: " << warrior2->GetHealth() << "\n\n";
  }
};


void PrintInstructions() {
  cout<< "WELCOME TO THE 2-PLAYER BATTLE ADVENTURE GAME\n\nRULES:\n1. Each Player chooses a warrior to fight for them.\n2. Each warrior has some Attack Power, Heal Power, Special Ability and Additional Damage.\n3. This is a turn based game, Each player has only one turn at a time. \n4. Each Special Ability has a 20% chance to be triggered\n5. If health of your warrior becomes 0, you will lose.\n6. You have 2 options each turn, either to damage your enemy or heal yourself.\n7. Press H to Heal or D to Damage\n\n\n";
};

void PrintWarriorDetails() {
  cout<< "We have 3 types of warriors for you to choose from:\n\n1) Powerful Warrior:\n\t\tHigh Health\n\t\tAvg Heal\n\t\tLow Atttack\n\t\tHigh Additional Damage\n\t\tSpecial Abilities:  Huge Heal (Heals a very huge amount)\n\t\t\t\t\t\t\tDouble Attack (Attack twice in a turn!)\n\n2) Skillful Warrior:\n\t\tAvg Health\n\t\tHigh Heal\n\t\tAvg Atttack\n\t\tAvg Additional Damage\n\t\tSpecial Abilities:  Attack Blocker (Recieves 0 Damage)\n\t\t\t\t\t\t\tHeal + Damage (Attack and heal in a single turn!)\n\n3) Raging Warrior:\n\t\tLow Health\n\t\tHigh Heal\n\t\tHigh Atttack\n\t\tHigh Additional Damage\n\t\tSpecial Abilities:  Rage (Attack increases when health is low)\n\t\t\t\t\t\t\tCritical Attack (Higher chances of a critical attack)\n\n\n";
};

Warrior* Warrior1Selection() {
  cout<<"Hi Player 1. Please choose your warrior:\n";
  cout<<"Enter 1 to choose the Powerful Warrior.\nEnter 2 to choose the Skillful Warrior.\nEnter 3 to choose the Raging Warrior\n";
  int x;
  Warrior *player1;
  cin>> x;
  switch(x) {
    case 1: player1 = new PowerfulWarrior();
    break;
    case 2: player1 = new SkillfulWarrior();
    break;
    case 3: player1 = new RagingWarrior();
    break;
    default: cout<<"Enter the correct input";
  }

  return player1;
};

Warrior* Warrior2Selection() {
  cout<<"Hi Player 2. Please choose your warrior:\n";
  cout<<"Enter 1 to choose the Powerful Warrior.\nEnter 2 to choose the Skillful Warrior.\nEnter 3 to choose the Raging Warrior\n";
  int x;
  Warrior *player2;
  cin>> x;
  switch(x) {
    case 1: player2 = new PowerfulWarrior();
    break;
    case 2: player2 = new SkillfulWarrior();
    break;
    case 3: player2 = new RagingWarrior();
    break;
    default: cout<<"Enter the correct input";
    break;
  }

  return player2;
};

void PlayTurn(Warrior *warrior1, Warrior *warrior2) {
  cout<<"Player 1 Playing: Press \'D\' to Deal Damage or Press \'H\' to Heal Yourself"<<endl;
  char x;
  cin>>x;

  int sp1 = rand()%100;
  int sp2 = rand()%100;

  if(sp1<15) {
    warrior1->SpecialAbility1(warrior2);
  } else if(sp1<30) {
    warrior1->SpecialAbility2(warrior2);
  } else if(x=='d' || x=='D') {

    cout<< warrior1->GetName() << " Attacked!\n";
    int additionalDamage = warrior1->GetAdditionalDamage();
    cout<<"Additional Damage dealt: "<< additionalDamage << endl;
    int totalDamage = additionalDamage + warrior1->GetBaseDamage();
    cout<<"Total Damage dealt by " << warrior1->GetName() << " is: " << totalDamage << endl;
    warrior2->TakeDamage(totalDamage);
    cout<<"Health of " << warrior2->GetName() << " after the attack: " << warrior2->GetHealth() << "\n\n"; 
  } 
  else if(x=='h' || x=='H') {
    cout<< warrior1->GetName() << " Healed himself!" << endl;
    int heal = warrior1->Heal();
    cout<< warrior1->GetName() << " was healed by " << heal << " health points" << endl ;
    cout << warrior1->GetName() << " has now total health of: " << warrior1->GetHealth() << "\n\n" ;
  }

  if(warrior2->GetHealth() == 0) {
    cout<< "Warrior 2 died!\n\n\nPLAYER 1 WINS!!!!!!!";
    return;
  }



  cout<<"Player 2 Playing: Press \'D\' to Deal Damage or Press \'H\' to Heal Yourself"<<endl;
  char y;
  cin>>y;
  
  if(sp2<15) {
    warrior2->SpecialAbility1(warrior1);
  } else if(sp2<30) {
    warrior2->SpecialAbility2(warrior1);
  } else if(y=='d' || y=='D') {

    cout<< warrior2->GetName() << " Attacked!\n";
    int additionalDamage2 = warrior2->GetAdditionalDamage();
    cout<<"Additional Damage dealt: "<< additionalDamage2 << endl;
    int totalDamage2 = additionalDamage2 + warrior2->GetBaseDamage();
    cout<<"Total Damage dealt by " << warrior2->GetName() << " is: " << totalDamage2 << endl;
    warrior1->TakeDamage(totalDamage2);
    cout<<"Health of " << warrior1->GetName() << " after the attack: " << warrior1->GetHealth() << "\n\n"; 
  } 
  else if(y=='h' || y=='H') {
    cout<< warrior2->GetName() << " Healed himself!" << endl;
    int heal = warrior2->Heal();
    cout<< warrior2->GetName() << " was healed by " << heal << " health points" << endl ;
    cout << warrior2->GetName() << " has now total health of: " << warrior2->GetHealth() << "\n\n" ;
  }

  if(warrior1->GetHealth() == 0) {
    cout<< "Warrior 1 died!\n\n\nPLAYER 2 WINS!!!!!!!";
    return;
  }

};


int main() {

  srand(time(0));

  PrintInstructions();  
  PrintWarriorDetails();

  Warrior *warrior1 = Warrior1Selection(); 
  Warrior *warrior2 = Warrior2Selection();

  cout<<"Get ready Warriors, Player1 will go first...\n"<<endl;

  while(warrior1->GetHealth()!=0 && warrior2->GetHealth()!=0) {
    PlayTurn(warrior1,warrior2);
  }
}