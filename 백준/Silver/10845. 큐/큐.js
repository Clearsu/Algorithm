const fs = require("fs");

const inputLines = fs
  .readFileSync("/dev/stdin", "utf8")
  .toString()
  .trim()
  .split("\n");

const queue = [];
let front = 0;

let ans = "";

inputLines.forEach((line) => {
  const [act, num] = line.split(" ");

  if (act === "front") {
    ans += front === queue.length ? "-1\n" : `${queue[front]}\n`;
  } else if (act === "back") {
    ans += front === queue.length ? "-1\n" : `${queue[queue.length - 1]}\n`;
  } else if (act === "size") {
    ans += `${queue.length - front}\n`;
  } else if (act === "pop") {
    if (queue.length === front) {
      ans += "-1\n";
    } else {
      ans += `${queue[front]}\n`;
      front++;
    }
  } else if (act === "empty") {
    ans += queue.length > front ? "0\n" : "1\n";
  } else if (act === "push") {
    queue.push(num);
  }
});

console.log(ans);
