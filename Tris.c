#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

char n1 = ' ', n2 = ' ', n3 = ' ', n4 = ' ', n5 = ' ', n6 = ' ', n7 = ' ', n8 = ' ', n9 = ' ';
int cont_scelta = 0;

void stato()                              //STATO DELLA GRIGLIA
{
  printf("\n %c | %c | %c\n", n1, n2, n3);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", n4, n5, n6);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", n7, n8, n9);
}

void win(int* end)                        //CONTROLLO VITTORIA
{
  //if che controlla tutte le combinazioni
  if( ((n1 == n2 && n2 == n3) && n1 != ' ') || ((n4 == n5 && n5 == n6) && n4 != ' ') || ((n7 == n8 && n8 == n9) && n7 != ' ') || ((n1 == n4 && n4 == n7) && n1 != ' ') || ((n2 == n5 && n5 == n8) && n2 != ' ') || ((n3 == n6 && n6 == n9) && n3 != ' ') || ((n1 == n5 && n5 == n9) && n1 != ' ') || ((n3 == n5 && n5 == n7) && n3 != ' '))
  {
    for(int i = 0; i < 3; i++) //piccola animazione
    {
        system("cls");
        stato();
        printf("\n \\ Vittoria! \\ \n");
        system("ping localhost -n 2 >nul");
        system("cls");
        stato();
        printf("\n / Vittoria! / \n");
        system("ping localhost -n 2 >nul");
    }

    //var in output (utilizzo di un puntatore)
    *end = 1;
  }
}

int controllo(int scelta)                 //CONTROLLA SE LA POSIZIONE SCELTA SIA ACCUPATA O MENO
{
  int a = 0;

  switch (scelta) {
    case 1:
      if(n1 == ' ')
        a = 1;
      break;
    case 2:
      if(n2 == ' ')
        a = 1;
      break;
    case 3:
      if(n3 == ' ')
        a = 1;
      break;
    case 4:
      if(n4 == ' ')
        a = 1;
      break;
    case 5:
      if(n5 == ' ')
        a = 1;
      break;
    case 6:
      if(n6 == ' ')
        a = 1;
      break;
    case 7:
      if(n7 == ' ')
        a = 1;
      break;
    case 8:
      if(n8 == ' ')
        a = 1;
      break;
    case 9:
      if(n9 == ' ')
        a = 1;
  }
  return a;
}

void posizionamento(int i, int scelta)    //POSIZIO0NAMENTO DI 'X' O 'O' SULLA GRIGLIA
{
  switch (scelta) {
    case 1:
      if(i % 2 == 0)
        n1 = 'X';
      else
        n1 = 'O';
      break;
    case 2:
      if(i % 2 == 0)
        n2 = 'X';
      else
        n2 = 'O';
      break;
    case 3:
      if(i % 2 == 0)
        n3 = 'X';
      else
        n3 = 'O';
      break;
    case 4:
      if(i % 2 == 0)
        n4 = 'X';
      else
        n4 = 'O';
      break;
    case 5:
      if(i % 2 == 0)
        n5 = 'X';
      else
        n5 = 'O';
      break;
    case 6:
      if(i % 2 == 0)
        n6 = 'X';
      else
        n6 = 'O';
      break;
    case 7:
      if(i % 2 == 0)
        n7 = 'X';
      else
        n7 = 'O';
      break;
    case 8:
      if(i % 2 == 0)
        n8 = 'X';
      else
        n8 = 'O';
      break;
    case 9:
      if(i % 2 == 0)
        n9 = 'X';
      else
        n9 = 'O';
  }
}

int mosse_vincenti(char input)            //CONTROLLO MOSSE VINCENTI AVVERSARIO
{
  cont_scelta++;
  //riga 1
  if((n1 == input && n2 == input) && n3 == ' ' ||
     (n2 == input && n3 == input) && n1 == ' ' ||
     (n3 == input && n1 == input) && n2 == ' ' )
  {
      return cont_scelta;
  }
  //riga 2
  if((n4 == input && n5 == input) && n6 == ' ' ||
     (n5 == input && n6 == input) && n4 == ' ' ||
     (n6 == input && n4 == input) && n5 == ' ' )
  {
      return cont_scelta + 3;
  }
  //riga 3
  if((n7 == input && n8 == input) && n9 == ' ' ||
     (n8 == input && n9 == input) && n7 == ' ' ||
     (n9 == input && n7 == input) && n8 == ' ' )
  {
      return cont_scelta + 6;
  }
  //colonna 1
  if((n1 == input && n4 == input) && n7 == ' ' ||
     (n4 == input && n7 == input) && n1 == ' ' ||
     (n7 == input && n1 == input) && n4 == ' ' )
  {
      switch(cont_scelta) {case 1: return 1; case 2: return 4; case 3: return 7;}
  }
  //colonna 2
  if((n2 == input && n5 == input) && n8 == ' ' ||
     (n5 == input && n8 == input) && n2 == ' ' ||
     (n8 == input && n2 == input) && n5 == ' ' )
  {
      switch(cont_scelta) {case 1: return 2; case 2: return 5; case 3: return 8;}
  }
  //colonna 3
  if((n3 == input && n6 == input) && n9 == ' ' ||
     (n6 == input && n9 == input) && n3 == ' ' ||
     (n9 == input && n3 == input) && n6 == ' ' )
  {
      switch(cont_scelta) {case 1: return 3; case 2: return 6; case 3: return 9;}
  }
  //diagonale 1
  if((n1 == input && n5 == input) && n9 == ' ' ||
     (n5 == input && n9 == input) && n1 == ' ' ||
     (n9 == input && n1 == input) && n5 == ' ')
  {
    switch(cont_scelta) {case 1: return 1; case 2: return 5; case 3: return 9;}
  }
  //diagonale 2
  if((n3 == input && n5 == input) && n7 == ' ' ||
     (n5 == input && n7 == input) && n3 == ' ' ||
     (n7 == input && n3 == input) && n5 == ' ')
  {
    switch(cont_scelta) {case 1: return 3; case 2: return 5; case 3: return 7;}
  }
  else
  {
    if(input == 'O')
      return 100;
    else
    {
      srand(time(NULL));
      switch (rand()%4) {case 0: return 1; case 1: return 3; case 2: return 7; case 3: return 9;}
    }
  }
}

int scelta_PC(int i)                      //SCELTA MOSSE PC
{
  int a;


  switch (i) {
    case 1:
      srand(time(NULL));
      return (rand()%9)+ 1;
    case 3:
      return mosse_vincenti('X');
    default:
      a = mosse_vincenti('O');
      if(a == 100)
        return mosse_vincenti('X');
      else
        return a;

  }
}

void multiplayer()                        //MODALITÀ MULTIPLAYER
{
  int scelta, a, end = 0;

  for(int i = 0; i < 9; i++)
  {

    system("cls");
    printf("===== MULTIPLAYER =====\n");
    stato();

    if(i % 2 == 0)
    {
      do
      {
        do
        {
          printf("\nX) Scegliere la posizione ");
          scanf("%d", &scelta);
        } while(scelta < 1 || scelta > 9);
      } while(controllo(scelta) == 0);
    }
    else
    {
      do
      {
        do
        {
          printf("\n0) Scegliere la posizione ");
          scanf("%d", &scelta);
        } while(scelta < 1 || scelta > 9);
      } while(controllo(scelta) == 0);
    }

    posizionamento(i, scelta);
    win(&end);

    if(end == 1) //se la variabile vale 1 (viene modificata in win() con l'uso di un puntatore) in programma finisce
      return;
  }
}

void singleplayer()                       //MODALITÀ SINGLEPLAYER
{
  /*
  FATTO
  prima mossa: casuale (casella vuota)
- prima mossa giocatore (X)

FATTO
seconda mossa:
- controllo combinazioni vincenti avversario (bloccare posizioni avversarie)
- posizione angolare
- se la X è su un bordo: il cerchio le andrà di fianco


terza mossa:
- controllo combinazioni vincenti (funzione che posiziona la O)
- controllo vittoria PC

mossa >3:
- controlli terza mossa
*/
  int scelta, end = 0;

  for(int i = 0; i < 9; i++)
  {

    system("cls");
    printf("===== SINGLEPLAYER =====\n");
    stato();

    if(i % 2 == 0)
    {
      do
      {
        do
        {
          printf("\nScegliere la posizione: ");
          scanf("%d", &scelta);
        } while(scelta <= 0 || scelta > 9);
      } while(controllo(scelta) == 0);
    }
    else
    {
      do
      {
        scelta = scelta_PC(i);
      } while(controllo(scelta) == 0);
      cont_scelta = 0;
    }

    posizionamento(i, scelta);
    win(&end);
    if(end == 1)
      return;
  }

  //piccola animazione
  for(int i = 0; i < 3; i++)
  {
      system("cls");
      stato();
      printf("\n \\ Pareggio! \\ \n");
      system("ping localhost -n 2 >nul");
      system("cls");
      stato();
      printf("\n / Pareggio! / \n");
      system("ping localhost -n 2 >nul");
  }


  return;
}

int main()
{
  int mod;

  printf("===== MODALITÀ =====\n");
  printf("  1) Multiplayer\n");
  printf("  2) Singleplayer\n");
  printf("=====================\n");

  do
  {
    printf("\nModalità: ");
    scanf("%d", &mod);
  } while(mod != 1 && mod != 2);

  if(mod == 1)
    multiplayer();
  else
    singleplayer();

  return 0;
}
