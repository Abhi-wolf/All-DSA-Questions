function heapify(arr, n, i) {
  let largest = i;

  // left child
  let left = 2 * i + 1;

  // right child
  let right = 2 * i + 2;

  // if left child is larger than root
  if (left < n && arr[left] > arr[largest]) largest = left;

  // if right child is larger than largest
  if (right < n && arr[right] > arr[largest]) largest = right;

  // if larger is not root
  if (largest != i) {
    let temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;

    // heapify the affected sub tree
    heapify(arr, n, largest);
  }
}

function heapSort(arr) {
  let n = arr.length;

  // build heap (rearrange array)
  for (let i = Math.floor(n / 2) - 1; i >= 0; i--) heapify(arr, n, i);

  // one by one extract an element from heap
  for (let i = n - 1; i > 0; i--) {
    // move current root to end
    let temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

// let arr = [2, 6, 1, 5, 0, 9, -1, -1, -2, 100, -400];
let arr = [5, 2, 3, 1];

heapSort(arr, 0, arr.length);
console.log(arr);
