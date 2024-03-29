-- 코드를 입력하세요
SELECT A.APNT_NO, C.PT_NAME, A.PT_NO, A.MCDP_CD, B.DR_NAME, A.APNT_YMD
FROM APPOINTMENT A
JOIN DOCTOR B
JOIN PATIENT C
ON A.MDDR_ID = B.DR_ID AND A.PT_NO = C.PT_NO
WHERE MONTH(A.APNT_YMD) = '04'
AND A.APNT_CNCL_YN = 'N'
AND A.MCDP_CD = 'CS'
ORDER BY A.APNT_YMD ASC