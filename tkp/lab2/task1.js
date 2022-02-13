let a1 = 8;
let b1 = 15;

let sum = 0;
for (let i = a1; i < b1+1; i++) {
    sum += i;
}

document.write("<h2>Task 1</h2>");

document.write(sum + "<br>");

document.write("четные числа:<br>");
for (let i = a1; i < b1; i++) {
    if (i % 2 == 0) {
        document.write(i + "<br>");
    }
}

document.write("<hr>");
