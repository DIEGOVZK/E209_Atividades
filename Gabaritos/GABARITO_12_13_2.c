/**
 * @file    GABARITO_12_13_2.c
 * @author  Diego Anestor Coutinho
 * @date    Mai 2022
 *
 * O algoritmo é uma possível resolução para o(s) exercício(s) avaliativo(s).
 * EM CASO DE DÚVIDA PROCURE POR UM MONITOR, FAREMOS O MELHOR PARA LHE AJUDAR.
 */

/* EXERCÍCIO DO DIA 04/05/2022:

Um driver de motor de passo de 4 pólos tem como entrada 4 canais. 
Para que o motor consiga dar 1 passo completo, é necessários que 
os canais A, B, A’, e B’ recebam um sinal sequencial, um após o outro, 
como mostrado na figura abaixo: <(consultar PDF com exercícios)>.

Seu trabalho é montar um circuito que representa essa sequência lógica 
utilizando 4 Leds de mesma cor para visualizar o ciclo do motor. 
Porém, é necessário implementar um botão S1 que interrompe a execução 
do código e inverte a direção do motor, ou seja, o circuito realiza a 
sequência na direção contrária. 

*/

// Variáveis para aplicação na lógica do programa
unsigned char passo = 0b00010000; // Inicia no estado A
bool direcaoDoMotor = true; // Inicia na direção normal

// Função ISR para o botão S1
ISR(INT0_vect)
{
    // Inverte a direção do passo
    direcaoDoMotor = !direcaoDoMotor;
}

int main (void)
{

    // Pino PD4, PD5, PD6 e PD7 definido como saída
    DDRD |= (1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4); 

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
        // Realiza a sequencia de ativação do motor
        if (direcaoDoMotor)
        {
            // Movimenta os bits na direção normal
            passo <<= 1;

            // Se o passo chegar ao final, reinicia o passo
            if (passo == 0)
                passo = 0b00010000;

            // Pisca o LED na posição "passo" por 100ms
            PORTD |= passo;
            _delay_ms(100);
            PORTD &= ~passo;
        }
        else
        {
            // Movimenta os bits na direção inversa
            passo >>= 1;

            // Se o passo chegar ao final, reinicia o passo
            if (passo == 0b00001000)
                passo = 0b10000000;
            
            // Pisca o LED na posição "passo" por 100ms
            PORTD |= passo;
            _delay_ms(100);
            PORTD &= ~passo;
        }

        // Espera o tempo de 100ms
        _delay_ms(100);
    }
}