function solution(arr) {
    
    let tmp_arr = [...arr];
    tmp_arr = tmp_arr.sort((a,b) => a-b);
    const valueToRemove = tmp_arr[0];
    const newArr = arr.filter((item)=> item !== valueToRemove);
    
    if (newArr.length == 0) return [-1];
    else return newArr;
}