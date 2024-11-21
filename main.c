#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct{
    char nome[MAX];
    char isbn[MAX];
    float preco;
    int score;
    char editora[MAX];
}livro, *pLivro;

pLivro livro_aloc(int qtde)
{
    pLivro L = (pLivro)malloc(qtde * sizeof(livro));
    return L;
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void livro_ler(pLivro livros, int qtde)
{
    for (int i = 0; i < qtde; i++)
    {
        scanf("%[^\n]s ", livros[i].nome);
        limpar_buffer();
        scanf("%[^\n]s ", livros[i].isbn);
        limpar_buffer();
        scanf("%f ", &livros[i].preco);
        scanf("%d ", &livros[i].score);
        scanf("%[^\n]s ", livros[i].editora);
        limpar_buffer();
    }
}

void livro_exibe(pLivro livros, int qtde)
{
    for (int e = 0; e < qtde; e++)
    {
        printf("Livro %d:\nNome: %s\nISBN: %s\nPreço: R$ %.2f\nScore: %d\nEditora: %s\n",
               e + 1,
               livros[e].nome,
               livros[e].isbn,
               livros[e].preco,
               livros[e].score,
               livros[e].editora);
            printf("\n");
    }
}

void livro_desaloca(pLivro livros)
{
    free(livros);
}

int main()
{
    int qtde;

    scanf("%d ", &qtde);
    if (qtde == 0)
    {
        printf("Sem livros");
    }
    else
    {
        pLivro livros = livro_aloc(qtde);

        livro_ler(livros, qtde);
        livro_exibe(livros, qtde);
        livro_desaloca(livros);
    }

    return 0;
}
