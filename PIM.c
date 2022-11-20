#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definindo novo tipo de dado "Usuário"

typedef struct NovoUsuario {
    char nome[20];
    char sobreNome[20];
    char usuario[50];
    char email[50];
    char senha[50];
}usuario;

//Definindo novo tipo de dado "Funcionário"

typedef struct NovoFuncionario {
    char nome[20];
    char sobreNome[20];
    char nascimento[10];//data
    char filiacao[20];//nome da mãe ou pai
    char nacionalidade[20];//país
    char naturalidade[3];//estado
    char pis[12];//numero de serie com 11 dígitos
    char ctps[12];//carteira de trabalho
    char escolaridade[50];//fundamental,colegial ou superior completo/incompleto
    char cpf[12];
    char rg[10];
    char eleitor[13];//12 dígitos
    char admisao[10];//data
    char cargo[50];//funcao
    float remuneracao;//salário
}funcionario;

//Definindo novo tipo de dado "Cliente"

typedef struct NovoCliente {
    char nomeCompleto[60];
    char cpf[11];
    char nascimento[11];
    char rua[50];
    int num;
    char bairro[50];
    char cidade[50];
    char tel[15];
    char email[50];
}cliente;

//Definindo nome de um novo tipo de dado: "produto"
//"produto" irá conter espaço para Nome, Preço e Código de produtos.

typedef struct {
    char tipo[50];
    char nome[50];
    float preco;
    int id;
}produto;

//Função responsável por realizar o cadastro dos usuarios e salvar os dados em arquivo.txt

void CadastroU(usuario user)
{
    FILE *arq;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arq = fopen ("D:/Trabalho/PIM/Usuarios.txt","a+");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arq == NULL)
    {
        puts("Nenhum dado de usuario cadastrado\n");
        system("pause");
        fclose(arq);
    }
    else
    {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE USUARIO--------------------\n\n");
            printf("                    Nome: ");
            fflush (stdin);
            gets(user.nome);
            printf("                    Sobrenome: ");
            fflush (stdin);
            gets(user.sobreNome);
            printf("                    Nome de usuario: ");
            fflush (stdin);
            gets(user.usuario);
            printf("                    endereco de email: ");
            fflush (stdin);
            gets(user.email);
            printf("                    senha: ");
            fflush (stdin);
            gets(user.senha);
            puts("\nUsuario cadastrado!");
            system("pause");
            system("cls");
            //Aqui o programa salva as informações coletadas no arquivo.txt
            fprintf(arq,"------------------------------------------------------------\n\n");
            fprintf(arq,"\tNome: %s",user.nome);
            fprintf(arq,"\n\tSobrenome: %s",user.sobreNome);
            fprintf(arq,"\n\tNome de usuario: %s",user.usuario);
            fprintf(arq,"\n\tE-mail: %s",user.email);
            fprintf(arq,"\n\tSenha: %s",user.senha);
            fprintf(arq,"\n\n------------------------------------------------------------\n\n");
            fclose(arq);
    }
}

//Função resposável por mostrar todos os dados de usuarios armazenados em arquivo.txt 

void ListaU(FILE *ArquivoU)
{
    FILE *arq;
    //Abrindo o diretório e concedendo a permissão de somente leitura
    arq = fopen ("D:/Trabalho/PIM/Usuarios.txt","r");
    if (arq == NULL)
    {
        puts("Nenhum dado de usuario cadastrado\n");
        system("pause");
        fclose(arq);
    }else{
    char dados[10000];
    printf("--------------------LISTA DE USUARIOS--------------------\n\n");
    //Função "fgets" significa "File Get String"
    //Ou seja, o programa lê uma "String" no arquivo até a quebra de linha.
    //Depois ele aloca todas essas informações no vetor até o arquivo ser nulo (quando chegar ao fim)
    while(fgets(dados, 10000, arq) != NULL)
    {
        //Então ele mostrará na tela todos os dados inseridos no vetor "dados"
        printf("%s", dados);
    }
    fclose(arq);
    puts("\n");
    system("pause");
    }
}

//Função responsavel por criar novos registros de funcionarios

void CadastroF(funcionario funs)
{
    FILE *arq;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arq = fopen ("D:/Trabalho/PIM/Funcionarios.txt","a+");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arq == NULL)
    {
        puts("Nenhum Funcionario cadastrado\n");
        system("pause");
        fclose(arq);
    }
    else
    {
        //Aqui é realizada a coleta de dados
        //função "system("cls");" é responsável por limpar a tela
        //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
        system("cls");
        printf("--------------------CADASTRO DE FUNCIONARIO--------------------\n\n");
        printf("                    Nome: ");
        fflush (stdin);
        gets(funs.nome);
        printf("                    Sobrenome: ");
        fflush (stdin);
        gets(funs.sobreNome);
        printf("                    Data de nascimento: ");
        fflush (stdin);
        gets(funs.nascimento);
        printf("                    Filiacao: ");
        fflush (stdin);
        gets(funs.filiacao);
        printf("                    Nacionalidade: ");
        fflush (stdin);
        gets(funs.nacionalidade);
        printf("                    Naturalidade: ");
        fflush (stdin);
        gets(funs.naturalidade);
        printf("                    Numero de identificacao PIS/PASEP: ");
        fflush (stdin);
        gets(funs.pis);
        printf("                    Carteira de Trabalho e Previdencia Social (CTPS): ");
        fflush (stdin);
        gets(funs.ctps);
        printf("                    Escolaridade: ");
        fflush (stdin);
        gets(funs.escolaridade);
        printf("                    CPF: ");
        fflush (stdin);
        gets(funs.cpf);
        printf("                    RG: ");
        fflush (stdin);
        gets(funs.rg);
        printf("                    Titulo de eleitor: ");
        fflush (stdin);
        gets(funs.eleitor);
        printf("                    Data de admissao: ");
        fflush (stdin);
        gets(funs.admisao);
        printf("                    Cargo/Funcao: ");
        fflush (stdin);
        gets(funs.cargo);
        printf("                    Remuneracao: ");
        fflush (stdin);
        scanf("%f",&funs.remuneracao);
        puts("\nFuncionario cadastrado!\n");
        system("pause");
        //Aqui o programa salva as informações coletadas no arquivo.txt
        fprintf(arq,"------------------------------------------------------------\n\n");
        fprintf(arq,"\tNome: %s",funs.nome);
        fprintf(arq,"\n\tSobrenome: %s",funs.sobreNome);
        fprintf(arq,"\n\tNascimento: %s",funs.nascimento);
        fprintf(arq,"\n\tFiliacao: %s",funs.filiacao);
        fprintf(arq,"\n\tNacionalidade: %s",funs.nacionalidade);
        fprintf(arq,"\n\tNaturalidade: %s",funs.naturalidade);
        fprintf(arq,"\n\tNumero de identificacao PIS/PASEP: %s",funs.pis);
        fprintf(arq,"\n\tCarteira de Trabalho e Previdencia Social (CTPS): %s",funs.ctps);
        fprintf(arq,"\n\tEscolaridade: %s",funs.escolaridade);
        fprintf(arq,"\n\tCPF: %s",funs.cpf);
        fprintf(arq,"\n\tRG: %s",funs.rg);
        fprintf(arq,"\n\tTitulo de eleitor: %s",funs.eleitor);
        fprintf(arq,"\n\tData de admissao: %s",funs.admisao);
        fprintf(arq,"\n\tCargo/Funcao: %s",funs.cargo);
        fprintf(arq,"\n\tRemuneracao: %f",funs.remuneracao);
        fprintf(arq,"\n\n------------------------------------------------------------\n\n");
        fclose(arq);
    }
}

void ListaF(FILE *ArquivoF)
{
    FILE *arq,*esc;
    //Abrindo o diretório e concedendo a permissão de somente leitura
    arq = fopen ("D:/Trabalho/PIM/Funcionarios.txt","r");
    if (arq == NULL)
    {
        puts("Nenhum funcionario cadastrado\n");
        system("pause");
        fclose(arq);
    }else{
    char dados[1000000];
    printf("--------------------LISTA DE FUNCIONARIOS--------------------\n\n");
    //Função "fgets" significa "File Get String"
    //Ou seja, o programa lê uma "String" no arquivo até a quebra de linha.
    //Depois ele aloca todas essas informações no vetor até o arquivo ser nulo (quando chegar ao fim)
    while(fgets(dados, 10000, arq) != NULL)
    {
        //Então ele mostrará na tela todos os dados inseridos no vetor "dados"
        printf("%s", dados);
    }
    fclose(arq);
    puts("\n");
    system("pause");
    }
}

//Função responsável por cadastrar novos clientes

void CadastroC(cliente cli)
{
    FILE *arq;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arq = fopen ("D:/Trabalho/PIM/Clientes.txt","a+");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arq == NULL)
    {
        puts("Nenhum Cliente cadastrado\n");
        system("pause");
        fclose(arq);
    }
    else
    {
        //Aqui é realizada a coleta de dados
        //função "system("cls");" é responsável por limpar a tela
         //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
        system("cls");
        printf("--------------------CADASTRO DE CLIENTE--------------------\n\n");
        printf("                    Nome Completo: ");
        fflush (stdin);
        gets(cli.nomeCompleto);
        printf("                    CPF: ");
        fflush (stdin);
        gets(cli.cpf);
        printf("                    Data de nascimento: ");
        fflush (stdin);
        gets(cli.nascimento);
        printf("                    Endereco: ");
        fflush (stdin);
        gets(cli.rua);
        printf("                    Numero: ");
        fflush (stdin);
        gets(cli.num);
        printf("                    Bairro: ");
        fflush (stdin);
        gets(cli.bairro);
        printf("                    Cidade: ");
        fflush (stdin);
        gets(cli.cidade);
        printf("                    Telefone: ");
        fflush (stdin);
        gets(cli.tel);
        printf("                    Endereco de E-mail: ");
        fflush (stdin);
        gets(cli.email);
        puts("\nCliente cadastrado!\n");
        system("pause");
        //Aqui o programa salva as informações coletadas no arquivo.txt
        fprintf(arq,"------------------------------------------------------------\n\n");
        fprintf(arq,"\tNome Completo: %s",cli.nomeCompleto);
        fprintf(arq,"\n\tCPF: %s",cli.cpf);
        fprintf(arq,"\n\tData de nascimento: %s",cli.nascimento);
        fprintf(arq,"\n\tEndereco: %s",cli.rua);
        fprintf(arq,"\n\tNumero: %i",cli.num);
        fprintf(arq,"\n\tBairro: %s",cli.bairro);
        fprintf(arq,"\n\tCidade: %s",cli.cidade);
        fprintf(arq,"\n\tTelefone: %s",cli.tel);
        fprintf(arq,"\n\tEndereco de E-mail: %s",cli.email);
        fprintf(arq,"\n\n------------------------------------------------------------\n\n");
        fclose(arq);
    }
}

//Função Lista de Clientes

void ListaC(FILE *ArquivoC)
{
    FILE *arq;
    //Abrindo o diretório e concedendo a permissão de somente leitura
    arq = fopen ("D:/Trabalho/PIM/Clientes.txt","r");
    if (arq == NULL)
    {
        puts("Nenhum cliente cadastrado\n");
        system("pause");
        fclose(arq);
    }
    else {
    char dados[1000000];
    printf("--------------------LISTA DE CLIENTES--------------------\n\n");
    //Função "fgets" significa "File Get String"
    //Ou seja, o programa lê uma "String" no arquivo até a quebra de linha.
    //Depois ele aloca todas essas informações no vetor até o arquivo ser nulo (quando chegar ao fim)
    while(fgets(dados, 10000, arq) != NULL)
    {
        //Então ele mostrará na tela todos os dados inseridos no vetor "dados"
        printf("%s", dados);
    }
    fclose(arq);
    puts("\n");
    system("pause");
    }
}

//Função responsável por realizar o cadastro dos itens e salvar os dados em arquivo.txt

void CadastroP(produto prods)
{
    FILE *arq,*esc;
    //Escolhendo diretório onde arquivo será salvo e concedendo a permissão de escrita e leitura
    arq = fopen ("D:/Trabalho/PIM/Produtos.txt","a+");
    //Caso o arquivo ainda não exista execute isso, e então o arquivo será criado
    if (arq == NULL)
    {
        puts("Nenhum produto cadastrado\n");
        system("pause");
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
        scanf("%f",&prods.preco);
        printf("                    Codigo do produto: ");
        fflush (stdin);
        scanf("%i",&prods.id);
        puts("\nproduto cadastrado!");
        system("pause");
        system("cls");
        //Aqui o programa salva as informações coletadas no arquivo.txt
        fprintf(arq,"------------------------------------------------------------\n\n");
        fprintf(arq,"\tTipo de produto: %s",prods.tipo);
        fprintf(arq,"\n\tNome do produto: %s",prods.nome);
        fprintf(arq,"\n\tPreco do produto: %.2f",prods.preco);
        fprintf(arq,"\n\tID do produto: %i",prods.id);
        fprintf(arq,"\n\n------------------------------------------------------------\n\n");
        fclose(arq);
    }
}

//Função resposável por mostrar todos os dados armazenados no arquivo.txt 

void ListaP(FILE *ArquivoP)
{
    FILE *arq;
    //Abrindo o diretório e concedendo a permissão de somente leitura
    arq = fopen ("D:/Trabalho/PIM/Produtos.txt","r");
    if (arq == NULL)
    {
        puts("Nenhum produto cadastrado\n");
        system("pause");
        fclose(arq);
    }else{
    char dados[10000];
    printf("--------------------LISTA DE PRODUTOS--------------------\n\n");
    //Função "fgets" significa "File Get String"
    //Ou seja, o programa lê uma "String" no arquivo até a quebra de linha.
    //Depois ele aloca todas essas informações no vetor até o arquivo ser nulo (quando chegar ao fim)
    while(fgets(dados, 10000, arq) != NULL)
    {
        //Então ele mostrará na tela todos os dados inseridos no vetor
        printf("%s", dados);
    }
    fclose(arq);
    puts("\n");
    system("pause");
    }
}

//NÃO IMPLEMENTADO ...
/*int Procurar(FILE *Procurando)
{
    FILE *arq,*esc;
    //Abrindo o diretório e concedendo a permissão de somente leitura
    arq = fopen ("D:/Trabalho/PIM/Funcionarios.txt","r");
    if (arq == NULL)
    {
        puts("Não foi possivel abrir arquivo\n");
        fclose(arq);
    }
    fclose(arq);
    puts("\n");
    system("pause");
}*/


void MenuPrincipal()
{
    system("cls");
    int opc;
    do{
        opc=0;
        printf("--------------------MENU--------------------\n\n");
        printf("           1 <> Novos cadastros\n");
        printf("           2 <> Exibir Listas\n");
        printf("           3 <> Trocar perfil de usuario\n");
        printf("           4 <> Fechar programa\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%i",&opc);
        system("cls");
        switch(opc)
        {
            case (1):
                MenuCadastros();
                system("cls");
                fflush(stdin);
                break;
            case (2):
                MenuListas();
                system("cls");
                fflush(stdin);
                break;
            case (3):
                system("cls");
                printf("\n\n\n                      Usuario desconectado.\n\n\n\n\n");
                system("pause");
                system("cls");
                Login();
                break;
        }
    }while(opc!=4);
    printf("\n\n\n                      Ate logo\n\n\n\n\n");
    system("pause");
    system("cls");
}

void MenuListas()
{
    //Criação de ponteiros
    FILE *arq,*farq,*carq,*parq;
    //Abrindo arquivos com permissão de leitura
    arq = fopen ("D:/Trabalho/PIM/Usuarios.txt","r");
    farq = fopen("D:/Trabalho/PIM/Funcionarios.txt","r");
    carq = fopen("D:/Trabalho/PIM/Clientes.txt","r");
    parq = fopen("D:/Trabalho/PIM/Produtos.txt","r");
    //Criação de Vetores
    usuario user; 
    funcionario funs;
    cliente cli;
    produto prods;
    //Menu principal do programa
    int opc;
    do{
        //Aqui ele mostrará esta tela repetidas vezes, até que o úsuario escolha a opção "Sair"
        system("cls");
        opc=0;
        printf("--------------------LISTAS--------------------\n\n");
        printf("           1 <> Exibir usuarios\n");
        printf("           2 <> Exibir dados de funcionarios\n");
        printf("           3 <> Exibir clientes cadastrados\n");
        printf("           4 <> Exibir lista de produtos\n");
        printf("           5 <> Voltar\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%i",&opc);
        system("cls");
        switch(opc)
        {
            case (1):
            //Aqui existe uma passagem de parametro para que a função Lista de Usuários possa ser executada
                ListaU(arq);
                system("cls");
                fflush(stdin);
                break;
            case (2):
            //Aqui existe uma passagem de parametro para que a função Lista de Funcionários possa ser executada
                ListaF(farq);
                system("cls");
                fflush(stdin);
                break;
            case (3):
            //Aqui existe uma passagem de parametro para que a função Lista de clientes possa ser executada
                ListaC(carq);
                system("cls");
                fflush(stdin);
                break;
            case (4):
            //Aqui existe uma passagem de parametro para que a função Lista de Produtos possa ser executada
                ListaP(parq);
                system("cls");
                fflush(stdin);
                break;
        }
    }while(opc!=5);
    fclose(arq);
    fclose(farq);
    fclose(carq);
    fclose(parq);
}

void MenuCadastros()
{
    //Criação de ponteiros
    FILE *arq,*farq,*carq,*parq;
    //Abrindo arquivos com permissão de leitura
    arq = fopen ("D:/Trabalho/PIM/Usuarios.txt","r");
    farq = fopen("D:/Trabalho/PIM/Funcionarios.txt","r");
    carq = fopen("D:/Trabalho/PIM/Clientes.txt","r");
    parq = fopen("D:/Trabalho/PIM/Produtos.txt","r");
    //Criação de Vetores
    usuario user; 
    funcionario funs;
    cliente cli;
    produto prods;
    int opc;
    system("cls");
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
        scanf("%i",&opc);
        system("cls");
        switch(opc)
        {
            case (1):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Usuários possa ser executada
                CadastroU(user);
                system("cls");
                fflush(stdin);
                break;
            case (2):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Funcionários possa ser executada
                CadastroF(funs);
                system("cls");
                fflush(stdin);
                break;
            case (3):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Clientes possa ser executada
                CadastroC(cli);
                system("cls");
                fflush(stdin);
                break;
            case (4):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Produtos possa ser executada
                CadastroP(prods);
                system("cls");
                fflush(stdin);
                break;
        }
    }while(opc!=5);
    fclose(arq);
    fclose(farq);
    fclose(carq);
    fclose(parq);
}

//A função de Login ainda não está definada corretamente  

void Login()
{
    system("cls");
    char usuario[50], senha[50];
    printf("--------------------TELA DE LOGIN--------------------\n\n");
    printf("\n                  <> Usuario: ");
    gets(usuario);
    printf("\n                  <> Senha: ");
    gets(senha);
    FILE *arq;
    arq = fopen("D:\\Trabalho\\PIM\\Usuarios.txt","r");
    /*char c;
    int i;
    while((c = fgetc(arq)) != EOF)
    {
        if(c == usuario)
        { //Primeiro caracter da STRING que estamos buscando foi encontrado, vamos checas os subsequentes:
            for(i = 0; i < strlen(usuario); i ++)
            { //loop para comparar cada caracter da String pesquisada com o proximo caracter lido
                c = fgetc(arq); //lê mais um caracter no arquivo
                if(c == EOF)  //se encontrar o final do arquivo sai do loop
                    break;
                if((usuario + i) != c) //se algum caracter subsequente lido for diferente da string pesquisada sai do loop
                    break;
            }
            if(i == strlen(usuario))
            { //se i == qtd caracteres da String a pesquisar então achamos a string (a verificação não foi interrompida durante as comparações de caracteres)
             //Aqui entra o seu código ao achar a STRING que você procurava
              //  break;  //break para parar de ler o arquivo
                MenuPrincipal();
            }
        }
        else
        {
            system("cls");
            printf("Usuario e/ou senha incorretos.\n\n");
            system("pause");
            system("cls");
            printf("--------------------TELA DE LOGIN--------------------\n\n");
            printf("\n                  <> Usuario: ");
            gets(usuario);
            printf("\n                  <> Senha: ");
            gets(senha);
        }
    }*/
    fclose(arq);
    system("cls");
    printf("\n\n\n                      Ola *USUARIO*\n\n\n\n\n");
    system("pause");
    system("cls");
}

void main()
{
    system("cls");
    printf("\n\n\n                      Bem-Vindo!\n\n\n\n\n");
    system("pause");
    system("cls");
    Login();
    MenuPrincipal();
}