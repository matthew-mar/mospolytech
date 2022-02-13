const size = 5;


class Queue {

    constructor() {
        this.head = 0;
        this.tail = 0;
        this.queue = Array(size).fill(0);
    }

    isFull() {
        return this.head == (this.tail + 1) % (this.size + 1);
    }

    isEmpty() {
        return this.head == this.tail;
    }

    add(a) {
        if (this.isFull()) {
            alert("queue if full");
        } else {
            this.queue[this.tail] = a;
            this.tail = (this.tail + 1) % (size + 1);
        }
    }

    pop() {
        if (this.isEmpty()) {
            alert("queue is empty");
        } else {
            let out = this.queue[this.head];
            this.head = (this.head + 1) % (size + 1);
            return out;
        }
    }
}


q = new Queue();

while (true) {
    let ins = parseInt(prompt("Вставить - 1\nЗабрать - 0"));
    if (ins) {
        let n = parseInt(prompt("введите число:"));  // принимаем число
        q.add(n);
    } else {
        let a = q.pop();
        if (a) {
            alert(a);
        } else {
            break;
        }
    }
}
