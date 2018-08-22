<b>PawCoin Project:</b>

PawCoin Project arises from the need to help aid associations for abandoned dogs aswell as raise awareness in society about the torture, abuse and neglect that some dogs face every day. sadly some dogs are still being abandoned on streets. We believe, we can and must do something about it!

We have created a crypto currency with the idea of helping as many dogs help organisations as possible utilising Blockchain technology.

Nowadays dog charities struggle to have enough funds to even buy food for dogs, needless to say they need extra funding that doesnt come from public instances. We will give 6% of the premine coins to fund those organisations and rise awareness of them by listing them on our website, you will also be able to fund directly your fauvourite local organisation by sending coins to their wallet.

PawCoin Specs:

    Algorithm:                        POS + MASTERNODE
    Ticker:                           PWC
    Block time:                       120 seconds
    Max Supply:                       43 298 969 PWCs
    Transaction confirmation:         15 blocks
    Mining maturation time:           20 blocks
    P2P Port:                         33128
    RPC Port:                         33127
    Min Stake                         8 hours
    Premine                           3% + 700 000 to SWAP


Premined purposes:

    6 % for donating asociations                    77 938 PWCs
    30 % for develop masternode                    389 690 PWCs
    10 % bounty programs                           129 896 PWCs
    1 % develop block explorer                      12 989 PWCs
    43 % staff                                     558 556 PWCs
    10 % donations for masternode listing          120 989 PWCs
    Swap coins                                     650 000 PWCs


POS Blocks Rewards:

    From block 1 to 18000 : 10 PWCs
    From block 18001 to 35000 : 20 PWCs
    From block 35001 to 75000 : 40 PWCs
    From block 75001 to 100000 : 50 PWCs
    From block 100001 to 145000 : 55 PWCs
    From block 145001 to 200000 : 40 PWCs
    From block 200001 to end : 20 PWCs


Masternode Rewards (75% FROM POS BLOCKS):

    From block 1 to 18000 : 7.5 PWCs
    From block 18001 to 35000 : 15 PWCs
    From block 35001 to 75000 : 30 PWCs
    From block 75001 to 100000 : 37.5 PWCs
    From block 100001 to 145000 : 41.25 PWCs
    From block 145001 to 200000 : 30 PWCs
    From block 200001 to end : 15 PWCs
### How to install

Updating Ubuntu system
```sh
sudo apt-get update
sudo apt-get upgrade
sudo apt-get dist-upgrade
```

Installing new packages
```sh
sudo apt-get install -y build-essential libssl-dev libboost-all-dev git libdb5.3++-dev libminiupnpc-dev screen
```

Creating folder on root structure and give permission
```sh
sudo mkdir /wallets
sudo chmod 777 /wallets
```

Downloading source code
```sh
git clone https://github.com/PawCoin/PawCoinMN.git PawCoin
cd PawCoin
```

Changing permission and compiling LevelDB
```sh
cd ./src/leveldb
chmod +x build_detect_platform
make libleveldb.a libmemenv.a
cd ../..
```

Compiling daemon
```sh
cd ./src
make -f makefile.unix
  or
make -f makefile.unix "USE_UPNP=-" # without support to UPNP
```
