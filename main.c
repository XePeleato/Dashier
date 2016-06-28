#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "dutils.h"
#include "config.h"
/*      Dashier daemon
        By XePeleato
        To be run on a Raspberry 3b      */

int main(int argc, char *argv[]) {
    if(strcmp(WALLET_TYPE, "LOCAL") == 0)
        StartDash(NETWORK);
        //TODO: Check PID
        printf("\nThe Dash deamon started succesfully!");
    printf("\nChecking if the blockchain is downloaded...");
    CheckBChain(NETWORK);
        printf("\nChecking balance...");
        FILE *dashcli = popen("dash-cli getbalance", "r");
        char Balance[15];
        fgets(Balance, sizeof(Balance), dashcli);
    fclose(dashcli);
        if(atof(Balance) < BALANCE_TRESHOLD)
        {
            int BNeeded = BALANCE_TRESHOLD - atof(Balance);
            printf("\n[ERROR] Your wallet is out of Dash, send %i DASH in order to continue", BNeeded);
            return 0;
        }
        printf("\nYou actually have %.3f DASH, seems ok", atof(Balance));
    //At this point the cashier is ready, since the blockchain is loaded and there's some dash.
   
   
   
    return 0;
}
