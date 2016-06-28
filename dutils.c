#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "config.h"
 
 
 
 
 
void StartDash(const char *NET)
{
    printf("\nOpening dashd on %s chain.", NET);
    if(strcmp(WALLET_TYPE, "LOCAL") == 0)
    {
            char opencmd[16];          
            sprintf(opencmd,"dashd -%s", NET);
            FILE *dashqt = popen(opencmd, "r");
        if(WALLET_KEY == true)
                {
                     printf("\nYour wallet is encrypted, you need to enter the key via dash-cli!");
                     //Or ask for the key here
            }
    }
    if(strcmp(WALLET_TYPE, "REMOTE") == 0)
    {
        //The wallet is already opened (at the remote server)
        //
       
    }
 
}
 
int CheckBChain(const char *NET)
{
    char actualBlock[10];
    char localBlock[10];
    if(strcmp(NET, "testnet") == 0)
    {
        printf("\nChecking against testnet blockchain...");
        FILE *wget = popen("wget -q -O - https://test.explorer.dash.org/chain/tDash/q/getblockcount", "r");
        fgets(actualBlock, sizeof(actualBlock), wget);
        pclose(wget);
    }
    if(strcmp(NET, "mainnet") == 0)
    {
        printf("\nChecking against mainnet blockchain...");
        FILE *wget = popen("wget -q -O - https://explorer.dash.org/chain/Dash/q/getblockcount", "r");
        fgets(actualBlock, sizeof(actualBlock), wget);
        pclose(wget);
    }
    char cmdchk[258];
    sprintf(cmdchk, "dash-cli -rpcconnect=%s -rpcport=%i -rpcuser=%s -rpcpassword=%s getblockcount", RPCHOST, RPCPORT, RPCUSER, RPCPASS);
    FILE *chkblk = popen(cmdchk , "r");
    fgets(localBlock, sizeof(localBlock), chkblk);
    pclose(chkblk);
    if(atoi(actualBlock) == atoi(localBlock))
    {
        printf("\nThe last block matches! %s - %s", actualBlock, localBlock);
    }
    else
    {
        printf("\n Blockchain Sync error! Local: %s Remote: %s", localBlock, actualBlock);
        exit(1);
    }
 
 
}
