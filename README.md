# tasksCPP
 Some tasks in c++


Общие сведения
Абстрактный тип данных (АТД) – это тип данных, который предоставляет для работы с элементами этого 
типа определённый набор функций или операций. Вся внутренняя структура такого типа спрятана от
использующего его разработчика программного обеспечения, то есть мы абстрагируемся от его внутреннего
устройства при использовании. В C++ АТД реализуется классом, в котором нет открытых членов-данных.
Цель – реализовать и протестировать новый класс, представляющий абстрактный тип данных, т.е. такой, 
пользователи которого могут обращаться только к публичным операциям, предусмотренными создателем класса, 
и не имеют информации о внутреннем его устройстве. 
Средство – язык С++ 
Пользователем (клиентом) класса считается не "пользователь программы" или "компьютерный пользователь" 
вообще, а программист, использующий ваш класс для решения своих задач, пишущий свою программу на его основе. 
Иногда также под пользователями класса понимаются другие классы, фрагменты программ, которые пользуются
его услугами. 
Дополнительные требования и условия к Task2 
По заданию требуется использовать язык C++ (а не C), старайтесь использовать средства языка С++ (ввод-вывод
cin/cout и т.п.; new и delete, а не malloc/free).
В данном задании не разрешается использовать контейнеры из STL языка C++. Написание собственных аналогов
стандартных STL контейнеров (например, string и vector) с соответствующим набором функций приветствуется. 
Методы (нестатические), которые не изменяют состояние объекта, должны быть объявлены как константные, если
это не противоречит смыслу использования АТД.
Программа должна быть представлена минимум тремя файлами: 
• <АТД>.h – объявлено все, что необходимо включить в программу, для использования вашего класса АТД,
• <АТД>.cpp – реализации нетривиальных методов класса,
• main.cpp – пользовательский интерфейс для тестирования.
При тестировании в поток stderr выводятся результаты теста или ошибки, полученные в ходе теста (для заранее
заданного набора тестов также должен выводиться номер теста). Makefile (или аналог) должен содержать цель clean 
для уборки за собой, а также цель test, которая компилирует main.cpp и прогоняет заранее заданный набор тестов и
завершает программу (это можно реализовать с помощью argv). По умолчанию подразумевается цель test.
Для класса, реализующего АТД, необходимо определить: 
• конструктор по умолчанию,
• конструктор копирования (глубокое копирование, если необходимо),
• операцию присваивания (предварительно уничтожить старое значение + см. требование выше относительно
копирования),
• деструктор (стоит предусмотреть ситуацию повторного вызова деструктора: он не должен пытаться в этом
случае освобождать в динамической памяти объекты повторно – это может привести к ошибке выполнения),
• базовый класс исключения, выбрасываемого всеми операциями класса, возможно с потомками – для более
детальной классификации ошибок, – вложен в основной класс (например, string_list::error).
Правильный вывод ошибок должен содержать, хотя бы приблизительно, номер строки, в которой произошла
ошибка

Вариант Task811
Вариант 2. Стек строк
Стек в обычном понимании (LIFO, последним вошел – первым вышел).
Вариант 2.1 (*)
Строки сохраняют начальные и конечные пробельные последовательности.
Обязательные операции: 
1) stack(char*) – конструкторы стека из одного элемента;
2) stack::push( char*) и синоним stack + char*– положить копию строки;
3) char* stack::pop() – вернуть верхний элемент с удалением из стека; 
4) char* stack::peek() – вернуть копию верхнего элемента без удаления;
5) int stack::length() – текущий размер;
6) stack - char* – синоним pop, записывающий результат во второй операнд; 
7) stack1 + stack2 – вернуть конкатенацию стеков, при этом на вершине стека должен оказаться, последний
элемент второго стека, операнды неизменны;
8) stack1 += stack1 – присоединить к первому списку, второй неизменен;
9) приведение к char*– вернуть строку, где все элементы разделены \n; 
10) int stack::length() – текущий размер



Вариант Task8.1
Вариант 4. Вещественная матрица
Вещественным числом считается число типа double. Необходимо реализовать вещественную матрицу – 
понятие линейной алгебры. Нужно обеспечить пользователя класса естественным интерфейсом
математических операций для работы с матрицами и составления вычислительных программ. 
Для удобства тестирования и отладки ввести строковое представление матрицы, похожее на инициализатор
двумерного массива. Так, строка "{{1, 0, 0}, {0, 1, 0.5}}" обозначает матрицу размера 2´3: 
 | 1 0 0 | 
 | 0 1 0.5 | 
Вариант 4.1 (***) 
Обязательные операции: 
1) matrix( int n, int m ) – конструктор матрицы размера n´m со значениями 0.0;
2) matrix( double ) – матрица 1´1 с этим элементом;
3) matrix( double*, int m ) – матрица-строка из массива длины m;
4) matrix( int n, double* ) – матрица-столбец из массива длины n;
5) matrix( char*) – из строкового представления (см. выше);
6) static matrix matrix::identity( int n ) – возвращает единичную матрицу размера n;
7) static matrixmatrix::diagonal( double* vals, int n ) – возвращает диагональную матрицу размера n с заданными
элементами по главной диагонали;
8) int matrix::rows() – число строк;
9) int matrix::columns() – число столбцов;
10) matrix::set( int i, int j, double val ) – присвоить значение элементу [i][j];
11) matrix matrix::matrix[ i ] – i-я строка в виде новой матрицы, если такая строка есть – 1-й приоритет
12) matrix matrix::matrix[ j ] – j-й столбец в виде новой матрицы, если такой столбец есть – 2-й приоритет, –
иначе ошибка (если M – матрица, то M[i] –матрица из одной строки, а М[i][j] – матрица 1´1 из одного элемента);
13) matrix * scalar и matrix*=scalar – умножение матрицы на скаляр;
14) перегрузка операции << – вывод матрицы, в привычном двумерном виде

Ко всему этому добавлены ещё несколько операций, такие как сумма матриц, умножение и т.д.

-----------------------------------------------------------------------------------------
Task3 – общие сведения
Цель – Придумать иерархию классов на любую тему с абстрактным классом в основе и наличием
минимум одной чистой виртуальной функцией. Иерархия классов должна включать минимум один
класс с множественным наследованием.
Средство – язык С++
Например: абстракция "геометрическая фигура", виртуальный метод -- площадь. Для абстрактной
фигуры формулы площади нет, но для классов-наследников, таких как треугольник, квадрат и т.п. 
метод вычисления площади замещается на свою функцию вычисления площади соответственно
треугольника, квадрата и т.п.
Абстракция "геометрическая фигура с фиксированным вырезом" может иметь реализацию чистой
виртуальной функции, возвращающую площадь выреза, которую нужно вычесть из общей площади
фигуры
Дополнительные требования и условия кTask3
• Программа должна состоять минимум из 8 файлов: .h для абстрактного класса, наборы из
.h и .cpp для классов потомков (минимум 3), .cpp с функцией main
• Функция main должна предоставлять пользовательский интерфейс для работы с классами –
создание и удаление объектов, вызов их методов. Кроме того, необходимо подготовить
тест (запускаемый отдельной командой) для абстрактного метода(-ов) классов, 
реализуемый путем вызова соответствующего метода через указатель на базовый класс
(например, для иерархии классов геометрических фигур – вычисление суммарной площади
всех созданных в программе объектов)
• Использование protected-областей должно быть обоснованным.
• Чистую виртуальную функцию нужно выбрать такую, чтобы ее невозможно было
реализовать в классе родителе, либо чтобы она делала какое-то действие, требующее
завершения в наследниках.
В придуманной иерархии выделение чистой виртуальной функции должно быть осмысленно
(т.е. такая функция действительно совершенно по-разному реализуется в наследниках и
ее либо невозможно реализовать в базовом классе, либо она делает какое-то базовое действие, 
которое обязательно должно доделываться по-разному в наследных классах). Иначе многие
пишут абстрактный класс Студент с чистой вирт. ф-ей, печатающей имя, и двух наследников - класс
Вася и класс Петя. Это не годится.
В разделе “Варианты” указаны ориентировочные варианты задания с указанием их сложности, но
вы можете придумать собственную иерархию классов, сложность которой будет оцениваться
преподавателем в индивидуальном порядке


Вариант task9.2
Абстрактный класс – Фигура
Классы наследники: Круг, квадрат
Класс с множественным наследованием – геометрическая фигура с фиксированным вырезом
Чистая виртуальная функция – площадь