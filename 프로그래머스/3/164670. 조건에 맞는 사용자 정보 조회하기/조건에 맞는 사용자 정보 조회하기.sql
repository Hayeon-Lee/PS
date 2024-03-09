-- 코드를 입력하세요
SELECT 
    B.USER_ID AS 'USER_ID',
    B.NICKNAME AS 'NICKNAME',
    CONCAT(B.CITY, ' ', B.STREET_ADDRESS1, ' ', B.STREET_ADDRESS2) AS '전체주소',
    CONCAT(SUBSTR(B.TLNO, 1, 3), '-', SUBSTR(B.TLNO, 4, 4), '-', SUBSTR(B.TLNO, 8)) AS '전화번호'
FROM USED_GOODS_USER AS B
INNER JOIN USED_GOODS_BOARD AS A
ON A.WRITER_ID = B.USER_ID
GROUP BY B.USER_ID
HAVING COUNT(A.WRITER_ID) >= 3
ORDER BY B.USER_ID DESC;

/*
사용자 ID, 닉네임, 전체주소, 전화번호
시, 도로명 주소, 상세 주소가 함께 출력되도록 해주시고, 전화번호의 경우 xxx-xxxx-xxxx 같은 형태로 하이픈 문자열(-)을 삽입하여 출력해주세요.
*/