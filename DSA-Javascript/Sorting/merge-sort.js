// PROGRAM TO SORT AN ARRAY USING MERGE SORT

function mergeSort(arr, left, right) {
  if (left < right) {
    let mid = left + Math.floor((right - left) / 2);

    // divide array in to part until only single elements left
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // merge the array bottom up in sorted manner
    merge(arr, left, mid + 1, right);
  }
}

function merge(arr, left, mid, right) {
  // array to store the sorted array after merging
  let temp = [];
  let i = left,
    j = mid,
    ind = left;

  // merge the array in sorted order
  while (i < mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp.push(arr[i]);
      i += 1;
    } else {
      temp.push(arr[j]);
      j += 1;
    }
  }

  while (i < mid) {
    temp.push(arr[i]);
    i += 1;
  }

  while (j <= right) {
    temp.push(arr[j]);
    j += 1;
  }

  // modifie the original array
  for (let k = 0; k < temp.length; k++) {
    arr[ind++] = temp[k];
  }
}

let arr = [2, 6, 1, 5, 0, 9, -1, -1, -2, 100, -400];
mergeSort(arr, 0, arr.length - 1);
console.log(arr);
