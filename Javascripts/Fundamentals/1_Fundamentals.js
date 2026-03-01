// 1. Declare variables
var a = 10;
let b = 20;
const c = 30;

console.log(a, b, c);

// 2. Primitive types practice
let name = "Duy";
let age = 32;
let isDev = true;
let empty = null;
let notAssigned;
let bigIntHere = 123n; // BigInt("0x1ffffffffffffffffff");
let symbolHere = Symbol("id");

console.log(typeof name);
console.log(typeof age);
console.log(typeof isDev);
console.log(typeof empty); // historical JS bug → "object"
console.log(typeof notAssigned);
console.log(typeof bigIntHere);
console.log(typeof symbolHere);

// 3. Type coercion
console.log("5" + 2); // if +, then concatenate into string
console.log("5" - 2); // if -, then it's 3
console.log(true + 1); // true is 1, false is 0
console.log(false == 0);
console.log(false - 1);

// 4. Truthy / Falsy
const values = [0, "", null, undefined, NaN, "Hello", 42];
values.forEach((v, i) => {
  console.log(v ? `true, ${i}` : `false, ${i}`);
});

// Objects in JS
const userName = "Rookie";
const status = "Active";

const userAccount = {
  userName,
  welcomeMessage: `Welcome, ${userName}. Status: ${status}`,
  logStatus: () => console.log("Account is verified"),
};

console.table(userAccount);

// 5. Arithmetic + Comparison
let x = 10;
let y = 3;

console.log(x + y);
console.log(x % y);
console.log(x > y);
console.log(x === "10");
console.log(x == "10");

// 6. Logical Operator
let isLoggedIn = true;
let isAdmin = false;

console.log(isLoggedIn && isAdmin);
console.log(isLoggedIn || isAdmin);
console.log(!isAdmin);

// 7. Nullish Coalescing
let username = null;
let ageNow = undefined;
let displayName = username ?? "Guest";
let displayAge = ageNow ?? 20;
console.log(displayName);
console.log(displayAge);

// 8. Optional Chaining
const monkey = {
  name: "Vu Kim Duy",
  age: 20,
};

console.log(monkey.dog?.name);
console.log(monkey.name);
// console.log(monkey.cat.name); // will raise error if cat is not declared

// 9 For...of for iteration
const array = [1, 2, 3, 5];
for (const val of array) {
  console.log(val);
}

// 10. For...in for iteration
const objects = { a: 1, b: 2, c: 3 };
for (const key in objects) {
  if (Object.hasOwn(objects, key)) {
    console.log(key + ": " + objects[key]);
  }
}
