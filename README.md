# Winshield-Wipers

## Descriere Proiect

Proiectul constă în realizarea unui **sistem de ștergătoare inteligente**, controlat de o placă **Arduino UNO R3**. Sistemul utilizează senzori pentru a ajusta automat funcționarea ștergătoarelor în funcție de condițiile de mediu:

- **Senzor de ploaie** – detectează nivelul de umiditate.
- **Senzor de lumină** – amplasat pe partea interioară a parbrizului, detectează cantitatea de lumină ce trece prin geam.
- **Servomotoare** – două motoare mici simulează mișcarea ștergătoarelor.
- **LCD 1602** – afișează timpul total de funcționare al ștergătoarelor.
- **LED-uri** – indică vizual starea parbrizului.

Toate componentele sunt alimentate prin Arduino, care acționează ca unitate centrală de control, analizând datele în timp real și luând decizii automatizate.

---

## Funcționalități

### Senzor de ploaie

- **Detectează picăturile de apă**.
- Arduino citește valoarea de pe un pin analogic:
  - **Ploaie ușoară** → ștergătoarele se mișcă lent.
  - **Ploaie puternică** → ștergătoarele se mișcă rapid.

### Senzor de lumină

- **Măsoară lumina** care trece prin parbriz.
- Dacă:
  - Valoare scăzută de lumină **și**
  - Senzorul de ploaie **nu detectează umiditate**
  → se consideră că **parbrizul este murdar**.
  - În acest caz, Arduino **oprește ștergătoarele** pentru a evita frecarea uscată.

### Controlul Servomotoarelor

- Controlul este realizat în funcție de:
  - **Nivelul de ploaie**
  - **Gradul de murdărie al parbrizului**
- Simulează un comportament realist al ștergătoarelor.

---

## LED-uri de stare

- 🟢 **Verde** → Nu plouă, parbrizul este curat.
- 🟡 **Galben** → Plouă, parbrizul este curat.
- 🔴 **Roșu** → Parbrizul este murdar.
- ⚪ **Alb** → Permanent aprins pentru a oferi iluminarea necesară senzorului de lumină.

---

## Afișaj LCD 1602

- Afișează **durata totală de funcționare a ștergătoarelor**.
- Oferă utilizatorului feedback cu privire la condițiile meteo întâlnite.

---

## Necesități Hardware

- Arduino UNO R3
- Senzor de ploaie
- Senzor de lumină
- 2 x Servomotoare
- Display LCD 1602
- 4 x LED-uri (verde, galben, roșu, alb)
- Rezistențe, fire, breadboard, etc.

---

## Observații

- Asigură-te că parbrizul nu este murdar atunci când nu plouă, pentru a nu deteriora sistemul de ștergere.
- Mai multe detalii pot fi gasite pe pagina proiectului [Windshield Wipers](https://ocw.cs.pub.ro/courses/pm/prj2025/iotelea/andreea.olteanu3110).