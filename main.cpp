/*
Program: Prison Ramen Tycoon
Author: Harry Chen
Version: 1.4.0
*/
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int main()
{
    int mainmenuChoice, shopChoice, ramenChoice, seasoChoice, bowlChoice, chopChoice, setrecipeChoice, locationChoice, // Choice Variables
    escapeChoice, rankchoice, invquit;
    int stamps = 130, ramenpacks = 0, seasonpackets = 0, bowls = 0, chopsticks = 0; // PLAYER INVENTORY VARIABLES
    const int ramendeal1 = 10, ramendeal2 = 25, ramendeal3 = 50, ramenprice1 =  20, ramenprice2 = 40, ramenprice3 = 70; // RAMEN DEALS
    const int seasodeal1 = 12, seasodeal2 = 30, seasodeal3 = 60, seasoprice1 = 18, seasoprice2 = 33, seasoprice3 = 56; // SEASONING DEALS
    const int bowldeal1 = 8, bowldeal2 = 20, bowldeal3 = 40, bowlprice1 = 10, bowlprice2 = 20, bowlprice3 = 36; // BOWL DEALS
    const int chopdeal1 = 16, chopdeal2 = 40, chopdeal3 = 80, chopprice1 = 18, chopprice2 = 36, chopprice3 = 64; // CHOPSTICKS DEALS
    bool notenoughmoney = false, success = false, toolow = false, escapesuccess = false, ranout = false;
    string username, wprisonrank = "New Inmate", wlocation = "My Prison Cell";
    int totalearnings = 0, totalcustomers = 0, customers;
    int setprice = 15, reciperamen = 1, recipeseason = 1, recipebowls = 1, recipechop = 2; // RECIPE VARIABLES
    int location = 0, prisonrank = 0;
    int minvisitors, maxvisitors, visitors, buyrate = 0;
    int day = 0, reputation = 0, stampstoday = 0;
    int cellcost = 0, gymcost = 70, courtcost = 150,  cafetcost = 300, locationcost;
    int recipepoints, ramenpoints, seasopoints, pricefactor, repfactor, visitorbonus;
    int crankcost = 250, brankcost = 2500, arankcost = 10000;
    int randomnumber;
    int escapecost1 = 100000, escapecost2 = 300000, escapedraw, escapeattempts = 0;

    cout << "Welcome to Prison Ramen Tycoon!\n" << endl;
    cout << "Your Objective is to run a Ramen business in a Prison setting." << endl;
    cout << "Perfect your Ramen Recipe and Upgrade your Prison Status," << endl;
    cout << "which unlocks better locations for you to sell Ramen." << endl;
    cout << "Your End Game Goal is to Escape the Prison." << endl;
    cout << "\nGood Luck and Have fun! ~ Harry Chen\n" << endl;
    system("pause");
    system("cls");

    cout << "Please Enter Your Username:" << endl;
    cin >> username;
    system("cls");
    cout << "Hey " << username << "," << endl;
    cout << "\nIt looks like you've landed your" << endl;
    cout << "filthy butt in the Iron Fist Maximum" << endl;
    cout << "Security Prison. Don't even think" << endl;
    cout << "about escaping you maggot or your" << endl;
    cout << "life sentence might just become" << endl;
    cout << "your Death Sentence!" << endl;
    cout << "\nWarden Chow" << endl;
    cout << "\nP.S. Enjoy your complimentary 130 Stamps...\n" << endl;
    system("PAUSE");

    srand(time(0));
    do //START MAIN GAME LOOP
    {
        if(prisonrank == 1)//RANK TO STRING START
        {
            wprisonrank = "C-Rank";
        }
        else if(prisonrank == 2)
        {
            wprisonrank = "B-Rank";
        }
        else if(prisonrank == 3)
        {
            wprisonrank = "A-Rank";
        }// RANK TO STRING END

        if(location == 0)
        {
            locationcost = cellcost;
        }
        else if(location == 1)
        {
            locationcost = gymcost;
        }
        else if(location == 2)
        {
            locationcost = courtcost;
        }
        else if(location == 3)
        {
            locationcost = cafetcost;
        }

        system("cls");// START MAIN MENU CHOICE
        cout << "__________[Main Menu]__________" << endl;
        cout << "1. Start The Day" << endl;
        cout << "2. Visit The Prison Commissary" << endl;
        cout << "3. Check Inventory & Balance" << endl;
        cout << "4. Set Recipe and Price" << endl;
        cout << "5. Prison Rankup" << endl;
        cout << "6. Set Location" << endl;
        cout << "7. Attempt To Escape" << endl;
        cout << "0. Quit The Game!\n" << endl;
        if(!cin.good())
        {
            cin.clear();
            cin.ignore(128, '\n');
            cout << "Error! Invalid Entry!\n" << endl;
        }
        cout << "What would you like to do?" << endl;
        cin >> mainmenuChoice; // END OF MAIN MENU CHOICE

        if(mainmenuChoice == 1)
        {
            system("cls");

            if(stamps >= locationcost)
            {
                stamps = stamps - locationcost;
                if(setprice >= 1 && setprice <= 10)// PRICE AFFECTING PURCHASE RATE START
                {
                    pricefactor = 40;
                }
                else if(setprice >= 11 && setprice <= 20)
                {
                    pricefactor = 20;
                }
                else if(setprice >=21 && setprice <= 30)
                {
                    pricefactor = 5;
                }
                else if(setprice >= 31 && setprice <= 40)
                {
                    pricefactor = -10;
                }
                else if(setprice >= 41 && setprice <= 50)
                {
                    pricefactor = -20;
                }// PRICE AFFECTING PURCHASE RATE END

                if(reciperamen == 1)// RAMEN RECIPE EVALUATION START
                {
                    ramenpoints = -1;
                }
                else if(reciperamen == 2)
                {
                    ramenpoints = 0;
                }
                else if(reciperamen == 3)
                {
                    ramenpoints = 1;
                }
                else if(reciperamen == 4)
                {
                    ramenpoints = 0;
                }
                else if(reciperamen == 5)
                {
                    ramenpoints = 1;
                }// RAMEN RECIPE EVALUATION END

                if(recipeseason >= 1 && recipeseason <= 3)
                {
                    seasopoints = -1;
                }
                else if(recipeseason >= 4 && recipeseason <= 5)
                {
                    seasopoints = 0;
                }
                else if(recipeseason == 6)
                {
                    seasopoints = 1;
                }
                else if(recipeseason >= 7 && recipeseason <= 8)
                {
                    seasopoints = 0;
                }
                else if(recipeseason >= 9 && recipeseason <= 10)
                {
                    seasopoints = -1;
                }

                if(reputation == 0)
                {
                    repfactor = 0;
                    visitorbonus = 0;
                }
                else if(reputation >= 1 && reputation <= 20)
                {
                    repfactor = 5;
                    visitorbonus = 3;
                }
                else if(reputation >= 21 && reputation <= 50)
                {
                    repfactor = 10;
                    visitorbonus = 6;
                }
                else if(reputation >= 51 && reputation <= 100)
                {
                    repfactor = 25;
                    visitorbonus = 12;
                }
                else if(reputation >= 101 && reputation <= 300)
                {
                    repfactor = 35;
                    visitorbonus = 24;
                }
                else if(reputation >= 301 && reputation <= 500)
                {
                    repfactor = 45;
                    visitorbonus = 32;
                }
                else if(reputation >= 501)
                {
                    repfactor = 55;
                    visitorbonus = 64;
                }
                else if(reputation <= -1 && reputation >= -10)
                {
                    repfactor = -5;
                }
                else if(reputation <= -11 && reputation >= -30)
                {
                    repfactor = -15;
                }
                else if(reputation <= -31)
                {
                    repfactor = -20;
                }

                recipepoints = ramenpoints + seasopoints;
                stampstoday = 0;
                buyrate = 40 + pricefactor + repfactor;

                if(location == 0)
                {
                    minvisitors = 10 + visitorbonus;
                    maxvisitors = 25 + visitorbonus;
                }
                else if(location == 1)
                {
                    minvisitors = 25 + visitorbonus;
                    maxvisitors = 70 + visitorbonus;
                }
                else if(location == 2)
                {
                    minvisitors = 70 + visitorbonus;
                    maxvisitors = 150 + visitorbonus;
                }
                else if(location == 3)
                {
                    minvisitors = 150 + visitorbonus;
                    maxvisitors = 450 + visitorbonus;
                }
                visitors = rand()%(maxvisitors-minvisitors+1) + minvisitors;

                customers = 0;
                for(int x = 1; x <= visitors; x++)
                {
                    randomnumber = rand()%100+1;
                    if(randomnumber <= buyrate)
                    {
                        if(ramenpacks >= reciperamen && seasonpackets >= recipeseason && bowls >= recipebowls && chopsticks >= recipechop)
                        {
                            customers++;
                            ramenpacks = ramenpacks - reciperamen;
                            seasonpackets = seasonpackets - recipeseason;
                            bowls = bowls - recipebowls;
                            chopsticks = chopsticks - recipechop;
                        }
                        else
                        {
                            ranout = true;
                        }
                    }
                }
                day++;
                stampstoday = customers*setprice;
                reputation = recipepoints*customers + reputation;
                totalearnings = totalearnings + stampstoday;
                totalcustomers = totalcustomers + customers;
                stamps = stamps + stampstoday;
                cout << "________________[Day Summary]________________" << endl;
                cout << "Location: " << wlocation << endl;
                cout << "Day " << day << endl;
                cout << "Number of Visitors: " << visitors << endl;
                cout << "Number of Customers: " << customers << endl;
                cout << "Reputation: " << reputation << endl;
                cout << "Today's Earnings: " << stampstoday << endl;
                cout << "Balance: " << stamps << " Stamps" << endl << endl;
                system("PAUSE");
                if(ranout == true)
                {
                    system("cls");
                    cout << "You were unable to serve every potential customer because" << endl;
                    cout << "you ran out of certain resources. Thus making you unable to" << endl;
                    cout << "produce your complete Ramen Recipe." << endl << endl;
                    ranout = false;
                    system("PAUSE");
                }
                system("cls");
                if(customers > 0)
                {
                    cout << "____________________[Customer Comments]____________________" << endl << endl;
                    if(setprice >= 1 && setprice <= 10)// PRICE CUSTOMER COMMENTS START
                    {
                        cout << "\"WOW! The Ramen here is extremely cheap! :D\"\n" << endl;
                    }
                    else if(setprice >= 11 && setprice <= 20)
                    {
                        cout << "\"The Ramen here is at a pretty cheap price! :)\"\n" << endl;
                    }
                    else if(setprice >=21 && setprice <= 30)
                    {
                        cout << "\"The price for Ramen is pretty good! :]\"\n" << endl;
                    }
                    else if(setprice >= 31 && setprice <= 40)
                    {
                        cout << "\"The price for Ramen is a pretty expensive. :|\"\n" << endl;
                    }
                    else if(setprice >= 41 && setprice <= 50)
                    {
                        cout << "\"The price for Ramen is EXTREMELY EXPENSIVE! >:(\"\n" << endl;
                    }// PRICE CUSTOMER COMMENTS
                    if(reciperamen == 1)// RAMEN RECIPE COMMENTS START
                    {
                        cout << "\"Your recipe needs a lot more Ramen! :(\"\n" << endl;
                    }
                    else if(reciperamen == 2)
                    {
                        cout << "\"Your recipe needs a bit more Ramen. :|\"\n" << endl;
                    }
                    else if(reciperamen == 3)
                    {
                        cout << "\"WOW! Your recipe has the Perfect amount of Ramen! :D\"\n" << endl;
                    }
                    else if(reciperamen == 4)
                    {
                        cout << "\"Your recipe needs less Ramen. :|\"\n" << endl;
                    }
                    else if(reciperamen == 5)
                    {
                        cout << "\"Your recipe needs ALOT LESS RAMEN! :(\"\n" << endl;
                    }// RAMEN RECIPE COMMENTS END

                    if(recipeseason >= 1 && recipeseason <= 3)// SEASONING COMMENTS START
                    {
                        cout << "\"Your recipe needs a lot more Seasoning! :(\"\n" << endl;
                    }
                    else if(recipeseason >= 4 && recipeseason <= 5)
                    {
                        cout << "\"Your recipe needs more Seasoning. :|\"\n" << endl;
                    }
                    else if(recipeseason == 6)
                    {
                        cout << "\"WOW! Your recipe has the Perfect amount of Seasoning! :D\"\n" << endl;
                    }
                    else if(recipeseason >= 7 && recipeseason <= 8)
                    {
                        cout << "\"Your recipe needs less Seasoning. :|\"\n" << endl;
                    }
                    else if(recipeseason >=9 && recipeseason <= 10)
                    {
                        cout << "\"Your recipe needs ALOT LESS SEASONING! :(\"\n" << endl;
                    }// SEASONING COMMENTS END
                    system("PAUSE");
                }
            }
            else if(stamps < locationcost)
            {
                cout << "You do not have enough Stamps to use " << wlocation << "." << endl << endl;
                system("pause");
            }
        }
        else if(mainmenuChoice == 2) // PRISON COMMISSARY START
        {
            do// SHOPCHOICE LOOP START
            {
                system("cls");// START SHOPCHOICE
                cout << "__________[Prison Commissary]__________ | __________[My Inventory]_________" << endl;
                cout << "1. Buy Ramen Packs                      | Balance: " << stamps << " Stamps" << endl;
                cout << "2. Buy Seasoning Packets                | Ramen Packs: " << ramenpacks << endl;
                cout << "3. Buy Bowls                            | Seasoning Packets: " << seasonpackets << endl;
                cout << "4. Buy Chopsticks                       | Bowls: " << bowls << endl;
                cout << "0. Leave The Commissary                 | Chopsticks: " << chopsticks << endl << endl;
                if(!cin.good())
                {
                    cin.clear();
                    cin.ignore(128, '\n');
                    cout << "Error! Invalid Entry!\n" << endl;
                }
                cout << "What would you like to do?" << endl;
                cin >> shopChoice;// END SHOPCHOICE

                if(shopChoice == 1)// RAMEN SHOP START
                {
                    do
                    {
                        system("cls");// RAMENCHOICE START
                        cout << "__________[Ramen Deals]__________ | __________[My Inventory]__________" << endl;
                        cout << "1. Buy " << ramendeal1 << " Packs for " << ramenprice1 << " Stamps     | Balance: " << stamps << " Stamps" << endl;
                        cout << "2. Buy " << ramendeal2 << " Packs for " << ramenprice2 << " Stamps     | Ramen Packs: " << ramenpacks << endl;
                        cout << "3. Buy " << ramendeal3 << " Packs for " << ramenprice3 << " Stamps     | Seasoning Packets: " << seasonpackets << endl;
                        cout << "0. Go Back To The Commissary Menu | Bowls: " << bowls << endl;
                        cout << "                                  | Chopsticks: " << chopsticks << endl;
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        if(notenoughmoney == true)
                        {
                            cout << "Insufficient Funds!\n" << endl;
                            notenoughmoney = false;
                        }
                        cout << "What would you like to do?" << endl;
                        cin >> ramenChoice;// RAMEN CHOICE END

                        if(ramenChoice == 1)// RAMEN SHOP EXECTUTIONS START
                        {
                            if(stamps >= ramenprice1)// SUCCESSFUL PURCHASE
                            {
                                stamps = stamps - ramenprice1;
                                ramenpacks = ramenpacks + ramendeal1;
                            }
                            else if (stamps < ramenprice1)//INSUFFICIENT FUNDS
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(ramenChoice == 2)
                        {
                            if(stamps >= ramenprice2)
                            {
                                stamps = stamps - ramenprice2;
                                ramenpacks = ramenpacks + ramendeal2;
                            }
                            else if (stamps < ramenprice2)
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(ramenChoice == 3)
                        {
                            if(stamps >= ramenprice3)
                            {
                                stamps = stamps - ramenprice3;
                                ramenpacks = ramenpacks + ramendeal3;
                            }
                            else if (stamps < ramenprice3)
                            {
                                notenoughmoney = true;
                            }
                        }//RAMEN SHOP EXECUTIONS END
                    }while(ramenChoice != 0 || ramenChoice < 0 || ramenChoice > 3 || !cin.good());
                }// RAMEN SHOP END
                else if(shopChoice == 2)// SEASONING SHOP START
                {
                    do
                    {
                        system("cls");// SEASONING CHOICE START
                        cout << "__________[Seasoning Deals]__________ | __________[My Inventory]__________" << endl;
                        cout << "1. Buy " << seasodeal1 << " Packets for " << seasoprice1 << " Stamps       | Balance: " << stamps << endl;
                        cout << "2. Buy " << seasodeal2 << " Packets for " << seasoprice2 << " Stamps       | Ramen Packs: " << ramenpacks << endl;
                        cout << "3. Buy " << seasodeal3 << " Packets for " << seasoprice3 << " Stamps       | Seasoning Packets: " << seasonpackets << endl;
                        cout << "0. Go Back To The Commissary Menu     | Bowls: " << bowls << endl;
                        cout << "                                      | Chopsticks: " << chopsticks << endl;
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        if(notenoughmoney == true)
                        {
                            cout << "Insufficient Funds!\n" << endl;
                            notenoughmoney = false;
                        }
                        cout << "What would you like to do?" << endl;
                        cin >> seasoChoice;// SEASONING CHOICE END

                        if(seasoChoice == 1)// SEASONING SHOP EXECTUTIONS START
                        {
                            if(stamps >= seasoprice1)
                            {
                                stamps = stamps - seasoprice1;
                                seasonpackets = seasonpackets + seasodeal1;
                            }
                            else if (stamps < seasoprice1)
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(seasoChoice == 2)
                        {
                            if(stamps >= seasoprice2)
                            {
                                stamps = stamps - seasoprice2;
                                seasonpackets = seasonpackets + seasodeal2;
                            }
                            else if (stamps < seasoprice2)
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(seasoChoice == 3)
                        {
                            if(stamps >= seasoprice3)
                            {
                                stamps = stamps - seasoprice3;
                                seasonpackets = seasonpackets + seasodeal3;
                            }
                            else if (stamps < seasoprice3)
                            {
                                notenoughmoney = true;
                            }
                        }// SEASONING EXECUTIONS SHOP END
                    }while(seasoChoice != 0 || seasoChoice < 0 || seasoChoice > 3 || !cin.good());
                }// SEASONING SHOP END
                else if (shopChoice == 3)
                {
                    do
                    {
                        system("cls");// BOWL CHOICE START
                        cout << "___________[Bowl Deals]___________ | __________[My Inventory]__________" << endl;
                        cout << "1. Buy " << bowldeal1 << " Bowls for " << bowlprice1 << " Stamps       | Balance: " << stamps << endl;
                        cout << "2. Buy " << bowldeal2 << " Bowls for " << bowlprice2 << " Stamps      | Ramen Packs: " << ramenpacks << endl;
                        cout << "3. Buy " << bowldeal3 << " Bowls for " << bowlprice3 << " Stamps      | Seasoning Packets: " << seasonpackets << endl;
                        cout << "0. Go Back To The Commissary Menu  | Bowls: " << bowls << endl;
                        cout << "                                   | Chopsticks: " << chopsticks << endl;
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        if(notenoughmoney == true)
                        {
                            cout << "Insufficient Funds!\n" << endl;
                            notenoughmoney = false;
                        }
                        cout << "What would you like to do?" << endl;
                        cin >> bowlChoice;// BOWL CHOICE END

                        if(bowlChoice == 1)// BOWL SHOP EXECTUTIONS START
                        {
                            if(stamps >= bowlprice1)
                            {
                                stamps = stamps - bowlprice1;
                                bowls = bowls + bowldeal1;
                            }
                            else if (stamps < bowlprice1)
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(bowlChoice == 2)
                        {
                            if(stamps >= bowlprice2)
                            {
                                stamps = stamps - bowlprice2;
                                bowls = bowls + bowldeal2;
                            }
                            else if (stamps < bowlprice2)
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(bowlChoice == 3)
                        {
                            if(stamps >= bowlprice3)
                            {
                                stamps = stamps - bowlprice3;
                                bowls = bowls + bowldeal3;
                            }
                            else if (stamps < bowlprice3)
                            {
                                notenoughmoney = true;
                            }
                        }// BOWL EXECUTIONS SHOP END
                    }while(bowlChoice != 0 || bowlChoice < 0 || bowlChoice > 3 || !cin.good());
                }// BOWL SHOP END
                else if(shopChoice == 4)//CHOPSTICKS SHOP START
                {
                    do
                    {
                        system("cls");// CHOP CHOICE START
                        cout << "__________[Chopsticks Deals]__________ | __________[My Inventory]__________" << endl;
                        cout << "1. Buy " << chopdeal1 << " Chopsticks for " << chopprice1 << " Stamps     | Balance: " << stamps << endl;
                        cout << "2. Buy " << chopdeal2 << " Chopsticks for " << chopprice2 << " Stamps     | Ramen Packs: " << ramenpacks << endl;
                        cout << "3. Buy " << chopdeal3 << " Chopsticks for " << chopprice3 << " Stamps     | Seasoning Packets: " << seasonpackets << endl;
                        cout << "0. Go Back To The Commissary Menu      | Bowls: " << bowls << endl;
                        cout << "                                       | Chopsticks: " << chopsticks << endl;
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        if(notenoughmoney == true)
                        {
                            cout << "Insufficient Funds!\n" << endl;
                            notenoughmoney = false;
                        }
                        cout << "What would you like to do?" << endl;
                        cin >> chopChoice;// CHOP CHOICE END

                        if(chopChoice == 1)// CHOPSTICKS SHOP EXECTUTIONS START
                        {
                            if(stamps >= chopprice1)// SUCCESSFUL PURCHASE
                            {
                                stamps = stamps - chopprice1;
                                chopsticks = chopsticks + chopdeal1;
                            }
                            else if (stamps < chopprice1)//INSUFFICIENT FUNDS
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(chopChoice == 2)
                        {
                            if(stamps >= chopprice2)
                            {
                                stamps = stamps - chopprice2;
                                chopsticks = chopsticks + chopdeal2;
                            }
                            else if (stamps < chopprice2)
                            {
                                notenoughmoney = true;
                            }
                        }
                        else if(chopChoice == 3)
                        {
                            if(stamps >= chopprice3)
                            {
                                stamps = stamps - chopprice3;
                                chopsticks = chopsticks + chopdeal3;
                            }
                            else if (stamps < chopprice3)
                            {
                                notenoughmoney = true;
                            }
                        }
                    }while(chopChoice != 0 || chopChoice < 0 || chopChoice > 3 || !cin.good());
                }// CHOPSTICKS SHOP END
            }while(shopChoice!= 0 || /*shopChoice < 0 || shopChoice > 3 ||*/ !cin.good());// END OF SHOP CHOICE LOOP
        }// END OF PRISON COMMISSARY
        else if(mainmenuChoice == 3) // START CHECK INVENTORY
        {
            do
            {
                system("cls");
                cout << "__________[My Inventory]_________" << endl;
                cout << "Balance: " << stamps << " Stamps" << endl;
                cout << "Ramen Packs: " << ramenpacks << endl;
                cout << "Seasoning Packets: " << seasonpackets << endl;
                cout << "Bowls: " << bowls << endl;
                cout << "Chopsticks: " << chopsticks << endl;
                if(!cin.good())
                {
                    cin.clear();
                    cin.ignore(128, '\n');
                    cout << "\nError! Invalid Entry!" << endl;
                }
                cout << "\n0. Go Back to The Main Menu" << endl;
                cin >> invquit;
            }while(invquit != 0 || !cin.good());
        }// END CHECK INVENTORY
        else if(mainmenuChoice == 4) // START SET RECIPE
        {
            do
            {
                system("cls");// START SET RECIPE
                cout << "__________[Recipe Settings]__________ | __________[My Recipe]_________" << endl;
                cout << "1. Set Price                          | Price: " << setprice << " Stamps" << endl;
                cout << "2. Set Amount Of Ramen Packs          | Ramen Packs: " << reciperamen << endl;
                cout << "3. Set Amount Of Seasoning Packets    | Seasoning Packets: " << recipeseason << endl;
                cout << "0. Go Back To The Main Menu           | Bowls: " << recipebowls /*<< " (Unchangeable)"*/ << endl;
                cout << "                                      | Chopsticks: " << recipechop /*<< " (Unchangeable)"*/ << endl;
                if(!cin.good())
                {
                    cin.clear();
                    cin.ignore(128, '\n');
                    cout << "Error! Invalid Entry!\n" << endl;
                }
                cout << "What would you like to do?" << endl;
                cin >> setrecipeChoice;// END SET RECIPE

                if(setrecipeChoice == 1)
                {
                    do
                    {
                        system("cls");
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        cout << "What would you like to set the price as? (1-50)" << endl;
                        cin >> setprice;
                    }while(setprice < 1 || setprice > 50 || !cin.good());

                }
                else if(setrecipeChoice == 2)
                {
                    do
                    {
                        system("cls");
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        cout << "How many Ramen Packs should be in one bowl? (1-5)" << endl;
                        cin >> reciperamen;
                    }while(!cin.good() || reciperamen < 1 || reciperamen > 5);
                }
                else if(setrecipeChoice == 3)
                {
                    do
                    {
                        system("cls");
                        if(!cin.good())
                        {
                            cin.clear();
                            cin.ignore(128, '\n');
                            cout << "Error! Invalid Entry!\n" << endl;
                        }
                        cout << "How many Seasoning Packets should be in one bowl? (1-10)" << endl;
                        cin >> recipeseason;
                    }while(!cin.good() || recipeseason < 1 || recipeseason > 10);
                }
            }while(setrecipeChoice != 0 || !cin.good());
        }
        else if(mainmenuChoice == 5) // PRISON RANK UP START
        {
            do
            {
                system("cls");
                if(prisonrank == 1)//RANK TO STRING START
                {
                    wprisonrank = "C-Rank";
                }
                else if(prisonrank == 2)
                {
                    wprisonrank = "B-Rank";
                }
                else if(prisonrank == 3)
                {
                    wprisonrank = "A-Rank";
                }// RANK TO STRING END
                cout << "_____________________[Prison Ranks]_____________________" << endl;
                cout << "C-Rank Costs " << crankcost << " Stamps (Unlocks Set Location & The Gym)" << endl;
                cout << "B-Rank Costs " << brankcost << " Stamps (Unlocks The Courtyard)" << endl;
                cout << "A-Rank Costs " << arankcost << " Stamps (Unlocks The Cafeteria)" << endl << endl;
                cout << "__________[Prison Rankup]_________ | ________[Player Info]_________" << endl;
                cout << "1. Upgrade to your Next Rank       | Balance: " << stamps << " Stamps" << endl;
                cout << "0. Go Back to the Main Menu        | Prison Status: " << wprisonrank << endl << endl;
                if(!cin.good())
                {
                    cin.clear();
                    cin.ignore(128, '\n');
                    cout << "Error! Invalid Entry!\n" << endl;
                }
                if(notenoughmoney == true)
                {
                    cout << "Insufficient Funds to Rankup!\n" << endl;
                    notenoughmoney = false;
                }
                if(success == true)
                {
                    cout << "You have Successfully upgraded to " << wprisonrank << endl << endl;
                    success = false;
                }
                cout << "What would you like to do?" << endl;
                cin >> rankchoice;
                if(rankchoice == 1)
                {
                    if(prisonrank == 0)
                    {
                        if(stamps >= crankcost)
                        {
                            stamps = stamps - crankcost;
                            prisonrank = 1;
                            success = true;
                        }
                        else
                        {
                            notenoughmoney = true;
                        }
                    }
                    else if(prisonrank == 1)
                    {
                        if(stamps >= brankcost)
                        {
                            stamps = stamps - brankcost;
                            prisonrank = 2;
                            success = true;
                        }
                        else
                        {
                            notenoughmoney = true;
                        }
                    }
                    else if(prisonrank == 2)
                    {
                        if(stamps >= arankcost)
                        {
                            stamps = stamps - arankcost;
                            prisonrank = 3;
                            success = true;
                        }
                        else
                        {
                            notenoughmoney = true;
                        }
                    }
                }
            }while(rankchoice != 0 || !cin.good());
        }// PRISON RANK UP END
        else if(mainmenuChoice == 6) // SET LOCATION START
        {
            if(prisonrank == 0)
            {
                system("cls");
                long startTime = time(0);
                cout << "Access Denied: Insufficient Prison Rank" << endl;
                cout << "\nReturning to the Main Menu in 3 seconds.\n" << endl;
                while(time(0) <= startTime + 1)
                {
                }
                cout << "3! ";
                while(time(0) <= startTime + 2)
                {
                }
                cout << "2! ";
                while(time(0) <= startTime + 3)
                {
                }
                cout << "1!" << endl;
                while(time(0) <= startTime + 4)
                {
                }
            }
            else if(prisonrank >= 1)
            {
                do
                {
                    system("cls");
                    cout << "__________[Location Choices]__________ | __________[Information]__________" << endl;
                    cout << "1. Set Location to My Prison Cell      | Cost: Free" << endl;
                    cout << "2. Set Location to the Gym             | Cost: " << gymcost <<" Stamps/Day" << endl;
                    cout << "3. Set Location to the Courtyard       | Cost: " << courtcost << " Stamps/Day" << endl;
                    cout << "4. Set Location to the Cafeteria       | Cost: " << cafetcost << " Stamps/Day" << endl;
                    cout << "0. Return to the Main Menu             | Prison Status: " << wprisonrank << endl;
                    cout << "                                       | Balance: " << stamps << " Stamps" << endl;
                    if(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(128, '\n');
                        cout << "Error! Invalid Entry!\n" << endl;
                    }
                    if(success == true)
                    {
                        cout << "Successfully set location to " << wlocation << endl << endl;
                        success = false;
                    }
                    if(toolow == true)
                    {
                        cout << "Access Denied:" << endl;
                        cout << "You need a Higher Prison Rank to unlock this location.\n" << endl;
                        toolow = false;
                    }
                    cout << "What would you like to do?" << endl;
                    cin >> locationChoice;

                    if(locationChoice == 1)
                    {
                        location = 0;
                        wlocation = "My Prison Cell";
                        success = true;
                    }
                    else if(locationChoice == 2)
                    {
                        location = 1;
                        wlocation = "The Gym";
                        success = true;
                    }
                    else if(locationChoice == 3)
                    {
                        if(prisonrank < 2)
                        {
                            toolow = true;
                        }
                        else if(prisonrank >= 2)
                        {
                            location = 2;
                            wlocation = "The Courtyard";
                            success = true;
                        }
                    }
                    else if (locationChoice == 4)
                    {
                        if(prisonrank < 3)
                        {
                            toolow = true;
                        }
                        else if (prisonrank == 3)
                        {
                            location = 3;
                            wlocation = "The Cafeteria";
                            success = true;
                        }
                    }

               }while(locationChoice != 0 || !cin.good());
            }

        }// SET LOCATION
        else if(mainmenuChoice == 7)
        {
            if(prisonrank < 3)
            {
                system("cls");
                long startTime = time(0);
                cout << "Access Denied: Insufficient Prison Rank" << endl;
                cout << "\nReturning to the Main Menu in 3 seconds.\n" << endl;
                while(time(0) <= startTime + 1)
                {
                }
                cout << "3! ";
                while(time(0) <= startTime + 2)
                {
                }
                cout << "2! ";
                while(time(0) <= startTime + 3)
                {
                }
                cout << "1!" << endl;
                while(time(0) <= startTime + 4)
                {
                }
            }
            else if(prisonrank == 3)
            {
                do
                {
                    system("cls");
                    cout << "____________[Prison Escape System]____________ | ________[Player Info]________" << endl;
                    cout << "1. Pay 100k Stamps for a 25% Chance to Escape  | Username: " << username << endl;
                    cout << "2. Pay 300k Stamps for a 50% Chance to Escape  | Balance: " << stamps << " Stamps" << endl;
                    cout << "0. Go Back to the Main Menu                    |" << endl << endl;
                    if(!cin.good())
                    {
                        cin.clear();
                        cin.ignore(128, '\n');
                        cout << "Error! Invalid Entry!\n" << endl;
                    }
                    if(notenoughmoney == true)
                    {
                        cout << "Insufficient Funds!\n" << endl;
                        notenoughmoney = false;
                    }
                    cout << "What would you like to do?" << endl;
                    cin >> escapeChoice;
                    if(escapeChoice == 1)
                    {
                        if(stamps < escapecost1)
                        {
                            notenoughmoney = true;
                        }
                        else if(stamps >= escapecost1)
                        {
                            stamps = stamps - escapecost1;
                            escapedraw = rand()%100+1;
                            if(escapedraw <= 25)
                            {
                                escapeattempts++;
                                escapesuccess = true;
                                escapeChoice = 0;
                                mainmenuChoice = 0;
                            }
                            else
                            {
                                system("cls");
                                escapeattempts++;
                                day = day + 10;
                                reputation = reputation - 100;
                                cout << "Warden Chow caught you in your Attempt to Escape!\n" << endl;
                                cout << "You spent 10 days in Solitary Confinement.\n" << endl;
                                cout << "Your reputation dropped by 100.\n" << endl;
                                if(stamps >= 10000)
                                {
                                    stamps = stamps - 10000;
                                    cout << "10000 Stamps were confiscated from you." << endl;
                                }
                                cout << endl;
                                system("pause");
                            }
                        }
                    }
                    else if (escapeChoice == 2)
                    {
                        if(stamps < escapecost2)
                        {
                            notenoughmoney = true;
                        }
                        else if(stamps >= escapecost2)
                        {
                            stamps = stamps - escapecost1;
                            escapedraw = rand()%99+1;
                            if(escapedraw <= 50)
                            {
                                escapeattempts++;
                                escapesuccess = true;
                                escapeChoice = 0;
                                mainmenuChoice = 0;
                            }
                            else
                            {
                                system("cls");
                                escapeattempts++;
                                day = day + 10;
                                reputation = reputation - 100;
                                cout << "Warden Chow caught you in your Attempt to Escape!\n" << endl;
                                cout << "You spent 10 days in Solitary Confinement.\n" << endl;
                                cout << "Your reputation dropped by 100.\n" << endl;
                                if(stamps >= 10000)
                                {
                                    stamps = stamps - 10000;
                                    cout << "10000 Stamps were confiscated from you." << endl;
                                }
                                cout << endl;
                                system("pause");
                            }
                        }
                    }
                }while(escapeChoice != 0 || !cin.good());
            }
        }
    }while(mainmenuChoice != 0 || !cin.good()); // END MAIN GAME LOOP
    system("cls");
    if(escapesuccess == true)
    {
        cout << "CONGRATULATIONS! You have SUCCESSFULLY ESCAPED \nfrom the Iron Fist Maximum Security Prison!" << endl << endl;
        cout << "__________[Player Statistics]__________" << endl;
        cout << "Username: " << username << endl;
        cout << "Days Taken: " << day << endl;
        cout << "Escape Attempts: " << escapeattempts << endl;
        cout << "Total Earnings: " << totalearnings << " Stamps" << endl;
        cout << "Customers Served: " << totalcustomers << endl;
        cout << "\nThank you guys so much for playing! \n~ Harry Chen January 2016" << endl;
        cin >> invquit;
    }
    return 0;
}
