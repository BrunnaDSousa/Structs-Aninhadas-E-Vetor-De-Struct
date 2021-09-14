//Structs aninhadas e vetor de struct em C - https://www.youtube.com/watch?v=h0GL9vWcxB8
//struct dentro de struct


#include <stdio.h>
#include <stdlib.h>


struct tp_endereco{
    //char nome;
    int numero;
    //char email; 
    char rua [40];
    char bairro[40];
    char cidade[40];
    char estado[3];
    int cep;
};

struct tp_data_nascimento{
    int dia;
    int mes;
    int ano;
};

struct cadastro_client{
    char nome_cliente [40];
    int telefone;



    //pra coisar o endereço contendo a rua, numero, bairro....
    struct tp_endereco endereco; //pode usar como tipo de dado dentro do cadastro cliente
    //variavel = endeco tipo=tp_endereco

    //pra coisar a data nascimento com dia, mes e ano
    struct tp_data_nascimento data_nascimento;
    
}
cad_cliente[2]; //vetor pra poder armazenar mais cliente
//"tabela dentro de outra tabela"

//programa principal
int main(){

    int i;

    printf("\n\n ----- Cadastro dos Clientes ----- \n\n");

    //Armazenando os dados do cadastro dentro da struct cad_cliente
    for(i=0; i<2; i++){
        printf("\n\nNome do cliente........:");
        fflush(stdin); //boffer do teclado
        gets(cad_cliente[i].nome_cliente); //nome_cliente = variavel interna

        printf("\nDigite o telefone do cliente..:");
        scanf("%d", &cad_cliente[i].telefone);


        //estao na struct do tipo endereco
        printf("\nDigite a rua ...... :");
        fflush(stdin);
        gets(cad_cliente[i].endereco.rua);
        //endereco = struct do tipo tp_endereco
        //nome da varivael interna = rua

        printf("\nDigite o numero.....:");
        scanf("%d", &cad_cliente[i].endereco.numero);

        printf("\n\nBairro.........................:");
        fflush(stdin);
        gets(cad_cliente[i].endereco.bairro);

        printf("\n\nCidade.........................:");
        fflush(stdin);
        gets(cad_cliente[i].endereco.cidade);

        printf("\n\nEstado.........................:");
        fflush(stdin);
        gets(cad_cliente[i].endereco.estado);

        printf("\nDigite seu CEP....:");
        scanf("%d", &cad_cliente[i].endereco.cep);

        //data_nascimento = separado
        printf("\nDia de nascimento.....:");
        scanf("%d", &cad_cliente[i].data_nascimento.dia);

        printf("\nMes de nascimento.....:");
        scanf("%d", &cad_cliente[i].data_nascimento.mes);

        printf("\nAno de nascimento.....:");
        scanf("%d", &cad_cliente[i].data_nascimento.ano);
    }//fim da coleta

    //mostar oq ta no vetor struct 
    //percorrer o vetor de struct cad_cliente
    for(i=0; i<2; i++){

        printf("\n------------------------\n");

        printf("\n Nome........: %s", cad_cliente[i].nome_cliente);
        printf("\n Rua........: %s", cad_cliente[i].endereco.rua);
        printf("\n Numero........: %d", cad_cliente[i].endereco.numero);
        printf("\n Bairro........: %s", cad_cliente[i].endereco.bairro);
        printf("\n Cidade........: %s", cad_cliente[i].endereco.cidade);
        printf("\n Estado........: %s", cad_cliente[i].endereco.estado);
        printf("\n Cep........: %d", cad_cliente[i].endereco.cep);

        printf("\n Dia de nasc: %d", cad_cliente[i].data_nascimento.dia);
        printf("\n Mes de nasc: %d", cad_cliente[i].data_nascimento.mes);
        printf("\n Ano de nasc: %d", cad_cliente[i].data_nascimento.ano);     

        printf("\n------------------------\n");  
    }


    system("pause");
    return 0;
}
