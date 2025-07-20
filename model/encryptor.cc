#include "encryptor.h"
#include <iostream>


Encryptor::Encryptor(const std::string& key, const std::string& iv)
    : aesKey((const byte*)key.data(), key.size()),
      aesIV((const byte*)iv.data(), iv.size()),
      hmacKey((const byte*)key.data(), key.size()) {}

std::vector<unsigned char> Encryptor::Encrypt(const std::string& plaintext) {
    std::string ciphertext;
    CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(aesKey, aesKey.size(), aesIV);
    
    CryptoPP::StringSource(plaintext, true,
        new CryptoPP::StreamTransformationFilter(encryptor,
            new CryptoPP::StringSink(ciphertext)));
    
    return std::vector<unsigned char>(ciphertext.begin(), ciphertext.end());
}

std::string Encryptor::Decrypt(const std::vector<unsigned char>& ciphertext) {
    std::string plaintext;
    CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(aesKey, aesKey.size(), aesIV);
    
    CryptoPP::StringSource(std::string(ciphertext.begin(), ciphertext.end()), true,
        new CryptoPP::StreamTransformationFilter(decryptor,
            new CryptoPP::StringSink(plaintext)));
    
    return plaintext;
}

std::string Encryptor::GenerateHMAC(const std::string& data) {
    std::string mac;
    CryptoPP::HMAC<CryptoPP::SHA256> hmac(hmacKey, hmacKey.size());
    
    CryptoPP::StringSource(data, true, 
        new CryptoPP::HashFilter(hmac, 
            new CryptoPP::StringSink(mac)));
    return mac;
}

bool Encryptor::VerifyHMAC(const std::string& data, const std::string& receivedHMAC) {
    return GenerateHMAC(data) == receivedHMAC;
}
/*
int main() {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string iv = "abcdef9876543210";
    Encryptor encryptor(key, iv);

    std::string message = "Test encryption message";
    std::vector<unsigned char> encrypted = encryptor.Encrypt(message);
    std::string decrypted = encryptor.Decrypt(encrypted);
    std::string hmac = encryptor.GenerateHMAC(message);
    bool isHMACValid = encryptor.VerifyHMAC(message, hmac);

    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Decrypted Message: " << decrypted << std::endl;
    std::cout << "HMAC: " << hmac << std::endl;
    std::cout << "HMAC Verification: " << (isHMACValid ? "Valid" : "Invalid") << std::endl;
    return 0;
}*/
