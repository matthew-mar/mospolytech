function addiction(a, b) { // функция сложения
    return a + b;
}


function subtraction(a, b) { // функция вычитания
    return a - b;
}


function multiplication(a, b) { // функция умножения
    return a * b;
}


function division(a, b) { // функция деления
    if (b == 0) {
        return "попытка деления на 0";
    }
    return a / b;
}

let a = parseInt(prompt("enter a:"));  // получение первого числа
let b = parseInt(prompt("enter b:"));  // получение второго числа

let function_choose_text = (  // текс меню
    "enter function number:\n" +
    "addiction - 1\n" +
    "subtraction - 2\n" +
    "multiplication -3\n" +
    "division - 4\n"
);
let f = parseInt(prompt(function_choose_text));  // получение номера функции

switch (f) {
    case 1: {
        document.write(addiction(a, b) + "<br>");
        break;
    }
    case 2: {
        document.write(subtraction(a, b) + "<br>");
        break;
    }
    case 3: {
        document.write(multiplication(a, b) + "<br>");
        break;
    }
    case 4: {
        document.write(division(a, b) + "<br>");
        break;
    }
}
