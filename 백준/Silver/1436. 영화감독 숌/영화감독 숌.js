const input = require("fs").readFileSync("/dev/stdin").toString().trim();

const n = Number(input);
let currEndNum = 666;
let currNum = currEndNum + 1;

for (let i = 1; i < n; i++) {
  while (true) {
    let copy = currNum;
    let count;
    while (copy > 0) {
      count = 0;
      while (copy > 0 && copy % 10 !== 6) {
        copy = Math.floor(copy / 10);
      }
      while (copy > 0 && copy % 10 === 6) {
        count++;
        copy = Math.floor(copy / 10);
      }
      if (count >= 3) {
        currEndNum = currNum;
        break;
      }
    }
    currNum++;
    if (count >= 3) {
      break;
    }
  }
}

console.log(currEndNum);
