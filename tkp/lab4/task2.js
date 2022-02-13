function numberSign(n) {
    if (n < 0) {
        return `${n} - отрицательное число`;
    }
    return `${n} - положительное число`;
}


function multiplicity(n) {
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 9 == 0) {
        return "Число делится на 2 или 5 или 3 или 6 или 9 без остатка";
    }
}


function isSimple(n) {
    for (let i = 2; i < n; i++) {
        if (n % i == 0) {  // если число n делится на какое-то число до себя
            return `число ${n} не простое`;  // число n не является простым
        }
    }
    return `число ${n} простое`;
}


let n = parseInt(prompt("Enter number:"));

let menu = (
    "Choose function:\n" +
    "number sign - 1\n" +
    "multiplicity - 2\n" +
    "simple number - 3\n"
);
let f = parseInt(prompt(menu));

switch (f) {
    case 1: {
        document.write(numberSign(n));
        break;
    }
    case 2: {
        document.write(multiplicity(n));
        break;
    }
    case 3: {
        document.write(isSimple(n));
        break;
    }
}
