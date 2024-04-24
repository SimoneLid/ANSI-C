# ANSI-C
Programma che può eseguire due compiti diversi:
1. Preso un testo in input crea una tabella csv in cui ogni riga contiene una parola con le frequenza delle parole successive
2. Presa una tabella csv scrive un testo random secondo le probabilità definite nel file di un numero di parole definito e partendo da una parola definita
## Esecuzione
Per decidere quale compito eseguire bisogna scrivere come input nella linea di comando `-1` o `-2` (obbligatorio inserirne solo uno dei due). Bisogna inoltre specificare un file in input, scritto dopo la flag `-i` e un file di output, scritto dopo la flag `-o`.<br>
Il programma può essere eseguito in modalità multiprocesso scrivendo come argomento nella linea di comando `-p`.
### Compito 1
Un esempio di comando per eseguire il programma e fargli eseguire il compito 1 multiprocesso:
```sh
./ANSI-C -1 -p -i input/example.txt -o csv/example.csv
```
In questo esempio il testo è:
```text
Cosa dicono le previsioni del tempo? Previsioni del tempo di oggi: tempo incerto! Previsioni di domani?
```
La tabella `csv` in questo casò contierrà:
```text
., cosa,1
!,previsioni,1
cosa,dicono,1
dicono,le,1
le,previsioni,1
previsioni,di,0.3333,del,0.6666
del,tempo,1
tempo,incerto,0.3333,di,0.3333,?,0.3333
?,previsioni,1
di,domani,0.5,oggi,0.5
oggi,tempo,1
incerto,!,1
domani,?,1
```


### Compito 2
Il compito due ha bisogno di un valore in input aggiuntivo, cioè il numero di parole, da scrivere dopo la flag `-n`. Inoltre si può aggiungere in modo opzionale una parola da cui far iniziare il testo random dopo una fla `-s`.<br> 
Un esempio di comando per eseguire il programma e fargli eseguire il compito 2 multiprocesso:
```sh
./ANSI-C -2 -p -i csv/example.csv -o random_text/example_random.txt -n 11 -s !
```
In questo esempio la tabella è:
```text
., cosa,1
!,previsioni,1
cosa,dicono,1
dicono,le,1
le,previsioni,1
previsioni,di,0.3333,del,0.6666
del,tempo,1
tempo,incerto,0.3333,di,0.3333,?,0.3333
?,previsioni,1
di,domani,0.5,oggi,0.5
oggi,tempo,1
incerto,!,1
domani,?,1
```
Il testo in output sarà creato in modo random, in questo casò un possibile output da 11 parole sarà:
```
Previsioni del tempo incerto ! Cosa dicono le previsioni del tempo
```

## Architettura
Il programma utilizza una linked list di parole (Word), ad ognuna è associata un'altra linked list contenente le parole (chiamate Tuple) che appaiono successive a quella con la frequenza.<br>
Per rendere la scritura del test random più veloce ogni Tupla ha inoltre un puntatore collegato alla Word contenente quella determinata parola.<br>
Una rappresentazione grafica dell'architettura è:
```text
+--WORD---+     +--WORD---+     +--WORD---+
|         | --> |         | --> |         | --> ...
+---------+     +---------+     +---------+
     |               |               |
     V               V               V
+--TUPLA--+     +--TUPLA--+     +--TUPLA--+
|         |     |         |     |         |
+---------+     +---------+     +---------+
     |               |               |
     V               V               V
+--TUPLA--+     +--TUPLA--+     +--TUPLA--+
|         |     |         |     |         |
+---------+     +---------+     +---------+
     |               |               |
     V               V               V
    ...             ...             ...
```