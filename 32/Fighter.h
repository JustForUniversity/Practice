#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum upgrade{HEALTH, FORCE, DEFENCE, AGILITY, CRIT};

class Fighter
{
private:
	int health_points;
	int force_points;
	int defence_points;
	int agility_points;
	int critical_points;
	string name;


	int health;
	int points;

	double critical_damage = 2;

	double force() {
		return (1.0 + this->force_points);
	}

	bool critical() {
		if ((double(rand()) / RAND_MAX) > 1 / (1 + pow(this->critical_points / 4.0,4)))
			return true;
		return false;
	}

	double defence() {
		return 1 / (1 + pow(this->defence_points / 4.0, 4));
	}

	bool agility() {
		if ((double(rand()) / RAND_MAX) > (1 / (1 + pow(this->agility_points / 4.0, 4))))
			return true;
		return false;
	}


public:

	Fighter() {
		this->health = 100;
		this->health_points = 0;
		this->force_points = 0;
		this->critical_points = 0;
		this->defence_points = 0;
		this->agility_points = 0;
		this->points = 10;
		this->name = "default";
		srand(time(NULL));
	}

	Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points, string name) {
		this->health_points = health_points;
		this->force_points = force_points;
		this->critical_points = critical_points;
		this->defence_points = defence_points;
		this->agility_points = agility_points;
		this->points = 0;
		this->health = 100 + health_points * 100;
		this->name = name;
		srand(time(NULL));
	}

	bool add_health_points(int points) {
		if (this->points < points) return false;
		this->health_points += points;
		this->points -= points;
		this->health = 100 + health_points * 100;
		return true;
	}

	bool add_force_points(int points) {
		if (this->points < points) return false;
		this->force_points += points;
		this->points -= points;
		return true;
	}

	bool add_defence_points(int points) {
		if (this->points < points) return false;
		this->defence_points += points;
		this->points -= points;
		return true;
	}

	bool add_agility_points(int points) {
		if (this->points < points) return false;
		this->agility_points += points;
		this->points -= points;
		return true;
	}

	bool add_critical_points(int points) {
		if (this->points < points) return false;
		this->critical_points += points;
		this->points -= points;
		return true;
	}

	bool free_points() {
		return this->points;
	}

	double attack() {
		if (critical()) return force() * critical_damage;
		else return force();
	}

	double damage(double dmg) {
		double a = agility(), b = defence();
		double injure = (1.0 - agility()) * defence() * dmg;
		this->health -= injure;
		return injure;
	}

	bool is_dead() {
		if (this->health <= 0) return true;
		return false;
	}

	void set_name(string name) {
		this->name = name;
	}

	string get_name() {
		return name;
	}
};

