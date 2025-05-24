function solution(sizes) {
    let row = 0;
    let height = 0;
    
    sizes.map((item, index) => {
        let subarr = item;
        let longer = 0;
        let shorter = 0;
        
        if (item[0] < item[1]) {
            longer = item[1];
            shorter = item[0];
        }
        else {
            longer = item[0];
            shorter = item[1];
        }
        
        if (row < longer) row = longer;
        if (height < shorter) height = shorter;
    })
  
    return row * height;
}