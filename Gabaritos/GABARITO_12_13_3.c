/**
 * @file    GABARITO_12_13_3.c
 * @author  Diego Anestor Coutinho
 * @date    Mai 2022
 *
 * O algoritmo é uma possível resolução para o(s) exercício(s) avaliativo(s).
 * EM CASO DE DÚVIDA PROCURE POR UM MONITOR, FAREMOS O MELHOR PARA LHE AJUDAR.
 */

/* EXERCÍCIO DO DIA 05/05/2022:

Um sistema de segurança empresarial é implementado para proteger arquivos confidenciais.
O método escolhido de proteção é a utilização de dois Tokens que serão entregues a duas 
pessoas de confiança. A única forma de acessar um arquivo, é se ambos fizerem o acesso 
simultâneo com seus Tokens, então o sistema verifica bit a bit a semelhança dos dois Tokens. 
Seu trabalho é criar a parte da verificação, que verifica bit a bit duas variáveis de 8 bits 
para validar sua semelhança. 

Caso um bit na posição x seja igual à sua cópia, um LED_VERDE deve piscar
Caso um bit na posição x seja diferente da sua cópia, um LED_VERMELHO deve piscar.

Quando um botão S1 for pressionado, o sistema deverá interromper a execução principal 
e realizar a verificação bit a bit em sequência, como citado acima. Ao final, caso verificado 
a semelhança de todos os 8 bits, um LED_AMARELO  acende para indicar a semelhança dos Tokens.

*/


// Variáveis para aplicação na lógica do programa
unsigned char token_1 = 0b01011000;
unsigned char token_2 = 0b01011000;
bool flag_semelhanca = true;

// Função ISR para o botão S1
ISR(INT0_vect)
{
    // Verifica bit a bit a semelhança dos Tokens
    for (int i = 0; i < 8; i++)
    {
        // Se o bit na posição i do token_1 for igual ao bit na posição i do token_2
        if ((token_1 & (1 << i)) == (token_2 & (1 << i)))
        {
            // Pisca o LED VERDE por 100ms
            PORTD |= (1 << PD7);
            _delay_ms(100);
            PORTD &= ~(1 << PD7);
        }
        else
        {
            // Pisca o LED VERMELHO por 100ms
            PORTD |= (1 << PD6);
            _delay_ms(100);
            PORTD &= ~(1 << PD6);

            // Indica que a semelhança dos Tokens não foi verificada
            flag_semelhanca = false;

        }
        
        // Delay até a próxima verificação
        _delay_ms(100);
    }

    // Se a semelhança dos Tokens foi verificada
    if (flag_semelhanca)
    {
        // Liga o LED AMARELO
        PORTD |= (1 << PD5);
    }
}

// Função de execução principal
int main(void)
{
    // Configuração dos pinos
    DDRD |= (1 << PD7) | (1 << PD6) | (1 << PD5); // Pino PD6 e PD7 definido como saída

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