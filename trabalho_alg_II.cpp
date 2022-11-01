
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/michel-dick/ALGORITMOS/Algotitmos-II-main/algoritmosII.cpp"


typedef struct RECLAMACAO
{
    char cpf[12];
    char email[50];
    char tel[11];
    char reclamacao[256];

}RECLAMACAO;

void Cadastro_Reclamacao(FILE *Cad)
{
    RECLAMACAO cad_reclamacao;
    char s_ou_n;

    //CPF
    printf("\nDigite seu cpf: ");
    scanf("%s", &cad_reclamacao.cpf);
    
    while (!(VALIDA_CPF(cad_reclamacao.cpf)))
    {
        printf("\nDigite um cpf VALIDO: ");
        scanf("%s", &cad_reclamacao.cpf);
    }

    //EMAIL
    /*
    printf("\ndigite seu email: ");
    scanf("%s", &cad_reclamacao.email);
    //COMO VALIDAR???
    */
  
    //TELEFONE
    printf("\nDigite seu telefone: ");
    scanf("%s", &cad_reclamacao.tel);
    while (VALIDA_TEL(cad_reclamacao.tel))
    {
        printf("\nDigite um numero de telefone VALIDO: ");
        scanf("%s",&cad_reclamacao.tel);
    }

    //RECLAMACAO
    /*    
    printf("\ndigite sua reclamacao: ");
    scanf("%[^\n]s", &cad_reclamacao.reclamacao);
    if(strlen(cad_reclamacao.reclamacao)<256)
    {
        printf("\nvoce ainda tem %d caracteres para digitar",strlen(cad_reclamacao.reclamacao));
        printf("\nvc quer acresentar algo?[s/n]");
        scanf("%c", &s_ou_n);
        toupper(s_ou_n);
        if (s_ou_n == 'S')
        { 
            char rec_cont[256-strlen(cad_reclamacao.reclamacao)];
            printf("\n %s",cad_reclamacao.reclamacao);  
            fgets(rec_cont,(256-strlen(cad_reclamacao.reclamacao)),stdin);
            strcat(cad_reclamacao.reclamacao, rec_cont);
        }
    }
    */

    //ABRE ARQUIVO  
    /*
    //abre arquivo e insere
    Cad = fopen("Reclamacao.txt","a+");
    if (Cad == NULL)
    {
        printf("\nErro na abertura do arquivo");
    }
    else
    {
        fprintf(Cad,"\n%s",cad_reclamacao.cpf);
        fprintf(Cad,"\n%s",cad_reclamacao.email);
        fprintf(Cad,"\n%s",cad_reclamacao.tel);
        fprintf(Cad,"\n%s",cad_reclamacao.reclamacao);
        fprintf(Cad,"\n################################");
    }

    fclose(Cad);
    */

    printf("\n ");
    printf("\n ##########################################");
    printf("\nCPF: %s", cad_reclamacao.cpf);
    printf("\nTELEFONE: %s", cad_reclamacao.tel);
    //printf("\n email: %s", cad_reclamacao.email);
    //printf("\n reclamacao: %s",cad_reclamacao.reclamacao);
    printf("\n ##########################################");
    printf("\n ");

}

int main(int argc, char const *argv[])
{
    FILE *Cadastro;
    char tel[11];
    int opcao=0;

    while (opcao != 3)
    {
        printf("\n-- MENU --");
        printf("\n-1- Cadastrar reclamacao");
        printf("\n-2- Mostrar arquivo");
        printf("\n-3- Fim");
        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                Cadastro_Reclamacao(Cadastro);
                break;

            case 2:
                break;

            case 3:
                opcao = 3;
                break;
            
            default:
                while (opcao<1 || opcao>3)
                { 
                    printf("\nDIGITE UMA OPCAO VALIDA");
                    printf("\n-1- Cadastrar reclamacao");
                    printf("\n-2- Mostrar arquivo");
                    printf("\n-3- Fim");
                    scanf("%d",&opcao);
                }
                break;
        }
    }
    return 0;
}
