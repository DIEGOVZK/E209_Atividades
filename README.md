# E209_Atividades
Lista de atividades práticas de E209 para treinar os conceitos de micro controladores, adaptado ao ATmega328p. Qualquer dúvida entre em contato:
<p style="margin:0.5rem; width: 100%; font-size: 100%" >
  <a href="https://www.github.com/DIEGOVZK/">
  <img style="margin:1rem 0.5rem; height: 30%; float: left;" src="https://img.shields.io/badge/GitHub-%20-white?style=for-the-badge&logo=github">
  </a>
  <a href="https://www.linkedin.com/in/diego-anestor-coutinho">
  <img style="margin:1rem 0.5rem; height: 30%;" src="https://img.shields.io/badge/LinkedIn-%20-blue?style=for-the-badge&logo=linkedin">
  </a>
</p>

## Buffer FILO para transmissor RF

<p float="left">

  <img style="float: left;" src="https://img.shields.io/badge/ Matéria - BITMASK | GPIO | INT - darkgreen" alt="DIEGOVZK's GitHub Stats" />

  <img  style="margin-left:0.5rem;" src="https://img.shields.io/badge/ Dificuldade - Fácil / Média - orange"/>
  
</p>

Uma memória FILO é um componente que Bufferiza dados para que sejam transmitidos bit a bit no futuro. Para um valor qualquer armazenado nessa memória, o sistema envia o bit na posição menos significativa da memória, e empurra todo o registro para a direita usando o operador bit shift ">>", e então repete o processo até que toda a informação tenha sido enviada.

Você tem a tarefa de integrar uma memória FILO em um sistema de transmissão RF, seu processador deverá armazenar em uma variável de 8-bits num buffer interno, que deverá ser transmitido bit a bit para o circuito Tx do sistema.
Para verificar o funcionamento, utilize um LED que indica por 100ms o valor do bit a ser transmitido sempre que um botão S1 for pressionado. E usando outro botão S2 faça com que o bit seja transmitido, ou seja, onde a fila da memória FILO em uma posição.


[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_11.c)


## Verificação bit-a-bit

<p float="left">

  <img style="float: left;" src="https://img.shields.io/badge/ Matéria - BITMASK | GPIO | INT - darkgreen" alt="DIEGOVZK's GitHub Stats" />

  <img  style="margin-left:0.5rem;" src="https://img.shields.io/badge/ Dificuldade - Média - orange"/>
  
</p>

Antes da criação dos algoritmos de correção de erros de bit, uma forma ineficiente de checar se um bit foi perdido ou alterado, era armazenar uma cópia da variável, e comparar bit a bit se as cópias têm o mesmo valor da variável original, e para cada bit errado, um algoritmo tentava restaurar os bits originais. Seu trabalho é criar a parte da verificação, que verifica bit a bit duas variáveis de 8 bits para validar sua semelhança. 

Caso um bit na posição x seja igual à sua cópia, um LED_VERDE deve acender.
Caso um bit na posição x seja diferente da sua cópia, um LED_VERMELHO deve acender.

Para passar ao próximo bit, utiliza-se um sistema de interrupção, que ao identificar o pressionar de um botão, realiza a verificação do próximo bit na fila.

Um LED_AMARELO deve ficar piscando com intervalos de 250ms a todo momento, para indicar que seu sistema está funcionando corretamente.

[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_12_13_1.c)
