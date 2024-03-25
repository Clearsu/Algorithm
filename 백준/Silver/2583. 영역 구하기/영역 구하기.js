const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

const [m, n, k] = input.shift().split(" ").map(Number);

const map = Array.from({ length: m }, () => Array.from({ length: n }, () => 1));

input.forEach((line) => {
  const [left, bottom, right, top] = line.split(" ").map(Number);
  for (let i = bottom; i < top; i++) {
    for (let j = left; j < right; j++) {
      map[i][j] = 0;
    }
  }
});

const areas = [];
const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];

const bfs = (i, j) => {
  const queue = [];
  let size = 1;
  map[i][j] = 0;
  queue.push({ y: i, x: j });

  while (queue.length > 0) {
    const { y, x } = queue.shift();
    let nextY, nextX;

    for (let k = 0; k < 4; k++) {
      nextY = y + dy[k];
      nextX = x + dx[k];
      if (
        nextY >= 0 &&
        nextY < m &&
        nextX >= 0 &&
        nextX < n &&
        map[nextY][nextX] == 1
      ) {
        map[nextY][nextX] = 0;
        size++;
        queue.push({ y: nextY, x: nextX });
      }
    }
  }
  areas.push(size);
};

let count = 0;

map.forEach((row, i) =>
  row.forEach((grid, j) => {
    if (grid > 0) {
      count++;
      bfs(i, j);
    }
  })
);

areas.sort((a, b) => a - b);

console.log(count);
console.log(areas.join(" "));
