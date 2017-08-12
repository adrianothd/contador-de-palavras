/* ADRIANO TENORIO        RA.: 154468 */

/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {
    
    char c0; // caracter anterior
    char c1; // caracter atual
    
    c0 = 0;
    c1 = 1;
    
    scanf("%c", &c0);
    scanf("%c", &c1);
    
    int NumPalavras = 0; // contagem das palavras
    int flag = 0; // situacao especial de "NUM." ou "NUM,"
    
    while(c1 != '\n'){ // enquanto não finalizar a frase com "ENTER"
        
        if( (c1 == ' ') || (c1 == '!') ){
            if( (c0 != ' ') && (c0 != '.') && (c0 != ',') && (c0 != '!') ){
                NumPalavras++;
            }
        }
        
        if( (c1 == ',') || (c1 == '.') ){
            if( (c0 == '0') || (c0 == '1') || (c0 == '2') || (c0 == '3') ||
                (c0 == '4') || (c0 == '5') || (c0 == '6') || (c0 == '7') ||
                (c0 == '8') || (c0 == '9') ){
                if(flag == 0){
                    flag = 1;
                }
                else{
                    NumPalavras++;
                    flag = 0;
                }
            }
            else{
                if( (c0 != ' ') && (c0 != '.') && (c0 != ',') && (c0 != '!') && (c0 != '-')){
                    NumPalavras++;
                }
            }
        }
        
        if(c1 == '-'){
            if( (c0 != ' ') && (c0 != '.') && (c0 != ',') && (c0 != '!') ){
                NumPalavras++;
            }
        }
        
        c0 = c1;
        scanf("%c", &c1);    // pega o próximo caracter
    }
    
    if( (c0 != ' ') && (c0 != '.') && (c0 != ',') && (c0 != '!') ){
        NumPalavras++;
    }

  printf("%d\n", NumPalavras);
  return 0;
}

/* CASOS POSSÍVEIS
LEGENDA
L        letra
N        número
\n        ENTER
nda        não faz nada

ESPAÇO & EXCLAMAÇÃO
"L "    "L!"    NumPalavras++
"N "    "N!"    NumPalavras++
"  "    " !"    nda
". "    ".!"    nda
", "    ",!"    nda
"! "    "!!"    nda

PONTO FINAL & VÍRGULA
"L,"    "L."    NumPalavras++
"N,"    "N."    se "FLAG = 1" -> NumPalavras++
                se "FLAG = 1" -> nda
" ,"    " ."    nda
".,"    ".."    nda
",,"    ",."    nda
"!,"    "!."    nda

ENTER
"L\n"    NumPalavras++
"N\n"    NumPalavras++
" \n"    nda
".\n"    nda
",\n"    nda
"!\n"    nda
*/



