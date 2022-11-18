#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1

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
    char naturalidade[20];//estado
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
    char cep[10];
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

void CadastroU(usuario *Vetor[MAX])
{
    int i;
    usuario users[MAX];
    FILE *arq,*esc;
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
        for(i=0;i<MAX;i++)
        {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE USUARIO--------------------\n\n");
            printf("                    Nome: ");
            fflush (stdin);
            scanf("%[^\n]s",&users[i].nome);
            printf("                    Sobrenome: ");
            fflush (stdin);
            scanf("%s",&users[i].sobreNome);
            printf("                    Nome de usuario: ");
            fflush (stdin);
            scanf("%s",&users[i].usuario);
            printf("                    endereco de email: ");
            fflush (stdin);
            scanf("%s",&users[i].email);
            printf("                    senha: ");
            fflush (stdin);
            scanf("%s",&users[i].senha);
            puts("\nUsuario cadastrado!");
            system("pause");
            system("cls");
        }
        for(int y=0;y<MAX;y++)
        {
            //Caso o índice do vetor estaja vazio ele pulará para o próximo, não preenchendo este espaço no arquivo.txt
            if(users[y].nome==NULL)
            {
                continue;
            }
            else
            {
                //Aqui o programa salva as informações coletadas no arquivo.txt
                fprintf(arq,"------------------------------------------------------------\n\n");
                fprintf(arq,"\tNome: %s",users[y].nome);
                fprintf(arq,"\n\tSobrenome: %s",users[y].sobreNome);
                fprintf(arq,"\n\tNome de usuario: %s",users[y].usuario);
                fprintf(arq,"\n\tE-mail: %s",users[y].email);
                fprintf(arq,"\n\tSenha: %s",users[y].senha);
                fprintf(arq,"\n\n------------------------------------------------------------\n\n");
            }
        }
        fclose(arq);
    }
}

//Função resposável por mostrar todos os dados de usuarios armazenados em arquivo.txt 

void ListaU(FILE *Arquivo)
{
    FILE *arq,*esc;
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

void CadastroF(funcionario *Vetor[MAX])
{
    int i;
    funcionario funs[MAX];
    FILE *arq,*esc;
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
        for(i=0;i<MAX;i++)
        {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE FUNCIONARIO--------------------\n\n");
            printf("                    Nome: ");
            fflush (stdin);
            scanf("%[^\n]s",&funs[i].nome);
            printf("                    Sobrenome: ");
            fflush (stdin);
            scanf("%s",&funs[i].sobreNome);
            printf("                    Data de nascimento: ");
            fflush (stdin);
            scanf("%s",&funs[i].nascimento);
            printf("                    Filiacao: ");
            fflush (stdin);
            scanf("%[^\n]s",&funs[i].filiacao);
            printf("                    Nacionalidade: ");
            fflush (stdin);
            scanf("%s",&funs[i].nacionalidade);
            printf("                    Naturalidade: ");
            fflush (stdin);
            scanf("%s",&funs[i].naturalidade);
            printf("                    Numero de identificacao PIS/PASEP: ");
            fflush (stdin);
            scanf("%s",&funs[i].pis);
            printf("                    Carteira de Trabalho e Previdencia Social (CTPS): ");
            fflush (stdin);
            scanf("%s",&funs[i].ctps);
            printf("                    Escolaridade: ");
            fflush (stdin);
            scanf("%[^\n]s",&funs[i].escolaridade);
            printf("                    CPF: ");
            fflush (stdin);
            scanf("%s",&funs[i].cpf);
            printf("                    RG: ");
            fflush (stdin);
            scanf("%s",&funs[i].rg);
            printf("                    Titulo de eleitor: ");
            fflush (stdin);
            scanf("%s",&funs[i].eleitor);
            printf("                    Data de admissao: ");
            fflush (stdin);
            scanf("%s",&funs[i].admisao);
            printf("                    Cargo/Funcao: ");
            fflush (stdin);
            scanf("%[^\n]s",&funs[i].cargo);
            printf("                    Remuneracao: ");
            fflush (stdin);
            scanf("%f",&funs[i].remuneracao);
            puts("\nFuncionario cadastrado!\n");
            system("pause");
        }
        for(int y=0;y<MAX;y++)
        {
            //Caso o índice do vetor estaja vazio ele pulará para o próximo, não preenchendo este espaço no arquivo.txt
            if(funs[y].nome==NULL)
            {
                continue;
            }
            else
            {
                //Aqui o programa salva as informações coletadas no arquivo.txt
                fprintf(arq,"------------------------------------------------------------\n\n");
                fprintf(arq,"\tNome: %s",funs[y].nome);
                fprintf(arq,"\n\tSobrenome: %s",funs[y].sobreNome);
                fprintf(arq,"\n\tNascimento: %s",funs[y].nascimento);
                fprintf(arq,"\n\tFiliacao: %s",funs[y].filiacao);
                fprintf(arq,"\n\tNacionalidade: %s",funs[y].nacionalidade);
                fprintf(arq,"\n\tNaturalidade: %s",funs[y].naturalidade);
                fprintf(arq,"\n\tNumero de identificacao PIS/PASEP: %s",funs[y].pis);
                fprintf(arq,"\n\tCarteira de Trabalho e Previdencia Social (CTPS): %s",funs[y].ctps);
                fprintf(arq,"\n\tEscolaridade: %s",funs[y].escolaridade);
                fprintf(arq,"\n\tCPF: %s",funs[y].cpf);
                fprintf(arq,"\n\tRG: %s",funs[y].rg);
                fprintf(arq,"\n\tTitulo de eleitor: %s",funs[y].eleitor);
                fprintf(arq,"\n\tData de admissao: %s",funs[y].admisao);
                fprintf(arq,"\n\tCargo/Funcao: %s",funs[y].cargo);
                fprintf(arq,"\n\tRemuneracao: %f",funs[y].remuneracao);
                fprintf(arq,"\n\n------------------------------------------------------------\n\n");
            }
        }
        fclose(arq);
    }
}

void ListaF(FILE *Arquivo)
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

void CadastroC(cliente *Vetor[MAX])
{
    int i;
    cliente cli[MAX];
    FILE *arq,*esc;
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
        for(i=0;i<MAX;i++)
        {
            //Aqui é realizada a coleta de dados
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE CLIENTE--------------------\n\n");
            printf("                    Nome Completo: ");
            fflush (stdin);
            scanf("%[^\n]s",&cli[i].nomeCompleto);
            printf("                    CPF: ");
            fflush (stdin);
            scanf("%s",&cli[i].cpf);
            printf("                    Data de nascimento: ");
            fflush (stdin);
            scanf("%s",&cli[i].nascimento);
            printf("                    Endereco: ");
            fflush (stdin);
            scanf("%[^\n]s",&cli[i].rua);
            printf("                    Numero: ");
            fflush (stdin);
            scanf("%i",&cli[i].num);
            printf("                    Bairro: ");
            fflush (stdin);
            scanf("%[^\n]s",&cli[i].bairro);
            printf("                    CEP: ");
            fflush (stdin);
            scanf("%s",&cli[i].cep);
            printf("                    Telefone: ");
            fflush (stdin);
            scanf("%[^\n]s",&cli[i].tel);
            printf("                    Endereco de E-mail: ");
            fflush (stdin);
            scanf("%s",&cli[i].email);
            puts("\nCliente cadastrado!\n");
            system("pause");
        }
        for(int y=0;y<MAX;y++)
        {
            //Caso o índice do vetor estaja vazio ele pulará para o próximo, não preenchendo este espaço no arquivo.txt
            if(cli[y].nomeCompleto==NULL)
            {
                continue;
            }
            else
            {
                //Aqui o programa salva as informações coletadas no arquivo.txt
                fprintf(arq,"------------------------------------------------------------\n\n");
                fprintf(arq,"\tNome Completo: %s",cli[y].nomeCompleto);
                fprintf(arq,"\n\tCPF: %s",cli[y].cpf);
                fprintf(arq,"\n\tData de nascimento: %s",cli[y].nascimento);
                fprintf(arq,"\n\tEndereco: %s",cli[y].rua);
                fprintf(arq,"\n\tNumero: %i",cli[y].num);
                fprintf(arq,"\n\tBairro: %s",cli[y].bairro);
                fprintf(arq,"\n\tCEP: %s",cli[y].cep);
                fprintf(arq,"\n\tTelefone: %s",cli[y].tel);
                fprintf(arq,"\n\tEndereco de E-mail: %s",cli[y].email);
                fprintf(arq,"\n\n------------------------------------------------------------\n\n");
            }
        }
        fclose(arq);
    }
}

//Função Lista de Clientes

void ListaC(FILE *Arquivo)
{
    FILE *arq,*esc;
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

void CadastroP(produto *Vetor[MAX])
{
    int i;
    produto prods[MAX];
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
        for(i=0;i<MAX;i++)
        {
            //função "system("cls");" é responsável por limpar a tela
            //Função "fflush(stdin);" serve para limpar o buffer do teclado, caso não for posta resultara em erro
            system("cls");
            printf("--------------------CADASTRO DE PRODUTOS--------------------\n\n");
            printf("                    Tipo do produto: ");
            fflush (stdin);
            scanf("%[^\n]s",&prods[i].tipo);
            printf("                    Nome do produto: ");
            fflush (stdin);
            scanf("%[^\n]s",&prods[i].nome);
            printf("                    Valor do produto: ");
            fflush (stdin);
            scanf("%f",&prods[i].preco);
            printf("                    Codigo do produto: ");
            fflush (stdin);
            scanf("%i",&prods[i].id);

            puts("\nproduto cadastrado!");
            system("pause");
            system("cls");
        }
        for(int y=0;y<MAX;y++)
        {
            //Caso o índice do vetor estaja vazio ele pulará para o próximo, não preenchendo este espaço no arquivo.txt
            if(prods[y].nome==NULL)
            {
                continue;
            }
            else
            {
                //Aqui o programa salva as informações coletadas no arquivo.txt
                fprintf(arq,"------------------------------------------------------------\n\n");
                fprintf(arq,"\tTipo de produto: %s",prods[y].tipo);
                fprintf(arq,"\n\tNome do produto: %s",prods[y].nome);
                fprintf(arq,"\n\tPreco do produto: %.2f",prods[y].preco);
                fprintf(arq,"\n\tID do produto: %i",prods[y].id);
                fprintf(arq,"\n\n------------------------------------------------------------\n\n");
            }
        }
        fclose(arq);
    }
}

//Função resposável por mostrar todos os dados armazenados no arquivo.txt 

void ListaP(FILE *Arquivo)
{
    FILE *arq,*esc;
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
        exit(1);
    }
    fclose(arq);
    puts("\n");
    system("pause");
}*/

//Função "main" encarregada das tarefas principais do código  

void main()
{
    //Criação de ponteiros
    FILE *larq,*arq,*lfarq,*farq,*lcarq,*carq,*pparq,*parq;
    //Abrindo arquivos com permissão de leitura
    arq = fopen ("D:/Trabalho/PIM/Usuarios.txt","r");
    farq = fopen("D:/Trabalho/PIM/Funcionarios.txt","r");
    carq = fopen("D:/Trabalho/PIM/Clientes.txt","r");
    parq = fopen("D:/Trabalho/PIM/Produtos.txt","r");
    //Atribuição de ponteiros de arquivos
    lfarq = farq;
    larq = arq;
    lcarq = carq;
    pparq = parq;
    //Criação de Vetores e ponteiros
    usuario *puser, user[MAX]; 
    funcionario *pfuns, funs[MAX];
    cliente *pcli, cli[MAX];
    produto *pprods, prods[MAX];
    //Atribruição de endereços de vetores
    pfuns = funs;
    puser = user;
    pcli = cli;
    pprods = prods;
    //Menu principal do programa
    int opc,cont;
    do{
        //Aqui ele mostrará esta tela repetidas vezes, até que o úsuario escolha a opção "Sair"
        system("cls");
        opc=0;
        cont=0;
        printf("--------------------MENU--------------------\n\n");
        printf("           1 <> Novo perfil de usuario\n");
        printf("           2 <> Novo registro de funcionario\n");
        printf("           3 <> Novo cadastro de cliente\n");
        printf("           4 <> Inserir novo produto\n");
        printf("           5 <> Exibir usuarios\n");
        printf("           6 <> Exibir dados de funcionarios\n");
        printf("           7 <> Exibir clientes cadastrados\n");
        printf("           8 <> Exibir lista de produtos\n");
        printf("           9 <> Sair\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%i",&opc);
        system("cls");
        switch(opc)
        {
            case (1):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Usuários possa ser executada
                CadastroU(puser);
                system("cls");
                fflush(stdin);
                break;
            case (2):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Funcionários possa ser executada
                CadastroF(pfuns);
                system("cls");
                fflush(stdin);
                break;
            case (3):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Clientes possa ser executada
                CadastroC(pcli);
                system("cls");
                fflush(stdin);
                break;
            case (4):
            //Aqui existe uma passagem de parametro para que a função Cadastro de Produtos possa ser executada
                CadastroP(pprods);
                system("cls");
                fflush(stdin);
                break;
            case (5):
            //Aqui existe uma passagem de parametro para que a função Lista de Usuários possa ser executada
                ListaU(larq);
                system("cls");
                fflush(stdin);
                break;
            case (6):
            //Aqui existe uma passagem de parametro para que a função Lista de Funcionários possa ser executada
                ListaF(farq);
                system("cls");
                fflush(stdin);
                break;
            case (7):
            //Aqui existe uma passagem de parametro para que a função Lista de clientes possa ser executada
                ListaC(lcarq);
                system("cls");
                fflush(stdin);
                break;
            case (8):
            //Aqui existe uma passagem de parametro para que a função Lista de Produtos possa ser executada
                ListaP(pparq);
                system("cls");
                fflush(stdin);
                break;
        }
    }while(opc!=9);
    fclose(arq);
    fclose(farq);
    fclose(carq);
    fclose(parq);
    puts("\nAte logo...");
    system("pause");
    system("cls");
}
