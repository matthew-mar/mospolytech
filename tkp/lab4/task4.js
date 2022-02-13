const size = 5;
queue = Array(size).fill(0)  // массив для хранения элементов очереди
let head = 0;  // голова
let tail = 0;  // хвост


function add(n) {
    if (head == (tail + 1) % (size + 1)) {
        alert("очередь заполнена");
    } else {
        queue[tail] = n;  // кладем число в очередь
        tail = (tail + 1) % (size + 1);  // передвижение хвоста к следующему элементу
    }
}


function pop() {
    if (head != tail) {
        let n = queue[head];
        head = (head + 1) % (size + 1);  // передвижение головы к следующему элементу
        return n;
    }
}


while (true) {
    let ins = parseInt(prompt("Вставить - 1\nЗабрать - 0"));
    if (ins) {
        let n = parseInt(prompt("введите число:"));  // принимаем число
        add(n);
    } else {
        let a = pop();
        if (a) {
            alert(a);
        } else {
            break;
        }
    }
}
