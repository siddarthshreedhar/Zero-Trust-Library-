#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <cryptopp/cryptlib.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
#include <cryptopp/hmac.h>
#include <cryptopp/hex.h>
#include <string>
#include <vector>

using namespace CryptoPP;

class Encryptor {
public:
    Encryptor(const std::string& key, const std::string& iv);
    std::vector<unsigned char> Encrypt(const std::string& plaintext);
    std::string Decrypt(const std::vector<unsigned char>& ciphertext);
    std::string GenerateHMAC(const std::string& data);
    bool VerifyHMAC(const std::string& data, const std::string& receivedHMAC);

private:
    SecByteBlock aesKey;
    SecByteBlock aesIV;
    SecByteBlock hmacKey;
};

#endif 

