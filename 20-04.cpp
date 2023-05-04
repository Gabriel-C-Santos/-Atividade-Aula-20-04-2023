#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
    Funcionario* prox;
};

Funcionario* init() {
    Funcionario* lista = new Funcionario;
    lista->prontuario = -1;
    lista->nome = "";
    lista->salario = 0.0;
    lista->prox = NULL;
    return lista;
}

Funcionario* insert(Funcionario* lista, int prontuario, string nome, double salario) {

    Funcionario* aux = lista->prox;
    while (aux != NULL) {
        if (aux->prontuario == prontuario) {
            cout << "Já existe um funcionario com o prontuario informado!" << endl;
            return lista;
        }
        aux = aux->prox;
    }
    

    Funcionario* novoFuncionario = new Funcionario;
    novoFuncionario->prontuario = prontuario;
    novoFuncionario->nome = nome;
    novoFuncionario->salario = salario;
    novoFuncionario->prox = lista->prox;
    lista->prox = novoFuncionario;
    
    cout << "Funcionario inserido com sucesso!" << endl;
    return lista;
}


Funcionario* find(Funcionario* lista, int prontuario) {
    Funcionario* aux = lista->prox;
    while (aux != NULL) {
        if (aux->prontuario == prontuario) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}


Funcionario* remove(Funcionario* lista, int prontuario) {
    Funcionario* ant = lista;
    Funcionario* aux = lista->prox;
    
    while (aux != NULL && aux->prontuario != prontuario) {
        ant = aux;
        aux = aux->prox;
    }
    
    if (aux == NULL) {
        cout << "Funcionario não encontrado!" << endl;
        return lista;
    }
    
    ant->prox = aux->prox;
    delete aux;
    cout << "Funcionario removido com sucesso!" << endl;
    return lista;
}


void print(Funcionario* lista) {
    Funcionario* aux = lista->prox;
    double totalSalarios = 0.0;
    cout << "Prontuario | Nome | Salario" << endl;
    cout << "--------------------------------------------------" << endl;
    while (aux != NULL) {
        cout << aux->prontuario << " | " << aux->nome << " | " << aux->salario << endl;
        totalSalarios += aux->salario;
        aux = aux->prox;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Total de salarios: " << totalSalarios << endl;
}


int main() {
    Funcionario* minhaLista = init();
    
    int opcao = -1;
    while (opcao != 0) {
        cout << "MENU" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Incluir" << endl;
        cout << "2 - Excluir" << endl;
        cout << "3 - Pesquisar" << endl;
        cout << "4 - Listar" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        
        switch (opcao) {
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
                
            case 1: {
                int prontuario;
                string nome;
                double salario;
                cout << "Inclusão de funcionario" << endl;
                cout << "Digite o prontuario: ";
                cin >> prontuario;
                cout << "Digite o nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o salario: ";
                cin >> salario;
                minhaLista = insert(minhaLista, prontuario, nome, salario);
            }   break;
                
            case 2: {
                int pront;
                cout << "Exclusão de funcionario" << endl;
                cout << "Digite o prontuario do funcionario a ser excluído: ";
                cin >> pront;
                minhaLista = remove(minhaLista, pront);
            }   break;
                
            case 3: {
                int prontPesq;
                cout << "Pesquisa de funcionario" << endl;
                cout << "Digite o prontuario do funcionario a ser pesquisado: ";
                cin >> prontPesq;
                Funcionario* func = find(minhaLista, prontPesq);
                if (func != NULL) {
                    cout << "Funcionario encontrado:" << endl;
                    cout << "Prontuario: " << func->prontuario << endl;
                    cout << "Nome: " << func->nome << endl;
                    cout << "Salario: " << func->salario << endl;
                } else {
                    cout << "Funcionario não encontrado!" << endl;
                }
            }   break;
                
            case 4: {
                cout << "Listagem de funcionarios" << endl;
                print(minhaLista);
            }   break;
                
            default:
                cout << "Opção inválida!" << endl;
        }
    }
    
    return 0;
}