#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3]; //declara uma array de nome board com 3 linhas e 3 colunas
const char PLAYER = 'X'; // declara uma variavel de nome Player do tipo char e estabelece o valor dela como X
const char COMPUTER = 'O'; // declara uma variavel de nome Computer do tipo char e estabelece o valor dela como O
/*serão criadas 7 funções prototipicas*/
void resetBoard();
void printBoard(); /* O tabuleiro será uma array de caracteres de 2 Dimensões*/
int checkFreeSpaces(); /* Se essa função retornar zero o jogo acabou, todas as posições do tabuleiro estão preenchidas*/
void playerMove(); /* Estabalece quando é a vez do Player*/
void computerMove(); /* Estabalece quando é a vez do Computador*/
char checkWinner();
void printWinner(char);

int main ()
{
  char winner = ' ';
  char response;
  
  do
  {
     
     winner = ' ';
     response = ' ';
     resetBoard();

  while (winner == ' ' && checkFreeSpaces() !=0) // se winner for igual vazio não tem ganhador E depois de evocar a checkfreespaces não pode ser zero
  {
      printBoard();

      playerMove();
      winner = checkWinner();
      if(winner != ' ' || checkFreeSpaces() == 0)//se o winner não for vazio, ou seja, se tivermos um vencedor OU o checkFreeSpaces for 0 o loop é parado (break)
      {
          break;
      }

      computerMove();
      winner = checkWinner();
      if(winner != ' ' || checkFreeSpaces() == 0)
      {
          break;
      }
  }
  
      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (Y/N): ");
      scanf("%c");
      scanf("%c", &response);
      response - toupper(response);
  } while (response == 'Y');
  

  return 0;
}
void resetBoard()
{
  for(int i = 0; i < 3; i++) // loop mais externo é para as linhas 
  {
    for(int j = 0; j < 3; j++) // loop mais interno é para as colunas
      {
          board[i][j] = ' '; //atribui o caractere de espaço em branco ' ' a cada elemento da matriz board na posição [i][j], limpando todos os elementos da matriz, preparando-a para um novo uso.
      }
  }
}
void printBoard();
{
  printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}
int checkFreeSpaces();
{
  int freeSpaces = 9; //declara variavel local de nome freespaces e inicializa ela com o valor de 9
  
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(board[i][j] != ' ')
        {
          freeSpaces--;
        }
      }
  }
  return freeSpaces;
}
void playerMove();
{
  int x;
  int y;

do//esse loop do-while solicita as entradas do jogador até que ele escolha uma posição válida
{
    printf("Enter row number (1-3): ")
  scanf("%d", &x);
  x--;//precisa desse decremento de 1 unidade pois o endereço das celula da matriz só pode ser 0,1 ou 2
  printf("Enter column number (1-3): ")
  scanf("%d", &y);
  y--;//precisa desse decremento de 1 unidade pois o endereço das celula da matriz só pode ser 0,1 ou 2

  if(board[x][y] != ' ') /* utilizado para confirmar se a célula (coordenada) estará ocupada (não vazia)*/
  {
    printf("Invalid move!\n");
  }
  else
  {
    board[x][y] = PLAYER
    break;
  }
} while (board[x][y] != ' ');

}
void computerMove();
{
    //create a seed based on current time
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces() > 0)
    {
      do
      {
        x = rand() % 3;
        y = rand() % 3;
      } while (board[x][y] != ' ');

      board[x][y] = COMPUTER;
    }
    else
    {
      printWinner(' '); //printWinner vazio significa um empate
    }
}
char checkWinner();
{
  //check rows
  for(int i = 0; i < 3; i++)
  {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] )
      {
        return board[i][0];
      }
  }
  //check columns
  for(int i = 0; i < 3; i++)
  {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] )
      {
        return board[0][i];
      }
  }
  //check diagonals
  if(board[0][0] == board[1][1] && board[0][0] == board[2][2] )
  {
     return board[0][0];
  }
  if(board[0][0] == board[1][1] && board[0][2] == board[2][2] )
  {
    return board[0][2];
  }

  return ' ';
}
void printWinner(char Winner); //função recebe uma variável de nome Winner do tipo char
{
    if (winner == PLAYER)
    {
      printf("YOU WIN!");
    }
    else if(winner == COMPUTER)
    {
      printf("YOU LOSE!");
    }
    else{
      printf("IT'S A TIE!")
    }
  
}