#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
//#include "dutils.h"
/*      Dashier daemon
        By XePeleato
        To be run on a Raspberry 3b      */
       
//Configuration EDIT THIS!
static const char NETWORK[] = "testnet";     // "testnet/mainnet"
static const char WALLET_TYPE[] = "LOCAL";               // LOCAL/REMOTE
    //IF REMOTE
static const char RPCHOST[] = "127.0.0.1";
static const char RPCUSER[] = "user";
static const char RPCPASS[] = "pass";
static const int  RPCPORT = 7777;
static const char EMAILADDR[] = "";            // If anything goes wrong...
static const bool WALLET_KEY = false;           // false = No key,  true = Key. For security reasons, it must be introduced manually
static const int BALANCE_TRESHOLD = 10;     // If your wallet keeps less than X, it stops the ATM

