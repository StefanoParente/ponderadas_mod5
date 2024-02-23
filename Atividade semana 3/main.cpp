#include <iostream>
#include <list>
#include <string>

using namespace std;

class Mercadoria {
public:
    int id;
    string nome;

    Mercadoria(int id, string nome) : id(id), nome(nome) {}
};

class HashTable {
    list<Mercadoria> *table;
    int capacity;

    int hashFunction(int id) {
        return id % capacity;
    }

public:
    HashTable(int size) : capacity(size) {
        table = new list<Mercadoria>[capacity];
    }

    void insertItem(int id, string nome) {
        int index = hashFunction(id);
        table[index].push_back(Mercadoria(id, nome));
    }

    bool deleteItem(int id) {
        int index = hashFunction(id);
        for (auto it = table[index].begin(); it != table[index].end(); ) {
            if (it->id == id) {
                it = table[index].erase(it); // Correção: atualiza o iterador após a remoção
                return true;
            } else {
                ++it; // Move para o próximo elemento se o atual não for o que estamos procurando
            }
        }
        return false;
    }

    Mercadoria *searchItem(int id) {
        int index = hashFunction(id);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->id == id) {
                return &(*it);
            }
        }
        return nullptr;
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht(10); // Tamanho da tabela hash.

    // Caso de Teste 1: Inserção e Busca
    ht.insertItem(1, "Maçã");
    ht.insertItem(2, "Banana");
    auto item = ht.searchItem(1);
    cout << "Busca pelo ID 1: " << (item != nullptr ? item->nome : "Não encontrado") << endl;

    // Caso de Teste 2: Tratamento de Colisões
    ht.insertItem(11, "Pera"); // Mesmo índice hash que o ID 1
    item = ht.searchItem(11);
    cout << "Busca pelo ID 11: " << (item != nullptr ? item->nome : "Não encontrado") << endl;

    // Caso de Teste 3: Deleção
    ht.deleteItem(1);
    item = ht.searchItem(1);
    cout << "Busca após deletar ID 1: " << (item != nullptr ? item->nome : "Não encontrado") << endl;

    // Caso de Teste 4: Buscar uma Mercadoria Não Existente
    item = ht.searchItem(3);
    cout << "Busca pelo ID 3: " << (item != nullptr ? item->nome : "Não encontrado") << endl;

    // Caso de Teste 5: Carga Alta
    for (int i = 3; i < 1003; i++) {
        ht.insertItem(i, "Mercadoria " + to_string(i));
    }
    item = ht.searchItem(1002);
    cout << "Busca pelo ID 1002: " << (item != nullptr ? item->nome : "Não encontrado") << endl;

    return 0;
}