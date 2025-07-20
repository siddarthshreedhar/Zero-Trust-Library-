

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <ns3/core-module.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/eccrypto.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/oids.h>
#include <cryptopp/asn.h>
#include <string>

class Authenticator {
public:
    Authenticator();
    ~Authenticator();
    
    void GenerateKeys();
    std::string SignMessage(const std::string &message);
    bool VerifySignature(const std::string &message, const std::string &signature);
    std::string GetPublicKey();

private:
    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PrivateKey privateKey;
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PublicKey publicKey;
};

#endif
