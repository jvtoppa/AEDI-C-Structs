#include <stdio.h>
#include <stdlib.h>
//1.Escreva um programa que define o tipo Personagem como uma struct de C. Este tipo
//contém os membros nome (80 caracteres), poder (inteiro), defesa (inteiro) e vida (inteiro). Crie
//dois personagens: (“Xil”, 54, 12, 100) e (“Yen”, 40, 20, 100). Crie também um procedimento
//status(), que recebe um personagem como parâmetro e imprime seu estado atual (todos os
//campos da struct). Chame este procedimento na função main para mostrar o status dos dois
//personagens.
int causouCounter = 0;

typedef struct{
    char nome[80];
    int poder;
    int defesa;
    int vida;

} Personagem;

void status(Personagem p){

    printf("%s Poder=%d Defesa=%d Vida=%d\n", p.nome, p.poder, p.defesa, p.vida);

}
//adicione uma função ataque(), que recebe como
//parâmetro dois personagens: p1 e p2. Essa função calcula o dano causado pelo ataque de p1 sobre
//p2, usando a fórmula dano = p1.poder - p2.defesa (se o cálculo for negativo, o dano deve ser
//zero). O resultado inteiro do dano deve ser retornado. Na função main, calcule e mostre o dano
//que seria causado por um ataque de Xil a Yen, e depois o dano que seria causado pelo ataque de
//Yen a Xil.

int ataque(Personagem p1, Personagem p2){

    int dano = p1.poder - p2.defesa;

    if (causouCounter < 2){

        printf("%s vai causar %d de dano em %s.\n", p1.nome, dano, p2.nome);
        causouCounter++;
        return dano;
    }
    else{
        printf("%s causou %d de dano em %s.\n", p1.nome, dano, p2.nome);
        return dano; 
    }
}
//Com base na atividade anterior, adicione uma função inimigo(), que não recebe
//parâmetros. Essa função deve construir um novo personagem da raça “Zed”, com poder, defesa e
//vida zero. Então use a função rand() para gerar valores aleatórios inteiros para o poder no
//intervalo [20, 30], para a defesa no intervalo [10, 30] e para a vida no intervalo [20, 50],
//devolvendo o personagem completo como valor de retorno. Faça então a batalha de Xil contra este
//inimigo gerado randomicamente.

Personagem inimigo(){
    Personagem z = {"Zed", 0, 0, 0};
    z.poder = rand() % (30 + 1 - 20) + 20;
    z.defesa = rand() % (30 + 1 - 10) + 10;
    z.vida = rand() % (50 + 1 - 20) + 20;

    printf("%s Poder=%d Defesa=%d Vida=%d\n", z.nome, z.poder, z.defesa, z.vida);

    return z;
}


int main(){

    Personagem x = {"Xil", 54, 12, 100};
    Personagem y = {"Yen", 40, 20, 100};

    status(x);
    status(y);

    printf("\n");

    ataque(x, y);
    ataque(y, x);

    printf("\n");

//Com base na atividade anterior, altere o programa principal para fazer uma batalha
//entre os dois personagens. Faça uma repetição enquanto os dois personagens estiverem com vida
//maior que zero. Dentro da repetição, calcule o dano do ataque de Xil a Yen, e depois de Yen a Xil.
//Então atualize a vida dos personagens subtraindo o dano recebido. Finalmente, imprima o status
//de ambos e repita. Ao final, indique quem venceu ou se ambos morreram.
  
    while (x.vida >= 1 && y.vida >= 1){

            y.vida = y.vida - ataque(x,y);
            printf("Vida de %s = %d\n", y.nome, y.vida);

            x.vida = x.vida - ataque(y,x);
            printf("Vida de %s = %d\n", x.nome, x.vida);
    }

    if (x.vida > 0) {

        printf("%s venceu!\n\n", x.nome);
    }

    else if (x.vida == y.vida){
        
        printf("%s e %s perderam!\n", x.nome, y.nome);
    }

    else {
        printf("%s venceu!\n", y.nome);
    }
        
    x.vida = 100;

    Personagem z = inimigo();
    while (x.vida >= 1 && z.vida >= 1){

            z.vida = z.vida - ataque(x,z);
            printf("Vida de %s = %d\n", z.nome, z.vida);

            x.vida = x.vida - ataque(z,x);
            printf("Vida de %s = %d\n", x.nome, x.vida);
    }

    if (x.vida > 0) {

        printf("%s venceu!\n\n", x.nome);
    }

    else {
        printf("%s morreu!\n", x.nome);
    }
        
//Com base na atividade anterior, crie um grupo com cinco inimigos gerados
//aleatoriamente (guardados em um vetor de Personagem). Faça então a batalha transcorrer em
//rounds, onde o herói Xil luta contra cada inimigo ainda vivo de cada vez. 
    Personagem z1 = inimigo(2);
    Personagem z2 = inimigo(3);
    Personagem z3 = inimigo(4);
    Personagem z4 = inimigo(5);
    Personagem z5 = inimigo(6);

    Personagem v[5] = {z1, z2, z3, z4, z5};
    
    printf("-x-\n\n");

    for( int i=0; i<5; i++){
        while (x.vida >= 1 && v[i].vida >= 1){

            v[i].vida = v[i].vida - ataque(x,v[i]);
            printf("Vida de %s = %d\n", v[i].nome, z.vida);

            x.vida = x.vida - ataque(v[i],x);
            printf("Vida de %s = %d\n", x.nome, x.vida);
            }

            if (x.vida > 0) {

            printf("%s venceu!\n\n", x.nome);
            
            }

            else {
                
            printf("%s morreu!\n", x.nome);
            break;
            }
    }

   
    return 0;

}
