# Crypotgraphy Implementation - AES
Implementation of Advanced Encryption Standard (AES) with CBC and OFB modes of operations.

## Compilation 
Makefile is provided to compile the project. Executing the `make` command will make an `AES` executable. <br/>
The `AES` executable can be deleted, along witht the .o files that result from compilation, with the `make clean` command.<br />

## Parameters
To incorporate encryption/decryption, modes of operations and AES-variant based on key-size, various features are provided through below cmds. The executable `AES` should be properly parameterized for succeccful execution.

* `-e/encrypt`: This must be first parameter used alongside AES. It determines a file will be encrypted. Do not use  `-d/decrypt`.
* `-d/decrypt`: This must be first parameter used alongside AES. It determines a file will be decrypted. Do not use  `-e/encrypt`.
* `-ofb`: It determines the encryption/decryption will be performed with OFB mode of operation.
* `-cbc`: It determines the encryption/decryption will be performed with CBC mode of operation.
* `[-p/path filePah]`: It specifies the path of the file that will be encrypted/decrypted.
* `[-aes aesPath]`: It specifies the path of the key used for AES.
* `[-mac macPath]`: It specifies the path of the key used for MAC.
* `[-b/bits length]`: It specifies the length for new AES and MAC key. Both keys are always the same length. Valid lengths ares: 128, 192, and 256.
* `-h/help`: Displays assistance with execution parameters.

## Execution
`AES` will execute in different ways according to the parameters given. In general, there are three possible ways to execute it and all of them require a specified path for the file that will be encrypted/decrypted (`-p/-path`) along with the mode of operation (`-ofb` or `-cbc`)
1. No specific `-aes` and `-mac` keys path were given. Therefore, `AES` will use keys stored by default in the hidden `~/.crypto` directory. This direcoty may 
contain keys of different sizes so the parameter `-b/bits` is required. This is the most simple way to execute `AES` and both encryption and decryption are
possible.<br />
Example,
```
./AES -e -p TheOne.jpeg -ofb -b 128
./AES -d -p TheOne.jpeg -ofb -b 128
```
2. `AES` will generate new keys, both `-aes` and `-mac`, if none are provided when encrypting a file. If you would like to store them on a different place than 
the hidden `~/.crypto` directory, you are able to provide a specified path (specifying fileName for new keys) where the keys will be stored. This allows you to 
store keys, for example, in a USB drive which you could hide. The required parameters are the followings.<br />
Example,
```
./AES -e -p TheOne.jpeg -cbc -b 192 -aes /Volumes/USB/aesKey-192.aes -mac /Volumes/USB/macKey-192.aes 
```

3. Once you have 128, 192, or 256 bits keys in a specified path you could use them to encrypt/decrypt other files. It is similar to the previous to the command, 
but since the key already exits its length does not need to be stated.<br />
Example,
```
./AES -e -p TheOne.jpeg -ofb -aes /Volumes/USB/aesKey-192.aes -mac /Volumes/USB/macKey-192.aes 
```
