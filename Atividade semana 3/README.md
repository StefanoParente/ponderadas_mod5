# Hash Table para Registro de Mercadorias

Este projeto implementa uma Hash Table em C++ para gerenciar um registro de mercadorias. A tabela hash suporta inserções, buscas e remoções de mercadorias, tratando colisões através de encadeamento.

## Casos de Teste

Abaixo estão descritos os casos de teste realizados, abrangendo as funcionalidades principais da Hash Table e seus resultados esperados.

### Caso de Teste 1: Inserção e Busca

- **Descrição**: Inserção das mercadorias com ID 1 ("Maçã") e ID 2 ("Banana"), seguida da busca pela mercadoria com ID 1.
- **Resultado Esperado**: A busca pelo ID 1 deve retornar "Maçã".

### Caso de Teste 2: Tratamento de Colisões

- **Descrição**: Inserção da mercadoria com ID 11 ("Pera"), que deve resultar na mesma posição hash que a mercadoria com ID 1, para testar o tratamento de colisões.
- **Resultado Esperado**: A busca pelo ID 11 deve retornar "Pera", indicando que o tratamento de colisões está funcionando corretamente.

### Caso de Teste 3: Deleção

- **Descrição**: Deleção da mercadoria com ID 1, seguida de uma tentativa de busca por essa mercadoria.
- **Resultado Esperado**: A busca pelo ID 1 após sua remoção deve retornar "Não encontrado".

### Caso de Teste 4: Buscar uma Mercadoria Não Existente

- **Descrição**: Tentativa de buscar uma mercadoria com ID 3, que não foi inserida na tabela.
- **Resultado Esperado**: A busca pelo ID 3 deve retornar "Não encontrado", indicando a correta manipulação de buscas por mercadorias não registradas.

### Caso de Teste 5: Carga Alta

- **Descrição**: Inserção de uma grande quantidade de mercadorias (do ID 3 ao ID 1002) para testar o desempenho da tabela sob carga alta.
- **Resultado Esperado**: A busca pelo ID 1002 deve retornar "Mercadoria 1002", demonstrando que a tabela hash lida eficientemente mesmo com muitas inserções.

## Registro dos Resultados

Abaixo estão as capturas de tela para os casos de teste, demonstrando os resultados obtidos ao executar o programa:

### Casos de teste:

<img src=“../main/Arquivos/Casos de teste.png" style="display: block; margin: auto;"></img>

### Resultados obtidos:

<img src=“../main/Arquivos/Resultados.png" style="display: block; margin: auto;"></img>
