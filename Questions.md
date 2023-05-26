### C++ pytania ogólne

#### Wymień rodzaje polimorfizmu w C++

   - **Statyczny** - rodzaj polimorfizmu, który jest rozpoznawany na etapie kompilacji. Przykładem jest przeciążenie ```funkcji``` i ```szablonów```.
   - **Dynamiczny** - polimorfizm dynamiczny jest rozpoznawany na etapie wykonania programu. Wykorzystuje ```funkcje wirtualne``` i ```dziedziczenie```.
   
> **Bonusowe** 

##### Czym jest ```vtable```?
   - ```vtable``` (virtual table) to tabela zawierająca wskaźniki do funkcji wirtualnych klasy. Używana jest do implementacji polimorfizmu dynamicznego.

##### Czym jest i co oznacza```SFINAE```?
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
##### Czym jest ```auto_ptr```?
   - ```auto_ptr``` to stary rodzaj inteligentnego wskaźnika, który jest teraz przestarzały. Miał semantykę przenoszenia, ale nie był zgodny z kontenerami ```STL```. Był też problematyczny, ponieważ miał dziwaczne zachowanie przy kopiowaniu, które faktycznie przenosiło własność.

#### Jaka jest róznica między tworzeniem ```std::shared_ptr``` za pomocą ```new``` a ```std::make_shared```?

> **Przykład:** 
> ```./examples/shared_ptr_deallocation.cpp```

- ```std::make_shared``` tworzy obiekt i ```std::shared_ptr``` do niego w jednej alokacji pamięci, co jest efektywniejsze. 
- Tworzenie poprzez ```new``` wymaga dwóch alokacji - jednej na obiekt, drugiej na licznik referencji.

#### Czym jest ```std::weak_ptr```?
   - ```std::weak_ptr``` jest to rodzaj inteligentnego wskaźnika, który trzyma "słabą" referencję do obiektu zarządzanego przez shared_ptr. Nie przeszkadza to w usunięciu obiektu, ale pozwala sprawdzić, czy obiekt nadal istnieje, zanim zostanie do niego dostęp.

   - Semantyka move i std::forward: Move służy do oznaczania obiektów, które mogą być bezpiecznie "przeniesione" zamiast kopiowane. Std::forward jest używane w szablonach

 do przenoszenia argumentów tak, jak zostały one przekazane do funkcji - jako l-wartości lub r-wartości.

   - Lambda: Jest to anonimowa funkcja, która może być używana w miejscu, w którym jest zdefiniowana.

   - Universal reference: Jest to referencja, która może wiązać się zarówno z l-wartością, jak i z r-wartością, zależnie od kontekstu.

   - Copy elision/RVO/NRVO: Są to optymalizacje kompilatora, które eliminują niektóre operacje kopiowania lub przenoszenia. RVO (Return Value Optimization) i NRVO (Named Return Value Optimization) są szczególnymi przypadkami, które dotyczą zwracania wartości z funkcji.

   - Dostępność stałej square5 w czasie kompilacji: Zależy to od tego, jak jest zdefiniowana. Jeśli jest to stała czasu kompilacji (constexpr), jest dostępna w czasie kompilacji. Można to osiągnąć, definiując ją jako constexpr: `constexpr int square5 = 5*5;`.

Kontenery
Wszystkie kontenery w Standard Template Library (STL) to: array, vector, deque, forward_list, list, set, multiset, map, multimap, unordered_set, unordered_multiset, unordered_map, unordered_multimap, stack, queue, priority_queue.

Wielowątkowość
1.Różnica między procesem a wątkiem:
   - Proces to egzemplarz programu w trakcie wykonywania, który ma własną przestrzeń adresową i własne zasoby.
   - Wątek to jednostka wykonawcza, która działa w kontekście procesu, dzieląc z nim przestrzeń adresową i zasoby.

2. Metody komunikacji między procesami: Współdzielona pamięć, gniazda (sockets), potoki (pipes), kolejki komunikatów (message queues), sygnały.

3. Metody synchronizacji między wątkami:Mutexy, zmienne warunkowe, semafory, bariery, atomiki, future/promise.

Embedded
1. Watchdog (software/hardware): Watchdog to mechanizm, który automatycznie zresetuje system lub proces, jeśli wystąpią problemy, takie jak zacięcie się lub brak odpowiedzi na sygnał "jestem żywy" (keep-alive).
2. Interrupt (sygnał przerwania): Przerwanie to sygnał wysyłany do procesora, który przerywa bieżące wykonywanie programu, aby procesor mógł wykonać inne zadanie, często bardziej pilne.
3. Volatile Specyfikator "volatile" w C++ informuje kompilator, że wartość zmiennej może zmieniać się w sposób nieprzewidywalny i niezależny od programu. Uniemożliwia to optymalizacje, które mogłyby zakładać, że zmienna

 nie zmienia się między poszczególnymi dostępami.
4. **Różnica między real-time a near real-time:** System real-time gwarantuje reakcję na wejście w ściśle określonym czasie. System near real-time stara się reagować jak najszybciej, ale nie daje gwarancji na reakcję w określonym czasie.
5. **RTOS (Real Time Operating System):** RTOS to system operacyjny zaprojektowany do obsługi operacji real-time. Zapewnia on funkcje, takie jak deterministyczne priorytety zadań, szybkie przełączanie kontekstu i obsługę przerwań.


