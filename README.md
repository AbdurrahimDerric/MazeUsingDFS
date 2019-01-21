# MazaUsingDFS
turkish


Yontem
Problem tanimi:
Verilen bir n sayisi ve n*n matrisi icin , baslangic hucresinden (1,1)
bitis noktasina (n,n) DFS algoritmasini kullanarak yol olup olmadigini
bulan ve o yolu yazdiran algoritma tasarlamak.

Cozum:
DFS ile Cikis Yol Kontrolu :
Matriste duvarlar 0 ile , yollar 1 ile temsil edilir, DFS algoritmasi
baslangic noktasindan baslayark iterative sekilde komsulara bakarak
ilerler
İşlem adımları aşağıdaki gibidir:
1. İşleme (1,1)hücresinden başlar.
2. O anda işlenen (x,y) hücresini “gelindi” olarak işaretler.
3. Kuzey-(x,y+1)yönünde duvar yoksa (x,y+1)hücresine giderek onun
komşularına bakar.
4. Doğu-(x+1,y)yönünde duvar yoksa (x+1,y)hücresine giderek onun
komşularına bakar.
5. Güney-(x,y-1)yönünde duvar yoksa (x,y-1)hücresine giderek onun
komşularına bakar.
6. Batı-(x-1,y)yönünde duvar yoksa (x-1,y)hücresine giderek onun
komşularına bakar.
7. (NxN) hücresine gelindiyse işlem bitmiştir.

Yolu Bulan Algoritma

Algoritma onceki sayfadai DFS mantigini kullanir yani komsulara
bakarak ilerler , bu algoritmada iki stack kullanildi ;
Birinci stack “PATH” gidilmis yolu kaydetmek icin kullanilr .
Ikinci stack “CROSSROAD” yolda ilerlerken bir hucrenin birden fazla
yola ayriliyorsa o hucrenin koordinatlari bu stackte kaydedilir.

Baslangis noktasindan baslayarak algoritma gectigi yolu path stackina
push eder ve -1e donusturur , birden fazla yola cikan noktaya geldiyse
o noktanin indisleri CrossRoad stack’ine push eder , alinan yolda
ilerlerken cikmaz duruma geldiyse ve ilerleyecek komusu kalmadiysa
CrossRoad stackinde nokta varsa o noktaya path stackini kullanark
doner , dondugu yol 0 yapar , CrossRoadin noktasinda gidilecek yol
varsa ordan ilerler , (n,n) noktasina gelindiyse is biter .

UYGULAMA
(6,6) boyutu ,(1,1) baslangic ve (4,4) bitis noktasi olan asagidaki
matris uzerinde “yolu bulan” algoritmasini gerceklestirleim

0 0 0 0 0 0
0 1 0 1 0 0
0 1 1 1 0 0
0 1 0 0 0 0
0 1 1 1 1 0
0 0 0 0 0 0

yani gidilebilen yol
0 0 0 0 0 0
0 1 0 1 0 0
0 1 1 1 0 0
0 1 0 0 0 0
0 1 1 1 1 0
0 0 0 0 0 0

0 0 0 0 0 0
0 -1 0 -1 0 0
0 -1 -1 -1 0 0
0 1 0 0 0 0
0 1 1 1 1 0
0 0 0 0 0 0

0 0 0 0 0 0
0- 1 0 0 0 0
0 -1 0 0 0 0
0 -1 0 0 0 0 (n,n) geldi yol -1lerle ifade edilmis oldu.
0 -1 -1 -1 -1 0
0 0 0 0 0 0

Sonuc :
DFS algoitmasi kullanarak bir graphta iki dugum arasinda baglanti
olup olmadiginin bulunur .
Stack veri yapisini kullanarak farkli algoritmalar cozulebilr hale
gelir.
