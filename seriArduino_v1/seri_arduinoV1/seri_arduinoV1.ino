/* 
*  Autor ----------------------- @Denis Cicau - 25442
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
#define seconds() (millis()/1000)

void setup() 
{
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Aquisição de dados: Temperatura e Tempo");
  
  if(!IMU.begin()){ // Inicialização da interface de sensores
        Serial.println("Não consegue inicializar IMU!");
        while (1);
    }
}

void loop() 
{
    if (IMU.temperatureAvailable()) // Aquisição de dados
    {
        int time = 0;
        float temp = 0;
        IMU.readTemperatureFloat(temp);
        time = seconds() - time;
        Serial.print(time);
        Serial.print(", "); // separação dos dados por uma vírgula e um espaço
        Serial.println(temp);
        delay(1000); // Aquisição a cada segundo
    }
}