

class GenerateBotShips
{
public:
	GenerateBotShips(std::array<std::array<char, 10>, 10>&BotGeneratedArray)
	{
		FourBlockShip fourBlockShipGenerator;
		ThreeBlockShipGenerator threeBlockShipGenerator;
		TwoBlockShipGenerator twoBlockShipGenerator;
		OneBlockShipGenerator oneBlockShipGenerator;
		GenerateNavigationDots generateNavigationDots;
		GenerateEmptyArray(BotGeneratedArray);
		is4BlockShipPresent = false;
		is3BlockShipsPresent = false;
		is2BlockShipsPresent = false;
		is1BlockShipsPresent = false;

		while (!is4BlockShipPresent || !is3BlockShipsPresent || !is2BlockShipsPresent || !is1BlockShipsPresent)
		{
			if (!is4BlockShipPresent)
			{
				fourBlockShipGenerator.Generate4BlockShip(BotGeneratedArray);
				generateNavigationDots.GenerateDots(BotGeneratedArray);
			}

			if (!is3BlockShipsPresent)
			{
				threeBlockShipGenerator.Generate3BlockShip(BotGeneratedArray);
				generateNavigationDots.GenerateDots(BotGeneratedArray);
			}

			if (!is2BlockShipsPresent)
			{
				twoBlockShipGenerator.Generate2BlockShip(BotGeneratedArray);
				generateNavigationDots.GenerateDots(BotGeneratedArray);

			}

			if (!is1BlockShipsPresent)
			{
				oneBlockShipGenerator.Generate1BlockShip(BotGeneratedArray);
				generateNavigationDots.GenerateDots(BotGeneratedArray);

			}			
		}
		Printing Printing(BotGeneratedArray);//Delete when finished
	}
};
