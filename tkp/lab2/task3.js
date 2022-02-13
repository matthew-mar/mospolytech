document.write("<h2>Task 3</h2>");

let length = 10; // длина прямоугольника
let width = 5; // ширина прямоугольника

let rectangle = "";
for (let i = 0; i < width; i++) {
    if (i == 0 || i == width - 1) {  // первая последняя строчка
        for (let j = 0; j < length; j++) {
            rectangle += "*";  // вся строчка заполняется звездами
        }
        rectangle += "<br>";
    } else {  // другие строчки
        // внутри строчки пробелы, по бокам звезды
        rectangle += "*";
        for (let k = 0; k < length-2; k++) {
            rectangle += " ";
        }
        rectangle += "*<br>";
    }
}
document.write("<pre>" + rectangle);  // вывод прямоугольника

let triangleRect = "";  // прямоугольный треугольник
for (let i = 0; i < 7; i++) {
    // на каждой строчке звезд становится на 1 больше
    triangleRect += "*".repeat(i) + "<br>";
}
document.write("<pre>" + triangleRect);  // вывод

let triangle = "";  // треугольник
let a = 4;
let c = 7;
let b = 1;
for (let i = 0; i < a; i++) {
    for (let j = 0; j <= (c / 2) - 1; j++) {
        triangle += " ";
    }
    for (let j = 0; j < b; j++) {
        triangle += "*";
    }
    c -= 2;
    b += 2;
    triangle += "<br>";
}
document.write("<pre>" + triangle);

// добавление к треугольнику отображенный вниз треугольник
a = 4;
c = 7;
for (let i = 0; i < a; i++) {
    for (let j = 0; j < c; j++) {
        triangle += "*";
    }
    c -= 2;
    triangle += "<br>";
    for (let j = 0; j <= i; j++) {
        triangle += " ";
    }
}
document.write("<pre>" + triangle);

document.write("<hr>");