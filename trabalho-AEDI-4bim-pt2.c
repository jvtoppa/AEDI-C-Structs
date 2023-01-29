#include <stdio.h>
#include <stdlib.h>

/*Criar uma estrutura chamada VetorInteligente (novo tipo, use o typedef) com dois
campos, um ponteiro para inteiro pi, que será usado para guardar o endereço do vetor; e
um inteiro n que guarda quantos elementos tem no vetor.*/

typedef struct {

    int *pi;
    int n;

}VetorInteligente;

/* Faça a função cria(), ela não recebe nenhum parâmetro, apenas define o ponteiro pi
como nulo e n como zero. A função retorna um estrutura do tipo vetorInteligente.*/

VetorInteligente cria(){
    VetorInteligente vecI;
    vecI.pi = NULL;
    vecI.n = 0;

    return vecI;
}
/*Faça a função adiciona(), ela recebe um vetor inteligente vi e um inteiro x e retorna
um novo vetor inteligente com uma posição a mais e com o inteiro x no final do vetor.
Detalhe: você deve usar o malloc() para criar um novo vetor, copiar todos os elementos do
vetor antigo para o novo e no novo espaço adicionar o inteiro x passado por parâmetro. A
função também deve atualizar o valor de n. E não esqueça de liberar o vetor antigo com o
free().
*/

VetorInteligente adiciona(VetorInteligente vi, int x){
    VetorInteligente novo_vi;

    novo_vi.pi = malloc((vi.n+1)*sizeof(int));

    for(int i=0; i < vi.n; i++){

        novo_vi.pi[i] = vi.pi[i];
    }

    novo_vi.pi[vi.n] = x;

    novo_vi.n = vi.n+1;

    free(vi.pi);
    vi.pi = NULL;

    return novo_vi;
}

void mostra(VetorInteligente v){
    printf("valor em binario: \n");

    for(int i = 0; i < v.n; i++){
        printf("%d", v.pi[v.n - (i + 1)]);
    }
}

/*Faça a função destroi(), a função deve dar um free() no vetor, tornar pi NULL e zerar
n.*/

void destroi(VetorInteligente ve){

    free(ve.pi);
    ve.pi = NULL;
    ve.n = 0;

}

/*Usando o vetor inteligente, leia um número decimal e mostre o seu equivalente em
binário. O valor decimal lido deve ser um inteiro grande, do tipo unsigned long long int,
para ler ou escrever um valor desse tipo, deve-se usar "%llu". Dica, o vetor deve guardar
apenas os restos das divisões (0 ou 1). Não esqueça de "destruir" o vetor no final.
*/
int  converte(unsigned long long int dec){
    int bin;

    if(dec % 2 == 0){
        
        bin = 0;
        
    }

    else{

        bin = 1;

    }
    return bin;
}

int main(){

    unsigned long long int dec;
    int bin;

    printf("Insira o valor decimal: ");
    scanf("%llu", &dec);

    VetorInteligente z = cria();

    while (dec >= 1){
        
        bin = converte(dec);
        z = adiciona(z, bin);

        dec = dec / 2;
    }
    
    mostra(z);
    destroi(z);
    
    return 0;
}
