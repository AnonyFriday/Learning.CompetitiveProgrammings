/*
    Functional Programming Paradigm
    - Immutability
    - Pure Functions
    - Recursion
    - Declarative Programming
    - Lazy Evaluation
*/

// Immutability
// - OOP way
const user = { name: "Roookie", score: 10 };
user.score;

// - FP way
// - since data is immutable, we cannot modify x, but just return a new object from it
const updatedUser = { ...user, score: 10 };

// Pure Functions
// - same input, same output, no depends on external state
const double = (x) => x * 2;

// - wrong, depends on the outside world
var discount = 10;
const totalPrice = (tax) => discount + tax;

// Declarative
// - Use built-in methods
const prices = [10, 20, 30, 40];

const expensiveItems = prices.filter((p) => p > 15).map((p) => p * 2);
console.log(expensiveItems);

// Recursion

// Lazy Evaluation
const bigInts = [1, 2, 3, 4, 4, 4, 4, 4, 2, 2, 1, 3, 4, 5, 6, 3];

const eagerSquare = bigInts.map((n) => {
  console.log("Eager processing...");
  return n * n;
});

function* lazySquare(data) {
  for (let n of bigInts) {
    console.log("Lazy processing...");
    yield n * n;
  }
}

const iterator = lazySquare(bigInts);
console.log("Generator created, but nothing processed yet.");

console.log(iterator.next().value); // Processed ONLY the first item
console.log(iterator.next().value); // Processed ONLY the second item
console.log(iterator.next().value); // Processed ONLY the third item
