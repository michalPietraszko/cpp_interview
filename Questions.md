### C++ pytania ogólne

#### Wymień rodzaje polimorfizmu w C++

   - **Statyczny** - rodzaj polimorfizmu, który jest rozpoznawany na etapie kompilacji. Przykładem jest przeciążenie ```funkcji``` i ```szablonów```.
   - **Dynamiczny** - polimorfizm dynamiczny jest rozpoznawany na etapie wykonania programu. Wykorzystuje ```funkcje wirtualne``` i ```dziedziczenie```.
   
> **Bonusowe** 
 **Czym jest ```vtable```?**
   - ```vtable``` (virtual table) to tabela zawierająca wskaźniki do funkcji wirtualnych klasy. Używana jest do implementacji polimorfizmu dynamicznego.

> **Bonusowe**
> **Czym jest i co oznacza```SFINAE```?**
   - ```SFINAE``` czyli *Substitution Failure Is Not An Error*, to zasada w C++, która pozwala na ignorowanie szablonów, które prowadzą do błędów kompilacji podczas ich zastępowania typami.  


#### Dlaczego klasa bazowa powinna mieć ```wirtualny destruktor```?

   - Klasa bazowa powinna mieć ```wirtualny destruktor```, aby zapewnić poprawne zwalnianie zasobów podczas usuwania obiektu przez wskaźnik na klasę bazową. W przeciwnym razie zostanie wywołany destruktor klasy bazowej, co może prowadzić do wycieku zasobów.

#### Wymień etapy od rozpoczęcia kompilacji do uruchomienia programu
   - ```preprocessing``` podczas tego etapu następuje zamiana makr na kod, zamiana dyrektyw ```#include``` na zawartość plików.
   - ```compiling``` to przetwarzanie preprocesowanego kodu na kod obiektowy.
   - ```linking``` to łączenie różnych plików obiektowych i bibliotek w jeden plik wykonywalny.

#### Czym jest klasa ```abstrakcyjna``` w C++?
   - Klasa ```abstrakcyjna``` to klasa, która zawiera przynajmniej jedną ```funkcję czysto wirtualną```. Służy jako baza dla innych klas, które implementują te metody. Używane są do tworzenia interfejsów, które określają zestaw operacji, które powinny być dostępne w klasach pochodnych.

#### Podaj kolejność wywoływania konstruktorów
   - Konstruktory ```klas bazowych``` od lewej do prawej, w porządku w jakim są wymienione w liście dziedziczenia.
   - Konstruktory ```członków klasy``` w porządku w jakim są zadeklarowane w klasie.
   - Konstruktor klasy pochodnej.

#### Podaj kolejność ewaluacji argumentów funkcji 
```c++
int getInt() { return 5; }
float getFloat() { return 3.14f; }
std::string getString() { return "string"; }

int f(int a, std::string b, float d);
f(getInt(), getString(), getFloat());
```

- Kolejność ewaluacji zależy od kompilatora. 

#### Czym jest ```internal``` i ```external``` linkage?
   - ```internal linkage``` oznacza, że dany ```symbol``` (np. ```zmienna``` lub ```funkcja```) jest dostępny tylko w jednym pliku źródłowym. Oznacza to, że ten sam ```symbol``` może być używany w innym pliku źródłowym bez konfliktu. 
   - ```external linkage``` oznacza, że ```symbol``` jest dostępny w całym programie. Jeżeli ten sam ```symbol``` jest używany w innym pliku źródłowym, to oba odnoszą się do tego samego obiektu.
```c++
// plik1.cpp
static int x = 5; // internal linkage

// plik2.cpp
int i = 5; // external linkage

// plik3.cpp
extern int i; // OK
extern int x; // will not work
```

#### Czym jest biblioteka statyczna i dynamiczna? 
   - Biblioteka ```statyczna``` jest dołączana do programu podczas ```linkowania```. Kod biblioteki staje się częścią programu.
   - Biblioteka ```dynamiczna``` dołączana do programu podczas jego wykonania. Pozwala na użycie tego samego kodu biblioteki przez wiele programów.

### C++ 11/14/17
#### Czym są i jak działają ```std::shared_ptr```, ```std::unique_ptr```
   - ```std::shared_ptr``` to inteligentny wskaźnik, który pozwala na wielokrotne udostępnianie obiektu. Obiekt jest usuwany, gdy ostatni ```std::shared_ptr``` do niego przestaje istnieć.
   - ```std::unique_ptr``` zapewnia wyłączne prawo do posiadania obiektu. Nie można skopiować ```std::unique_ptr``` natomiast mozna stosować na nim ```std::move()```.

> **Bonusowe**
> **Czym jest ```auto_ptr```?**
   - ```auto_ptr``` to stary rodzaj inteligentnego wskaźnika, który jest teraz przestarzały. Miał semantykę przenoszenia, ale nie był zgodny z kontenerami ```STL```. Był też problematyczny, ponieważ miał dziwaczne zachowanie przy kopiowaniu, które faktycznie przenosiło własność.

#### Jaka jest róznica między tworzeniem ```std::shared_ptr``` za pomocą ```new``` a ```std::make_shared```?

> **Przykład:** 
> ```./examples/shared_ptr_deallocation.cpp```

- ```std::make_shared``` tworzy obiekt i ```std::shared_ptr``` do niego w jednej alokacji pamięci, co jest efektywniejsze. 
- Tworzenie poprzez ```new``` wymaga dwóch alokacji - jednej na obiekt, drugiej na licznik referencji.

#### Czym jest ```std::weak_ptr```?
   - ```std::weak_ptr``` jest to rodzaj inteligentnego wskaźnika, który trzyma "słabą" referencję do obiektu zarządzanego przez shared_ptr. Nie przeszkadza to w usunięciu obiektu, ale pozwala sprawdzić, czy obiekt nadal istnieje, zanim zostanie do niego dostęp.

#### Czym jest ```std::move``` i ```std::forward```?
   - ```std::move``` jest to funkcja, która konwertuje obiekt na ```r-wartość```. Może być używana do przenoszenia obiektów, które nie są już potrzebne, zamiast kopiowania ich.
   - ```std::forward``` jest to funkcja, która pozwala na przenoszenie argumentów tak, jak zostały one przekazane do funkcji - jako ```l-wartości``` lub ```r-wartości```.

#### Czym jest ```lambda```?
   - Jest to obiekt anonimowej klasy, z operatorem ```operator() const``` wraz z listą argumentów przekazywanych jako ```capture```.

> **Bonusowe**
> **Jaka jest różnica między```lambda``` a ```std::function```?**
   - Universal reference: Jest to referencja, która może wiązać się zarówno z l-wartością, jak i z r-wartością, zależnie od kontekstu.

#### Czym jest copy ```elision```/```RVO```/```NRVO```?
   - Są to optymalizacje kompilatora, które eliminują niektóre operacje kopiowania lub przenoszenia. ```RVO``` *(Return Value Optimization)* i ```NRVO``` *(Named Return Value Optimization)* są szczególnymi przypadkami, które dotyczą zwracania wartości z ```funkcji```.

#### Czy stała ```square5``` jest dostępna w czasie kompilacji?
```c++
constexpr int square(const int number) {
    return number * number;
}

int main() {
    constexpr auto square5 = square(5);
    return 0;
}
```
   - Zależy to od kompilatora. ```gcc``` raczej stworzy ```square5``` w czasie kompilacji, natomiast ```MSVC``` jest bardziej leniwy.

> **Bonusowe**
> **W jaki sposob można zmusić kompilator do obliczenia ```square5``` w czasie kompilacji?**
   - Można użyć ```static contexpr```
   - Można użyć ```square5``` w kontekście wymagającym stałego wyrarzenia, np. ```static_assert``` lub ```std::array<int, square5>```.


### Kontenery

#### Sklasyfikuj i wymień wszystkie kontenery w STL 

- Sequence:
    - ```std::array```
    - ```std::vector```
    - ```std::deque```
    - ```std::forward_list```
    - ```std::list```
- Associative:
    - ```std::set``` 
    - ```std::multiset```
    - ```std::map```
    - ```std::multimap```
- Unordered Associative:
    - ```std::unordered_set```
    - ```std::unordered_multiset```
    - ```std::unordered_map```
    - ```std::unordered_multimap```

> **Bonusowe**
> **Jak zaimplementowany jest ```std::map```?**
- ```std::map``` jest zaimplementowany jako drzewo np. ```czerwono-czarne```.

> **Bonusowe**
> **Co nalezy zdefiniowac dla ```klasy``` aby jego ```obiekty``` umiescic w ```std::set``` i ```std::unordered_map```?**

### Wielowątkowość
#### Jaka są róznice między procesem a wątkiem?
   - Proces to egzemplarz programu w trakcie wykonywania, który ma własną przestrzeń adresową i własne zasoby.
   - Wątek to jednostka wykonawcza, która działa w kontekście procesu, dzieląc z nim przestrzeń adresową i zasoby.

#### Wymień metody komunikacji między procesami
- współdzielona pamięć
- gniazda (```sockets```)
- potoki (```pipes```)
- kolejki komunikatów (```message queues```)
- sygnały (```signals```)

#### Wymien metody synchronizacji między wątkami
- mutexy (```mutex```)
- zmienne warunkowe (```cond_var```)
- semafory
- bariery
- atomiki (```std::atomic```) 
- ```std::future```/```std::promise```

### Embedded
#### Czym jest ```watchdog```? 
- Watchdog to mechanizm, który automatycznie zresetuje system lub ```proces```, jeśli wystąpią problemy, takie jak zacięcie się lub brak odpowiedzi na sygnał ```keep-alive```.

#### Czym jest sygnał ```interrupt```?
- Przerwanie to sygnał wysyłany do procesora, który przerywa bieżące wykonywanie programu, aby procesor mógł wykonać inne zadanie, często bardziej pilne.

#### Czym jest słowo kluczowe ```volatile```
- Informuje on kompilator, że wartość zmiennej może zmieniać się w sposób nieprzewidywalny i niezależny od programu. Uniemożliwia to optymalizacje, które mogłyby zakładać, że zmienna
  nie zmienia się między poszczególnymi dostępami.

#### Różnica między systemami ```real-time``` a ```near real-time```
- System ```real-time``` gwarantuje reakcję na wejście w ściśle określonym czasie. 
- System ```near real-time``` stara się reagować jak najszybciej, ale nie daje gwarancji na reakcję w określonym czasie.

#### Czym jest RTOS (Real Time Operating System)
- ```RTOS``` to system operacyjny zaprojektowany do obsługi operacji ```real-time```. Zapewnia on funkcje, takie jak deterministyczne priorytety zadań, szybkie przełączanie kontekstu i obsługę ```przerwań```.

### Systemy Operacyjne
#### Czym jest ```wirtualizacja pamięci```, jakie problemy rozwiązuje, dlaczego jest potrzebna?
   - Jest to mechanizmem systemu operacyjnego, który pozwala na wydzielenie przestrzeni adresowej dla każdego ```procesu```, tak jakby każdy z nich był jedynym procesem korzystającym z ```pamięci```. 
   - ```Wirtualizacja``` pamięci rozwiązuje wiele problemów, takich jak bezpieczeństwo (``procesy`` nie mogą naruszyć ```pamięci``` innych ``procesów``), efektywne zarządzanie ```pamięcią``` (np. przez ```stronicowanie```, które pozwala na przechowywanie nieaktywnych porcji ```pamięci``` na ```dysku```) oraz izolację ```procesów```.


#### Dlaczego iteracja po wewnętrznych wektorach jest szybsza dla ```std::vector<std::vector<Foo>>```?
   - ```Iteracja``` po wewnętrznym wektorze w jest szybsza, ponieważ ```std::vector``` gwarantuje ciągłe przechowywanie elementów w pamięci. Dzięki temu, procesor może skutecznie korzystać z predykcji ```branchingu``` i ```cache```, co przyspiesza ```iterację```.

#### Dlaczego ```std::vector``` jest szybszy niż ```std::unordered_map``` dla małych kontenerów?
   - ```std::vector``` jest kontenerem opartym na tablicy, co oznacza, że ma doskonałe właściwości ```lokalności pamięci```, które są dobre dla ```cache``` procesora. Dla małych kontenerów koszt przeszukiwania ```std::vector``` jest zaniedbywalny, a operacje na ```std::vector``` są zwykle szybsze niż na ```std::unordered_map```, który korzysta z ```haszowania```, co dla małych kontenerów, moze być wolniejsze.


### Debugowanie
#### Czym jest ```valgrind```?
   - ```Valgrind``` to narzędzie do ```debugowania``` i ```profilowania```, które pomaga znaleźć problemy z pamięcią, takie jak wycieki pamięci, niezainicjowane zmienne, dostęp do pamięci poza granicami zaalokowanego obszaru, itp. Jest bardzo użyteczny do znajdowania subtelnych błędów, które są trudne do wykrycia przez inne metody.

#### W jaki sposób debugowałbyś ```deadlock```?
- ```gdb```
- logi
- ```core dump```

### Dobre praktyki
#### Jakie znasz akronimy dobrych praktyk?
   - ```DRY``` - *Don't Repeat Yourself* - Unikaj powtarzania tego samego kodu w wielu miejscach.
   - ```KISS``` - *Keep It Simple, Stupid* - Staraj się utrzymać kod prostym i zrozumiałym.
   - ```YAGNI``` - *You Aren't Gonna Need It* - Nie dodawaj funkcji na zapas, które mogą być potrzebne w przyszłości.
   - ```SOLID``` - zbior pięciu zasad dobrego projektowania i programowania obiektowego, które pomagają tworzyć kod bardziej zrozumiały, elastyczny i łatwy do utrzymania.


#### Rozwiń ```SOLID```
   - ```Single Responsibility Principle```
    Zasada ta mówi, że klasa powinna mieć tylko jeden powód do zmiany. Innymi słowy, klasa powinna mieć tylko jeden obowiązek.
   - ```Open/Closed Principle```
   Klasa powinna być otwarta na rozszerzenia, ale zamknięta na modyfikacje. W praktyce oznacza to, że powinno być możliwe dodanie nowych funkcji poprzez dodanie nowego kodu, a nie modyfikowanie istniejącego.
   - ```Liskov Substitution Principle```
   Zasada ta mówi, że powinniśmy być w stanie użyć dowolnej klasy pochodnej zamiast jej klasy bazowej, bez zakłócania działania programu.
   - ```Interface Segregation Principle```
   Klienci nie powinni być zmuszani do zależności od interfejsów, których nie używają. Innymi słowy, lepiej mieć wiele specyficznych interfejsów niż jeden "uniwersalny".
   - ```Dependency Inversion Principle```
   Moduły wysokiego poziomu nie powinny zależeć od modułów niskiego poziomu. Zależności powinny wynikać z abstrakcji, a nie z konkretów.

#### Czym jest ```rule of 0, 3, 5```?
   - ```Rule of Zero``` - twórz klasy, które nie wymagają jawnego zarządzania zasobami. Skorzystaj z mechanizmów ```RAII``` (*Resource Acquisition Is Initialization*), takich jak ```smart pointery```, które automatycznie zarządzają zasobami.
   - ```Rule of Three``` - jeśli klasa definiuje jedną z następujących funkcji: destruktor, konstruktor kopiujący, operator przypisania kopiujący, to powinna zdefiniować wszystkie trzy.
   - ```Rule of Five``` - w kontekście ```C++11``` i późniejszych, jeśli klasa definiuje lub usuwa dowolną funkcję zarządzania zasobami (*destruktor, konstruktor kopiujący, operator przypisania kopiujący, konstruktor przenoszący, operator przypisania przenoszący*), powinna zdefiniować lub usunąć wszystkie pięć.

### Wzorce projektowe
#### Czym są design patterny i dlaczego ich używamy
   - ```Design Patterns```, czyli wzorce projektowe, to sprawdzone rozwiązania dla często występujących problemów w projektowaniu oprogramowania. Są one jak gotowe szablony, które można dostosować do konkretnych potrzeb. Używamy ich, aby poprawić strukturę kodu, promować dobre praktyki i zwiększyć czytelność i zrozumiałość kodu. Pomagają one także w komunikacji między programistami, ponieważ nazwy wzorców często są powszechnie rozumiane.

#### Wymień znane Ci design patterny
   - ```Singleton``` - zapewnia, że klasa ma tylko jedną instancję i dostarcza globalny punkt dostępu do niej.
   - ```Factory``` - służy do tworzenia obiektów bez ujawniania logiki tworzenia.
   - ```Builder``` - oddziela konstrukcję obiektu od jego reprezentacji, zawsze tworząc ten sam typ produktu.
   - ```Adapter``` - konwertuje interfejs jednej klasy na interfejs oczekiwany przez klientów. Pozwala na współpracę klas, które normalnie nie byłyby kompatybilne.

> **Bonusowe**
> **Czym są ```wzorce architektoniczne``` i wymien jakie znasz**
- ```Wzorce architektoniczne``` to ogólne, wielokrotnie używane rozwiązania do organizowania struktury oprogramowania. W przeciwieństwie do wzorców projektowych, które są stosowane w ramach pojedynczych modułów, wzorce architektoniczne są stosowane na poziomie architektury systemu. Przykłady wzorców architektonicznych to:

- ```MVC``` - *Model-View-Controller* - rozdziela logikę biznesową, interfejs użytkownika i sterowanie.
- ```MVVM``` - *Model-View-ViewModel* - jest podobny do ```MVC```, ale jest bardziej skupiony na zapewnieniu większej abstrakcji logiki interfejsu użytkownika i lepszego wiązania danych.
- ```Client-server``` podzielony na dwa oddzielne części: ```serwer```, który dostarcza usługi, i ```klient```, który korzysta z tych usług.
- ```Event-driven``` oparty na komunikacji między komponentami, które reagują na zdarzenia.
- ```Microservices``` rozdziela aplikację na wiele niezależnych, drobnych usług, które komunikują się między sobą.

