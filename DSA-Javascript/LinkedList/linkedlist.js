class ListNode {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}
class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  /* Returns true or false based on whether the head points to null or not */
  isEmpty() {
    return this.head === null;
  }

  /* Insert At head */
  insertAtHead(val) {
    let newNode = new ListNode(val);
    newNode.next = this.head;
    this.head = newNode;

    if (!this.tail) this.tail = newNode;
  }

  /* Add new node to the end of the linked list (Insert at tail) */
  insertAtTail(val) {
    if (this.isEmpty()) {
      this.insertAtHead(val);
    } else {
      this.tail.next = new ListNode(val);
      this.tail = this.tail.next;
    }
  }

  /* make linked list from array */
  fromArray(values) {
    values.forEach((val) => this.insertAtTail(val));
    return this;
  }

  /* Insert at a position */
  insertAtPosition(val, pos) {
    if (this.isEmpty() || pos <= 0) {
      this.insertAtHead(val);
    } else {
      let curr = this.head;
      while (pos > 1 && curr) {
        curr = curr.next;
        pos -= 1;
      }
      if (curr) {
        let newNode = new ListNode(val);
        newNode.next = curr.next;
        curr.next = newNode;
      } else {
        this.insertAtTail(val);
      }
    }
  }

  /* print the linked list */
  display() {
    if (this.isEmpty()) {
      console.log("Empty \n");
      return;
    }

    let temp = this.head;
    while (temp) {
      console.log(temp.data);
      temp = temp.next;
    }
  }

  /* delete a node from the linked list */
  delete(val) {
    if (this.isEmpty()) {
      console.log("Empty\n");
      return;
    }

    let temp = this.head;
    let prev = null;
    while (temp && temp.data != val) {
      prev = temp;
      temp = temp.next;
    }

    if (temp) {
      if (this.head === temp) {
        this.head = this.head.next;
        if (!this.head) this.tail = null;
      } else {
        prev.next = temp.next;
        if (!prev.next) this.tail = prev;
      }
      console.log("\nNode deleted = ", temp.data, "\n");
    } else {
      console.log("\nNot found\n");
    }
  }

  /* linked list to array */
  toArray() {
    const nodes = [];
    let curr = this.head;

    while (curr) {
      nodes.push(curr.data);
      curr = curr.next;
    }

    return nodes;
  }

  /* Search a node */
  search(val) {
    let temp = this.head;
    while (temp && temp.data !== val) {
      temp = temp.next;
    }

    if (temp) console.log("\nData found = ", temp.data, "\n");
    else console.log("\nData not found \n");
  }
}

let list1 = new LinkedList();
list1.fromArray([10, 30, 50, 70, 100]);
let nodes = list1.toArray();
console.log(nodes);
console.log(list1.isEmpty());
// list1.Display();
list1.insertAtPosition(20, 7);
list1.insertAtPosition(20, -3);
list1.display();

let list2 = new LinkedList();
list2.fromArray([10, 30, 50, 70, 100]);
console.log("Initial List:", list2.toArray());
console.log("Is Empty:", list2.isEmpty());

list2.insertAtPosition(20, 2);
list2.display();

list2.delete(30);
list2.display();

list2.search(70);
list2.search(25);

console.log("Final List:", list2.toArray());
console.log("Is Empty:", list2.isEmpty());
