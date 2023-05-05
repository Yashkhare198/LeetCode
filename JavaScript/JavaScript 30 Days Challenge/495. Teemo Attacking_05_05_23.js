/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function(timeSeries, duration) {

    let ans = 0;

    for(let i = 0; i<timeSeries.length-1 ; i++){

        if(timeSeries[i] + (duration - 1) < timeSeries[i+1]){
            ans += duration;
        }
        else{
            ans += timeSeries[i+1] - timeSeries[i];
        }
    }

    return ans + duration;
    
};
