function fibonacci(n) {
  if (n <= 1) return n;
  else return fibonacci(n - 1) + fibonacci(n - 2);
}

function fibonacci2(n) {
  var arr = [0, 1];
  if (n <= 2) return 1;

  for (var i = 2; i <= n; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  return arr[n];
}

console.log(fibonacci(12));
console.log(fibonacci(5));
console.log(fibonacci(1));

console.log(fibonacci2(12));
console.log(fibonacci2(5));
console.log(fibonacci2(1));
