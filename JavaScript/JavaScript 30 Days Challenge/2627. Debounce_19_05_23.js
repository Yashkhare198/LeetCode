var debounce = function (fn, t) {
  let timer; // A local variable to store previous setTimeout key
  return function (...args) {
    clearTimeout(timer) // clear any previously existing timer
    timer = setTimeout(()=> { // start a new timer to call after `t` ms
      fn(...args) // call the function with all the original arguments
    }, t)

  };
};
