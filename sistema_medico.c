//BIBLIOTECAS GLOBAIS

#include <stdio.h>      //Biblioteca padr�o de entrada e sa�da;
#include <locale.h>     //Biblioteca para usar texto em Portugu�s;
#include <string.h>     //Biblioteca para uso e tratamento de strings;
#include <stdlib.h>     //Biblioteca para usar as fun��es: Limpa tela / system("cls") e Cria��o de arquivo TXT;
#include <windows.h>    //Biblioteca para usar a fun��o Sleep();
#include <ctype.h>      //Biblioteca para tratamento de maiuscula e minuscula;
#include <time.h>       //Biblioteca para uso da fun��o randon;

/*==================== FUN��O PARA CRIAR ARQUIVO TXT =================================================================*/

void ArqTxt(){
    setlocale(LC_ALL, "");

    //COMANDO PARA CRIA��O DE PASTA;
    if(CreateDirectory("Arquivos", NULL)){
        CreateDirectory("Arquivos/Consultas", NULL);
        CreateDirectory("Arquivos/Cadastros", NULL);

        printf("|==================================================================|\n");
        printf("|                                                                  |\n");
        printf("|              BEM VINDO AO SISTEMA DE CL�NICA M�DICA              |\n");
        printf("|                            VERS�O 1.0                            |\n");
        printf("|==================================================================|\n");
        printf("|           COMO � O SEU PRIMEIRO ACESSO, VAMOS FAZER A            |\n");
        printf("|                  INSTALA��O DE ALGUNS ARQUIVOS.                  |\n");
        printf("|                                                                  |\n");
        printf("|==================================================================|\n");
        Sleep(4000);
        printf("| Instalando pastas do programa.");
        for(int cont = 0; cont < 35; cont++){
            printf(".");
            Sleep(700);
        }
        printf("|\n");
        printf("|==================================================================|\n");
        printf("|           TUDO OK! VOC� J� PODE UTILIZAR NOSSO SISTEMA           |\n");
        printf("|==================================================================|\n");
        Sleep(4000);
    }

    //CRIANDO A VARI�VEL PARA O ARQUIVO TXT;
    FILE *arq_paciente;
    FILE *arq_medicos;
    FILE *arq_consultas;
    FILE *arq_funcionarios;
    FILE *arq_reclama;
    FILE *arq_elogio;
    FILE *arq_login;

    //ABRINDO O ARQUIVO;
    arq_paciente = fopen("Arquivos/Cadastros/cad_pacientes.txt", "at+");
    arq_medicos = fopen("Arquivos/Cadastros/cad_medicos.txt", "at+");
    arq_consultas = fopen("Arquivos/Consultas/cad_consultas.txt", "at+");
    arq_reclama = fopen("Arquivos/Cadastros/cad_reclama.txt", "at+");
    arq_elogio = fopen("Arquivos/Cadastros/cad_elogio.txt", "at+");
    arq_login = fopen("Arquivos/Cadastros/login.txt", "at+");

    //TESTANTO O ARQUIVO;
    if(arq_paciente == NULL){
        printf("Erro na abertura do arquivo PACIENTES! \a\n");
        system("pause");
    }
    if(arq_medicos == NULL){
        printf("Erro na abertura do arquivo M�DICOS! \a\n");
        system("pause");
    }
    if(arq_consultas == NULL){
        printf("Erro na abertura do arquivo CONSULTAS! \a\n");
        system("pause");
    }
    if(arq_login == NULL){
        printf("Erro na abertura do arquivo LOGIN! \a\n");
        system("pause");
    }
    if(arq_reclama == NULL){
        printf("Erro na abertura do arquivo RECLAMA��O! \a\n");
        system("pause");
    }
    if(arq_elogio == NULL){
        printf("Erro na abertura do arquivo ELOGIOS! \a\n");
        system("pause");
    }

    //FUN��O PARA GRAVAR USU�RIO PADR�O DO PROGRAMA;
    char buscalogin[100];
    char login[100] = "admin";
    strcat(login, "\n");

    while(!feof(arq_login)){

        fgets(buscalogin, 100, arq_login);

        if(strcmp(buscalogin, login) == 0){
            //printf("Login encontrado! \n");
            break;
        }
        else{
            //printf("Login nao encontrado! \n");
            fprintf(arq_login, "admin\n");
            fprintf(arq_login, "admin\n");
            fprintf(arq_login, "--------------------\n");
            break;
        }
    }
    //system("pause");

    //FECHANDO O ARQUIVO;
    fclose(arq_paciente);
    fclose(arq_medicos);
    fclose(arq_consultas);
    fclose(arq_login);
    fclose(arq_reclama);
    fclose(arq_elogio);

    //MENSAGEM PARA O USU�RIO;
    //printf("Arquivos criados com sucesso! \a\n");

    //system("pause");
}
/*==================== FUN��O CABE�ALHO ==============================================================================*/

void Cabecalho(){
    setlocale(LC_ALL, "");

    //LIMPA TELA;
    system("cls");

    //CABECALHO;
    printf("|====================================================================|\n");
    printf("|                       SISTEMA DE CL�NICA M�DICA                    |\n");
    printf("|====================================================================|\n");

}
/*==================== CAPA DO PROGRAMA - APRESENTA��O ================================================================*/

void Capa(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //LIMPA TELA;
    system("cls");

    printf("|======================================================================|\n");
    printf("|                     UNIP - UNIVERSIDADE PAULISTA                     |\n");
    printf("|                                                                      |\n");
    printf("|                                CURSO                                 |\n");
    printf("|             CST EM AN�LISE E DESENVOLVIMENTO DE SISTEMAS             |\n");
    printf("|                                                                      |\n");
    printf("|                                                                      |\n");
    printf("|                                 PIM                                  |\n");
    printf("|                  PROJETO INTEGRADO MULTIDISCIPLINAR                  |\n");
    printf("|                           2� PER�ODO DE 2020                         |\n");
    printf("|                                                                      |\n");
    printf("|                                 TEMA                                 |\n");
    printf("|           Desenvolvimento de um software de controle para            |\n");
    printf("|                  uma pequena rede cl�nicas m�dica.                   |\n");
    printf("|                                                                      |\n");
    printf("| -------------------------------------------------------------------- |\n");
    printf("|                           DESENVOLVIDO POR:                          |\n");
    printf("|                                                                      |\n");
    printf("|  PROGRAMA��O: DARLAN P. ARAUJO - RA: F249EA0                         |\n");
    printf("|  DOCUMENTA��O:                                                       |\n");
    printf("|  DIAGRAMA:                                                           |\n");
    printf("|                                                                      |\n");
    printf("|======================================================================|\n");
    system("Pause");
    Login();
}
/*==================== FUN��O LOGUIN ==================================================================================*/
void Login(){
    //LIMPA TELA;
    system("cls");

    //VARIAVEIS;
    FILE *arq_login;
    char login[100], senha[100], buscalogin[100], buscasenha[100];
    char loginOK[100], senhaOK[100];

    //FUN��O QUE ABRE, O ARQUIVO LOGIN TXT;
    arq_login = fopen("Arquivos/Cadastros/login.txt", "at+");

    printf("|======================================================================|\n");
    printf("|                                                                      |\n");
    printf("|                                                                      |\n");
    printf("|                                                                      |\n");
    printf("|                          -----------------                           |\n");
    printf("|                         |  TELA DE LOGIN  |                          |\n");
    printf("|                          -----------------                           |\n");
    printf("|                  Obs: Usu�rio e Senha padr�o \"admin\".                |\n");
    printf("|                                                                      |\n");
    printf("|             Voc� pode cadastrar um novo usu�rio no MENU do           |\n");
    printf("|                               programa!                              |\n");
    printf("|                                                                      |\n");
    printf("| -------------------------------------------------------------------- |\n");
    printf("| USU�RIO: ");
    scanf(" %[^\n]s", login);
    strcat(login, "\n"); //COMANDO PARA JUNTAR O TEXTO FINALIZANDO EM UMA QUEBRA DE LINHA;

    do{
        fgets(buscalogin, 100, arq_login); //COMANDO QUE L� A LINHA DO ARQUIVO

        //COMANDO PARA COMPARAR SE O TEXTO NA LINHA � IGUAL AO TEXTO DA VARI�VEL;
        if(strcmp(buscalogin, login) == 0){
            fgets(buscasenha, 100, arq_login);

            printf("| SENHA: ");
            scanf(" %s", senha);
            strcat(senha, "\n");

            if(strcmp(buscasenha, senha) == 0){
                printf("| -------------------------------------------------------------------- |\n");
                printf("|                                                                      |\n");
                printf("|                                                                      |\n");
                printf("|                              LOGANDO...                              |\n");
                printf("|                                                                      |\n");
                printf("|======================================================================|\n");
                Sleep(2000);
                Inicio();
            }
        }
    }while(!feof(arq_login));
    fclose(arq_login);

    printf("\a");
    printf("|                                                                      |\n");
    printf("|                           LOGIN INV�LIDO...                          |\n");
    printf("|                                                                      |\n");
    printf("|======================================================================|\n");
    Sleep(2000);
    Login();
}
/*==================== FUN��O IN�CIO ==================================================================================*/

void Inicio(){
    setlocale(LC_ALL, "");

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DAS FUN��ES CABE�ALHO E MENU;
    Cabecalho();
    Menu();

}
/*==================== FUN��O MENU PRINCIPAL DO PROGRAMA ==============================================================*/
void Menu(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS
    char menu;
    int cont = 0;

    printf("| A) CADASTRO PACIENTES                                              |\n");
    printf("| B) CADASTRO DE M�DICOS                                             |\n");
    printf("| C) CADASTRO DE USU�RIOS                                            |\n");
    printf("| D) CADASTRO DE CONSULTAS                                           |\n");
    printf("| E) CANCELAMENTO DE CONSULTAS                                       |\n");
    printf("| F) RECLAMA��ES OU ELOGIOS                                          |\n");
    printf("| G) SAIR DO SISTEMA                                                 |\n");
    printf("|====================================================================|\n");


    while(cont == 0){
        printf("| ESCOLHA A OP��O DESEJADA: ");
        //scanf(" %c", &menu);
        fflush(stdin);
        menu = getchar();
        printf("|--------------------------------------------------------------------|\n");

        //C�DIGO PARA TRANSOFORMAR O TEXTO EM MINUSCULO;
        menu = tolower(menu);

        //INICIO DAS CONDI��ES;
        switch(menu){
            case 'a':
                MenuPacientes();
            case 'b':
                MenuMedicos();
            case 'c':
                CadastroUsuarios();
            case 'd':
                CadastroConsultas();
            case 'e':
                printf("| Fun��o em desenvolvimento!                                         |\a\n");
                printf("|--------------------------------------------------------------------|\n");
                system("Pause");
                Inicio();
            case 'f':
                ReclamacoesElogios();
            case 'g':
                printf("| FINALIZANDO.");
                cont ++;
                break;
            default:
                printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
                printf("|--------------------------------------------------------------------|\n");
            }
    }
    //C�DIGO PARA FINALIZAR O PROGRAMA COM EFEITO SLEEP;
    for(int c = 0; c < 40; c ++){
        printf(".");
        Sleep(100);
    }
    printf(" VOLTE SEMPRE! |\n");
    printf("|--------------------------------------------------------------------|\n\n");
    exit(1);
}

/*==================== FUN��O MENU PACIENTES ==========================================================================*/
void MenuPacientes(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS;
    char resposta, menu;
    int cont = 0;

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();

    printf("|========================== MENU PACIENTES ==========================|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| A) CADASTRAR PACIENTES                                             |\n");
    printf("| B) PACIENTES CADASTRADOS                                           |\n");
    printf("| C) VOLTAR PARA MENU PRINCIPAL                                      |\n");
    printf("|====================================================================|\n");

    while(cont == 0){
        printf("| ESCOLHA A OP��O DESEJADA: ");
        scanf(" %c", &menu);
        printf("|--------------------------------------------------------------------|\n");

        //C�DIGO PARA TRANSOFORMAR O TEXTO EM MINUSCULO;
        menu = tolower(menu);

        //INICIO DAS CONDI��ES;
        switch(menu){
        case 'a':
            CadastroPacientes();
            break;
        case 'b':
            Pacientes();

        case 'c':
            Inicio();
            break;
        default:
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
        }
    }
}
/*==================== FUN��O PARA CONSULTAR PACIENTES CADASTRADOS ====================================================*/

void Pacientes(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS;
    FILE *arq_pacientes;
    char busca[100];
    char codigo[100], nome[100], sexo[100], cpf[100], nascimento[100], rua[100], quadra[100], lote[100], cep[100];
    char resposta, menu;
    int cont = 1;

    //LIMPA TELA;
    system("cls");

    //FUN��O QUE ABRE, O ARQUIVO LOGIN TXT;
    arq_pacientes = fopen("Arquivos/Cadastros/cad_pacientes.txt", "at+");

    //FUN��O PARA SEPARA PARTE DO TEXTO NO ARQUIVO.
    while(!feof(arq_pacientes)){
        fgets(busca, 100, arq_pacientes);

        if(cont == 1){
            strcpy(codigo, busca);
        }
        else if(cont == 2){
            strcpy(nome, busca);
        }
        cont ++;
    }

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();
    printf("|--------------------------------------------------------------------|\n");
    printf("|            ABAIXO, EXEMPLO DE COMO VAI FICAR O PROGAMA.            |\n");
    printf("|                                                                    |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|====================== CADASTRO DE PACIENTES =======================|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|   C�DIGO   |             NOME                 |       FONE:        |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| 56324      | JULIO GOMES SILVA                | (62) 98865-7742    |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| 56324      | CARLOS MARTINS                   | (62) 99965-0325    |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| 56324      | PEDRO ALVARES JOSE               | (62) 98499-1987    |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| 56324      | DANIELLE FIRMINO                 | (62) 98869-1157    |\n");
    printf("|--------------------------------------------------------------------|\n");

    system("Pause");
    MenuPacientes();

}

/*==================== FUN��O CADASTRO DE PACIENTES ===================================================================*/

void CadastroPacientes(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //COMANDO PARA GERAR NUMEROS ALEAT�RIOS;
    srand(time(NULL));
    int codigo = rand() % 999;

    //VARI�VEIS;
    FILE *arq_paciente;
    char nome[100], fone[100], email[100], sexo, cpf[100], nascimento[100], rua[100], quadra[100], lote[100], cep[100];
    char resposta;
    int cont = 0;

    //ABRINDO O ARQUIVO;
    arq_paciente = fopen("Arquivos/Cadastros/cad_pacientes.txt", "at+");

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();

    printf("|====================== CADASTRO DE PACIENTES =======================|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|       PARA UM BOM FUNCIONAMENTO DO PROGRAMA RECOMENDAMOS QUE       |\n");
    printf("|     N�O USE ACENTOS NO TEXTO, APENAS PONTOS, VIRGULAS E TRA�OS.    |\n");
    printf("|                                                                    |\n");
    printf("|--------------------------------------------------------------------|\n");

    printf("| NOME DO PACIENTE: ");
    fflush(stdin);
    gets(nome);
    printf("|--------------------------------------------------------------------|\n");

    printf("| N� CELULAR: [EX: (00) 90000-0000]: ");
    fflush(stdin);
    gets(fone);
    printf("|--------------------------------------------------------------------|\n");

    printf("| EMAIL: [EX: nome@email.com]: ");
    fflush(stdin);
    gets(email);
    printf("|--------------------------------------------------------------------|\n");

    printf("| SEXO [M/F]: ");
    scanf(" %c", &sexo);
    printf("|--------------------------------------------------------------------|\n");

    printf("| CPF: [EX: 000.000.000-00]: ");
    fflush(stdin);
    gets(cpf);
    printf("|--------------------------------------------------------------------|\n");

    printf("| DATA DE NASCIMENTO: [EX: 00/00/0000]: ");
    fflush(stdin);
    gets(nascimento);
    printf("|--------------------------------------------------------------------|\n");

    printf("| CADASTRO DE ENDERE�O:                                              | \n");
    printf("| LOGRADOURO: ");
    fflush(stdin);
    gets(rua);
    printf("| QUADRA: ");
    fflush(stdin);
    gets(quadra);
    printf("| LOTE: ");
    fflush(stdin);
    gets(lote);
    printf("| CEP: ");
    fflush(stdin);
    gets(cep);
    printf("|--------------------------------------------------------------------|\n");

    //TRATAMENTO DE STRING PARA MA�USCA;
    //nome[100] = toupper(nome);
    //sexo[100] = toupper(sexo);
    //rua[100] = toupper(rua);

    //CONDI��O PARA CONFIRMA��O DO CADASTRO;
    while(cont == 0){
        printf("| DESEJA CONFIRMAR O CADASTRO? [S/N]: ");
        scanf(" %c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){
            //C�DIGO PARA ARMAZENAR O TEXTO NO TXT;
            fprintf(arq_paciente, "%i\n", codigo);
            fprintf(arq_paciente, "%s\n", nome);
            fprintf(arq_paciente, "%s\n", fone);
            fprintf(arq_paciente, "%c\n", sexo);
            fprintf(arq_paciente, "%s\n", cpf);
            fprintf(arq_paciente, "%s\n", nascimento);
            fprintf(arq_paciente, "%s\n", rua);
            fprintf(arq_paciente, "%s\n", quadra);
            fprintf(arq_paciente, "%s\n", lote);
            fprintf(arq_paciente, "%s\n", cep);
            fprintf(arq_paciente, "------------------------------------------------\n");

            //FECHANDO O ARQUIVO;
            fclose(arq_paciente);

            printf("| CADASTRO EFETUADO COM SUCESSO!                                     |\n");
            printf("|--------------------------------------------------------------------|\n");
            break;
        }
        else if(resposta == 'n' || resposta == 'N'){
            printf("| OK! VAMOS RETORNAR PARA O MENU ANTERIOR.                           |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            MenuPacientes();
        }
        else{
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
        }
    }

    //CONDI��O PARA FAZER UM NOVO CADASTRO;
    while(cont == 0){
        printf("| FAZER NOVO CADASTRO? [S/N]: ");
        scanf(" %c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){
            CadastroPacientes();
        }
        else if(resposta == 'n' || resposta == 'N'){
            printf("| OK! VAMOS RETORNAR PARA O MENU ANTERIOR.                           |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            MenuPacientes();
        }
        else{
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
        }
    }
}

/*==================== FUN��O MENU M�DICOS ============================================================================*/

void MenuMedicos(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS;
    char resposta, menu;
    int cont = 0;

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();

    printf("|=========================== MENU M�DICOS ===========================| \n");
    printf("|--------------------------------------------------------------------|\n");

    printf("| A) CADASTRAR M�DICOS                                               |\n");
    printf("| B) M�DICOS CADASTRADOS                                             |\n");
    printf("| C) VOLTAR PARA MENU PRINCIPAL                                      |\n");
    printf("|====================================================================|\n");

    while(cont == 0){
        printf("| ESCOLHA A OP��O DESEJADA: ");
        scanf(" %c", &menu);
        printf("|--------------------------------------------------------------------|\n");

        //C�DIGO PARA TRANSOFORMAR O TEXTO EM MINUSCULO;
        menu = tolower(menu);

    //INICIO DAS CONDI��ES;
        switch(menu){
        case 'a':
            CadastroMedicos();
            cont++;
            break;
        case 'b':
            Medicos();

        case 'c':
            Inicio();
            cont ++;
            break;
        default:
            printf("| OP��O INV�LIDA! DIGITE NOVAMENTE...                                |\a\n");
            printf("|--------------------------------------------------------------------|\n");
        }
    }
}
/*==================== FUN��O PARA CONSULTAR M�DICOS CADASTRADOS ======================================================*/

void Medicos(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS;
    char resposta, menu;
    int cont = 0;

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();

    printf("|======================= M�DICOS CADASTRADOS ========================|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|            ABAIXO, EXEMPLO DE COMO VAI FICAR O PROGRAMA            |\n");
    printf("|                                                                    |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|    CRM    |            NOME            |       ESPECIALIDADE       |\n");
    printf("|--------------------------------------------------------------------|\n");
    //EXEMPLO DE COMO VAI FICAR O PROGRAMA;
    printf("| 12345     | MARCOS PAULO               | PEDIATRA                  |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| 56890     | MARIA HELENA               | CARDIOLOGISTA             |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| 56890     | FRANCISCO SOUZA            | GINICOLOGISTA             |\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| FUN��O EM DESENVOLVIMENTO...                                       |\n");
    printf("|--------------------------------------------------------------------|\n");

    system("Pause");
    MenuMedicos();

}

/*==================== FUN��O CADASTRO DE M�DICOS =====================================================================*/
void CadastroMedicos(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS;
    FILE *arq_medicos;
    char nome[30], especialidade[100], crm[100];
    char resposta;
    int cont = 0;

    //ABRINDO O ARQUIVO;
    arq_medicos = fopen("Arquivos/Cadastros/cad_medicos.txt", "at+");

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();

    printf("|======================= CADASTRO DE M�DICOS ========================|\n");
    printf("|--------------------------------------------------------------------|\n");

    printf("| CRM DO M�DICO: ");
    fflush(stdin);
    gets(crm);
    printf("|--------------------------------------------------------------------|\n");

    printf("| NOME DO M�DICO: ");
    //scanf(" %s", &nome);
    fflush(stdin);
    gets(nome);
    printf("|--------------------------------------------------------------------|\n");

    printf("| ESPECIALIDADE: ");
    fflush(stdin);
    gets(especialidade);
    printf("|--------------------------------------------------------------------|\n");

    while(cont == 0){
        printf("| DESEJA CONFIRMAR O CADASTRO? [S/N]: ");
        scanf(" %c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){
            fprintf(arq_medicos, "%s\n", crm);
            fprintf(arq_medicos, "%s\n", nome);
            fprintf(arq_medicos, "%s\n", especialidade);
            fprintf(arq_medicos, "-------------------------\n");

            //FECHANDO O ARQUIVO;
            fclose(arq_medicos);

            printf("| CADASTRO EFETUADO COM SUCESSO!                                     |\n");
            printf("|--------------------------------------------------------------------|\n");
            break;
        }
        else if(resposta == 'n' || resposta == 'N'){
            printf("| OK! VAMOS RETORNAR PARA O MENU ANTERIOR.                           |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            MenuMedicos();
        }
        else{
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
        }
    }

    while(cont == 0){
        printf("| FAZER NOVO CADASTRO? [S/N]: ");
        scanf(" %c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){
            CadastroMedicos();
        }
        else if(resposta == 'n' || resposta == 'N'){
            printf("| OK! VAMOS RETORNAR PARA O MENU ANTERIOR.                           |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            MenuMedicos();
        }
        else{
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
        }
    }

}
/*==================== FUN��O CADASTRO DE USU�RIOS ===================================================================*/

void CadastroUsuarios(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //VARI�VEIS;
    FILE *arq_login;
    char login[100], senha[100];
    char resposta;
    int cont = 0;

    //ABRINDO O ARQUIVO;
    arq_login = fopen("Arquivos/Cadastros/login.txt", "at+");

    //LIMPA TELA;
    system("cls");

    //IMPORTA��O DA FUN��O CABE�ALHO;
    Cabecalho();

    printf("|====================== CADASTRO DE USU�RIOS ========================|\n");
    printf("|--------------------------------------------------------------------|\n");

    printf("| LOGIN: ");
    fflush(stdin);
    gets(login);

    printf("| SENHA: ");
    fflush(stdin);
    gets(senha);
    printf("|--------------------------------------------------------------------|\n");

    while(cont == 0){
        printf("| DESEJA CONFIRMAR O CADASTRO? [S/N]: ");
        scanf("%c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){
            //C�DIGO PARA ARMAZENAR O TEXTO NO TXT;
            fprintf(arq_login, "%s\n", login);
            fprintf(arq_login, "%s\n", senha);
            fprintf(arq_login, "--------------------\n");

            //FECHANDO O ARQUIVO;
            fclose(arq_login);

            printf("| CADASTRO EFETUADO COM SUCESSO!                                     |\n");
            printf("|--------------------------------------------------------------------|\n");
            break;
        }
        else if(resposta == 'n' || resposta == 'N'){
            printf("| OK! VAMOS RETORNAR PARA O MENU ANTERIOR.                           |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            Inicio();
        }
        else{
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
        }
    }

    while(cont == 0){
        printf("| FAZER NOVO CADASTRO? [S/N]: ");
        scanf(" %c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){
            CadastroUsuarios();
        }
        else if(resposta == 'n' || resposta == 'N'){
            printf("| OK! VAMOS RETORNAR PARA O MENU ANTERIOR.                           |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            Inicio();
        }
        else{
            printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
        }
    }

}
/*==================== FUN��O CADASTRO DE CONSULTAS =============================================================*/
void CadastroConsultas(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //LIMPA TELA;
    system("cls");

    //FUN��O RAND PARA GERAR NUMEROS;
    srand(time(NULL));
    int numeros = rand() % 1000 +1;

    //VARI�VEIS;
    FILE *arq_consultas;
    float valor;
    char nome[30], medico[30], texto[100], data[10];
    char resposta;
    int cont = 0;

    //ABRINDO O ARQUIVO;
    arq_consultas = fopen("Arquivos/Consultas/cad_consultas.txt", "at+");

    Cabecalho();

    printf("|====================== CADASTRO DE CONSULTAS =======================|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|                              ATEN��O!                              | \n");
    printf("|     PARA CADASTRAR UMA CONSULTA � NECESS�RIO QUE O PACIENTE E O    |\n");
    printf("|                   M�DICO J� TENHA SIDO CADASTRADOS.                |\n");
    printf("|--------------------------------------------------------------------|\n");

    printf("| NOME DO PACIENTE: ");
    fflush(stdin);
    gets(nome);
    printf("|--------------------------------------------------------------------|\n");
    printf("| NOME DO M�DICO: ");
    fflush(stdin);
    gets(medico);
    printf("|--------------------------------------------------------------------|\n");
    printf("|              Para preencher a data use n�meros e barras!           | \a\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("| DATA DA CONSULTA: [00/00/0000]: ");
    fflush(stdin);
    gets(data);
    printf("|--------------------------------------------------------------------|\n");
    printf("| VALOR DA CONSULTA: R$ ");
    scanf("%f", &valor);
    printf("|--------------------------------------------------------------------|\n");
    printf("| ANOTA��ES DA CONSULTA:                                             |\n");
    printf("| ");
    fflush(stdin);
    gets(texto);
    printf("|--------------------------------------------------------------------|\n");

    printf("| GERANDO DADOS DA CONSULTA.");
    for(int cont = 0; cont < 42; cont++){
        printf(".");
        Sleep(100);
    }
    printf("| \n");

    system("cls");

    printf("      ABAIXO, UM EXEMPLO DE COMO O FORMUL�RIO DA CONSULTA VAI FICAR! \n\n");

    //EXEMPLO DE COMO VAI FICAR O FORMUL�RIO;
    printf("|======================== CADASTRO DE CONSULTAS =========================|\n");
    printf("|========================================================================|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| CODIGO DA CONSULTA: 0000         | DATA DA CONSULTA: 12/12/2020        |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| MEDICO: JULIO CESAR     | CRM: 012345  | ESPECIALIDADE: PEDIATRA       |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| PACIENTE: MARIA EDUARDA          | SEXO: F   | DATA NASC: 18/05/2018   |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| FONE: (62) 98469-3488      | EMAIL: MARIAEDUARDA@GMAIL.COM             |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| END: AV. BELA VISTA      | QUADRA: 20  | LOTE: 06  | CEP: 74.984-570   |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| SETOR: BELA VISTA           | CIDADE: GOIANIA      | ESTADO: GOIAS     |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|                   VALOR DA CONSULTA: R$ 150,00 REAIS                   |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|                            <<< ANOTA��ES >>>                           |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("| O PACIENTE APRESENTA UMA TOSE FORTE A PELO MENOS 5 DIAS, ALEM DE       |\n");
    printf("| DIFICULDADE DE RESPIRAR.                                               |\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|========================================================================|\n");
    printf("|########################################################################|\n");
    printf("|########################################################################|\n");
    printf("|========================================================================|\n");
    printf("|========================================================================|\n");

    system("pause");
    Inicio();

    while(cont == 0){

        printf("\nDESEJA SALVAR O FORMUL�RIO? [S/N]: ");
        scanf(" %c", &resposta);
        printf("|--------------------------------------------------------------------|\n");

        if(resposta == 's' || resposta == 'S'){

            //GUARDANDO DADOS NO ARQUIVO;
            fprintf(arq_consultas, "|======================== CADASTRO DE CONSULTAS =========================|\n");
            fprintf(arq_consultas, "|========================================================================|\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| CODIGO DA CONSULTA: 0000         | DATA DA CONSULTA: 12/12/2020        |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| MEDICO: JULIO CESAR     | CRM: 012345  | ESPECIALIDADE: PEDIATRA       |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| PACIENTE: MARIA EDUARDA          | SEXO: F   | DATA NASC: 18/05/2018   |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| FONE: (62) 98469-3488      | EMAIL: MARIAEDUARDA@GMAIL.COM             |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| END: AV. BELA VISTA      | QUADRA: 20  | LOTE: 06  | CEP: 74.984-570   |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| SETOR: BELA VISTA           | CIDADE: GOIANIA      | ESTADO: GOIAS     |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "|                   VALOR DA CONSULTA: R$ 150,00 REAIS                   |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "|                            <<< ANOTA��ES >>>                           |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "| O PACIENTE APRESENTA UMA TOSE FORTE A PELO MENOS 5 DIAS, ALEM DE       |\n");
            fprintf(arq_consultas, "| DIFICULDADE DE RESPIRAR.                                               |\n");
            fprintf(arq_consultas, "|------------------------------------------------------------------------|\n");
            fprintf(arq_consultas, "|========================================================================|\n");
            fprintf(arq_consultas, "|########################################################################|\n");
            fprintf(arq_consultas, "|########################################################################|\n");
            fprintf(arq_consultas, "|========================================================================|\n");
            fprintf(arq_consultas, "|========================================================================|\n");

            //FECHANDO ARQUIVO;
            fclose(arq_consultas);

            printf("\n");
            printf("| CADASTRO EFETUADO COM SUCESSO!                                     |\n");
            printf("|--------------------------------------------------------------------|\n");
            Sleep(1000);
            MenuPacientes();
        }
    }
}
/*==================== FUN��O RECLAMA��ES OU ELOGIOS ==================================================================*/

void ReclamacoesElogios(){
    //Fun��o para uso do portugues;
    setlocale(LC_ALL, "");

    //LIMPA TELA;
    system("cls");

    //VARI�VEIS;
    FILE *arq_reclama;
    FILE *arq_elogio;
    int cont = 0;
    char menu, resp;
    char reclamacoes[200], elogios[200];

    //ABRINDO O ARQUIVO;
    arq_reclama = fopen("Arquivos/Cadastros/cad_reclama.txt", "at+");
    arq_elogio = fopen("Arquivos/Cadastros/cad_elogio.txt", "at+");

    Cabecalho();

    printf("|===================== RECLAMA��ES OU ELOGIOS =======================|\n");
    printf("|--------------------------------------------------------------------|\n");

    printf("| A) RECLAMA��ES                                                     |\n");
    printf("| B) ELOGIOS                                                         |\n");
    printf("| C) VOLTAR AO MENU PRINCIPAL                                        |\n");
    printf("|====================================================================|\n");

    while(cont == 0){
        printf("| ESCOLHA A OP��O DESEJADA: ");
        scanf(" %c", &menu);
        printf("|--------------------------------------------------------------------|\n");

        //C�DIGO PARA COLOCAR O TEXTO EM MINUSCULO;
        menu = tolower(menu);

        switch(menu){
            case 'a':
                printf("| QUAL A SUA RECLAMA��O?                                             |\n");
                printf("|--------------------------------------------------------------------|\n");
                printf("|              OBS. EVITE O USO DE ACENTOS NO TEXTO!                 |\n");
                printf("|--------------------------------------------------------------------|\n");
                printf("| MENSAGEM:                                                          |\n");
                printf("| ");
                fflush(stdin);
                gets(reclamacoes);
                printf("|--------------------------------------------------------------------|\n");

                while(cont == 0){
                    printf("| DESEJA ENVIAR A SUA RECLAM��O? [S/N]: ");
                    scanf(" %c", &resp);
                    printf("|--------------------------------------------------------------------|\n");

                    //C�DIGO PARA COLOCAR O TEXTO EM MINUSCULO;
                    resp = tolower(resp);

                    if(resp == 's'){
                        //SALVANDO OS DADOS NO ARQUIVO;
                        fprintf(arq_reclama, "%s\n", reclamacoes);
                        fprintf(arq_reclama, "------------------------------------------------\n");

                        //FECHANDO O ARQUIVO;
                        fclose(arq_reclama);

                        printf("| RECLAMA��O ENVIADA COM SUCESSO!                                    |\n");
                        printf("|--------------------------------------------------------------------|\n");
                        Sleep(1000);
                        ReclamacoesElogios();
                    }
                    else if(resp == 'n'){
                        printf("| OK! VAMOS RETORNAR AO MENU ANTERIOR                                |\n");
                        printf("|--------------------------------------------------------------------|\n");
                        Sleep(1000);
                        ReclamacoesElogios();
                    }
                    else{
                        printf("| ERRO! OP��O INV�LIDA. TENTE NOVAMENTE.                             |\a\n");
                        printf("|--------------------------------------------------------------------|\n");
                        Sleep(1000);
                    }
                }

            case 'b':
                printf("| QUAL O SEU ELOGIO?                                                 |\n");
                printf("|--------------------------------------------------------------------|\n");
                printf("| Obs. Evite o uso de acentos no texto!                              |\n");
                printf("|--------------------------------------------------------------------|\n");
                printf("| MENSAGEM:                                                          |\n");
                printf("| ");
                fflush(stdin);
                gets(elogios);
                printf("|--------------------------------------------------------------------|\n");

                while(cont == 0){
                    printf("| DESEJA ENVIAR O SEU ELOGIO? [S/N]: ");
                    scanf(" %c", &resp);
                    printf("|--------------------------------------------------------------------|\n");

                    //C�DIGO PARA COLOCAR O TEXTO EM MINUSCULO;
                    resp = tolower(resp);

                    if(resp == 's'){
                        //SALVANDO OS DADOS NO ARQUIVO;
                        fprintf(arq_elogio, "%s\n", elogios);
                        fprintf(arq_elogio, "------------------------------------------------\n");

                        //FECHANDO O ARQUIVO;
                        fclose(arq_elogio);

                        printf("| ELOGIO ENVIADO COM SUCESSO!                                        |\n");
                        printf("|--------------------------------------------------------------------|\n");
                        Sleep(1000);
                        ReclamacoesElogios();
                    }
                    else if(resp == 'n'){
                        printf("| OK! VAMOS RETORNAR AO MENU ANTERIOR                                |\n");
                        printf("|--------------------------------------------------------------------|\n");
                        Sleep(1000);
                        ReclamacoesElogios();
                    }
                    else{
                        printf("| ERRO! OP��O INV�LIDA. TENTE NOVAMENTE.                             |\a\n");
                        printf("|--------------------------------------------------------------------|\n");
                        Sleep(1000);
                    }
                }
            case 'c':
                Inicio();

            default:
                printf("| ERRO! OP��O INV�LIDA. DIGITE NOVAMENTE...                          |\a\n");
                printf("|--------------------------------------------------------------------|\n");
                Sleep(1000);
        }
    }
}
/*==================== PROGRAMA PRINCIPAL =============================================================================*/
void main(){

    // TITULO DO PROGRAMA;
    SetConsoleTitle("<<< SCM - SISTEMA PARA CLINICA MEDICA >>>");

    //FUN��O QUE CRIA / VERIFICA SE J� FOI CRIADO O ARQUIVO TXT;
    ArqTxt();

    //IMPORTA��O DA FUN��O IN�CIO;
    Capa();
}
