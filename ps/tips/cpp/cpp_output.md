# CPP로 출력 다루기!

## Index
- `cout`에서 서식 설정하기

## `cout`에서 서식 설정하기
실수 자료형을 다룰 때 소수점 이하 자리수의 표현 등을 설정할 때에 필요

### `.precision(n)`
해당 실수의 전체 출력 자리수를 지정한다. 이 메서드만 실행한다면 정수부/소수부 모두 포함한 전체 출력 자리수를 지정한다. 소수 자리수만 특정하여 지정하려면 아래의 `fixed` 조정자를 사용한다.

```cpp
cout.precision(4); // 총 4자리를 표시
cout << 1.234;         // 1.234
cout << 1.23456;       // 1.234
cout << 12.3456;       // 12.34
```

### `fixed`
고정소수점 형태로 실수를 출력한다. 즉, 