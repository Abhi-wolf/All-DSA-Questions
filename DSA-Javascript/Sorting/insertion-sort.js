// PROGRAM TO SORT AN ARRAY USING BUBBLE SORT
// In insertion sort an element is placed in its right place in the sorted array

function insertionSort(arr) {
  // size of the array
  let n = arr.length;

  for (let i = 1; i < n; i++) {
    // temporarily store the value of the arr[i] in temp
    let temp = arr[i];
    let j = i;

    // shift the larger elements greater than temp
    while (arr[j - 1] > temp && j >= 1) {
      arr[j] = arr[j - 1];
      j -= 1;
    }

    // store the element in its right place in the sorted array
    arr[j] = temp;
    console.log(arr);
  }
}

let arr = [2, 6, 1, 5, 0, 9, 4, 6, 100, -1, -1, -2];
insertionSort(arr);
console.log(arr);
