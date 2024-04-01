const [firstLine, ...rest] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [N, M] = firstLine.split(" ").map(Number);

const ans = [];

for (let i = 0; i < N; i++) {
  const a = rest[i].split(" ").map(Number);
  const b = rest[i + N].split(" ").map(Number);
  const res = [];
  for (let j = 0; j < M; j++) {
    res.push(a[j] + b[j]);
  }
  ans.push(res);
}

console.log(ans.map((row) => row.join(" ")).join("\n"));
