const size = 5;
let stack = Array(size).fill(0);
let tp = -1;


function push(n) {
    if (tp != size - 1) {
        stack[++tp] = n;
    } else {
        alert("stack is filled");
    }
} 


function pop() {
    if (tp > -1) {
        alert(stack[tp--]);
        return true;
    }
    alert("stack is empty");
    return false;
}


let stop = true;
while (stop) {
    let ins = parseInt(prompt("Вставить - 1\nЗабрать - 0"));
    if (ins) {
        let n = parseInt(prompt("Введите число: "));
        push(n);
    } else {
        stop = pop();
    }
}
