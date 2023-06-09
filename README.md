# iCipher, a C++ application for encrypting sentences with some re-imaginings of popular algorithms

![GitHub repo size](https://img.shields.io/github/repo-size/lamferzon/iCipher?logo=c%2B%2B)
![Lines of code](https://img.shields.io/tokei/lines/github/lamferzon/iCipher?color=yellow)
![GitHub repo file count](https://img.shields.io/github/directory-file-count/lamferzon/iCipher?color=gree)
![GitHub](https://img.shields.io/github/license/lamferzon/iCipher?color=red)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/lamferzon/iCipher?color=lightblue)


## Author ##
+ **Lorenzo LEONI**, postgraduate in Computer Engineering at University of Bergamo.

## Description ##
Is there a way to complicate and to make less vulnerable some of the most popular monoalphabetic substitution ciphers like Caesar and Vigenère? The aim of *iCipher* is this, i.e. providing to users a C++ application through which they can encrypt and decrypt sentences by using more complex algorithms deriving from the ones mentioned above.

## Main features ##
Through a command line interface, users can access two services thanks to *iCipher*
+ **encryption** and **decryption** of character sequences using the Caesar cipher, its modified version, the Vigenère algorithm or the Leoni cipher, a technique that repeats *n* times the previous ones;
+ **storage** in a CSV file of the encrypted versions of the words that have been entered into the application. For each of them the parameters of the cipher used are also specified.

*iCipher* works completely offline, therefore there is no risk of spreading your sensitive data on the Internet.

## UML Class Diagrams ##
- [x] UML Class Diagram of the header file *encryptors.h*.

![Image 1](documentazione/UML/UML_1.jpg)

- [x] UML Class Diagram of the header files *application.h* and *consts.h*.

![Image 1](documentazione/UML/UML_2.jpg)


