Лабораторная работа No5.б – Алгоритмы на графах

Kernel: 4.19.128-microsoft-standard

OS: Ubuntu 20.04.1 LTS on Windows 10 x86_64

gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

Компилирование

```linux
g++ test-graph-a.cpp graph-a.h
```

Вывод

```linux
Graph:
0 (1,9) (2,2) (3,2) (4,4) 
1 
2 (0,8) (4,9) 
3 (0,6) (1,10) (4,4) 
4 (0,7) (1,9) 
print for https://csacademy.com/app/graph_editor/
0 1 9
0 2 2
0 3 2
0 4 4
2 0 8
2 4 9
3 0 6
3 1 10
3 4 4
4 0 7
4 1 9
Алгоритм Тарьяна:
0 3 2 4 1 
Алгоритм Флери:
0 2 4 0 3 4 1
Алгоритм на основе циклов:
Нет эйлерова цикла
Алгоритм Косарайю:
0 2 3 4 1 
```