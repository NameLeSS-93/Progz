#include<iostream>
#include<ctime>
#include"stdlib.h"
using namespace std;

int main(){
    
    const int iFieldWidth(20), iFieldHeight(10);
    const char chLiveCell('#'), chDeadCell('.');

    int iGenerations(5);

    bool bCellArray[iFieldHeight*iFieldWidth] = {false};
    bool bTempCellArray[iFieldHeight*iFieldWidth] = {false};
    srand(time(NULL));

    for(int y = 0; y < iFieldHeight; y++)
    {
        for(int x = 0; x < iFieldWidth; x++)
        {
            if(bCellArray[x + y * iFieldWidth])
            {
                cout << chLiveCell;
            } 
            else
            {
                cout << chDeadCell;
            }
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
    short shRandNumber = rand();

    for(int y = 0; y < iFieldHeight; y++)
    {
        for(int x = 0; x < iFieldWidth; x++)
        {
            bCellArray[x + y * iFieldWidth] = rand() % 2;
            if(bCellArray[x + y * iFieldWidth])
            {
                cout << chLiveCell;
            } else {
                cout << chDeadCell;
            }
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
    for(int g = 0; g < iGenerations; g++)
    {
        for(int y = 0; y < iFieldHeight; y++)
        {
            for(int x = 0, iCellCounter = 0; x < iFieldWidth; x++)
            {
                if(((x - 1) >= 0) && ((y - 1) >= 0))
                {
                    if(bCellArray[(x-1) + (y-1) * iFieldWidth]) iCellCounter++;
                }
                if((y - 1) >= 0)
                {
                    if(bCellArray[x + (y - 1) * iFieldWidth]) iCellCounter++;
                }
                if(((x+1) <= iFieldWidth) && (y - 1) >= 0)
                {
                    if(bCellArray[(x + 1) + (y - 1) * iFieldWidth]) iCellCounter++;
                }
                if(((x - 1) >= 0))
                {
                    if(bCellArray[(x - 1) + (y) * iFieldWidth]) iCellCounter++;
                }
                if(((x + 1) <= iFieldWidth))
                {
                    if(bCellArray[(x + 1) + (y) * iFieldWidth]) iCellCounter++;
                }
                if(((x - 1) >= 0 && (y + 1) <= iFieldHeight))
                {
                    if(bCellArray[(x - 1) + (y + 1) * iFieldWidth]) iCellCounter++;
                }
                if((y + 1) <= iFieldHeight)
                {
                    if(bCellArray[x + (y + 1) * iFieldWidth]) iCellCounter++;
                }
                if(((x + 1) <= iFieldWidth) && ((y + 1) <= iFieldHeight))
                {
                    if(bCellArray[(x + 1) + (y + 1) * iFieldWidth]) iCellCounter++;
                }


                if((iCellCounter < 2 ) || (iCellCounter > 3))
                {
                    bTempCellArray[x + y * iFieldWidth] = false;
                    cout << chDeadCell;
                } 
                else
                {
                    if((!bCellArray[x + y * iFieldWidth] && iCellCounter != 3))
                    {
                        bTempCellArray[x + y * iFieldWidth] = false;
                        cout << chDeadCell;
                    } 
                    else 
                    { 
                        bTempCellArray[x + y * iFieldWidth] = true;
                        cout << chLiveCell;
                    }
                }
                iCellCounter = 0;
            } // горизонтальные поля
            cout << '\n';
        } // вертикальные поля
        cout << '\n';
        cout << '\n';
        for(int i = 0; i < iFieldHeight * iFieldHeight; i++)
        {
            bCellArray[i] = bTempCellArray[i];
        }
    }
    return 0;
}