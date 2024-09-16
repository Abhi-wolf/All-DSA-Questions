class Node {
  constructor(val) {
    this.data = val;
    this.left = null;
    this.right = null;
  }
}

class BinaryTree {
  constructor() {
    this.root = null;
  }

  createTreeFromArray(arr) {
    if (arr.length == 0) {
      console.log("\n Array is empty");
      return;
    }

    this.root = new Node(arr[0]);
    let queue = [this.root];

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
  }

  inOrder(root) {
    if (!root) return;
    this.inOrder(root.left);
    console.log(root.data);
    this.inOrder(root.right);
  }

  iterativeInOrder() {
    let arr = [];
    let stack = [];
    let curr = this.root;

    while (curr !== null || stack.length > 0) {
      if (curr !== null) {
        stack.push(curr);
        curr = curr.left;
      } else {
        curr = stack.pop();
        arr.push(curr.data);
        curr = curr.right;
      }
    }

    return arr;
  }

  preOrder(root) {
    if (!root) return;
    console.log(root.data);
    this.preOrder(root.left);
    this.preOrder(root.right);
  }

  iterativePreOrder() {
    let arr = [];
    let stack = [];
    let curr = this.root;

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

  postOrder(root) {
    if (!root) return;
    this.postOrder(root.left);
    this.postOrder(root.right);
    console.log(root.data);
  }

  height(root) {
    if (!root) return 0;

    let h1 = this.height(root.left);
    let h2 = this.height(root.left);

    return Math.max(h1, h2) + 1;
  }

  diameter(root) {
    if (!root) return 0;

    let leftHeight = this.height(root.left);
    let rightHeight = this.height(root.right);

    let leftDia = this.diameter(root.left);
    let rightDia = this.diameter(root.right);

    return Math.max(leftHeight + rightHeight + 1, Math.max(leftDia, rightDia));
  }
}

let tree = new BinaryTree();
// tree.createTreeFromArray([1, 2, 3, 4, 5, 6, 7, 8]);
tree.createTreeFromArray([1, 2, 3, 4, -1, -1, -1, 6, -1, 7, -1]);
// tree.inOrder(tree.root);
console.log(tree.iterativeInOrder());
// tree.postOrder(tree.root);
// tree.preOrder(tree.root);
console.log(tree.iterativePreOrder());
console.log(tree.height(tree.root));
console.log(tree.diameter(tree.root));
