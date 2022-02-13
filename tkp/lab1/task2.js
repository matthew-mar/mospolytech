let x = 6;
let y = 15;
let z = 4;

document.write("<h2>Task 2</h2>");

res = x += y - x++ * z;
document.write(res + "<br>");

res = z = --x - y * 5;
document.write(res + "<br>");

res = y /= x + 5 % z ;
document.write(res + "<br>");

res = z = x++ + y * 5 ;
document.write(res + "<br>");

res = x = y - x++ * z ;
document.write(res + "<br>");

document.write("<hr>");
