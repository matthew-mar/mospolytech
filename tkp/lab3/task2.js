document.write("<h2>Task 2</h2>");

arr2 = [
    [0, -34, 32, 33, 64],
    [32, 1, 32, 23, 84],
    [54, 73, 0, -65, 32],
    [43, 50, 21, 0, 76],
    [12, 51, 19, -54, 0],
]

for (let i = 0; i < arr2.length; i++) {
    for (let j = 0; j < arr2[i].length; j++) {
        if (arr2[i][j] < 0) {
            arr2[i][j] = 0;
        } else {
            arr2[i][j] = 1;
        }
        document.write(arr2[i][j] + "&nbsp");
    }
    document.write("<br>");
}

document.write("<hr>");
