/*
Sensor jarak HC-SR04
pin yang perlu dihubungkan
VCC to arduino 5v
GND to arduino GND
Echo to Arduino pin 7
Trig to Arduino pin 8
*/
 
#define echoPin 11 //Echo Pin
#define trigPin 12 //Trigger Pin
//#define LEDPin 13 //Led default dari Arduino uno
 
//int maximumRange = 2000; //kebutuhan akan maksimal range
//int minimumRange = 00; //kebutuhan akan minimal range
int lantai = 20;
long durasi, jarak ,selisih ,tibadan; //waktu untuk kalkulasi jarak
 
void setup() {
Serial.begin (9600); //inisialiasasi komunikasi serial
//deklarasi pin
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(13, OUTPUT);
}
 
void loop() {
/* Berikut siklus trigPin atau echo pin yang digunakan
untuk menentukan jarak objek terdekat dengan memantulkan
gelombang suara dari itu. */
digitalWrite(trigPin, LOW);delayMicroseconds(2);
digitalWrite(trigPin, HIGH);delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durasi = pulseIn(echoPin, HIGH);
 
//1.perhitungan untuk dijadikan jarak
jarak = (340*durasi/2)/10000;
Serial.print(jarak);

 
//2.YANG DIBAWAH NGITUNG seensor banjir
 
if (jarak > 10)
Serial.println ("siaga banjir");
else
Serial.println("air normal");
{
Serial.print("ketinggian air = "); 
Serial.print(jarak);
Serial.print(" cm");
digitalWrite(13, HIGH);

}

//3.perhitungan tinggi badan dengan if
tibadan = lantai - jarak;
Serial.print("tinggi badan = ");
Serial.print(tibadan);
Serial.println(" cm");

if (jarak>=20)
Serial.println("Silahkan ukur tinggi badan");
else if (jarak>=15)
Serial.print("anda pendek");

else
Serial.print(tibadan);
/*Kirim jarak ke komputer menggunakan Serial protokol, dan
menghidupkan LED OFF untuk menunjukkan membaca sukses. */
//Serial.println(distance);
digitalWrite(13, LOW);
 
//waktu tunda 50mS
delay(1500);
jarak = 0;
Serial.println();
}