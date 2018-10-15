// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x4c;
        pchMessageStart[1] = 0x17;
        pchMessageStart[2] = 0xfe;
        pchMessageStart[3] = 0xe9;
        vAlertPubKey = ParseHex("046bcf8279df0f85f79b0bce7693011f45955bfd5645b1fd109cb300d4dc3f47e8d0495808a73b31965a910fdf9a0ddef1c663788d08ea0d828a963a6e2ac9401e");
        nDefaultPort = 32390;
        nRPCPort = 32391;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
       

        const char* pszTimestamp = "06/03/2018 Pawcoin Masternodes";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char *)pszTimestamp, (const unsigned char *)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1520363196, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1520363196;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 2084745091;

        hashGenesisBlock = genesis.GetHash();


        assert(hashGenesisBlock == uint256("0x00000db25ffc0da6d4894dd1f597126a1c1b07de9f878cac4043ceb8fe9e0def"));
        assert(genesis.hashMerkleRoot == uint256("0x3b4541236757005b3f543e502d34e325636e11244293b3dcd6e3c2c2e8377ac2"));

        vSeeds.push_back(CDNSSeedData("n0", "107.172.205.232"));
        vSeeds.push_back(CDNSSeedData("n1", "23.95.214.48"));
        vSeeds.push_back(CDNSSeedData("n2", "193.37.152.99"));
        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,55);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,85);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,153);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 1000;
    }

    virtual const CBlock &GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress> &FixedSeeds() const
    {
        return vFixedSeeds;
    }

  protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;

//
// Testnet
//

class CTestNetParams : public CMainParams
{
  public:
    CTestNetParams()
    {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x4c;
        pchMessageStart[1] = 0x17;
        pchMessageStart[2] = 0xfe;
        pchMessageStart[3] = 0xe9;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("");
        nDefaultPort = 31979;
        nRPCPort = 21979;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
       genesis.nTime    = 1520363196;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 2084745091;

       // assert(hashGenesisBlock == uint256("0x00000db25ffc0da6d4894dd1f597126a1c1b07de9f878cac4043ceb8fe9e0def"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,55);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,192);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 20;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params()
{
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network)
{
    switch (network)
    {
    case CChainParams::MAIN:
        pCurrentParams = &mainParams;
        break;
    case CChainParams::TESTNET:
        pCurrentParams = &testNetParams;
        break;
    default:
        assert(false && "Unimplemented network");
        return;
    }
}

bool SelectParamsFromCommandLine()
{

    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet)
    {
        SelectParams(CChainParams::TESTNET);
    }
    else
    {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
