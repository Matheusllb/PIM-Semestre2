#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    //Login();
    MenuPrincipal();
}

//Definindo novo tipo de dado "Data"

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

//Definindo novo tipo de dado "Usuário"
typedef struct NovoUsuario {
    char nome[20];
    char sobreNome[20];
    char usuario[50];
    char email[50];
    char senha[20];
}USUARIO;

//Definindo novo tipo de dado "Funcionário"

typedef struct NovoFuncionario {
    char nome[20];
    char sobreNome[20];
    DATA nascimento;//data
    char filiacao[20];//nome da mãe ou pai
    char nacionalidade[20];//país
    char naturalidade[20];//estado
    char pis[12];//numero de serie com 11 dígitos
    char ctps[12];//carteira de trabalho
    char escolaridade[50];//fundamental,colegial ou superior completo/incompleto
    char cpf[12];
    char rg[10];
    char eleitor[13];//12 dígitos
    DATA admissao;//data
    char cargo[50];//funcao
    int remuneracao;//salário
}FUNCIONARIO;

//Definindo novo tipo de dado "Cliente"

typedef struct NovoCliente {
    char nomeCompleto[60];
    char cpf[11];
    DATA nascimento;
    char rua[50];
    int num;
    char bairro[50];
    char cidade[50];
    char uf[2];//SP, MG, ES, RJ etc.
    char cep[10];
    char tel[15];
    char email[50];
}CLIENTE;

//Definindo nome de um novo tipo de dado: "produto"
//"produto" irá conter espaço para Nome, Preço e Código de produtos.

typedef struct produto{
    char tipo[50];
    char nome[50];
    float preco;
    int id;
}PRODUTO;

//Função responsável por realizar o cadastro dos usuarios e salvar os dados em arquivo.txt

void MenuPrincipal()
{
    int opc;
    int opcUsuarios;
    do{
        //Aqui ele mostrará esta tela repetidas vezes, até que o úsuario escolha a opção "Sair"
        system("cls");
        opc=0;
        opcUsuarios=0;
        printf("--------------------MENU--------------------\n\n");
        printf("           1 <> Novo Cadastro\n");
        printf("           2 <> Menu Usuarios\n");
        printf("           3 <> Menu Funcionarios\n");
        printf("           4 <> Menu Clientes\n");
        printf("           5 <> Menu Produtos\n");
        printf("           6 <> Desconectar\n");
        printf("           7 <> Sair\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%d",&opc);
        system("cls");
        switch(opc)
        {
            case 1:
            //Aqui existe uma passagem de parametro para que a função Cadastro de Usuários possa ser executada
                MenuCadastros();
                fflush(stdin);
                break;
            case 2:
                opcoesUsuarios();
                system("cls");
                fflush(stdin);
                break;
            case 3:
                opcoesFuncionarios();
                system("cls");
                fflush(stdin);
                break;
            case 4:
                opcoesClientes();
                system("cls");
                fflush(stdin);
                break;
            case 5:
                opcoesProdutos();
                system("cls");
                fflush(stdin);
                break;
            case 6:
                system("cls");
                printf("\n\n\n                      Usuario desconectado.\n\n\n\n\n");
                system("pause");
                system("cls");
                //Login();
                MenuPrincipal();
                break;
            default:
                printf("Opcao invalida!");
                break;
        }

    }while(opc!=7);
    system("cls");
    printf("\n\n\n                      Ate logo\n\n\n\n\n");
    system("pause");

}

void MenuCadastros()
{
    int opc;
    do{
        //Aqui ele mostrará esta tela repetidas vezes, até que o úsuario escolha a opção "Sair"
        system("cls");
        opc=0;
        printf("--------------------CADASTROS--------------------\n\n");
        printf("           1 <> Novo perfil de usuario\n");
        printf("           2 <> Novo registro de funcionario\n");
        printf("           3 <> Novo cadastro de cliente\n");
        printf("           4 <> Inserir novo produto\n");
        printf("           5 <> Voltar\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%d",&opc);
        system("cls");
        switch(opc)
        {
            case (1):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Usuários possa ser executada
                system("cls");
                CadastroU();
                system("cls");
                fflush(stdin);
                break;
            case (2):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Funcionários possa ser executada
                system("cls");
                CadastroF();
                system("cls");
                fflush(stdin);
                break;
            case (3):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Clientes possa ser executada
                system("cls");
                CadastroC();
                system("cls");
                fflush(stdin);
                break;
            case (4):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Produtos possa ser executada
                system("cls");
                CadastroP();
                system("cls");
                fflush(stdin);
                break;
        }
    }while(opc!=5);
}

void CadastroU()
{
    USUARIO users;
    FILE *arqUsuarios;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arqUsuarios = fopen ("D:\\Trabalho\\Gustavo\\Usuarios.txt","ab");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arqUsuarios == NULL)
    {
        puts("Nenhum usuário cadastrado\n");
        fclose(arqUsuarios);
    }
    else
    {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE USUARIO--------------------\n\n");

            fflush (stdin);
            printf("                    Nome: ");
            gets(users.nome);

            fflush (stdin);
            printf("                    Sobrenome: ");
            gets(users.sobreNome);

            fflush (stdin);
            printf("                    Nome de usuario: ");
            gets(users.usuario);

            fflush (stdin);
            printf("                    endereco de email: ");
            gets(users.email);

            fflush (stdin);
            printf("                    senha: ");
            gets(users.senha);

            fwrite(&users, sizeof(USUARIO), 1, arqUsuarios);

            puts("\nUsuario cadastrado!");
        }
    fclose(arqUsuarios);
}

void CadastroF()
{
    FUNCIONARIO funs;
    FILE *arqFuncionarios;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arqFuncionarios = fopen ("D:\\Trabalho\\Gustavo\\Funcionarios.txt","ab");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arqFuncionarios == NULL)
    {
        puts("Nenhum Funcionario cadastrado\n");
        fclose(arqFuncionarios);
    }
    else
    {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE FUNCIONARIO--------------------\n\n");

            fflush (stdin);
            printf("                    Nome: ");
            gets(funs.nome);

            fflush (stdin);
            printf("                    Sobrenome: ");
            gets(funs.sobreNome);

            fflush (stdin);
            printf("                    Data de nascimento: ");
            scanf("%d %d %d", &funs.nascimento.dia, &funs.nascimento.mes, &funs.nascimento.ano);

            fflush (stdin);
            printf("                    Filiacao: ");
            gets(funs.filiacao);

            fflush (stdin);
            printf("                    Nacionalidade: ");
            gets(funs.nacionalidade);

            fflush (stdin);
            printf("                    Naturalidade: ");
            gets(funs.naturalidade);

            fflush (stdin);
            printf("                    Numero de identificacao PIS/PASEP: ");
            gets(funs.pis);

            fflush (stdin);
            printf("                    Carteira de Trabalho e Previdencia Social (CTPS): ");
            gets(funs.ctps);

            fflush (stdin);
            printf("                    Escolaridade: ");
            gets(funs.escolaridade);

            fflush (stdin);
            printf("                    CPF: ");
            gets(funs.cpf);

            fflush (stdin);
            printf("                    RG: ");
            gets(funs.rg);

            fflush (stdin);
            printf("                    Titulo de eleitor: ");
            gets(funs.eleitor);

            fflush (stdin);
            printf("                    Data de admissao: ");
            scanf("%d %d %d", &funs.admissao.dia, &funs.admissao.mes, &funs.admissao.ano);

            fflush (stdin);
            printf("                    Cargo/Funcao: ");
            gets(funs.cargo);

            fflush (stdin);
            printf("                    Remuneracao: ");
            scanf("%d", &funs.remuneracao);

            fwrite(&funs, sizeof(FUNCIONARIO), 1, arqFuncionarios);

            puts("\nFuncionario cadastrado!\n");
            system("pause");

        }
            fclose(arqFuncionarios);
}

void CadastroC()
{
    CLIENTE cli;
    FILE *arqClientes;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arqClientes = fopen ("D:\\Trabalho\\Gustavo\\Clientes.txt","ab");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arqClientes == NULL)
    {
        puts("Nenhum Cliente cadastrado\n");
        fclose(arqClientes);
    }
    else
    {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE CLIENTE--------------------\n\n");

            fflush (stdin);
            printf("                    Nome Completo: ");
            gets(cli.nomeCompleto);

            fflush (stdin);
            printf("                    CPF: ");
            gets(cli.cpf);

            fflush (stdin);
            printf("                    Data de nascimento: ");
            scanf("%d %d %d", &cli.nascimento.dia, &cli.nascimento.mes, &cli.nascimento.ano);

            fflush (stdin);
            printf("                    Endereco: ");
            gets(cli.rua);

            fflush (stdin);
            printf("                    Numero: ");
            scanf("%d",&cli.num);

            fflush (stdin);
            printf("                    Bairro: ");
            gets(cli.bairro);

            fflush (stdin);
            printf("                    Cidade: ");
            gets(cli.cidade);

            fflush (stdin);
            printf("                    UF: ");
            gets(cli.uf);

            fflush (stdin);
            printf("                    CEP: ");
            gets(cli.cep);

            fflush (stdin);
            printf("                    Telefone: ");
            gets(cli.tel);

            fflush (stdin);
            printf("                    Endereco de E-mail: ");
            gets(cli.email);

            fwrite(&cli, sizeof(CLIENTE), 1, arqClientes);

            puts("\nCliente cadastrado!\n");
            system("pause");
        }

        fclose(arqClientes);
        getch();
    }

void CadastroP()
{
    PRODUTO prods;
    FILE *arq;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arq = fopen ("D:\\Trabalho\\Gustavo\\Produtos.txt","ab");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arq == NULL)
    {
        puts("Nenhum produto cadastrado\n");
        fclose(arq);
    }
    else
    {
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE PRODUTOS--------------------\n\n");
            printf("                    Tipo do produto: ");
            fflush (stdin);
            gets(prods.tipo);
            printf("                    Nome do produto: ");
            fflush (stdin);
            gets(prods.nome);
            printf("                    Valor do produto: ");
            fflush (stdin);
            gets(&prods.preco);
            printf("                    Codigo do produto: ");
            fflush (stdin);
            gets(&prods.id);

            fwrite(&prods, sizeof(PRODUTO), 1, arq);

            puts("\nproduto cadastrado!");
            system("pause");
            system("cls");
        }
        fclose(arq);
    }

//Inicio do bloco relacionado a relatórios de usuários
void listarUsuarios(){
    FILE* arqUsuario;
    USUARIO userArq;

    arqUsuario = fopen("D:\\Trabalho\\Gustavo\\Usuarios.txt","rb");

    if(arqUsuario == NULL){
        puts("Nenhum usuario cadastrado...\n");
        system("pause");
        fclose(arqUsuario);
    }
    else {
        puts("--------------------USUARIOS CADASTRADOS--------------------\n\n");
        while(fread(&userArq, sizeof(USUARIO), 1, arqUsuario)==1){
                printf("Nome: %s\n", userArq.nome);
                printf("Sobrenome: %s\n", userArq.sobreNome);
                printf("Usuário: %s\n", userArq.usuario);
                printf("Email: %s\n", userArq.email);
                printf("Senha: %s\n", userArq.senha);
                printf("-------------------------------------\n\n", userArq.nome);
        }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqUsuario);
    getch(); //esta função espera alguma entrada de tecla para sair da tela de lista
}

void procuraUsuarioNome(){
    FILE* arqUsuario;
    USUARIO userArq;

    char userName[30];

    arqUsuario = fopen("D:\\Trabalho\\Gustavo\\Usuarios.txt","rb");



    if(arqUsuario == NULL){
        puts("Nenhum usuario cadastrado...\n");
        fclose(arqUsuario);
    } else {
        fflush(stdin);
        printf("\nDigite o nome a pesquisar: \n\n");
        gets(userName);
        printf("-------------------------------------\n");

        while(fread(&userArq, sizeof(USUARIO), 1, arqUsuario)==1 ){
            if(strcmp(userName, userArq.nome)==0){
                printf("\nNome: %s\n", userArq.nome);
                printf("Sobrenome: %s\n", userArq.sobreNome);
                printf("Usuário: %s\n", userArq.usuario);
                printf("Email: %s\n", userArq.email);
                printf("Senha: %s\n", userArq.senha);
                printf("-------------------------------------\n\n", userArq.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqUsuario);
    getch();
}

void procuraUsuarioSobrenome(){
    FILE* arqUsuario;
    USUARIO userArq;

    char userName[30];

    arqUsuario = fopen("D:\\Trabalho\\Gustavo\\Usuarios.txt","rb");



    if(arqUsuario == NULL){
        puts("Nenhum usuario cadastrado...\n");
        system("pause");
        fclose(arqUsuario);
    } else {
        fflush(stdin);
        printf("\nDigite o Sobrenome a pesquisar: \n\n");
        gets(userName);
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");

        while(fread(&userArq, sizeof(USUARIO), 1, arqUsuario)==1 ){
            if(strcmp(userName, userArq.sobreNome)==0){
                printf("\nNome: %s\n", userArq.nome);
                printf("Sobrenome: %s\n", userArq.sobreNome);
                printf("Usuário: %s\n", userArq.usuario);
                printf("Email: %s\n", userArq.email);
                printf("Senha: %s\n", userArq.senha);
                printf("-------------------------------------\n\n", userArq.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqUsuario);
    getch();
}

void procuraUsuarioLogin(){
    FILE* arqUsuario;
    USUARIO userArq;

    char userName[30];

    arqUsuario = fopen("D:\\Trabalho\\Gustavo\\Usuarios.txt","rb");



    if(arqUsuario == NULL){
        puts("Nenhum usuario cadastrado...\n");
        system("pause");
        fclose(arqUsuario);
    } else {
        fflush(stdin);
        printf("\nDigite o login a pesquisar: \n\n");
        gets(userName);
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");

        while(fread(&userArq, sizeof(USUARIO), 1, arqUsuario)==1 ){
            if(strcmp(userName, userArq.usuario)==0){
                printf("\nNome: %s\n", userArq.nome);
                printf("Sobrenome: %s\n", userArq.sobreNome);
                printf("Usuário: %s\n", userArq.usuario);
                printf("Email: %s\n", userArq.email);
                printf("Senha: %s\n", userArq.senha);
                printf("-------------------------------------\n\n", userArq.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqUsuario);
    getch();
}

void menuUsuarios(){
    printf("-------------MENU REL. USUARIOS-------------\n\n");
    printf("           1 <> Exibir usuarios cadastrados\n");
    printf("           2 <> Procurar por nome\n");
    printf("           3 <> Procurar por sobrenome\n");
    printf("           4 <> Procurar por login\n");
    printf("           5 <> Editar usuario\n");
    printf("           6 <> Voltar\n\n");
    printf("Opcao: ");
    fflush(stdin);
    getch();
}

void opcoesUsuarios(){
int opcaoUsuario=0;

do {
    menuUsuarios();
    scanf("%d", &opcaoUsuario);

    switch (opcaoUsuario){
        case 1:
            system("cls");
            listarUsuarios();
            fflush(stdin);
            system("cls");
            break;
        case 2:
            system("cls");
            procuraUsuarioNome();
            fflush(stdin);
            system("cls");
            break;
        case 3:
            system("cls");
            procuraUsuarioSobrenome();
            fflush(stdin);
            system("cls");
            break;
        case 4:
            system("cls");
            procuraUsuarioLogin();
            fflush(stdin);
            system("cls");
            break;
        case 5:
            system("cls");
            AlterarUsuario();
            fflush(stdin);
            system("cls");
            break;
        }
    }while (opcaoUsuario != 6);
}
//fim do bloco relacionado a usuários

//inicio bloco de códigos relacionados ao menu de funcionários

void menuFuncionarios(){
    printf("-----------MENU REL. FUNCIONÁRIOS-----------\n\n");
    printf("           1 <> Exibir funcionarios cadastrados\n");
    printf("           2 <> Procurar por nome\n");
    printf("           3 <> Procurar por sobrenome\n");
    printf("           4 <> Listar aniversariantes do mes\n");
    printf("           5 <> Listar por data de admissao\n");
    printf("           6 <> Editar funcionario\n");
    printf("           7 <> Voltar\n\n");
    printf("Opcao: ");
    fflush(stdin);
    getch();
}

void opcoesFuncionarios(){
int opcaoFuns=0;

do {
    menuFuncionarios();
    scanf("%d", &opcaoFuns);

    switch (opcaoFuns){
        case 1:
            system("cls");
            listarFuncionarios();
            fflush(stdin);
            system("cls");
            break;
        case 2:
            system("cls");
            procuraFuncionarioNome();
            fflush(stdin);
            system("cls");
            break;

        case 3:
            system("cls");
            procuraFuncionarioSobrenome();
            fflush(stdin);
            system("cls");
            break;

        case 4:
            system("cls");
            procuraAniversariantes();
            fflush(stdin);
            system("cls");
            break;

        case 5:
            system("cls");
            listarAdmissao();
            system("cls");
            fflush(stdin);
            break;

        case 6:
            system("cls");
            AlterarFuncionario();
            system("cls");
            fflush(stdin);
            break;
        }
    }while (opcaoFuns != 7);
}

void listarFuncionarios(){
    FILE* arqFuns;
    FUNCIONARIO funs;

    arqFuns = fopen("D:\\Trabalho\\Gustavo\\Funcionarios.txt","rb");

    if(arqFuns == NULL){
        puts("Nenhum funcionario cadastrado...\n");
        system("pause");
        fclose(arqFuns);
    }
    else {
        puts("-----------FUNCIONÁRIOS CADASTRADOS-----------\n\n");
        while(fread(&funs, sizeof(FUNCIONARIO), 1, arqFuns)==1){
                printf("Nome: %s\n", funs.nome);
                printf("Sobrenome: %s\n", funs.sobreNome);
                printf("Data de nascimento: %d/%d/%d\n", funs.nascimento.dia, funs.nascimento.mes, funs.nascimento.ano);
                printf("Filiação: %s\n", funs.filiacao);
                printf("Nacionalidade: %d\n", funs.nacionalidade);
                printf("Naturalidade: ", funs.naturalidade);
                printf("PIS: %s\n", funs.pis);
                printf("CTPS: %s\n", funs.ctps);
                printf("Escolaridade: %s\n", funs.escolaridade);
                printf("CPF: %s\n", funs.cpf);
                printf("RG: %d\n", funs.rg);
                printf("Titulo de eleitor: %s\n", funs.eleitor);
                printf("Admissao: %d/%d/%d\n", funs.admissao.dia, funs.admissao.mes, funs.admissao.ano);
                printf("Cargo: %s\n", funs.cargo);
                printf("Remuneração: R$%d\n", funs.remuneracao);
                printf("-------------------------------------\n\n", funs.nome);
        }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqFuns);
    getch(); //esta função espera alguma entrada de tecla para sair da tela de lista
}

void procuraFuncionarioNome(){
    FILE* arqFuns;
    FUNCIONARIO funs;

    char funsNome[30];

    arqFuns = fopen("D:\\Trabalho\\Gustavo\\Funcionarios.txt","rb");



    if(arqFuns == NULL){
        puts("Nenhum funcionario cadastrado...\n");
        system("pause");
        fclose(arqFuns);
    } else {
        puts("-----------FUNCIONÁRIOS CADASTRADOS-----------\n\n");
        fflush(stdin);
        printf("\nDigite o nome a pesquisar: \n\n");
        gets(funsNome);
        puts("-----------FUNCIONÁRIOS CADASTRADOS-----------\n\n");

        while(fread(&funs, sizeof(FUNCIONARIO), 1, arqFuns)==1 ){
            if(strcmp(funsNome, funs.nome)==0){
                printf("Nome: %s\n", funs.nome);
                printf("Sobrenome: %s\n", funs.sobreNome);
                printf("Data de nascimento: %d/%d/%d\n", funs.nascimento.dia, funs.nascimento.mes, funs.nascimento.ano);
                printf("Filiação: %s\n", funs.filiacao);
                printf("Nacionalidade: %d\n", funs.nacionalidade);
                printf("Naturalidade: ", funs.naturalidade);
                printf("PIS: %s\n", funs.pis);
                printf("CTPS: %s\n", funs.ctps);
                printf("Escolaridade: %s\n", funs.escolaridade);
                printf("CPF: %s\n", funs.cpf);
                printf("RG: %d\n", funs.rg);
                printf("Titulo de eleitor: %s\n", funs.eleitor);
                printf("Admissao: %d/%d/%d\n", funs.admissao.dia, funs.admissao.mes, funs.admissao.ano);
                printf("Cargo: %s\n", funs.cargo);
                printf("Remuneração: R$%d\n", funs.remuneracao);
                printf("-------------------------------------\n\n", funs.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqFuns);
    getch();
}

void procuraFuncionarioSobrenome(){
    FILE* arqFuns;
    FUNCIONARIO funs;

    char funsNome[30];

    arqFuns = fopen("D:\\Trabalho\\Gustavo\\Funcionarios.txt","rb");



    if(arqFuns == NULL){
        puts("Nenhum funcionario cadastrado...\n");
        system("pause");
        fclose(arqFuns);
    } else {
        fflush(stdin);
        printf("\nDigite o Sobrenome a pesquisar: \n\n");
        gets(funsNome);
        puts("-------------FUNCIONÁRIOS CADASTRADOS-------------\n\n");

        while(fread(&funs, sizeof(FUNCIONARIO), 1, arqFuns)==1 ){
            if(strcmp(funsNome, funs.sobreNome)==0){
                printf("Nome: %s\n", funs.nome);
                printf("Sobrenome: %s\n", funs.sobreNome);
                printf("Data de nascimento: %d/%d/%d\n", funs.nascimento.dia, funs.nascimento.mes, funs.nascimento.ano);
                printf("Filiação: %s\n", funs.filiacao);
                printf("Nacionalidade: %d\n", funs.nacionalidade);
                printf("Naturalidade: ", funs.naturalidade);
                printf("PIS: %s\n", funs.pis);
                printf("CTPS: %s\n", funs.ctps);
                printf("Escolaridade: %s\n", funs.escolaridade);
                printf("CPF: %s\n", funs.cpf);
                printf("RG: %d\n", funs.rg);
                printf("Titulo de eleitor: %s\n", funs.eleitor);
                printf("Admissao: %d/%d/%d\n", funs.admissao.dia, funs.admissao.mes, funs.admissao.ano);
                printf("Cargo: %s\n", funs.cargo);
                printf("Remuneração: R$%d\n", funs.remuneracao);
                printf("-------------------------------------\n\n", funs.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqFuns);
    getch();
}

void procuraAniversariantes(){
    FILE* arqFuns;
    FUNCIONARIO funs;

    arqFuns = fopen("D:\\Trabalho\\Gustavo\\Funcionarios.txt","rb");

    int mes=0;


    if(arqFuns == NULL){
        puts("Nenhum funcionario cadastrado...\n");
        system("pause");
        fclose(arqFuns);
    } else {
        fflush(stdin);
        printf("\nDigite o mês de aniversário: \n\n");
        scanf("%d", &mes);
        puts("-----------FUNCIONÁRIOS CADASTRADOS-----------\n\n");

        while(fread(&funs, sizeof(FUNCIONARIO), 1, arqFuns)==1 ){
            if(mes == funs.nascimento.mes){
                printf("Nome: %s\n", funs.nome);
                printf("Sobrenome: %s\n", funs.sobreNome);
                printf("Data de nascimento: %d/%d/%d\n", funs.nascimento.dia, funs.nascimento.mes, funs.nascimento.ano);
                printf("Filiação: %s\n", funs.filiacao);
                printf("Nacionalidade: %d\n", funs.nacionalidade);
                printf("Naturalidade: ", funs.naturalidade);
                printf("PIS: %s\n", funs.pis);
                printf("CTPS: %s\n", funs.ctps);
                printf("Escolaridade: %s\n", funs.escolaridade);
                printf("CPF: %s\n", funs.cpf);
                printf("RG: %d\n", funs.rg);
                printf("Titulo de eleitor: %s\n", funs.eleitor);
                printf("Admissao: %d/%d/%d\n", funs.admissao.dia, funs.admissao.mes, funs.admissao.ano);
                printf("Cargo: %s\n", funs.cargo);
                printf("Remuneração: R$%d\n", funs.remuneracao);
                printf("-------------------------------------\n\n", funs.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqFuns);
    getch();
}

void listarAdmissao(){
    FILE* arqFuns;
    FUNCIONARIO funs;

    arqFuns = fopen("D:\\Trabalho\\Gustavo\\Funcionarios.txt","rb");

    int mes=0;


    if(arqFuns == NULL){
        puts("Nenhum funcionario cadastrado...\n");
        system("pause");
        fclose(arqFuns);
    } else {
        fflush(stdin);
        printf("\nDigite o mês de admissão: \n\n");
        scanf("%d", &mes);
        puts("-------------FUNCIONÁRIOS CADASTRADOS-------------\n\n");

        while(fread(&funs, sizeof(FUNCIONARIO), 1, arqFuns)==1 ){
            if(mes == funs.admissao.mes){
                printf("Nome: %s\n", funs.nome);
                printf("Sobrenome: %s\n", funs.sobreNome);
                printf("Data de nascimento: %d/%d/%d\n", funs.nascimento.dia, funs.nascimento.mes, funs.nascimento.ano);
                printf("Filiação: %s\n", funs.filiacao);
                printf("Nacionalidade: %d\n", funs.nacionalidade);
                printf("Naturalidade: ", funs.naturalidade);
                printf("PIS: %s\n", funs.pis);
                printf("CTPS: %s\n", funs.ctps);
                printf("Escolaridade: %s\n", funs.escolaridade);
                printf("CPF: %s\n", funs.cpf);
                printf("RG: %d\n", funs.rg);
                printf("Titulo de eleitor: %s\n", funs.eleitor);
                printf("Admissao: %d/%d/%d\n", funs.admissao.dia, funs.admissao.mes, funs.admissao.ano);
                printf("Cargo: %s\n", funs.cargo);
                printf("Remuneração: R$%d\n", funs.remuneracao);
                printf("-------------------------------------\n\n", funs.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqFuns);
    getch();
}
//fim do bloco de códigos de funcionários

//inicio do bloco de códigos de clientes
void menuClientes(){
    system("cls");
    printf("-------------MENU REL. CLIENTES-------------\n\n");
    printf("           1 <> Exibir clientes cadastrados\n");
    printf("           2 <> Procurar por nome\n");
    printf("           3 <> Procurar por CPF\n");
    printf("           4 <> Listar aniversariantes do mes\n");
    printf("           5 <> Listar por cidade\n");
    printf("           6 <> Editar cliente\n");
    printf("           7 <> Voltar\n\n");
    printf("Opcao: ");
    fflush(stdin);
    getch();
}

void opcoesClientes(){
int opcaoCli=0;

do {
    menuClientes();
    scanf("%d", &opcaoCli);

    switch (opcaoCli){
        case 1:
            system("cls");
            listarClientes();
            fflush(stdin);
            system("cls");
            break;
        case 2:
            system("cls");
            procuraClienteNome();
            fflush(stdin);
            system("cls");
            break;

        case 3:
            system("cls");
            procuraClienteCPF();
            fflush(stdin);
            system("cls");
            break;

        case 4:
            system("cls");
            procuraClientesAniversariantes();
            fflush(stdin);
            system("cls");
            break;

        case 5:
            system("cls");
            listarPorCidade();
            system("cls");
            fflush(stdin);
            break;

        case 6:
            system("cls");
            AlterarCliente();
            system("cls");
            fflush(stdin);
            break;
        }
    }while (opcaoCli != 7);
}

void listarClientes(){
    FILE* arqCli;
    CLIENTE clis;

    arqCli = fopen("D:\\Trabalho\\Gustavo\\Clientes.txt","rb");

    if(arqCli == NULL){
        puts("Nenhum cliente cadastrado...\n");
        system("cls");
        fclose(arqCli);
    }
    else {
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");
        while(fread(&clis, sizeof(CLIENTE), 1, arqCli)==1){
                printf("Nome: %s\n", clis.nomeCompleto);
                printf("CPF: %s\n", clis.cpf);
                printf("Data de nascimento: %d/%d/%d\n", clis.nascimento.dia, clis.nascimento.mes, clis.nascimento.ano);
                printf("Rua: %s\n", clis.rua);
                printf("Número: %d\n", clis.num);
                printf("Bairro: ", clis.bairro);
                printf("Cidade: %s\n", clis.cidade);
                printf("Estado(UF): %s\n", clis.uf);
                printf("CEP: %s\n", clis.cep);
                printf("CPF: %s\n", clis.cpf);
                printf("Telefone: %s\n", clis.tel);
                printf("E-mail: %s\n", clis.email);
                printf("-------------------------------------\n\n", clis.nomeCompleto);
        }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqCli);
    getch(); //esta função espera alguma entrada de tecla para sair da tela de lista
}

void procuraClienteNome(){
    FILE* arqCli;
    CLIENTE clis;

    char cliNome[50];

    arqCli = fopen("D:\\Trabalho\\Gustavo\\Clientes.txt","rb");



    if(arqCli == NULL){
        puts("Nenhum cliente cadastrado...\n");
        system("pause");
        fclose(arqCli);
    } else {
        fflush(stdin);
        printf("\nDigite o nome a pesquisar: \n\n");
        gets(cliNome);
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");

        while(fread(&clis, sizeof(CLIENTE), 1, arqCli)==1 ){
            if(strcmp(cliNome, clis.nomeCompleto)==0){
                printf("Nome: %s\n", clis.nomeCompleto);
                printf("CPF: %s\n", clis.cpf);
                printf("Data de nascimento: %d/%d/%d\n", clis.nascimento.dia, clis.nascimento.mes, clis.nascimento.ano);
                printf("Rua: %s\n", clis.rua);
                printf("Número: %d\n", clis.num);
                printf("Bairro: ", clis.bairro);
                printf("Cidade: %s\n", clis.cidade);
                printf("Estado(UF): %s\n", clis.uf);
                printf("CEP: %s\n", clis.cep);
                printf("CPF: %s\n", clis.cpf);
                printf("Telefone: %s\n", clis.tel);
                printf("E-mail: %s\n", clis.email);
                printf("-------------------------------------\n\n", clis.nomeCompleto);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqCli);
    getch();
}

void procuraClienteCPF(){
    FILE* arqCli;
    CLIENTE clis;

    char clisCPF[30];

    arqCli = fopen("D:\\Trabalho\\Gustavo\\Clientes.txt","rb");

    if(arqCli == NULL){
        puts("Nenhum cliente cadastrado...\n");
        system("pause");
        fclose(arqCli);
    } else {
        fflush(stdin);
        printf("\nDigite o CPF a pesquisar: \n\n");
        gets(clisCPF);
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");

        while(fread(&clis, sizeof(CLIENTE), 1, arqCli)==1 ){
            if(strcmp(clisCPF, clis.cpf)==0){
                printf("Nome: %s\n", clis.nomeCompleto);
                printf("CPF: %s\n", clis.cpf);
                printf("Data de nascimento: %d/%d/%d\n", clis.nascimento.dia, clis.nascimento.mes, clis.nascimento.ano);
                printf("Rua: %s\n", clis.rua);
                printf("Número: %d\n", clis.num);
                printf("Bairro: ", clis.bairro);
                printf("Cidade: %s\n", clis.cidade);
                printf("Estado(UF): %s\n", clis.uf);
                printf("CEP: %s\n", clis.cep);
                printf("CPF: %s\n", clis.cpf);
                printf("Telefone: %s\n", clis.tel);
                printf("E-mail: %s\n", clis.email);
                printf("-------------------------------------\n\n", clis.nomeCompleto);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqCli);
    getch();
}

void procuraClientesAniversariantes(){
    FILE* arqCli;
    CLIENTE clis;

    arqCli = fopen("D:\\Trabalho\\Gustavo\\Clientes.txt","rb");

    int cliMes=0;


    if(arqCli == NULL){
        puts("Nenhum cliente cadastrado...\n");
        system("pause");
        fclose(arqCli);
    } else {
        fflush(stdin);
        printf("\nDigite o mês de aniversário: \n\n");
        scanf("%d", &cliMes);
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");

        while(fread(&clis, sizeof(CLIENTE), 1, arqCli)==1 ){
            if(cliMes == clis.nascimento.mes){
                printf("Nome: %s\n", clis.nomeCompleto);
                printf("CPF: %s\n", clis.cpf);
                printf("Data de nascimento: %d/%d/%d\n", clis.nascimento.dia, clis.nascimento.mes, clis.nascimento.ano);
                printf("Rua: %s\n", clis.rua);
                printf("Número: %d\n", clis.num);
                printf("Bairro: ", clis.bairro);
                printf("Cidade: %s\n", clis.cidade);
                printf("Estado(UF): %s\n", clis.uf);
                printf("CEP: %s\n", clis.cep);
                printf("CPF: %s\n", clis.cpf);
                printf("Telefone: %s\n", clis.tel);
                printf("E-mail: %s\n", clis.email);
                printf("-------------------------------------\n\n", clis.nomeCompleto);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqCli);
    getch();
}

void listarPorCidade(){
    FILE* arqCli;
    CLIENTE clis;

    arqCli = fopen("D:\\Trabalho\\Gustavo\\Clientes.txt","rb");

    char cliCidade[30];


    if(arqCli == NULL){
        puts("Nenhum cliente cadastrado...\n");
        system("pause");
        fclose(arqCli);
    } else {
        fflush(stdin);
        printf("\nDigite a cidade: \n\n");
        scanf("%d", &cliCidade);
        puts("-------------CLIENTES CADASTRADOS-------------\n\n");

        while(fread(&clis, sizeof(FUNCIONARIO), 1, arqCli)==1 ){
            if(strcmp(cliCidade, clis.cidade)==0){
               printf("Nome: %s\n", clis.nomeCompleto);
                printf("CPF: %s\n", clis.cpf);
                printf("Data de nascimento: %d/%d/%d\n", clis.nascimento.dia, clis.nascimento.mes, clis.nascimento.ano);
                printf("Rua: %s\n", clis.rua);
                printf("Número: %d\n", clis.num);
                printf("Bairro: ", clis.bairro);
                printf("Cidade: %s\n", clis.cidade);
                printf("Estado(UF): %s\n", clis.uf);
                printf("CEP: %s\n", clis.cep);
                printf("CPF: %s\n", clis.cpf);
                printf("Telefone: %s\n", clis.tel);
                printf("E-mail: %s\n", clis.email);
                printf("-------------------------------------\n\n", clis.nomeCompleto);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqCli);
    getch();
}
//fim do bloco de código de relatórios clientes

//inicio bloco de código de relatórios produtos
void menuProdutos(){
    system("cls");
    printf("--------------MENU REL. PRODUTOS--------------\n\n");
    printf("           1 <> Exibir produtos cadastrados\n");
    printf("           2 <> Listar por tipo\n");
    printf("           3 <> Procurar por nome\n");
    printf("           4 <> Procurar por ID\n");
    printf("           5 <> Editar produto\n");
    printf("           6 <> Voltar\n\n");
    printf("Opcao: ");
    fflush(stdin);
    getch();
}

void opcoesProdutos(){
int opcaoProd=0;

do {
    menuProdutos();
    scanf("%d", &opcaoProd);

    switch (opcaoProd){
        case 1:
            system("cls");
            listarProdutos();
            fflush(stdin);
            system("cls");
            break;
        case 2:
            system("cls");
            listarProdutosTipo();
            fflush(stdin);
            system("cls");
            break;

        case 3:
            system("cls");
            procuraProdutoNome();
            fflush(stdin);
            system("cls");
            break;

        case 4:
            system("cls");
            procuraProdutoPorId();
            fflush(stdin);
            system("cls");
            break;

        case 5:
            system("cls");
            AlterarProduto();
            fflush(stdin);
            system("cls");
        }
    }while (opcaoProd != 6);
}

void listarProdutos(){
    FILE* arqProd;
    PRODUTO prods;

    arqProd = fopen("D:\\Trabalho\\Gustavo\\Produtos.txt","rb");

    if(arqProd == NULL){
        puts("Nenhum produto cadastrado...\n");
        system("pause");
        fclose(arqProd);
    }
    else {
        puts("-------------PRODUTOS CADASTRADOS-------------\n\n");
        while(fread(&prods, sizeof(PRODUTO), 1, arqProd)==1){
                printf("Tipo: %s\n", prods.tipo);
                printf("Nome: %s\n", prods.nome);
                printf("Preço: R$%f\n", prods.preco);
                printf("Código: %d\n", prods.id);
                printf("-------------------------------------\n\n", prods.nome);
        }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqProd);
    getch(); //esta função espera alguma entrada de tecla para sair da tela de lista
}

void listarProdutosTipo(){
    FILE* arqProd;
    PRODUTO prods;

    char prodTipo[50];

    arqProd = fopen("D:\\Trabalho\\Gustavo\\Produtos.txt","rb");

    if(arqProd == NULL){
        puts("Nenhum produto cadastrado...\n");
        system("pause");
        fclose(arqProd);
    } else {
        fflush(stdin);
        printf("\nDigite o tipo do produto a pesquisar: \n\n");
        gets(prodTipo);
        puts("-------------PRODUTOS CADASTRADOS-------------\n\n");

        while(fread(&prods, sizeof(PRODUTO), 1, arqProd)==1 ){
            if(strcmp(prodTipo, prods.tipo)==0){
                printf("Tipo: %s\n", prods.tipo);
                printf("Nome: %s\n", prods.nome);
                printf("Preço: R$%f\n", prods.preco);
                printf("Código: %d\n", prods.id);
                printf("-------------------------------------\n\n", prods.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqProd);
    getch();
}

void procuraProdutoNome(){
    FILE* arqProd;
    PRODUTO prods;

    char prodNome[50];

    arqProd = fopen("D:\\Trabalho\\Gustavo\\Produtos.txt","rb");


    if(arqProd == NULL){
        puts("Nenhum produto cadastrado...\n");
        system("pause");
        fclose(arqProd);
    } else {
        fflush(stdin);
        printf("\nDigite o nome do produto a pesquisar: \n\n");
        gets(prodNome);
        puts("-------------PRODUTOS CADASTRADOS-------------\n\n");

        while(fread(&prods, sizeof(PRODUTO), 1, arqProd)==1 ){
            if(strcmp(prodNome, prods.nome)==0){
                printf("Tipo: %s\n", prods.tipo);
                printf("Nome: %s\n", prods.nome);
                printf("Preço: R$%f\n", prods.preco);
                printf("Código: %d\n", prods.id);
                printf("-------------------------------------\n\n", prods.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
        }
    fclose(arqProd);
    getch();
}

void procuraProdutoPorId(){
    FILE* arqProd;
    PRODUTO prods;

    arqProd = fopen("D:\\Trabalho\\Gustavo\\Produtos.txt","rb");

    int prodId=0;


    if(arqProd == NULL){
        puts("Nenhum produto cadastrado...\n");
        system("pause");
        fclose(arqProd);
    } else {
        fflush(stdin);
        printf("\nDigite o código do produto: \n\n");
        scanf("%d", &prodId);
        puts("-------------PRODUTOS CADASTRADOS-------------\n\n");

        while(fread(&prods, sizeof(PRODUTO), 1, arqProd)==1 ){
            if(prodId == prods.id){
                printf("Tipo: %s\n", prods.tipo);
                printf("Nome: %s\n", prods.nome);
                printf("Preço: R$%f\n", prods.preco);
                printf("Código: %d\n", prods.id);
                printf("-------------------------------------\n\n", prods.nome);
               }
            }
        puts("Fim da lista!");
        puts("Pressione qualquer tecla para retornar ao menu anterior.");
    }
    fclose(arqProd);
    getch();
}


//ALTERAÇÃO DE DADOS DE USUARIOS

void AlterarUsuario()
{
    FILE *arquivo = fopen("D:\\Trabalho\\Gustavo\\Usuarios.txt","rb+");
    USUARIO user;
    int i = 1, id;

    if(arquivo)
    {
        printf("--------------------USUARIOS CADASTRADOS--------------------\n\n");
        while(fread(&user, sizeof(USUARIO), 1, arquivo))
        {
            printf("(%i)\n\tNome: %s\n\tSobrenome: %s\n\tUsuario: %s\n\tEmail: %s\n\tSenha: %s\n\n", i, user.nome, user.sobreNome, user.usuario, user.email, user.senha);
            i++;
        }
        printf("\n------------------------------------------------------------\n\n");
        printf("Informe o numero do usuario que deseja alterar: ");
        scanf("%i",&id);
        fflush(stdin);
        id--;
        if(id >= 0 && id < i - 1)
        {
            system("cls");
            puts("--------------------EDICAO DE USUARIO--------------------\n\n");
            printf("                  Novo* Nome: ");
            gets(user.nome);
            printf("                  Novo* Sobrenome: ");
            gets(user.sobreNome);
            printf("                  Novo* Usuário: ");
            gets(user.usuario);
            printf("                  Novo* Email: ");
            gets(user.email);
            printf("                  Nova* Senha: ");
            gets(user.senha);
            fseek(arquivo, id * sizeof(USUARIO), SEEK_SET);
            fwrite(&user, sizeof(USUARIO), 1, arquivo);
        }
        fclose(arquivo);
    }
    else
    {
        system("cls");
        puts("Nenhum usuario cadastrado...\n");
        system("pause");
    }
}

//ALTERAÇÃO DE DADOS DE FUNCIONARIO

void AlterarFuncionario()
{
    FILE *arquivo = fopen("D:\\Trabalho\\Gustavo\\Funcionarios.txt","rb+");
    FUNCIONARIO funs;
    int i = 1, id;

    if(arquivo)
    {
        printf("--------------------FUNCIONARIOS CADASTRADOS--------------------\n\n");
        while(fread(&funs, sizeof(FUNCIONARIO), 1, arquivo))
        {
            printf("(%i)\n\tNome: %s\n\tSobrenome: %s\n\tData de nascimento: %d/%d/%d\n\tFiliacao: %s\n\tNacionalidade: %s\n\tNaturalidade: %s\n\tNumero de identificacao PIS/PASEP: %s\n\tCarteira de Trabalho e Previdencia Social (CTPS): %s\n\tEscolaridade: %s\n\tCPF: %s\n\tRG: %s\n\tTitulo de eleitor: %s\n\tData de admissao: %d/%d/%d\n\tCargo/Funcao: %s\n\tremuneracao: %d\n\n", i, funs.nome, funs.sobreNome, funs.nascimento.dia, funs.nascimento.mes, funs.nascimento.ano, funs.pis, funs.ctps, funs.escolaridade, funs.cpf, funs.rg, funs.eleitor, funs.admissao.dia, funs.admissao.mes, funs.admissao.ano);
            i++;
        }
        printf("\n------------------------------------------------------------\n\n");
        printf("Informe o numero do Funcionario que deseja alterar: ");
        scanf("%i",&id);
        fflush(stdin);
        id--;
        if(id >= 0 && id < i - 1)
        {
            system("cls");
            puts("--------------------EDICAO DE FUNCIONARIO--------------------\n\n");
            printf("                  Novo* Nome: ");
            gets(funs.nome);
            printf("                  Novo* Sobrenome: ");
            gets(funs.sobreNome);
            printf("                  Nova* Data de nascimento: ");
            scanf("%d %d %d", &funs.nascimento.dia, &funs.nascimento.mes, &funs.nascimento.ano);
            printf("                  Nova* Filiacao: ");
            gets(funs.filiacao);
            printf("                  Nova* Nacionalidade: ");
            gets(funs.nacionalidade);
            printf("                  Nova* Naturalidade: ");
            gets(funs.naturalidade);
            printf("                  Nova* Numero de identificacao PIS/PASEP: ");
            gets(funs.pis);
            printf("                  Nova* Carteira de Trabalho e Previdencia Social (CTPS): ");
            gets(funs.ctps);
            printf("                  Nova* Escolaridade: ");
            gets(funs.escolaridade);
            printf("                  Novo* CPF: ");
            gets(funs.cpf);
            printf("                  Novo* RG: ");
            gets(funs.rg);
            printf("                  Novo* Titulo de eleitor: ");
            gets(funs.eleitor);
            printf("                  Nova* Data de admissao: ");
            scanf("%d %d %d", &funs.admissao.dia, &funs.admissao.mes, &funs.admissao.ano);
            printf("                  Novo* Cargo/Funcao: ");
            gets(funs.cargo);
            printf("                  Nova* remuneracao: ");
            scanf("%f",&funs.remuneracao);
            fseek(arquivo, id * sizeof(FUNCIONARIO), SEEK_SET);
            fwrite(&funs, sizeof(FUNCIONARIO), 1, arquivo);
        }
        fclose(arquivo);
    }
    else
    {
        system("cls");
        puts("Nenhum funcionario cadastrado...\n");
        system("pause");
    }
}

//ALTERAÇÃO DE DADOS DE CLIENTES

void AlterarCliente()
{
    FILE *arquivo = fopen("D:\\Trabalho\\Gustavo\\Clientes.txt","rb+");
    CLIENTE cli;
    int i = 1, id;

    if(arquivo)
    {
        printf("--------------------CLIENTES CADASTRADOS--------------------\n\n");
        while(fread(&cli, sizeof(CLIENTE), 1, arquivo))
        {
            printf("(%i)\n\tNome completo: %s\n\tCPF: %s\n\tData de nascimento: %d/%d/%d\n\tEndereco: %s\n\tNumero: %d\n\tBairro: %s\n\tCidade: %s\n\tCEP: %s\n\tUF: %s\n\tTelefone: %s\n\tE-mail: %s\n\n", i, cli.nomeCompleto, cli.cpf, cli.nascimento.dia, cli.nascimento.mes, cli.nascimento.ano, cli.rua, cli.num, cli.bairro, cli.cidade, cli.cep, cli.uf, cli.tel, cli.email);
            i++;
        }
        printf("\n------------------------------------------------------------\n\n");
        printf("Informe o numero do cliente que deseja alterar: ");
        scanf("%i",&id);
        fflush(stdin);
        id--;
        if(id >= 0 && id < i - 1)
        {
            system("cls");
            puts("--------------------EDICAO DE CLIENTE--------------------\n\n");
            printf("                  Novo* Nome completo: ");
            gets(cli.nomeCompleto);
            printf("                  Novo* CPF: ");
            gets(cli.cpf);
            printf("                  Nova* Data de nascimento: ");
            scanf("%d %d %d", &cli.nascimento.dia, &cli.nascimento.dia, &cli.nascimento.dia);
            printf("                  Novo* Endereco: ");
            gets(cli.rua);
            printf("                  Nova* Numero: ");
            scanf("%d",&cli.num);
            printf("                  Novo* Bairro: ");
            gets(cli.bairro);
            printf("                  Nova* Cidade: ");
            gets(cli.cidade);
            printf("                  Novo* Estado(UF): ");
            gets(cli.uf);
            printf("                  Novo* CEP: ");
            gets(cli.cep);
            printf("                  Novo* Telefone: ");
            gets(cli.tel);
            printf("                  Novo* Endereco de E-mail: ");
            gets(cli.email);
            fseek(arquivo, id * sizeof(CLIENTE), SEEK_SET);
            fwrite(&cli, sizeof(CLIENTE), 1, arquivo);
        }
        fclose(arquivo);
    }
    else
    {
        system("cls");
        puts("Nenhum cliente cadastrado...\n");
        system("pause");
    }
}

//ALTERAÇÃO DE DADOS DE PRODUTOS

void AlterarProduto()
{
    FILE *arquivo = fopen("D:\\Trabalho\\Gustavo\\Produtos.txt","rb+");
    PRODUTO prods;
    int i = 1, id;

    if(arquivo)
    {
        printf("--------------------PRODUTOS CADASTRADOS--------------------\n\n");
        while(fread(&prods, sizeof(PRODUTO), 1, arquivo))
        {
            printf("(%i)\n\tTipo: %s\n\tNome: %s\n\tValor: %f\n\tID: %d\n\n", i, prods.tipo, prods.nome, prods.preco, prods.id);
            i++;
        }
        printf("\n------------------------------------------------------------\n\n");
        printf("Informe o numero do produto que deseja alterar: ");
        scanf("%i",&id);
        fflush(stdin);
        id--;
        if(id >= 0 && id < i - 1)
        {
            system("cls");
            puts("--------------------EDICAO DE PRODUTO--------------------\n\n");
            printf("                  Novo* Tipo: ");
            gets(prods.tipo);
            printf("                  Novo* Nome: ");
            gets(prods.nome);
            printf("                  Novo* Valor: ");
            scanf("%f",&prods.preco);
            printf("                  Novo* Codigo: ");
            scanf("%d",&prods.id);
            fseek(arquivo, id * sizeof(PRODUTO), SEEK_SET);
            fwrite(&prods, sizeof(PRODUTO), 1, arquivo);
        }
        fclose(arquivo);
    }
    else
    {
        system("cls");
        puts("Nenhum produto cadastrado...\n");
        system("pause");
    }
}

//A função de Login ainda não está definada corretamente

/*
int verificaUsuario(char login){
    FILE* arqUsuario;
    USUARIO user;


    arqUsuario = fopen("Usuario.txt", "r");

        while(fread(&user, sizeof(USUARIO), 1, arqUsuario)== 1 ){
            if(strcmp(login, user.usuario)==0){
                return 1;
               }
               else {
                return 0;
               }
            }
    fclose(arqUsuario);
    getch();
}



int validaSenha(char senha){
   FILE* arqUsuario;
   USUARIO user;

    arqUsuario = fopen("Usuario.txt", "r");
        while(fread(&user, sizeof(USUARIO), 1, arqUsuario)== 1 ){
            if(strcmp(senha, user.senha)==0){
                return 1;
               }
               else {
                return 0;
               }
            }
    fclose(arqUsuario);
    getch();
}


void Login()
{
    system("cls");
    char usu[50], senha[50];
    int usuarioLogado = 0;
    USUARIO userArq;

    FILE *arq;
    arq = fopen("Usuarios.txt","rb");

    printf("--------------------TELA DE LOGIN--------------------\n\n");
    printf("\n                  <> Usuario: ");
    scanf("%s",&usu);
    printf("\n                  <> Senha: ");
    scanf("%s",&senha);

    if(arq == NULL)
    {
        puts("Não foi possível abrir o arquivo!\n");
        exit(0);
    }
    else
    {
        fflush(stdin);
        while(fread(&userArq, sizeof(USUARIO), 1, arq)==1 )
        {
            if (strcmp(usu, userArq.usuario)==0)
                {
                    system("cls");
                    printf("\n\n\n                      Ola %s \n\n\n\n\n",userArq.nome);
                    system("pause");
                    system("cls");
                    usuarioLogado = 1;
                }
                else{
                        do{
                        system("cls");
                        printf("\n\n\nUsuario e/ou senha incorretos!\n\n\n\n\n");
                        system("pause");
                        system("cls");
                        printf("--------------------TELA DE LOGIN--------------------\n\n");
                        printf("\n                  <> Usuario: ");
                        scanf("%s",&usu);
                        printf("\n                  <> Senha: ");
                        scanf("%s",&senha);

                        if (strcmp(usu, userArq.usuario)==0)
                        {
                            system("cls");
                            printf("\n\n\n                      Ola %s \n\n\n\n\n",userArq.nome);
                            system("pause");
                            system("cls");
                            usuarioLogado = 1;}
                    else{
                        usuarioLogado = 0;
                    }
                    } while(usuarioLogado != 1);
            }
        }
        fclose(arq);
    }
}*/
