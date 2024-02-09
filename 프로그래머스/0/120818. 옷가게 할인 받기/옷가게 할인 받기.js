function solution(price) {
    
    if (price >= 500000) {
        price -= (price*0.2);
        price = parseInt(price);
    }
    else if (price >= 300000) {
        price -= (price*0.1);
        price = parseInt(price);
    }
    else if (price >= 100000) {
        price -= (price*0.05);
        price = parseInt(price);
    }

    return price;
}