# Exam_02_01. Некорректная работа программы №1.

## Задание

**Уровень:** 1  
**Темы:** Ввод/вывод данных..  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** -  
**Выходные данные:** стандартный поток вывода (stdout)  

Необходимо исправить синтаксические, стилевые и логические ошибки, не изменяя работу программы. В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>
int main (void)
{
	int x = 0;

	scanf ("%d", x);
	printf("%05d", x);
	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 0 | 00000 |  
| 1 | 00001 |  
| -10 | -0010 |  
| 666666 | 666666 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_02_02. Некорректная работа программы №2.

## Задание

**Уровень:** 1  
**Темы:** Ввод/вывод данных..  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** -  
**Выходные данные:** стандартный поток вывода (stdout)  

Необходимо исправить синтаксические, стилевые и логические ошибки, не изменяя работу программы. В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>
int main (void)
{
	int x = -21;

	scanf ("%d", x);
	printf("%03d", x);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 0 | 00000 |  
| 1 | 00001 |  
| -12 | -0012 |  
| 55555 | 55555 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_02_03. Некорректная работа программы №3.

## Задание

**Уровень:** 1  
**Темы:** Ввод/вывод данных..  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** -  
**Выходные данные:** стандартный поток вывода (stdout)  

Написать программу для вывода на стандартный поток знаменитой фразы: "I'm Groot" (c) Groot  
В конце ответа не должно быть переноса на новую строку.

## Примеры

| Входные данные | Результат работы |  
| | "I'm Groot" (c) Groot |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_02_04. Путь к Блокноту

## Задание

**Уровень:** 1  
**Темы:** Ввод/вывод данных..  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** -  
**Выходные данные:** стандартный поток вывода (stdout)  

Предположим, что операционная система Windows установлена на диск С:, требуется написать программу для вывода полного пути до стандартной программы блокнот: C:\Windows\System32\notepad.exe  
В конце ответа не должно быть переноса на новую строку.

**Примечание:** Полный или абсолютный путь - это путь, который указывает на одно и то же место в файловой системе, вне зависимости от текущего рабочего каталога. Полный путь в Windows всегда начинается с имени диска.

## Примеры
| Входные данные | Результат работы |  
| | C:\Windows\System32\notepad.exe |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_02_05. 205.

## Задание

**Уровень:** 1  
**Темы:** Ввод/вывод данных..  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** -  
**Выходные данные:** стандартный поток вывода (stdout)  

Необходимо исправить синтаксические, стилевые и логические ошибки, не изменяя работу программы. Программа должна  вывести на экран число 205.  
В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>
int main (void)
{
	int x = 205;
	printf("%d", &x);
	return 0;
}
```

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!