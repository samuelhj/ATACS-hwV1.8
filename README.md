# ATACS-hw1.7-swv1.2.0
 
Uppfærslur má nálgast hér: https://ulfraf.space/files/ATACS-V1.8.x-updater-current.7z

Til að opna 7z skránna gæti þurft p7zip forritið. Það má nálgast hér: https://www.7-zip.org/download.html

Leiðbeiningar: https://ulfraf.space/files/ATACS-Manual-V1.8.pdf


### Eiginleikar:

Forritið stýrir 6rása mosfet útgangsrás, snertiskjá og les frá þrýstinema. Gildin birtir það svo á skjánum.
Frá skjánum tekur það valin gildi á hvaða þrýstingur á að vera í dekkjum og stillir þrýstingin í dekkjunum eftir því. Einnig fylgist það af og til með
að réttur þrýstingur sé í dekkjum og ef það er ekki til staðar leiðréttir forritið
þrýstingin í því dekki eða dekkjum sem um ræðir.

Hjartað í kerfinu er annarsvegar ATmega1284P með Mightycore bootloader ásamt II9341 skjá frá Adafruit. Sjálfsagt er lítið mál að porta kóðann fyrir á einhverja aðra ATmega rás, t.d. 2560 eða ARM. ATmega328P rásirnar hafa einfaldlega ekki nægilegt minni til að keyra kóðann, en hugsanlega er það hægt með einhverjum brögðum (fækka valmöguleikum t.d.)

Þetta forrit miðast við 2+4 kistu og með skynjarann á prentplötu
Líklega er ekki mikið mál að breyta forritinu svo það lesi aðrar
tegundir af skynjurum. Ef ekki er ætlunin að nota loftút eða auka úrtak frá
loftkerfi má sleppa AIR_IN loka og tengja þann útgang frá MOSFET stýringu beint
á segulrofa fyrir loftdælu og spara þannig bæði einn loftloka og aflestunarloka
fyrir loftdælu. Athugið að EKKI er mælst til þess að nota kerfið með loftkút, það gerir lítið gagn
annað en að rugla kerfið. Ef einhverra hluta vegna er algjört möst að eyða pening í loftkút þá er best
að einangra loftkútinn frá kerfinu með segulrofa, sem lokar á kútinn á meðan ATACS er virkt.

    Útgangar eru eftirfarandi:
    * 6 til að stýra loftlokum með MOSFET stýringu (Gefur jörð)
    * 6 fyrir sér kistu fyrir loftpúða
    * RS232 útgangur fyrir t.d. RS232 skjá eða samskipti við hvað annað sem mönnum
      gæti dottið í hug að bæta við seinna meir.
    * 15 pinna tengi fyrir SPI skjá.
    * CAN-BUS 

### Kóðasöfn í notkun:
* TouchScreen.h  Við þurfum library til að lesa snertingu af skjá.
* Adafruit_GFX.h  Við þurfum library til að teikna á skjá.
* Adafruit_ILI9341.h  Við þurfum library til að tala við ILI9341 stýringu á skjá.


Ath breyta þarf línu í kóðasafninu Touchscreen.h fyrir ATmega1284P

"TouchScreen.h: Lína 12 í TouchScreen.h bæta þarf við:
>||defined(__AVR_ATmega1284P__)"
