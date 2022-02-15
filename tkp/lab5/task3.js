class Node {
    constructor(data) {
        this.data = data;  // значение узла
        this.nextNode = null;  // следущий узел
        this.previousNode = null;  // предыдущий узел
    }
}


class List {
    constructor() {
        this.headNode = null;  // первый элемент списка
        this.tailNode = null;  // последний элемент списка
    }

    search(n) {  // метод поиска
        // начиная с головы двигаться по следующим узлам пока не дойдем до null
        for (let currentNode = this.headNode; currentNode != null; currentNode = currentNode.nextNode) {
            if (currentNode.data == n) {  // если значение текущего узла равно переданному значению
                alert("found");  // выводим сообщение
                return currentNode;  // возвращаем из метод текущий узел
            }
        }
        alert("not found");  // если вышли из цикла, значит значения в списке нет
        return null;
    }

    append(d) {  // добавление в конец
        let newNode = new Node(d);  // создаем новый узел

        if (this.headNode == null) {  // если первый узел списка пустой
            this.headNode = newNode;  // делаем новый узел головным узлом
            return;
        }

        if (this.tailNode == null) {  // если последний узел списка пустой
            this.tailNode = newNode;  // делаем новый узел хвостовым узлом
            this.tailNode.previousNode = this.headNode;  // предыдущий узел - головной узел
            this.headNode.nextNode = this.tailNode;  // у головного узла следующий узел - хвостовой узел
            return;
        }

        this.tailNode.nextNode = newNode;  // следующий узел для хвостого узла - новый узел
        newNode.previousNode = this.tailNode;  // предыдущий узел нового узла - хвостовой узел
        this.tailNode = newNode;  // новый узел становится хвостом
    }

    insert(d) {  // добавление в начало
        let newNode = new Node(d);  // создание нового узла

        if (this.headNode == null) {  // если головной узел пуст
            this.headNode = newNode;  // новый узел становится головным узлом
            // this.tailNode = newNode;
            return;
        }

        newNode.nextNode = this.headNode;  // следующий узел нового узла - головной узел
        this.headNode.previousNode = newNode;  // предыдущий узел головного узла - новый узел
        this.headNode = newNode;  // новый ухел становится головным узлом
    }

    deleteLast() {  // удаление с конца
        if (this.tailNode == null) {
            this.deleteFirst();
            return;
        }
        this.tailNode = this.tailNode.previousNode;  // хвостовой узел становится предыдущим от хвоста узлом
        if (this.tailNode != null) {
            this.tailNode.nextNode = null;  // обнуляем ссылку на следующий элемент для хвостового узла
        }
    }

    deleteFirst() {  // удаление с начала
        if (this.tailNode == null) {  // если хвостовой узел пуст
            this.headNode = null;  // обнуляем головной узел
            return;
        }
        this.headNode = this.headNode.nextNode;  // головным узлом становится следующий от головного узла узел
        if (this.headNode != null) {
            this.headNode.previousNode = null;  // обнуление ссылки на предыдущий элемент для головного узла
        }
    }

    searchAdd(searchData, newData) {  // добавление после найденного элемента
        let foundNode = this.search(searchData);  // ищем узел

        if (foundNode == this.tailNode  || foundNode == this.headNode) {  // если найденный узел является хвостом или головой
            this.append(newData);  // вызываем метод добавления в конец
            return;
        }

        if (foundNode != null) {  // если найденный узел существует
            let newNode = new Node(newData);  // создаем новый узел
            let foundNextNode = foundNode.nextNode;  // находим следующий узел после найденного

            newNode.nextNode = foundNextNode;  // следующий узел для нового узла - следующий узел после найденного
            foundNextNode.previousNode = newNode;  // предыдущий узел для следующего после найденного узла - новый узел

            foundNode.nextNode = newNode;  // следующий узел для найденного узла - новый узел
            newNode.previousNode = foundNode;  // предыдущий узел для новго узла - найденный узел
        }
    }

    searchDelete(searchData) {  // удаление найденного узла
        let foundNode = this.search(searchData);  // поиск узла

        if (foundNode == null) {  // если узел не найден
            return;  // выходим из метода
        }
        if (foundNode == this.headNode) {  // если найденный узел является головным узлом
            this.deleteFirst();  // вызываем метод удаления первого элемента
            return;
        }
        if (foundNode == this.tailNode) {  // если найденный узел является хвостовым узлом
            this.deleteLast();  // вызываем метод удаления последнего элемента
            return;
        }

        let currentNode = this.headNode;  // текущий узел равен головному узлу
        while (currentNode.nextNode != foundNode) {  // пока текущий узел не станет равен найденнуму узлу
            currentNode = currentNode.nextNode;  // текущий узел равен своему следующему узлу
        }

        let foundNextNode = foundNode.nextNode;  // следующий узел от найденного узла
        currentNode.nextNode = foundNextNode;  // следующий узел для текущего узла - следующий узел от найденного узла
        foundNextNode.previousNode = currentNode;  // предыдущий узел для следующего от найденного узла - текущий узел
        foundNode = null;  // обнуляем найденный узел
    }

    display() {  // вывод списка на экран
        let output = "";  // строка вывод
        for (let currentNode = this.headNode; currentNode != null; currentNode = currentNode.nextNode) {
            output += currentNode.data + " ";  // прибавление к строке вывода данных узла
        }
        alert(output);
    }
}


let myList = new List();

let menu = (
    "Choose function:\n" +
    "1: append\n" +
    "2: insert to start\n" +
    "3: delete last\n" +
    "4: delete first\n" + 
    "5: search\n" +
    "6: add after search\n" +
    "7: delete search node\n" +
    "8: display list\n"
);

while (true) {
    let ans = parseInt(prompt(menu));
    switch (ans) {
        case 1: {
            let d = parseInt(prompt("enter number: "));
            myList.append(d);
            break;
        }
        case 2: {
            let d = parseInt(prompt("enter number: "));
            myList.insert(d);
            break;
        }
        case 3: {
            myList.deleteLast();
            break;
        }
        case 4: {
            myList.deleteFirst();
            break;
        }
        case 5: {
            let s = parseInt(prompt("enter number to search:"));
            myList.search(s);
            break;
        }
        case 6: {
            let s = parseInt(prompt("enter number to search:"));
            let d = parseInt(prompt("enter number to add: "));
            myList.searchAdd(s, d);
            break;
        }
        case 7: {
            let s = parseInt(prompt("enter number to search:"));
            myList.searchDelete(s);
            break;
        }
        case 8: {
            myList.display();
            break;
        }
    }
}
