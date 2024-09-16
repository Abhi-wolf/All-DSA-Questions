// PROGRAM TO SORT AN ARRAY USING SELECTION SORT
// In selection sort minimum element is selected from the rest of the array and swapped with the index

function selectionSort(arr) {
  // size of the array
  let n = arr.length;

  for (let i = 0; i < n; i++) {
    // initialize min index as i
    let min = i;
    for (let j = i + 1; j < n; j++) {
      // find minimum element index
      if (arr[min] > arr[j]) min = j;
    }

    // if min is not equal to i then smaller element exist then the element at arr[i]
    if (min != i) {
      let temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}

let arr = [2, 6, 1, 5, 0, 9, 4, 6, 100, -1, -1, -2];
selectionSort(arr);
console.log(arr);
