#include <iostream>
#include <string>

using namespace std;

void show(string* arr, int str, int col) {
	for (int i = 0; i < str; i++) {
		cout << "/*" << i << "*/\t";
		for (int j = 0; j < col; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void recursia(string* arr, int start_str, int start_col) {

	if (arr[start_str][start_col] != ' ' && arr[start_str][start_col] != '#') {
		if (arr[start_str][start_col] == 'A') cout << "A ";
		else if (arr[start_str][start_col] == 'B') cout << "B ";
		else if (arr[start_str][start_col] == 'C') cout << "C ";
		else if (arr[start_str][start_col] == 'D') cout << "D ";
		else if (arr[start_str][start_col] == 'E') cout << "E ";
		else if (arr[start_str][start_col] == 'F') cout << "F ";
		return;
	}

	arr[start_str][start_col] = '#';
	if (arr[start_str + 1][start_col] != '#')
		recursia(arr, start_str + 1, start_col);
	if (arr[start_str - 1][start_col] != '#')
		recursia(arr, start_str - 1, start_col);
	if (arr[start_str][start_col + 1] != '#')
		recursia(arr, start_str, start_col + 1);
	if (arr[start_str][start_col - 1] != '#')
		recursia(arr, start_str, start_col - 1);
	return;
}

int main() {
	setlocale(LC_ALL, "rus");

	int start_str, start_col;

	string maze[25] = {
		/*0*/	"####B######################",
		/*1*/	"# #       #   #      #    #",
		/*2*/	"# # # ###### #### ####### #",
		/*3*/	"# # # #       #   #       #",
		/*4*/	"#   # # ######### # ##### #",
		/*5*/	"# # # #   #       #     # #",
		/*6*/	"### ### ### ############# #",
		/*7*/	"# #   #     # #           #",
		/*8*/	"# # #   ####### ###########",
		/*9*/	"# # # #       # #         C",
		/*10*/	"# # ##### ### # # ####### #",
		/*11*/	"# # #     ### # #       # #",
		/*12*/	"#   ##### ### # ######### #",
		/*13*/	"######### ### #           #",
		/*14*/	"# ####### ### #############",
		/*15*/	"A           #   ###   #   #",
		/*16*/	"# ############# ### # # # #",
		/*17*/	"# ###       # # ### # # # #",
		/*18*/	"# ######### # # ### # # # F",
		/*19*/	"#       ### # #     # # # #",
		/*20*/	"# ######### # ##### # # # #",
		/*21*/	"# #######   #       #   # #",
		/*22*/	"# ####### ######### #######",
		/*23*/	"#         #########       #",
		/*24*/	"#######E############D######"
	};

	show(maze, 25, 28);

	cout << "Введите начальное положение: ";
	cin >> start_col >> start_str;

	if (start_str <= 0 || start_str >= 24 || start_col <= 0 || start_col >= 27 - 1 || maze[start_str][start_col] == '#') {
		cout << "Ошибка, неверное значение начального положения, попробуйте еще раз\n";
		system("pause");
		system("cls");
		main();
	}
	else {
		recursia(maze, start_str, start_col);
	}

	cout << endl;
	system("pause");
	return 0;
}