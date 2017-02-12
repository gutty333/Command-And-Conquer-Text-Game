#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

#include "Building.h"
#include "ConstructionYard.h"
#include "PowerPlant.h"
#include "Refinery.h"
#include "Barracks.h"
#include "WarFactory.h"
#include "CommandPost.h"
#include "Airfield.h"
#include "Armory.h"
#include "TechCenter.h"
#include "CommandLink.h"

#include "Unit.h"
#include "Rifleman.h"
#include "MissileSquad.h"
#include "Engineer.h"
#include "Grenadier.h"
#include "SniperTeam.h"
#include "ZoneTrooper.h"

#include "Apc.h"
#include "Pitbull.h"
#include "Predator.h"
#include "Harvester.h"
#include "Mcv.h"
#include "Rig.h"
#include "Juggernaut.h"
#include "MammothTank.h"

#include "Orca.h"
#include "Firehawk.h"

using namespace std;

// GDI buildings
const int GDI_SIZE = 9;
const string GDI[GDI_SIZE] = { "Power Plant", "Refinery", "Barracks", "War Factory", "Command Post", "Airfield" , "Armory", "Tech Center", "Space Command Uplink" };

// Unit Types
const string unitTypes[] = { "Infantry","Vehicle","Air" };

// GDI Infantry Units
const string GDI_INFANTRY[] = { "Rifleman Squad", "Missile Squad", "Engineer", "Grenadier Squad", "Sniper Team", "Zone Trooper" };
// GDI Vehicle Units
const string GDI_VEHICLE[] = { "CC-6 Pitbull", "Guardian APC","MBT-6 Predator", "Harvester", "Mobile Construction Vehicle", "Rig", "Juggernaut MK. III", "Mammoth MK. III" };
// GDI Air Units
const string GDI_AIR[] = { "A-15 Orca", "Firehawk" };

int main()
{
	Player player;
	Building* structure;
	Unit* unit;
	int choice,select;
	string line;
	line.assign(50, '-');
	cout << "Welcome back commander" << endl;
	cout << "This is Command and Conquer you will be playing as the GDI faction" << endl;
	player.setResources(20000);
	cout << endl << "Entering Sandbox Mode" << endl;
	cout << line << endl;
	

	do
	{
		Building* list[] = { new PowerPlant, new Refinery, new Barracks, new WarFactory, new CommandPost, new AirField, new Armory, new TechCenter, new CommandLink };
		Unit* infantry[] = { new Rifleman, new MissileSquad, new Engineer, new Grenadier, new SniperTeam, new ZoneTrooper };
		Unit* vehicle[] = { new Apc, new Pitbull, new Predator, new Harvester, new Mcv, new Rig, new Juggernaut, new MammothTank };
		Unit* air[] = { new Orca, new Firehawk };
		// Player command menu
		cout << endl << endl << "Action Menu (Please select an action by entering corresponding number)" << endl;
		cout << line << endl;
		cout << "1. Check Stats" << endl;
		cout << "2. Buy Building" << endl;
		cout << "3. Sell Building" << endl;
		cout << "4. Power Manage" << endl;
		cout << "5. Repair Building" << endl;
		cout << "6. Buy Units" << endl;
		cout << "7. Destroy Units" << endl;
		cout << "8. Exit" << endl;
		cin >> choice;

		// User input validation
		while (choice < 1 || choice > 8)
		{
			cout << "Please enter a valid choice number (1-7)" << endl;
			cin >> choice;
		}



		switch (choice)
		{
			case 1: // View Stats
			{
				cout << endl << line << endl << "\tHere are your stats commander" << endl;

				cout << endl << line << endl<<"\tResources" << endl;
				cout << "\tMoney: " << player.getResources() << endl;

				cout << endl << line << endl << "\tPower Status" << endl;
				cout << "\tCurrent Power: " << player.getCurrentPower() << endl;
				cout << "\tRequired Power: " << player.getRequiredPower() << endl;

				cout << endl << line << endl << "\tYou have a total of " << player.getTotalBuildings() << " Buildings" << endl;
				player.printBuildings();

				cout << endl << line << endl << "\tUnits" << endl;
				player.printUnits();

				break;
			}
			case 2: // Build Building
			{
				cout << endl << line << endl << "\tWhich structure do you want to build?" << endl;
				for (int x = 0; x < GDI_SIZE; x++)
				{
					cout << "\t" << x << ". " << GDI[x] << endl;
				}
				cin >> select;

				player.buildBuilding(list[select]);
				player.checkPower();
				break;
			}
			case 3: // Sell Building
			{
				cout << endl << line << endl << "\tWhich structure do you want to sell?" << endl;
				player.printBuildingList();
				cin >> select;

				player.sellBuilding(select);
				player.checkPower();
				break;
			}
			case 4: // Power Manage
			{
				cout << endl << line << endl << "\tWhich structure do you want to power manage?" << endl;
				player.printBuildingList();
				cin >> select;

				player.managePower(select);
				player.checkPower();
				break;
			}
			case 5: 
			{
				cout << endl << line << endl << "\tWhich structure do you want to repair?" << endl;
				player.printBuildingList();
				cin >> select;

				if (player.needsRepair(select))
				{
					// Menu to decide how we will repair our structure
					cout << "\tWhat do you want to use to repair the structure?" << endl;
					cout << "\t1. Repair Tool" << endl;
					cout << "\t2. Engineer" << endl;
					int repairChoice;
					cin >> repairChoice;

					switch (repairChoice)
					{
						case 1: 
						{
							player.repairBuilding(select);
							break;
						}
						case 2:
						{
							player.repairBuilding2(select);
							break;
						}
					}
				}
				
				break;
			}
			case 6:
			{
				cout << endl << line << endl << "\tWhich unit type do you want to buy?" << endl;
				for (int x = 0; x < 3; x++)
				{
					cout << "\t" << x + 1 << " " << unitTypes[x] << endl;
				}
				int unitChoice;
				cin >> unitChoice;

				switch (unitChoice)
				{
					case 1:
					{
						cout << endl << line << endl << "\tWhich infantry unit do you want to buy?" << endl;
						for (int x = 0; x < 6; x++)
						{
							cout << "\t" << x << ". " << GDI_INFANTRY[x] << endl;
						}
						cin >> unitChoice;
						cout << "\tHow many do you want to train?" << endl;
						int size;
						cin >> size;

						player.buildUnit(infantry[unitChoice], size);
						break;
					}
					case 2:
					{
						cout << endl << line << endl << "\tWhich vehicle unit do you want to buy?" << endl;
						for (int x = 0; x < 8; x++)
						{
							cout << "\t" << x << ". " << GDI_VEHICLE[x] << endl;
						}
						cin >> unitChoice;
						cout << "\tHow many do you want to train?" << endl;
						int size;
						cin >> size;

						player.buildUnit(vehicle[unitChoice], size);
						break;
					}
					case 3:
					{
						cout << endl << line << endl << "\tWhich air unit do you want to buy?" << endl;
						for (int x = 0; x < 2; x++)
						{
							cout << "\t" << x << ". " << GDI_AIR[x] << endl;
						}
						cin >> unitChoice;
						cout << "\tHow many do you want to train?" << endl;
						int size;
						cin >> size;

						player.buildUnit(air[unitChoice], size);
						break;
					}
				}
				break;
			}
			case 7:
			{
				if (player.getTotalUnits() > 0)
				{
					cout << "\tWhich unit do you want to destroy?" << endl;
					player.printUnitList();
					cin >> select;
					cout << "\tHow many do you want to destroy?" << endl;
					int destroyTotal;
					cin >> destroyTotal;

					player.destroyUnit(select, destroyTotal);
				}
				else
				{
					cout << "\tYou do not have any units" << endl;
				}
				
				break;
			}
		}

		if (choice > 1 && choice < 8)
		{
			player.harvest();
		}
		

		player.checkAlive();

	}while (choice != 8 && player.getAlive());


	cout << endl << line << endl << "\tThank you for playing" << endl;

	return 0;
}