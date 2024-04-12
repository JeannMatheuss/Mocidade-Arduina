Sistema de Controle de Luminosidade

Este é um sistema de controle de luminosidade baseado em Arduino que utiliza um Light Dependent Resistor (LDR) para monitorar a luminosidade do ambiente e controlar LEDs e um buzzer de acordo com os níveis de luz detectados.



Componentes Utilizados

LED Verde: Conectado ao pino digital 8.

LED Amarelo: Conectado ao pino digital 7.

LED Vermelho: Conectado ao pino digital 4.

Buzzer: Conectado ao pino digital 3.

LDR (Light Dependent Resistor): Conectado ao pino analógico A0.



Funcionamento

O código monitora constantemente a luminosidade detectada pelo LDR. Com base nesse valor, ele controla os LEDs e o buzzer de acordo com as seguintes condições:

Luminosidade Baixa (<= 20): O LED verde é aceso e os LEDs amarelo e vermelho são apagados. O buzzer também é desligado.

Luminosidade Moderada (21-50): O LED amarelo é aceso, enquanto os LEDs verde e vermelho são apagados. O buzzer é acionado com um tom de 2000Hz por 3000ms.

Luminosidade Alta (> 50): O LED vermelho é aceso, enquanto os LEDs verde e amarelo são apagados. O buzzer é acionado com um tom de 2000Hz por 1000ms.

Setup
No setup(), a comunicação serial é iniciada com uma taxa de 9600 bauds e os pinos são configurados como entrada ou saída conforme necessário para os LEDs, o buzzer e o LDR.

Loop
No loop(), o valor analógico do LDR é lido e mapeado para o intervalo de 0 a 100, representando a luminosidade. Com base nesse valor, são tomadas as decisões para controlar os LEDs e o buzzer conforme as condições descritas acima. Após cada ciclo de leitura e controle, o programa aguarda 3 segundos antes de repetir o processo.



Observações

A comunicação serial é utilizada para exibir a luminosidade medida pelo LDR.
Os tempos de acionamento do buzzer foram definidos experimentalmente e podem ser ajustados conforme necessário.
Nota: Certifique-se de conectar os componentes aos pinos corretos do Arduino de acordo com as definições no código.

Espero que este readme tenha esclarecido o funcionamento do código! Se precisar de mais alguma informação, não hesite em perguntar.



