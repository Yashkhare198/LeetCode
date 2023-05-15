/**
 * @param {number} millis
 */
async function sleep(millis) {
    const ans = new Promise((resolve,reject)=>{

        setTimeout(()=>{
            resolve()
        },millis);
    })
    return ans;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
