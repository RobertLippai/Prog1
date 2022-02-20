# Előadás Jegyzet Első hét - Grafikus program felvezetés

Előadás: A félév tartalma. Grafikus program felvezetés (PPP Ch 12)

Labor: Alakzatok a programban.

Feladatok: Github repó készítése, könyvelés. A fenti könyvek beszerzése. Tanulni a könyből: PPP Ch 12. Drill elkészítése: PPP Ch 12. PPP Ch 12 Exercises 1-9.

Határidő: feb. 25.

## Display Model:

Könyv 10-11es fejezetet átismételni

### GUI: amin keresztül a programot tudjuk vezérelni, irányítani. Visszajelzést ad a program, átlagos Usereknek írt programnál kell a GUI nagyon.

Amit írsz a kódba, azt fogod látni a képernyőn.


Van egy ablakunk, amit látunk. Ebbe lehet grafikus eszközöket rakni. Egyszerű shape-eket fogunk felcsatolni rá. Pl. négyzet, kocka (attach() függény)
Ezeket az alakzatokat majd a display engine megrajzolja. (Opr., videókártya)


# Előadás Jegyzet Második hét - Grafikus Osztályok

A Graph header-t nézzük most.

Headerek:
	* Interface információkat tartalmazzaű
	* Deklarációk (A fordíónak megmondja, hogy az adott szimbulum mit fog jelenteni. Pl. függvények paraméterlistája)
	* Ezeket include-oljuk

A headerek mögött található az "implementation file", azaz a kódfájl. Ebben már a függvények pontos definiciók találhatóak. Ebben a header van includeolva. Így viszonylag egyszerű cserélni a library-kat.

Window - Legyen az ablak amit a képernyőn látunk (Minden oprendszeren máshogy néz ki)
Line - egy vonal 
Point - kordináta pont
Shape - mi a közös az alakzatokban?
Color - szín

Korináta lehet-e negatív?

## strcut vs class:
Szinte mindegy c++-ben, class-nál alapból privát a láthatósági szint. Struct-nál ez publikus alapból.

## Line:
Shape osztály leszármazottja. 
Egy egy pontot adunk át neki kordinátával.
Szint is tudunk nekik adni. (set_color())

## Lines:
Több vonal is lehetséges ebben az objektumban.
Pont párokat adunk hozzá.

struct Lines : Shape
A Lines egyfajta Shape. (Leszármazott, örökli a Shape tulajdonságait, függvényeit)

Shape::add() - hatókör operétor: Shape osztály Add függvényét szeretnénk használni

## Color, Vonal Stílus:
FLT konstansok vannak saját nevekre leképezve.

## Polylineok
Ez is egy shape típus

### Closed Polyline-nál van egy vonal húzva az első és utolsó pont között, azért closed.

## Text
Point x - honnantól rajzoljuk ki
string - szöveg

## Előfordító utasítás:
Csak akkor includolja ha még nincs be includeolva.
#ifndef GRAPH_GUARD
#define GRAPH_GUARD

## inline
Nem függvényként hívja, hanem folytatólagos lesz a vezérlés. Így nincs erőforrásugrás.




# Előadás Jegyzet Harmadik hét - OO 
Shape osztály főként absztrakció. Belőle tehát nem lehet példányt, objektumot készíteni.
(Constructore a protected)

Egy adott függvény ami adott feladatot csinál, annak minden osztályban ugyanaz lesz a neve.
Ami logikailag különbözően működik, annak legyen különböző neve.

A grafikus objektumokat nem jó másolni, referenciát kell használni.

Az adatok elrejtése, hogyne lehessen rosszra módosítani. (Pl. legyen radius privát, legyen egy set_radius függvény és ebben hibakezelés, hogy ne lehessen negítvra módosítani. )

Publikus tagok: az interface az osztályhoz
Privát: belső, az implementáció

## Miért jó a private?
Változhat az implementáció, könnyebb lecserélni a library-t.
Az implementációs részbe, így már ellenörzöt adat kerül. 
Az implementációs rész elrejtése.

## Protected: Olyan mint a privát, de a leszármazott osztályok elérik, az ősosztály protected részét.

## Library: osztályok és függvények gyűjteménye, Építőkövek

## Virtual calll, a hívóoldal tudja, hogy melyik leszármazott függvényét kell hívni

virtual double increase(int i) = 0; //muszáj definiálni ezt  a függvényt egy leszármazotban.

virtual destructor (Meghívja a virtual függvény desktructorát. (Pointer, heap memória))

Másoló konstruktor és másoló értékadás letíltása (=delete)

## Override check szó: Hibát jelez fordításkor, ha nem lehet felüldefiniálni

## Referencia: új név, ugyanarra az objektumra, csak más néven hivatkozunk rá.

## Pointer-nél nyilat használunk nem pontot.
