/* inspired by 7-segment-display: playground2014.wordpress.com
 * original gear shift indicator design by George MACIU & Nicu FLORICA (niq_ro)
 * http://www.tehnic.go.ro/ & http://www.arduinotehniq.com/
 * http://nicuflorica.blogspot.ro/ & http://arduinotehniq.blogspot.com/
 * Original design is 7 segments, i want the display not only number but also character (only N and R)
 * then i modify the 16 segments to 14 segments
*/

byte digitArray[12][14] =  // {a,b,c,d,e,f,g}  // ASLINYA [12][7] = 
 {                         // 12 adalah jumlah array, 14 adalah isi dalam setiap array
                           // isi setiap array adalah 14 logika digital untuk membentuk setiap digit N-1-2-3-4-5-R
                           
 { 1,0,0,1,0,0,1,0,0,1,1,1,1,1, }, // = N     //{ 0,1,1,0,1,1,0,1,1,0,0,0,0,0, }, // ASLINYA UNTUK COMMON CATHODE
 { 1,0,0,1,1,1,1,1,1,0,1,1,1,1, }, // = 1     //{ 0,1,1,0,0,0,0,0,0,1,0,0,0,0, }, // LOGIKA DIBALIK AGAR ADI COMMON ANODE
 { 0,0,1,0,0,1,0,1,1,1,1,1,1,1, }, // = 2     //{ 1,1,0,1,1,0,1,0,0,0,0,0,0,0, },    
 { 0,0,0,0,1,1,0,1,1,1,1,1,1,1, }, // = 3     //{ 1,1,1,1,0,0,1,0,0,0,0,0,0,0, },
 { 1,0,0,1,1,0,0,1,1,1,1,1,1,1, }, // = 4     //{ 0,1,1,0,0,1,1,0,0,0,0,0,0,0, }, 
 { 0,1,0,0,1,0,0,1,1,1,1,1,1,1, }, // = 5     //{ 1,0,1,1,0,1,1,0,0,0,0,0,0,0, },
 { 0,0,1,1,0,0,0,1,0,1,1,1,1,1, }, // = R     //{ 1,1,0,0,1,1,1,0,1,0,0,0,0,0, }, // *aslinya huruf P ditambah digit miring kaki R
 { 0,0,0,1,1,1,1,1,1,1,1,1,1,1, }, // = 7     //{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0, }, // *digit 6-7-8-9-0 blinking tidak digunakan
 { 0,0,0,0,0,0,0,1,1,1,1,1,1,1, }, // = 8     //{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0, }, // *biarin saja agar tidak banyak rubahan
 { 0,0,0,1,1,0,0,1,1,1,1,1,1,1, }, // = 9     //{ 1,1,1,0,0,1,1,0,0,0,0,0,0,0, }, // *di program
 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1, }, // = off   //{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0, }, // = off 
 { 0,0,0,0,0,0,1,1,1,1,1,1,1,1, } // = "0"    //{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0, }  // = ANGKA "0"   
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
 pinMode(9, OUTPUT); // N Letter adder  //logikanya menyalakan angka 11, nyalakan digit b-c-e-f-h-n
 pinMode(10,OUTPUT); // R Letter adder  //logikanya huruf P, kasih kaki, huruf P ditambah digit n, a-b-e-f-g-n
 pinMode(11,OUTPUT); // 1 Number adder  //logikanya menyalakan angka 1 ada hidungnya, nyalakan digit b-c-k
 
 pinMode(A0, INPUT); // Netral,   A0 sebagai input, untuk mentrigger huruf N, Posisi Netral
 pinMode(A1, INPUT); // 1st gear, A1
 pinMode(A2, INPUT); // 2nd gear, A2
 pinMode(A3, INPUT); // 3rd gear, A3
 pinMode(A4, INPUT); // 4rd gear, A4
 pinMode(A5, INPUT); // 5rd gear, A5
 pinMode(12, INPUT);  // D12 untuk input trigger gigi Reverse, untuk mentrigger huruf R
 pinMode(13, INPUT);  // BLINKING ZERO, optional blinking digit untuk tampilan gigi 5 high speed 
                    

digitalWrite(A0, HIGH); // pull-up the internal resistor
digitalWrite(A1, HIGH); // pull-up the internal resistor
digitalWrite(A2, HIGH); // pull-up the internal resistor
digitalWrite(A3, HIGH); // pull-up the internal resistor
digitalWrite(A4, HIGH); // pull-up the internal resistor
digitalWrite(A5, HIGH); // pull-up the internal resistor
digitalWrite(12, HIGH); // pull-up the internal resistor
digitalWrite(13, HIGH); // pull-up the internal resistor
}

// we define a function to display one digit
void setDigit(byte digit) {
 byte pin=2;
 for (byte i = 0; i < 14; ++i) {         // Aslinya <7 (7 segment), karena kita rubah ke 14 segment
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
if (digitalRead(12)  == LOW) setDigit(6);   // REVERSE
else

// Fungsi untuk memanggil angka 5 berkedip, cara mengedipkan huruf 5
// ------------------------------------------------------------------------
 
if (digitalRead(13) == LOW)                // jika input DX pada logika LOW
{
if (blinking%2 == 1) setDigit(5);  // on, angka 5 berkedip akan menyala
else setDigit(10);                 // off, memanggil array baris ke 10, dimana semua logika adalah 0
}
else
setDigit(10);  // display off
delay(50);
blinking = blinking + 1;
}

/*
************** EOF 06-09-24 6:15 pm ************
* Order PCB ke PCBWay 22-09-2024
* 29 September 2024
* Mencoba mengkustom pin i/o untuk membebaskan D0& D1 sebagai serial monitor.
* input tambahan yaitu A6 & A7 TIDAK BISA DIPAKAI SEBAGAI DIGITAL I/O. HARUS SEBAGAI ADC INPUT SAJA
* Mengkustom D4,D5,D6,D7,D8,D9,D10,D11,D12,D13 sebagai OUTPUT DISPLAY, TIDAK BISA, 
* JADINYA KACAU BALAU hasil Display outputnya;
* HASIL AKHIR KUSTOMISASI PIN GEAR INDIKATOR:
* PIN INPUT = A0,A1,A2,A3,A4,A5,D12,D13.
* PIN OUTPUT KE DISPLAY D3,D4,D5,D6,D7,D8,D9,D10,D11 (digit a,b,c,d,e,f,g,h,n.k).
* pin adder 7seg ke 14 seg = digit h-n-k(designasi digit pada 14seg, bukan 16seg).
* digit h = N adder
* digit n = R adder
* digit k = 1 adder
* 28 September 2024 = belanja material :
* Marnov Bandung = MCU ATMEGA8-PU @10 pcs, sensor A3144@50pcs.
* Eltec SBY = display 16 segment 1"@10pcs
* Toko Magnet jakbar = Neodium magnet 5x2mm
*/
