function removeDuplicate(arr) {
  var exists = {},
    res = [],
    elm;

  for (var i = 0; i < arr.length; i++) {
    elm = arr[i];

    if (!exists[elm]) {
      res.push(elm);
      exists[elm] = true;
    }
  }

  return res;
}

// for string
function removeDuplicateString(str) {
  var exists = {},
    resString = "",
    elm;

  for (var i = 0; i < str.length; i++) {
    elm = str[i];

    if (!exists[elm]) {
      resString += elm;
      exists[elm] = true;
    }
  }

  return resString;
}

console.log(removeDuplicate([1, 3, 3, 3, 1, 5, 6, 7, 8, 1]));

console.log(removeDuplicateString("geekforgeeks"));
