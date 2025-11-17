# Sistema Simples de Inventário em C++

Este é um projeto simples em C++ que demonstra um sistema básico de gerenciamento de inventário. O código utiliza diversas estruturas da Standard Template Library (STL) do C++ (`vector`, `map`, `set`, `list`) para gerenciar produtos e suas propriedades.

## 🚀 Funcionalidades

A classe `Inventario` é o núcleo do sistema e oferece as seguintes funcionalidades:

* **Adicionar produtos** ao inventário.
* **Buscar produtos** pelo nome.
* **Listar produtos** por categoria (com verificação se a categoria existe).
* **Registrar vendas**, atualizando o estoque e o valor por categoria (com validação de estoque).
* Calcular o **valor total** do inventário (soma de `preço * estoque` de todos os produtos).
* **Mostrar um relatório** resumido por categoria (total de itens e valor).
* **Mostrar um histórico** de todas as vendas registradas com sucesso.
* **Limpar** todos os dados da memória quando o objeto `Inventario` é destruído.

## 📂 Estrutura dos Arquivos

* `include.cpp`: Contém as definições das classes `Produto` e `Inventario`. Esta é a biblioteca principal que define toda a lógica de negócios.
* `main.cpp`: Contém a função `main()` que serve como ponto de entrada. Ele inclui `include.cpp` e demonstra o uso da classe `Inventario`.

## ⚙️ Como Compilar e Executar

Você pode compilar os arquivos usando um compilador C++ padrão, como o `g++`. Como `main.cpp` já inclui `include.cpp`, você só precisa compilar `main.cpp`.

1.  Abra seu terminal.
2.  Navegue até o diretório onde os arquivos estão localizados.
3.  Execute o seguinte comando para compilar:

    ```sh
    g++ main.cpp -o inventario
    ```

    *(Isso compilará `main.cpp` e o `include.cpp` incluído nele, criando um executável chamado `inventario`)*

4.  Execute o programa:

    ```sh
    ./inventario
    ```

### Saída Esperada (Atualizada)

Com base no código `main.cpp`, a saída do console será:

```plaintext
Produto 'Mouse' adicionado!
Produto 'Teclado' adicionado!
Produto 'Notebook' adicionado!

Produtos da categoria 'sla':
Categoria nao encontrada!

Venda registrada!
Valor total do inventario: 11410

--- Relatorio de Categorias ---
Categoria: Computadores
  - Tipos de Produtos: 1
  - Valor em Estoque: R$ 10500
Categoria: Perifericos
  - Tipos de Produtos: 2
  - Valor em Estoque: R$ 910

Historico de vendas:
- Mouse - qtd: 8