// this keyword
// - in JS, this keyword is dynamic and dangerous, this points to the object that calling the method
// - in C#, this keyword is safe and lock
// - Arrow function does not have this keyword, they inherit from the class or scope where they were written
// - Normal function have this keyword, this is the object on the left of the dot

// This in Normal function = Dynamic This
const user = {
  name: "Rookie",
  greet: function () {
    console.log(this.name);
  },
};

user.greet(); // this = user object --> this.name = Rookie

const myGreet = user.greet;
myGreet(); // this = window object --> this.name = underfine

// This in arrow function = Static This
// this = class or object that surrouding the this keyword, in this case is ApiService
class ApiService {
  url = "blak blah";

  fetchData() {
    const self = this;
    setTimeout(function () {
      console.log(self.url);
    }, 100);
  }

  fetchInfor() {
    setTimeout(() => {
      console.log(this.url);
    });
  }
}

let apiService = new ApiService();
let newService = apiService;
apiService.fetchData();
newService.fetchData();

apiService.fetchInfor();
newService.fetchInfor();
