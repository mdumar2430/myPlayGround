var module = require("./lib");
var input = require('readline-sync');
var x = parseInt(input.question("Enter number:"));
console.log(module.sqr(x));
console.log(module.cube(x));
console.log(module.COLLEGE);

