-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME LIKE '%EL%'
# OR NAME LIKE '%eL%'
# OR NAME LIKE '%El%'
# OR NAME LIKE '%el%'
AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME