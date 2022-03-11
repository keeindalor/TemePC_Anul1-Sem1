GATES.C
TASK1.1: 
-pentru functia get_bit, am shiftat numarul n la dreapta cu i pozitii, dupa care am facut "si" exclusiv pe biti
pentru a avea pe pozitia 0 a numarului res bitul i din nr, care poate fi 0 sau 1
-pentru functia flip_bit, am utilizat XOR intre numarul dat in functie, si valoarea lui 1 shiftata la dreapta cu i pozitii, astfel incat 
in urma operatiei XOR  sa isi schimbe valoarea. mai exact, daca bitul pe care doream sa il schimbam era 1, in urma xor-ului acesta devenea
0, pentru ca in xor, doua valori egale rezulta o valoare nula, iau daca bitul era 0, devenea 1, deoarece comparam in xor cu un bit 1
-pentru functia activate_bit, m-am folosit de functia get_bit pentru a selecta bitul i, si apoi de functia flip bit pentru a-l face 1
-analog clear_bit

TASK1.2
-am urmat diagramele pentru porti

TASK1.3
-full_adder-ul realizeaza, de fapt, suma dintre 3 biti: a, b si unul carry-in. pentru a realiza aceasta suma
am folosit doua variabile, sum si carry (care este un carry-out), definite prin portile de la task 1.2
apoi, in cazul in care suma era egala cu 0 , schimbam bitul de pe pozitia 1 din res, iar in cazul in care 
carry era 0, schimbam bitul de pe pozitia 0 in res, mai exact, pentru a memora in aceasta variabila res 
suma si bit-ul de transport carry
-ripple_carry_adder este suma pe biti dintre doua valori, a si b, care are ca rezultat fie o valoare fara 
overflow, fie una cu overflow. acest overflow se intampla in cazul in care adunam pe ultimele pozitii ale 
bitilor 1 si 1, rezultand 0 overflow 1, iar ideea acestui ripple_carry este de a returna la final sum si 
carry pentru a indica daca se intampla overflow sau nu

COMMUNICATION.C
TASK2.1:
-prin funcia send_byte, trebuia sa trimitem codat, utilizand send_squanch, literele R, I, C, K. ideea de
codare era sa adaugam la aceste litere " -'A' + 1", pentru a respecta codarea oferita pe ocw.cs
-prin functia recv_byte, primeam un mesaj codat, litera cu litera, prin functia recv_squanch. am adau
gat aceste litere intr-un vector de char-uri, si apoi le-am decodat, folosind inversul codarii
adica " +'A' - 1"
-functia comm_byte primeste 10 caractere, si le trimite inapoi de doua ori.

TASK2.2:
-functia send_message trebuie sa trimita lungimea si fiecare caracter codat. astfel lungimea se codeaza
prin shiftarea la dreapta a 4 pozitii si shiftarea la stanga a 2 pozitii, pentru a fi cei 4 biti in mijloc
o trimitem folosind functia send_squanch
apoi parcurgem toate caracterele ale mesajului si le trimitem codate
-functia recv_message primeste lungimea codata, o decodam folosind acelasi principiu, apoi primeste cate un
caracter codat pe care il decodam, printand la final lungimea si mesajul decodate
-functia comm_message primeste lungimea codata, o decodam, apoi primeste cate un caracter codat pe care il
decodam. in functie de ultimul caracter din mesaj, noi trimitem o lungime codata si un cate un caracter 
codat pana la lungimea respectiva, mai exact trimitem lungimea si mesajul codat ale lui PICKLERICK sau
VINDICATORS

task 2.3:
-functia send_squanch2 trebuie sa trimita un cod format din 2 jumatati de octet. m-am folosit de functia
get_bit de la gates.c, si am extras bitii respectivi, dupa care i-am shiftat dupa formula i*2 sau i*2+1
- analog funtia decode_squanch2.

HUNT.C
TASK 3.1:
-pentru functia spell, am parcurs toti bitii lui memory, pentru a gasi acea grupare de 5. cand am gasit-o,
am memorat pozitia si am oprit structura repetitiva.
apoi, de la bitul urmator pozitiei, pana la urmatorii 16, am selectat bitul i, dupa care am shiftat acel bit
cu o pozitie j, pentru a putea construi spell-ul format din 16 biti care se afla in memory.
-analog functia key, am folosit acelasi principiu
-functia decrypt_spell foloseste ecuatia data, al carei rezultat l-am returnat

TASK 3.2:
-aici, a trebuit sa construim o sabie. primii 16 biti ii constituiau ecuatia lui Value, urmatorii 12
erau nesemnificativi, iar ultimii 4 erau dati ori de valoarea 6, ori de valoarea 9
valoarea 6 era data tipului om, iar 9 pentru monstru, iar aceste valori le-am shiftat la stanga cu 28 
de pozitii pentru a putea fi adaugate in sabia finala. cum value se afla pe primii 16 biti, iar dupa shiftare
tipul se afla pe ultimii biti, putem adauga cele doua valori (value si tip) intr-o sabie.
am parcurs bitii lui enemy pentru a afla cate valori de 1 avem, iar daca era un numar par, aveam nevoie de
o sabie anti monstri, altfel anti oameni.

TASK 3.3:
-pentru grasses, am luat ecuatiile respective pe foaie, ajungand la concluzia ca antibodies_high = cocktail
in final, returnand antibodies shiftat cu 16, pentru ca eu le-am declarat in 32 de biti, el fiind pe 16, 
si neavand nevoie de anumite valori de 0
-
-pentru distanta, am parcurs cei 32 de biti ale hartii, memorand pozitia 1 si pozitia 2 unde se afla acele
doua valori de 1. dupa care am calculat distanta ca fiind poz2-poz1, si am returnat-o