#include "authenticator.h"
#include <iostream>

Authenticator::Authenticator() {
    GenerateKeys();
}

Authenticator::~Authenticator() {}

void Authenticator::GenerateKeys() {
    privateKey.Initialize(prng, CryptoPP::ASN1::secp256r1());
    privateKey.MakePublicKey(publicKey);
}

std::string Authenticator::SignMessage(const std::string& message) {
    std::string signature;
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::Signer signer(privateKey);
    CryptoPP::StringSource ss(message, true,
        new CryptoPP::SignerFilter(prng, signer,
            new CryptoPP::StringSink(signature)
        )
    );
    return signature;
}

bool Authenticator::VerifySignature(const std::string& message, const std::string& signature) {
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::Verifier verifier(publicKey);
    return verifier.VerifyMessage(
        reinterpret_cast<const CryptoPP::byte*>(message.data()), message.size(),
        reinterpret_cast<const CryptoPP::byte*>(signature.data()), signature.size()
    );
}


std::string Authenticator::GetPublicKey() {
    std::string pubKey;
    CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(pubKey));
    publicKey.Save(encoder);
    return pubKey;
}
/*
int main() {
    Authenticator auth;
    
    std::string message = "Test message";
    std::string signature = auth.SignMessage(message);
    
    bool isValid = auth.VerifySignature(message, signature);
    std::string publicKey = auth.GetPublicKey();

    std::cout << "Message: " << message << std::endl;
    std::cout << "Signature verification: " << (isValid ? "Valid" : "Invalid") << std::endl;
    std::cout << "Public Key: " << publicKey << std::endl;

    return 0;
}
*/
