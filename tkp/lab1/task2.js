let x = 6;
let y = 15;
let z = 4;

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
