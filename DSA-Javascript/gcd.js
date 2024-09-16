function gcd(a, b) {
  if (b == 0) return a;
  if (a == 0) return b;

  if (a > b) return gcd(b, a % b);
  else return gcd(b % a, a);
}

console.log(gcd(14, 28));
console.log(gcd(69, 169));
