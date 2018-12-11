# Лабораторная работа по оптимизации
## Сборка

Для сборки потребуется Intel C++ Compiler. Работоспособность проверена только на версии 19.

Для сборки под Windows необходимо открыть консоль разработчика Visual Studio и перейти в каталог с исходными файлами. Сборка осуществляется следующей командой:
```path_to_parallel_studio\compilers_and_libraries_2019\windows\bin\intel64\icl.exe /Fomatrix /O2 /Ob1 /Qaxkabylake /Qopenmp /Qopt-report:5 /DEBUG /SUBSYSTEM:CONSOLE /Zi main.cpp /link /SUBSYSTEM:CONSOLE /LIBPATH:path_to_parallel_studio\compilers_and_libraries_2019\windows\compiler\lib\intel64_win"```

## Запуск
В качестве параметра командной строки можно передать размер квадратных матриц для корректировки времени работы (по умолчанию 4000). На выходе программа напечатает время работы матричного умножения в секундах.