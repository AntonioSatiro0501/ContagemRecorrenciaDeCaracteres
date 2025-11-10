/*
Nome: Aline Barbosa Vidal RA: 10721348
Nome: Antonio Costa Satiro de Souza RA: 10723636

Descrição:

Este Programa Lê Uma String Digitada pelo Usuário e Compacta Blocos de Caracteres
Que Se Repetem de Forma Contínua. A Ideia é Testar Padrões de Diferentes Comprimentos
Até Encontrar o Menor Que Se Repete Consecutivamente.

Caso um Trecho Não Possua Repetições, Ele é Impresso como Está e Cada
Caractere Será Seguido de 1. Exemplo: carlos - c1-a1-r1-l1-o1-s1.

Exemplos de Entrada:

antonioantonioantoniocarloscarlos
abcabcabcabcxyxyxyccccccc

Exemplos de Saída:

antonio3-carlos2
abc4-xy3-c7

*/

#include <stdio.h>
#include <string.h>

// Função: Contar Repetições Consecutivas De um Padrão (tamanho_padrao) A Partir De uma Posição (pos).
int contar_repeticoes(char str[], int pos, int tamanho_padrao, int tamanho_total){
    int cont = 1;
    int i;

    while(pos +(cont * tamanho_padrao) + tamanho_padrao <= tamanho_total){
        int iguais = 1; // Inicialmente, Assume-se Que Os Blocos São Iguais (true)

        // Compara o Bloco Atual Com o Próximo Bloco
        for(int i = 0; i < tamanho_padrao; i++){
            if(str[pos + i] != str[pos + cont * tamanho_padrao + i]){
                iguais = 0; // Blocos São Diferentes (false)
                break; // Se o Bloco For Diferente, Interrompe a Comparação

            }
        }
        if(iguais){
            cont++; // Padrão Encontrado
        }else{
            break; // Padrão Interrompido
        }
    }
    return cont;
}

int main(){

    // Declaração de Variáveis
    char linha[512];
    int n, i = 0;

    // Obtenção da String Via Teclado
    fgets(linha,sizeof(linha),stdin);
    n = strlen(linha);

    // Remove o \n No Final Da String (Evita Erros de Contagem)
    if(linha[n - 1] == '\n'){
        linha[n - 1] = '\0';
        n--;
    }

    // Laço Principal Para Compactação de String
    while(i < n){
        int tam_padrao = 1; // Inicialmente, o Padrão é Composto Por Caractere Único
        int qtd_repeticoes = 1;

        // Testa Tamanhos de Padrão 'j' Até a Metade do Restante da String
        for(int j = 1; j <= (n - i)/2;j++){
            int repeticao = contar_repeticoes(linha,i,j,n);
            if(repeticao > 1){
                tam_padrao = j;
                qtd_repeticoes = repeticao;
                break; // Processa o Menor Padrão Encontrado
            }
        }

        // Imprime o Padrão Encontrado
        for(int j = 0; j < tam_padrao; j++){
        printf("%c",linha[i + j]);
    }
        printf("%d",qtd_repeticoes);
        i+= tam_padrao * qtd_repeticoes;

        // Imprime o Separador "-" Caso Existam Mais Padrões A Serem Impressos
        if(i < n){
            printf("-");
        }
    }

    return 0;
}
