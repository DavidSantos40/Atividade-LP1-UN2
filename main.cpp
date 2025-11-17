#include "include.cpp"

#include <iostream>

using namespace std;

int main() {

    Inventario inv;

    Produto p1("Mouse", "Perifericos", 80.0, 10);

    Produto p2("Teclado", "Perifericos", 150.0, 5);

    Produto p3("Notebook", "Computadores", 3500.0, 3);

    inv.adicionarProduto(p1);

    inv.adicionarProduto(p2);

    inv.adicionarProduto(p3);

    inv.listarPorCategoria("sla");

    inv.registrarVenda("Mouse", 8);

    cout << "Valor total do inventario: " << inv.valorTotal() << "\n";

    inv.mostrarRelatorioPorCategoria();
    
    inv.mostrarHistorico();

    return 0;
} 