/**
 * @file    GABARITO_12_13_1.c
 * @author  Diego Anestor Coutinho
 * @date    Mai 2022
 *
 * O algoritmo é uma possível resolução para o(s) exercício(s) avaliativo(s).
 * EM CASO DE DÚVIDA PROCURE POR UM MONITOR, FAREMOS O MELHOR PARA LHE AJUDAR.
 */

/* EXERCÍCIO DO DIA 03/05/2022:

Antes da criação dos algoritmos de correção de erros de bit, uma forma ineficiente 
de checar se um bit foi perdido ou alterado, era armazenar uma cópia da variável, 
e comparar bit a bit se as cópias têm o mesmo valor da variável original, e para 
cada bit errado, um algoritmo tentava restaurar os bits originais. Seu trabalho é 
criar a parte da verificação, que verifica bit a bit duas variáveis de 8 bits para 
validar sua semelhança. 

Caso um bit na posição x seja igual à sua cópia, um LED_VERDE deve acender.
Caso um bit na posição x seja diferente da sua cópia, um LED_VERMELHO deve acender.

Para passar ao próximo bit, utiliza-se um sistema de interrupção, que ao identificar 
o pressionar de um botão, realiza a verificação do próximo bit na fila.

Um LED_AMARELO deve ficar piscando com intervalos de 250ms a todo momento, para 
indicar que seu sistema está funcionando corretamente.

*/


// Variáveis para aplicação na lógica do programa
unsigned char original = 0b01011000;
unsigned char varCopia = 0b11101000;
unsigned char aux_verificacao = 1;

// Função ISR para o botão S1
ISR(INT0_vect)
{
    // Verifica se o bit na posição x é igual à sua cópia
    if ((original & aux_verificacao) == (varCopia & aux_verificacao))
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
    }

    // Passa para o próximo bit
    aux_verificacao <<= 1;

    // Se o aux chegar ao final, reinicia o aux
    if (aux_verificacao == 0)
    {
        aux_verificacao = 1;
    }

}

int main(void)
{
    // Pino PD5, PD6 e PD7 definido como saída
    DDRD |= (1 << PD7) | (1 << PD6) | (1 << PD5); 

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
        // Pisca o LED AMARELO por 250ms a todo momento
        PORTD ^= (1 << PD5);
        _delay_ms(250);
    }
}