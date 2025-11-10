/*

Nome: Aline Barbosa Vidal RA: 10721348
Nome: Antonio Costa Satiro de Souza RA: 10723636

Descrição: O Programa Realiza Uma Contagem de Caracteres Consecutivos Em Uma String Lida,
Imprimindo o Resultado no Formato Caractere+Quantidade, Separados por Hífens.
O caractere '\n' Lido pelo fgets Não é Removido, Mas é Aproveitado para Forçar a Impressão
Do Último Grupo de Caracteres.

Exemplo de Entrada:
aaabbcc

Exemplo de Saída:
a3-b2-c2

*/

#include <stdio.h>
#include <string.h>

int main() {

    // Declaração de Variáveis
    char linha[512];
    char atual;
    int cont = 0;

    // Obtenção de String Via Teclado
    fgets(linha, sizeof(linha), stdin);
    int tam = strlen(linha);

    // Percorre a String
    for (int i = 0; i < tam; i++) {
        // Inicializa a Sequência na Variável 'atual'
        if (i == 0) {
            atual = linha[i];
            cont++;
        } else {
            // Se Padrão For Interrompido
            if (atual != linha[i]) {
                printf("%c%d", atual, cont); // Imprima Caractere + Qtd de Repetições

                // Imprime o Separador "-" Caso Existam Mais Impressões
                if (i != tam - 1) {
                    printf("-");
                }
                
                // Atualiza o Caractere Atual e Reinicia o Contador de Caractere
                atual = linha[i];
                cont = 1;
            } else {
                cont++;
            }
        }
    }

    return 0;
}
