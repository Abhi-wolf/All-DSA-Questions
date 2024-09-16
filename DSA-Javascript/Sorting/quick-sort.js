function quickSort(arr, low, high) {
  if (high > low) {
    let pivot = partition(arr, low, high);
    // console.log("pivot = ", pivot);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

function partition(arr, low, high) {
  // make the element at low index as pivot element
  let pivotEle = arr[low];
  let left = low,
    right = high;

  while (left < right) {
    // move right while items are smaller than pivot element
    while (arr[left] <= pivotEle) left++;

    // move left while items are greater than pivot element
    while (arr[right] > pivotEle) right--;

    // swap elements that are causing trouble (0 and 4)
    // [2, 1, 4, 3, 0, 8, 9]  --> [2, 1, 0, 3, 4, 8, 9]
    if (left < right) {
      let temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
  }

  // place pivot in its right place in the array
  arr[low] = arr[right];
  arr[right] = pivotEle;
  // console.log("pivot = ", pivotEle, " ==> ", arr);
  // return index
  return right;
}

// let arr = [2, 6, 1, 5, 0, 9, -1, -1, -2, 100, -400];
let arr = [2, 1, 4, 3, 0, 8, 9];

quickSort(arr, 0, arr.length - 1);
console.log(arr);
