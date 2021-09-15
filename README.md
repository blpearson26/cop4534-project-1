# cop4534-project-1

The Project
----------------

The goal of this project is to create an efficient storage and lookup scheme for userids and passwords utilizing an externally chained hash table. Programming will be object-oriented using C++. The assignment has two parts. 

Part 1, Creating encrypted passwords.
---------------------------------------

We will use the names in "names.txt," located with this project description, as userids. You will only need the data in the first column of the file. You will first generate random passwords for each userid and write them with the corresponding userid to a raw file, one userid, password combination per line. This file should be named "rawdata.txt." Note that we DO NOT want sequential passwords such as a1, a2, a3, a4, etc. Passwords should be 9 characters, comprised of random combinations of lower-case letters (admittedly crummy, but simpler for our purposes). Userids are unique, passwords do NOT need to be unique. Next, you will read the unencrypted file, encrypt the passwords, and write this file back to a disk file named "encrypteddata.txt." We will use the Vigenere Cipher to create encrypted passwords: 

Use jones as the key:a b c d e f g h i j k l m n o p q r s t u v w x y z| | | | | | | | | | | | | | | | | | | | | | | | | |j k l m n o p q r s t u v w x y z a b c d e f g h ia b c d e f g h i j k l m n o p q r s t u v w x y z| | | | | | | | | | | | | | | | | | | | | | | | | |o p q r s t u v w x y z a b c d e f g h i j k l m na b c d e f g h i j k l m n o p q r s t u v w x y z| | | | | | | | | | | | | | | | | | | | | | | | | |n o p q r s t u v w x y z a b c d e f g h i j k l ma b c d e f g h i j k l m n o p q r s t u v w x y z| | | | | | | | | | | | | | | | | | | | | | | | | |e f g h i j k l m n o p q r s t u v w x y za b c d a b c d e f g h i j k l m n o p q r s t u v w x y z| | | | | | | | | | | | | | | | | | | | | | | | | |s t u v w x y za b c d e f g h i j k l m n o p q r

You would then encode data :  moge The Vigenere Cipher is a simple cypher that solves the problem of using frequency analysis to defeat a basic encryption scheme. In this method, you first choose a key that you use to make a mapping of real letter to cypher by adjusting the alphabet according to the key: 

Part 2. Testing userid/password combinations
----------------------------------------------

Now we get to the hashing part. You will build an externally chained hash table of userids and passwords. You will process "encrypteddata.txt" to create the hash table by hashing on userid. At that appropriate location, you will store the unencrypted userid and encrypted password. Recall that an externally chained hash table is pretty easy to implement as simply a collection of linked lists:
