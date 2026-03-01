const settings = {
  theme: "dark",
  notifications: true,
  volumne: 80,
};

// Destructurign Assignment & Rest Operator
// - Pulling out the variables
// - In C#, using the 'with' keyword
const { volumne, ...others } = settings;
console.log(volumne);
console.log(others);

// Rest Parameter
function getTotal(name = "UNKNOWN", price1, price2, ...additionalFees) {
  var total = price1 + price2;
  additionalFees.forEach((price) => {
    total += price;
  });

  return total;
}

console.log(getTotal("VU KIM DUY", 1, 2, 3, 3, 3, 3, 3));

// Short-circuit
const isAdmin = true;
const ui = isAdmin && "Delete Button";
console.log(isAdmin, ui);

// Spread Operators
// - Copying the original object or array and modify its prooerty to avoid mutation
const newSettings = { ...settings, volumne: 100 };
console.log(newSettings);

const rawUsers = [
  { id: 1, first_name: "John", last_name: "Doe", role: "admin", active: true, metadata: { loginCount: 5 } },
  { id: 2, first_name: "Jane", last_name: "Smith", role: "editor", active: false, metadata: { loginCount: 12 } },
  { id: 3, first_name: "Rookie", last_name: "Dev", role: "guest", active: true, metadata: { loginCount: 1 } },
];

// Optional Chaining
const displayUserStatus = (user) => {
  const logins = user?.metadata?.loginCount ?? 0; // Nullish Coalescing (??)
  const alert = logins > 10 && "User Alert!";
  const fullName = `${user.first_name} ${user.last_name}`;
  console.log(`${fullName} has ${logins}. ${alert || ""}`);
};

rawUsers.forEach((user) => {
  displayUserStatus(user);
});

// Extended Parameter Handling
const calculateTotal = (discount, ...prices) => {
  const subtotal = prices.reduce((acc, curr) => {
    return acc + curr;
  }, 0);
  return subtotal - discount;
};

console.log(calculateTotal(5, 10, 20, 30, 333));

// Computed Property
let myName = "Vu Kim Du";
const obj = {
  [`${myName}OfMyChild`]: myName,
};

console.log(obj);

// Higher Order Function
// - a function that take another function as an argument
// - a function return a function

function greet(name) {
  return "Hello " + name;
}

function processUser(name, callback) {
  return callback(name);
}

const greeting = processUser("Duy", greet);
console.log(greeting);

// Closure
// - function remember variable outside the scope of it
// - useful in the concept of react hooks
// - capture by reference alike, not same mechanism like in c++

function counter() {
  // 1. run first
  let count = 0;
  console.log("Count before: " + count);

  // 3. after executing first execution context, calling this (I) will execute the lambda function
  // - x is being captured by reference in closure
  // - x is still survived after the counter end, not like in c++, x is being destroyed

  let f = function () {
    count++;

    console.log("Count in function: " + count);
    return count;
  };

  // 2. run till here
  count += 1000;
  console.log("Count after: " + count);
  return f;
}

// 2 Difference closure object
counter()();
counter()();

// Same closure object, difference inner execution
// - sharing the same closure object, referencing the same variable
let c = counter();
c();
c();
c();
