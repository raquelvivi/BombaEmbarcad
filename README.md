# 🚒 Bomba de Caixa D’água com Detecção de Incêndio (Arduino)

Projeto final da faculdade (Sistemas Embarcados) onde desenvolvemos um circuito de **bomba d’água acionada por relé**, com **detecção de risco de incêndio** usando Arduino.

A bomba só é acionada quando:
- há **risco de chama/fogo** (fotodiodo + sensor de temperatura)
- e existe **água disponível no reservatório**

O sistema possui **2 modos**, alternados por um único botão:
- **Modo Automático:** a bomba liga automaticamente ao detectar perigo
- **Modo Manual:** a bomba liga/desliga apenas quando o botão é pressionado

> Obs.: o relé foi soldado por cada estudante.
</br></br>
## 🛠️ Tecnologias Utilizadas

### 💻 Software
- Arduino (C++)
- Tinkercad

### 🔩 Hardware
- Arduino Uno
- Relé 5V
- Buzzer
- LED + resistor
- Fotodiodo
- Sensor de temperatura
- Sensor ultrassônico (nível de água)
- Transistor
- Buzzer

</br></br>

## 🖼️ Imagens

<img width="1528" height="635" alt="Funky Turing" src="https://github.com/user-attachments/assets/d33af528-c8d2-49d2-af4f-fbeeab5d1048" />
<img width="622" height="468" alt="Captura de tela 2026-02-02 002717" src="https://github.com/user-attachments/assets/0d012228-cc0b-4bd2-87dc-a0e0ed6a97fd" />
<img width="622" height="468" alt="Captura de tela 2026-02-02 002739" src="https://github.com/user-attachments/assets/5242c25a-50b3-4c21-ba38-642530b5349a" />


## 🧠 Aprendizados / Desafios
O maior desafio do projeto foi entender o funcionamento do relé (COM/NO/NC) e fazer as conexões corretamente.
Após várias tentativas e testes no Tinkercad, consegui validar a ligação correta e evitar a queima de componentes antes da montagem física.
