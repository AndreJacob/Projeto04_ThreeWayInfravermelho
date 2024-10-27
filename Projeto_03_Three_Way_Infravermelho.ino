/* JACOB TECNOLOGIA
 https://www.youtube.com/channel/UCoyPRGrpP_G7i2sgEytbnBQ?view_as=subscriber
 
 PASSA LÁ NO CANAL PRA NOS INCENTIVAR A FAZER NOVOS PROJETOS*/

#include <IRremote.h> 
 
int Receptor = 3; 
int Lp1 = 2;
int estado = 1;
int ultimo_estado = 0;
 
IRrecv irrecv(Receptor); //PASSA O PARÂMETRO PARA A FUNÇÃO irrecv

decode_results results; 
 
void setup(){
  Serial.begin(9600); 
  irrecv.enableIRIn(); //Inicializa a leitura do receptor.
}
 
void loop(){
  pinMode(Lp1, OUTPUT);
  
  
  if (irrecv.decode(&results)) { //Pega o sinal do infravermelho.
    
    Serial.print("Valor lido no Receptor é: "); 
    Serial.println(results.value, DEC); // Imprimi na Serial os valores recebidos no infravermelho.
    irrecv.resume(); //  Aguarda receber um sinal.
    delay(100); 
    
  }

    if (results.value == 702755664){
 
        if (estado == HIGH) {
        ultimo_estado = !ultimo_estado;
        delay(500);
        }
 
       if (ultimo_estado == HIGH) {
        digitalWrite(Lp1, HIGH);
        }
        else {  
        digitalWrite(Lp1, LOW);
        }
  }
      
}
