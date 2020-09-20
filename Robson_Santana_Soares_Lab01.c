/***********************************/
/* Aluno: Robson Santana Soares    */
/* Linguagem de Programação        */
/* Prof. Eliane                    */
/***********************************/

#include <stdio.h>
#include <string.h>

// função para avaliar se possui direito ao benefício
int avaliacaoDeRequisitos();

// funcoes para averiguar condicoes de cada empregador
int trabalhadorFormal();
int trabalhadorDomestico();
int pescadorArtesanal();
int trabalhadorResgatado();

// funcoes para calcular quanto o trabalhador receberá de seguro-desemprego
int calculoDoPagamento();

// funcoes auxiliares para a calculoDoPagamento
int calculoDeParcelas(int);
double mediaSalarial(double, double, double);
double valorDoBeneficio(double);


int main(void)
{
    int opcao = 0, confirmacao = 0; 

    opcao = avaliacaoDeRequisitos(); // chama a função de averiguar direito e atribui resultado à variável opcao

    switch (opcao)
    {
        case 1:
            printf("\n\n\n\n\n");
            confirmacao = trabalhadorFormal();

            printf("\n\nTrabalhador tem direito ao beneficio");

            if(confirmacao == 1)
            {
                printf("\nTrabalhador atende as condicoes para receber o beneficio");          
                printf("\n\n\n\n\n");
                calculoDoPagamento();
            }
            else if(confirmacao == 0)
                printf("\nTrabalhador NAO ATENDE as condicoes para receber o beneficio");
            break;

        case 2:
            printf("\n\n\n\n\n");
            confirmacao = trabalhadorDomestico();

            printf("\n\nTrabalhador tem direito ao beneficio");

            if(confirmacao == 1)
            {
                printf("\nTrabalhador atende as condicoes para receber o beneficio");
                printf("\n\n\n\n\n");
                calculoDoPagamento();
            }
            else if(confirmacao == 0)
                printf("\nTrabalhador NAO ATENDE as condicoes para receber o beneficio");
            break;

        case 3:
            printf("\n\n\n\n\n");
            confirmacao = trabalhadorResgatado();

            printf("\n\nTrabalhador tem direito ao beneficio");

            if(confirmacao == 1)
            {
                printf("\nTrabalhador atende as condicoes para receber o beneficio");
                printf("\n\n\n\n\n");
                calculoDoPagamento();
            }
            else if(confirmacao == 0)
                printf("\nTrabalhador NAO ATENDE as condicoes para receber o beneficio");
            break;

        case 4:
            printf("\n\n\n\n\n");
            confirmacao = pescadorArtesanal();

            printf("\n\nTrabalhador tem direito ao beneficio");

            if(confirmacao == 1)
            {
                printf("\nTrabalhador atende as condicoes para receber o beneficio");
                printf("\n");
                  
                printf("\n\n\n\n\n");
                calculoDoPagamento();
            }
            else if(confirmacao == 0)
                printf("\nTrabalhador NAO ATENDE as condicoes para receber o beneficio");
                break;

        default:
            break;
    }
}


int avaliacaoDeRequisitos()
{
    int resposta[6];

    printf("Formulario para averiguacao de disponibilidade do Seguro-Desemprego\n");
    printf("\nE trabalhador formal?.....................................................: ");
    resposta[0] = getchar();
    scanf("%*c", &resposta[0]);

    printf("\n\nFoi dispensado por demissao indireta?.....................................: ");
    resposta[1] = getchar();
    scanf("%*c", &resposta[1]);

    printf("\n\nFoi dispensado sem justa causa?...........................................: ");
    resposta[2] = getchar();
    scanf("%*c", &resposta[2]);

    if((resposta[1]  == 's') || (resposta[2] == 's'))
    {
        printf("\n\nE empregado domestico?....................................................: ");
        resposta[3] = getchar();
        scanf("%*c", &resposta[3]); 
        
        if(resposta[3] == 's')
            return 2;
        else
        {
            printf("\n\nE trabalhador resgatado?..................................................: ");
            resposta[4] = getchar();
            scanf("%*c", &resposta[4]);

            if(resposta[4] == 's')
                return 3;
            else
            {
                printf("\n\nE pescador profissional?..................................................: ");
                resposta[5] = getchar();
                scanf("%*c", &resposta[5]);

                if(resposta[5] == 's')
                    return 4;
            }
        }
    }

    if((resposta[0] == 's') && (resposta[3] == 'n') && (resposta[4] == 'n') && (resposta[5] ==  'n'))
        return 1;
    else 
        return 0;
}


int trabalhadorFormal()
{
    char r2[6];

    printf("Foi dispensado sem justa causa?[s/n]\nResposta.................: ");
    r2[0] = getchar(); 
    scanf("%*c", &r2[0]);
    
    printf("\nRecebeu salarios de pessoa juridica ou pessoa fisica, no periodo de 6 meses consecutivos?[s/n]\nResposta.................: ");
    r2[1] = getchar();
    scanf("%*c", &r2[1]);
    
    printf("\nEsta desempregado quando do requerimento do beneficio?[s/n]\nResposta.................: ");
    r2[2] = getchar();
    scanf("%*c", &r2[2]);
    
    printf("\nPossui renda propria de qualquer natureza suficiente a sua manutencao e a de sua familia?[s/n]\nResposta.................: ");
    r2[3] = getchar();
    scanf("%*c", &r2[3]);
       
    printf("\nEsta em gozo de qualquer beneficio previdenciario de prestacao continuada, com excecao do auxilio-acidente e pensao por morte?[s/n]\nResposta.................: ");
    r2[4] = getchar();
    scanf("%*c", &r2[4]);
       
    printf("\nFoi empregado de pessoa juridica ou de pessoa fisica equiparada a juridica, pelo menos 6 meses nos ultimos 36 meses?[s/n]\nResposta.................: ");
    r2[5] = getchar(); 
    scanf("%*c", &r2[5]);

    if((r2[0] == 's') && (r2[1] == 's') && (r2[2] == 's') && (r2[3] ==  'n') && (r2[4] ==  'n') && (r2[5] == 's'))
        return 1;
    else 
        return 0;
}

int trabalhadorDomestico()
{   
    char r2[6];

    printf("Foi dispensado sem justa causa?[s/n]\nResposta.................: ");
    r2[0] = getchar(); 
    scanf("%*c", &r2[0]);
    
    printf("\nTrabalhou, exclusivamente, como empregado domestico, pelo periodo minimo de 15 meses nos ultimos 24 meses?[s/n]\nResposta.................: ");
    r2[1] = getchar();
    scanf("%*c", &r2[1]);
      
    printf("\nEsta desempregado quando do requerimento do beneficio?[s/n]\nResposta.................: ");
    r2[2] = getchar();
    scanf("%*c", &r2[2]);
    
    printf("\nPossui renda propria de qualquer natureza suficiente a sua manutencao e a de sua familia?[s/n]\nResposta.................: ");
    r2[3] = getchar(); 
    scanf("%*c", &r2[3]);
    
    printf("\nEsta em gozo de qualquer beneficio previdenciario de prestacao continuada, com excecao do auxilio-acidente e pensao por morte?[s/n]\nResposta.................: ");
    r2[4] = getchar(); 
    scanf("%*c", &r2[4]);  

    if((r2[0] == 's') && (r2[1] == 's') && (r2[2] == 's') && (r2[3] == 'n') && (r2[4] == 'n'))
        return 1;
    else
        return 0;
}

int pescadorArtesanal()
{ 
    char r2[6] = {0};

    printf("Possui inscricao no INSS como segurado especial?[s/n]\nResposta.................: ");
    r2[0] = getchar(); 
    scanf("%*c", &r2[0]);

    printf("\nPossui comprovacao de venda do pescado a adquirente pessoa juridica ou cooperativa, \nno periodo correspondente aos ultimos 12 meses?[s/n]\nResposta.................: ");
    r2[1] = getchar();
    scanf("%*c", &r2[1]);

    printf("\nEsta em gozo de algum beneficio de prestacao continuada da Previdencia Social ou da Assistencia Social, \nexceto auxilio-acidente ou pensao por morte.?[s/n]\nResposta.................: ");
    r2[2] = getchar();
    scanf("%*c", &r2[2]);
    
    printf("\nComprovou o exercicio profissional da atividade de pesca artesanal objeto do defeso e se dedicou a pesca\ndurante o periodo compreendido entre o defeso anterior e o em curso?[s/n]\nResposta.................: ");
    r2[3] = getchar(); 
    scanf("%*c", &r2[3]);
      
    printf("\nTem vinculo de emprego ou outra relacao de trabalho ou outra fonte de renda diversa\nda decorrente da atividade pesqueira?[s/n]\nResposta.................: ");
    r2[4] = getchar();
    scanf("%*c", &r2[4]);

    if(r2[0] == 's' && r2[1] == 's' && r2[2] == 'n' && r2[3] == 's' && r2[4] == 'n')
        return 1;
    else
        return 0;
}

int trabalhadorResgatado()
{
    char r2[3];

    printf("Foi comprovadamente resgatado do regime de trabalho forcado ou da condicao analoga a de escravizado em decorrencia de acao de fiscalizacao do MTE?[s/n]\nResposta.................:  ");
    r2[0] = getchar(); 
    scanf("%*c", &r2[0]);

    printf("\n\nEsta em gozo de qualquer beneficio previdenciario de prestacao continuada, com excecao do auxilio-acidente e pensao por morte?[s/n]\nResposta.................: ");
    r2[1] = getchar();
    scanf("%*c", &r2[0]);

    printf("\n\nPossui renda propria de qualquer natureza suficiente a sua manutencao e a de sua familia?[s/n]\nResposta.................: ");
    r2[2] = getchar();
    scanf("%*c", &r2[0]);

    if(r2[0] == 's' && r2[1] == 'n' && r2[2] == 'n')
        return 1;
    else
        return 0;
}

int calculoDoPagamento()
{
    int resposta;
    double salarioUltimoMes, salarioPenultimoMes, salarioAntepenultimoMes, mediaDoSalario;
    
    printf("Calculo de parcelas..................................: \n");
    printf("\nTempo de vinculo empregaticio em numero de meses.....: ");
    scanf("%d", &resposta);

    printf("\n[A] Salario do ultimo mes............................: ");
    scanf("%lf", &salarioUltimoMes);
    
    printf("\n[B] Salario do penultimo mes.........................: ");
    scanf("%lf", &salarioPenultimoMes);
    
    printf("\n[C] Salario do antepenultimo mes.....................: ");
    scanf("%lf", &salarioAntepenultimoMes);

    mediaDoSalario = mediaSalarial(salarioUltimoMes, salarioPenultimoMes, salarioAntepenultimoMes); 
   
    printf("\n\nMedia salarial (A + B + C) / 3......................: %.2lf", mediaDoSalario);

    printf("\n\nQuantidade de parcelas..............................: %d ", calculoDeParcelas(resposta));

    printf("\n\nValor do beneficio..................................: %.2lf\n\n\n\n", valorDoBeneficio(mediaDoSalario));

    return 0;
}

// funcao para calcular o numero de parcelas
int calculoDeParcelas(int numeroDeParcelas)
{
    int quantidadeDeParcelas;
    if (numeroDeParcelas >= 6 && numeroDeParcelas <= 11)
        quantidadeDeParcelas = 3;
    else if(numeroDeParcelas >= 12 && numeroDeParcelas <= 23)
        quantidadeDeParcelas = 4;
    else if (numeroDeParcelas >= 24 && numeroDeParcelas <= 36)
        quantidadeDeParcelas = 5;

    return quantidadeDeParcelas;
}

// funcao para calcular a media salarial
double mediaSalarial(double salario1, double salario2, double salario3)
{
    double mediaSalarial;
    
    if(salario1 > 0 && salario2 > 0 && salario3 > 0)
        mediaSalarial = (salario1 + salario2 + salario3) / 3;
    else if(salario1 > 0 && salario2 > 0 && salario3 == 0)
        mediaSalarial = (salario1 + salario2) / 2;
    else if(salario1 == 0 && salario2 > 0 && salario3 > 0)
        mediaSalarial = (salario2 + salario3) / 2;
    else if(salario1 > 0 && salario2 == 0 && salario3 > 0)
        mediaSalarial = (salario1 + salario3) / 2;
    else if(salario1 > 0 && salario2 == 0 && salario3 == 0)
        mediaSalarial = salario1;

    return mediaSalarial;     
}

// funcao para calcular o valor final do beneficio
double valorDoBeneficio(double media)
{
    double valorDoBeneficio;
    if(media <= 1222.77)
        valorDoBeneficio = (media > 788) ? media * 80 / 100 : 788;  
    
    else if(media > 1222.77 && media <= 2038.15)
        valorDoBeneficio = ((media - 1222.77) * 50/100) + 978.22 ;
    else if(media > 2038.55)
        valorDoBeneficio = 1385.91;

    return valorDoBeneficio;
}
