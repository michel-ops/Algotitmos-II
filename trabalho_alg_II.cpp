
#include <stdio.h>
#include <stdlib.h>
#include "/home/michel/algoritmos II/Validacoes.cpp"


typedef struct RECLAMACAO
{
    char cpf[12];
    char email[50];
    char tel[11];
    char reclamacao[];

}RECLAMACAO;

void Cadastro_Reclamacao(FILE *Cad)
{
    RECLAMACAO cad_reclamacao;

    printf("\ndigite seu cpf: ");
    scanf("%s",&cad_reclamacao.cpf);
    while (!VALIDA_CPF(cad_reclamacao.cpf))
    {
        printf("\ndigite um cpf VALIDO: ");
        scanf("%s",&cad_reclamacao.cpf);
    }
    
    //email
    printf("\ndigite seu email: ");
    scanf("%s",&cad_reclamacao.email);
    //COMO VALIDAR???
   

    //telefone
    printf("\ndigite seu telefone: ");
    scanf("%s",&cad_reclamacao.tel);
 

    //reclamacao
    printf("\ndigite sua reclamacao: ");
    scanf("%s",&cad_reclamacao.reclamacao);

    //abre arquivo e insere 
}

int main(int argc, char const *argv[])
{
    FILE *Cadastro;
    int opcao;

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

    return 0;
}
