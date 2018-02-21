const addon = require('./build/Release/addon.node');
const native = require('./sum');

function performIterationTest(iterations) {
  console.log(`Iterations = ${iterations}`);

  const cppTag = `c++ ${iterations}`;
  console.time(cppTag);
  addon.Sum(iterations);
  console.timeEnd(cppTag);

  const jsTag = `js ${iterations}`;

  console.time(jsTag);
  native.Sum(iterations);
  console.timeEnd(jsTag);
}

for (let i = 0; i <= 9; i += 1) {
  performIterationTest(10 ** i);
}
