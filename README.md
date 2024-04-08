# ANSI-C
Programma che può eseguire due compiti diversi:
1. preso un testo in input crea una tabella csv in cui ogni riga contiene una parola con le frequenza delle parole successive
2. Presa una tabella csv scrive un testo random secondo le probabilità definite nel file

Il programma può essere eseguito in modalità mono-processo o multiprocesso scrivendo come secondo argomento nella linea di comando ```par``` per eseguirlo in modalità multiprocesso.
## Compito 1
Per far eseguire il compito 1 bisogna scrivere come input da linea di comandi ```1``` come primo argomento. Oltre il numero del compito e se lo si vuole multiprocesso o no bisogna specificare il file ```txt``` dalla linea di comando. Un esempio di comando per eseguire il programma e fargli eseguire il compito 1:
```sh
./ANSI-C 1 par input/example.txt
```
In questo esempio il testo è:
```
Scrivi testo esempio
```
La tabella ```csv``` sarà creata in un file chiamato ```example.csv``` nella cartella ```csv```, in questo casò la tabella sarà:
```
Scrivi tabella csv
```


## Compito 2
Per far eseguire il compito 2 bisogna scrivere come input da linea di comandi ```2``` come primo argomento. Oltre il numero del compito e se lo si vuole multiprocesso o no bisogna specificare il file ```csv``` dalla linea di comando. Un esempio di comando per eseguire il programma e fargli eseguire il compito 2:
```sh
./ANSI-C 2 par input/example.csv
```
In questo esempio la tabella è:
```
Scrivi tabella csv
```
Il testo in output sarà creato in un file chiamato ```example_random.txt``` nella cartella ```output```, in questo casò la tabella sarà:
```
Scrivi testo casuale
```