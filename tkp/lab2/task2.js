// чтобы найти все возможные маршруты обхода магазинов нужно найти
// факториал от количества магазинов

let a2 = 10;
let p = 1;  // факториал
for (let i = 1; i < a2; i++) {
    p *= i;
}
document.write("<h2>Task 2</h2>");
document.write(p);
document.write("<hr>");
