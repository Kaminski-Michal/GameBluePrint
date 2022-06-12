

#pragma region include <Library>
#pragma region SFML_Library
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#pragma endregion
#include <iostream>
#include <Windows.h>
#include <array>
#include <string>
#include <fstream>
#include <stdbool.h>
#include <math.h>
#include <cstdlib>
#include <WinUser.h>
#pragma endregion

int BotTurnsToWin = 0;


#pragma region VariablesDeclaration
#pragma region PlayerShipPresentVariables
bool isPlayer4BlockShipPresent = false;//1x
bool isPlayer3BlockShipsPresent = false;//2x
bool isPlayer2BlockShipsPresent = false;//3x
bool isPlayer1BlockShipsPresent = false;//4x
#pragma endregion
#pragma region BotShipPresentVariables
bool is4BlockShipPresent = false;//1x
bool is3BlockShipsPresent = false;//2x
bool is2BlockShipsPresent = false;//3x
bool is1BlockShipsPresent = false;//4x
#pragma endregion
#pragma region BoolMovementVarables
bool isBotMovement = true;
bool isPlayerMovement = true;
bool PlayerHaveRemainingShips = true;
bool BotHaveRemainingShips = true;

#pragma endregion
#pragma endregion

#pragma region include Common_.h_Files
#include "Enums.hpp"
#include "GenerateNavigationsDots.hpp"
#include "InstructionPrintingClass.h"
#include "Printing_Board.hpp"
//#include "ConvertPlayerInPutLocation.hpp"
#include "Shooting.hpp"
#include "SettingEmptyArray.hpp"
#pragma endregion

#pragma region BotFiles

#pragma region include "BotMovementFiles"
#include "UpdatedPathFindingProgressionShootFour.hpp"
#include "UpdatedPathFindingProgressionShootThree.hpp"
#include "UpdatedPathFindingProgressionStart.hpp"
#include "BotShootMovement.hpp"
#include "BotMainMovementClass.hpp"
#pragma endregion

#pragma region include BotReceiveShoot
#include "BotReceiveShoot.hpp"
#pragma endregion

#pragma region include "BotShipsFiles"
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

#pragma region PlayerFiles
#include "Board.h"
#include "BoardShooting.h"
#include "PlayerShooting.hpp"
#include "Player_Check_all_ships.hpp"


#pragma endregion






int main()
{
	Bot1BlockShipsInNavigationArray;
	Board board_1;
	BoardShooting board_shooting;
	board_1.SetUp();
	board_1.setUserGrid();
	board_shooting.SetUp();
	board_shooting.setUserGrid();
	bool TypesOfShipsPresent = false;
	InstructionPrintingClass Print();
	//ShowWindow(GetConsoleWindow(), SW_HIDE); unset as comment to hide console (leaves only main game window)
	sf::RenderWindow window;
	window.create(sf::VideoMode{ 1024, 610 }, "Boards");
	//window.setFramerateLimit(0);
	sf::Event event;
	sf::Texture boardTexture;
	sf::Texture GridTexture;
	sf::Sprite board;
	sf::Sprite botgrid;
	sf::Texture instructionPlaceHolder;
	sf::Texture instruction1;
	sf::Image instruction2;
	sf::Sprite currentInstriction;
	sf::Sprite usergrid;

	boardTexture.loadFromFile("Plansze.png");
	window.display();
	board.setTexture(boardTexture);
	GridTexture.loadFromFile("net.png");

	


	
	usergrid.setTexture(GridTexture);
	botgrid.setTexture(GridTexture);
	usergrid.setPosition(50, 150);
	botgrid.setPosition(650, 150);



	
	
	
	
	window.display();
	while (!isPlayer1BlockShipsPresent || !isPlayer2BlockShipsPresent || !isPlayer3BlockShipsPresent || !isPlayer4BlockShipPresent)
	{
		

		if (!isPlayer4BlockShipPresent)
		{
			instruction1.loadFromFile("InstructionPlace4BlockShipNow.png");
			currentInstriction.setTexture(instruction1);
			currentInstriction.setPosition(190, 520);
		}
		else if (!isPlayer3BlockShipsPresent)
		{
			instruction1.loadFromFile("InstructionPlace3BlockShipNow.png");
			currentInstriction.setTexture(instruction1);
			currentInstriction.setPosition(190, 520);
		}
		else if (!isPlayer2BlockShipsPresent)
		{
			instruction1.loadFromFile("InstructionPlace2BlockShipNow.png");
			currentInstriction.setTexture(instruction1);
			currentInstriction.setPosition(190, 520);
		}
		else if (!isPlayer1BlockShipsPresent)
		{
			instruction1.loadFromFile("InstructionPlace1BlockShipNow.png");
			currentInstriction.setTexture(instruction1);
			currentInstriction.setPosition(190,520);
		}

		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}

		//window.clear();
		
		
		
		window.draw(board);
		window.draw(usergrid);
		window.draw(botgrid);


		window.draw(currentInstriction);

		board_1.addSensorsToGrid();
		board_1.addBoxToSquare(window);


		//board_1.readUserGridInfo(window);
		board_1.gridEvent(window);
		
		window.display();
		

		if (!isPlayer4BlockShipPresent)
		{
			isPlayer4BlockShipPresent = board_1.GetConfirmationIfAllShipsArePresent(PlayersPlacedShips::FourBlockShips);
		}
		else if (!isPlayer3BlockShipsPresent)
		{
			isPlayer3BlockShipsPresent = board_1.GetConfirmationIfAllShipsArePresent(PlayersPlacedShips::ThreeBlockShips);
		}
		else if (!isPlayer2BlockShipsPresent)
		{
			isPlayer2BlockShipsPresent = board_1.GetConfirmationIfAllShipsArePresent(PlayersPlacedShips::TwoBlockShips);
		}
		else if (!isPlayer1BlockShipsPresent)
		{
			isPlayer1BlockShipsPresent = board_1.GetConfirmationIfAllShipsArePresent(PlayersPlacedShips::OneBlockShips);
		}
		


		
	} 
	PlayerArray = board_1.GetCompletetPlayerArray();
	Printing print(PlayerArray);
	board_shooting.addSensorsToGrid();
	board_shooting.addBoxToSquare(window);
	board_shooting.gridEvent(window);
	window.display();
	window.clear(sf::Color::Black);
	int x;
	std::cin >> x;
	BotMainMovementClass BotMainMovementClass;
	Bot Bot;
	PlayerShooting PlayerShooting;
	//GenerateBotShips Generate(PlayerArray); //Remove when PlayerArray added also remove isXBlockShipPresent (from file ShipGenerateClass.hpp) - made to have quick access to "Player" board and shooting at it 
	
	
	while (BotHaveRemainingShips && PlayerHaveRemainingShips)
	{

		if (isPlayerMovement)
		{
			PlayerShooting.PlayerIsShooting();
		}
		else
		{
			BotMainMovementClass.BotShootingTurn();
			Printing Printing(BotShootingAray);

		}

	}
	std::cout << "Bot needed: " << BotTurnsToWin << "turns to win this\n";
	return 0;







	//Wy�wietla now� tablic� (teraz pod strzelanie)
	//aktualizacja tablicy po strzale bota 

	
	

}

