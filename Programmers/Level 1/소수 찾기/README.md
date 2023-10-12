# 문제
https://school.programmers.co.kr/learn/courses/30/lessons/12921

## 시도 1. (실패)
<p> bool을 이용하여 소수 판별.
<p> 이중 for문
<p> 수와 제곱근의 나머지가 0이면 소수가 아님.
<p> 
==> 정확도 테스트는 통과했으나, 효율성 테스트에서 실패 뜸.

## 시도 2. 에라토스테네스의 체 (성공)
<p> 참고 : https://kangworld.tistory.com/20
<p> -> 시간 복잡도가 O(Nlog(logN))으로 O(N)에 가깝다
<p> bool형 벡터 선언
<p> for문을 사용하여 소수가 될수 없는 수의 배수를 판별
<p> bool형 벡터에 소수 판별 값 저장
