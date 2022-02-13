class Node {
    constructor(data) {
        this.data = data;
        this.nextNode = null;
        this.previousNode = null;
    }
}


class List {
    constructor() {
        this.headNode = null;
        this.tailNode = null;
    }

    search(n) {
        for (let currentNode = this.headNode; currentNode != null; currentNode = currentNode.nextNode) {
            if (currentNode.data == n) {
                alert("found");
                return currentNode;
            }
        }
        alert("not found");
        return null;
    }

    append(d) {
        let newNode = new Node(d);

        if (this.headNode == null) {
            this.headNode = newNode;
            return;
        }

        if (this.tailNode == null) {
            this.tailNode = newNode;
            this.tailNode.previousNode = this.headNode;
            this.headNode.nextNode = this.tailNode;
            return;
        }

        this.tailNode.nextNode = newNode;
        newNode.previousNode = this.tailNode;
        this.tailNode = newNode;
    }

    insert(d) {
        let newNode = new Node(d);

        if (this.headNode == null) {
            this.headNode = newNode;
            this.tailNode = newNode;
            return;
        }

        newNode.nextNode = this.headNode;
        this.headNode.previousNode = newNode;
        this.headNode = newNode;
    }

    deleteLast() {
        this.tailNode = this.tailNode.previousNode;
        this.tailNode.nextNode = null;
    }

    deleteFirst() {
        if (this.tailNode == null) {
            this.headNode = null;
            return;
        }
        this.headNode = this.headNode.nextNode;
        this.headNode.previousNode = null;
    }

    searchAdd(searchData, newData) {
        let foundNode = this.search(searchData);

        if (foundNode == this.tailNode) {
            this.append(newData);
            return;
        }

        if (foundNode != null) {
            let newNode = new Node(newData);
            let foundNextNode = foundNode.nextNode;

            newNode.nextNode = foundNextNode;
            foundNextNode.previousNode = newNode;

            foundNode.nextNode = newNode;
            newNode.previousNode = foundNode;
        }
    }

    searchDelete(searchData) {
        let foundNode = this.search(searchData);

        if (foundNode == null) {
            return;
        }
        if (foundNode == this.headNode) {
            this.deleteFirst();
            return;
        }
        if (foundNode == this.tailNode) {
            this.deleteLast();
            return;
        }

        let currentNode = this.headNode;
        while (currentNode.nextNode != foundNode) {
            currentNode = currentNode.nextNode;
        }

        let foundNextNode = foundNode.nextNode;
        currentNode.nextNode = foundNextNode;
        foundNextNode.previousNode = currentNode;
        foundNode = null;
    }

    display() {
        let output = ""
        for (let currentNode = this.headNode; currentNode != null; currentNode = currentNode.nextNode) {
            output += currentNode.data + " ";
        }
        alert(output);
    }
}


let myList = new List();

let menu = (
    "Choose function:\n" +
    "1: append\n" +
    "2: insert to start\n" +
    "3: search\n" +
    "4: add after search\n" +
    "5: delete search node\n" +
    "6: display list\n"
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
            let s = parseInt(prompt("enter number to search:"));
            myList.search(s);
            break;
        }
        case 4: {
            let s = parseInt(prompt("enter number to search:"));
            let d = parseInt(prompt("enter number to add: "));
            myList.searchAdd(s, d);
            break;
        }
        case 5: {
            let s = parseInt(prompt("enter number to search:"));
            myList.searchDelete(s);
            break;
        }
        case 6: {
            myList.display();
            break;
        }
    }
}
