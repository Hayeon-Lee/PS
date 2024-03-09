-- 코드를 입력하세요
SELECT 
    ORDER_ID, 
    PRODUCT_ID, 
    DATE_FORMAT(OUT_DATE, '%Y-%m-%d') AS 'OUT_DATE',
    CASE
        WHEN DATE_FORMAT(OUT_DATE, '%Y-%m-%d') <= '2022-05-01' THEN '출고완료'
        WHEN DATE_FORMAT(OUT_DATE, '%Y-%m-%d') > '2022-05-01' THEN '출고대기'
        WHEN OUT_DATE IS NULL THEN '출고미정'
    END AS '출고여부'
FROM FOOD_ORDER
ORDER BY ORDER_ID ASC;

/*
5월 1일을 기준으로
주문 ID, 제품 ID, 출고일자, 출고여부
5월 1일까지 출고완료
이 후 날짜는 출고 대기
미정이면 출고미정
*/