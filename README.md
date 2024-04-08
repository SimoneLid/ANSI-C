# ANSI-C
Programma che può eseguire due compiti diversi:
1. preso un testo in input crea una tabella csv in cui ogni riga contiene una parola con le frequenza delle parole successive
2. Presa una tabella csv scrive un testo random secondo le probabilità definite nel file
## Esecuzione
Il programma può essere eseguito in modalità mono-processo o multiprocesso scrivendo come secondo argomento nella linea di comando ```par``` per eseguirlo in modalità multiprocesso.
### Compito 1
Per far eseguire il compito 1 bisogna scrivere come input da linea di comandi ```1``` come primo argomento. Oltre il numero del compito e se lo si vuole multiprocesso o no bisogna specificare il file ```txt``` dalla linea di comando.<br>
Un esempio di comando per eseguire il programma e fargli eseguire il compito 1:
```sh
./ANSI-C 1 par input/example.txt
```
In questo esempio il testo è:
```
Cosa dicono le previsioni del tempo? Previsioni del tempo di oggi: tempo incerto! Previsioni di domani?
```
La tabella ```csv``` sarà creata in un file chiamato ```example.csv``` nella cartella ```csv```, in questo casò la tabella sarà:
```
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
Per far eseguire il compito 2 bisogna scrivere come input da linea di comandi ```2``` come primo argomento. Oltre il numero del compito e se lo si vuole multiprocesso o no bisogna specificare il file ```csv``` dalla linea di comando. Inoltra bisogna inserire in input la lunghezza della frase che si vuole generare e una parola da cui partire (opzionale).<br> 
Un esempio di comando per eseguire il programma e fargli eseguire il compito 2:
```sh
./ANSI-C 2 par input/example.csv 11 !
```
In questo esempio la tabella è:
```
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
Il testo in output sarà creato in un file chiamato ```example_random.txt``` nella cartella ```output```, in questo casò un possibile output da 11 parole sarà:
```
Previsioni del tempo incerto ! Cosa dicono le previsioni del tempo
```

## Architettura
