class Node {
  constructor(val) {
    this.data = val;
    this.left = null;
    this.right = null;
  }
}

function createBinaryTree(arr) {
  let head = new Node(arr[0]);
  let queue = [head];

  for (let i = 1; i < arr.length; i++) {
    const curr = queue.shift();

    if (arr[i] != -1) {
      curr.left = new Node(arr[i]);
      queue.push(curr.left);
    }
    i += 1;
    if (i < arr.length && arr[i] != -1) {
      curr.right = new Node(arr[i]);
      queue.push(curr.right);
    }
  }

  return head;
}

function inOrder(head) {
  if (!head) return;

  inOrder(head.left);
  console.log(head.data);
  inOrder(head.right);
}

function iterativeInOrder(head) {
  let arr = [];
  let stack = [];
  let curr = head;

  while (curr !== null || stack.length > 0) {
    if (curr !== null) {
      stack.push(curr);
      curr = curr.left;
    } else {
      const poppedNode = stack.pop();
      arr.push(poppedNode.data);
      curr = poppedNode.right;
    }
  }
  return arr;
}

function preOrder(head) {
  if (!head) return;

  console.log(head.data);
  preOrder(head.left);
  preOrder(head.right);
}

function iterativePreOrder(head) {
  let arr = [];
  let stack = [];

  let curr = head;
  while (curr !== null || stack.length > 0) {
    if (curr !== null) {
      arr.push(curr.data);
      stack.push(curr);
      curr = curr.left;
    } else {
      curr = stack.pop();
      curr = curr.right;
    }
  }

  return arr;
}

function levelOrder(head) {
  let queue = [];
  let arr = [];
  queue.push(head);
  queue.push(null);
  while (queue.length > 0) {
    let curr = queue.shift();

    if (curr === null) {
      console.log(arr);
      arr = [];
      console.log();
      if (queue.length > 0) queue.push(null);
    } else {
      arr.push(curr.data);
      if (curr.left !== null) queue.push(curr.left);
      if (curr.right !== null) queue.push(curr.right);
    }
  }
}

function postOrder(head) {
  if (!head) return;
  postOrder(head.left);
  postOrder(head.right);
  console.log(head.data);
}

let head = createBinaryTree([1, 2, 3, 4, 5, 6, 7, 8]);
// inOrder(head);
// let arr = iterativeInOrder(head);
// preOrder(head);
// let arr = iterativePreOrder(head);
levelOrder(head);
postOrder(head);

// console.log("Iterative preorder = ", arr);
