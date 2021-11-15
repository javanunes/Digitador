/* Esse programa unix lê do arquivo /tmp/comandos.txt a primeira linha de comando
 * para depois simular alguém o digitando para a uma apresentação , no fimal ele
 * executa o comando dentro desse arquivo também.
 * Ideal para screencats onde se mostra um comando sendo digitado para ver a sua saída.
 */


#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

string obtemLinhaComandoArquivo(){
    string line;
    ifstream arquivo("/tmp/comandos.txt");
    system("clear");
    if (arquivo.is_open())
    {
      while (! arquivo.eof() )
      {
         getline (arquivo,line);
         return line;
      }
    }
    cout << "Erro ao ler o arquivo /tmp/comandos.txt onde tem os comandos para ler  " << endl;
    return "";
}



int main(void)
{
    string linha = obtemLinhaComandoArquivo();
    const int TAMANHO_LINHA_COMANDO_BUFFER = 2000;
    const int SEGUNDOS_PARA_INICIAR_APRESENTACAO = 4;
    int tamanhoStringComando = linha.length();
    int letraPosicao = 0;
    char stringComando[TAMANHO_LINHA_COMANDO_BUFFER];

    strcpy(stringComando,linha.c_str());
    cout << "\n \n \n \n \n";
    sleep(SEGUNDOS_PARA_INICIAR_APRESENTACAO);
    while(letraPosicao < tamanhoStringComando){
        printf("%c", stringComando[letraPosicao]);
        cout.flush();
        usleep(310000);
        letraPosicao++;
    }
    cout << endl;
    system(stringComando);
    return 0;
}
