-- 코드를 작성해주세요

SELECT A.DEPT_ID, A.DEPT_NAME_EN, ROUND(AVG(B.SAL),0) AS AVG_SAL FROM HR_DEPARTMENT AS A
RIGHT JOIN HR_EMPLOYEES AS B ON A.DEPT_ID = B.DEPT_ID
GROUP BY A.DEPT_ID
ORDER BY AVG(B.SAL) DESC;