let a1 = 8;  // начало диапазона
let b1 = 15;  // конец диапазона

let sum = 0;
for (let i = a1; i < b1+1; i++) {  // цикл от а до b включительно
    sum += i;  // суммируем числа
}

document.write("<h2>Task 1</h2>");

document.write(sum + "<br>");  // вывод суммы

document.write("четные числа:<br>");
for (let i = a1; i < b1; i++) {  // цикл от а до b не включительно
    if (i % 2 == 0) {  // если остаток от деления на 2 равен 0
        document.write(i + "<br>");  // выводим число
    }
}

document.write("<hr>");
