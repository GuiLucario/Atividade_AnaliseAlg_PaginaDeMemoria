# Atividade_AnaliseAlg_PaginaDeMemoria
Escrever programa em C capaz de escrever dados em formato de texto em páginas de memória virtual no sistema operacional.

* A função open() abre o arquivo "biblia.txt" em modo somente leitura;*
* Verifica-se se a abertura foi bem-sucedida, caso contrário, o programa é encerrado com uma mensagem de erro;
* A função fstat() obtém informações sobre o arquivo, incluindo o seu tamanho, que é armazenado em sb.st_size;
* A função mmap() mapeia o arquivo inteiro para um endereço de memória virtual;
* Os argumentos especificam o tamanho do mapeamento, as permissões (somente leitura), o tipo de mapeamento (privado) e o descritor de arquivo;
* O endereço de início do mapeamento é armazenado em addr;
* O código calcula o número de páginas de memória necessárias para armazenar o arquivo, considerando o tamanho da página do sistema;
* Imprime na tela o número de páginas de memória que o arquivo ocupa;
* A função munmap() desmapeia a região de memória anteriormente mapeada;
* A função close() fecha o descritor de arquivo.
