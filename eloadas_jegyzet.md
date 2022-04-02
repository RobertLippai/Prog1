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

# Előadás Jegyzet Negyedik hét

Function (föggvény, range(x0-xN), első pont, egyéb);
n_points: hány pontot
x_scale, y_scale: mekkora legyen a függvény

Constansokat fontos használni!

Fct double paramétert vár és double-al tér vissza

## Marks: a polylineok törésvonalaknak helyére teszünk egy kis jelzőt (stringet)
Az átadott stringet, betűnkönt hozzápárosítjuk a polylineok töréspontjához (ahol a pont van).

c_str() ez egy karakter pointer

## Image:
Konstruktor: Kezdőpont, String (Fájlnév), Encoding

## Map: string kulcs, stuffix az érték olyan mint a Python dictionary

Iterator, a string annak az elemére mutat ahol a megadott char van.
s.end() végigment a stringen, de nincs meg a keresett char

# TODO: Stuffix keresést a végétől kezdeni, hogy elérési utvonalakkal is működjön

## Pure Virtual Function: Olyan osztály, amiben megtalálható a pure virtual function, annak nem lehet példánya! Így az osztály absztrakt!


# Előadás Jegyzet Ötödik hét - GUI
A GUI egy Input/Output eszköz
A legtöbb átlagfelhasználói program GUI-val rendelkezik

Event drive -  a program vár egy eseményre, hogy folytassa a működését / futasson valamit

GUI részei: 
	* Gombok
	* Textfield
	* Radio buttons

Feladatai:
	* szövegek, számok megjelenítése
	* alakzatok, stílus, szín
	* egér követése, drag n drop, kéziárás felismerése

## Itt már a lines_window-ot fogjuk használni.

Widget: Valamilyen működésre képes dolog (Gomb, Textfield stb)
A button egy widget. (Szín, outline, text)
Ha rákattintunk a gombra egy callback triggerelődik. 

Gomb(Point xy, int w, int h, string felirat, callback )

Quit(ablak_címe(melyikbe nyomtuk meg)) és annak az ablaknak kell meghívni a megfelelő függvényét.


#include "gui.h", ha használni akarunk gombokat

static void -- tudjuk hívni objektum példány nélkül is

reference_to a memória címet átalakítja egy simple-window tagra és azon hívja meg
Simple_window(Point xy, int w, int h, const string& title );



Window::Window(Point xy, int ww, int hh, const string& title)
:Fl_Window(xy.x,xy.y,ww,hh,title.c_str()),w(ww),h(hh)
{ 
	init();
}

Itt a w a tag, a ww amit a konstruktorból kapunk.

unsigned int -- előjel nélküli típus, nem lehet negatív

## inline nem ugrik a vezérlés, hanem folytatólagos a hívott helyen
A lefordított kódban már nem a hívott függvényre található, hanem a hívott függvényben lévő kód!

Általában ősosztályoknál leszoktuk a másolást tiltani. Ezért pointert vagy referenciát hazsnálunk, ha pl. egy vectorba szeretnénk tenni. 

## Slicing: a leszármazott osztály tegjai nem jelennének meg, amik nincsenek benne az ősosztályban. Pl. Shape ősosztály, Shape vector, 
Kör a leszármazott a kör sugara és egyéb paramétere nem lenne benne a Shape vectorban így.

## void* egy olyan memóricím ami valamilyen memóriácímre mutat
## függvény pointer: így regisztráljuk itt a gombhoz a függvényt. Átadjuk a gombnak a függvény memóricímét. Ez hasznos, 
ha van valami aminek szeretnénk átadni egy függvényt. A függvény memória címét pedig könnyű átadni.
## reference_to: egy memória címből csinál egy tetszőleges referenciatípust.
## widgeteknél is levan tiltva a másolás

## GUI.h, Menu widget, ez kell majd a drillhez.


# C++ Memóriakezelés ismétlés:
A vektor az alapértelmezett tároló c++-ban. 
Memória: semmi ellenörzés, semmi rugalmasság de cserébe nagyon gyors

## Pointerek:

A pointer egy memóriacím. 
A memória byte-onként van címezve. 

Jele: *
pl double*: ez egy olyan memóriacím ami egy double típusu objektum memória címét tárolja___*

## Free Store:
Hasznos ha pl. szeretnénk, hogy túlélje a scope-ot amiben foglaltuk.

Ha pl 7 dolognak foglalunk így memóriát, akkor a pointer mindig a legelső elem címét adja vissza!
De szépen egymás után fognak következni, ezért ha léptetjük byte-onként a következő elemet kapjuk meg.

A pointer nem tudja, hogy hány elemre mutat. Csak a memória címet tudja!

new int(5) //egy darab int-et foglal, aminek öt lesz az értéke
new int[5] //öt darab int-et foglal

* - dereference operatoral tudjuk elkérni_*
pl. int x = *p2; _*

Ha van más megoldás érdemes azt használni, ahelyett, hogy mi kezeljük közvetlenül a memóriát.

## C-style string karaktertömb
A c-style stringek végén van egy \0
Amint a while elér a \0-hoz a while hamis lesz

# Free Store:
Ha new-el foglalunk delete-el felkell szabadítani.

# Vector:
n elem sorozata, futás során változhat az elemek száma

# Destructor:
Fájlok, Socketek, Free Store használata esetén fontos a class-oknál
A destructor automatikusan hívodik.

virtual destructor, ha van egy base classunk. Hogy hívodjon a leszármazott desktruktor, ha az ős referencián keresztül használjuk. 

# Másolás

Deep Copy: az értékeet is lemásolja, egy új memória területre

Shallow copy: csak a memória címet másoljuk, így ugyanarra fog mutatni, ha egyik helyen módosítunk az értéken, akkor az összes helyen módosul.

## A return alapból másol. 

## Az egy paraméteres konstruktor legyen explicit

# Generikus programozás:
Jelenleg a vectorunk csak egy típusra működik. Kezdetben sokszor szoktunk így, hogy elérjük, hogy először egy típusra jól és stabilan működjön.
Késöbb pedig megcsináljuk, hogy bármilyen típusra működjön.
A cél, hogy paraméterezhető legyen (vagyis bármilyen típusra jó lesz, hozzátudjuk majd írni, hogy milyen típust fogad el)
pl. vector<double> itt a double a paraméter

"Típusok és függvények paraméterezhetősége típusokkal és egésszekkel."

## Template Definició:
template<class T> class Vector {...};

T a típus paraméter

Függvényeknél a fordító kitudja következtetni a template paramétereket. 

Type Safty: Predikátum függvény (Igazat vagy hamisart ad vissza), egy feltétel aminek a T type-nak megkell felelnie.

## Erőforrás:
Valamilyen eszközt amit lekell foglalunk és felkell szabadítanunk
általában a konstruktorokban a legjobb ezeket lefoglalni
És a destruktorban érdemes felszabadítani ezeket

## Unique Pointer: 
Egy smart pointer, ami felügyeli, hogy használjuk-e még az adott pointert.
Így ez fogja a memória felszabadítást végezni. Így nekünk nem kell rá külön figyelni.

## Make Unique Pointer:
Mégegyszerűbb használni, ezt javasolt főként használni. 
Itt még new-t sem kell használni.

# De ha lehet ne használjunk semmilyen pointert!

# RAII:
## Scoped Resource Managment:
Memória foglalás a konstruktorban
Desktruktor felszabadít
Így automatikusan van kezelve a memóriaterület.
Ha hibát / kivételt kapunk, akkor is hívódik a scopeos objektumok desktruktora.

Garanciák:
* Vagy lefut sikeresen vagy a try catch miatt kivételt dob
* Erős garancia: Minden elérhető változó, ugyanolyan értéket vesz fel, mint a hiba hívása előtt volt. (Tehát mintha mi sem történt volna)
* No-throw: írjunk olyan kódot ami nem dob kivételt, kerüljük a new a threw és a dynamic cast használatát

## Allocator: generikus eszköz, ami tetszőleges objektumokoknak tud memóriát foglalni
alloc.allocate(s) s darab elemnek foglal memóriát.
Olyan memóriát ami az adott allocator típusnak kell.

## Iterátor: begin első elem, end utolsó utáni elem:
* acces
== ugyanarra mutat-e a két iterátor?
++ következő elem

end = utolsó utáni elemre mutat mindig!

for(auto& x:v) minden elemet bejár begin és end között

## unique_ptr.relase():
// release, az unique pointerből átadjuk a jogot. Az birtokolja aki akarja. 


# Week 7: STL
Tárolók, algoritmusok, iterátorok

Szekvencia tárolók

Generizálás: úgy készítjük / átalakítjuk a kódot, hogy az ne függjön semmilyen típustól. Így típusmentes lesz.

Miután nem függ a típustól algoritmusnak nevezzük.

STL: C++ Std-ben van benne

Algoritmusok és tárolók szétvannak választva. Az iterátorok segítenek, hogy az algoritmusok hozzáférjenek a tárolókhoz.

Boost library, nagyon jó.

## Iterator pár: 
begin - legelső elem
end - utolsó utáni elem! (nem létező elem!)

* acces
== ugyanarra mutat-e a két iterátor?
++ iterátor léptetése
-- iterátor léptetése (nem mindig van)
[] (nem mindig van)

## Pl. egy kereső függvényél: end() a visszatérés ha nincs benne a keresett elem

## Nevesített objektum:
Ha valami összetett dolog
Ha valami több helyen kell

## Lambda expression:
Ha rövid és egyértelmű

# Week 8:
Typesafty-re figyelni: pl. ha összeadunk figyelni kell, hogy lehet, hogy double-okat adunk össze és ilyenkor az összesnek is érdemes abba lenni. Hogy ne vesszen el, ha intben lenne.

Azért csak 1 iterátor van a második paramtéternél, mert már az első iterátor pár meghatározza a hosszát.
Ha még a 2. hosszabb, arra a részre már nem fogunk akkor sem menni!

## Map (Asszociativ):
Vector: egéssz lesz az "index". Azaz egész a subscript
Lista: itt nincs subscript
Map: bármi lehet subscript. Kulcs-érték párok
pl. map<string, int>
	Ahol string = kulcs (map.first)
	int = érték (map.second)


## Másolásnál:
Az iterátort léptetjük és dereferenciáljuk
*res = *first;
++res;
++first;


