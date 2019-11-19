# Čítač nábojů na airsoftové pušce
Projekt Václava Raidy

Projekt bude zahrnovat nástavec na hlaveň mojí airsoftové pušky, který bude sledovat jestli jím proletí projektil a podle toho mi na displeji na těle zbrani bude počítat počet kuliček v zásobníku.

Postup
Zatím jsem odzkoušel několik zkušebních zapojení a vyzkoušel několik jednoduchých kódů na odzkoušení svých součástek a možností. 
Původní senzor co jsem plánoval používat pro tento projekt kvůli jeho ideálnímu tvaru a vůbec spolehlivosti nakonec nebyl dostačující pro rychlost kuličky když je vystřelena zbraní. Pro pomalý projektil jako kuličku puštěnou prototypovým nastavcem nebo tyč v nástavci fungoval dobře, ale pro kuličku při vysoké rychlosti prostě nefungoval. Vyzkoušel jsem několik dalších senzorů co mám k dispozici, ale většina měla stejný výsledek.
Po zkoušení několika kombinací trubek pro nástavec, metod připevnění, zapojení a kódu jsem našel senzor, který konečně funguje s relativně uspokojivou konsistencí. TCRT5000, co se prodává už zapájený s potenciometrem pro upravování citlivosti. Potenciometrem se dá nastavit citlivost na nastavení, kde je dost citlivý aby detekoval kuličku a nedával špatný výstup i bez jakéhokoliv projektilu. Problém je, že toto nastavení potenciometrem je až moc citlivé na pohyb samotnou součástkou. Manipulace se samotnou součástkou a nástavcem často pokazí citlivé nastavení a musí se potenciometr přenastavovat.

