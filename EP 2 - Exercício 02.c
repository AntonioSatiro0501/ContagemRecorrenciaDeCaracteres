/*

Aline Barbosa Vidal - RA: 10721348
Antonio Costa Satiro de Souza - RA: 10723636

Descrição: Este Programa Lê Uma Linha de Texto Codificada e a Decodifica.
Cada Caractere, Exceto '-', é Seguido De Um Número, Que Indica Quantas
Vezes Esse Caractere Deve Ser Repetido Na Saída. Hífens São Ignorados.

Exemplo de Entrada:
a3-b2

Exemplo de Saída:
aaabb

 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char linha[512];
    int i = 0;

    // Lê Uma Linha da Entrada
    fgets(linha, sizeof(linha), stdin);

    // Remove o Caractere de Nova linha ('\n'), Caso Exista
    linha[strcspn(linha, "\n")] = '\0';

    int tam = strlen(linha);

    // Loop Principal Para Percorrer Toda a Linha
    while (i < tam) {

        // Ignora Hífens
        if (linha[i] == '-') {
            i++;
            continue;
        }

        // Armazena o Caractere Atual
        char atual = linha[i++];
        int n = 0;

        // Constrói o Número Que Indica Quantas Vezes Repetir o Caractere
        // Necessário Para Números Que Ocupem Mais de um Char (Ex: 15,175)
        while (i < tam && isdigit(linha[i])) {
            n = n * 10 + (linha[i] - '0');
            i++;
        }

        // Imprime o Caractere 'Atual', 'N' Vezes
        for (int j = 0; j < n; j++) {
            printf("%c", atual);
        }
    }

    return 0;
}

