/**
 * @file    GABARITO_12_13_4.c
 * @author  Diego Anestor Coutinho
 * @date    Mai 2022
 *
 * O algoritmo é uma possível resolução para o(s) exercício(s) avaliativo(s).
 * EM CASO DE DÚVIDA PROCURE POR UM MONITOR, FAREMOS O MELHOR PARA LHE AJUDAR.
 */

/* EXERCÍCIO DOS DIAS 10-11/05/2022:

O dono de uma fábrica lhe contratou para implementar um sistema que separa os produtos
ruins em uma linha de produção de maneira semi automática. O sistema classifica o estado
do produto como “1” = peça defeituosa, e “0” = normal. O estado de uma esteira com
capacidade de 8 peças é armazenado em uma variável de 8 bits, e para cada peça na última
posição, um LED VERMELHO acende para indicar sempre que ela é defeituosa. E a esteira
é movida por uma interrupção no sistema acionado por um botão S1.

No caso de encontrar uma peça com defeito, o sistema despacha a peça para outra esteira de 8 posições,
sempre colocando a peça com defeito na primeira posição, e movendo o resto para frente.

No fim do lote, o sistema deve mover os itens com defeito para outro local,
e para cada peça com defeito que passa pela primeira posição da esteira 2,
deve acender um LED AMARELO para indicá-lo.

*/

// Variáveis para aplicação na lógica do programa
unsigned char esteira_1 = 0b01011000;
unsigned char esteira_2 = 0;
unsigned char lote = 0;

// Função ISR para o botão S1
ISR(INT0_vect)
{
    // Adiciona mais 1 na contagem do lote
    lote++;

    // Se o último bit da variável esteira_1 for 1
    if (esteira_1 & 0b00000001)
    {
        // Liga o LED VERMELHO
        PORTD |= (1 << PD7);

        // Delay de 100ms
        _delay_ms(100);

        // Desliga o LED VERMELHO
        PORTD &= ~(1 << PD7);

        // Desloca todos os bits para direita
        esteira_1 >>= 1;

        // Movimenta os bits da esteira_2 para a esquerda e
        // Introduz um bit 1 na última posição de esteira_2
        esteira_2 <<= 1;
        esteira_2 |= 1;
    }

    else
    {
        // Desloca todos os bits para direita
        esteira_1 >>= 1;
    }

    // Se já tiverem sido movidos todos os itens da esteira 1
    if (lote == 8)
    {
        // Passa por todos os bits da variável esteira_2
        for (unsigned char i = 0; i < 8; i++)
        {
            // Se o bit for 1
            if (esteira_2 & 0b00000001)
            {
                // Liga o LED AMARELO
                PORTD |= (1 << PD6);

                // Delay de 100ms
                _delay_ms(100);

                // Desliga o LED AMARELO
                PORTD &= ~(1 << PD6);

                // Delay de 500ms
                _delay_ms(500);
            }

            // Desloca todos os bits para direita
            esteira_2 >>= 1;
        }
    }
}

// Função de execução principal
int main(void)
{
    // Configuração dos pinos
    DDRD |= (1 << PD7) | (1 << PD6); // Pino PD6 e PD7 definido como saída

    // Configura o PD2 como entrada
    DDRD &= ~(1 << PD2);

    // Coloca Pull-Up no PD2
    PORTD |= (1 << PD2);

    // Configura o interruptor INT0...
    EICRA |= (1 << ISC00) | (1 << ISC01); // Transição de subida no S1
    EIMSK |= (1 << INT0);                 // Habilita a interrupção INT0

    // Habilita o interruptor global
    sei();

    // Loop infinito
    while (1)
    {
        // Não faz nada
    }

    return 0;
}