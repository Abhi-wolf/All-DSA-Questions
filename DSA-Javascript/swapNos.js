function swapNos(a, b) {
  console.log("Before swap = ", a, " , ", b);
  b = b - a;
  a = a + b;
  b = a - b;
  console.log("after swap = ", a, " , ", b);
}

(x = 10), (y = 20);
swapNos(x, y);
