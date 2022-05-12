/**
 * @file    GABARITO_11.c
 * @author  Diego Anestor Coutinho
 * @date    Abr 2022
 *
 * O algoritmo é uma possível resolução para o(s) exercício(s) do relatório 9.5.
 * EM CASO DE DÚVIDA PROCURE POR UM MONITOR, FAREMOS O MELHOR PARA LHE AJUDAR.
 */


// Buffer para armazenar os 8 bits da memória FILO
unsigned char _Buffer = 0b00110100; // 52

// Ao pressionar o botão S2
ISR(INT0_vect)
{
    // Buffer tem seus bits empurrados 1 posição para a direita
    _Buffer = _Buffer >> 1;
    _delay_ms(100);
}

// Ao pressionar o botão S1
ISR(INT1_vect)
{
    // Filtra o bit 0 do buffer, e verifica se é 1
    if((_Buffer & 0b00000001))
    {
        // Só se for 1, então ativa o LED no PD7 por 100ms
        PORTD |= (1 << 7);
        _delay_ms(100);
    }

    // Em qualquer caso, desliga o LED no PD7
    PORTD &= ~(1 << 7);
}


int main()
{
    // Configura o PD7 como saída e coloca PULL-UP no PD2 e PD3
    PORTD |= (1 << 2) | (1 << 3);
    DDRD  |= (1 << 7);

    /* Configura o interruptor para executrar ISR (int1, int0)
       sempre que os botões S1 e S2 forem pressionados */
    EICRA = 0b00001111;
    EIMSK = 0b00000011;

    sei();

    for (;;)
    {
        /* Tudo com interrupção, não precisa executar nada no super-loop  */
    }
}
