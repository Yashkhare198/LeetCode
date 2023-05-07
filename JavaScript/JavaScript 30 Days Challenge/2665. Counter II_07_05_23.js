/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let cnt = init
    let ob1 ={
      increment:()=> cnt+=1,
      decrement:()=> cnt-=1,
      reset:()=>  (cnt=init)
    }
    return ob1;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
