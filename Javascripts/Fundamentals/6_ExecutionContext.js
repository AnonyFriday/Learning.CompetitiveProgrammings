// Variables are hoisted before execution phase
console.log(x); // will print undefined
var x = 5;

function test() {
  console.log("hello");
}

// Function declaration are fully hoisted
sayHello();
function sayHello() {
  console.log("HI");
}

// Function expression not hoisted
// sayMom(); // will raise error
// let sayMom = () => {
//   console.log("Mom");
// };

// TDZ
{
  // let/const must be declared first before using it due to TMZ mechanism
  //   console.log(a);

  let a;
  console.log(a);
}

// Shadowing also cause ReferenceError by the TDZ as well
{
  let k = 10; // even declaring first, you also cannot initialize it

  {
    console.log(k);
    let k = 10;
  }
}
