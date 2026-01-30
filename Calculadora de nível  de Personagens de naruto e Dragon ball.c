#include <stdio.h>
#include <string.h>

int main() {
    double escolher_nivel;
    double poder_luta = 0;
    int escolha_categoria, escolha_habilidade,escolha;
    double valor_base_nivel;

    do {
        printf("--- MENU DE HABILIDADES ---\n");
        printf("Poder Atual: %.2f\n\n", poder_luta);
        printf("1. Ninjutsu  \n");
        printf("2. Taijutsu \n");
        printf("3. Genjutsu \n");
        printf("4. Dojutsu\n");
        printf("5. Invocação\n");
        printf("6. Jutsus Proibidos \n");
        printf("7. Jutsus de Selamento\n");
        printf("8. Jutsus Temporais e de Espaço-Tempo\n");
        printf("9. Kekkei Genkai\n");
        printf("10. Habilidades Especiais\n");
        printf("11. ki ou chakara\n");
        printf("12. Senjutsu e Marcas da Maldição\n");
        printf("13. Jinchuriki e Transformações\n");
        printf("14. Jutsus de Cla\n");
        printf("15. Armas Ninjas\n");
        printf("100.******* RESETAR E RECALCULAR******\n");
        printf("0. CALCULAR PODER TOTAL E SAIR\n");
        printf("-------------------------\n");
        printf("Escolha uma categoria: ");
        scanf("%d", &escolha_categoria);

        printf("\n");

        if (escolha_categoria == 0) {
            break;
        } else if (escolha_categoria == 100) {
            poder_luta = 0;
            printf("Poder de Luta Resetado!\n\n");
            valor_base_nivel ;
            poder_luta += valor_base_nivel;
            continue;
        }

        switch (escolha_categoria) {

            case 1: { // Ninjutsu #######
                int escolha_sub_habilidade;
                do {
                    printf("--- Ninjutsu ---\n");
                    printf("1. Fogo (Katon) (Sasuke)\n");
                    printf("2. Terra (Doton) (Hiruzen)\n");
                    printf("3. Agua (Suiton) (Tobirama)\n");
                    printf("4. Vento (Fuuton) (Naruto)\n");
                    printf("5. Raio (Raiton) (Kakashi)\n");
                    printf("6. Energia Pura (Rasengan)(palmas de bisturi) (Naruto,sakura,kabuto)\n");
                    printf("7. Cinco Elementos (Hiruzen)\n");
                    printf("0. Finalizar e voltar ao menu principal\n");
                    printf("Escolha um elemento/tipo: ");
                    scanf("%d", &escolha_sub_habilidade);

                    if (escolha_sub_habilidade == 0) break;

                    if (escolha_sub_habilidade == 7) {
                        double valores_base[] = {5, 4, 6, 9, 8};
                        char* nomes_elementos[] = {"Fogo", "Terra", "Agua", "Vento", "Raio"};

                        double multiplicadores[] = {1, 2, 4};

                        for (int i = 0; i < 5; i++) {
                            printf("\n--- Nivel de Dominio para %s ---\n", nomes_elementos[i]);
                            printf("1. Usuario\n");
                            printf("2. Especialista\n");
                            printf("3. Mestre\n");
                            printf("Escolha o nivel de dominio: ");
                            scanf("%d", &escolha_habilidade);

                            if (escolha_habilidade >= 1 && escolha_habilidade <= 3) {
                                poder_luta += valores_base[i] * multiplicadores[escolha_habilidade - 1];
                            } else {
                                printf("Opcao invalida. Nenhum bonus aplicado.\n");
                            }
                        }
                    } else {
                        double valor_elemento = 0.0;
                        switch (escolha_sub_habilidade) {
                            case 1: valor_elemento = 5; break; // fogo
                            case 2: valor_elemento = 4; break;// terra
                            case 3: valor_elemento = 6; break; // agua
                            case 4: valor_elemento = 9; break; // vento
                            case 5: valor_elemento = 8; break; // raio
                            case 6: valor_elemento = 6; break; // energia pura
                            default: printf("Opcao invalida.\n");
                        }

                        double multiplicador_dominio = 0.0;
                        printf("\n--- Nivel de Dominio ---\n");
                        printf("1. Usuario\n");
                        printf("2. Especialista \n");
                        printf("3. Mestre\n");
                        printf("Escolha o nivel de dominio: ");
                        scanf("%d", &escolha_habilidade);
                        switch (escolha_habilidade) {
                            case 1: multiplicador_dominio = 1; break;
                            case 2: multiplicador_dominio = 2; break;
                            case 3: multiplicador_dominio = 4; break;
                            default: printf("Opcao invalida.\n");
                        }
                        poder_luta += valor_elemento * multiplicador_dominio;
                    }
                } while(escolha_sub_habilidade != 0);
                break;
            }

            case 2: { // Taijutsu #########
                int escolha_sub_habilidade;
                do {
                    printf("--- Taijutsu ---\n");
                    printf("1. Goken (Punho Forte) (Lee/Gai)\n");
                    printf("2. Juken (Punho Gentil) (Neji, Hinata)\n");
                    printf("0. Finalizar e voltar ao menu principal\n");
                    printf("Escolha um estilo de Taijutsu: ");
                    scanf("%d", &escolha_sub_habilidade);

                    if (escolha_sub_habilidade == 0) break;

                    double valor_estilo = 0.0;
                    switch (escolha_sub_habilidade) {
                        case 1: valor_estilo = 7; break;
                        case 2: valor_estilo = 9; break;
                        default: printf("Opcao invalida.\n");
                    }

                    double multiplicador_dominio = 0.0;
                    printf("\n--- Nivel de Dominio ---\n");
                    printf("1. Iniciante\n");
                    printf("2. Intermediario\n");
                    printf("3. Mestre\n");
                    printf("Escolha o nivel de dominio do estilo de Taijutsu: ");
                    scanf("%d", &escolha_habilidade);
                    switch (escolha_habilidade) {
                        case 1: multiplicador_dominio = 1; break;
                        case 2: multiplicador_dominio = 2; break;
                        case 3: multiplicador_dominio = 10; break;
                        default: printf("Opcao invalida. Valor padrao aplicado.\n");
                    }

                    poder_luta += valor_estilo * multiplicador_dominio;

                    int escolha_elemento_raio;
                    printf("\nDeseja adicionar o **Elemento Raio** (Kakashi, Sasuke, A)?\n");
                    printf("1. Sim\n");
                    printf("2. Nao\n");
                    printf("Escolha: ");
                    scanf("%d", &escolha_elemento_raio);

                    if (escolha_elemento_raio == 1) {
                        poder_luta *= 1.5;
                        printf("\nPoder de Taijutsu multiplicado\n");
                    }

                    int ativar_portoes;
                    printf("\nDeseja adicionar os **Oito Portoes Internos** a esta habilidade?\n");
                    printf("1. Sim\n");
                    printf("2. Nao\n");
                    printf("Escolha: ");
                    scanf("%d", &ativar_portoes);

                    if (ativar_portoes == 1) {
                        printf("\n--- Oito Portoes Internos ---\n");
                        printf("1. Portao da Abertura\n");
                        printf("2. Portao da Cura\n");
                        printf("3. Portao da Vida\n");
                        printf("4. Portao do Ferimento\n");
                        printf("5. Portao da Floresta\n");
                        printf("6. Portao da Visao\n");
                        printf("7. Portao da Loucura\n");
                        printf("8. Portao da Morte\n");
                        printf("Escolha um Portao para ativar: ");
                        scanf("%d", &escolha_habilidade);

                        double multiplicador_portao = 0.0;
                        switch (escolha_habilidade) {
                            case 1: multiplicador_portao = 1.2; break;
                            case 2: multiplicador_portao = 1.4; break;
                            case 3: multiplicador_portao = 1.8; break;
                            case 4: multiplicador_portao = 2.6; break;
                            case 5: multiplicador_portao = 5.2; break;
                            case 6: multiplicador_portao = 10.4; break;
                            case 7: multiplicador_portao = 20.8; break;
                            case 8: multiplicador_portao = 41.6; break;
                            default: printf("Opcao invalida.\n");
                        }
                        if (multiplicador_portao > 0) {
                            poder_luta *= multiplicador_portao;
                        }
                    }
                } while(escolha_sub_habilidade != 0);
                break;
            }

            case 3: { // Genjutsu ##########

                 int escolha_sub_habilidade;
                do {
                    printf("--- Genjutsu---\n");
                    printf("1. Genjutsu Visual)\n");
                    printf("2. Genjutsu Sonoro)\n");
                    printf("0. Finalizar e voltar ao menu principal\n");
                    printf("Escolha uma habilidade: ");
                    scanf("%d", &escolha_sub_habilidade);
                    if (escolha_sub_habilidade == 0) break;

                    switch (escolha_sub_habilidade) {
                        case 1: poder_luta += 3; break;
                        case 2: poder_luta += 5; break;

                        default: printf("Opcao invalida.\n");
                    }
                } while (escolha_sub_habilidade != 0);
                break;

            }

            case 4: { // Dojutsu ############
    int escolha_sub_habilidade;
    do {
        printf("---  Dojutsu ---\n");
        printf("1. Sharingan (Escolha o nivel)\n");
        printf("2. Rinnegan (Pain, Sasuke)\n");
        printf("3. Rinne-Sharingan (Kaguya, Madara)\n");
        printf("4. Byakugan ou  kekei genkai do Ranmaru (Escolha o nivel)\n");
        printf("5. Jogan (Boruto)\n");
        printf("6. Ketsuryugan (Chinoike)\n");
        printf("7. kokugan (Isshiki)\n");
        printf("8. serigan \n");
        printf("9. Donjutsu da Shion(ver o futuro) \n");
        printf("10. Donjutsu da yome(rastrea inimigos pelas lagrimas) \n");
        printf("0. Finalizar e voltar ao menu principal\n");
        printf("Escolha uma habilidade: ");
        scanf("%d", &escolha_sub_habilidade);

        if (escolha_sub_habilidade == 0) break;
        switch (escolha_sub_habilidade) {

            case 1: { // Sharingan
printf("\n--- Nivel do Sharingan ---\n");
printf("1. 1 tomoe (Sasuke)\n");
printf("2. 2 tomoes (Sasuke)\n");
printf("3. 3 tomoes (Kakashi)\n");
printf("4. Mangekyo Incompleto (Itachi, Obito)\n");
printf("5. Mangekyo Eterno (Sasuke, Madara)\n");
printf("Escolha o nivel: ");
int escolha_sharingan;
scanf("%d", &escolha_sharingan);

switch(escolha_sharingan) {
    case 1: poder_luta += 30; break; // 1 tomoe (ver chakara = 15) + (aumentar o sensorial =15 )
    case 2: poder_luta += 40; break; // 2 tomoes (ver chakara = 15) + (copia movimentos = 10 ) + (aumentar o sensorial =15 )
    case 3: poder_luta += 50; break; // 3 tomoes (ver chakara = 15) + (copia movimentos = 10 ) + (aumentar o sensorial =15 ) + (Genjutsu visual = 10 )
    case 4: poder_luta += 44; break; // Mangekyo Incompleto - (ficar cego - 6)
    case 5: poder_luta += 50; break; // Mangekyo Eterno
    default: printf("Opcao invalida.\n");
}

if (escolha_sharingan == 3) {
    int habilidadesha;
    do {
        printf("\n--- Habilidades Sharingan ---\n");
        printf("1. Adicionar Izanagi (Danzō)\n");
        printf("2. Adicionar Izanami (Itachi)\n");
        printf("0. Finalizar\n");
        scanf("%d", &habilidadesha);
        switch(habilidadesha) {
            case 1: poder_luta += 14; break; // Izanagi
            case 2: poder_luta += 16.5; break; // Izanami
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while(habilidadesha != 0);
}

if (escolha_sharingan >= 4) {
    int escolha_mangekyo_habilidades;
    do {
        printf("\n--- HABILIDADES DO MANGEKYO SHARINGAN ---\n");
        printf("1. Adicionar Kamui (Obito)\n");
        printf("2. Adicionar Tsukuyomi (Itachi)\n");
        printf("3. Adicionar Susanoo (Sub-menu)\n");
        printf("4. Adicionar Kamui Shuriken (Kakashi)\n");
        printf("5. Adicionar Amaterasu (Sasuke, Itachi)\n");
        printf("6. Adicionar Izanagi (Danzō)\n");
        printf("7. Adicionar Izanami (Itachi)\n");
        printf("8. Intangibilidade (Obito)\n");
        printf("9. Controlar facas (Shin)\n");
        printf("0. Finalizar a selecao de habilidades\n");
        printf("Escolha uma habilidade: ");
        scanf("%d", &escolha_mangekyo_habilidades);

        switch(escolha_mangekyo_habilidades) {
            case 1: poder_luta += 20; break; // Kamui
            case 2: poder_luta += 12; break; // Tsukuyomi
            case 3: {
                printf("\n--- TIPOS DE SUSANOO ---\n");
                printf("1. Susanoo (Costelas)\n");
                printf("2. Susanoo (Esqueleto)\n");
                printf("3. Susanoo (Protegido)\n");
                printf("4. Susanoo (Humanoide)\n");
                printf("5. Susanoo (Completo)\n");
                printf("Escolha um tipo de Susanoo: ");
                int escolha_susanoo;
                scanf("%d", &escolha_susanoo);
                switch(escolha_susanoo) {
                    case 1: poder_luta += 10; break;
                    case 2: poder_luta += 25; break;
                    case 3: poder_luta += 50; break;
                    case 4: poder_luta += 75; break;
                    case 5: poder_luta += 100; break; // Susanoo completo atualizado
                    default: printf("Opcao invalida.\n");
                }

                int escolha_armas;
                printf("\nDeseja adicionar armas ao seu Susanoo?\n");
                printf("1. Sim\n");
                printf("2. Nao\n");
                printf("Escolha: ");
                scanf("%d", &escolha_armas);
                if (escolha_armas == 1) {
                    do {
                        printf("\n--- ARMAS DO SUSANOO ---\n");
                        printf("1. Espada Totsuka (Itachi)\n");
                        printf("2. Escudo Yata (Itachi)\n");
                        printf("3. Flecha de Indra (Sasuke)\n");
                        printf("4. Espada de Chakra de Raio (Sasuke)\n");
                        printf("5. Block (Shisui)\n");
                        printf("0. Finalizar selecao\n");
                        printf("Escolha uma arma: ");
                        scanf("%d", &escolha_armas);

                        switch (escolha_armas) {
                            case 1: poder_luta += 30; break;
                            case 2: poder_luta += 32; break;
                            case 3: poder_luta += 38; break;
                            case 4: poder_luta += 25; break;
                            case 5: poder_luta += 21; break;
                            case 0: break;
                            default: printf("Opcao invalida.\n");
                        }
                    } while (escolha_armas != 0);
                }
                break;
            }
            case 4: poder_luta += 23; break; // Kamui Shuriken
            case 5: poder_luta += 18; break; // Amaterasu
            case 6: poder_luta += 14; break; // Izanagi
            case 7: poder_luta += 16.5; break; // Izanami
            case 8: poder_luta += 6; break; // Intangibilidade
            case 9: poder_luta += 5; break; // Facas controladas
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while(escolha_mangekyo_habilidades != 0);
} break;

            }

            case 2: { // Rinnegan
                // poder base de luta (genjutsu + percepção)
                poder_luta += 5 + 4 + 6 + 9 + 8; // todos os jutsus de  elementos

                int escolha_caminho;
                do {
                    printf("\n--- Habilidades do Rinnegan ---\n");
                    printf("1. Caminho Deva (Gravidade)\n");
                    printf("2. Caminho Asura (Mecanico)\n");
                    printf("3. Caminho Humano (Alma)\n");
                    printf("4. Caminho Animal (Invocacoes)\n");
                    printf("5. Caminho Naraka (Reanimacao)\n");
                    printf("6. Caminho Preta (Absorcao)\n");
                    printf("7. Caminho exterior (Preserva a vida e a morte)\n");
                    printf("8. Estátua Gedo Mazo \n");
                    printf("9. Limbo (Madara)\n");
                    printf("10. Chibaku Tensei\n");
                    printf("11. Criação de Todas as Coisas\n");
                    printf("12. Todos os Poderes Basico do rinegan\n");
                    printf("13. Yomotsu Hirasaka (Kaguya)\n");
                    printf("14. Genjutsu do Rinnegan (Sasuke)\n");
                    printf("15. Criação de portais (Sasuke)\n");
                    printf("16. Amenotejikara (Sasuke)\n");
                    printf("0. Finalizar\n");
                    printf("Escolha: ");
                    scanf("%d", &escolha_caminho);

                    switch(escolha_caminho) {
                        case 1: poder_luta += 25; break;  // Caminho Deva: controle de gravidade ofensivo
                        case 2: poder_luta += 12; break;  // Caminho Asura: mecânico / armas e robôs
                        case 3: poder_luta += 18; break;  // Caminho Humano: captura de almas
                        case 4: poder_luta += 15; break;  // Caminho Animal: invocações poderosas
                        case 5: poder_luta += 20; break;  // Caminho Naraka: reanimação e julgamento
                        case 6: poder_luta += 30; break;  // Caminho Preta: absorção de chakra
                        case 7: poder_luta += 25; break;  // Caminho exterior: controle da vida/morte
                        case 8: poder_luta += 35; break;  // Estátua Gedo Mazo: força bruta defensiva
                        case 9: poder_luta += 22; break;  // Limbo: invisível e intocável
                        case 10: poder_luta += 30; break; // Chibaku Tensei: devastação em larga escala
                        case 11: poder_luta += 50; break; // Criação de Todas as Coisas: ofensiva e estratégica máxima
                        case 12: poder_luta += 25 + 12 + 18 + 15 + 20 + 30 + 25 + 35 ; break; // Todos os Seis Caminhos combinados
                        case 13: poder_luta += 35; break; // Yomotsu Hirasaka: teleporte dimensional + letal
                        case 14: poder_luta += 18; break; // Genjutsu do Rinnegan (Sasuke)
                        case 15: poder_luta += 20; break; // Criação de portais (Sasuke)
                        case 16: poder_luta += 22; break; // Amenotejikara (Sasuke)
                        case 0: break;
                        default: printf("Opcao invalida.\n");
                    }
                } while(escolha_caminho != 0);
                break;

            } 

            case 3: { // Rinne-Sharingan
poder_luta += 100; // base de poder do Rinne-Sharingan

int escolha_rsh;
do {
    printf("\n--- Habilidades do Rinne-Sharingan ---\n");
    printf("1. Tsukuyomi Infinito\n");
    printf("2. Teleporte Dimensional\n");
    printf("3. Todos os poderes do Rinnegan\n");
    printf("0. Finalizar\n");
    scanf("%d", &escolha_rsh);

    switch(escolha_rsh) {
        case 1: poder_luta += 80; break;  // Tsukuyomi Infinito: Genjutsu mais mortal do universo
        case 2: poder_luta += 40; break;  // Teleporte Dimensional: ofensivo e estratégico
        case 3: poder_luta += 25 + 12 + 18 + 15 + 20 + 30 + 25 + 35 + 50 ; break; // Todos os poderes do Rinnegan combinados e  sharigan combinados
        case 0: break;
        default: printf("Opcao invalida.\n");
    }
} while(escolha_rsh != 0 && escolha_rsh != 3);

            }

            case 4: { // Byakugan

                            printf("\n--- Nivel do Byakugan ---\n");
            printf("1. Byakugan ou kekei genkai do Ranmaru (Neji)\n");
            printf("2. Tenseigan (Toneri)\n");
            printf("0. Finalizar\n");
            int escolha_byakugan;
            scanf("%d", &escolha_byakugan);

            switch(escolha_byakugan) {
                case 1: poder_luta += 40; break;   // (visão 360 = 15) + (visão de chakra = 15) + (ver longa distancia = 10)
                case 2: poder_luta = (40 + 30 + 50 + 60 ); break; // Tenseigan: (byakugan) + (voar = 30) + (gokudamas 50)+(chakara masivo = +60)
                case 0: break;
                default: printf("Opcao invalida.\n");
            }

            if (escolha_byakugan >= 1 && escolha_byakugan <= 2) {
                int escolher_palmas;
                printf("\nDeseja adicionar Punho Gentil: 64 Palmas?\n");
                printf("1. Sim\n");
                printf("2. Nao\n");
                scanf("%d", &escolher_palmas);
                if (escolher_palmas == 1) {
                    poder_luta *= 1.64; // Punho Gentil: aumenta letalidade significativamente
                }
            }
            break;

            }

            case 5: poder_luta += 25; break; // Jogan (visão de chakra = 15) + (ver longa distancia = 10)
            case 6: poder_luta += 31; break; // Ketsuryugan = (genjutusu = 3) + (controlar ferro = 28)
            case 7: poder_luta += 84  ; break;  // kokugan (alterar a altura sua ou dos objetos = 10 ) + (ter sua dimesão(kamui) = 20) + (cubos pretos antes sensor = 16) + (chama tira vida(copia do amatrasu) =18)+(portal =20)
            case 8: poder_luta += 100; break;  // seringan (onisiciencia = 100)
            case 9: poder_luta += 10  ; break; // ver o futuro / sua alma volta ao passado
            case 10: poder_luta += 10; break;  // Donjutsu da yome( ver longa distancia)
            default: printf("Opcao invalida.\n");
        }
    } while(escolha_sub_habilidade != 0);
    break;
}

            case 5: { // Invocacao ############
int escolha_sub_habilidade;
do {
    printf("--- Invocacao ---\n");
    printf("1. Sapos, Cobras, Lesma (Naruto, Jiraiya, Tsunade)\n");
    printf("2. Manda (Orochimaru)\n");
    printf("3. Gamabunta, Katsuyu, Manda (Modo Completo)\n");
    printf("4. Elefante (Danzō)\n");
    printf("5. Aguia (Sasuke)\n");
    printf("6. Salamandra (Hanzo)\n");
    printf("7. Cachorros (Kakashi)\n");
    printf("8. Macaco (Hiruzen)\n");
    printf("9. Corvos (Itachi)\n");
    printf("10. Tartaruga (Might Guy)\n");
    printf("11. Aranhas (Kidomaru)\n");
    printf("12. Techiro (Temari)\n");
    printf("13. Tomperia (Jirobo)\n");
    printf("14. Inseto Gigante (Shino Aburame)\n");
    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma habilidade: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch (escolha_sub_habilidade) {
        case 1: poder_luta += 5; break;    // Sapos, Cobras, Lesma: utilidade média
        case 2: poder_luta += 20; break;   // Manda: ofensiva e grande poder
        case 3: poder_luta += 50; break;   // Modo completo: alto impacto
        case 4: poder_luta += 15; break;   // Elefante: força bruta
        case 5: poder_luta += 12; break;   // Águia: reconhecimento e ataque médio
        case 6: poder_luta += 10; break;   // Salamandra: ataque especial
        case 7: poder_luta += 18; break;   // Cachorros: combate tático
        case 8: poder_luta += 14; break;   // Macaco: ofensiva moderada
        case 9: poder_luta += 20; break;   // Corvos: distração e ataque tático
        case 10: poder_luta += 8; break;   // Tartaruga: defesa situacional
        case 11: poder_luta += 12; break;  // Aranhas: ataque em grupo
        case 12: poder_luta += 7; break;   // Techiro: utilidade menor
        case 13: poder_luta += 8; break;   // Tomperia: ofensiva menor
        case 14: poder_luta += 6; break;   // Inseto gigante: suporte tático
        default: printf("Opcao invalida.\n");
    }
} while (escolha_sub_habilidade != 0);
break;

            }

            case 6: { // Jutsus Proibidos ######################
int escolha_sub_habilidade;
do {
    printf("--- Jutsus Proibidos e de Selamento ---\n");
    printf("1. Reencarnacao do Mundo Impuro OU RESSUSITAR (Kabuto, Orochimaru/ WHIS)\n");
    printf("2. Multi clone das sombras\n");
    printf("3. Fios (Kakuzu)\n");
    printf("4. Ataque múltiplo de papel bomba (Tobirama, Hidan)\n");
    printf("5. C0 ou alto destruição (Delta, Deidara)\n");
    printf("6. Apagar matéria (Zeno)\n");
    printf("0. Voltar\n");
    printf("Escolha uma habilidade: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch(escolha_sub_habilidade) {
        case 1: poder_luta += 50; break;   // Ressonância de reanimação ofensiva e estratégica
        case 2: poder_luta += 60; break;  // Multiclone das sombras: grande ofensiva
        case 3: poder_luta += 12; break;  // Fios controláveis ofensivos
        case 4: poder_luta += 18; break;  // Ataque múltiplo de papel bomba
        case 5: poder_luta += 80; break;  // Alto poder destrutivo
        case 6: poder_luta += 10000; break; // Apagar matéria: devastador
        default: printf("Opcao invalida.\n");
    }
} while(escolha_sub_habilidade != 0);
break;

            }

            case 7: { // Selamento ######################
                        int escolha_sub_habilidade;
                        do {
                            printf("--- Jutsus  de Selamento ---\n");
                            printf("1. Tecnica de Selamento da Morte (Minato, Hiruzen)\n");
                            printf("2. Selo de Quatro Simbolos (Minato)\n");
                            printf("3. Selo de Oito Trigramas (Minato)\n");
                            printf("4. Jutsu de 5 simbolos (Orochimaru/Jiraya)\n");
                            printf("5. Selamento cabeça de leão (Vovo Chiri)\n");
                            printf("6. Selamento auto amaldiçoamento (Danzō)\n");
                            printf("7. Selamento por desenho (Sai)\n");
                            printf("8. Selamento reverso dos quatro simbolos (Danzō)\n");
                            printf("9. Selamento da corrente adamantina (Naruto)\n");
                            printf("10.Selamento do grande portao de Deus (Hashirama)\n");
                            printf("11.Selamento de duas ou tres pessoas (Konohamaru)\n");
                            printf("12.Selamento do Ichiki (Konohamaru)\n");
                            printf("13.Selamento de areia (Gaara/Filho do Gaara)\n");
                            printf("14.Mafuba (Goku/Master Kame)\n");
                            printf("0. Voltar\n");
                            printf("Escolha uma habilidade: ");
                            scanf("%d", &escolha_sub_habilidade);
                            if (escolha_sub_habilidade == 0) break;

    switch(escolha_sub_habilidade) {
        case 1: poder_luta += 40; break;   // Selamento letal
        case 2: poder_luta += 25; break;   // Selo moderado
        case 3: poder_luta += 30; break;   // Selo de efeito maior
        case 4: poder_luta += 20; break;   // Selamento ofensivo limitado
        case 5: poder_luta += 15; break;   // Selamento de efeito menor
        case 6: poder_luta += 18; break;   // Auto-tributo de força
        case 7: poder_luta += 12; break;   // Selamento de utilidade média
        case 8: poder_luta += 35; break;   // Selamento reverso estratégico
        case 9: poder_luta += 30; break;  // Corrente de alto impacto
        case 10: poder_luta += 50; break;  // Grande portão de força
        case 11: poder_luta += 20; break;  // Selamento múltiplo moderado
        case 12: poder_luta += 15; break;  // Selamento pessoal
        case 13: poder_luta += 25; break;  // Selamento defensivo/tático
        case 14: poder_luta += 30; break;  // Selamento defensivo/tático
        default: printf("Opcao invalida.\n");
    }
} while(escolha_sub_habilidade != 0);
break;

            }

            case 8: { // Jutsus Temporais e de Espaco-Tempo ###########################
int escolha_sub_habilidade;
do {
    printf("--- Jutsus Temporais e de Espaco-Tempo ---\n");
    printf("1. Jutsu do Deus Voador do Raio (Minato) \n");
    printf("2. Marcas de Garra (Code)\n");
    printf("3. Teletransporte (Goku)\n");
    printf("4. Congelar o tempo por um curto periodo (Guildo)\n");
    printf("5. Viajar no tempo (Whis)\n");
    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma habilidade: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch(escolha_sub_habilidade) {
        case 1: poder_luta += 30; break;  // Habilidade altamente letal e útil para combate rápido
        case 2: poder_luta += 20; break;  // Marca de ataque tático e dano considerável
        case 3: poder_luta += 25; break;  // Teletransporte: utilidade ofensiva/defensiva muito relevante
        case 4: poder_luta += 15; break;  // Pausar o tempo: situacional, bom efeito tático
        case 5: poder_luta += 70; break;  // Pausar o tempo:  E VIAJA PRO PASSADO
        default: printf("Opcao invalida.\n");
    }
} while(escolha_sub_habilidade != 0);
break;

            }

            case 9: { // Kekkei Genkai #########
int escolha_sub_habilidade;
do {
    printf("--- Kekkei Genkai ---\n");
    printf("1. Estilo Madeira (Hashirama)\n");
    printf("2. Estilo Gelo (Haku)\n");
    printf("3. Estilo Poeira (Mu, Oonoki)\n");
    printf("4. Estilo Magnetismo (Terceiro Kazekage, Toroi)\n");
    printf("5. Estilo Lava (Mei Terumi)\n");
    printf("6. Estilo Chama (Sasuke)\n");
    printf("7. Meiton (Liberacao de Escuridao)\n");
    printf("8. Koton (Liberacao de Aco)\n");
    printf("9. Jinton (Liberacao de Velocidade)\n");
    printf("10. Ranton (Liberacao de Tempestade)\n");
    printf("11. Bakuton (Liberacao de Explosao) (DARUI)\n");
    printf("12. Controle dos Ossos\n");
    printf("13. Controle da Areia\n");
    printf("14. Controle de Crystal\n");
    printf("15. Estilo Vapor (Mei)\n");
    printf("16. Estilo Lava (Mei)\n");
    printf("17. Estilo Calor (Bakura)\n");
    printf("18. Estilo Explosao (Deidara)\n");
    printf("19. Estilo Tufao (Deidara)\n");
    printf("20. Estilo Papel (Konah)\n");
    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma habilidade: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch(escolha_sub_habilidade) {
        case 1: poder_luta += 40; break;   // Madeira: altíssimo controle, defesa e ataque
        case 2: poder_luta += 8; break;    // Gelo: utilidade defensiva e ofensiva média
        case 3: poder_luta += 50; break;   // Poeira: destruição em massa, letalidade muito alta
        case 4: poder_luta += 20; break;   // Magnetismo: tático, bom controle de inimigos
        case 5: poder_luta += 25; break;   // Lava: ataque forte e letal
        case 6: poder_luta += 30; break;   // Chama: ataque contínuo e forte
        case 7: poder_luta += 35; break;   // Meiton: habilidades únicas de dano e absorção
        case 8: poder_luta += 28; break;   // Koton: armadura e ataque defensivo
        case 9: poder_luta += 33; break;   // Jinton: velocidade e impacto em combate
        case 10: poder_luta += 30; break;  // Ranton: ataques combinados, versátil
        case 11: poder_luta += 32; break;  // Bakuton: explosão e destruição de área
        case 12: poder_luta += 22; break;  // Ossos: utilidade ofensiva/defensiva média
        case 13: poder_luta += 25; break;  // Areia: controle e defesa média-alta
        case 14: poder_luta += 30; break;  // Crystal: ataque forte e letal
        case 15: poder_luta += 27; break;  // Vapor: versátil e rápido
        case 16: poder_luta += 28; break;  // Lava: ataque poderoso
        case 17: poder_luta += 26; break;  // Calor: dano contínuo e tático
        case 18: poder_luta += 40; break;  // Explosão Deidara: destruição em massa, letalidade máxima
        case 19: poder_luta += 35; break;  // Tufao: ataque surpresa, bastante letal
        case 20: poder_luta += 15; break;  // Papel: ataque rápido, letalidade média
        default: printf("Opcao invalida.\n");
    }
} while(escolha_sub_habilidade != 0);
break;

            }

            case 10: { // Habilidades ########

                int escolha_sub_habilidade;
                do {
                    printf("--- Habilidades Especiais ---\n");
                    printf("1. Regeneracao (Tsunade, Hashirama/Goku)\n");
                    printf("2. Arte Eremita: Portao Divino (Hashirama)\n");
                    printf("3. As Verdadeiras Mil Maos (Hashirama)\n");
                    printf("4. Estilo Madeira: Tecnica da Grande Floresta (Hashirama)\n");
                    printf("5. Invocacao: Rashomon (cirar grandes páredespara parar o ataque) (Hashirama)\n");
                    printf("6. Karma (Boruto)\n");
                    printf("7. Esferas da Busca da Verdade e Hakai (Gudodama)\n");
                    printf("8. Super Força (Sasuke e Tsunade)\n");
                    printf("9. Imortalidade (Hidan/ kakuzu)\n");
                    printf("10. Substituição (Kakashi)\n");
                    printf("11. Clone (Naruto e Goku)\n");
                    printf("12. Ninja medico\n");
                    printf("13. Ninja sensorial\n");
                    printf("14. Jutsus de cobras (Orochimaru)\n");
                    printf("15. Jutsus de cabelo (Jiraya)\n");
                    printf("16. Fica invisível\n");
                    printf("17. Voar\n");
                    printf("18. Dispersão de vírus (Boro)\n");
                    printf("19. Gás corrosivo (Boro)\n");
                    printf("20. Rajadas de poder (Delta e Goku)\n");
                    printf("21. Alta velocidade (Goku, Minato, Tobirama)\n");
                    printf("22. Resistência (Goku, Naruto)\n");
                    printf("23. Imagem residual (Goku, Shisui)\n");
                    printf("24. Barreira de Ki (Goku, Vegeta)\n");
                    printf("25. Kamehameha/Galik Ho/Big Bang Attack (Goku, Goten)\n");
                    printf("26. Kienzan (Ki de corte) (Goku, Kuririn)\n");
                    printf("27. Telecinese (Goku, Frieza)\n");
                    printf("28. Jekedama (Goku)\n");
                    printf("29. Troca de corpo (Goku)\n");
                    printf("30. Absorver energia (Android 17)\n");
                    printf("31. Energia infinita (Android 17)\n");
                    printf("32. Controlar pessoas (Baby)\n");
                    printf("33. Armas feitas de energia (Goku Black)\n");
                    printf("34. Salto no tempo (Hit)\n");
                    printf("35. Makankosappo (Piccolo)\n");
                    printf("36. Crescer de altura (Piccolo)\n");
                    printf("0. Finalizar e voltar ao menu principal\n");
                    printf("Escolha uma habilidade: ");
                    scanf("%d", &escolha_sub_habilidade);
                    if (escolha_sub_habilidade == 0) break;

                    switch (escolha_sub_habilidade) {
                        case 1: poder_luta += 10; break;      // Regeneração: aumenta a durabilidade em combate, essencial defensivamente
                        case 2: poder_luta += 40; break;      // Portão Divino: boost extremo de combate corpo-a-corpo
                        case 3: poder_luta += 200; break;      // Mil mãos: domínio total ofensivo, letalidade muito alta
                        case 4: poder_luta += 20; break;      // Grande Floresta: controle de campo, útil para ofensiva e defesa
                        case 5: poder_luta += 25; break;      // Rashomon: defesa poderosa, boa relevância estratégica
                        case 6: poder_luta += 35; break;      // Karma: potencial de ataque e defesa, relevante taticamente
                        case 7: poder_luta += 50; break;      // Esferas/Hakai: letalidade extrema, destruição massiva
                        case 8: poder_luta += 65; break;     // Super Força: letalidade máxima em combate corpo-a-corpo
                        case 9: poder_luta += 25; break;     // Imortalidade Hidan: resistência alta, letalidade limitada
                        case 10: poder_luta += 10; break;     // Substituição: utilidade tática, evasão relevante
                        case 11: poder_luta += 25; break;     // Clone: aumenta presença em campo, útil ofensiva e defensivamente
                        case 12: poder_luta += 15; break;     // Ninja médico: suporte, combate indireto
                        case 13: poder_luta += 15; break;     // Ninja sensorial: prevenção de emboscadas, controle de informação
                        case 14: poder_luta += 30; break;     // Cobras: ataque versátil, utilidade média-alta
                        case 15: poder_luta += 20; break;     // Cabelo: ataque de média relevância
                        case 16: poder_luta += 25; break;     // Invisibilidade: emboscadas e furtividade, alta relevância tática
                        case 17: poder_luta += 30; break;     // Voar: mobilidade, ataque e evasão melhorados
                        case 18: poder_luta += 40; break;     // Dispersão de vírus: ataque em massa, letalidade alta
                        case 19: poder_luta += 35; break;     // Gás corrosivo: ataque contínuo e controle de campo
                        case 20: poder_luta += 40; break;     // Rajadas de poder: ofensiva direta, letalidade alta
                        case 21: poder_luta += 45; break;     // Alta velocidade: combate decisivo e evasão, relevância alta
                        case 22: poder_luta += 40; break;     // Resistência: prolonga combates, relevante defensivamente
                        case 23: poder_luta += 25; break;     // Imagem residual: confunde inimigos, tática média
                        case 24: poder_luta += 30; break;     // Barreira de Ki: defesa sólida, bom controle de campo
                        case 25: poder_luta += 50; break;    // Kamehameha/Galik/Big Bang: letalidade máxima, multiplicador ofensivo
                        case 26: poder_luta += 25; break;     // Kienzan: ataque preciso e letal
                        case 27: poder_luta += 30; break;     // Telecinese: controle do oponente, letalidade média-alta
                        case 28: poder_luta += 35; break;     // Jekedama: ataque explosivo, alta letalidade
                        case 29: poder_luta += 40; break;     // Troca de corpo: controle estratégico do combate
                        case 30: poder_luta += 35; break;     // Absorver energia: reduz recursos do inimigo, relevância alta
                        case 31: poder_luta += 25; break;     // Energia finita: efeito limitado, utilidade média
                        case 32: poder_luta += 40; break;     // Controlar pessoas: manipulação de combate, letalidade alta
                        case 33: poder_luta += 40; break;     // Armas de energia: ofensiva potente, letalidade alta
                        case 34: poder_luta += 100; break;   // Salto no tempo: tática decisiva, multiplicador de relevância
                        case 35: poder_luta += 70; break;    // Makankosappo: letalidade máxima, multiplicador de ataque
                        case 36: poder_luta += 10 ; break;    // aumentar altura
                        default: printf("Opcao invalida.\n");
                    }
                } while (escolha_sub_habilidade != 0);
                    break;

                            }

           case 11: { // KI ou Chakra #########
int escolha_sub_habilidade;
do {
    printf("\n--- KI ou Chakra ---\n");
    printf("Naruto (Chakra):\n");
    printf(" 1. Pouco chakra (genin fraco)\n");
    printf(" 2. Chakra normal e sayan din baixo nivel(chunin,raditz)\n");
    printf(" 3. Chakara medio e syajin nivel medio ( junin  e nappa)\n");
    printf(" 4. Muito chakra e sayan din alto nivel(kage comum)\n");
    printf(" 5. Chakra monstruoso e tropa ginyu (kage de alto nivel jinchuuriki)\n");
    printf(" 6. Freeza forma final(frieza)\n");
    printf(" 7. ssj 2  e biju ( )\n");
    printf(" 8. ssj 3 e uzumaki\n");
    printf(" 9. mistico e chakra espansivo(hashirama e madara)\n");
    printf(" 10. ssj 4 e outsukiki(goku ssj 4,sheron)\n");
    printf(" 11. ssj god e hagoromo\n");
    printf(" 12. Super Saiyajin Blue e kaguya (hit torneio do pode/ toppo e kaguya)\n");
    printf(" 13. Super Saiyajin Blue evolution(hit torneio do pode/ toppo)\n");
    printf(" 14. Ultra Instinct(jiren)\n");
    printf(" 15. hakai\n");
    printf(" 16. anjo\n");
    printf(" 17. daishikan\n");
    printf(" 18. zeno\n");
    printf(" 19. Chakara do Hagoromo (Sasuke, Naruto)\n");
    printf("\n0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma habilidade: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch (escolha_sub_habilidade) {
        case 1: poder_luta += 1; break;   // Pouco chakra: impacto quase nulo
        case 2: poder_luta += 5; break;   // Chakra baixo: ligeira melhora
        case 3: poder_luta += 10; break;    // Chakra médio: utilidade pequena-média
        case 4: poder_luta += 20; break;    // Muito chakra: combate mais eficiente
        case 5: poder_luta += 30; break;     // Chakra monstruoso: combate de alto nível
        case 6: poder_luta += 50; break;       // Chakra imenso: impacto decisivo
        case 7: poder_luta += 100; break;       // SSJ2: grande aumento de letalidade
        case 8: poder_luta += 200; break;       // SSJ3: destruição extrema
        case 9: poder_luta += 300; break;      // Místico: controle de combate elevado
        case 10: poder_luta +=400; break;      // SSJ4: letalidade máxima corpo-a-corpo
        case 11: poder_luta += 500; break;      // Chakra divino / SSJ God: destruição massiva
        case 12: poder_luta += 550; break;     // SSJ Blue: letalidade extrema
        case 13: poder_luta += 570; break;     // SSJ Blue Evolution: versão aprimorada
        case 14: poder_luta += 1000; break;     // Ultra Instinct: combate quase perfeito
        case 15: poder_luta += 5000; break;     // Hakai: destruição total
        case 16: poder_luta += 10000; break;     // Anjo: poder esmagador
        case 17: poder_luta += 100000; break;     // Daishinkan: letalidade e controle total
        case 18: poder_luta += 1000000; break;    // Zeno: destruição universal instantânea
        case 19: poder_luta += 500; break;    // +  chakra do hagoromo
        default: printf("Opcao invalida.\n");
    }
} while (escolha_sub_habilidade != 0);
break;

}
//--------------------------------------------------------------------------------------------------------------------

            case 12: { // Senjutsu e Marcas da Maldicao #############
int escolha_sub_habilidade;
do {
    printf("--- Senjutsu e Marcas da Maldicao ---\n");
    printf("1. Modo Sabio (Jiraiya)\n");
    printf("2. Modo Eremita das Cobras (Kabuto)\n");
    printf("3. Modo Sabio com Senjutsu da Floresta (Hashirama)\n");
    printf("4. Marca da maldição nivel 1\n");
    printf("5. Marca da maldição nivel 2\n");
    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma transformacao: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch (escolha_sub_habilidade) {
        case 1:
            poder_luta += 65+ 45 + 15 + 40 +10 ;  // força + velocidade + sensorial + rsistencia + taijutsu do sapos
            printf("Modo Sabio ativado.\n");
            break;
        case 2:
            poder_luta += 65+ 45 + 15 + 40 + 10 + 20 ;  // força + velocidade + sensorial + rsistencia  + ante genjutsu + fundir com  o terreno
            printf("Modo Eremita das Cobras ativado.\n");
            break;
        case 3:
            poder_luta += 65+ 45 + 15 + 40 + 20;  // força + velocidade + sensorial + rsistencia + chakara
            printf("Modo Sabio com Senjutsu da Floresta ativado.\n");
            break;
        case 4:
            poder_luta += 30+ 20 + 15 ; //// força + velocidade + chakra +
            printf("Marca da maldição 1.\n");
            break;
        case 5:
            poder_luta += 65+ 45 + 15 + 40; // // força + velocidade + chakra + rsistencia
            printf("Marca da maldição 2 .\n");
            break;
        default:
            printf("Opcao invalida.\n");
    }
} while (escolha_sub_habilidade != 0);
break;

            }

            case 13: { // Jinchuriki e Transformacoes ###################
int escolha_sub_habilidade;
do {
    printf("--- Jinchuriki e Transformacoes ---\n");
    printf("1. Gaara (Shukaku) \n");
    printf("2. Yugito Nii (Matatabi)\n");
    printf("3. Yagura (Isobu)\n");
    printf("4. Roshi (Son Goku)\n");
    printf("5. Han (Kokuo)\n");
    printf("6. Utakata (Saiken)\n");
    printf("7. Fu (Chomei)\n");
    printf("8. Killer B (Gyuki)\n");
    printf("9. Naruto (Kurama)\n");
    printf("10. Modo Rikudou (Naruto)\n");
    printf("11. Modo Baryon (Naruto)\n");
    printf("12. Dez Caudas\n");
    printf("13. Kaioken 2x\n");
    printf("14. Kaioken 5x\n");
    printf("15. Kaioken 10x e Oozaru\n");
    printf("16. Kaioken 20x\n");
    printf("17. Super Saiyan Din 1\n");
    printf("18. Super Saiyan Din 2\n");
    printf("19. Super Saiyan Din 3\n");
    printf("20. Super Saiyan Din Mistico\n");
    printf("21. Super Saiyan Din 4 e Oozaru Dourado\n");
    printf("22. Super Saiyan Din God\n");
    printf("23. Super Saiyan Din Blue\n");
    printf("24. Super Saiyan Din Blue Evolution\n");
    printf("25. Ultra Instinto Incompleto\n");
    printf("26. Ultra Instinto Completo e Ego Superior\n");
    printf("27. Segunda Forma Especial\n");
    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma transformacao: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch(escolha_sub_habilidade) {
        case 1: poder_luta += 10; break;    // Shukaku: bom controle de areia, letalidade moderada
        case 2: poder_luta += 20; break;    // Matatabi: velocidade e poder de fogo aumentados
        case 3: poder_luta += 30; break;    // Isobu: defesa alta, ataque médio
        case 4: poder_luta += 40; break;    // Son Goku: ataque e velocidade equilibrados
        case 5: poder_luta += 50; break;    // Kokuo: força física e velocidade grandes
        case 6: poder_luta += 60; break;    // Saiken: ataque em área, utilidade tática
        case 7: poder_luta += 70; break;    // Chomei: voo e mobilidade elevada
        case 8: poder_luta += 80; break;    // Gyuki: força e defesa extremas
        case 9: poder_luta += 90; break;    // Kurama: força, velocidade e chakra massivos
        case 10: poder_luta += 50; break;   // Modo Rikudou: aumento significativo de chakra e habilidades
        case 11: poder_luta += 100; break;  // Modo Baryon: letalidade máxima temporária
        case 12: poder_luta += 500; break;  // Dez Caudas: destruição em larga escala
        case 13: poder_luta += 2; break; // Kaioken 2x
        case 14: poder_luta += 5; break;  // Kaioken 5x
        case 15: poder_luta += 10; break; // Kaioken 10x ou Oozaru
        case 16: poder_luta += 20; break;  // Kaioken 20x
        case 17: poder_luta += 50; break;    // Super Saiyan Din 1
        case 18: poder_luta += 100; break;    // Super Saiyan Din 2
        case 19: poder_luta += 200; break;    // Super Saiyan Din 3
        case 20: poder_luta += 300; break;    // Super Saiyan Mistico
        case 21: poder_luta += 400; break;    // Super Saiyan 4 + Oozaru Dourado
        case 22: poder_luta += 500; break;   // Super Saiyan God
        case 23: poder_luta += 550; break;   // Super Saiyan Blue
        case 24: poder_luta += 570; break;   // Super Saiyan Blue Evolution
        case 25: poder_luta += 800; break;   // Ultra Instinto Incompleto
        case 26: poder_luta += 1000; break;   // Ultra Instinto Completo + Ego Superior
        case 27: poder_luta += 10; break;  // Segunda forma especial
        default: printf("Opcao invalida.\n");
    }
} while(escolha_sub_habilidade != 0);
break;

            }

            case 14: { // Jutsus de Clã #########
int escolha_sub_habilidade;
do {
    printf("--- Jutsus de Cla ---\n");
    printf("1. Clan Akimichi (Expansao de corpo)\n");
    printf("2. Clan Nara (Manipulacao de Sombras)\n");
    printf("3. Clan Yamanaka (Troca de mentes)\n");
    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma habilidade: ");
    scanf("%d", &escolha_sub_habilidade);
    if (escolha_sub_habilidade == 0) break;

    switch (escolha_sub_habilidade) {
        case 1:
            poder_luta += 25; // Akimichi: dano físico e defesa aumentada, bom em combate direto
            break;
        case 2:
            poder_luta += 30; // Nara: controle de inimigos, letalidade estratégica alta
            break;
        case 3:
            poder_luta += 20; // Yamanaka: controle de mentes, útil taticamente, letalidade indireta
            break;
        default:
            printf("Opcao invalida.\n");
    }
} while (escolha_sub_habilidade != 0);
break;

            }

            case 15: { // Armas Ninjas ###########
int escolha_sub_habilidade;
do {
    printf("--- Armas Ninjas ---\n");
    printf("1. Katana/Espada\n");
    printf("2. Shuriken\n");
    printf("3. Kunai\n");
    printf("4. Fios de Aco\n");
    printf("5. Bomba de Fumaca\n");
    printf("6. Bomba de Luz \n");
    printf("7. Papel Bomba \n");
    printf("8. Pergaminho de Armas (Ten-ten)\n");
    printf("9. Laminas de Chakra (Asuma Sarutobi)\n");
    printf("10. Foice de Lamina Tripla (Hidan)\n");
    printf("11. Massa Crustacea (Kotetsu) \n");
    printf("12. Frauta Demoniaca (Tayuya) \n");
    printf("13. Papel de Selamento\n");
    printf("14. Leque Gigante (Temari)\n");
    printf("15. Espada Retratil (Darui)\n");
    printf("16. Espada Kusanagi (Orochimaru, Sasuke)\n");
    printf("17. Gunbai (Leque que absorve ataque) (Madara)\n");
    printf("18. Bastao Ema (Hiruzen)\n");
    printf("20. Canhoes de Som (Dosu)\n");
    printf("21. Espada da nevoa Kubikiriboshi (Zabuza)\n");
    printf("22. Espada da nevoa Hiramekarei (Mangetsu)\n");
    printf("23. Espada da nevoa Nuibari (Kushimaru)\n");
    printf("24. Espada da nevoa Kabutowari (Jinin)\n");
    printf("25. Espada da nevoa Kiba (Amerili)\n");
    printf("26. Espada da nevoa Shibuki (Jimpachi)\n");
    printf("27. Espada da nevoa Samehada (Kisame/Fuguki)\n");
    printf("28. Bastao da Verdade (Hagoromo/Obito)\n");
    printf("29. Bastao Magico (Goku)\n");

    printf("0. Finalizar e voltar ao menu principal\n");
    printf("Escolha uma arma: ");
    scanf("%d", &escolha_sub_habilidade);

    if (escolha_sub_habilidade == 0) break;

    switch (escolha_sub_habilidade) {
        case 1: poder_luta += 5; break;   // Katana/Espada: arma básica corpo-a-corpo
        case 2: poder_luta += 2; break;  // Shuriken: ataque a distância leve
        case 3: poder_luta += 2; break;   // Kunai: ataque a distância ou corpo-a-corpo
        case 4: poder_luta += 2; break;  // Fios de aço: controle e ataque estratégico
        case 5: poder_luta += 1; break;  // Bomba de fumaça: utilidade tática
        case 6: poder_luta += 1; break;  // Bomba de luz: distração
        case 7: poder_luta += 4; break;  // Papel Bomba: dano leve
        case 8: poder_luta += 1; break;   // Pergaminho de armas: versátil, ataques variados
        case 9: poder_luta += 7; break;   // Laminas de Chakra: letalidade aumentada
        case 10: poder_luta += 10; break;  // Foice de Lamina Tripla: dano e alcance
        case 11: poder_luta += 10; break; // Massa Crustácea: dano limitado, útil taticamente
        case 12: poder_luta += 10; break; // Frauta Demoníaca: genjutsu ofensivo
        case 13: poder_luta += 1; break;  // Papel de Selamento: útil em combate estratégico
        case 14: poder_luta += 10; break;  // Leque Gigante: ataques de vento, controle de área
        case 15: poder_luta += 6; break; // Espada Retrátil: dano médio
        case 16: poder_luta += 8; break;  // Espada Kusanagi: alta letalidade, versátil
        case 17: poder_luta += 20; break;    // Gunbai: absorve ataques, defesa + ofensiva
        case 18: poder_luta += 10; break;  // Bastão Ema: poder de ataque moderado
        case 20: poder_luta += 10; break; // Canhões de Som: dano à distância, impacto tático
        case 21: poder_luta += 10; break;  // Kubikiriboshi: espada de combate direto
        case 22: poder_luta += 10; break;  // Hiramekarei: vantagem tática significativa
        case 23: poder_luta += 10; break;  // Nuibari: perfuração e controle
        case 24: poder_luta += 10; break;  // Kabutowari: penetrante, supera defesas
        case 25: poder_luta += 10; break;    // Kiba: ataque elétrico, dano elevado
        case 26: poder_luta += 10; break;  // Shibuki: explosivo, tático
        case 27: poder_luta += 20; break;    // Samehada: absorve chakra, muito estratégico
        case 28: poder_luta += 50; break;   // Bastão da Verdade: ataque divino, destruição massiva
        case 29: poder_luta += 10; break;    // Bastão Mágico: poder ofensivo considerável
        case 0: break;
        default: printf("Opcao invalida.\n");
    }
} while (escolha_sub_habilidade != 0);
break;

            }

            default: {
                printf("Opcao de categoria invalida. Tente novamente.\n\n");

    }
    }

    }while (escolha_categoria != 0);

    printf("\n--- CALCULO FINAL DE PODER DE LUTA ---\n");
    printf("Seu Poder de Luta Total é: %f\n", poder_luta);
    printf("Obrigado por usar a Calculadora de Poder Ninja!\n\n\n\n\n");

    return 0;
}


