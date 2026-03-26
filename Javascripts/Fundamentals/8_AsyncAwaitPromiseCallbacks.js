// Synchronous
console.log("Start");
console.log("Start 2");
console.log("Start 3 ");

// Asynchronous
// - setTimeout is a web API,
// which is not part of JavaScript, but provided by the browser
// - callback inside the setTimeout is macro task,
// which will be put in the task queue after the timer is expired
console.log("A");

setTimeout(() => {
  console.log("B");
}, 1000);

// Promise
let resultFromAsyncOperation = new Promise((resolve, reject) => {
  // after 2 seconds, resolve the promise with a result
  setTimeout(() => {
    resolve("Result from async operation");
  }, 2000);

  if (Math.random() > 0.0) {
    reject("Error occurred");
  }
});

resultFromAsyncOperation
  .then((result) => {
    console.log(result);
  })
  .catch((error) => {
    console.error(error);
  });

// Track state of the promise using closure
function trackStateOfPromise(promise) {
  let state = "pending";

  let tracked = promise
    .then((value) => {
      state = "fulfilled";
      return value;
    })
    .catch((error) => {
      state = "rejected";
      return error;
    });

  // can add a method to get the current state of the promise because
  // promise is an object and we can add properties to it

  // dynamic property assignment
  tracked.getState = () => state;
  return tracked;
}

let trackedPromise = trackStateOfPromise(
  new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve("Tracked promise resolved");
    }, 1500);

    if (Math.random() > 0.5) {
      reject("Error occurred in tracked promise");
    }
  }),
);

console.log("Initial State: " + trackedPromise.getState());
console.log("Waiting for promise to settle...");
setTimeout(() => {
  console.log("Final State: " + trackedPromise.getState());
}, 2000);
