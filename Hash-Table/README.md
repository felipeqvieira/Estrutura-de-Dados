# Projeto de implementação de Hash em C.

Nesse programa, são utilizadas duas tabelas. No momento em que o campo da tabela 1 é ocupado, se houver a tentativa de inserção no mesmo espaço, o conteúdo da tabela 1 é direcionado para a tabela 2. Assim, o valor mais recente é atribuído ao espaço recém-ocupado de t1.

Para cada tabela, há uma fórmula diferente. A fórmula da tabela 1 é o resto da divisão por m (11). Para a segunda tabela, é o piso do valor multiplicado por 0.9.

Quando um valor é removido da tabela, o conteúdo do índice se torna 999.

## Arquivos:

O arquivo hash.h mostra e explica o objetivo das funções utilizadas para as tabelas. Já hash.c demonstra a implementação das funções.