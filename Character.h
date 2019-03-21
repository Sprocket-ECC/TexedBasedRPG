#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>
#include <math.h>

typedef std::string NameType;
typedef std::string RoleType;

class Character {
public:
	
	Character();										//Constructor
	
	Character(const Character &rhs);					//Copy Constructor

	Character(NameType Name);
	
	Character(NameType nme, int health, int action,		//Overloaded constructor
		int level, int experience, int strength, 
		int dexerity, int defense, int charisma, int intellect);
	
	~Character();										//Deconstructor

	
private:

	struct character_profile {
		NameType name;
		int hp, ap, lvl, exp, str, dex, def, chr, intel;

		////Equipment Slots
		////[0] = Head, [1] = Neck, [2] = Chest, [3] = L. Hand, [4] = R. Hand, [5] = Legs, [6] = Feet
		//std::unique_ptr<Item[]> EquipmentSlots = std::make_unique<Item[]>(7);
		////Inventory
		//std::unique_ptr<Item[]> Inventory = std::make_unique<Item[]>(20);

		//character_profile constructor
		character_profile() : name("No_name_set"), hp(1), ap(1), lvl(1), exp(0), 
			str(1), def(1), chr(1), intel(1) {}

		//Character_Profile only name constructor
		character_profile(NameType nme) : name(nme), hp(1), ap(1), lvl(1), exp(0),
			str(1), def(1), chr(1), intel(1) {}

		//Character_profile constructor overloaded
		character_profile(NameType nme, int health, int action, int level, 
			int experience, int strength, int dexerity, int defense, int charisma, int intellect) : 
			name(nme), hp(health), ap(action), lvl(level), exp(experience), 
			str(strength), dex(dexerity), def(defense), chr(charisma), intel(intellect) {}

		//Character_Profile constructor for Role constructor-No name, lvl, exp
		character_profile(int health, int action, int level,
			int experience, int strength, int dexerity, int defense, int charisma, int intellect) :
			hp(health), ap(action), lvl(level), exp(experience),
			str(strength), dex(dexerity), def(defense), chr(charisma), intel(intellect) {}
	};

	struct role_profile {
		//Skill Array[]
		///NOT IMPLEMENTED YET

		//Stats adjustor 
		int hp, ap, str, dex, def, chr, intel;

		bool roleStatsUpdated = false;
	};
	//Function to read skill list file
	void readSkillList(RoleType role); ///NOT IMPLEMENTED YET
public:
	//Updates CharacterProfile stats to increase by Role stats
	void updateRoleStats();

	//Updates stats 
	void updateStats(int health, int action, int strength, int dexerity, int defense, int charisma, int intellect);

	//Upgrade lvl stat
	void upgradeLVL();									//Upgrade character by one level

	//Upgrade lvl stat with all exp						
	int upgradeMaxLvl();								//Upgrade character lvl by total amount of exp

	//Check if enough exp to lvl up
	bool ifEnoughExp();									//Check Experience to level Pawn

	//Calculate Ap amount per lvl upgraded
	int calculateStatPointsForCurrentLVL();

	//Calculate Total Skill points amount for multiple lvl upgraded
	int calculateTotalStatPoints();
	

#pragma region Setters/Getters

	/////////////////////////
	//    GetFunctions     //
	/////////////////////////

	NameType getName();									//Get name

	int getHp();										//get hp

	int getAP();										//Get AP

	int getLvl();										//Get level

	int getExp();										//Get exp

	int getStr();										//Get strength

	int getDex();										//Get dex

	int getDef();										//Get dex

	int getChr();										//Get charisma

	int getIntel();										//Get Intellect

	/////////////////////////
	//    SetFunctions     //
	/////////////////////////

	void setName(NameType n);							//Set name

	void setHp(int hp);									//Set HP

	void setAp(int ap);									//Set AP

	void setLvl(int lvl);								//Set lvl

	void setExp(int exp);								//Set Exp

	void setStr(int str);								//Set str

	void setDex(int dex);								//Set Dex

	void setDef(int def);								//Set Def

	void setChr(int chr);								//Set chr

	void setIntel(int intel);							//Set intellect

#pragma endregion

	//shared pointer for character
	std::shared_ptr<character_profile> CharacterProfile = std::make_shared<character_profile>();

	//Unique pointer for role_profile
	std::unique_ptr<role_profile> RoleProfile = std::make_unique<role_profile>();

};