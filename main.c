#include <stdio.h>
#include <string.h>
#include <lista.h>
int main()
{
    // Struct com os dados do professor
    ListaVetor lista;
    Professor prof;
    //Comando que declar um ponteiro para um arquivo em C
    FILE *arquivo = NULL;
    //Endereço do arquivo no computador
    char *nomeDoArquivo = "/Users/macbookpro/Desktop/dados.txt";
    //String para coletar dados do teclado
    char string[250];
    Professor profOut;

    inicializarDadosLista(600,&lista);
    int posicao = 0;
    int escolha=0;
    do{
        printf("\t\tMENU\n");
        printf("1 - Carregar arquivo\n"
               "2 - Mostrar dados da lista\n"
               "3 - Inserir no inicio\n"
               "4 - Inserir no fim\n"
               "5 - Inserir na posição\n"
               "6 - Retirar do inicio\n"
               "7 - Retirar do fim\n"
               "8 - Retirar da posição\n"
               "9 - Acessar no inicio\n"
               "10 - Acessar no fim\n"
               "11 - Acessar na posição\n"
               "12 - Inserir ordenado\n"
               "-1 - Finalizar programa\n"
               "Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            //Comando que abre um arquivo texto existente
            arquivo = fopen(nomeDoArquivo, "r");
            printf("\n ARQUIVO CARREGADO \n");
            while(!feof(arquivo)){
                if(fgets(string,250,arquivo)){
                    carregarProf(&prof, string);
                    inserirElementoNoFinal(&prof, &lista);
                }
            }
            //Comando que fecha um arquivo texto
            fclose(arquivo);
            break;
        case 2:
            mostrarDadosLista(&lista);
            break;
        case 3:
            printf("\nMATRICULA;NOME;ESCOLA;TITULAÇÃO;TIPO");
            printf("\n\nDigite os dados do professor: ");
            fflush(stdin);
            fgets(string, 250, stdin);

            carregarProf(&prof, string);
            inserirElementoNoInicio(&prof, &lista);
            break;
        case 4:
            printf("\nMATRICULA;NOME;ESCOLA;TITULAÇÃO;TIPO");
            printf("\n\nDigite os dados do professor: ");
            fflush(stdin);
            fgets(string, 250, stdin);

            carregarProf(&prof, string);
            inserirElementoNoFinal(&prof, &lista);
            break;

        case 5:
            printf("\nMATRICULA;NOME;ESCOLA;TITULAÇÃO;TIPO");
            printf("\n\nDigite os dados do professor: ");
            fflush(stdin);
            fgets(string, 250, stdin);
            carregarProf(&prof, string);
            printf("\nDigite a posição: ");
            fflush(stdin);
            scanf("%d", &posicao);
            inserirNaPosicao(&prof,posicao,&lista);
            break;

        case 6:
            profOut = retirarInicioLista(&lista);
            mostrarDadosProfessor(&profOut);
            break;

        case 7:
            profOut = retirarFinalLista(&lista);
            mostrarDadosProfessor(&profOut);
            break;

        case 8:
            printf("\nDigite a posição: ");
            fflush(stdin);
            scanf("%d", &posicao);
            profOut = retirarPosicaoLista(posicao, &lista);
            mostrarDadosProfessor(&profOut);
            break;

        case 9:
            profOut = acessarInicioLista(&lista);
            mostrarDadosProfessor(&profOut);
            break;

        case 10:
            profOut = acessarFinalLista(&lista);
            mostrarDadosProfessor(&profOut);
            break;

        case 11:
            printf("\nDigite a posição: ");
            fflush(stdin);
            scanf("%d", &posicao);
            profOut = acessarPosicaoLista(posicao, &lista);
            mostrarDadosProfessor(&profOut);
            break;

        case 12:
            printf("\nMATRICULA;NOME;ESCOLA;TITULAÇÃO;TIPO");
            printf("\n\nDigite os dados do professor: ");
            fflush(stdin);
            fgets(string, 250, stdin);

            carregarProf(&prof, string);
            inserirOrdenadoLista(&prof, &lista);
            break;

        case -1:
            printf("Encerrando programa...");
            break;

        default:
            printf("\nDigite uma opção válida!\n");
            break;
        }
    }while(escolha != -1);
    liberarLista(&lista);

}
