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

<p loat="left" >

  <img style="margin:1rem 0.5rem; width: 40%; float: left;" src="https://github.com/DIEGOVZK/E209_Atividades/blob/main/Imagens/Img%20AmbienteIntegrado.png">

  ### [Exemplo: Ambiente Integrado](https://www.tinkercad.com/things/ftL9kai7N9I-e209-teste-de-logicas)

</p>

## Buffer FILO para transmissor RF

<p float="left">

  <img style="float: left;" src="https://img.shields.io/badge/ Matéria - BITMASK | GPIO | INT - darkgreen" alt="Stats" />

  <img  style="margin-left:0.5rem;" src="https://img.shields.io/badge/ Dificuldade - Fácil / Média - orange" alt="Stats" />
  
</p>

Uma memória FILO é um componente que Bufferiza dados para que sejam transmitidos bit a bit no futuro. Para um valor qualquer armazenado nessa memória, o sistema envia o bit na posição menos significativa da memória, e empurra todo o registro para a direita usando o operador bit shift ">>", e então repete o processo até que toda a informação tenha sido enviada.

Você tem a tarefa de integrar uma memória FILO em um sistema de transmissão RF, seu processador deverá armazenar em uma variável de 8-bits num buffer interno, que deverá ser transmitido bit a bit para o circuito Tx do sistema. Para verificar o funcionamento, utilize um LED que indica por 100ms o valor do bit a ser transmitido sempre que um botão S1 for pressionado. E usando outro botão S2 faça com que o bit seja transmitido, ou seja, onde a fila da memória FILO em uma posição.


[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_11.c)


## Verificação bit-a-bit

<p float="left">

  <img style="float: left;" src="https://img.shields.io/badge/ Matéria - BITMASK | GPIO | INT - darkgreen" alt="Stats" />

  <img  style="margin-left:0.5rem;" src="https://img.shields.io/badge/ Dificuldade - Média - orange" alt="Stats" />
  
</p>

Antes da criação dos algoritmos de correção de erros de bit, uma forma ineficiente de checar se um bit foi perdido ou alterado, era armazenar uma cópia da variável, e comparar bit a bit se as cópias têm o mesmo valor da variável original, e para cada bit errado, um algoritmo tentava restaurar os bits originais. Seu trabalho é criar a parte da verificação, que verifica bit a bit duas variáveis de 8 bits para validar sua semelhança. 

Caso um bit na posição x seja igual à sua cópia, um LED_VERDE deve acender.  
Caso um bit na posição x seja diferente da sua cópia, um LED_VERMELHO deve acender.

Para passar ao próximo bit, utiliza-se um sistema de interrupção, que ao identificar o pressionar de um botão, realiza a verificação do próximo bit na fila.

Um LED_AMARELO deve ficar piscando com intervalos de 250ms a todo momento, para indicar que seu sistema está funcionando corretamente.

[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_12_13_1.c)


## Driver para motor de passo

<p float="left">

  <img style="float: left;" src="https://img.shields.io/badge/ Matéria - BITMASK | GPIO | INT - darkgreen" alt="Stats" />

  <img  style="margin-left:0.5rem;" src="https://img.shields.io/badge/ Dificuldade - Média - orange" alt="Stats" />
  
</p>

Um driver de motor de passo de 4 pólos tem como entrada 4 canais. Para que o motor consiga dar 1 passo completo, é necessários que os canais A, B, A’, e B’ recebam um sinal sequencial, um após o outro, como mostrado na figura abaixo:

<img  style="margin-left:0.5rem; width: 60%" src="https://github.com/DIEGOVZK/E209_Atividades/blob/main/Imagens/Ex12_2.png"/>

Seu trabalho é montar um circuito que representa essa sequência lógica utilizando 4 Leds de mesma cor para visualizar o ciclo do motor. Porém, é necessário implementar um botão S1 que interrompe a execução do código e inverte a direção do motor, ou seja, o circuito realiza a sequência na direção contrária. 


[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_12_13_2.c)


## Token para abertura do cofre

<p float="left">

  <img style="float: left;" src="https://img.shields.io/badge/ Matéria - BITMASK | GPIO | INT - darkgreen" alt="Stats" />

  <img  style="margin-left:0.5rem;" src="https://img.shields.io/badge/ Dificuldade - Média - orange" alt="Stats" />
  
</p>

Um sistema de segurança empresarial é implementado para proteger arquivos confidenciais. O método escolhido de proteção é a utilização de dois Tokens que serão entregues a duas pessoas de confiança. A única forma de acessar um arquivo, é se ambos fizerem o acesso simultâneo com seus Tokens, então o sistema verifica bit a bit a semelhança dos dois Tokens. Seu trabalho é criar a parte da verificação, que verifica bit a bit duas variáveis de 8 bits para validar sua semelhança. 

Caso um bit na posição x seja igual à sua cópia, um LED_VERDE deve piscar.  
Caso um bit na posição x seja diferente da sua cópia, um LED_VERMELHO deve piscar.

Quando um botão S1 for pressionado, o sistema deverá interromper a execução principal e realizar a verificação bit a bit em sequência, como citado acima. Ao final, caso verificado a semelhança de todos os 8 bits, um LED_AMARELO  acende para indicar a semelhança dos Tokens.

[`GABARITO`](https://github.com/DIEGOVZK/E209_Atividades/blob/main/Gabaritos/GABARITO_12_13_3.c)