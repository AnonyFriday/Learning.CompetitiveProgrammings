// ===== Using xmlHttpRequest to create the Http Request
function loadImage(url, callbackSuccess, callbackError) {
  let xhr = new XMLHttpRequest();
  xhr.open("GET", url, true);
  xhr.responseType = "blob";

  // fire multiple times on state changes, but at state 4 and status 200
  xhr.onreadystatechange = () => {
    if (xhr.readyState == 4 && xhr.status == 200) {
      callbackSuccess(xhr.response);
    }
  };

  xhr.onerror = (err) => {
    callbackError(err);
  };

  xhr.send();
}

const baseUrl = "https://picsum.photos/id/";
for (let i = 0; i < 3; i++) {
  let imageUrl = `${baseUrl}${i}/200/300`;
  let imageDiv = document.getElementById(`image${i}`);
  loadImage(
    imageUrl,
    (response) => {
      imageDiv.src = URL.createObjectURL(response);
    },
    (error) => {
      console.log(error);
    },
  );
}

// ===== Load Image using Promise
const loadImagePromise = (url) =>
  new Promise((resolve, reject) => {
    let xhr = new XMLHttpRequest();
    xhr.open("GET", url, true);
    xhr.responseType = "blob";

    xhr.onreadystatechange = () => {
      if (xhr.readyState == 4 && xhr.status == 200) {
        resolve(xhr.response);
      } else if (xhr.status == 404) {
        reject(`HTTP error: ${xhr.status}`);
      }
    };

    xhr.onerror = (err) => {
      reject(err);
    };

    xhr.send();
  });

// Requesting images in parallel, not in the sequential
const promiseImage3 = loadImagePromise(`${baseUrl}/3/200/300`);
const promiseImage4 = loadImagePromise(`${baseUrl}/4/200/300`);
const promiseImage5 = loadImagePromise(`${baseUrl}/5/200/300`);

promiseImage3
  .then((imageData) => {
    let imageDiv3 = document.getElementById(`image3`);
    imageDiv3.src = URL.createObjectURL(imageData);

    return promiseImage4;
  })
  .then((imageData) => {
    let imageDiv4 = document.getElementById(`image4`);
    imageDiv4.src = URL.createObjectURL(imageData);

    return promiseImage5;
  })
  .then((imageData) => {
    let imageDiv5 = document.getElementById(`image5`);
    imageDiv5.src = URL.createObjectURL(imageData);
  })
  .catch((err) => {
    console.log(err);
  });

// Requesting images in sequential chaining
// - Demonstrate the async/await behind the scene
// - return loadImagePromise(`${baseUrl}/7/200/300`); would be the next continuation register
// as a microtask (via .then()) and being called subsequently
const promiseImage6 = loadImagePromise(`${baseUrl}/6/200/300`);

promiseImage6
  .then((imageData) => {
    let imageDiv6 = document.getElementById(`image6`);
    imageDiv6.src = URL.createObjectURL(imageData);

    // Continuation is stored inside the Promise’s .then() handlers
    // Behind the scene of await
    return loadImagePromise(`${baseUrl}/7/200/300`);
  })
  .then((imageData) => {
    let imageDiv7 = document.getElementById(`image7`);
    imageDiv7.src = URL.createObjectURL(imageData);

    return loadImagePromise(`${baseUrl}/8/200/300`);
  })
  .then((imageData) => {
    let imageDiv8 = document.getElementById(`image8`);
    imageDiv8.src = URL.createObjectURL(imageData);
  })
  .catch((err) => {
    console.log(err);
  });

// Request images using async await to simulate the situation
// - The code after await will be put inside the continuation resolve, which will be register as a microtask and push
// into the microqueue for later picking up by the event loop and execute on the callstack
async function loadImagesAsyncAwait() {
  let imageData9 = await loadImagePromise(`${baseUrl}/3/200/300`);
  let imageDiv9 = document.getElementById(`image9`);
  imageDiv9.src = URL.createObjectURL(imageData9);

  let imageData10 = await loadImagePromise(`${baseUrl}/3/200/300`);
  let imageDiv10 = document.getElementById(`image10`);
  imageDiv10.src = URL.createObjectURL(imageData10);

  let imageData11 = await loadImagePromise(`${baseUrl}/3/200/300`);
  let imageDiv11 = document.getElementById(`image11`);
  imageDiv11.src = URL.createObjectURL(imageData11);
}

loadImagesAsyncAwait();
