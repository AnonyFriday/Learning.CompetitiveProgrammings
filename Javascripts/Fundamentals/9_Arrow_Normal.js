const obj = {
  name: "John",
  value: 42,
  print: function () {
    const self = this;

    // Normal function
    // - function does not capture the surrounding this object
    // - solution
    // + have to assign variables to capture the outer `this` context (e.g., `const self = this;`)
    // + using .bind(this)
    function print2() {
      console.log(`Name: ${this.name}, Value: ${this.value}`);
      console.log(`Name: ${self.name}, Value: ${self.value}`);
    }

    // Arrow function will capture the `this` context of the enclosing scope (the `print` function), which is the `obj` object. Therefore, it can access the properties of `obj` directly without needing to assign `this` to another variable.
    const print3 = () => {
      console.log(`Name: ${this.name}, Value: ${this.value}`);
    };

    print2();
    print3();
  },
};

obj.print();

const students = [
  {
    id: 1,
    name: "Alice 1",
    missingSubmission: 2,
  },
  {
    id: 2,
    name: "Alice 2",
    missingSubmission: 2,
  },
  {
    id: 3,
    name: "Alice 3",
    missingSubmission: 3,
  },
];
