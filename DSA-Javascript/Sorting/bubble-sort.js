// PROGRAM TO SORT AN ARRAY USING BUBBLE SORT

function bubbleSort(arr) {
  // size of the array
  let n = arr.length;

  // mark swapped as true
  let swapped = true;

  // start loop from back
  for (let i = n - 1; i >= 0 && swapped; i--) {
    // mark swpped as false so that we loop terminates when there is no swapping done in an iteration
    swapped = false;
    for (let j = 0; j < i; j++) {
      // if larger swap
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
  }
}

let arr = [2, 6, 1, 5, 0, 9, 4, 6, 100, -1, -1000];
bubbleSort(arr);
console.log(arr);
