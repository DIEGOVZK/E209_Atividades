/**
 * @file    GABARITO_12_13_5.c
 * @author  Diego Anestor Coutinho
 * @date    Mai 2022
 *
 * O algoritmo é uma possível resolução para o(s) exercício(s) avaliativo(s).
 * EM CASO DE DÚVIDA PROCURE POR UM MONITOR, FAREMOS O MELHOR PARA LHE AJUDAR.
 */

/* EXERCÍCIO DO DIA 12/05/2022:

Um sistema de monitoramento da sala de servidores armazena o estado operacional de 8 servidores
em 1 bit de uma variável, sendo que o bit “1” = servidor com problema, e “0” = estado normal.
No total, a empresa de hosting tem 2 (duas) salas de servidor implementadas.

A sua empresa foi contratada para fazer um sistema de alerta que indica caso um
servidor apresente problemas de operação. O sistema deverá indicar à qual sala o
servidor pertence ao acender um LED VERDE = Sala 1, e outro LED VERMELHO = Sala 2.

Além disso, o sistema indica qual o número do servidor com problema ao piscar n vezes
indicando a posição n do bit que indica o problema. O sistema deve interromper a execução normal
e iniciar a verificação quando o botão S1 for pressionado.

OBS: Considere que somente 1 servidor irá apresentar problema em um determinado instante.
OBS 2: Esse gabarito consegue atuar sobre a situacao de terem mais de 1 servidor com problema.

*/

// Variáveis para aplicação na lógica do programa
unsigned char sala_1 = 0b00000000;
unsigned char sala_2 = 0b00010000;
unsigned char contador = 0;

// Função ISR para o botão S1
ISR(INT0_vect)
{

    // Passa por todos os bits da variável sala_1 até encontrar um bit com 1
    for (int i = 0; i < 8; i++)
    {
        // Adiciona mais 1 na contagem
        contador++;

        // Se o bit for 1
        if (sala_1 & (1 << i))
        {
            // Pisca o LED VERMELHO i vezes
            for (int j = 0; j < i + 1; j++)
            {
                PORTD ^= (1 << PD7);
                _delay_ms(500);
                PORTD ^= (1 << PD7);
                _delay_ms(500);
            }
        }
    }

    // Zera o contador
    contador = 0;

    // Passa por todos os bits da variável sala_2 até encontrar um bit com 1
    for (int i = 0; i < 8; i++)
    {
        // Adiciona mais 1 na contagem
        contador++;

        // Se o bit for 1
        if (sala_2 & (1 << i))
        {
            // Pisca o LED VERMELHO i vezes
            for (int j = 0; j < i + 1; j++)
            {
                PORTD ^= (1 << PD6);
                _delay_ms(500);
                PORTD ^= (1 << PD6);
                _delay_ms(500);
            }
        }
    }

    // Zera o contador
    contador = 0;
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
