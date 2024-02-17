# **IDAPro**
***IDAPro*** — это целая программа для реверсинга, которая может быть использована в 32/64 системах как и отладчик, так и дизассемблер.

### **Команды**
1. В любой из вкладок IDA, где есть такие списки, как FUNCTIONS, STRINGS, NAMES можно с помощью CTRL+F открыть поисковую систему, которая фильтрует информацию
2. Через VIEW-OPEN SUBVIEW-DISASSEMBLY можно открыть второе дизасм окно, показывающее и выполняющее другие функции.
3. В OPEN SUBVIEW-IMPORTS IDA покажет импортируемые функции.
4. VIEW - CALCULATOR, он позволяет увидеть преобразованное число во всех системах счисления сразу, и, кроме того, показывает его соответствие символу, если оно есть, в случае c 0x45 – это E.

В **ЗАГРУЗЧИКЕ** программа абсолютно не выполняется, но она анализируется, и создаётся база данных с информацией этого файла, и это значительное отличие относительно **ОТЛАДЧИКА**. В ЗАГРУЗЧИКЕ нет ни окна РЕГИСТРОВ, ни окна СТЕКА, ни списка модулей, которые загружены в память. Это вещи, существуют при выполнении и отладке программы.

5. слово OFFSET, указывает нам, что мы должны использовать адрес, но не его содержание. Если нажмём **Q** , то OFFSET пропадает. Без OFFSET будут []. Когда IDA использует слово OFFSET перед адресом памяти она ссылается на это же числовое значение, а не на его содержимое. 
6. Если нажать на адрес и с помощью нажатия на **X** на ссылки, мы видим все ссылки.
7. Находясь в секции импортируемых функий в OPTIONS->DEMANGLE NAMES и выбрать NAMES и имена могут стать лучше. Префикс **EXTRN** подразумевает, что это ВНЕШНЯЯ импортированная функция.
8. Для изменения инструкции поместить курсор на строку адреса и перейти в меню EDIT->PATCH PROGRAM->ASSEMBLE. Если есть не распознанные части, но с кодом всё ОК, мы щелкаем правой кнопкой мыши, где было начало функции, и выбираем там пункт CREATE FUNCTION. И это меняет префикс loc_, который означает "локальная метка" на префикс sub_, который означает, "начало подпрограммы или функции".

Поскольку команда ASSEMBLE не работает полноценно для всех инструкций, мы должны изменить байты в меню где написано PATCH BYTES, но лучше загрузить плагин, такой как Keystone, который позволяет нам записать все инструкции намного проще.

9. Для обработки данных предоставляется две основные операции: положить или **PUSH**, которая помещает объект в стек и обратная операция, чтобы забрать последнее значение или **POP**. Обычно, в 32-битных приложениях, PUSH используется, чтобы передать аргументы функции в стек, прежде, чем вызвать функцию с помощью **CALL**.
10. Если мы дважды щёлкнем на строковую переменную, то в исходнике на C увидим массив символов.
11. Если мы нажмём кнопку **D**, то мы можем заставить IDA прекратить обнаруживать эту строку как символьный массив, и оставить её как DB (байты).
12. Если мы нажмём кнопку **A** и последовательности станет снова как и раньше строкой ASCII символов.
13. Если мы нажмём кнопку **X**, чтобы искать ссылки, то я буду видеть где используются эти строки.
14. Обычно, когда аргументы передаются к функциям, мы всегда будем видеть PUSH offset xxxxx, потому что ищется адрес строки, чтобы передать его функции, API всегда передаётся указатель на начало или адрес где начинается строка.
15. Префикс DS:TAG указывает, что сохранение в адрес памяти секции данных (DS=DATA), инструкция сохраняет адрес начала строки в секции DATA.
16. Клавиша **N** переименовывает переменную.
17. Инструкция LEA помещает указанный адрес из B в A. Она никогда не получает доступ к содержимому B, это всегда будет адрес или результат работы операции между квадратными скобками во втором операнде. Инструкция используется, чтобы получить адреса переменных в памяти или параметров.
18. Инструкция **ADD A, B** складывает значение B и A, и помещает результат в A. A может быть регистром или содержимым ячейки памяти, B может быть регистром, константой или содержимым ячейки памяти (A и B не должны быть в памяти в одно и то же время, в одной и той же инструкции).
19. Инструкция **SUB A, B** действует так же как и ADD за исключением того, что вместо операции сложения в данном случае вычитается целое число и сохранит результат в A, возможные комбинации те же самые.
20. Инструкции **INC A и DEC A** увеличивает или уменьшает регистр, или содержимое ячейки памяти на 1, на самом деле это частный случай сложения и вычитания.
21. **IMUL** инструкция умножения со знаком и существует две её формы. **IMUL A, B** выполняет целочисленное умножение A на B, и результат сохраняется в A, а **IMUL A, B, C** выполняет умножение B на C, и результат сохраняется в A. В обоих случаях A может быть только регистром, B может быть регистром или содержимым ячейки памяти и C может быть только константой.
22. **IDIV A** определяет только ДЕЛИТЕЛЬ операции, делимое же как и частное не определяются, потому что они всегда используют одинаковые регистры. Эта операция создаёт большое 64-битное число, старшая часть которого находится в EDX, а младшая часть в EAX. Инструкция делит значение на A и сохраняет результат в EAX, а остаток значение в EDX.
23. Инструкция **AND A, B**  выполняет логическую операцию И между двумя значениями и будет сохранять результат в A, то же самое происходит с инструкциями **OR или XOR**, каждая инструкция имеет свою таблицу истинности, которая применяется к каждому члену и результат будет сохранён в A. A и B могут быть регистрами или содержимым ячеек памяти, но запрещено, чтобы оба были содержимым ячейки памяти в одной и той же инструкции.
24. Самые используемые случаи - это применение **XOR** к одному и тому же регистру, чтобы легко и быстро изменить его в ноль.
25. Записывая значения в PYTHON строке и используя символ **^**, который является операцией XOR в PYTHON, **&** - AND, **|** - OR, мы увидем результат операции.
26. Инструкция **NOT A**  инвертирует все биты A и сохраняется затем в A.
27. Инструкция **NEG A** превращает A в -A.
28. Эти инструкции **SHL и SHR** сдвигают байты влево(SHL) и вправо (SHR), байты которые исчезают с одной стороны, заменяются нулями с другой стороны.
29. Инструкции **ROL и ROR**, вращают определенное количество бит, но в этом случае те биты, которые исчезают с одной стороны, возвращаются с другой стороны с теми же значениями.
30. **EIP** указывает на следующую инструкцию, которая будет выполнена, и когда это произойдёт, EIP будет указывать снова на следующую инструкцию.
31. **JMP A** - A будет адресом памяти, куда мы хотим, чтобы программа совершила безусловный переход. Размер 5 байт.
32. **JMP SHORT** - это короткий переход, который состоит их двух байт и он имеет возможность переходить вперед и назад, направление задаётся значением второго байта, первый байт это ОПКОД перехода, мы не можем переходить очень далеко. Размер 2 байта.
33. **Всегда, если мы имеем сомнения, что мы делаем что-то, что можем испортить любую функцию и мы не знаем как её восстановить, рекомендуется делать снимок. - take database snapshot. В VIEW->DATABASE SNAPSHOT MANAGER**
34. **loc_** говорит нам, что эта инструкция является локальной(любой, основной) инструкцией.
35. **sub_** - функция.
36. **CMP A, B** - сравнение, после которого идет переход. JZ.
37. **CALL** - используется для вызова функции. Сохраняет на ВЕРШИНЕ стэка значение, куда будет возвращаться выполнение или адрес возврата (следующий адрес после CALL).
38. **RET** - используется для возврата из функции к инструкции слeдующей за тем, где был вызов CALL, беря адрес из стека.

В VIEW->OPEN SUBVIEW->SEGMENTS мы увидим сегменты. Начало и конец сегмента. Права на R - чтение, W - запись, X - выполнение. D - вызов сегмента в ОТЛАДЧИКе, L - вызов сегмента в ЗАГРУЗЧИКе.

## **Алгоритм**

При загрузке файла выбираем PE, ставим калочку в **MANUEL LOAD** и нажимаю OK. Перед модификациями сохранять СНИМОК с помощью пункта меню **FILE->TAKE DATABASE SNAPSHOT**. Чтобы вернутся к предыдущему снимку **VIEW->DATABASE SNAPSHOT MANAGER** и нажимаем RESTORE. 

Строки играют ключевую роль, чтобы привести нас в важные области, давайте посмотрим в меню **VIEW->OPEN SUBVIEW→STRING**. По двойному ЛКМ в строке можно перейти. Переходим в DATA. Нажмём **X** и видим ссылки где строка используется (Фунция + смещение строки в функции). Переходим в одну из функций. 

После перехода в функцию ее следует переименовать для простоты исследования. Нажимаем на фукнцию ЛКМ, затем кнопку **N** и пишем новое имя. Когда встречаем **CALL**, то для входа в вызываемую функцию можно нажать **ENTER**. 

Для удобной работы с другими частями программы, чтобы можно было легко возвращаться назад добавим JUMP метки. Находимся в JZ и идём в **JUMP->MARK POSITION** и вводим имя, которое вело бы нас к функции. В меню **JUMP->JUMP TO MARKED POSITION** появляется список со всеми нашими отметками, которые мы сделали раньше и мы можем перейти к любой из них, которая нам нужна, если мы теряемся в программе.

Исправления делаются с помощью **KEYPATCH**. Сохранять изменения с помощью **EDIT -> Patch Program -> APPLY PATCH TO INPUT FILE**. Можно просто заделать командами NOP. Заполнять наш код с помощью байта 0x90 (**NOP**) до следующей инструкции (установить галочку - **NOPs padding until next instruction boundary**). 