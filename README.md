# PesmaProj
------------
ENG
- *Skup-The set*: consists of an arbitrary number of characters (char). It is created with the default C++ string
(string), whose characters are immediately appended. It is possible to add a character to a set (set+=character), where
adding a character already in the set is ignored, as well as checking if the character is in the
set (set(character)). The set cannot be copied in any way.
- *Reč-A word*: is created with a given C++ string and consists only of letters of the English alphabet.
It is possible to determine the length of the word (+rec), as well as the number of syllables of the word (~rec). The number of syllables in a word
is equal to the number of syllable carriers of the word. A syllable carrier is every vowel in the set {a, e, i, o, u}
or every sonant in the set {l, n, r}, if there is neither a vowel before nor after it (and for
sonante nor sonant before it), and for the letters l and n, even if there is no letter j after them. It is possible to
determine the position of the letter of the nth syllable carrier in the word (rec(n)), where the positions of the letters move
of 0. The value n==0 determines the first syllable at the beginning of the word, positive n values ​​indicate
search from the beginning of the word, and negative n values ​​from the end of the word. In case of unsuccessful search
the return value is -1. Two given words rhyme (rec1^rec2) if they match
corresponding letters of the last two syllables, or of the last syllable if it is one of the words
monosyllabic. The letter matching check is carried out from the carriers of the penultimate syllables in the words,
that is, the carriers of the last syllables, if any of the words is monosyllabic. The word can be loaded
from a single line of input stream (it>>rec), ignoring all non-letter characters
of the English alphabet and the previous content of the word is lost. The word is written to the output stream
(it<<rec) by writing its letters.
- *Stih- A verse*: is a sequence of words of arbitrary length. It is created empty, and after that it is possible to add
individual words at the end of a verse (stih+=rec). It is possible to determine the length of the verse expressed in
to the number of its words (+stih), as well as the number of syllables of the verse expressed in the sum of the syllables of its words
(~ stih). It is possible to retrieve a word from a given position (stih[ind]), delete a word from a given position
positions (stih(ind)) and insert the word before the word at the given position (stih(rec, ind)).
Two given verses rhyme (stih1^stih2) if their last words rhyme. A verse is possible
load from one line of the input stream (it>>stih) by reading a word from that line, where it is lost
previous content of the verse. The verse is written to the output stream (it<<stih) by writing its
words separated by exactly one space character, on one line.
- *Strofa- A strophe*: is a sequence of verses of limited capacity (number of verses), which is given at
to creation and which can be reached. It is created empty, and after that it is possible to add
individual verses at the end of the strophe (strofa+=stih), whereby the operation has no effect in
in case an attempt is made to add a line to a full strophe or a line with a different number of syllables than
verses that are already in the strophe. When adding a verse to a strophe, a copy of the verse is made
which is added. It is possible to remove the last added verse (-strofa), whereby the removal from
empty strophe of operations without effect, as well as determine the length of the strophe expressed in the number of strophe
verses (+strofa). It is possible to retrieve a verse from a given position (strofa[ind]), as well as
replace places with verses from given positions (strofa(i, j)). It is possible to determine whether
the lines of the strophe rhyme (*strofa), as well as the one-letter designation of the type of strophe. The strophe is printed
into the output stream (it<<strofa) by writing its lines in individual lines.
- *Katren- A quatrain*: is a strophe of capacity 4. The verses of the quatrain rhyme, if the number of verses is equal
capacity and if the first verse rhymes with the last, and the second with the penultimate. A symbol of quatrain
is K.
Write a main function that loads several lines from standard input, adds them to quatrain i
print it to standard output.

SRB
- *Skup* se sastoji od proizvoljnog broja znakova (char). Stvara se sa zadatom C++ niskom
(string), čiji se znaci odmah dodaju. Moguće je dodati znak u skup (skup+=znak), pri čemu
se dodavanje znaka koji se već nalazi u skupu ignoriše, kao i ispitati da li se znak nalazi u
skupu (skup(znak)). Skup nije moguće kopirati ni na koji način.
- *Reč* se stvara sa zadatom C++ niskom (string) i sastoji se samo od slova engleskog alfabeta.
Moguće je odrediti dužinu reči (+rec), kao i broj slogova reči (~rec). Broj slogova reči
jednak je broju nosilaca slogova reči. Nosilac sloga je svaki samoglasnik u skupu {a, e, i, o, u}
ili svaki sonant u skupu {l, n, r}, ako se ni ispred ni iza njega ne nalazi samoglasnik (a za
sonante ni sonant ispred njega), a za slova l i n, ni ako se iza njih ne nalazi slovo j. Moguće je
odrediti poziciju slova n-tog nosioca sloga u reči (rec(n)), pri čemu pozicije slova kreću
od 0. Vrednost n==0 određuje prvi slog na početku reči, pozitivne vrednosti n označavaju
pretragu od početka reči, a negativne vrednosti n od kraja reči. U slučaju neuspešne pretrage
povratna vrednost je -1. Dve zadate reči se rimuju (rec1^rec2) ako im se poklapaju
odgovarajuća slova poslednja dva sloga, odnosno poslednjeg sloga ako je neka od reči
jednosložna. Provera poklapanja slova vrši se od nosilaca pretposlednjih slogova u rečima,
odnosno nosilaca poslednjih slogova, ako je neka od reči jednosložna. Reč je moguće učitati
iz jedne linije ulaznog toka (it>>rec), pri čemu se ignorišu svi znaci koji nisu slova
engleskog alfabeta i pri čemu se gubi prethodni sadržaj reči. Reč se ispisuje u izlazni tok
(it<<rec) ispisivanjem njenih slova.
- *Stih* je sekvenca reči proizvoljne dužine. Stvara se prazan, a nakon toga je moguće dodavati
pojedinačne reči na kraj stiha (stih+=rec). Moguće je odrediti dužinu stiha izraženu u
broju njegovih reči (+stih), kao i broj slogova stiha izražen u zbiru slogova njegovih reči
(~stih). Moguće je dohvatiti reč sa zadate pozicije (stih[ind]), obrisati reč sa zadate
pozicije (stih(ind)) i umetnuti reč ispred reči na zadatoj poziciji (stih(rec, ind)).
Dva zadata stiha se rimuju (stih1^stih2) ako im se rimuju poslednje reči. Stih je moguće
učitati iz jedne linije ulaznog toka (it>>stih) čitanjem reči iz te linije, pri čemu se gubi
prethodni sadržaj stiha. Stih se ispisuje u izlazni tok (it<<stih) ispisivanjem njegovih
reči odvojenih tačno jednim znakom razmaka, u jednom redu.
- *Strofa* je sekvenca stihova ograničenog kapaciteta (broja stihova), koji se zadaje pri
stvaranju i koji može da se dohvati. Stvara se prazna, a nakon toga je moguće dodavati
pojedinačne stihove na kraj strofe (strofa+=stih), pri čemu je operacija bez efekta u
slučaju da se pokuša dodavanje stiha u punu strofu ili stiha sa različitim brojem slogova od
stihova koji se već nalaze u strofi. Prilikom dodavanja stiha u strofu pravi se kopija stiha
koji se dodaje. Moguće je ukloniti poslednje dodati stih (-strofa), pri čemu je uklanjanje iz
prazne strofe operacija bez efekta, kao i odrediti dužinu strofe izraženu u broju njenih
stihova (+strofa). Moguće je dohvatiti stih sa zadate pozicije (strofa[ind]), kao i
zameniti mesta stihovima sa zadatih pozicija (strofa(i, j)). Moguće je odrediti da li se
stihovi strofe rimuju (*strofa), kao i jednoslovnu oznaku vrste strofe. Strofa se ispisuje
u izlazni tok (it<<strofa) ispisivanjem njenih stihova u pojedinačnim redovima.
- *Katren* je strofa kapaciteta 4. Stihovi katrena se rimuju, ako je broj stihova jednak
kapacitetu i ako se prvi stih rimuje sa poslednjim, a drugi sa pretposlednjim. Vrsta katrena
je K.
Napisati glavnu funkciju koja učita nekoliko stihova sa standardnog ulaza, doda ih u katren i
ispiše ga na standardnom izlazu.
