# E209_Atividades
Lista de atividades práticas de E209 para treinar os conceitos de micro controladores, adaptado ao ATmega328p

## Verificação bit-a-bit

Antes da criação dos algoritmos de correção de erros de bit, uma forma ineficiente de checar se um bit foi perdido ou alterado, era armazenar uma cópia da variável, e comparar bit a bit se as cópias têm o mesmo valor da variável original, e para cada bit errado, um algoritmo tentava restaurar os bits originais. Seu trabalho é criar a parte da verificação, que verifica bit a bit duas variáveis de 8 bits para validar sua semelhança. 

Caso um bit na posição x seja igual à sua cópia, um LED_VERDE deve acender.
Caso um bit na posição x seja diferente da sua cópia, um LED_VERMELHO deve acender.

Para passar ao próximo bit, utiliza-se um sistema de interrupção, que ao identificar o pressionar de um botão, realiza a verificação do próximo bit na fila.

Um LED_AMARELO deve ficar piscando com intervalos de 250ms a todo momento, para indicar que seu sistema está funcionando corretamente.

[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_12_03_05_2022.c)

<img src="https://img.shields.io/badge/ Matéria - GPIO | INT - darkgreen">
<img src="https://img.shields.io/badge/ Dificuldade - Média - orange">
