/* inspired by 7-segment-display: playground2014.wordpress.com
 * original gear shift indicator design by George MACIU & Nicu FLORICA (niq_ro)
 * http://www.tehnic.go.ro/ & http://www.arduinotehniq.com/
 * http://nicuflorica.blogspot.ro/ & http://arduinotehniq.blogspot.com/
*/

byte digitArray[12][14] =  // {a,b,c,d,e,f,g}  // ASLINYA [12][7] = 
 {                         // 12 adalah jumlah array, 14 adalah isi dalam setiap array
                           // isi setiap array adalah logika untuk membentuk setiap digit N-1-2-3-4-5-R
                           
 { 1,0,0,1,0,0,1,0,0,1,1,1,1,1, }, // = N     //{ 0,1,1,0,1,1,0,1,1,0,0,0,0,0, },ASLINYA UNTUK COMMON CATHODE
 { 1,0,0,1,1,1,1,1,1,0,1,1,1,1, }, // = 1     //{ 0,1,1,0,0,0,0,0,0,1,0,0,0,0, },
 { 0,0,1,0,0,1,0,1,1,1,1,1,1,1, }, // = 2     //{ 1,1,0,1,1,0,1,0,0,0,0,0,0,0, },    
 { 0,0,0,0,1,1,0,1,1,1,1,1,1,1, }, // = 3     //{ 1,1,1,1,0,0,1,0,0,0,0,0,0,0, },
 { 1,0,0,1,1,0,0,1,1,1,1,1,1,1, }, // = 4     //{ 0,1,1,0,0,1,1,0,0,0,0,0,0,0, }, 
 { 0,1,0,0,1,0,0,1,1,1,1,1,1,1, }, // = 5     //{ 1,0,1,1,0,1,1,0,0,0,0,0,0,0, },
 { 0,0,1,1,0,0,0,1,0,1,1,1,1,1, }, // = R     //{ 1,1,0,0,1,1,1,0,1,0,0,0,0,0, },
 { 0,0,0,1,1,1,1,1,1,1,1,1,1,1, }, // = 7     //{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0, }, //digit 6-7-8-9-0 blinking tidak digunakan
 { 0,0,0,0,0,0,0,1,1,1,1,1,1,1, }, // = 8     //{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0, }, //biarin saja agar tidak banyak rubahan
 { 0,0,0,1,1,0,0,1,1,1,1,1,1,1, }, // = 9     //{ 1,1,1,0,0,1,1,0,0,0,0,0,0,0, }, //di program
 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1, }, // = off   //{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0, }, // = off 
 { 0,0,0,0,0,0,1,1,1,1,1,1,1,1, } // = "0"    //{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0, } // = "0"   
 };

int blinking = 0; //set integer untuk sub perintah blinking digit 0 ketika dipanggil
 
void setup() {
 pinMode(2, OUTPUT); // kingbrigth - a
 pinMode(3, OUTPUT); // kingbrigth - b
 pinMode(4, OUTPUT); // kingbrigth - c
 pinMode(5, OUTPUT); // kingbrigth - d
 pinMode(6, OUTPUT); // kingbrigth - e
 pinMode(7, OUTPUT); // kingbrigth - f
 pinMode(8, OUTPUT); // kingbrigth - g
 pinMode(9, OUTPUT); // N Letter adder  //untuk menghemat penggunaan pin I/O arduino, agar terbentuk huruf N pada 16 segment
 pinMode(10,OUTPUT); // R Letter adder  //untuk menghemat penggunaan pin, agar terbentuk huruf R pada 16 segment
 pinMode(11,OUTPUT); // 1 number adder  //untuk menghemat penggunaan pin, agar terbentuk angka 1 dengan topi pada 16 segment
 
 pinMode(A0, INPUT); // Netral, A0 sebagai input, main body letter N
 pinMode(A1, INPUT); // 1st gear, A1
 pinMode(A2, INPUT); // 2nd gear, A2
 pinMode(A3, INPUT); // 3rd gear, A3
 pinMode(A4, INPUT); // 4rd gear, A4
 pinMode(A5, INPUT); // 5rd gear, A5
 pinMode(0, INPUT);  // reverse gear, D0 sebagai input, main body letter R
 pinMode(1, INPUT);  // BLINKING ZERO, optional blinking digit 

digitalWrite(A0, HIGH); // pull-up the internal resistor  //TRANSLATE KE COMMON ANODA, ASLINYA HIGH
digitalWrite(A1, HIGH); // pull-up the internal resistor
digitalWrite(A2, HIGH); // pull-up the internal resistor
digitalWrite(A3, HIGH); // pull-up the internal resistor
digitalWrite(A4, HIGH); // pull-up the internal resistor
digitalWrite(A5, HIGH); // pull-up the internal resistor
digitalWrite(0,  HIGH); // pull-up the internal resistor
digitalWrite(1,  HIGH); // pull-up the internal resistor
}

// we define a function to display one digit
void setDigit(byte digit) {
 byte pin=2;
 for (byte i = 0; i < 14; ++i) {         //aslinya 7
 digitalWrite(pin, digitArray[digit][i]);
 ++pin;
 }
}

void loop() {

if (digitalRead(A0) == LOW) setDigit(0);  // NETRAL
else
if (digitalRead(A1) == LOW) setDigit(1);  // 1st gear
else
if (digitalRead(A2) == LOW) setDigit(2);  // 2nd gear
else
if (digitalRead(A3) == LOW) setDigit(3);  // 3rd gear
else
if (digitalRead(A4) == LOW) setDigit(4);  // 4rd gear
else
if (digitalRead(A5) == LOW) setDigit(5);  // 5rd gear
else
if (digitalRead(0) == LOW) setDigit(6);  // REVERSE
else

if (digitalRead(1) == LOW)            //jika input D1 pada logika LOW
{
if (blinking%2 == 1) setDigit(5);  // on
else setDigit(10);                // off
}
else
setDigit(10);  // display off
delay(200);
blinking = blinking + 1;
}

//eof 06-09-24 6:15 pm
