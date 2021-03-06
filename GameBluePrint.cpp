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
#pragma region VariablesDeclaration
#pragma region PlayerShipPresentVariables
bool isPlayer4BlockShipPresent = false;
bool isPlayer3BlockShipsPresent = false;
bool isPlayer2BlockShipsPresent = false;
bool isPlayer1BlockShipsPresent = false;
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
#include "Printing_Board.hpp"
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
#include "PlayerIsShooting.h"
#pragma endregion

int main()
{
	Board board_1;

	board_1.SetUp();
	board_1.setUserGrid();
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	sf::RenderWindow window;
	window.create(sf::VideoMode{ 1024, 610 }, "Boards");
	sf::Event event;
	sf::Texture boardTexture;
	sf::Texture GridTexture;
	sf::Texture instruction1;
	sf::Texture instructionPlaceHolder;
	sf::Sprite board;
	sf::Sprite botgrid;
	sf::Sprite currentInstriction;
	sf::Sprite usergrid;
	sf::Image instruction2;

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
			currentInstriction.setPosition(190, 520);
		}

		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}

		window.draw(board);
		window.draw(usergrid);
		window.draw(botgrid);
		window.draw(currentInstriction);
		board_1.addSensorsToGrid();
		board_1.addBoxToSquare(window);
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

	BotMainMovementClass BotMainMovementClass;
	Bot Bot;
	BoardShooting board_shooting;
	board_shooting.takeBotGeneratedArray(BotGeneratedArray);
	board_shooting.SetUp();
	board_shooting.pass2BlockArray(Bot2BlockShipsInNavigationArray);
	board_shooting.pass3BlockArray(Bot3BlockShipsInNavigationArray);
	board_shooting.pass4BlockArray(Bot4BlockShipInNavigationArray);

	while (BotHaveRemainingShips && PlayerHaveRemainingShips)
	{
		board_1.addSensorsToGrid();
		board_1.addBoxToSquare(window, GameInProgress, BotHitThatShip, BotShotHere);
		instruction1.loadFromFile("InstructionPlayerTurnNow.png");
		currentInstriction.setTexture(instruction1);
		currentInstriction.setPosition(190, 520);
		window.draw(currentInstriction);
		board_shooting.addSensorsToGrid();
		board_shooting.addBoxToSquare(window);
		window.display();

		if (isPlayerMovement)
		{
			board_shooting.gridEvent(window, isPlayerMovement, currentInstriction);
			BotHaveRemainingShips = board_shooting.DoesBotStillHaveShips();
		}
		else
		{
			BotMainMovementClass.BotShootingTurn();
			Printing Printing(BotShootingAray);
			Sleep(1000);
		}
	}

	if (BotHaveRemainingShips)
	{
		boardTexture.loadFromFile("NEWBotWON.png");
		window.display();
	}
	else
	{
		boardTexture.loadFromFile("NEWPlayerWON.png");
		window.display();
	}

	board.setTexture(boardTexture);
	window.draw(board);
	window.display();
	Sleep(6000);
	return 0;
}