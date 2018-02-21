const Sum = (iterations) => {
  let a = 3.1415926;
  const b = 2.718;

  for (let i = 0; i < iterations; i += 1) {
    a += b;
  }

  return a;
};

module.exports = {
  Sum,
};
