from Crypto.Cipher import AES
from binascii import unhexlify, hexlify

key = unhexlify(b'2b7e151628aed2a6abf7158809cf4f3c')
plaintext = unhexlify(b'6bc1bee22e409f96e93d7e117393172a')
print("\nPlain text: ")
print(str(hexlify(plaintext)))

mode = AES.MODE_ECB
encryptor = AES.new(key, mode)

encryptedtext = encryptor.encrypt(plaintext)
print("\nEncrypted: ")
print(str(hexlify(encryptedtext)))

decryptedtext = encryptor.decrypt(encryptedtext)
print("\nDecrypted: ")
print(str(hexlify(decryptedtext)))
