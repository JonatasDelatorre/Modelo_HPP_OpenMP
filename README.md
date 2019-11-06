# Modelo_HPP_OpenMP
Computação de alto desempenho: Implementação em OpenMP do Modelo HPP

*** Todos com np = n^2/100 ***
*** notebook 4core i7 ***
*gcc trabalhoHPP.c -fopenmp*

[Thread]   [n]     [Time]
   1       100     0.0033497 ms.
   1       200     0.0469341 ms.
   1       500     1.57922 ms.
   1       1000    22.9129 ms.
   1       2000    387.892 ms. 

[Thread]   [n]     [Time]          | [Thread]  [n]     [Time]          | [Thread]  [n]      [Time]
   2       100     0.0031259 ms.   |    4      100     0.0043184 ms.   |    8      100      0.0036913 ms.
   2       200     0.0317523 ms.   |    4      200     0.0205448 ms.   |    8      200      0.0191723 ms.
   2       500     0.889995 ms.    |    4      500     0.606958 ms.    |    8      500      0.540015 ms.
   2       1000    13.9432 ms.     |    4      1000    10.5587 ms.     |    8      1000     8.30764 ms.
   2       2000    221.186 ms.     |    4      2000    130.642 ms.     |    8      2000     129.801 ms.

