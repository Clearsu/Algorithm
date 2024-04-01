const [firstLine, ...rest] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [N, M] = firstLine.split(" ").map(Number);

console.log(
  Array.from({ length: N }, (_, i) => {
    const a = rest[i].split(" ").map(Number);
    const b = rest[i + N].split(" ").map(Number);

    return a.map((val, idx) => val + b[idx]).join(" ");
  }).join("\n")
);
