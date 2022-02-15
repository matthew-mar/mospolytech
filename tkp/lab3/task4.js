document.write("<h2>Task 3</h2>");

const size = 5;
queue = Array(size1).fill(0)  // массив для хранения элементов очереди
let head = 0;  // голова
let tail = 0;  // хвост

while (true) {
    let ins = parseInt(prompt("Вставить - 1\nЗабрать - 0"));
    if (ins) {
        if (head == (tail + 1) % (size1 + 1)) {  // проверка очереди на заполненность
            alert("очередь заполнена");
        } else {
            let n = parseInt(prompt("введите число:"));  // принимаем число
            queue[tail] = n;  // кладем число в очередь
            tail = (tail + 1) % (size1 + 1);  // передвижение хвоста к следующему элементу
        }
    } else {
        if (head == tail) {  // проверка на пустую очередь
            alert("очередь пустая");
            break;
        } else {
            alert(queue[head]);  // вывод первого элемента очереди
            head = (head + 1) % (size1 + 1);  // передвижение головы к следующему элементу
        }
    }
}

document.write("<hr>");
