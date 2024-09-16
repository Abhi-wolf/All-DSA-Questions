function mergeSortedArray(arr1, arr2) {
  var mergeArray = [],
    i = 0,
    j = 0;

  var n1 = arr1.length;
  var n2 = arr2.length;

  if (n1 == 0) return arr2;
  if (n2 == 0) return arr1;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      mergeArray.push(arr1[i]);
      i++;
    } else {
      mergeArray.push(arr2[j]);
      j++;
    }
  }

  while (i < n1) {
    mergeArray.push(arr1[i]);
    i++;
  }

  while (j < n2) {
    mergeArray.push(arr2[j]);
    j++;
  }

  return mergeArray;
}

console.log(
  mergeSortedArray([2, 5, 6, 9, 10, 15, 17], [1, 2, 3, 8, 29, 30, 45])
);
