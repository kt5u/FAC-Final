/* Autor ----------------------- @Denis Cicau - 25442
*
*  Repositório: ---------------- https://github.com/kt5u/FAC-Final
*
*  Instituição: ---------------- Instituto Politécnico de Beja - Escola Superior de Tecnologia e Gestão
*
*  Curso / Unidade Curricular: - Engenharia Informática - Física Aplicada à Computação
*
*  Data / Ano Letivo: ---------- 2023/2024 | 28-01-2024
*
*  Descrição do projeto: ------- Aquisição de dados de temperatura e tempo utilizando um Arduino
*
*  Hardware: ------------------- Arduino Nano rp2040 Connect
*
*  Bibliotecas utilizadas:  ---- LSM6DSOX (sensor de temperatura)
*/

#include <Arduino.h>
#include <Arduino_LSM6DSOX.h>

void setup() 
{
  Serial.begin(9600); // Identificação
  while(!Serial);
  Serial.println("Aquisição de dados: Temperatura e Tempo");
  Serial.println("");
  
  if (IMU.temperatureAvailable()) // Verificação da existência de sensor de temperatura (LSMDSOX)
  {
    Serial.println("Sensor de temperatura encontrado!");
    Serial.println("A ler valores de temperatura e tempo...");
    Serial.println("");
  } 
}

void loop() 
{
    int time = 0;
    int temp = 0;
    IMU.readTemperature(temp);
    time = millis() - time;
    Serial.print(time);
    Serial.print(" ms, ");
    Serial.print(temp);
    Serial.println(" ºC");
    delay(1000);
}



