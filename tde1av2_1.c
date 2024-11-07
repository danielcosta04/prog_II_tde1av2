PARTE - 1
//1.Contar Produtos Abaixo de um Valor: Crie um programa que conte quantos produtos têm
um valor abaixo de um determinado valor fornecido pelo usuário.
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;

#define MAX_PRODUTOS 5

// Definindo a struct para o produto
typedef struct {
int id;
char nome[50];
float valor;
} Produto;

int main() {
Produto produtos[MAX_PRODUTOS];
int quantidade, i;
float valorLimite;
int contador = 0;

// Lendo a quantidade de produtos e verificando o limite
printf(&quot;Digite a quantidade de produtos (máximo %d): &quot;, MAX_PRODUTOS);
scanf(&quot;%d&quot;, &amp;quantidade);

if (quantidade &gt; MAX_PRODUTOS) {
printf(&quot;A quantidade de produtos excede o limite de %d.\n&quot;, MAX_PRODUTOS);
return 1;
}

// Lendo os dados dos produtos

for (i = 0; i &lt; quantidade; i++) {
printf(&quot;Produto %d:\n&quot;, i + 1);
printf(&quot;ID: &quot;);
scanf(&quot;%d&quot;, &amp;produtos[i].id);

printf(&quot;Nome: &quot;);
getchar(); // Limpa o buffer para evitar problemas com fgets
fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
produtos[i].nome[strcspn(produtos[i].nome, &quot;\n&quot;)] = &#39;\0&#39;; // Remove o &#39;\n&#39; do final da
string

printf(&quot;Valor: &quot;);
scanf(&quot;%f&quot;, &amp;produtos[i].valor);
}

// Lendo o valor limite
printf(&quot;Digite o valor limite: &quot;);
scanf(&quot;%f&quot;, &amp;valorLimite);

// Contando produtos abaixo do valor limite
for (i = 0; i &lt; quantidade; i++) {
if (produtos[i].valor &lt; valorLimite) {
contador++;
}
}

// Exibindo o resultado
printf(&quot;Quantidade de produtos abaixo de R$ %.2f: %d\n&quot;, valorLimite, contador);

return 0;
}

//2. Buscar Produto pelo ID: Implemente um programa que permita ao usuário buscar um
produto pelo ID. Se o produto for encontrado, exiba suas informações; caso contrário, informe
que não foi encontrado.
int main() {
#include &lt;stdio.h&gt;

Produto* buscarPorID(Produto produtos[], int tamanho, int id) {
for (int i = 0; i &lt; tamanho; i++) {
if (produtos[i].id == id) {
return &amp;produtos[i];
}
}
return NULL;
}

Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
int id;
printf(&quot;Digite o ID do produto que deseja buscar: &quot;);
scanf(&quot;%d&quot;, &amp;id);

Produto* encontrado = buscarPorID(produtos, MAX_PRODUTOS, id);
if (encontrado) {
printf(&quot;Produto encontrado: ID %d, Nome: %s, Valor: %.2f\n&quot;, encontrado-&gt;id,
encontrado-&gt;nome, encontrado-&gt;valor);
} else {
printf(&quot;Produto não encontrado.\n&quot;);
}
return 0;
}

// 3 - Atualizar Valor do Produto: Desenvolva um programa que permita ao usuário atualizar o
valor de um produto com base no seu ID.

#include &lt;stdio.h&gt;

void atualizarValor(Produto produtos[], int tamanho, int id, float novoValor) {
for (int i = 0; i &lt; tamanho; i++) {
if (produtos[i].id == id) {
produtos[i].valor = novoValor;
printf(&quot;Valor do produto ID %d atualizado para %.2f\n&quot;, id, novoValor);
return;
}
}
printf(&quot;Produto com ID %d não encontrado.\n&quot;, id);
}

int main() {
Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
int id;
float novoValor;
printf(&quot;Digite o ID do produto a ser atualizado: &quot;);
scanf(&quot;%d&quot;, &amp;id);
printf(&quot;Digite o novo valor: &quot;);
scanf(&quot;%f&quot;, &amp;novoValor);
atualizarValor(produtos, MAX_PRODUTOS, id, novoValor);
return 0;
}

//4.Calcular Média de Preços: Implemente um programa que calcule e retorne a média dos
preços dos produtos.

#include &lt;stdio.h&gt;

float calcularMedia(Produto produtos[], int tamanho) {
float soma = 0;
for (int i = 0; i &lt; tamanho; i++) {
soma += produtos[i].valor;
}
return soma / tamanho;
}

int main() {
Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
float media = calcularMedia(produtos, MAX_PRODUTOS);
printf(&quot;A média dos preços dos produtos é: %.2f\n&quot;, media);
return 0;
}

//5.Exibir Produtos Acima da Média: Crie um programa que exiba todos os produtos cujo preço
é superior à média calculada.

#include &lt;stdio.h&gt;

void exibirAcimaMedia(Produto produtos[], int tamanho, float media) {
printf(&quot;Produtos acima da média (%.2f):\n&quot;, media);
for (int i = 0; i &lt; tamanho; i++) {
if (produtos[i].valor &gt; media) {
printf(&quot;ID: %d, Nome: %s, Valor: %.2f\n&quot;, produtos[i].id, produtos[i].nome,
produtos[i].valor);

}
}
}

int main() {
Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
float media = calcularMedia(produtos, MAX_PRODUTOS);
exibirAcimaMedia(produtos, MAX_PRODUTOS, media);
return 0;
}

PARTE 2
1 - Cadastro de Clubes: Crie um programa que permita ao usuário cadastrar um número
determinado de clubes (por exemplo, 10). Para cada clube, solicite que o usuário insira
o ID, nome, vitórias, empates, derrotas, gols pró e gols contra. O programa deve calcular
a pontuação de cada clube com base em suas vitórias, empates e derrotas.
A pontuação deve ser calculada da seguinte forma: 3 pontos por vitória, 1 ponto por
empate, 0 pontos por derrota. Exiba a pontuação total de cada clube.
#include &lt;stdio.h&gt;
#define MAX_CLUBES 10
// Definindo a struct para o Clube
typedef struct {
int id;
char nome[50];
int vitorias;
int empates;
int derrotas;
int gols_pro;
int gols_contra;
int pontos;

} Clube;

void calcularPontuacao(Clube *clube) {
clube-&gt;pontos = (clube-&gt;vitorias * 3) + (clube-&gt;empates * 1);
}

int main() {
Clube clubes[MAX_CLUBES];
int quantidade, i;

printf(&quot;Digite a quantidade de clubes (até %d): &quot;, MAX_CLUBES);
scanf(&quot;%d&quot;, &amp;quantidade);
for (i = 0; i &lt; quantidade; i++) {
printf(&quot;Clube %d:\n&quot;, i + 1);
printf(&quot;ID: &quot;);
scanf(&quot;%d&quot;, &amp;clubes[i].id);
printf(&quot;Nome: &quot;);
scanf(&quot; %[^\n]s&quot;, clubes[i].nome);
printf(&quot;Vitórias: &quot;);
scanf(&quot;%d&quot;, &amp;clubes[i].vitorias);
printf(&quot;Empates: &quot;);
scanf(&quot;%d&quot;, &amp;clubes[i].empates);
printf(&quot;Derrotas: &quot;);
scanf(&quot;%d&quot;, &amp;clubes[i].derrotas);
printf(&quot;Gols Pró: &quot;);
scanf(&quot;%d&quot;, &amp;clubes[i].gols_pro);
printf(&quot;Gols Contra: &quot;);
scanf(&quot;%d&quot;, &amp;clubes[i].gols_contra);

calcularPontuacao(&amp;clubes[i]);
printf(&quot;Pontuação total do clube %s: %d\n&quot;, clubes[i].nome, clubes[i].pontos);
}
return 0;
}
2 - Buscar Clube pelo ID:  Desenvolva um programa que permita ao usuário buscar um
clube pelo ID. Se o clube for encontrado, exiba suas informações; caso contrário,
informe que não foi encontrado.
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
void buscarClubePorID(Clube clubes[], int quantidade, int id) {
int encontrado = 0;
for (int i = 0; i &lt; quantidade; i++) {
if (clubes[i].id == id) {
encontrado = 1;
printf(&quot;Clube encontrado:\n&quot;);
printf(&quot;ID: %d\nNome: %s\nVitórias: %d\nEmpates: %d\nDerrotas: %d\nGols Pró:
%d\nGols Contra: %d\nPontuação: %d\n&quot;,
clubes[i].id, clubes[i].nome, clubes[i].vitorias, clubes[i].empates,
clubes[i].derrotas, clubes[i].gols_pro, clubes[i].gols_contra, clubes[i].pontos);
break;
}
}
if (!encontrado) {
printf(&quot;Clube com ID %d não encontrado.\n&quot;, id);
}
}
3 - Exibir Clubes com Gols Pró Acima da Média: Crie um programa que calcule a média
de gols pró de todos os clubes e exiba apenas os clubes que têm um número de gols
pró superior a essa média.

#include &lt;stdio.h&gt;
float calcularMediaGolsPro(Clube clubes[], int quantidade) {
int totalGolsPro = 0;
for (int i = 0; i &lt; quantidade; i++) {
totalGolsPro += clubes[i].gols_pro;
}
return (float)totalGolsPro / quantidade;
}
void exibirClubesAcimaMediaGolsPro(Clube clubes[], int quantidade) {
float mediaGolsPro = calcularMediaGolsPro(clubes, quantidade);
printf(&quot;Clubes com gols pró acima da média (%.2f):\n&quot;, mediaGolsPro);
for (int i = 0; i &lt; quantidade; i++) {
if (clubes[i].gols_pro &gt; mediaGolsPro) {
printf(&quot;Nome: %s | Gols Pró: %d\n&quot;, clubes[i].nome, clubes[i].gols_pro);
}
}
}
4 - Exibir saldo de gols: Crie um programa que calcule o saldo de gols de todos os
clubes e exiba o nome e o saldo de cada clube.
#include &lt;stdio.h&gt;
void exibirSaldoGols(Clube clubes[], int quantidade) {
printf(&quot;Saldo de gols de cada clube:\n&quot;);
for (int i = 0; i &lt; quantidade; i++) {
int saldoGols = clubes[i].gols_pro - clubes[i].gols_contra;
printf(&quot;Nome: %s | Saldo de Gols: %d\n&quot;, clubes[i].nome, saldoGols);
}
}

5 – Exibir dados do melhor e do pior clube: Crie um programa que exiba os dados do
clube campeão e do último colocado.
#include &lt;stdio.h&gt;
void exibirSaldoGols(Clube clubes[], int quantidade) {
printf(&quot;Saldo de gols de cada clube:\n&quot;);
for (int i = 0; i &lt; quantidade; i++) {
int saldoGols = clubes[i].gols_pro - clubes[i].gols_contra;
printf(&quot;Nome: %s | Saldo de Gols: %d\n&quot;, clubes[i].nome, saldoGols);
}
}
