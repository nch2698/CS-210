#include <iostream>
#include <iomanip>
using namespace std;
const int row = 5;
const int col = 3;
const int size = 4;

struct Player{
	string name;
	int id;
	int score = 0;
	int color = NULL; // 0-Green, 1-Yellow, 2-Red
};

//Admin privillege

void swap(int &a,int &b);
void changeColor(int menu[][col], int row);
void inputPosition_Color(int & ,int &, int &, int menu[][col], int row);

//Player privilige

void playerInfo(Player &);
void askPlayerName_Color(Player &player);
void capitalizeName(string &);

//Khoi tao tro choi, Choi theo luot
void printMenu();
void createPlayBoard(int [][col],int);
void printPlayBoard(int [][col],int);
void gamePlay(int menu[][col], int row, Player &player);
void nimbleFeet(Player players[], int size, int menu[][col], int row);
void printSummary(Player players[],int size);

int main(){
	//Create playboard(menu) and show it
	int menu [row][col];
	
	
	/*changeColor(menu,row);
	printPlayBoard(menu,row);*/

	Player player1, player2, player3, player4;
	Player players[] = {player1 , player2, player3, player4};
	bool keepPlaying;
	int choice;
	printMenu();
	do {
		do{
			cout << "\nEnter your choice: ";
			cin >> choice;
		}while((choice < 1 || choice > 5) && !(isdigit(choice)));
		
		switch (choice)
		{
			case 1:
			{
				createPlayBoard(menu,row);
				printPlayBoard(menu,row);
				break;
			}
			case 2:
			{
				changeColor(menu,row);
				printPlayBoard(menu,row);
				break;
			}
			case 3:
			{
				nimbleFeet(players, size, menu, row);
				
				break;
			}
			case 4:
			{
				printSummary(players, size);
				break;
			}
			case 5:
				cout << "Thank you. Goodbye.\n";	
				break;	
		}		
		
	}while(choice != 5);
	return 0;
}

//Admin part
void changeColor(int menu[][col], int row){
	int row_pos,col_pos;
	int color;
	inputPosition_Color(row_pos,col_pos,color,menu,row);
	
	for (int j=0; j < col;++j){
		if (menu[row_pos][j] == color)
			swap(menu[row_pos][col_pos],menu[row_pos][j]);
	}
}
void inputPosition_Color(int &row_pos,int &col_pos, int &color, int menu[][col], int row){
	bool condition;
	do {
		cout << "Enter the position you want to change (row-col) (Ex:2 3): ";
		cin >> row_pos >> col_pos;
		
		condition = ((0<=row_pos && row_pos<=row) && (0<=col_pos && col_pos<=col)) ? true : false;
		if (!condition) 
			cout << "The position " << row_pos << "," << col_pos << " not in range.\n";	
	}while (!condition);
	
	do{
		cout << "Enter the color value you want to place (0-Green, 1-Yellow, 2-Red): ";
		cin >> color;
		if (color != 0 && color != 1 && color != 2) cout << "\nInvalid Color.\n";
		else if (menu[row_pos][col_pos] == color) cout << "\nDuplicate Color at that position.\n";
		
		condition = ((color == 0 || color == 1 || color == 2) && (menu[row_pos][col_pos] != color)) ? true : false;
	}while (!condition);
}

//Tao bang mau 5x3
void createPlayBoard(int menu[][col], int row){
	
	  menu[0][0] = 0;
	  menu[0][1] = 1;
	  menu[0][2] = 2;
	  menu[1][0] = 1;
	  menu[1][1] = 2;
	  menu[1][2] = 0;
	  menu[2][0] = 2;
	  menu[2][1] = 1;
	  menu[2][2] = 0;
	  menu[3][0] = 0;
	  menu[3][1] = 2;
	  menu[3][2] = 1;
	  menu[4][0] = 1;
	  menu[4][1] = 2;
	  menu[4][2] = 0;
}

void printPlayBoard(int menu[][col], int row){
	for (int i=0; i < row; i++){
		for (int j=0; j < col; j++)
			cout << menu[i][j];
		cout << endl;
	}
}

void swap(int &a,int &b){
	int c;
	c = a;
	a = b;
	b = c;
}

//Player part
void askPlayerName_Color(Player &player){
	cin.ignore();
	cout << "What is your name?";
	getline(cin,player.name);
	
	do {
		cout << "What color do you choose (0-Green, 1-Yellow, 2-Red)?";
		cin >> player.color;
		if (player.color != 0 && player.color != 1 && player.color != 2)
			cout << "Invalid color.\n";
	}while(player.color != 0 && player.color != 1 && player.color != 2);
	capitalizeName(player.name);
}

//Name modification
void capitalizeName(string &name){
	bool flag = false;
	name[0] = toupper(name[0]);
	for (int i=0; i < name.length();++i){
		if (isspace(name[i]) && flag == false)
			flag = true;
		if (isalpha(name[i]) && flag)
		{
			name[i] = toupper(name[i]);
			flag = false;
		}
	}
}
//Game play
void gamePlay(int menu[][col], int row, Player &player){
		int col_pos, row_pos = 0;
		bool nextRound;	
		cout << "\nThe row position is the round you are playing.\n";
		cout << player.name << endl;
		do
		{	
			do {
				cout << "Enter the column position for round " << (row_pos+1) << " (0 1 2): ";
				cin >> col_pos;
			}while(col_pos != 0 && col_pos != 1 && col_pos != 2);
			
			if (menu[row_pos][col_pos] == player.color && row_pos < 5)
			{
				cout << "You win round " << row_pos + 1 << endl;
				nextRound = true;
				(player.score)++;
				row_pos++;
			}else
			{
				nextRound = false;
				cout << "Color not match. You lose.\n";
				row_pos = 0;
			}
		}while(nextRound);	
}

void nimbleFeet(Player players[], int size, int menu[][col], int row){
	for (int i=0; i < size;i++){
		askPlayerName_Color(players[i]);
		gamePlay(menu, row, players[i]);
		cin.ignore();
	}
}

//In bang tong sap
void printSummary(Player players[],int size)
{
	cout << "\n---------------Score board-------------------------\n";
	cout << left<<setw(7) << "Round" << setw(20) << "Ten nguoi choi" << setw(15) << "Mau lua chon" << setw(8) << "Diem so" << endl;
	for (int i=0; i < size;i++)
	{
		cout << left <<setw(7) << i+1 << setw(20) << players[i].name << setw(15) << players[i].color << setw(8) << players[i].score << endl;
	}
	//Chua lam duoc min max, gap bugs
	/* max , maxIndex;
	int min , minIndex;
	max = players[0].score, min = players[0].score;
	for (int i=0; i < size; i++)
	{
		if (players[i].score > max){
			max = players[i].score;
			maxIndex = i;
		}	
		if (players[i].score < min){
			min = players[i].score;
			minIndex = i;
		}
			
	}
	cout << players[maxIndex].name << " has the highest score " << max << " points."<<endl;
	cout << players[minIndex].name << " has the lowest score " << min << " points."<<endl;*/
	cout << "---------------------------------------------------\n";
}

void printMenu(){
	
	cout << "\nChao mung den voi tro choi hanh khach cuoi cung.\n";
	cout << "\n---------------Menu-----------------------\n";
	cout << "1. Khoi tao moi truong choi." << endl;
	cout << "2. Thay doi vi tri cac o mau trong cung 1 hang." << endl;
	cout << "3. Choi tro choi theo luot 4 nguoi." << endl;
	cout << "4. In bang tong sap." << endl;
	cout << "5. Thoat." << endl;
	
}

