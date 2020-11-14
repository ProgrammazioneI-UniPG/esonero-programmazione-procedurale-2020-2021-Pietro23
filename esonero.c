#include <stdio.h>
#include <stdlib.h> //Da includere per utilizzare rand() e srand ()
#include <time.h> // per utilizzare time()
#include <string.h>//per utilizzare strlen
int main(void){
//Dichiaro le variabili
char i=0;
int a; //Serve all'utente per decidere 1 o 2
int b;//Serve per decidere 1 o 2
char str_m[128];  //str = plaintext
char str_k[128];//Chiave per cifrare
char str_r[128];//chiave automatica
char txtc[128]; //Testo cifrato

time_t t ;//dichiarata per usare srand((unsigned) time(&t))


printf("Inserire la stringa di max 128 caratteri che si vuole cifrare\n");
fgets(str_m,128,stdin);
printf("La stringa inserita è: %s\n", str_m);

printf("Per immettere manualmente la chiave digitare: 1\nPer generare casualmente la chiave digitare: 2\n");
scanf("%d", &a);
getchar();
  if(a==1){
    printf("Inserisci la chiave con la quale cifrare il testo(uguale o superiore non di 128)\n");
    fgets(str_k,128,stdin);

    if(strlen(str_k)<strlen(str_m)){
      printf("Inserisci la chiave uguale o maggiore del testo da cifrare,per favore riesegui il programma \n");
    }
    else {
      printf("La chiave inserita è: %s\n",str_k);
      //ciclo per eseguire xor carattere per carattere
      for(int i=0; i<strlen(str_m); i++){
      txtc[(unsigned char)i]=str_m[(unsigned char)i]^str_k[(unsigned char)i];
      //esegue lo xor tra str_m e str_k
    }
      printf("Il testo cifrato è: %s\n", txtc);
      printf("Se vuoi vedere il testo inserito attraverso testo cifrato^chiave inserisci 1\n");
      scanf("%d", &b);
      if(b==1){
      str_m[(unsigned char)i]=txtc[(unsigned char)i]^str_k[(unsigned char)i];
      printf("Il testo inserito ricavato con txtc^str_k è: %s\n", str_m);
    }
    else{
      printf("Devi inserire 1... Per favore ripetere da capo il programma\n");
    }
  }
}
else if(a==2){
  printf("La chiave generata casualmente è:\n");
  /* Inizializza il generatore di numeri casuali utilizzando il tempo attuale */
  srand((unsigned) time(&t));
  for (int i=0; i<strlen(str_m); i++) {
  str_r[i]=33+rand()%96;
  printf("%s",str_r);
}
  if(strlen(str_r)<strlen(str_m))
  {
    printf("La chiave generata è piu piccola di k\n");
  }
  else{
    //ciclo per eseguire xor carattere per carattere
  for(i=0;i<strlen(str_m);i++){
    //esegue lo xor tra str_m e str_r
    txtc[(unsigned char)i]=str_m[(unsigned char)i]^str_r[(unsigned char)i];
  }
    printf("\nIl testo cifrato è: %s", txtc);
    printf("\nSe vuoi vedere il testo inserito attraverso 'testo cifrato^chiave' inserisci 2\n");
    scanf("%d", &b);
  }
  if(b==2){
  str_m[(unsigned char)i]=txtc[(unsigned char)i]^str_r[(unsigned char)i];
  printf("Il testo inserito ricavato con txtc^str_k è: %s\n", str_m);
  }
  else{
  printf("Devi inserire 2... Per favore ripetere da capo il programma\n");
  }
  }
else if(a!=1 && a!=2){
  printf("Devi inserire 1 o 2,per favore, ripetere il programma dall'inizio.\n");
}
return 0;
}
