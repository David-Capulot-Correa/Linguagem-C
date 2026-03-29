#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int atk;
    int def;
    int vida;
} Personagem;

void raca(Personagem *p, int tipo){

    switch(tipo){

        case 1: // humano
        p->atk+=5; p->def+=5; p->vida+=20;
        break;

        case 2: // animal
        p->atk+=6; p->def+=4; p->vida+=18;
        break;

        case 3: // cyborg
        p->atk+=7; p->def+=6; p->vida+=24;
        break;

        case 4: // otsutsuki
        p->atk+=10; p->def+=10; p->vida+=35;
        break;

    }

}

void elemento(Personagem *p, int e){

    switch(e){

        case 1: p->atk+=3; break;
        case 2: p->atk+=2; p->def+=1; break;
        case 3: p->def+=3; break;
        case 4: p->atk+=2; break;
        case 5: p->atk+=3; break;

    }

}

void modo_sabio(Personagem *p){

    p->atk+=4;
    p->def+=3;
    p->vida+=5;

}

void kekkei_genkai(Personagem *p, int tipo){

    switch(tipo){

        case 1: p->atk+=4; p->def+=3; break; // gelo
        case 2: p->atk+=5; p->def+=2; break; // lava
        case 3: p->atk+=3; p->def+=5; p->vida+=3; break; // madeira
        case 4: p->atk+=6; p->def+=3; break; // poeira

    }

}

void jinchuriki(Personagem *p, int caudas){

    if(caudas>=1 && caudas<=2){
        p->atk+=3; p->def+=2; p->vida+=8;
    }

    else if(caudas<=4){
        p->atk+=5; p->def+=3; p->vida+=10;
    }

    else if(caudas<=6){
        p->atk+=6; p->def+=4; p->vida+=12;
    }

    else if(caudas<=8){
        p->atk+=7; p->def+=5; p->vida+=14;
    }

    else if(caudas==9){
        p->atk+=10; p->def+=7; p->vida+=18;
    }

}

void dojutsu(Personagem *p, int tipo){

    switch(tipo){

        case 1: p->atk+=4; p->def+=2; p->vida+=2; break; // sharingan
        case 2: p->atk+=7; p->def+=3; p->vida+=2; break; // mangekyo
        case 3: p->atk+=9; p->def+=4; p->vida+=3; break; // eternal
        case 4: p->atk+=3; p->def+=4; p->vida+=2; break; // byakugan
        case 5: p->atk+=10; p->def+=6; p->vida+=5; break; // rinnegan

    }

}

void arma(Personagem *p, int tipo){

    switch(tipo){

        case 1: p->atk+=1; break; // kunai
        case 2: p->atk+=3; p->def+=1; break; // espada
        case 3: p->atk+=6; p->def+=2; break; // arma lendaria

    }

}

int main(){

    Personagem p={0};

    int op;
    int qtd;

    printf("Nome do personagem: ");
    scanf("%s",p.nome);

    printf("\nRaca\n1-Humano\n2-Animal\n3-Cyborg\n4-Otsutsuki\n");
    scanf("%d",&op);

    raca(&p,op);

    printf("\nQuantos elementos (0-5)? ");
    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){

        printf("Elemento %d (1-Fogo 2-Agua 3-Terra 4-Vento 5-Raio): ",i+1);
        scanf("%d",&op);

        elemento(&p,op);

    }

    printf("\nModo sabio? 1-Sim 0-Nao\n");
    scanf("%d",&op);

    if(op==1)
    modo_sabio(&p);

    printf("\nKekkei Genkai\n0-Nao\n1-Gelo\n2-Lava\n3-Madeira\n4-Poeira\n");
    scanf("%d",&op);

    if(op>0)
    kekkei_genkai(&p,op);

    printf("\nNumero de caudas (0 se nao for jinchuriki): ");
    scanf("%d",&op);

    if(op>0)
    jinchuriki(&p,op);

    printf("\nQuantos dojutsu possui? ");
    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){

        printf("\nDojutsu %d\n",i+1);
        printf("1-Sharingan\n2-Mangekyo\n3-Eternal Mangekyo\n4-Byakugan\n5-Rinnegan\n");

        scanf("%d",&op);

        dojutsu(&p,op);

    }

    printf("\nQuantas armas possui? ");
    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){

        printf("\nArma %d\n",i+1);
        printf("1-Kunai\n2-Espada\n3-Arma Lendaria\n");

        scanf("%d",&op);

        arma(&p,op);

    }

    printf("\n===== CARD FINAL =====\n");

    printf("Nome: %s\n",p.nome);
    printf("Ataque: %d\n",p.atk);
    printf("Defesa: %d\n",p.def);
    printf("Vida: %d\n",p.vida);

    return 0;
}
