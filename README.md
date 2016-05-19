# SEANS

## входная точка
```
fn main:
	тело программы
```

## Типы данных
* none //возможные значения -> none
* bool //возможные значения -> true/false
* double //возможные значения -> числа с плавающей запятой [0..9]
* array //возможные значения -> индексирумые типы
* string //возможные значения -> любые комбинации символов [0..9a-Zа-Я,./!@#$%^&* ()_+{}\[\]\\]

## Приведение типов
* bool(значение/переменная)
* double(значение/переменная)
* string(значение/переменная)



## Переменные
//Переменные начинаются с маленькой буквы
//объявление переменной
имя_переменной = значение//типизировнные переменные имя_переменной:тип = значение


## Функции
*//Функции начинаются с большой буквы*
*//объявление функции*
```
fn Имя_функции(аргументы)://типизированная функция fn Имя_функции(аргумент:тип аргумента):тип возвращаемого значения:
	тело функции
	return значение
```



## циклы
```
for(имя_пееременой = начальное_значение;условие_конца;работа_над_переменной):
	тело
```
//Ключевое слово break принудительный выход из цикла



## условие
```
if():
	тело

if():
	тело
else:
	тело 2

if():
	тело
elif():
	тело 2
```



## доступные операции и выражения
```
=
/=
*=
+=
-=
++
--
+
-
/
* 
^

==
!=
>
<

!
&&
||
```



## Массив
```
[]
```

*//при инциализации, следует указывать размер массива, а так же начальное значение в круглых скобках*
```
arr = [100](0)
*//выделит память под 100 элементов, с начальным значением 0*
```



## Встроенные функции

### функция len - возвращает размер элемента, доступна для типов массивов, строк
*//возвращает размер массива*
```
arr = [8]
len(arr)
*//вернет 8*
```

*возвращает размер строки*
```
str = "hello world"
len(str)
*вернет 11*
```

### Функция print(имя_переменной) - функция вывода на экран 
```
print(result)
*//выведет на экран содержимое переменной result*
```

### Функция input(строка) - функция считывания с клавитуры
```
name = input("Введите ваще имя")
*//Вывдет на экран строку "Введите ваше имя", а так же запишет в переменную name имя, введеное с клавиатуры*
```

### Функция char() - функция возвращает представление символа по индексу unicode в виде строки
```
ch = char(2764)
*//Вернет знак сердечка*
```


## Подключение подпрограмм
```
import название_модуля//либо адрес файла
```



## Ключевое слово const
```
const название_константы = значение
```



## ключевой символ & ссылки
```
&имя_переменной = переменная
```



#Примеры программ



### Hello world
```
fn Main():
	result = "hello world"
	print(result)
```

### Нахождение чисел фибоначчи
```
fn Fib(n):
    a = 0
    b = 1
    for (i = 0; i < n;i++):
    	c = b
    	b = a + b
    	a = b
    return a

fn Main():
	in = input()
	result = fib(in)
	print(result)
```



### Калькулятор
```
fn Plus(first, second):
	result = first + second
	return result

fn Minus(first, second):
	result = first - second
	return result

fn Multiplication(first, second):
	result = first *  second
	return result

fn Division(first, second):
	result = first / second
	return result

fn Main():
	numarg = 0
	first = 0
	second = 0
	operation = ""
	for(;;):
		in = input()
		if(in == "break"):
			break
		elif(numarg == 0):
			first = double(in)
			numarg++
		elif(numarg == 1):
			opeation = in
			numarg++
		elif(numarg == 2):
			second = double(in)
			if(operation == "plus"):
				Plus(first, second)
			elif(operation == "minus"):
				Minus(first, second)
			elif(operation == "division"):
				Division(first, second)
			elif(operation == "multiplication"):
				Multiplication(first, second)
			else:
				print("error operation")
			numarg = 0
		else:
			result = "error"
			print(result)
			break
```



### Пузырьковая сортировка
```
fn Main():
	list = [8](0)
	list[0] = 5
	list[1] = 2
	list[2] = 7
	list[3] = 4
	list[4] = 0
	list[5] = 9
	list[6] = 8
	list[7] = 6

	n = 1 
	for(;n < len(li);n++):
    	for(i = 0; i < 8 - n; i++):
          if(li[i] > li[i+1]):
          	buffer = li[i]
          	li[i] = li[i+1]
          	li[i+1] = buffer
    for(i = 0; i < 8; i++ ):
    	print(list[i])
```


### Простейший поиск подстроки в строке
```
fn Find(haystack, needle):
	lenght = len(haystack) - len(needle)
	i = 0
	for(; i < lenght; i++)
  		for(j=1;j < len(needle); j++)
    		if(haystack[i+j]!=needle[j]) 
      			break
	i++
	return i
  	
 
fn Main():
	haystack = input()
	needle = input()
	findResult = Find(haystack, needle)
	result = "Найдено: " + findResult
	print(result)
```



### Интерпритатор HQ9+
```
fn Interpreter(s):
	count = 0
	for(i = 0;i < len(s);i++):
   		if(s[i] == ```H```):
   			result = "Hello, world!"
        	print(result)
    	elif(i == ```Q```):
        	print(s)
    	elif(i == ```9```):
        	for(j = 99; j > 1; i--):
        		penultimateResult = j - 1
        		result = j + " bottles of beer on the wall.\nTake one down and pass it around, " + penultimateResult + " bottles of beer on the wall."
        		print(result)
        	print("1 bottle of beer on the wall.\nTake one down and pass it around, no more bottles of beer on the wall.")
        	print("No more bottles of beer on the wall.\nGo to the store and buy some more, 99 bottles of beer on the wall.")
    	elif(i == ```+```):
        	count += 1
        	print(count)

fn Main():
	in = ""
	for(;;in != "break"):
		in = input("Enter the program")
```



### brainfuck
*не реализуема из-за отсутствия vector, map*
```
fn Block(code):
    opened = []
    blocks = {}
    for(i = 0;i < len(code);i++):
        if(code[i] == ```[```):
            opened.append(i)
        elif(code[i] == ```]```):
            blocks[i] = opened[-1]
            blocks[opened.pop()] = i
    return blocks

fn Parse(code):
	result = ""
	for(i = 0; i < len(code); i++):
		for(c = 0; c < len(code);c++):
			if(c == "<" || c == ">" || c == "+" || c == "-" || c == "." || c == "," || c == "[" || c == "]"):
				result += " "
				result += c
	return result

fn Run(code):
    code = Parse(code)
    x = 0
    i = 0
    bf = {0: 0}
    blocks = block(code)
    l = len(code)
    for(;i < l;)
        sym = code[i]
        if(sym == ```>```):
            x += 1
            if(!bf.has(x)):
            	x = 0
        elif(sym == ```<```):
            x -= 1
        elif(sym == ```+```):
            bf[x] += 1
        elif(sym == ```-```):
            bf[x] -= 1
        elif(sym == ```.```):
            print(chr(bf[x]))
        elif(sym == ```,```):
            bf[x] = int(input(```Input: ```))
        elif(sym == ```[```):
            if not bf[x]: i = blocks[i]
        elif(sym == ```]```):
            if bf[x]: 
            	i = blocks[i]
        i += 1

fn main():
	code = input("Enter code")
	run(code)
```

Базовая грамматика:
```
#!grammar

//@НАЧАЛО


<программа> ::= <импорт модулей><разделитель><функции><разделитель><функция main>
<функции и структуры> ::= <функция> | <структуры> | <функции и структуры><функции и структуры>

//@служебные нетерминалы
<разделитель> ::= \n
<число> = <цифра> | <цифра><число>
<цифра> = [0-9]
<символы строки> = [a-Zа-Я0-9!"№;%:?*()_+~\"'/\|"]
<буква> ::= [a-Z]
<буквы> ::= <буква><буквы> | <буква>

//@ключевые слова
<break> ::= break


//@Операторные скобки 

<начало> ::= {
<конец> ::= }

//@Импорт модулей
<импорт модулей> ::= <импорт модуля>|<импорт модуля><символы разделения строк><импорт модулей>
<импорт модуля> ::= import "<путь и название файла>"
<путь и название файла> ::= <путь><название файла>

<путь> ::= <относительный путь> | <абсолютный путь>
<относительный путь> ::= ./<относительный путь>/<путь спуска> | ./
<абсолютный путь> ::= <буква>:/<путь спуска>
<путь спуска> ::= <название директории>/<путь спуска> | <название директории>/


//@Идентификатор и значение
<идентификатор> ::= <буква> | <буква><сложный идентификатор>
<сложный идентификатор> ::= <число> | <буквы> | _ | <число><сложный идентификатор> | <буквы><сложный идентификатор> | _<сложный идентификатор>
<значение> ::= <имя переменной> | <тип данных> | <функция с аргументами>


//@Присвоение
<идентификатор присвоения> ::= <list it> | <vector it> | <map it> | <идентификатор>
<list it> ::= <имя переменой>[<число>]
<vector it> ::= <имя переменной>[<число>]
<map it> ::= <имя переменной>[<string>]


//Структуры
<структуры> ::= <структура> | <структуры><структуры>
<структура> ::= struct <имя переменной><начало><поля и методы структуры><конец>
<поля и методы структуры> ::= <поле структуры> | <метод структуры> | <поля и методы структуры><поля и методы структуры>
<поле структуры> ::= <имя переменной> | <имя переменной> = <значение>
<метод структыры> ::= функция

//@функции
<функции> ::= <функция><символы разделения строк><функции> | <функция>

<функция с аргументами> ::= <имя функции>(<аргументы функции>
<функция> ::= fn <функция с аргументами>:<начало><тело функции><конец>
<функция main> ::= fn main():<начало><тело функции><конец>

<имя функции> ::= <идентификатор> | char | len | print | input
<аргументы функции> ::= <аргумент>) | <несколько аргументов>)
<несколько аргументов> ::= <аргумент>, <аргументы функции>
<аргумент> ::= <имя переменной>

<имя переменной> ::= <идентификатор> | <идентификатор>[<число>]
<тип значения> ::= none | | bool | double | container | string
<тело функции> ::= <блок кода>return <значение>
<блок кода> ::= <ветвление> | <циклы> | <операции> | <ветвление><блок кода> | <циклы><разделитель><блок кода> | <операции><разделитель><тело функции>


//@Типы данных
<тип данных> = none | <bool> | <integer> | <double> | <string> | <list> | <vector> | <map>
<bool> ::= true | false
<integer> ::= <число>
<double> ::= <число>.<число>
<string> ::= "<символы строки>"
<list> ::= list():<тип данных>
<vector> ::= vector():<тип данных>
<map> ::= map():<тип данных>


//@Операторы
<бинарный логический оператор> ::= and | or | xor
<унарный логичесикй оператор> ::= not
<унарный арифметический оператор> ::= ++ | -- | -
<бинарный арифметический оператор> ::= + | - | * | / | % | ^ | += | -= | *= | /= | %= | ^=


//@Условие
<ветвление> ::= if(<логическое выражение>):<начало><тело функции><конец> |
				if(<логическое выражение>):<начало><тело функции><конец><условие иначе> |
				if(<логическое выражение>):<начало><тело функции></конец><условие иначе если> | 
				if(<логическое выражение>):<начало><тело функции></конец><условие иначе если><иначе>
<условие иначе> ::= else:<начало><блок кода><конец>
<условие иначе если> ::= elif:<начало><тело функции><конец> | elif:<начало><тело функции><конец><условие иначе если>


//@Логические выражения
<логическое выражение> ::= <простое логическое выражение> | <сложное логическое выражение>
<простое логическое выражение> ::= <значение><бинарный оператор сравнения><значение> | <унарный оператор сравнения><значение>
<сложное логическое выражение> ::= <сложное логическое выражение><бинарный логический оператор><сложное логическое выражение> | <простое логическое выражение>


//@циклы
<блок кода цикла> ::= <ветвление> | <циклы> | <операции> | <ветвление><блок кода> | <циклы><блок кода> | <операции><тело функции> | <break>
<циклы> ::= <цикл for>|<цикл loop>|<цикл for>
<цикл for> ::= for(<объявление переменной или пустота><условие или пустота><операция или пустота>):<начало><блок кода цикла><конец>
<цикл loop> ::= loop:<начало><блок кода цикла><конец>
<цикл while> ::= while(<логическое выражение>):<начало><блок кода цикла><конец>
<объявление переменной или пустота> ::= <бинарная операция присвоение>; | ;
<условие или пустота> ::= <логическое выражение>; | ;
<операция или пустота> ::= <оперкция>; | ;


//@Арифметические операции
<операции> ::= <операция> | <операция><операции>
<операция> ::= <унарная операция> | <присвоение>
<унарная операция> ::= <унарный арифметический оператор><имя переменной>
<присвоение> ::= <идентификатор присвоения> = <бинарная операция> | <идентификатор присвоения> = <унарная операция> | <идентификатор присвоения> = <значение>
<бинарная операция> ::= <значение><вторая часть бинарной операции>
<вторая часть бинарной операции> ::= <бинарный оператор><значение> | <вторая часть бинарной операции><вторая часть бинарной операции>

//Коммментарии
<однострочный комментарий> ::= //<символы строки>
```
