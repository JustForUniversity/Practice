#include <iostream>
#include <ctime>
#include "Fighter.h"

using namespace std;

Fighter create_Fighter_bot(string ch) {
	Fighter bot;
	int upgrade;
	while (bot.free_points()) {
		upgrade = rand() % 5;
		switch (upgrade) {
		case HEALTH:	 bot.add_health_points(1); break;
		case FORCE:		 bot.add_force_points(1); break;
		case DEFENCE:	 bot.add_defence_points(1); break;
		case AGILITY:	 bot.add_agility_points(1); break;
		case CRIT:		 bot.add_critical_points(1); break;
		}
	}
	string name = "bot " + ch;
	bot.set_name(name);
	return bot;
}

Fighter create_Fighter_player() {
	int upgrade_health, upgrade_force, upgrade_critical, upgrade_defence, upgrade_agility;
	string name;

	cout << "Player name: ";
	cin >> name;
	cout << "points to health: ";
	cin >> upgrade_health;
	cout << "points to force: ";
	cin >> upgrade_force;
	cout << "points to crit: ";
	cin >> upgrade_critical;
	cout << "points to defence: ";
	cin >> upgrade_defence;
	cout << "points to agility: ";
	cin >> upgrade_agility;


	Fighter player(upgrade_health, upgrade_force, upgrade_critical, upgrade_defence, upgrade_agility, name);
	return player;
}

void battle(Fighter first, Fighter second) {
	bool first_Fighter_turn = rand() % 2;

	cout << "Fight\n";

	while (!(first.is_dead()) && !(second.is_dead())) {
		if (first_Fighter_turn)
			cout << second.get_name() << " received " << second.damage(first.attack()) << " damage from " << first.get_name() << endl;
		else
			cout << first.get_name() << " received " << first.damage(second.attack()) << " damage from " << second.get_name() << endl;

		first_Fighter_turn ? first_Fighter_turn = false : first_Fighter_turn = true;
	}
	cout << endl;

	if (first.is_dead()) cout << second.get_name() << " Winner";
	else cout << first.get_name() << " Winner";
}

int main() {

	srand(time(NULL));
	Fighter a = create_Fighter_bot("1");
	int var;
	cout << "Mortal Combat\n";
	cout << "Choose mod: \n";
	cout << "1.Bot VS Bot (BvB) \n";
	cout << "2.Player VS Bot (PvB) \n";
	cout << "3.Player VS Player (PvP) \n";
	cout << "Your answer: ";
	cin >> var;
	Fighter b = create_Fighter_bot("2");

	system("cls");

	switch (var) {
	//case 1: battle(create_Fighter_bot("1"), create_Fighter_bot("2")); break;
	case 1: battle(a, b); break;
	case 2: battle(create_Fighter_player(), create_Fighter_bot("1")); break;
	case 3: battle(create_Fighter_player(), create_Fighter_player()); break;
	default: cout << "Choose correct number!";
	}

	cout << endl;

	system("pause");

	return 0;
}
