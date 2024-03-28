const [firstLine, ...rest] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .split("\n");

const [N, H] = firstLine.split(" ").map(Number);

const stalagmite = rest
  .filter((_, idx) => idx % 2 === 0)
  .map(Number)
  .sort((a, b) => a - b); // 석순
const stalactite = rest
  .filter((_, idx) => idx % 2 === 1)
  .map(Number)
  .sort((a, b) => a - b); // 종유석

let minBrokenCount = Number.MAX_VALUE;
let sectionCount;

for (let i = 1; i <= H; i++) {
  const brokenCount =
    getBrokenColumns(stalagmite.length, binarySearch(i, stalagmite)) +
    getBrokenColumns(stalactite.length, binarySearch(H - i + 1, stalactite));

  if (brokenCount < minBrokenCount) {
    minBrokenCount = brokenCount;
    sectionCount = 1;
  } else if (brokenCount === minBrokenCount) {
    sectionCount++;
  }
}

console.log(`${minBrokenCount} ${sectionCount}`);

function getBrokenColumns(length, idx) {
  return length - idx;
}

function binarySearch(val, arr) {
  let left = 0;
  let right = arr.length;
  let mid;

  while (left < right) {
    mid = Math.floor((left + right) / 2);
    if (arr[mid] < val) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}
