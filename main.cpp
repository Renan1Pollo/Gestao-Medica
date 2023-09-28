#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct indice
{
    int codigo;
    int ender;
};

struct Paciente
{
    int cpf;
    string nome;
    int idade;
    char sexo;
    string telefone;
    string endereco;
    string cidade;
    string uf;
};

struct Especializacao
{
    int codigo;
    string nome;
};

struct Medico
{
    int crm;
    string nome;
    int idade;
    char sexo;
    string telefone;
    int codigoEspecializacao;
    double valorConsulta;
    bool status = true;
};

struct ConsultaMarcada
{
    int cpfPaciente;
    int crmMedico;
    string data;
    string horario;
};

// Gerando dados
void gerar_dados_paciente(Paciente pacientes[], indice idxPaciente[], int &contPaciente);
void gerar_dados_especializacao(Especializacao especializacao[], indice idxEspecializacao[], int &contEspecializacao);
void gerar_dados_medico(Medico medico[], indice idxMedico[], int &contMedico);
void gerar_dados_consulta(ConsultaMarcada consulta[], indice idxConsulta[], int &contConsulta);

// inclusões
void incluir_paciente(Paciente paciente[], indice idxPaciente[], int &cont);
void incluir_medico(Medico medico[], indice idxMedico[], int &cont, Especializacao esp[], indice idxEsp[], int contEsp);

int busca_binaria_Especializacao(indice idxEspecializacao[], int cod, int cont);
int busca_binaria_Medico(indice idxMedico[], int cod, int cont);
void buscar_medicoEsp(indice idxEsp[], Especializacao especializacao[], indice idxMed[], Medico medico[], int contEsp, int contMed);

void agendar_Consulta(indice idxMed[], Medico medico[], int contMed, ConsultaMarcada consulta[], indice idx[], int &cont);
void remover_Medico(indice idxMed[], Medico medico[], int contMed);
void reorganizar_Medico(indice idxMed[], Medico medico[], int &cont);
void calcular_faturamento(Medico medico[], int contMed);
void mostrar_valores(Medico medico[], int contMed);

int main()
{
    setlocale(LC_ALL, "");
    struct Paciente paciente[30];
    struct indice idxPaciente[30];
    int contPaciente = 0;

    struct Especializacao especializacao[30];
    struct indice idxEspecializacao[30];
    int contEspecializacao = 0;

    struct Medico medico[30];
    struct indice idxMedico[30];
    int contMedico = 0;

    struct ConsultaMarcada consulta[30];
    struct indice idxConsulta[30];
    int contConsulta = 0;

    gerar_dados_paciente(paciente, idxPaciente, contPaciente);
    gerar_dados_especializacao(especializacao, idxEspecializacao, contEspecializacao);
    gerar_dados_medico(medico, idxMedico, contMedico);
    gerar_dados_consulta(consulta, idxConsulta, contConsulta);

    int op = 0;
    while (op != 9)
    {
        system("cls");
        cout << "\t\t Bem Vindo ao sistema +Saude \n\n";
        cout << " 1 - Incluir Paciente" << endl;
        cout << " 2 - Incluir Medico" << endl;
        cout << " 3 - Consultar Medico (Especialidade)" << endl;
        cout << " 4 - Agendar Consulta" << endl;
        cout << " 5 - Desativar Medico" << endl;
        cout << " 6 - Reorganizar Medicos" << endl;
        cout << " 7 - Consultar Faturamento da Clinica" << endl;
        cout << " 8 - Consultar Precos de Consultas (Caras/Baratas)" << endl;
        cout << " 9 - Sair" << endl;

        cout << "\n Escolha uma opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            incluir_paciente(paciente, idxPaciente, contPaciente);
            break;

        case 2:
            system("cls");
            incluir_medico(medico, idxMedico, contMedico, especializacao, idxEspecializacao, contEspecializacao);
            break;

        case 3:
            system("cls");
            buscar_medicoEsp(idxEspecializacao, especializacao, idxMedico, medico, contEspecializacao, contMedico);
            break;

        case 4:
            system("cls");
            agendar_Consulta(idxMedico, medico, contMedico, consulta, idxConsulta, contConsulta);
            break;

        case 5:
            system("cls");
            remover_Medico(idxMedico, medico, contMedico);
            break;

        case 6:
            system("cls");
            reorganizar_Medico(idxMedico, medico, contMedico);
            break;

        case 7:
            system("cls");
            calcular_faturamento(medico, contMedico);
            break;

        case 8:
            system("cls");
            mostrar_valores(medico, contMedico);
            break;
        case 9:
            system("cls");
            cout << "Saindo...\n\n";
            break;
        default:
            system("cls");
            cout << "Opcao invalida!\n\n";
            op = 0;
            system("pause");
            break;
        }
    }
}

// Gerando dados
void gerar_dados_paciente(Paciente pacientes[], indice idxPaciente[], int &contPaciente)
{
    // Incluindo na estrutura de pacientes
    pacientes[0].cpf = 9;
    pacientes[0].nome = "Renan";
    pacientes[0].idade = 19;
    pacientes[0].sexo = 'M';
    pacientes[0].telefone = "18 998221129";
    pacientes[0].endereco = "Rua A";
    pacientes[0].cidade = "Assis";
    pacientes[0].uf = "SP";

    pacientes[1].cpf = 5;
    pacientes[1].nome = "Gui";
    pacientes[1].idade = 20;
    pacientes[1].sexo = 'M';
    pacientes[1].telefone = "123456789";
    pacientes[1].endereco = "Rua B";
    pacientes[1].cidade = "Assis";
    pacientes[1].uf = "SP";

    pacientes[2].cpf = 6;
    pacientes[2].nome = "Alice";
    pacientes[2].idade = 22;
    pacientes[2].sexo = 'F';
    pacientes[2].telefone = "0987654321";
    pacientes[2].endereco = "Rua C";
    pacientes[2].cidade = "Londrina";
    pacientes[2].uf = "PR";

    // Incluindo na estrutura de indice
    idxPaciente[0].codigo = 5;
    idxPaciente[0].ender = 1;

    idxPaciente[1].codigo = 6;
    idxPaciente[1].ender = 2;

    idxPaciente[2].codigo = 9;
    idxPaciente[2].ender = 0;

    contPaciente = 3;
}
void gerar_dados_especializacao(Especializacao especializacao[], indice idxEspecializacao[], int &contEspecializacao)
{
    // Incluindo na estrutura de especializacao
    especializacao[0].codigo = 1;
    especializacao[0].nome = "Cardiologista";

    especializacao[1].codigo = 5;
    especializacao[1].nome = "Pediatra";

    especializacao[2].codigo = 2;
    especializacao[2].nome = "Ortopedista";

    // Incluindo na estrutura de indice
    idxEspecializacao[0].codigo = 1;
    idxEspecializacao[0].ender = 0;

    idxEspecializacao[1].codigo = 2;
    idxEspecializacao[1].ender = 2;

    idxEspecializacao[2].codigo = 5;
    idxEspecializacao[2].ender = 1;

    contEspecializacao = 3;
}
void gerar_dados_medico(Medico medico[], indice idxMedico[], int &contMedico)
{
    // Incluindo na estrutura de Medico
    medico[0].crm = 5;
    medico[0].nome = "Dr.Jose";
    medico[0].idade = 45;
    medico[0].sexo = 'M';
    medico[0].telefone = "1234554321";
    medico[0].codigoEspecializacao = 1;
    medico[0].valorConsulta = 100;
    medico[0].status = true;

    medico[1].crm = 10;
    medico[1].nome = "Dr.Miguel";
    medico[1].idade = 58;
    medico[1].sexo = 'M';
    medico[1].telefone = "0987654321";
    medico[1].codigoEspecializacao = 2;
    medico[1].valorConsulta = 200;
    medico[1].status = true;

    medico[2].crm = 4;
    medico[2].nome = "Dra.Julia";
    medico[2].idade = 38;
    medico[2].sexo = 'F';
    medico[2].telefone = "12344566";
    medico[2].codigoEspecializacao = 5;
    medico[2].valorConsulta = 500;
    medico[2].status = true;

    // Incluindo na estrutura de indice
    idxMedico[0].codigo = 4;
    idxMedico[0].ender = 2;

    idxMedico[1].codigo = 5;
    idxMedico[1].ender = 0;

    idxMedico[2].codigo = 10;
    idxMedico[2].ender = 1;

    contMedico = 3;
}
void gerar_dados_consulta(ConsultaMarcada consulta[], indice idxConsulta[], int &contConsulta)
{
    consulta[0].cpfPaciente = 9;
    consulta[0].crmMedico = 5;
    consulta[0].data = "15/11/2023";
    consulta[0].horario = "19:00";

    consulta[1].cpfPaciente = 5;
    consulta[1].crmMedico = 10;
    consulta[1].data = "27/09/2023";
    consulta[1].horario = "15:00";

    consulta[2].cpfPaciente = 6;
    consulta[2].crmMedico = 4;
    consulta[2].data = "08/10/2024";
    consulta[2].horario = "09:00";

    idxConsulta[0].codigo = 5;
    idxConsulta[0].ender = 1;

    idxConsulta[1].codigo = 6;
    idxConsulta[1].ender = 2;

    idxConsulta[2].codigo = 9;
    idxConsulta[2].ender = 0;

    contConsulta = 3;
}

// Inclusões
void incluir_paciente(Paciente paciente[], indice idxPaciente[], int &cont)
{
    int codigo = 0;
    while (codigo != -1)
    {
        cout << "\t\t Inclusao de Paciente \n\n";
        cout << "\t Se desejar sair digite o cpf como 0\n\n";
        cout << " CPF: ";
        cin >> codigo;
        if (codigo > 0)
        {
            paciente[cont].cpf = codigo;

            cout << " Nome: ";
            cin >> paciente[cont].nome;
            cout << " Idade: ";
            cin >> paciente[cont].idade;
            cout << " Sexo: ";
            cin >> paciente[cont].sexo;
            cout << " Telefone: ";
            cin >> paciente[cont].telefone;
            cout << " Endereco: ";
            cin >> paciente[cont].endereco;
            cout << " Cidade: ";
            cin >> paciente[cont].cidade;
            cout << " Estado (UF): ";
            cin >> paciente[cont].uf;

            int i;
            for (i = cont - 1; idxPaciente[i].codigo > codigo && i >= 0; i--)
            {
                idxPaciente[i + 1].codigo = idxPaciente[i].codigo;
                idxPaciente[i + 1].ender = idxPaciente[i].ender;
            }

            idxPaciente[i + 1].codigo = codigo;
            idxPaciente[i + 1].ender = cont;
            cout << "\n\t ===== Inclusao Concluida com Sucesso ===== " << endl;
            cont++;
            system("pause");
            system("cls");
        }
        else
        {
            codigo = -1;
        }
    }
}
void incluir_medico(Medico medico[], indice idxMedico[], int &cont, Especializacao especializacao[], indice idxEsp[], int contEsp)
{
    int codigo = 0;
    while (codigo != -1)
    {
        cout << "\t\t Inclusao de Medicos \n\n";
        cout << "\t Se desejar sair digite o CRM como 0\n\n";
        cout << " CRM: ";
        cin >> codigo;
        if (codigo > 0)
        {
            medico[cont].crm = codigo;

            cout << " Nome: ";
            cin >> medico[cont].nome;
            cout << " Idade: ";
            cin >> medico[cont].idade;
            cout << " Sexo: ";
            cin >> medico[cont].sexo;
            cout << " Telefone: ";
            cin >> medico[cont].telefone;
            cout << " Codigo da Especializacao: ";
            cin >> medico[cont].codigoEspecializacao;
            int endEsp = busca_binaria_Especializacao(idxEsp, medico[cont].codigoEspecializacao, contEsp);
            while (endEsp == -1)
            {
                cout << "\n\t ===== Codigo de Especializacao invalido =====" << endl;
                cout << " Codigo da Especializacao: ";
                cin >> medico[cont].codigoEspecializacao;
                endEsp = busca_binaria_Especializacao(idxEsp, medico[cont].codigoEspecializacao, contEsp);
            }
            cout << " Especialidade: " << especializacao[endEsp].nome << endl;
            cout << " Valor da consulta: ";
            cin >> medico[cont].valorConsulta;
            medico[cont].status = true;

            int i;
            for (i = cont - 1; idxMedico[i].codigo > codigo && i >= 0; i--)
            {
                idxMedico[i + 1].codigo = idxMedico[i].codigo;
                idxMedico[i + 1].ender = idxMedico[i].ender;
            }

            idxMedico[i + 1].codigo = codigo;
            idxMedico[i + 1].ender = cont;
            cout << "\n\t ===== Inclusao Concluida com Sucesso ===== " << endl;
            cont++;
            system("pause");
            system("cls");
        }
        else
        {
            codigo = -1;
        }
    }
}

// Buscas binarias
int busca_binaria_Especializacao(indice idxEspecializacao[], int cod, int cont)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idxEspecializacao[m].codigo; m = (i + f) / 2)
    {
        if (cod > idxEspecializacao[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idxEspecializacao[m].codigo)
        return idxEspecializacao[m].ender;
    else
        return -1;
}
int busca_binaria_Medico(indice idxMedico[], int cod, int cont)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idxMedico[m].codigo; m = (i + f) / 2)
    {
        if (cod > idxMedico[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idxMedico[m].codigo)
        return idxMedico[m].ender;
    else
        return -1;
}

// Consultas
void buscar_medicoEsp(indice idxEsp[], Especializacao especializacao[], indice idxMed[], Medico medico[], int contEsp, int contMed)
{
    int codEsp = 1;
    while (codEsp > 0)
    {
        cout << "\t\t Consulta de Medicos por Especializacao \n\n";
        cout << "\t Se desejar sair digite o codigo da especializacao como 0\n\n";
        cout << " Codigo da Especializacao: ";
        cin >> codEsp;

        if (codEsp > 0)
        {
            int endEsp = busca_binaria_Especializacao(idxEsp, codEsp, contEsp);

            while (endEsp == -1)
            {
                cout << "\n\t ===== Codigo de Especializacao invalido =====" << endl;
                cout << " Codigo da Especializacao: ";
                cin >> codEsp;
                endEsp = busca_binaria_Especializacao(idxEsp, codEsp, contEsp);
            }

            cout << " Especialidade: " << especializacao[endEsp].nome << endl;

            for (int i = 0; i < contMed; i++)
            {
                int end = idxMed[i].ender;
                if (codEsp == medico[end].codigoEspecializacao)
                {
                    cout << "\n\t ===== Medico Encontrado =====" << endl;
                    cout << " CRM: " << medico[end].crm << endl;
                    cout << " Nome: " << medico[end].nome << endl;
                    cout << " Valor da consulta: " << medico[end].valorConsulta << endl;
                }
            }
            system("pause");
            system("cls");
        }
    }
}

// Agendamentos
void agendar_Consulta(indice idxMed[], Medico medico[], int contMed, ConsultaMarcada consulta[], indice idx[], int &cont)
{
    int cod = 1;
    while (cod > 0)
    {
        cout << "\t\t Agendamento de Paciente \n\n";
        cout << "\t Se desejar sair digite o cpf como 0\n\n";
        cout << " Informe o CPF do Paciente: ";
        cin >> cod;
        if (cod > 0)
        {
            consulta[cont].cpfPaciente = cod;
            cout << " Data: ";
            cin >> consulta[cont].data;
            cout << " Horario: ";
            cin >> consulta[cont].horario;
            cout << " CRM: ";
            cin >> consulta[cont].crmMedico;
            int endMed = busca_binaria_Medico(idxMed, consulta[cont].crmMedico, contMed);
            while (endMed == -1)
            {
                cout << "\n\t ===== CRM nao encontrado =====" << endl;
                cout << " CRM: ";
                cin >> consulta[cont].crmMedico;
                endMed = busca_binaria_Medico(idxMed, consulta[cont].crmMedico, contMed);
            }
            cout << "Medico: " << medico[endMed].nome << endl;
            int i;
            for (i = cont - 1; idx[i].codigo > cod; i--)
            {
                idx[i + 1].codigo = idx[i].codigo;
                idx[i + 1].ender = idx[i].ender;
            }
            idx[i + 1].codigo = cod;
            idx[i + 1].ender = cont;

            cout << "\n\t ===== Agendamento Concluido com Sucesso ===== " << endl;
            cont++;
            system("pause");
            system("cls");
        }
    }
}

// Desativação de Medicos
void remover_Medico(indice idxMed[], Medico medico[], int contMed)
{
    int cod = 1;
    while (cod > 0)
    {
        cout << "\t\t Desativacao de Medicos \n\n";
        cout << "\t Se desejar sair digite a CRM como 0\n\n";
        cout << " Informe a CRM do Medico: ";
        cin >> cod;
        if (cod > 0)
        {
            int ender = busca_binaria_Medico(idxMed, cod, contMed);
            if (ender != -1)
            {
                cout << " Desativando Medico: " << medico[ender].nome << endl;
                medico[ender].status = false;
            }
            else
            {
                cout << " Médico não encontrado...";
            }
            system("pause");
            system("cls");
        }
    }
}

// Reorganização
void reorganizar_Medico(indice idxMed[], Medico medico[], int &cont)
{
    Medico aux[30];
    int cont2 = 0;

    for (int j = 0; j < cont; j++)
    {
        int i = idxMed[j].ender;
        if (medico[i].status == true)
        {
            idxMed[cont2].codigo = medico[i].crm;
            idxMed[cont2].ender = cont2;
            aux[cont2] = medico[i];

            cont2++;
        }
    }

    for (int i = 0; i < cont2; i++)
    {
        int ender = idxMed[i].ender;
        medico[ender] = aux[ender];
    }
    cont = cont2;

    cout << "\n Tabela Reorganizadacom sucesso" << endl;
    system("pause");
    system("cls");
}

void calcular_faturamento(Medico medico[], int contMed)
{
    double totalFaturado = 0;
    for (int i = 0; i < contMed; i++)
        if (medico[i].status)
            totalFaturado += medico[i].valorConsulta * 0.05;

    cout << " Total faturado: R$" << totalFaturado << endl;
    system("pause");
    system("cls");
}
void mostrar_valores(Medico medico[], int contMed)
{
    int indiceMin = 0;
    int indiceMax = 0;

    for (int i = 0; i < contMed; i++)
    {
        if (medico[i].status)
        { 
            if (medico[i].valorConsulta < medico[indiceMin].valorConsulta)
                indiceMin = i;

            if (medico[i].valorConsulta > medico[indiceMax].valorConsulta)
                indiceMax = i;
        }
    }

    cout << " Consulta mais barata:" << endl;
    cout << " Medico: " << medico[indiceMin].nome << endl;
    cout << " Valor: R$" << medico[indiceMin].valorConsulta << endl;

    cout << "\n Consulta mais cara:" << endl;
    cout << " Medico: " << medico[indiceMax].nome << endl;
    cout << " Valor: R$" << medico[indiceMax].valorConsulta << endl;

    system("pause");
    system("cls");
}
