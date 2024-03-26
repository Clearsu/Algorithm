const [N, M] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

const ans = [];

const dfs = (start, seq = []) => {
  if (seq.length === M) {
    ans.push(seq);
    return;
  }
  for (let i = start; i <= N; i++) {
    dfs(i, [...seq, i]);
  }
};

dfs(1);

console.log(ans.map((subSeq) => subSeq.join(" ")).join("\n"));
