C kod implementira server koji prima tekstualnu datoteku od klijenta. Server slusa kako bi uspostavio konekciju, zatim prima broj rijeci koja je sadrzana u datoteci koju prima od klijenta, nakon cega sacuva sadrzaj datoteke u novu datoteku koja se nalazi na istoj lokaciji kao i implementacija servera u C programskom jeziku.

**Koraci implementacije rjesenja:**
1. Kreiranje socket-a i slusanje nadolazecih konekcija
2. Prihvatanje konekcije sa klijentom
3. Prihvatanje broja rijeci unutar datoteke poslane od strane klijenta
4. Prihvatanje sadrzaja datoteke poslane od strane klijenta
5. Spremanje primljenih podataka u datoteku "file_server.txt"

Za kompajliranje koda koristen je GCC kompajler.