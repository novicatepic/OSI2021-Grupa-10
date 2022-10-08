# OSI2021-Grupa-10

===============================================

Clanovi grupe 10:
Vojvopriv - Даријо Прерад 1103/20     
Djed01    - Гордан Летић  1157/20
zoran-jeftenic - Зоран Јефтенић
sinisa-radeta - Синиша Радета
novicatepic - Новица Тепић 1102/20

===============================================



Specifikacija projektnog zadatka na srpskom jeziku: 

Implementirati jednostavnu aplikaciju za rad aerodroma. Radnici treba da imaju mogućnost prijave na sistem unosom korisničkog imena i lozinke, a podaci o registrovanim korisnicima se čuvaju u binarnoj datoteci u sklopu aplikacije.

Kada se prijave na sistem, korisnici mogu koristiti različite opcije, u zavisnosti od vrste naloga koje imaju. Potrebno je realizovati četiri vrste korisničkih naloga: operater, kontrolor, šef i administrator.

Nalog za operatere omogućava da se pregledaju sve dobijene rezervacije letova od klijenata. Ovaj dio se može pojednostaviti tako što će se rezervacije nalaziti u nekom folderu, pri čemu ih program automatski čita i prikazuje u aplikaciji (spisak), a operater može otvoriti neku rezervaciju i zatim je odobriti ili otkazati. Validnost podataka (postojanje leta i slobodnih mjesta) se radi automatski i operater vidi rezultat tih provjera. Operater može vidjeti spisak svih odobrenih i odbijenih rezervacija. Fajlovi za rezervaciju se kreiraju ručno izvan ovog sistema. Ime i prezime operatera se čuva u svakoj obrađenoj rezervaciji.

Nalog za kontolore omogućava kreiranje novih letova, pravljenje rasporeda letova (u sklopu kreiranja), mijenjanje statusa leta (sletio, poletio, leti), pregled informacija o svakom letu (od - do, vrijeme, opis, broj mjesta, broj trenutno slobodnih mjesta) i otkazivanje leta. Svi podaci se čuvaju u tekstualnim fajlovima na fajl sistemu. Prilikom otkazivanja leta sve rezervacije za taj let se automatski brišu.

Nalog za šefove omogućava pregled izvještaja o završenim letovima na dnevnom, sedmičnom i mjesečnom nivou. Pored toga, šefovi vide i sve rezervacije, ali ih ne mogu mijenjati.

Naloge svih zaposlenih kreiraju/brišu administratori. Nalozi se mogu privremeno suspendovati, pri čemu se ne brišu već se korisnici ne mogu prijaviti na sistem. U sistemu postoje najviše 2 administratora i 3 šefa

U pitanju je konzolna aplikacija za koju su napisani detaljni testovi, zavrsni izvjestaj, uputstvo za instaliranje i SRS dokument.



===============================================



Project specification:

Implement a simple application for airports. People who work at the airport should be able to log in to the system by entering their credentials, username and password. Data for the registered users is saved in a binary file which is a part of the application.

Users that are logged in to the system can use various kind of options depending on the type of their account. There are four types of accounts: operator, supervisor, chief and administrator.

Operator is allowed to check each of the flight reservation requested by client. This part can be simplified so that reservations are saved in a folder, and the program automatically reads them and shows them in the application, and operator can easily open a reservation and accept or deny it. Data validity (fligth existence and number of free seats) is checked automatically and operater can easily see these results. Operator can check all accepted and declined reservations. Files which contain reservations are not created in the system. First name and last name of the operator is saved in each elaborated reservation.

Supervisor can create a new flight, schedule flights, change flight status, check informations about every flight and cancel the flight. All the data is saved in textual files in file system. When a flight is cancelled, all the reservations for that flight are automatically deleted.

Chiefs are allowed to check reports which contain informations about finished flights. Those reports can be daily, weekly or monthly reports. Besides that, chiefs can see all reservations, but are unable to change them.

Administrators can create or delete accounts of all the users in the system. Accounts can be suspended. Suspension doesn't mean accounts are deleted, it means that users can't log in to the system. There are maximum of two administrators and three chiefs in the system.

This is a console application. Tests for this application are written in detail, there is a final report, as well as a manual for installation and SRS document.
