const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

input.shift();

input.sort((a, b) => parseInt(a) - parseInt(b));

console.log(input.join("\n"));
