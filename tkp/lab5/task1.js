// Создать программную модель стека, используя объектно-ориентированный подход
const size = 5;


class Stack {

    constructor() {
        this.stack = Array(size).fill(0);
        this.top = -1;
    }

    isEmpty() {  // контроль на отсутствие элементов
        return this.top == -1;
    }

    isFull() {  // контроль на переполнение
        return this.top == size - 1;
    }

    push(a) {  // добавление элемента
        if (this.isFull()) {
            alert("stack is filled");
        } else {
            this.stack[++this.top] = a;
        }
    }

    pop() {  // удаление элемента
        if (this.isEmpty()) {
            alert("stack is empty");
        } else {
            return this.stack[this.top--];
        }
    }
}


s = new Stack();

while (true) {
    let ins = parseInt(prompt("Вставить - 1\nЗабрать - 0"));
    if (ins) {
        let n = parseInt(prompt("Введите число: "));  // принимаем число
        s.push(n);
    } else {
        let a = s.pop();
        if (a) {
            alert(a);
        } else {
            break;
        }
        
    }
}
