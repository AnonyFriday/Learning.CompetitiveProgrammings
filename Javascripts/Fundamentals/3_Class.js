// ES 6: Class
// - Just the syntatic sugar for prototype
class Person {
  #job;
  #name;
  #age;

  constructor(name, age, job) {
    this.#job = job;
    this.#name = name;
    this.#age = age;
  }
}

class Repository extends Person {
  #connectionString; //private property

  constructor(age, name, job, dbName) {
    super(name, age, job);
    this.dbName = dbName; // public property
    this.#connectionString = `Server=myServer;DB=${dbName}`;
  }

  getData() {
    console.log(`Fetching from ${this.dbName}`);
  }

  static info() {
    console.log("This is an Repository class");
  }
}

const myRepo = new Repository("UserDb");
console.log(myRepo.dbName);
myRepo.getData();
Repository.info();

// ES 5: Prototype (replacement for the inheritance in ES 6)
// - constructor function
function User(name) {
  this.name = name;
}

User.prototype.sayHi = function () {
  console.log(this.name);
};

const me = new User("Rooke");
const anotherPointerPointToObjectUser = me;
me.sayHi();
anotherPointerPointToObjectUser.sayHi();
