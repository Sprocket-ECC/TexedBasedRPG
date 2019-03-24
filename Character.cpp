//Character.cpp
//Written by: Ethan Covington
//Updated on: 3/23/2019
#include "Character.h"
#pragma region Construct/Copy/Deconstruct
//Constructor
Character::Character()
{
	character_profile();
}

//Overloaded Constructor only name
Character::Character(NameType Name)
{
	character_profile();
	CharacterProfile->name = Name;//Sets character name to Name
}

//Overloaded Constructor
Character::Character(NameType nme, int health, int action, int level, int experience, 
					int strength, int dexerity, int defense, int charisma, int intellect)
{
	character_profile(nme, health, action, level, experience, strength, dexerity, defense, charisma, intellect);
}

//Copy constructor
Character::Character(const Character &rhs)
{
	character_profile(rhs.CharacterProfile->name, rhs.CharacterProfile->hp, rhs.CharacterProfile->ap, rhs.CharacterProfile->lvl, rhs.CharacterProfile->exp,
		rhs.CharacterProfile->str, rhs.CharacterProfile->dex, rhs.CharacterProfile->def, rhs.CharacterProfile->chr, rhs.CharacterProfile->intel);
}

//Deconstructor
Character::~Character()
{
	CharacterProfile.~shared_ptr(); //Delete CharacterProfile
	RoleProfile.~unique_ptr();		//Delete RoleProfile
}
#pragma endregion



void Character::updateRoleStats()
{
	if (this->RoleProfile->roleStatsUpdated == false) //If Character stats haven't been updated by Role data
	{
		this->CharacterProfile->hp += RoleProfile->hp;
		this->CharacterProfile->ap += RoleProfile->ap;
		this->CharacterProfile->str += RoleProfile->str;
		this->CharacterProfile->dex += RoleProfile->dex;
		this->CharacterProfile->def += RoleProfile->def;
		this->CharacterProfile->intel += RoleProfile->intel;
		this->CharacterProfile->chr += RoleProfile->chr;

		RoleProfile->roleStatsUpdated = true;
	}
}

void Character::updateStats(int health, int action, int strength, int dexerity, int defense, int charisma, int intellect)
{
	//Update all CharacterProfile stats
	this->CharacterProfile->hp += health;
	this->CharacterProfile->ap += action;
	this->CharacterProfile->str += strength;
	this->CharacterProfile->dex += dexerity;
	this->CharacterProfile->def += defense;
	this->CharacterProfile->intel += intellect;
	this->CharacterProfile->chr += charisma;
}

void Character::upgradeLVL()
{
	if (ifEnoughExp())
	{
		int expPerLevel = pow(CharacterProfile->lvl, 3);//Exp Per Level algorithm
		CharacterProfile->exp -= expPerLevel;			//Suptract exp used to level player
		CharacterProfile->lvl++;						//Increase player level by one 
	}
}

int Character::upgradeMaxLvl()
{
	int numOfLvl = 0;
	while (ifEnoughExp())
	{
		int expPerLevel = pow(CharacterProfile->lvl, 3); //Exp Per Level algorithm
		CharacterProfile->exp -= expPerLevel;			//Suptract exp used to level player
		CharacterProfile->lvl++;						//Increase player level by one 
		numOfLvl++;
	}
	return numOfLvl;
}

bool Character::ifEnoughExp()
{
	//Level algorithm per level lvl^3
	int expPerLevel = pow(CharacterProfile->lvl, 3);//Exp Per level algorithm

	//Check if player has enough experience to level up
	if (CharacterProfile->exp >= expPerLevel)
	{
		return true;
	}
	return false;
}

int Character::calculateStatPointsForCurrentLVL()
{
	int newSPAmount = (int)CharacterProfile->lvl * 1.3; //Calculate SP per current lvl
	return newSPAmount;
}

int Character::calculateTotalStatPoints()
{
	int totalSP = 0;
	int beginningLvl = CharacterProfile->lvl;
	beginningLvl++;								//First lvl that is upgraded
	int totalLvlGained = upgradeMaxLvl();		//Total lvls gained
	for (int i = 0; i < totalLvlGained; i++)	//Loop for number of lvls gained
	{
		totalSP += (int)beginningLvl * 1.3;		//Calculate SP per lvl
	}

	return totalSP;
}

/////////////////////////
//  Getter functions   //
/////////////////////////

#pragma region Getter Functions
NameType Character::getName()
{
	return CharacterProfile->name;
}

int Character::getHp()
{
	return CharacterProfile->hp;
}

int Character::getAP()
{
	return CharacterProfile->ap;
}

int Character::getLvl()
{
	return CharacterProfile->lvl;
}

int Character::getExp()
{
	return CharacterProfile->exp;
}

int Character::getStr()
{
	return CharacterProfile->exp;
}

int Character::getDex()
{
	return CharacterProfile->dex;
}

int Character::getDef()
{
	return CharacterProfile->def;
}

int Character::getChr()
{
	return CharacterProfile->chr;
}

int Character::getIntel()
{
	return CharacterProfile->intel;
}

#pragma endregion

/////////////////////////
//    SetFunctions     //
/////////////////////////

#pragma region Set Functions
void Character::setName(NameType n)
{
	CharacterProfile->name = n;
}

void Character::setHp(int hp)
{
	CharacterProfile->hp = hp;
}

void Character::setAp(int ap)
{
	CharacterProfile->ap = ap;
}

void Character::setLvl(int lvl)
{
	CharacterProfile->lvl = lvl;
}

void Character::setExp(int exp)
{
	CharacterProfile->exp = exp;
}

void Character::setStr(int str)
{
	CharacterProfile->str = str;
}

void Character::setDex(int dex)
{
	CharacterProfile->dex = dex;
}

void Character::setDef(int def)
{
	CharacterProfile->def = def;
}

void Character::setChr(int chr)
{
	CharacterProfile->chr = chr;
}

void Character::setIntel(int intel)
{
	CharacterProfile->intel = intel;
}

#pragma endregion
