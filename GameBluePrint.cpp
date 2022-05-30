
#pragma region include <Library>
#include <iostream>
#include <Windows.h>
#include <array>
#include <string>
#include <stdbool.h>
#include <math.h>
#include <cstdlib>
using namespace std;
#pragma endregion

#pragma region ShipPresentVariables
bool is4BlockShipPresent = false;
bool is3BlockShipsPresent = false;
bool is2BlockShipsPresent = false;
bool is1BlockShipsPresent = false;
#pragma endregion

#pragma region BoolMovementVarables
bool BotMovement = true;
bool PlayerMovement = true;
bool PlayerHaveRemainingShips = true;
bool BotHaveRemainingShips = true;

#pragma endregion

#pragma region include Common_.h_Files
#include "Enums.hpp"
#include "Printing_Board.hpp"
#include "SettingEmptyArray.hpp"
#include "ConvertPlayerInPutLocation.hpp"
#include "ValidatePlayerInPutLocation.hpp"
#pragma endregion

#pragma region BotFiles

#pragma region include "BotMovementFiles"
#include "BotShootMovement.hpp"
#include "BotMainMovementClass.hpp"
#pragma endregion

#pragma region include BotReceiveShoot
#include "BotReceiveShoot.hpp"
#pragma endregion

#pragma region include "BotFiles"
#include "GenerateNavigationsDots.hpp"
#include "PathFinding_SuccessorThree.hpp"
#include "PathFinding_SuccessorTwo.hpp"
#include "PathFinding.hpp"
#include "ValideteShipPosition.hpp"
#include "NextShipSegmentGenerator.hpp"
#include "Gemerate4BlockShip.hpp"
#include "Generate3BlockShip.hpp"
#include "Generate2BlockShip.hpp"
#include "Generate1BlockShip.hpp"
#include "ShipGenerateClass.hpp"
#include "MainBotFunction.hpp"
#pragma endregion

#pragma endregion
























int main()
{
	BotMainMovementClass BotMainMovementClass;
	string testPlayerInput = "";
	Bot Bot;

		while (BotHaveRemainingShips && PlayerHaveRemainingShips)
	{

		if (PlayerMovement)
		{

		}
		if (BotMovement)
		{
			BotMainMovementClass.BotShootingTurn();
		}
	}
	cin >> testPlayerInput;
	ValidatePlayerInPutLocation ValidatePlayerInputLocation(testPlayerInput);
	return 0;
}



/*
 
A - 65 J-74
a - 97 j-106
0 - 48 9-57
Genertowanie statku:
Doda� tablic� tymczasow� (jakby bot chcia� generowa� w rogu i szuka� kolejnej lokacji, sam si� blokuje) (niech szuka maksylanie 4 razy nowej pozycji)
ewentualnie zamiast tablicy stringa z pozycjami zaj�tymi przez generowany statek, aby m�g� generowa� w innym kierunku (mo�e powsta� p�tla je�li b�dzie generowa� w wolnej przestrzeni 2
(a chce statek 3)


pathfinding algorytm dla 3 statk�w (max 2 kroki do przodu)



Movement:
Array Trafionych statk�w, array<array,4>,1>oneBlockShipsArray;
rand() Row
rand() Column


if(bot[row][column] == 1)
{
 bool hit =true;
 bot[row][column] = X;
 

}

if(bot[row][column] == 2)
bool hit = true;
for

	for

bool Hit = true;
	if 


	if(row ==

else

hit = false;






for(Row)
{
	for(Column)
	{
		
	}
}



je�li w kiedunku [-1;1][-1;1] niema ju� �adnej '.' (albo s� same [1,2,3,4,'*'])
przeskocz do innego [X,Y] z array kt�ry ma ju� X jako warto��, 
je�li trafienie -> zmien� warto�� "1,2,3,4" w array na 'X' p�tla if sprawdzaj�ca
czy w danym wierszu array jest jeszcze jaka� cyfra, je�li nie bool shipXblock drowned;
bool botHaveMove = true;

mo�e doda� 1 miejsce wi�cej w array (na pocz�tku) jako [0,1] - Drowned/Present








*/

