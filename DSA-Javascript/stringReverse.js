function ReverseStr1(str) {
  let tempStr = "";

  for (var i = str.length - 1; i >= 0; i--) {
    tempStr += str[i];
  }

  return tempStr;
}

function ReverseStr2(str) {
  str = str.split("");
  let len = str.length;
  let half = Math.floor(len / 2) - 1;
  let revStr;

  for (let i = 0; i <= half; i++) {
    revStr = str[len - i - 1];
    str[len - i - 1] = str[i];
    str[i] = revStr;
  }

  return str.join("");
}

function ReverseStr3(str) {
  if (!str || str.length < 2) return str;

  return str.split("").reverse().join("");
}

console.log(ReverseStr1("abcdef"));
console.log(ReverseStr2("geeks"));




