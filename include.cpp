#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

class Produto {
public:
    string nome;
    string categoria;
    double preco;
    int estoque;

    Produto() {}

    Produto(string n, string c, double p, int e)
        : nome(n), categoria(c), preco(p), estoque(e) {}
};

class Inventario {
private:
    vector<Produto> produtos;
    set<string> categorias;
    map<string, int> contagemPorCategoria;
    map<string, double> valorPorCategoria;
    list<string> historicoVendas;

public:


    

    void adicionarProduto(const Produto& p) {
        produtos.push_back(p);
        categorias.insert(p.categoria);
        contagemPorCategoria[p.categoria]++;
        valorPorCategoria[p.categoria] += p.preco * p.estoque;

        cout << "Produto '" << p.nome << "' adicionado!\n";
    }

    Produto* buscarProduto(string nome) {
        for (auto& p : produtos)
            if (p.nome == nome)
                return &p;
        return nullptr;
    }

    
   void listarPorCategoria(string cat) {
    cout << "\nProdutos da categoria '" << cat << "':\n";

    // Verifica se a categoria existe no inventário
    if (categorias.find(cat) == categorias.end()) {
        cout << "Categoria nao encontrada!\n\n";
        return; // Sai da função
    }

    // Se existir, lista os produtos
    bool encontrou = false;

    for (auto& p : produtos) {
        if (p.categoria == cat) {
            encontrou = true;
            cout << "- " << p.nome << " | Estoque: " << p.estoque << "\n";
        }
    }
}


    double valorTotal() {
        double total = 0;
        for (auto& p : produtos)
            total += p.preco * p.estoque;
        return total;
    }

    
    void registrarVenda(string nome, int quantidade) {
        Produto* p = buscarProduto(nome);

        if (!p) {
            cout << "Produto nao encontrado!\n";
            return;
        }

        if (p->estoque < quantidade) {
            cout << "Estoque insuficiente!\n";
            return;
        }

        p->estoque -= quantidade;
        valorPorCategoria[p->categoria] -= p->preco * quantidade;

        historicoVendas.push_back(nome + " - qtd: " + to_string(quantidade));

        cout << "Venda registrada!\n";
    }


    void mostrarHistorico() {
        if (historicoVendas.empty())
        {
            cout << "historico de Vendas vazio"<< endl;
        } else {
            cout << "\nHistorico de vendas:\n";

        for (auto& item : historicoVendas){
        cout << "- " << item << "\n";
        cout << endl;
        }
        }
        
        
    }
    ~Inventario() {
    
    produtos.clear();
    categorias.clear();
    contagemPorCategoria.clear();
    valorPorCategoria.clear();
    historicoVendas.clear();
}
    void mostrarRelatorioPorCategoria() {
        cout << "\n--- Relatorio de Categorias ---\n";

        if (contagemPorCategoria.empty()) {
            cout << "Nenhuma categoria registrada.\n";
            cout << "---------------------------------\n";
            return;
        }

        for (auto const& par : contagemPorCategoria) {
            string cat = par.first;
            int contagem = par.second;
            
            double valor = valorPorCategoria.at(cat);

            cout << "Categoria: " << cat << "\n";
            cout << "  - Tipos de Produtos: " << contagem << "\n";
            cout << "  - Valor em Estoque: R$ " << valor << "\n";
        }
        
    }
};
