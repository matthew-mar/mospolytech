let arr = Array(3, 5, -3, 6, 143, 7, 12, -87, 54, 32, -78, 5, 43);

// 1. Поиск наибольшего значения массива
let max = -Infinity;
for (let i = 0; i < arr.length; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
document.write(`Найболшее значение массива = ${max}<br>`);

// 2. Поиск найменьшего значения массива
let min = Infinity;
for (let i = 0; i < arr.length; i++) {
    if (arr[i] < min) {
        min = arr[i];
    }
}
document.write(`Найменьшее значение массива = ${min}<br>`);

// 3. Определение суммы всех элеменов масива
let sum = 0;
for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
}
document.write(`Сумма всех элементов массива = ${sum}<br>`);

// 4. Определение среднего арифметического
let sr = sum / arr.length;
document.write(`Среднее арифметическое массива = ${sr}<br>`);

// 5. Определение всех не четных значений
for (let i = 0; i < arr.length; i++) {
    if (arr[i] % 2 == 1) {
        document.write(`Элемент по индексу ${i} со значением ${arr[i]} не четный<br>`);
    }
}