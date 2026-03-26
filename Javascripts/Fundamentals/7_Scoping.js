// Lexical Scoping
// A function can access the variable where the function defined, not where the function called
let x = 10;

function outer() {
  // since inner is defined inside the outer's function scope, inner can access the vairable
  // which will create the closure object in the memory
  let x = 2;
  let inner = function () {
    x += 100;
    console.log(x);
  };

  x += 900;
  console.log(x);

  return inner;
}

let o = outer();
o();
o();

let a = outer();
a();
